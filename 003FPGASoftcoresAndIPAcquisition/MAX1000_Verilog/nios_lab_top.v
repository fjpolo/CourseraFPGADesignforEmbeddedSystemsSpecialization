`timescale 1ps/1ps
module nios_lab_top(
	// Reset and clock
	input			CLK12M,
	input			RST_BTN,
	// User button
	input			USER_BTN,
	// LEDs
	output		[7:0]LED
);

// REG/WIRE declarations

// Structural code here
nios_sys u0 (
		.clk_clk                   (CLK12M),         //                clk.clk
		.pio_button_export         (USER_BTN),       //         pio_button.export
		.pio_leds_export           (LED),           	//           pio_leds.export
		.pll_locked_conduit_export ( ), 					// pll_locked_conduit.export
		.reset_reset_n             (RST_BTN)         //              reset.reset_n
	);

endmodule