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


