/**
 * define main to run
 */
//#define MAIN_NIOS_LAB
//#define HELLO_WORLD_SMALL
//#define MAIN_BLINKY
#define MAIN_COUNTER_BLINKY

#ifdef MAIN_BLINKY
/**
 *
 */
#include <stdio.h>
#include "system.h"
#include "unistd.h"
#include "altera_avalon_pio_regs.h"

int main(){
	while(1){
		// set LED
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_LEDS_BASE, 0x01);
		// wait 500ms
		usleep(1000*500);
		// clear LED
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_LEDS_BASE, 0x00);
		// wait 500ms
		usleep(1000*500);
	}
}

#endif // MAIN_BLINKY


#ifdef MAIN_COUNTER_BLINKY
/**
 *
 */
#include <stdio.h>
#include <stdint.h>
#include "system.h"
#include "unistd.h"
#include "altera_avalon_pio_regs.h"

int main(){
	uint8_t counter = 0;
	while(1){
		// set LEDs
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_LEDS_BASE, counter);
		counter++;
		// wait 100ms
		usleep(1000*100);
	}
}
#endif // MAIN_COUNTER_BLINKY


#ifdef MAIN_NIOS_LAB
/*
 * main.c

 *-- MAX1000 NIOS II implementation
 *
 * (c) 2017 Arrow Central Europe GmbH
 *
 */


#include <stdio.h>
#include "system.h"
#include "unistd.h"
#include "altera_avalon_pio_regs.h"
#include "altera_avalon_spi.h"

void init_LIS3DH();

int main()
{
	unsigned char wdata[1];
	unsigned char rdata[2];
	unsigned char led_out = 0x18;

	alt_8 y_value   	= 0;			// create buffer for filtering
	alt_8 prev_y_value 	= 0;
	alt_8 y_value_1 	= 0;
	alt_8 y_value_2 	= 0;
	alt_8 y_value_3 	= 0;
	alt_8 y_value_4 	= 0;
	alt_8 y_value_5 	= 0;

	printf("Nios Lab with MAX1000!\n");
	printf("---------------------------------------------------------------------------------\n");
	printf("DEMO:\n");
	printf("Read y-axis value of the accelerometer and have the LEDs react to received values\n");
	printf("---------------------------------------------------------------------------------\n");
	usleep(2000000);				// wait 2s

	init_LIS3DH();				// initiate LIS3DH
	wdata[0]=0xC0 | 0x2A;       // read y-register and increment

	while (1)
	{
		// read y-axis data from gyro
		alt_avalon_spi_command (SPI_LIS3DH_BASE, 0, 1, wdata, 2, rdata, 0);


		// calculate average
		y_value_5 = y_value_4;
		y_value_4 = y_value_3;
		y_value_3 = y_value_2;
		y_value_2 = y_value_1;
		y_value_1 = rdata[1];

		y_value = (y_value_1 + y_value_2 + y_value_3 + y_value_4 + y_value_5) / 5;


		// determine LED setting according to y-axis value
		if (y_value > -4 && y_value < 4)
			led_out = 0x18;
		if (y_value >= 4 && y_value < 8)
			led_out = 0x08;
		if (y_value >= 8 && y_value < 12)
			led_out = 0x04;
		if (y_value >= 12 && y_value < 16)
			led_out = 0x02;
		if (y_value >= 16)
			led_out = 0x01;
		if (y_value > -8 && y_value <= -4)
			led_out = 0x10;
		if (y_value > -12 && y_value <= -8)
			led_out = 0x20;
		if (y_value > -16 && y_value <= -12)
			led_out = 0x40;
		if (y_value <= -16)
			led_out = 0x80;

		//Send y-axis values to Nios II Console if value has changed
		if (y_value != prev_y_value)
			printf("Y-AXIS: %d\n",y_value);

		// save current value for next comparison
		prev_y_value = y_value;

		// set LED
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_LEDS_BASE, led_out);

		// wait 10ms
		usleep(10000);
	}
	return 0;
}

