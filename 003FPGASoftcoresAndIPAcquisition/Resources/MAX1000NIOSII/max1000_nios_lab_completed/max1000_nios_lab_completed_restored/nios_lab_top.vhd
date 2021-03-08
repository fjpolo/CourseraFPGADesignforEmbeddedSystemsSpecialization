-- MAX1000 NIOS II implementation
--
-- (c) 2017 Arrow Central Europe GmbH

library ieee;
use ieee.std_logic_1164.all;

entity nios_lab_top is
port (	CLK12M								: in		std_logic;	-- 12MHz Clock
			RESET_n								: in		std_logic;	-- Reset Button
			SEN_SDO								: in		std_logic;	-- Accelerometer SPI SDO
			SEN_SDI								: out		std_logic;	-- Accelerometer SPI SDI
			SEN_SPC								: out		std_logic;	-- Accelerometer SPI CLOCK
			SEN_CS								: out		std_logic;	-- Accelerometer SPI Chip Select
			SEN_INT1								: in		std_logic;	-- Accelerometer SPI Interrupt 1
			SEN_INT2								: in		std_logic;	-- Accelerometer SPI interrupt 2
			LED									: out	std_logic_vector(7 downto 0)	-- LEDs
);
end entity;


architecture rtl of nios_lab_top is

-- Signal declaration
	signal reset 												: std_logic;
	signal CONNECTED_TO_pll_locked_conduit_export	: std_logic;
	signal CONNECTED_TO_clk_clk 							: std_logic;
	signal CONNECTED_TO_pio_leds_export 				: std_logic_vector(7 downto 0);
	signal CONNECTED_TO_pio_lis3dh_export 				: std_logic_vector(1 downto 0);
	signal CONNECTED_TO_reset_reset_n					: std_logic;
	signal CONNECTED_TO_spi_lis3dh_MISO 				: std_logic;
	signal CONNECTED_TO_spi_lis3dh_MOSI					: std_logic;
	signal CONNECTED_TO_spi_lis3dh_SCLK					: std_logic;
	signal CONNECTED_TO_spi_lis3dh_SS_n					: std_logic;

-- Component Declaration
	component RESET_GEN
		port (
				clk_in			: in	std_logic;
				reset_n_1		: in	std_logic;
				reset_n_2		: in	std_logic;
				reset_out_n		: out	std_logic
		);
	end component;
		
------ INSERT nios_sys component declaration here ------
--------------------------------------------------------

    component nios_sys is
        port (
            clk_clk                   : in  std_logic                    := 'X';             -- clk
            pio_leds_export           : out std_logic_vector(7 downto 0);                    -- export
            pio_lis3dh_export         : in  std_logic_vector(1 downto 0) := (others => 'X'); -- export
            pll_locked_conduit_export : out std_logic;                                       -- export
            reset_reset_n             : in  std_logic                    := 'X';             -- reset_n
            spi_lis3dh_MISO           : in  std_logic                    := 'X';             -- MISO
            spi_lis3dh_MOSI           : out std_logic;                                       -- MOSI
            spi_lis3dh_SCLK           : out std_logic;                                       -- SCLK
            spi_lis3dh_SS_n           : out std_logic                                        -- SS_n
        );
    end component nios_sys;
	
--------------------------------------------------------	  
------ END of nios_sys component declaration      ------	

begin

------ nios_sys connections -----------------------------------------
CONNECTED_TO_clk_clk 				<= CLK12M;
LED 									 	<= CONNECTED_TO_pio_leds_export;
CONNECTED_TO_pio_lis3dh_export 	<= (SEN_INT1 & SEN_INT2);	 
CONNECTED_TO_reset_reset_n 		<= reset;
CONNECTED_TO_spi_lis3dh_MISO 		<= SEN_SDO;
SEN_SDI 									<= CONNECTED_TO_spi_lis3dh_MOSI;
SEN_SPC 									<= CONNECTED_TO_spi_lis3dh_SCLK;
SEN_CS 									<= CONNECTED_TO_spi_lis3dh_SS_n;
---------------------------------------------------------------------

-- Component Instantiation 
------ INSERT nios_sys component instantiation here ------
----------------------------------------------------------

	u0 : component nios_sys
	  port map (
			clk_clk                   => CONNECTED_TO_clk_clk,                   -- clk.clk
			pio_leds_export           => CONNECTED_TO_pio_leds_export,           -- pio_leds.export
			pio_lis3dh_export         => CONNECTED_TO_pio_lis3dh_export,         -- pio_lis3dh.export
			pll_locked_conduit_export => CONNECTED_TO_pll_locked_conduit_export, -- pll_locked_conduit.export
			reset_reset_n             => CONNECTED_TO_reset_reset_n,             -- reset.reset_n
			spi_lis3dh_MISO           => CONNECTED_TO_spi_lis3dh_MISO,           -- spi_lis3dh.MISO
			spi_lis3dh_MOSI           => CONNECTED_TO_spi_lis3dh_MOSI,           -- .MOSI
			spi_lis3dh_SCLK           => CONNECTED_TO_spi_lis3dh_SCLK,           -- .SCLK
			spi_lis3dh_SS_n           => CONNECTED_TO_spi_lis3dh_SS_n            -- .SS_n
	  );

---------------------------------------------------------- 
------ END of nios_sys component instantiation    --------	
		
		
	-- Reset Component Instantiation		
	u1	: 	component RESET_GEN
			port map (
			clk_in				=> CLK12M, 
			reset_n_1			=> RESET_n,
			reset_n_2			=> CONNECTED_TO_pll_locked_conduit_export,
			reset_out_n			=>	reset
			);
  
end architecture;
		  
