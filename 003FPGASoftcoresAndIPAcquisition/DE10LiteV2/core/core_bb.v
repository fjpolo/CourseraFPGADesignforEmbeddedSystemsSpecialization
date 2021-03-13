
module core (
	clk_clk,
	pio_0_external_export,
	reset_reset_n,
	reset_0_reset_n,
	slide_pio_external_export,
	clk_0_clk,
	altpll_1_areset_conduit_export,
	altpll_1_locked_conduit_export,
	altpll_0_c1_clk);	

	input		clk_clk;
	output	[9:0]	pio_0_external_export;
	input		reset_reset_n;
	input		reset_0_reset_n;
	input	[9:0]	slide_pio_external_export;
	input		clk_0_clk;
	input		altpll_1_areset_conduit_export;
	output		altpll_1_locked_conduit_export;
	output		altpll_0_c1_clk;
endmodule