void init_LIS3DH()
{
	unsigned char wdata[3];
	unsigned char rdata[1];

	wdata[0]= 0x40 | 0x20;		// write multiple bytes with start address 0x20
	wdata[1]= 0x37;				// 25Hz mode, low power off, enable axis Z Y X
	wdata[2]= 0x00;				// all filters disabled

	alt_avalon_spi_command (SPI_LIS3DH_BASE, 0, 3, wdata, 0, rdata, 0);

	wdata[0]= 0x40 | 0x22;		// write multiple bytes with start address 0x22
	wdata[1]= 0x00;				// all interrupts disabled
	wdata[2]= 0x00;				// continuous update, little endian, 2g full scale, high resolution disabled, self test disabled, 4 wire SPI

	alt_avalon_spi_command (SPI_LIS3DH_BASE, 0, 3, wdata, 0, rdata, 0);
}

#endif // MAIN_NIOS_LAB







#ifdef HELLO_WORLD_SMALL
/*
 * "Small Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It requires a STDOUT  device in your system's hardware.
 *
 * The purpose of this example is to demonstrate the smallest possible Hello
 * World application, using the Nios II HAL library.  The memory footprint
 * of this hosted application is ~332 bytes by default using the standard
 * reference design.  For a more fully featured Hello World application
 * example, see the example titled "Hello World".
 *
 * The memory footprint of this example has been reduced by making the
 * following changes to the normal "Hello World" example.
 * Check in the Nios II Software Developers Manual for a more complete
 * description.
 *
 * In the SW Application project (small_hello_world):
 *
 *  - In the C/C++ Build page
 *
 *    - Set the Optimization Level to -Os
 *
 * In System Library project (small_hello_world_syslib):
 *  - In the C/C++ Build page
 *
 *    - Set the Optimization Level to -Os
 *
 *    - Define the preprocessor option ALT_NO_INSTRUCTION_EMULATION
 *      This removes software exception handling, which means that you cannot
 *      run code compiled for Nios II cpu with a hardware multiplier on a core
 *      without a the multiply unit. Check the Nios II Software Developers
 *      Manual for more details.
 *
 *  - In the System Library page:
 *    - Set Periodic system timer and Timestamp timer to none
 *      This prevents the automatic inclusion of the timer driver.
 *
 *    - Set Max file descriptors to 4
 *      This reduces the size of the file handle pool.
 *
 *    - Check Main function does not exit
 *    - Uncheck Clean exit (flush buffers)
 *      This removes the unneeded call to exit when main returns, since it
 *      won't.
 *
 *    - Check Don't use C++
 *      This builds without the C++ support code.
 *
 *    - Check Small C library
 *      This uses a reduced functionality C library, which lacks
 *      support for buffering, file IO, floating point and getch(), etc.
 *      Check the Nios II Software Developers Manual for a complete list.
 *
 *    - Check Reduced device drivers
 *      This uses reduced functionality drivers if they're available. For the
 *      standard design this means you get polled UART and JTAG UART drivers,
 *      no support for the LCD driver and you lose the ability to program
 *      CFI compliant flash devices.
 *
 *    - Check Access device drivers directly
 *      This bypasses the device file system to access device drivers directly.
 *      This eliminates the space required for the device file system services.
 *      It also provides a HAL version of libc services that access the drivers
 *      directly, further reducing space. Only a limited number of libc
 *      functions are available in this configuration.
 *
 *    - Use ALT versions of stdio routines:
 *
 *           Function                  Description
 *        ===============  =====================================
 *        alt_printf       Only supports %s, %x, and %c ( < 1 Kbyte)
 *        alt_putstr       Smaller overhead than puts with direct drivers
 *                         Note this function doesn't add a newline.
 *        alt_putchar      Smaller overhead than putchar with direct drivers
 *        alt_getchar      Smaller overhead than getchar with direct drivers
 *
 */

#include "sys/alt_stdio.h"
#include <stdint.h>

/**
 * main loop
 */
int main(){
	/**/
	uint8_t counter = 0;
	/**/
	alt_putstr("Hello from Nios II!\n");
	/* Event loop never exits. */
	while (1){
//	  printf("%d\n", counter);
	  alt_putstr("Hi\n\r");
	  counter++;
	}
	return 0;
}
#endif // HELLO_WORLD_SMALL
