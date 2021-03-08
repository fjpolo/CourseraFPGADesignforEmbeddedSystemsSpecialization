
module nios_sys (
	clk_clk,
	pio_leds_export,
	pio_lis3dh_export,
	pll_locked_conduit_export,
	reset_reset_n,
	spi_lis3dh_MISO,
	spi_lis3dh_MOSI,
	spi_lis3dh_SCLK,
	spi_lis3dh_SS_n,
	pio_button_export);	

	input		clk_clk;
	output	[7:0]	pio_leds_export;
	input	[1:0]	pio_lis3dh_export;
	output		pll_locked_conduit_export;
	input		reset_reset_n;
	input		spi_lis3dh_MISO;
	output		spi_lis3dh_MOSI;
	output		spi_lis3dh_SCLK;
	output		spi_lis3dh_SS_n;
	input		pio_button_export;
endmodule
