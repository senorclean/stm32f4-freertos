/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Frantisek Burian <BuFran@seznam.cz>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DWT_H_
#define DWT_H_

#include "memory_map.h"

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

#define DWT_CTRL			(DWT_BASE + 0x00)
#define DWT_CYCCNT			(DWT_BASE + 0x04)
#define DWT_CPICNT			(DWT_BASE + 0x08)
#define DWT_EXCCNT			(DWT_BASE + 0x0C)
#define DWT_SLEEPCNT			(DWT_BASE + 0x10)
#define DWT_LSUCNT			(DWT_BASE + 0x14)
#define DWT_FOLDCNT			(DWT_BASE + 0x18)
#define DWT_PCSR			(DWT_BASE + 0x1C)
#define DWT_COMP(n)			(DWT_BASE + 0x20 + (n) * 16)
#define DWT_MASK(n)			(DWT_BASE + 0x24 + (n) * 16)
#define DWT_FUNCTION(n)			(DWT_BASE + 0x28 + (n) * 16)

#define DWT_DEMCR   (DWT_BASE + 0xEDFC)


/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* --- DWT_CTRL values ---------------------------------------------------- */

#define DWT_CTRL_NUMCOMP_SHIFT		28
#define DWT_CTRL_NUMCOMP		(0x0F << DWT_CTRL_NUMCOMP_SHIFT)

#define DWT_CTRL_NOTRCPKT		(1 << 27)
#define DWT_CTRL_NOEXTTRIG		(1 << 26)
#define DWT_CTRL_NOCYCCNT		(1 << 25)
#define DWT_CTRL_NOPRFCCNT		(1 << 24)

#define DWT_CTRL_CYCEVTENA		(1 << 22)
#define DWT_CTRL_FOLDEVTENA		(1 << 21)
#define DWT_CTRL_LSUEVTENA		(1 << 20)
#define DWT_CTRL_SLEEPEVTENA		(1 << 19)
#define DWT_CTRL_EXCEVTENA		(1 << 18)
#define DWT_CTRL_CPIEVTENA		(1 << 17)
#define DWT_CTRL_EXCTRCENA		(1 << 16)
#define DWT_CTRL_PCSAMPLENA		(1 << 12)

#define DWT_CTRL_SYNCTAP_SHIFT		10
#define DWT_CTRL_SYNCTAP		(3 << DWT_CTRL_SYNCTAP_SHIFT)
#define DWT_CTRL_SYNCTAP_DISABLED	(0 << DWT_CTRL_SYNCTAP_SHIFT)
#define DWT_CTRL_SYNCTAP_BIT24		(1 << DWT_CTRL_SYNCTAP_SHIFT)
#define DWT_CTRL_SYNCTAP_BIT26		(2 << DWT_CTRL_SYNCTAP_SHIFT)
#define DWT_CTRL_SYNCTAP_BIT28		(3 << DWT_CTRL_SYNCTAP_SHIFT)

#define DWT_CTRL_CYCTAP			(1 << 9)

#define DWT_CTRL_POSTCNT_SHIFT		5
#define DWT_CTRL_POSTCNT		(0x0F << DWT_CTRL_POSTCNT_SHIFT)

#define DWT_CTRL_POSTPRESET_SHIFT	1
#define DWT_CTRL_POSTPRESET		(0x0F << DWT_CTRL_POSTPRESET_SHIFT)

#define DWT_CTRL_CYCCNTENA		(1 << 0)

/* --- DWT_MASK(x) values -------------------------------------------------- */

#define DWT_MASKx_MASK			0x0F

/* --- DWT_FUNCTION(x) values ---------------------------------------------- */

#define DWT_FUNCTIONx_MATCHED		(1 << 24)

#define DWT_FUNCTIONx_DATAVADDR1_SHIFT	16
#define DWT_FUNCTIONx_DATAVADDR1	(15 << DWT_FUNCTIONx_DATAVADDR1_SHIFT)

#define DWT_FUNCTIONx_DATAVADDR0_SHIFT	12
#define DWT_FUNCTIONx_DATAVADDR0	(15 << DWT_FUNCTIONx_DATAVADDR0_SHIFT)

#define DWT_FUNCTIONx_DATAVSIZE_SHIFT	10
#define DWT_FUNCTIONx_DATAVSIZE		(3 << DWT_FUNCTIONx_DATAVSIZE_SHIFT)
#define DWT_FUNCTIONx_DATAVSIZE_BYTE	(0 << DWT_FUNCTIONx_DATAVSIZE_SHIFT)
#define DWT_FUNCTIONx_DATAVSIZE_HALF	(1 << DWT_FUNCTIONx_DATAVSIZE_SHIFT)
#define DWT_FUNCTIONx_DATAVSIZE_WORD	(2 << DWT_FUNCTIONx_DATAVSIZE_SHIFT)

#define DWT_FUNCTIONx_LNK1ENA		(1 << 9)
#define DWT_FUNCTIONx_DATAVMATCH	(1 << 8)
#define DWT_FUNCTIONx_CYCMATCH		(1 << 7)
#define DWT_FUNCTIONx_EMITRANGE		(1 << 5)

#define DWT_FUNCTIONx_FUNCTION				15
#define DWT_FUNCTIONx_FUNCTION_DISABLED			0

#endif /* LIBOPENCM3_CM3_DWT_H */
