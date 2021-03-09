	component core is
		port (
			clk_clk                        : in  std_logic                    := 'X';             -- clk
			pio_0_external_export          : out std_logic_vector(9 downto 0);                    -- export
			reset_reset_n                  : in  std_logic                    := 'X';             -- reset_n
			reset_0_reset_n                : in  std_logic                    := 'X';             -- reset_n
			slide_pio_external_export      : in  std_logic_vector(9 downto 0) := (others => 'X'); -- export
			clk_0_clk                      : in  std_logic                    := 'X';             -- clk
			altpll_1_areset_conduit_export : in  std_logic                    := 'X';             -- export
			altpll_1_locked_conduit_export : out std_logic;                                       -- export
			altpll_0_c1_clk                : out std_logic                                        -- clk
		);
	end component core;

	u0 : component core
		port map (
			clk_clk                        => CONNECTED_TO_clk_clk,                        --                     clk.clk
			pio_0_external_export          => CONNECTED_TO_pio_0_external_export,          --          pio_0_external.export
			reset_reset_n                  => CONNECTED_TO_reset_reset_n,                  --                   reset.reset_n
			reset_0_reset_n                => CONNECTED_TO_reset_0_reset_n,                --                 reset_0.reset_n
			slide_pio_external_export      => CONNECTED_TO_slide_pio_external_export,      --      slide_pio_external.export
			clk_0_clk                      => CONNECTED_TO_clk_0_clk,                      --                   clk_0.clk
			altpll_1_areset_conduit_export => CONNECTED_TO_altpll_1_areset_conduit_export, -- altpll_1_areset_conduit.export
			altpll_1_locked_conduit_export => CONNECTED_TO_altpll_1_locked_conduit_export, -- altpll_1_locked_conduit.export
			altpll_0_c1_clk                => CONNECTED_TO_altpll_0_c1_clk                 --             altpll_0_c1.clk
		);

