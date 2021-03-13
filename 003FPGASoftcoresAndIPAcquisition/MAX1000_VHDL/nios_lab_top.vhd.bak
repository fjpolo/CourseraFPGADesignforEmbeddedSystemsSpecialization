-- MAX1000 NIOS II implementation
--
-- (c) 2017 Arrow Central Europe GmbH

library ieee;
use ieee.std_logic_1164.all;

entity nios_lab_top is
port (	CLK12M								: in		std_logic;
			RESET_n								: in		std_logic;
			SEN_SDO								: in		std_logic;
			SEN_SDI								: out		std_logic;
			SEN_SPC								: out		std_logic;
			SEN_CS								: out		std_logic;
			SEN_INT1								: in		std_logic;
			SEN_INT2								: in		std_logic;
			LED									: out	std_logic_vector(7 downto 0)
);
end entity;


architecture rtl of nios_lab_top is

-- Signal declaration
	signal reset 														: std_logic;
	signal CONNECTED_TO_pll_locked_conduit_export			: std_logic;
	signal CONNECTED_TO_clk_clk 				: std_logic;
	signal CONNECTED_TO_pio_leds_export 	: std_logic_vector(7 downto 0);
	signal CONNECTED_TO_pio_lis3dh_export 	: std_logic_vector(1 downto 0);
	signal CONNECTED_TO_reset_reset_n		: std_logic;
	signal CONNECTED_TO_spi_lis3dh_MISO 	: std_logic;
	signal CONNECTED_TO_spi_lis3dh_MOSI		: std_logic;
	signal CONNECTED_TO_spi_lis3dh_SCLK		: std_logic;
	signal CONNECTED_TO_spi_lis3dh_SS_n		: std_logic;

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



---------------------------------------------------------- 
------ END of nios_sys component instantiation    --------	
		
u1	: 	component RESET_GEN
		port map (
		clk_in				=> CLK12M, 
		reset_n_1			=> RESET_n,
		reset_n_2			=> CONNECTED_TO_pll_locked_conduit_export,
		reset_out_n			=>	reset
		);
  
end architecture;
		  
