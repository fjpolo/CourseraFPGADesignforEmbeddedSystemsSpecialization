-- MAX10 workshop based on Arrow BeMicro Max10
--
-- (c) 2014 Arrow Central Europe GmbH

library IEEE;
use IEEE.std_logic_1164.all;

entity RESET_GEN is
port (
	clk_in			: in	std_logic;
	reset_n_1		: in	std_logic;
	reset_n_2		: in	std_logic;
	reset_out_n		: out	std_logic
);
end entity;

architecture content of RESET_GEN is
	signal int_res_1		: std_logic;
	signal int_res_2		: std_logic;
	signal int_res_3		: std_logic;
	
	begin
	process (clk_in)
		begin
		if (rising_edge(clk_in)) then
			if (reset_n_1 = '0' or reset_n_2 = '0') then
				int_res_1 <= '0';
				int_res_2 <= '0';
				int_res_3 <= '0';
			else
				int_res_1 <= '1';
				int_res_2 <= int_res_1;
				int_res_3 <= int_res_2;
			end if;
		end if;
	end process;

	reset_out_n <= int_res_3;
end architecture;