/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright 2017-2021 NXP
 */

/*
 * Configuration settings for all the Freescale S32G274A boards.
 */

#ifndef __S32G274A_H
#define __S32G274A_H

#ifdef CONFIG_PCIE_S32GEN1
#define PCIE_MSIS_ENV_SETTINGS	\
	PCIE_SET_MSI_CONTROLLER \
	"fdt_pcie0_spis_fixup=pcie_addr=40400000; run fdt_pcie_set_gic; \0" \
	"fdt_pcie1_spis_fixup=pcie_addr=44100000; run fdt_pcie_set_gic; \0"
#endif

#include <configs/s32-gen1.h>

#if !defined(CONFIG_PRAM) && !defined(CONFIG_S32_SKIP_RELOC)

/* 24 MB covering the following:
 *  - 22 MB for optee_os + shared memory between optee_os and linux kernel
 *  - 2 MB for the Secure Monitor
 */
#define CONFIG_PRAM	24576	/* 24MB */
#endif

#if defined(CONFIG_TARGET_S32G274AEVB) && defined(CONFIG_USB)
#define CONFIG_USB_EHCI_MX6
#define CONFIG_MXC_USB_PORTSC        PORT_PTS_ULPI
#endif

#endif
