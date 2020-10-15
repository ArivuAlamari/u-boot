// SPDX-License-Identifier:     GPL-2.0+
/*
 * Copyright 2014-2015 Freescale Semiconductor, Inc.
 * (C) Copyright 2017-2020 NXP
 */

#include <common.h>
#include <cpu_func.h>
#include <asm/io.h>
#include <asm/system.h>
#include <asm/io.h>
#include <asm/arch/mc_me_regs.h>
#include <asm/arch/mc_rgm_regs.h>
#include <asm/spin_table.h>
#include "mp.h"

DECLARE_GLOBAL_DATA_PTR;

#ifdef CONFIG_S32V234
static bool is_core_active(int core)
{
	u32 core_mask = MC_ME_CS_A53(core);

	return (readl(MC_ME_CS) & core_mask) == core_mask;
}

static unsigned long get_core_start_addr(int core)
{
	return readl(MC_ME_CADDR_A53(core)) & MC_ME_CADDRn_ADDR_MASK;
}

int fsl_s32_wake_secondary_cores(void)
{
	u32 start_addr = (u32)(uintptr_t)gd->relocaddr;

	/* program the cores possible running modes */
	writew(MC_ME_CCTL_DEASSERT_CORE, MC_ME_CCTL2);
	writew(MC_ME_CCTL_DEASSERT_CORE, MC_ME_CCTL3);
	writew(MC_ME_CCTL_DEASSERT_CORE, MC_ME_CCTL4);

	/* write the cores' start address */
	writel(start_addr | MC_ME_CADDRn_ADDR_EN, MC_ME_CADDR2);
	writel(start_addr | MC_ME_CADDRn_ADDR_EN, MC_ME_CADDR3);
	writel(start_addr | MC_ME_CADDRn_ADDR_EN, MC_ME_CADDR4);

	writel( MC_ME_MCTL_RUN0 | MC_ME_MCTL_KEY, MC_ME_MCTL );
	writel( MC_ME_MCTL_RUN0 | MC_ME_MCTL_INVERTEDKEY, MC_ME_MCTL );

	while( (readl(MC_ME_GS) & MC_ME_GS_S_MTRANS) != 0x00000000 );

	smp_kick_all_cpus();

	printf("All (%d) cores are up.\n", cpu_numcores());

	return 0;
}

#elif defined(CONFIG_S32_GEN1)
static bool is_core_active(int core)
{
	u32 mask = MC_ME_PRTN_N_CORE_M_STAT_CCS;
	uintptr_t addr = MC_ME_PRTN_N_CORE_M_STAT(MC_ME_CORES_PRTN, core & ~1);
	u32 status = readl(addr);

	return (status & mask) == mask;
}

static unsigned long get_core_start_addr(int core)
{
	return readl(MC_ME_PRTN_N_CORE_M_ADDR(MC_ME_CORES_PRTN, core));
}

static void fsl_s32_wake_secondary_core(int prtn, int core)
{
	u32 reset, resetc;

	/* MC_ME holds the low 32 bits of the start_address */
	writel(gd->relocaddr, MC_ME_PRTN_N_CORE_M_ADDR(prtn, core));

	/* If in performance (i.e. not lockstep) mode, the following bits used
	 * in the core wakeup sequence are only defined for the first core of
	 * each cluster: CCE, CCUPD, CCS.
	 */
	/*
	 * Enable core clock
	 */
	writel(MC_ME_PRTN_N_CORE_M_PCONF_CCE,
	       MC_ME_PRTN_N_CORE_M_PCONF(prtn, core & ~1));
	writel(MC_ME_PRTN_N_CORE_M_PUPD_CCUPD,
	       MC_ME_PRTN_N_CORE_M_PUPD(prtn, core & ~1));

	/* Write valid key sequence to trigger the update. */
	writel(MC_ME_CTL_KEY_KEY, MC_ME_CTL_KEY(MC_ME_BASE_ADDR));
	writel(MC_ME_CTL_KEY_INVERTEDKEY, MC_ME_CTL_KEY(MC_ME_BASE_ADDR));

	/* Wait for core clock enable status bit. */
	while ((readl(MC_ME_PRTN_N_CORE_M_STAT(prtn, core & ~1)) &
				MC_ME_PRTN_N_CORE_M_STAT_CCS) !=
			MC_ME_PRTN_N_CORE_M_STAT_CCS)
		;

	/* Deassert core reset */
	reset = readl(RGM_PRST(MC_RGM_BASE_ADDR, RGM_CORES_RESET_GROUP));
	resetc = RGM_CORE_RST(core);
	reset &= ~resetc;
	writel(reset, RGM_PRST(MC_RGM_BASE_ADDR, RGM_CORES_RESET_GROUP));
	while ((readl(RGM_PSTAT(MC_RGM_BASE_ADDR, RGM_CORES_RESET_GROUP))
				& resetc) != 0)
		;

	printf("CA53 core %d running.\n", core);
}

