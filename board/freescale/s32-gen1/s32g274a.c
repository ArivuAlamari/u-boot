// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Copyright 2018-2019 NXP
 */

#include <common.h>
#include <asm/arch/soc.h>

#include "board_common.h"

void setup_iomux_uart(void)
{
#if (CONFIG_FSL_LINFLEX_MODULE == 0)

	/* Muxing for linflex0 */
	setup_iomux_uart0_pc09_pc10();

#elif (CONFIG_FSL_LINFLEX_MODULE == 1)
	/* Muxing for linflex1 */

	/* set PC08 - MSCR[40] - for UART1 TXD */
	writel(SIUL2_MSCR_S32G_G1_PORT_CTRL_UART1_TXD,
	       SIUL2_0_MSCRn(SIUL2_PC08_MSCR_S32_G1_UART1));

	/* set PC04 - MSCR[36] - for UART1 RXD */
	writel(SIUL2_MSCR_S32G_G1_PORT_CTRL_UART_RXD,
	       SIUL2_0_MSCRn(SIUL2_PC04_MSCR_S32_G1_UART1));

	/* set PC04 - MSCR[736]/IMCR[224] - for UART1 RXD */
	writel(SIUL2_IMCR_S32G_G1_UART1_RXD_to_pad,
	       SIUL2_1_IMCRn(SIUL2_PC04_IMCR_S32_G1_UART1));
#else
#error "Unsupported UART pinmuxing configuration"
#endif
}

void setup_iomux_i2c(void) {}

#ifdef CONFIG_FSL_DSPI
void setup_iomux_dspi(void)
{
	/* Muxing for DSPI1 */

	/* Configure Chip Select Pins */
	writel(SUIL2_MSCR_S32G_PAD_CTL_SPI1_CS0,
	       SIUL2_0_MSCRn(SIUL2_MSCR_S32G_PA_07));

	/* MSCR */
	writel(SIUL2_MSCR_S32G_PAD_CTL_SPI1_SOUT,
	       SIUL2_0_MSCRn(SIUL2_MSCR_S32G_PA_06));

	writel(SIUL2_MSCR_S32G_PAD_CTL_SPI1_SIN,
	       SIUL2_0_MSCRn(SIUL2_MSCR_S32G_PF_15));

	writel(SIUL2_MSCR_S32G_PAD_CTL_SPI1_SCK,
	       SIUL2_0_MSCRn(SIUL2_MSCR_S32G_PA_08));

	/* IMCR */
	writel(SIUL2_IMCR_S32G_PAD_CTL_SPI1_SIN,
	       SIUL2_1_IMCRn(SIUL2_PF_15_IMCR_S32G_SPI1_SIN));

	/* Muxing for DSPI5 */

	/* Configure Chip Select Pins */
	writel(SUIL2_MSCR_S32G_PAD_CTL_SPI5_CS0,
	       SIUL2_0_MSCRn(SIUL2_MSCR_S32G_PA_12));

	/* MSCR */
	writel(SIUL2_MSCR_S32G_PAD_CTL_SPI5_SOUT,
	       SIUL2_0_MSCRn(SIUL2_MSCR_S32G_PA_11));

	writel(SIUL2_MSCR_S32G_PAD_CTL_SPI5_SIN,
	       SIUL2_0_MSCRn(SIUL2_MSCR_S32G_PA_10));

	writel(SIUL2_MSCR_S32G_PAD_CTL_SPI5_SCK,
	       SIUL2_0_MSCRn(SIUL2_MSCR_S32G_PA_09));

	/* IMCR */
	writel(SIUL2_IMCR_S32G_PAD_CTL_SPI5_SIN,
	       SIUL2_1_IMCRn(SIUL2_PA_10_IMCR_S32G_SPI5_SIN));
}
#endif

void setup_iomux_sdhc(void)
{
	/* Set iomux PADS for USDHC */

	/* PC14 pad: uSDHC SD0_CLK_O  */
	writel(SIUL2_USDHC_S32_G1_PAD_CTRL_CLK, SIUL2_0_MSCRn(46));

	/* PC15 pad: uSDHC SDO_CMD_0 */
	writel(SIUL2_USDHC_S32_G1_PAD_CTRL_CMD, SIUL2_0_MSCRn(47));
	writel(0x2, SIUL2_0_MSCRn(515));

	/* PD00 pad: uSDHC SD0_D_O[0] */
	writel(SIUL2_USDHC_S32_G1_PAD_CTRL_DATA, SIUL2_0_MSCRn(48));
	writel(0x2, SIUL2_0_MSCRn(516));

	/* PD01 pad: uSDHC SD0_D_O[1] */
	writel(SIUL2_USDHC_S32_G1_PAD_CTRL_DATA, SIUL2_0_MSCRn(49));
	writel(0x2, SIUL2_0_MSCRn(517));

	/* PD02 pad: uSDHC SD0_D_O[2] */
	writel(SIUL2_USDHC_S32_G1_PAD_CTRL_DATA, SIUL2_0_MSCRn(50));
	writel(0x2, SIUL2_0_MSCRn(520));

	/* PD03 pad: uSDHC SD0_D_O[3] */
	writel(SIUL2_USDHC_S32_G1_PAD_CTRL_DATA, SIUL2_0_MSCRn(51));
	writel(0x2, SIUL2_0_MSCRn(521));

	/* PD04 pad: uSDHC SD0_D_O[4] */
	writel(SIUL2_USDHC_S32_G1_PAD_CTRL_DATA, SIUL2_0_MSCRn(52));
	writel(0x2, SIUL2_0_MSCRn(522));

	/* PD05 pad: uSDHC SD0_D_O[5] */
	writel(SIUL2_USDHC_S32_G1_PAD_CTRL_DATA, SIUL2_0_MSCRn(53));
	writel(0x2, SIUL2_0_MSCRn(523));

	/* PD06 pad: uSDHC SD0_D_O[6] */
	writel(SIUL2_USDHC_S32_G1_PAD_CTRL_DATA, SIUL2_0_MSCRn(54));
	writel(0x2, SIUL2_0_MSCRn(519));

	/* PD07 pad: uSDHC SD0_D_O[7] */
	writel(SIUL2_USDHC_S32_G1_PAD_CTRL_DATA, SIUL2_0_MSCRn(55));
	writel(0x2, SIUL2_0_MSCRn(518));

	/* PD08 pad: uSDHC SDO_RST */
	writel(SIUL2_USDHC_S32_G1_PAD_RST, SIUL2_0_MSCRn(56));

	/* PD10 pad: uSDHC SD0_DQS_I */
	writel(0x2, SIUL2_0_MSCRn(524));
}