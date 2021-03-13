`timescale 1ps/1ps
module nios_lab_top(
	// Reset and clock
	input			CLK12M,
	input			RST_BTN,
	// User button
	input			USER_BTN,
	// LEDs
	output		[7:0]LED,
	// SPI int pins
	input 		[1:0]LIS3DH_INT,
	// SPI pins
	output		LIS3DH_SCLK,
	output		LIS3DH_SS,
	output		LIS3DH_MOSI,
	input			LIS3DH_MISO
);

// REG/WIRE declarations

// Structural code here
nios_sys u0 (
		.clk_clk                   (CLK12M),         		//          clk.clk
		.pio_button_export         (USER_BTN),       		//         	pio_button.export
		.pio_leds_export           (LED),           			//          pio_leds.export
		.pll_locked_conduit_export ( ), 							// 			pll_locked_conduit.export
		.reset_reset_n             (RST_BTN),         		//          reset.reset_n
		.pio_lis3dh_export         (LIS3DH_INT),         	//        	pio_lis3dh.export
      .spi_lis3dh_MISO           (LIS3DH_MISO),          //         	spi_lis3dh.MISO
      .spi_lis3dh_MOSI           (LIS3DH_MOSI),          //          .MOSI
      .spi_lis3dh_SCLK           (LIS3DH_SCLK),          //          .SCLK
      .spi_lis3dh_SS_n           (LIS3DH_SS)            	//          .SS_n
	);

endmodule

/*

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

*/