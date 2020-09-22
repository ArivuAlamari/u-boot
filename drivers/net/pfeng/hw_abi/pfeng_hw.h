/* SPDX-License-Identifier: GPL 2.0 OR BSD-3-Clause */
/*
 *  Copyright 2018-2020 NXP
 */

/**
 * @brief	The PFE hw
 * @details	This SW module is intended to provide full PFE HW
 *		abstraction layer. Using this module's API one is able to
 *		configure, control and encapsulate particular
 *		PFE HW components like classifier,
 *		GPI or HIF as a single object.
 *
 *		Module can be used to create and maintain various PFE instances
 *		depending on currently used HW platform or HW configuration
 *		without need to modify upper or application-level SW layers.
 *
 *		Module consists of following components:
 *		- pfe_pe - A generic processing engine representation
 *		- pfe_class - The CLASS block
 *		- pfe_rtable - The routing table
 *		- pfe_tmu - The TMU block
 *		- pfe_util - The UTIL block
 *		- pfe_bmu - The BMU block
 *		- pfe_gpi - The GPI block
 *		- pfe_util - The UTIL block
 *		- pfe_emac - The EMAC block
 *		- pfe_hif - The HIF block
 *		- pfe_hif_chnl - The HIF channel
 *		- pfe_hif_ring - The HIF BD ring
 *		- pfe_wdt - The WDT block
 *
 *		These components can be used to synthesize SW representation of
 *		a PPFE HW block using hierarchical structure where top level is
 *		the PFE platform object.
 *
 */

#ifndef SRC_PFE_PLATFORM_H_
#define SRC_PFE_PLATFORM_H_

#include "pfe_ct.h"
#include "pfe_hif_ring.h"
#include "pfe_platform_cfg.h"

struct pfe_fw {
	char *version;     /* free text: version */
	char *source;	     /* free text: filename, filepath, ... etc */
	void *class_data;    /* The CLASS fw data buffer */
	u32 class_size; /* The CLASS fw data size */
};

struct pfe_platform_config {
	u64 cbus_base;	/* PFE control bus base address */
	u64 cbus_len;	/* PFE control bus size */
	char *fw_name;	/* FW name */
	struct pfe_fw *fw;		/* Required firmware, embedded */
};

struct pfe_platform {
	bool probed;
	void *cbus_baseaddr;
	struct pfe_ct_pe_mmap *memmap;
	void *bmu_buffers_va;
	u64 bmu_buffers_size;
	u32 hif_chnl_count; /* Number of HIF channels */
	u32 emac_count;	    /* Number of EMAC blocks */
	u32 gpi_total;	    /* Number of GPI/ETGPI/HGPI blocks */
	u32 gpi_count;	    /* Number of GPI blocks */
	u32 etgpi_count;	    /* Number of ETGPI blocks */
	u32 hgpi_count;	    /* Number of HGPI blocks */
	u32 bmu_count;	    /* Number of BMU blocks */
	u32 class_pe_count;    /* Number of CLASS PEs */
	u32 sch_per_phy;    /* Number of schedulers per phy */
	u32 shape_per_phy;    /* Number of schedulers per phy */
	u32 util_pe_count;	    /* Number of UTIL PEs */
	u32 tmu_pe_count;	    /* Number of TMU PEs */
	u8 hif_chnl;		/* HIF channel to be used by u-boot */
	struct pfe_fw *fw;
	void **bmu_base;	   /* The BMU blocks base */
	void **gpi_base;	   /* The GPI blocks base */
	void **emac_base;	   /* The EMAC blocks base */
	void *hif_base;
};

/* Eth driver functionality */
int pfeng_hw_start(struct pfe_platform *platform, int emac, u8 *ea);
int pfeng_hw_stop(struct pfe_platform *platform, int emac);
int pfeng_hw_attach_ring(struct pfe_platform *platform,
			 void *tx_ring, void *tx_ring_wb,
			 void *rx_ring, void *rx_ring_wb);

/* Mdio functionality */
int pfeng_hw_emac_mdio_read(void *base_va, u8 pa, u8 dev, u16 ra, u16 *val);
int pfeng_hw_emac_mdio_write(void *base_va, u8 pa, u8 dev, u16 ra, u16 val);

/* Init functionality */
int pfeng_hw_init(struct pfe_platform_config *config);
int pfeng_hw_soft_reset(struct pfe_platform *platform);
int pfeng_hw_remove(void);
struct pfe_platform *pfeng_hw_get_instance(void);
int pfeng_hw_debug(struct pfe_platform *platform);

#endif /* SRC_PFE_PLATFORM_H_ */

/** @}*/
