/*
 * (C) Copyright 2015-2016 Freescale Semiconductor, Inc.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

/*
 * Configuration settings for the Freescale S32V234 FVB board.
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_S32V234
#define CONFIG_S32VFVB_REVB
#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO

#undef CONFIG_RUN_FROM_IRAM_ONLY

#define CONFIG_MACH_TYPE		4146

#define CONFIG_SKIP_LOWLEVEL_INIT

/* Config CACHE */
#define CONFIG_CMD_CACHE

/* Enable DCU QoS fix */
#define CONFIG_DCU_QOS_FIX

/* FVB_REVB board has 2x256 MB DDR chips, DDR0 and DDR1,
 * u-boot is using just one */
#define DDR_SIZE		(256 * 1024 * 1024)

/* Enable DDR handshake at functional reset event */
#define CONFIG_DDR_HANDSHAKE_AT_RESET

#define CONFIG_DDR_INIT_DELAY		1000

/* System Timer */
#define CONFIG_SYS_GENERIC_TIMER
/* #define CONFIG_SYS_PIT_TIMER */

#define LINFLEXUART			0

#define CONFIG_SYS_FSL_ESDHC_ADDR	0

#define CONFIG_CMD_EXT2 /* EXT2 Support */

#define CONFIG_FEC_XCV_TYPE     RMII
#define CONFIG_FEC_MXC_PHYADDR  1
#define CONFIG_PHYLIB
#define CONFIG_PHY_MICREL

#define FDT_FILE		s32v234-fvb.dtb

#define CONFIG_LOADADDR		LOADADDR

#define CONFIG_SYS_INIT_SP_OFFSET \
	(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)

/* #define CONFIG_CMD_PCI */

/* we include this file here because it depends on the above definitions */
#include <configs/s32v234_common.h>

#endif
