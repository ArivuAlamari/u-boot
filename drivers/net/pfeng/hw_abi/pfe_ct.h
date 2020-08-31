/* SPDX-License-Identifier: GPL 2.0 OR BSD-3-Clause */
/*
 *  Copyright 2018-2020 NXP
 *
 */

/**
 * @addtogroup  dxgr_PFE_PLATFORM
 * @{
 *
 * @file		pfe_ct.h
 * @brief		Common types (s32g).
 * @details		This header contains data types shared by host as well
 *			as PFE firmware.
 *
 */

#ifndef HW_S32G_PFE_CT_H_
#define HW_S32G_PFE_CT_H_

#include "pfe_compiler.h"
#if (!defined(PFE_COMPILER_BITFIELD_BEHAVIOR))
#error PFE_COMPILER_BITFIELD_BEHAVIOR is not defined
#endif
#if (!defined(PFE_COMPILER_BITFIELD_HIGH_FIRST))
#error PFE_COMPILER_BITFIELD_HIGH_FIRST is not defined
#endif
#if (!defined(PFE_COMPILER_BITFIELD_HIGH_LAST))
#error PFE_COMPILER_BITFIELD_HIGH_LAST is not defined
#endif
#if (PFE_COMPILER_BITFIELD_HIGH_LAST == PFE_COMPILER_BITFIELD_HIGH_FIRST)
#error PFE_COMPILER_BITFIELD_HIGH_LAST == PFE_COMPILER_BITFIELD_HIGH_FIRST
#endif
#if (!defined(PFE_COMPILER_RESULT))
#error PFE_COMPILER_RESULT is not defined
#endif
#if (!defined(PFE_COMPILER_RESULT_FW))
#error PFE_COMPILER_RESULT_FW is not defined
#endif
#if (!defined(PFE_COMPILER_RESULT_DRV))
#error PFE_COMPILER_RESULT_DRV is not defined
#endif
#if (PFE_COMPILER_RESULT_DRV == PFE_COMPILER_RESULT_FW)
#error PFE_COMPILER_RESULT_DRV is equal to PFE_COMPILER_RESULT_FW
#endif

#if PFE_COMPILER_RESULT == PFE_COMPILER_RESULT_DRV
/* Compiling for the driver */
#include "oal_types.h"
#else
#error Ambiguous value of PFE_COMPILER_RESULT
#endif

/* Interfaces */
#define PFE_PHY_IF_ID_EMAC0	0
#define	PFE_PHY_IF_ID_EMAC1	1
#define	PFE_PHY_IF_ID_EMAC2	2

#define	PFE_PHY_IF_ID_HIF	3
#define	PFE_PHY_IF_ID_HIF_NOCPY	3
#define	PFE_PHY_IF_ID_UTIL	5

#define	PFE_PHY_IF_ID_HIF0	6
#define	PFE_PHY_IF_ID_HIF1	7
#define	PFE_PHY_IF_ID_HIF2	8
#define	PFE_PHY_IF_ID_HIF3	9

#define	PFE_PHY_IF_ID_MAX	PFE_PHY_IF_ID_HIF3
#define	PFE_PHY_IF_ID_INVALID	(PFE_PHY_IF_ID_MAX + 1)


/* Operation modes */
#define IF_OP_DEFAULT		1

/* Interface flags */
#define IF_FL_ENABLED		BIT(0)

/* Tx header flags*/
#define HIF_TX_INJECT		BIT(6)


/**
 * @brief Firmware logical interface
 */
struct pfe_ct_log_if {
	u32 next;
	u32 e_phy_ifs;
	u8 reserved[76] __aligned(4);
	u8 id;
	u8 mode;
	u8 flags;
	u32 m_rules;
	u32 class_stats[4] __aligned(4);
} __packed __aligned(4);

_ct_assert(sizeof(struct pfe_ct_log_if) == 108);

/**
 * @brief Firmware physical interface
 */
struct pfe_ct_phy_if {
	u32 log_ifs;
	u32 def_log_if;
	u8 id;
	u8 mode;
	u8 flags;
	u8 block_state;
	u8 mirror;
	u8 reserved[3];
	u32 phy_stats[4] __aligned(4);
} __packed __aligned(4);

_ct_assert(sizeof(struct pfe_ct_phy_if) == 32);


/**
 * @brief Firmware version information
 */
struct pfe_ct_version {
	/*	ID */
	u32 id;
	/*	Revision info */
	u8 major;
	u8 minor;
	u8 patch;
	u8 res;
	/*	Firmware properties */
	u32 flags;
	/*	Build date and time */
	u8 build_date[16];
	u8 build_time[16];
	/*	Version control ID (e.g. GIT commit) */
	char_t vctrl[16];
	/*  This header version */
	char_t cthdr[36];
} __packed;

_ct_assert(sizeof(struct pfe_ct_version) == 96);


/**
 * @brief PE memory map representation type shared between host and PFE
 */
struct pfe_ct_pe_mmap {
	/*	Size of the structure in number of bytes */
	u32 size;
	/*	Version information */
	struct pfe_ct_version version;
	/*	Pointer to DMEM heap */
	u32 dmem_heap_base;
	/*	DMEM heap size in number of bytes */
	u32 dmem_heap_size;
	/*	Pointer to array of physical interfaces */
	u32 dmem_phy_if_base;
	/*	Physical interfaces memory space size in number of bytes */
	u32 dmem_phy_if_size;
	u8 fill[48];
} __packed __aligned(4);

_ct_assert(sizeof(struct pfe_ct_pe_mmap) == 164);

/**
 * @brief	HIF RX packet header
 */
struct pfe_ct_hif_rx_hdr {
	/*	Punt reason flags */
	u16 punt_reasons;
	/*	Ingress physical interface ID */
	u8 i_phy_if;
	/*	Ingress logical interface ID */
	u8 i_log_if;
	/*	Rx frame flags */
	u16 flags;
	/*	Reserved */
	u8 reserved[2];
	/*	RX timestamp */
	u32 rx_timestamp_ns;
	u32 rx_timestamp_s;
} __packed;

_ct_assert(sizeof(struct pfe_ct_hif_rx_hdr) == 16);

/**
 * @brief	HIF TX packet header
 */
struct pfe_ct_hif_tx_hdr {
	u8 flags;
	u8 queue;
	u8 chid;
	u8 reserved1;
	u16 reserved2;
	u16 refnum;
	u32 e_phy_ifs;
	u32 cookie;
} __aligned(4);

_ct_assert(sizeof(struct pfe_ct_hif_tx_hdr) == 16);
_ct_assert(0 == (sizeof(struct pfe_ct_hif_tx_hdr) % sizeof(uint32_t)));
#endif /* HW_S32G_PFE_CT_H_ */
/** @} */
