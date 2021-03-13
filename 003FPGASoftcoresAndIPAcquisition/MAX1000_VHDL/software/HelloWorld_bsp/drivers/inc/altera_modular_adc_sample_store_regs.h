/******************************************************************************
*                                                                             *
* License Agreement                                                           *
*                                                                             *
* Copyright (c) 2014 Altera Corporation, San Jose, California, USA.           *
* All rights reserved.                                                        *
*                                                                             *
* Permission is hereby granted, free of charge, to any person obtaining a     *
* copy of this software and associated documentation files (the "Software"),  *
* to deal in the Software without restriction, including without limitation   *
* the rights to use, copy, modify, merge, publish, distribute, sublicense,    *
* and/or sell copies of the Software, and to permit persons to whom the       *
* Software is furnished to do so, subject to the following conditions:        *
*                                                                             *
* The above copyright notice and this permission notice shall be included in  *
* all copies or substantial portions of the Software.                         *
*                                                                             *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  *
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,    *
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE *
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER      *
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING     *
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER         *
* DEALINGS IN THE SOFTWARE.                                                   *
*                                                                             *
* This agreement shall be governed in all respects by the laws of the State   *
* of California and by the laws of the United States of America.              *
*                                                                             *
******************************************************************************/

#ifndef __ALTERA_MODULAR_ADC_SAMPLE_STORE_REGS_H__
#define __ALTERA_MODULAR_ADC_SAMPLE_STORE_REGS_H__

#include <io.h>

/*
 * Sample Store Core Registers Definition
 */
#define ALTERA_MODULAR_ADC_SAMPLE_STORAGE_REG                   0
#define ALTERA_MODULAR_ADC_SAMPLE_STORAGE_MSK                   (0x00000FFF)
#define ALTERA_MODULAR_ADC_SAMPLE_STORAGE_FIRST_SLOT            0
#define ALTERA_MODULAR_ADC_SAMPLE_STORAGE_LAST_SLOT             63

#define ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_ENABLE_REG        0x40
#define ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_ENABLE_MSK        (0x00000001)
#define ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_ENABLED           (0x00000001)
#define ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_DISABLED          (0x00000000)

#define ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_STATUS_REG        0x41
#define ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_STATUS_MSK        (0x00000001)
#define ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_STATUS_W1C        (0x00000001)

/*
 * IO Read Write helper Macros
 */
#define IORD_ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_ENABLE_REG(base) \
  IORD(base, ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_ENABLE_REG)

#define IOWR_ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_ENABLE_REG(base, data) \
  IOWR(base, ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_ENABLE_REG, data)

#define IORD_ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_STATUS_REG(base) \
  IORD(base, ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_STATUS_REG)

#define IOWR_ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_STATUS_REG(base, data) \
  IOWR(base, ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_STATUS_REG, data)

/*
 To Enable Interrupt
*/
#define ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_ENABLE(base)        \
   IOWR_ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_ENABLE_REG(base, (  \
   IORD_ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_ENABLE_REG(base)    \
    & ~(ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_ENABLE_MSK) )       \
      | ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_ENABLED)

/*
 To Disable Interrupt
*/
#define ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_DISABLE(base)       \
   IOWR_ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_ENABLE_REG(base, (  \
   IORD_ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_ENABLE_REG(base)    \
    & ~(ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_ENABLE_MSK) )       \
      | ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_DISABLED)

/*
 To Read Interrupt Status bit
*/
#define READ_ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_STATUS(base) ( \
        IORD_ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_STATUS_REG(base) \
           & ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_STATUS_MSK   )

/*
 To Clear Interrupt Status bit
*/
#define CLEAR_ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_STATUS(base)  \
   IOWR_ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_STATUS_REG(base, (  \
   IORD_ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_STATUS_REG(base)    \
    & ~(ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_STATUS_MSK) )       \
      | ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_STATUS_W1C)

/*
 To Poll Interrupt Status bit until it become 1
 */
#define WAIT_FOR_ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ(base) \
    while((READ_ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_STATUS(base))==0)


#endif /* __ALTERA_MODULAR_ADC_SAMPLE_STORE_REGS_H__ */
