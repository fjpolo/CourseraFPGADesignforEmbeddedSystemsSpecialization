
module nios_sys (
	clk_clk,
	pio_button_export,
	pio_leds_export,
	pll_locked_conduit_export,
	reset_reset_n,
	pio_lis3dh_export,
	spi_lis3dh_MISO,
	spi_lis3dh_MOSI,
	spi_lis3dh_SCLK,
	spi_lis3dh_SS_n);	

	input		clk_clk;
	input		pio_button_export;
	output	[7:0]	pio_leds_export;
	output		pll_locked_conduit_export;
	input		reset_reset_n;
	input	[1:0]	pio_lis3dh_export;
	input		spi_lis3dh_MISO;
	output		spi_lis3dh_MOSI;
	output		spi_lis3dh_SCLK;
	output		spi_lis3dh_SS_n;
endmodule
