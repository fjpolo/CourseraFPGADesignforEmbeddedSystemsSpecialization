	nios_sys u0 (
		.clk_clk                   (<connected-to-clk_clk>),                   //                clk.clk
		.pio_button_export         (<connected-to-pio_button_export>),         //         pio_button.export
		.pio_leds_export           (<connected-to-pio_leds_export>),           //           pio_leds.export
		.pll_locked_conduit_export (<connected-to-pll_locked_conduit_export>), // pll_locked_conduit.export
		.reset_reset_n             (<connected-to-reset_reset_n>),             //              reset.reset_n
		.pio_lis3dh_export         (<connected-to-pio_lis3dh_export>),         //         pio_lis3dh.export
		.spi_lis3dh_MISO           (<connected-to-spi_lis3dh_MISO>),           //         spi_lis3dh.MISO
		.spi_lis3dh_MOSI           (<connected-to-spi_lis3dh_MOSI>),           //                   .MOSI
		.spi_lis3dh_SCLK           (<connected-to-spi_lis3dh_SCLK>),           //                   .SCLK
		.spi_lis3dh_SS_n           (<connected-to-spi_lis3dh_SS_n>)            //                   .SS_n
	);

