/*
 * Copyright 2013-2015 Freescale Semiconductor, Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

void init_mmu(void);
void enable_mmu(void);
void invalidate_all_tlb(void);
void enable_DDRWorkaround(void);

#define MMU_PAGE_TABLE_LEVEL_2_DESC_BASE_ADDR_SHIFT		(10)
#define MMU_PAGE_TABLE_LEVEL_2_DESC_BASE_ADDR_MASK		((0x3fffff) << (MMU_PAGE_TABLE_LEVEL_2_DESC_BASE_ADDR_SHIFT))

#define MMU_PAGE_TABLE_P_SHIFT							(9)
#define MMU_PAGE_TABLE_P_MASK							((0x1) << (MMU_PAGE_TABLE_P_SHIFT))

#define MMU_PAGE_TABLE_DOMAIN_SHIFT						(5)
#define MMU_PAGE_TABLE_DOMAIN_MASK						((0xf) << (MMU_PAGE_TABLE_DOMAIN_SHIFT))

#define MMU_PAGE_TABLE_ENTRY_TYPE_SHIFT					(0)
#define MMU_PAGE_TABLE_ENTRY_TYPE_MASK					((0x3) << (MMU_PAGE_TABLE_ENTRY_TYPE_SHIFT))

#define MMU_SECTION_SECTION_BASE_ADDR_SHIFT				(20)
#define MMU_SECTION_SECTION_BASE_ADDR_MASK				((0xfff) << (MMU_SECTION_SECTION_BASE_ADDR_SHIFT))

#define MMU_SECTION_TABLE_ENTRY_TYPE_A_SHIFT			(18)
#define MMU_SECTION_TABLE_ENTRY_TYPE_A_MASK				((0x1) << (MMU_SECTION_SECTION_BASE_ADDR_SHIFT))

#define MMU_SECTION_NG_SHIFT							(17)
#define MMU_SECTION_NG_MASK								((0x1) << (MMU_SECTION_NG_SHIFT))

#define MMU_SECTION_S_SHIFT								(16)
#define MMU_SECTION_S_MASK								((0x1) << (MMU_SECTION_S_SHIFT))

#define MMU_SECTION_APX_SHIFT							(15)
#define MMU_SECTION_APX_MASK							((0x1) << (MMU_SECTION_APX_SHIFT))

#define MMU_SECTION_TEX_SHIFT							(12)
#define MMU_SECTION_TEX_MASK							((0x7) << (MMU_SECTION_TEX_SHIFT))

#define MMU_SECTION_AP_SHIFT							(10)
#define MMU_SECTION_AP_MASK								((0x3) << (MMU_SECTION_AP_SHIFT))

#define MMU_SECTION_P_SHIFT								(9)
#define MMU_SECTION_P_MASK								((0x1) << (MMU_SECTION_P_SHIFT))

#define MMU_SECTION_DOMAIN_SHIFT						(5)
#define MMU_SECTION_DOMAIN_MASK							((0xf) << (MMU_SECTION_DOMAIN_SHIFT))

#define MMU_SECTION_XN_SHIFT							(4)
#define MMU_SECTION_XN_MASK								((0x1) << (MMU_SECTION_XN_SHIFT))

#define MMU_SECTION_C_SHIFT								(3)
#define MMU_SECTION_C_MASK								((0x1) << (MMU_SECTION_C_SHIFT))

#define MMU_SECTION_B_SHIFT								(2)
#define MMU_SECTION_B_MASK								((0x1) << (MMU_SECTION_B_SHIFT))

#define MMU_SECTION_ENTRY_TYPE_SHIFT					(0)
#define MMU_SECTION_ENTRY_TYPE_MASK						((0x3) << (MMU_SECTION_ENTRY_TYPE_SHIFT))

#define MMU_SUPER_SECTION_SUPER_SECTION_BASE_ADDR_SHIFT			(24)
#define MMU_SUPER_SECTION_SUPER_SECTION_BASE_ADDR_MASK			((0xff) << (MMU_SUPER_SECTION_SUPER_SECTION_BASE_ADDR_SHIFT))

#define MMU_SUPER_SECTION_TABLE_ENTRY_TYPE_A_SHIFT				(18)
#define MMU_SUPER_SECTION_TABLE_ENTRY_TYPE_A_MASK				((0x1) << (MMU_SUPER_SECTION_SUPER_SECTION_BASE_ADDR_SHIFT))

#define MMU_SUPER_SECTION_NG_SHIFT								(17)
#define MMU_SUPER_SECTION_NG_MASK								((0x1) << (MMU_SUPER_SECTION_NG_SHIFT))

#define MMU_SUPER_SECTION_S_SHIFT								(16)
#define MMU_SUPER_SECTION_S_MASK								((0x1) << (MMU_SUPER_SECTION_S_SHIFT))

#define MMU_SUPER_SECTION_APX_SHIFT								(15)
#define MMU_SUPER_SECTION_APX_MASK								((0x1) << (MMU_SUPER_SECTION_APX_SHIFT))

#define MMU_SUPER_SECTION_TEX_SHIFT								(12)
#define MMU_SUPER_SECTION_TEX_MASK								((0x7) << (MMU_SUPER_SECTION_TEX_SHIFT))

#define MMU_SUPER_SECTION_AP_SHIFT								(10)
#define MMU_SUPER_SECTION_AP_MASK								((0x3) << (MMU_SUPER_SECTION_AP_SHIFT))

#define MMU_SUPER_SECTION_P_SHIFT								(9)
#define MMU_SUPER_SECTION_P_MASK								((0x1) << (MMU_SUPER_SECTION_P_SHIFT))

#define MMU_SUPER_SECTION_DOMAIN_SHIFT							(5)
#define MMU_SUPER_SECTION_DOMAIN_MASK							((0xf) << (MMU_SUPER_SECTION_DOMAIN_SHIFT))

#define MMU_SUPER_SECTION_XN_SHIFT								(4)
#define MMU_SUPER_SECTION_XN_MASK								((0x1) << (MMU_SUPER_SECTION_XN_SHIFT))

#define MMU_SUPER_SECTION_C_SHIFT								(3)
#define MMU_SUPER_SECTION_C_MASK								((0x1) << (MMU_SUPER_SECTION_C_SHIFT))

#define MMU_SUPER_SECTION_B_SHIFT								(2)
#define MMU_SUPER_SECTION_B_MASK								((0x1) << (MMU_SUPER_SECTION_B_SHIFT))

#define MMU_SUPER_SECTION_ENTRY_TYPE_SHIFT						(0)
#define MMU_SUPER_SECTION_ENTRY_TYPE_MASK						((0x3) << (MMU_SUPER_SECTION_ENTRY_TYPE_SHIFT))

#define MMU_LARGE_PAGE_LARGE_PAGE_BASE_ADDR_SHIFT				(16)
#define MMU_LARGE_PAGE_LARGE_PAGE_BASE_ADDR_MASK				((0xffff) << (MMU_LARGE_PAGE_LARGE_PAGE_BASE_ADDR_SHIFT))

#define MMU_LARGE_PAGE_XN_SHIFT									(15)
#define MMU_LARGE_PAGE_XN_MASK									((0x1) << (MMU_LARGE_PAGE_XN_SHIFT))

#define MMU_LARGE_PAGE_TEX_SHIFT								(12)
#define MMU_LARGE_PAGE_TEX_MASK									((0x7) << (MMU_LARGE_PAGE_TEX_SHIFT))

#define MMU_LARGE_PAGE_NG_SHIFT									(11)
#define MMU_LARGE_PAGE_NG_MASK									((0x1) << (MMU_LARGE_PAGE_NG_SHIFT))

#define MMU_LARGE_PAGE_S_SHIFT									(10)
#define MMU_LARGE_PAGE_S_MASK									((0x1) << (MMU_LARGE_PAGE_S_SHIFT))

#define MMU_LARGE_PAGE_APX_SHIFT								(9)
#define MMU_LARGE_PAGE_APX_MASK									((0x1) << (MMU_LARGE_PAGE_APX_SHIFT))

#define MMU_LARGE_PAGE_AP_SHIFT									(4)
#define MMU_LARGE_PAGE_AP_MASK									((0x3) << (MMU_LARGE_PAGE_AP_SHIFT))

#define MMU_LARGE_PAGE_C_SHIFT									(3)
#define MMU_LARGE_PAGE_C_MASK									((0x1) << (MMU_LARGE_PAGE_C_SHIFT))

#define MMU_LARGE_PAGE_B_SHIFT									(2)
#define MMU_LARGE_PAGE_B_MASK									((0x1) << (MMU_LARGE_PAGE_B_SHIFT))

#define MMU_LARGE_PAGE_ENTRY_TYPE_SHIFT							(0)
#define MMU_LARGE_PAGE_ENTRY_TYPE_MASK							((0x3) << (MMU_LARGE_PAGE_ENTRY_TYPE_SHIFT))

#define MMU_SMALL_PAGE_SMALL_PAGE_BASE_ADDR_SHIFT				(12)
#define MMU_SMALL_PAGE_SMALL_PAGE_BASE_ADDR_MASK				((0xfffff) << (MMU_SMALL_PAGE_SMALL_PAGE_BASE_ADDR_SHIFT))

#define MMU_SMALL_PAGE_NG_SHIFT									(11)
#define MMU_SMALL_PAGE_NG_MASK									((0x1) << (MMU_SMALL_PAGE_NG_SHIFT))

#define MMU_SMALL_PAGE_S_SHIFT									(10)
#define MMU_SMALL_PAGE_S_MASK									((0x1) << (MMU_SMALL_PAGE_S_SHIFT))

#define MMU_SMALL_PAGE_APX_SHIFT								(9)
#define MMU_SMALL_PAGE_APX_MASK									((0x1) << (MMU_SMALL_PAGE_APX_SHIFT))

#define MMU_SMALL_PAGE_TEX_SHIFT								(6)
#define MMU_SMALL_PAGE_TEX_MASK									((0x7) << (MMU_SMALL_PAGE_TEX_SHIFT))

#define MMU_SMALL_PAGE_AP1_SHIFT								(5)
#define MMU_SMALL_PAGE_AP1_MASK									((0x1) << (MMU_SMALL_PAGE_AP1_SHIFT))

#define MMU_SMALL_PAGE_AP0_SHIFT								(4)
#define MMU_SMALL_PAGE_AP0_MASK									((0x1) << (MMU_SMALL_PAGE_AP0_SHIFT))

#define MMU_SMALL_PAGE_AP_SHIFT									(4)
#define MMU_SMALL_PAGE_AP_MASK									((0x3) << (MMU_SMALL_PAGE_AP_SHIFT))


#define MMU_SMALL_PAGE_C_SHIFT									(3)
#define MMU_SMALL_PAGE_C_MASK									((0x1) << (MMU_SMALL_PAGE_C_SHIFT))

#define MMU_SMALL_PAGE_B_SHIFT									(2)
#define MMU_SMALL_PAGE_B_MASK									((0x1) << (MMU_SMALL_PAGE_B_SHIFT))

#define MMU_SMALL_PAGE_ENTRY_TYPE_SHIFT							(1)
#define MMU_SMALL_PAGE_ENTRY_TYPE_MASK							((0x1) << (MMU_SMALL_PAGE_ENTRY_TYPE_SHIFT))

#define MMU_SMALL_PAGE_XN_SHIFT									(0)
#define MMU_SMALL_PAGE_XN_MASK									((0x1) << (MMU_SMALL_PAGE_XN_SHIFT))

/* define for APX/AP bit setting*/
#define MMU_AP_PERMISSION_FAULT									0
#define MMU_AP_PRIVILEGED_ACCESS_ONLY							1
#define MMU_AP_NO_USER_MODE_WRITE								2
#define MMU_AP_FULL_ACCESS										3
#define MMU_AP_RESERVED_1										4
#define MMU_AP_PRIVILEGED_READ_ONLY								5
#define MMU_AP_READ_ONLY										6
#define MMU_AP_RESERVED_2										7
