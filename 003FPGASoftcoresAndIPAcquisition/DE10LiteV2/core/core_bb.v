
module core (
	altpll_0_c1_clk,
	clk_clk,
	pio_0_external_export,
	reset_reset_n,
	slide_pio_external_export);	

	output		altpll_0_c1_clk;
	input		clk_clk;
	output	[9:0]	pio_0_external_export;
	input		reset_reset_n;
	input	[9:0]	slide_pio_external_export;
endmodule
