	component nios_sys is
		port (
			clk_clk                   : in  std_logic                    := 'X';             -- clk
			pio_button_export         : in  std_logic                    := 'X';             -- export
			pio_leds_export           : out std_logic_vector(7 downto 0);                    -- export
			pll_locked_conduit_export : out std_logic;                                       -- export
			reset_reset_n             : in  std_logic                    := 'X';             -- reset_n
			pio_lis3dh_export         : in  std_logic_vector(1 downto 0) := (others => 'X'); -- export
			spi_lis3dh_MISO           : in  std_logic                    := 'X';             -- MISO
			spi_lis3dh_MOSI           : out std_logic;                                       -- MOSI
			spi_lis3dh_SCLK           : out std_logic;                                       -- SCLK
			spi_lis3dh_SS_n           : out std_logic                                        -- SS_n
		);
	end component nios_sys;

	u0 : component nios_sys
		port map (
			clk_clk                   => CONNECTED_TO_clk_clk,                   --                clk.clk
			pio_button_export         => CONNECTED_TO_pio_button_export,         --         pio_button.export
			pio_leds_export           => CONNECTED_TO_pio_leds_export,           --           pio_leds.export
			pll_locked_conduit_export => CONNECTED_TO_pll_locked_conduit_export, -- pll_locked_conduit.export
			reset_reset_n             => CONNECTED_TO_reset_reset_n,             --              reset.reset_n
			pio_lis3dh_export         => CONNECTED_TO_pio_lis3dh_export,         --         pio_lis3dh.export
			spi_lis3dh_MISO           => CONNECTED_TO_spi_lis3dh_MISO,           --         spi_lis3dh.MISO
			spi_lis3dh_MOSI           => CONNECTED_TO_spi_lis3dh_MOSI,           --                   .MOSI
			spi_lis3dh_SCLK           => CONNECTED_TO_spi_lis3dh_SCLK,           --                   .SCLK
			spi_lis3dh_SS_n           => CONNECTED_TO_spi_lis3dh_SS_n            --                   .SS_n
		);

