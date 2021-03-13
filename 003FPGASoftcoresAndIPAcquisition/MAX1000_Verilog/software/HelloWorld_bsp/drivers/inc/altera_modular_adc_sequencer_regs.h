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

#ifndef __ALTERA_MODULAR_ADC_SEQUENCER_REGS_H__
#define __ALTERA_MODULAR_ADC_SEQUENCER_REGS_H__

#include <io.h>

/*
 * Sequencer Core Command Register Register
 */
#define ALTERA_MODULAR_ADC_SEQUENCER_CMD_REG                    0
#define ALTERA_MODULAR_ADC_SEQUENCER_CMD_MSK                    (0x0000000F)

#define ALTERA_MODULAR_ADC_SEQUENCER_CMD_RUN_MSK                (0x00000001)
#define ALTERA_MODULAR_ADC_SEQUENCER_CMD_RUN_START              (0x00000001)
#define ALTERA_MODULAR_ADC_SEQUENCER_CMD_RUN_STOP               (0x00000000)

#define ALTERA_MODULAR_ADC_SEQUENCER_CMD_MODE_MSK               (0x0000000E)
#define ALTERA_MODULAR_ADC_SEQUENCER_CMD_MODE_CONTINUOUS        (0x00000000)
#define ALTERA_MODULAR_ADC_SEQUENCER_CMD_MODE_ONCE              (0x00000002)
#define ALTERA_MODULAR_ADC_SEQUENCER_CMD_MODE_RECALIBRATE       (0x0000000E)



/*
 * IO Read Write helper Macros
 */
#define IORD_ALTERA_MODULAR_ADC_SEQUENCER_CMD_REG(base) \
  IORD(base, ALTERA_MODULAR_ADC_SEQUENCER_CMD_REG)

#define IOWR_ALTERA_MODULAR_ADC_SEQUENCER_CMD_REG(base, data) \
  IOWR(base, ALTERA_MODULAR_ADC_SEQUENCER_CMD_REG, data)


/*
 * RUN - START/STOP helper Macros
 */
#define IORD_ALTERA_MODULAR_ADC_SEQUENCER_CMD_RUN_REG(base) \
        IORD_ALTERA_MODULAR_ADC_SEQUENCER_CMD_REG(base)     \
           & ALTERA_MODULAR_ADC_SEQUENCER_CMD_RUN_MSK

/*
 To Start the Sequencer Core
*/
#define ALTERA_MODULAR_ADC_SEQUENCER_START(base)      \
   IOWR_ALTERA_MODULAR_ADC_SEQUENCER_CMD_REG(base, (  \
   IORD_ALTERA_MODULAR_ADC_SEQUENCER_CMD_REG(base)    \
    & ~(ALTERA_MODULAR_ADC_SEQUENCER_CMD_RUN_MSK) )   \
      | ALTERA_MODULAR_ADC_SEQUENCER_CMD_RUN_START)

/*
 To Stop the Sequencer Core
 Step:
     1. Write 0 to RUN bit
     2. Poll the RUN bit until it read 0.
 */
#define ALTERA_MODULAR_ADC_SEQUENCER_STOP(base)       \
do {                                                  \
   IOWR_ALTERA_MODULAR_ADC_SEQUENCER_CMD_REG(base, (  \
   IORD_ALTERA_MODULAR_ADC_SEQUENCER_CMD_REG(base)    \
    & ~(ALTERA_MODULAR_ADC_SEQUENCER_CMD_RUN_MSK))    \
      | ALTERA_MODULAR_ADC_SEQUENCER_CMD_RUN_STOP);   \
   while(                                             \
   IORD_ALTERA_MODULAR_ADC_SEQUENCER_CMD_REG(base)    \
      & ALTERA_MODULAR_ADC_SEQUENCER_CMD_RUN_MSK);    \
} while (0)



/*
 * MODE - ONCE/CONTINUOUS helper Macros
 */

/*
 Set sequencer to run once only
*/
#define ALTERA_MODULAR_ADC_SEQUENCER_MODE_RUN_ONCE(base) \
   IOWR_ALTERA_MODULAR_ADC_SEQUENCER_CMD_REG(base, (     \
   IORD_ALTERA_MODULAR_ADC_SEQUENCER_CMD_REG(base)       \
    & ~(ALTERA_MODULAR_ADC_SEQUENCER_CMD_MODE_MSK) )     \
      | ALTERA_MODULAR_ADC_SEQUENCER_CMD_MODE_ONCE)

/*
 Set sequencer to run continuously
*/
#define ALTERA_MODULAR_ADC_SEQUENCER_MODE_RUN_CONTINUOUSLY(base) \
   IOWR_ALTERA_MODULAR_ADC_SEQUENCER_CMD_REG(base, (             \
   IORD_ALTERA_MODULAR_ADC_SEQUENCER_CMD_REG(base)               \
    & ~(ALTERA_MODULAR_ADC_SEQUENCER_CMD_MODE_MSK) )             \
      | ALTERA_MODULAR_ADC_SEQUENCER_CMD_MODE_CONTINUOUS)

/*
 Set sequencer to recalibration mode
*/
#define ALTERA_MODULAR_ADC_SEQUENCER_MODE_RUN_RECALIBRATION(base) \
   IOWR_ALTERA_MODULAR_ADC_SEQUENCER_CMD_REG(base, (              \
   IORD_ALTERA_MODULAR_ADC_SEQUENCER_CMD_REG(base)                \
    & ~(ALTERA_MODULAR_ADC_SEQUENCER_CMD_MODE_MSK) )              \
      | ALTERA_MODULAR_ADC_SEQUENCER_CMD_MODE_RECALIBRATE)

#endif /* __ALTERA_MODULAR_ADC_SEQUENCER_REGS_H__ */
