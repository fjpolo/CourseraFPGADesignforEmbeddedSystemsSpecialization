
module nios_sys (
	clk_clk,
	pio_button_export,
	pio_leds_export,
	pll_locked_conduit_export,
	reset_reset_n);	

	input		clk_clk;
	input		pio_button_export;
	output	[7:0]	pio_leds_export;
	output		pll_locked_conduit_export;
	input		reset_reset_n;
endmodule
