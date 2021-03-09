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

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include "altera_modular_adc.h"
#include "priv/alt_file.h"
#include "sys/alt_irq.h"

static void alt_adc_irq(void *context);

ALT_LLIST_HEAD(altera_modular_adc_list);

/*
 * alt_adc_irq()
 *
 * Interrupt handler for the altera modular adc.
 */
static void alt_adc_irq(void *context)
{
    alt_modular_adc_dev *dev = (alt_modular_adc_dev *) context;
    alt_irq_context cpu_sr = 0;

	if(NULL != dev)
	{
	    cpu_sr = alt_irq_disable_all();
		/* 
		* Other interrupts are explicitly disabled if callbacks
		* are registered because there is no guarantee that they are 
		* pre-emption-safe. This allows the driver to support 
		* interrupt pre-emption.
		*/
		if(dev->callback) 
		{
			dev->callback (dev->callback_context);
		}
    
		/* clear the IRQ status */
		adc_clear_interrupt_status(dev->sample_store_base);
	    
		alt_irq_enable_all(cpu_sr);
	}
	
    return;
}

/**
 * alt_adc_word_read
 *
 * Reading from sample store core (RAM) in word addressing
 *
 *slot |  address_ofset    |  ADC1 sample data   |   ADC0 sample data
 *     | (word addressing) |  MS2B(31-16)        |   LS2B(15-0 bits)
 *--------------------------------------------------------------------
 * 0   |     0             |   xxxx xxxx xxxx    |   xxxx xxxx xxxx    
 * 1   |     4             |   xxxx xxxx xxxx    |   xxxx xxxx xxxx 
 * Arguments:
 * - sample_store_base: Base address of sample store core
 * - *dest_ptr: destination buffer  
 * - len: size of reading in 32 bits.
 *
 * Returns:
 * 0 -> success
 * -EINVAL -> Invalid arguments
**/
int alt_adc_word_read (alt_u32 sample_store_base, alt_u32* dest_ptr, alt_u32 len)
{
    alt_u32 word = 0;
    alt_u32 word_length = len;
    alt_u32* dest_buf = dest_ptr;
    alt_u32 base = sample_store_base;
     
    /* return -EINVAL if invalid arguments passed into function */
    if(NULL == dest_buf)
    {
    	return -EINVAL;
    }

    for(word = 0; word < word_length; word++)
    {
       *dest_buf = IORD_32DIRECT((base + (word * 4)),0);

       dest_buf++;
    }

    return 0;

}


void altera_modular_adc_init(alt_modular_adc_dev* dev, alt_32 ic_id, alt_32 irq)
{
    extern alt_llist altera_modular_adc_list;
    alt_dev_llist_insert((alt_dev_llist*) dev, &altera_modular_adc_list);
	
	if ((0 <= ic_id) && (0 <= irq))
	{
          /* Install IRQ handler */
	  #ifdef ALT_ENHANCED_INTERRUPT_API_PRESENT
              alt_ic_isr_register(ic_id, irq, alt_adc_irq, 
                      dev, NULL);
          #else
             alt_irq_register(irq, dev, alt_adc_irq);
          #endif 
	}
}

/*
 * alt_adc_register_callback
 *
 * Associate a user-specific routine with the adc interrupt handler.
 * If a callback is registered, all enable interrupts that will cause 
 * the callback to be executed. The callback runs as part of the interrupt 
 * service routine, and great care must be taken to follow the guidelines 
 * for acceptable interrupt service routine behaviour as described in the 
 * Nios II Software Developer's Handbook.
 *
 * Note: To disable callbacks and interrupt after registering one, this routine
 * may be called passing 0x0 to the callback argument.
 *
 * Arguments:
 * - *dev: Pointer to adc device (instance) structure.
 * - callback: Pointer to callback routine to execute at interrupt level
 * - *context: Pointer to adc device structure.
 * - sample_store_base: Base address of the sample store micro core.
 */
void alt_adc_register_callback(
	alt_modular_adc_dev *dev,
	alt_adc_callback callback,
	void *context,
	alt_u32 sample_store_base)
{
    dev->callback         = callback;
    dev->callback_context = context;
    dev->sample_store_base = sample_store_base;
	
	if(NULL != callback)
	{
                adc_clear_interrupt_status(sample_store_base);
		adc_interrupt_enable(sample_store_base);
	}
	else
	{
		adc_interrupt_disable(sample_store_base);
                adc_clear_interrupt_status(sample_store_base);
	}
	
    
	
    return ;
}

alt_modular_adc_dev* altera_modular_adc_open (const char *name)
{
    alt_modular_adc_dev *dev = NULL;

    /* Find requested device */
    dev = (alt_modular_adc_dev*) alt_find_dev (name, &altera_modular_adc_list);

    return dev;
}

void adc_stop(int sequencer_base)
{
    ALTERA_MODULAR_ADC_SEQUENCER_STOP(sequencer_base);
}

void adc_start(int sequencer_base)
{
    ALTERA_MODULAR_ADC_SEQUENCER_START(sequencer_base);
}

void adc_set_mode_run_once(int sequencer_base)
{
    /* Note: Stop the ADC before calling this function,
       changing ADC mode while RUN bit is set has no effect. */
    ALTERA_MODULAR_ADC_SEQUENCER_MODE_RUN_ONCE(sequencer_base);
}

void adc_set_mode_run_continuously(int sequencer_base)
{
    /* Note: Stop the ADC before calling this function,
       changing ADC mode while RUN bit is set has no effect. */
    ALTERA_MODULAR_ADC_SEQUENCER_MODE_RUN_CONTINUOUSLY(sequencer_base);
}

void adc_recalibrate(int sequencer_base)
{
    /*
     To Recalibrate ADC
     Step:
         1. Backup CMD register, because some value will be overwritten
         2. Stop the ADC Sequencer Core.
         3. Set the recalibration request bits
         2. Start the ADC Sequencer Core.
         5. Poll for RUN bit to be clear
         6. Restore CMD register
     */
    alt_u32 backup_cmd_reg;
    backup_cmd_reg = IORD_ALTERA_MODULAR_ADC_SEQUENCER_CMD_REG(sequencer_base);
    adc_stop(sequencer_base);
    ALTERA_MODULAR_ADC_SEQUENCER_MODE_RUN_RECALIBRATION(sequencer_base);
    adc_start(sequencer_base);
    while(IORD_ALTERA_MODULAR_ADC_SEQUENCER_CMD_REG(sequencer_base)
             & ALTERA_MODULAR_ADC_SEQUENCER_CMD_RUN_MSK);
    IOWR_ALTERA_MODULAR_ADC_SEQUENCER_CMD_REG(sequencer_base, backup_cmd_reg);
}

void adc_interrupt_enable(int sample_store_base)
{
    ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_ENABLE(sample_store_base);
}

void adc_interrupt_disable(int sample_store_base)
{
    ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_DISABLE(sample_store_base);
}

void adc_clear_interrupt_status(int sample_store_base)
{
    CLEAR_ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_STATUS(sample_store_base);
}

int adc_interrupt_asserted(int sample_store_base)
{
    return((READ_ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ_STATUS(sample_store_base)==1) ? -1 : 0);
}

void adc_wait_for_interrupt(int sample_store_base)
{
    WAIT_FOR_ALTERA_MODULAR_ADC_SAMPLE_STORAGE_IRQ(sample_store_base);
}
