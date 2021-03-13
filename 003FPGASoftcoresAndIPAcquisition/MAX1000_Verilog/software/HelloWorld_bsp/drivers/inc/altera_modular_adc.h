/******************************************************************************
*                                                                             *
* License Agreement                                                           *
*                                                                             *
* Copyright (c) 2015 Altera Corporation, San Jose, California, USA.           *
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

#ifndef __ALT_MODULAR_ADC_H__
#define __ALT_MODULAR_ADC_H__

#include <stddef.h>
#include "priv/alt_dev_llist.h"
#include "sys/alt_dev.h"
#include "os/alt_sem.h"
#include "altera_modular_adc_sequencer_regs.h"
#include "altera_modular_adc_sample_store_regs.h"
#include "alt_types.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/* Callback routine type definition */
typedef void (*alt_adc_callback)(void *context);

typedef struct alt_modular_adc_dev
{
    alt_dev              dev;
    /* Callback routine pointer */
    alt_adc_callback     callback;
    /* Callback context pointer */
    void                 *callback_context;
    /* Base address of the sample store micro core */
    alt_u32              sample_store_base;
   /* Base address of the sequencer micro core */
    alt_u32	         sequencer_csr_base;
   /* Dual ADC mode enable status */
    alt_u8               DUAL_ADC_MODE;
} alt_modular_adc_dev;

/*
 * Public APIs
 */
void adc_stop(int sequencer_base);
void adc_start(int sequencer_base);
void adc_set_mode_run_once(int sequencer_base);
void adc_set_mode_run_continuously(int sequencer_base);
void adc_recalibrate(int sequencer_base);
void adc_interrupt_enable(int sample_store_base);
void adc_interrupt_disable(int sample_store_base);
void adc_clear_interrupt_status(int sample_store_base);
void adc_wait_for_interrupt(int sample_store_base);
int adc_interrupt_asserted(int sample_store_base);
alt_modular_adc_dev* altera_modular_adc_open (const char *name);
void alt_adc_register_callback(
	alt_modular_adc_dev *dev,
	alt_adc_callback callback,
	void *context,
	alt_u32 sample_store_base);
int alt_adc_word_read (alt_u32 sample_store_base, alt_u32* source_ptr, alt_u32 len);

void altera_modular_adc_init(alt_modular_adc_dev* dev, alt_32 ic_id, alt_32 irq);
/*
 *   Use by alt_sys_init.c
 *
 */

#define ALTERA_MODULAR_ADC_INSTANCE(name, dev) \
static alt_modular_adc_dev dev =       \
{                                      \
  {                                    \
    ALT_LLIST_ENTRY,                   \
    name##_SEQUENCER_CSR_NAME,         \
    NULL,                              \
    NULL,                              \
    NULL,                              \
    NULL,                              \
    NULL,                              \
    NULL,                              \
    NULL,                              \
  },                                   \
   NULL,                               \
   NULL,                               \
   0,                                  \
   0,                                  \
   name##_SEQUENCER_CSR_DUAL_ADC_MODE  \
}


/*
 * The macro ALTERA_MODULAR_ADC_INIT is called by the auto-generated function
 * alt_sys_init() to initialize a given device instance.
 */
#define ALTERA_MODULAR_ADC_INIT(name, dev) \
 altera_modular_adc_init(&dev, name##_SAMPLE_STORE_CSR_IRQ_INTERRUPT_CONTROLLER_ID, name##_SAMPLE_STORE_CSR_IRQ); 
  
  
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __ALT_MODULAR_ADC_H__ */
