	component core is
		port (
			altpll_0_c1_clk           : out std_logic;                                       -- clk
			clk_clk                   : in  std_logic                    := 'X';             -- clk
			pio_0_external_export     : out std_logic_vector(9 downto 0);                    -- export
			reset_reset_n             : in  std_logic                    := 'X';             -- reset_n
			slide_pio_external_export : in  std_logic_vector(9 downto 0) := (others => 'X')  -- export
		);
	end component core;

	u0 : component core
		port map (
			altpll_0_c1_clk           => CONNECTED_TO_altpll_0_c1_clk,           --        altpll_0_c1.clk
			clk_clk                   => CONNECTED_TO_clk_clk,                   --                clk.clk
			pio_0_external_export     => CONNECTED_TO_pio_0_external_export,     --     pio_0_external.export
			reset_reset_n             => CONNECTED_TO_reset_reset_n,             --              reset.reset_n
			slide_pio_external_export => CONNECTED_TO_slide_pio_external_export  -- slide_pio_external.export
		);