int fsl_s32_wake_secondary_cores(void)
{
	/* Enable partition clock */
	writel(MC_ME_PRTN_N_PCE,
	       MC_ME_PRTN_N_PCONF(MC_ME_BASE_ADDR, MC_ME_CORES_PRTN));
	writel(MC_ME_PRTN_N_PCE,
	       MC_ME_PRTN_N_PUPD(MC_ME_BASE_ADDR, MC_ME_CORES_PRTN));

	/* Write valid key sequence to trigger the update. */
	writel(MC_ME_CTL_KEY_KEY, MC_ME_CTL_KEY(MC_ME_BASE_ADDR));
	writel(MC_ME_CTL_KEY_INVERTEDKEY, MC_ME_CTL_KEY(MC_ME_BASE_ADDR));

	/* Cluster 0, core 0 is already enabled by BootROM.
	 * We should enable core 1 from cluster 0 and
	 * core 0 and 1 from cluster 1. All are in prtn 1.
	 * The procedure can be found in
	 * "MC_ME application core enable", S32R RM Rev1 DraftC.
	 */
	fsl_s32_wake_secondary_core(1, 1);
	fsl_s32_wake_secondary_core(1, 2);
	fsl_s32_wake_secondary_core(1, 3);

	smp_kick_all_cpus();

	printf("All (%d) cores are up.\n", cpu_numcores());

	return 0;
}
#else
#error "Incomplete platform definition"
#endif

#ifdef CONFIG_MP
int is_core_valid(unsigned int core)
{
	if (core == 0)
		return 0;

	return !!((1 << core) & cpu_mask());
}

int cpu_reset(u32 nr)
{
	puts("Feature is not implemented.\n");

	return 0;
}

int cpu_disable(u32 nr)
{
	puts("Feature is not implemented.\n");

	return 0;
}

int core_to_pos(int nr)
{
	u32 cores = cpu_mask();
	int i, count = 0;

	if (nr == 0) {
		return 0;
	} else if (nr >= hweight32(cores)) {
		puts("Not a valid core number.\n");
		return -1;
	}

	for (i = 1; i < 32; i++) {
		if (is_core_valid(i)) {
			count++;
			if (count == nr)
				break;
		}
	}

	return count;
}

int cpu_status(u32 nr)
{
	printf("Core %d status: ", nr);
	if (!is_core_active(nr))
		printf("inactive");
	else
		printf("running");
	printf("\n");

	printf("Start address = 0x%lx\n", get_core_start_addr(nr));
	return 0;
}

int cpu_release(u32 nr, int argc, char * const argv[])
{
	int valid;
	u64 boot_addr;

	valid = is_core_valid(nr);
	if (!valid)
		return 0;

	boot_addr = simple_strtoull(argv[0], NULL, 16);
	spin_table_cpu_release_addr = boot_addr;
	flush_dcache_range((unsigned long)&spin_table_cpu_release_addr,
			   (unsigned long)(&spin_table_cpu_release_addr + 1));
	asm volatile("dsb st");

	smp_kick_all_cpus();	/* only those with entry addr set will run */
	return 0;
}
#endif
