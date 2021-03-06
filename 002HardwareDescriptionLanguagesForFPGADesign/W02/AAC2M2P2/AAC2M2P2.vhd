LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.numeric_std.ALL;

ENTITY RAM128_32 IS
	PORT
	(
		address	: IN STD_LOGIC_VECTOR (6 DOWNTO 0);
		clock		: IN STD_LOGIC  := '1';
		data		: IN STD_LOGIC_VECTOR (31 DOWNTO 0);
		wren		: IN STD_LOGIC ;
		q		: OUT STD_LOGIC_VECTOR (31 DOWNTO 0)
	);
END RAM128_32;

-- data type for a 128 x 32 memory: 128 bytes (depth) by 32-bit (width) RAM

architecture behavioral of RAM128_32 is
type ram_t is array (127 DOWNTO 0) of STD_LOGIC_VECTOR(31 DOWNTO 0);
signal ram : ram_t;
signal data_reg : STD_LOGIC_VECTOR(31 DOWNTO 0);
begin
	process (clock)
	begin
		if (rising_edge(clock)) then
			if (wren = '1') then
				ram(to_integer(unsigned(address))) <= data; 		-- write
				-- q <= ram(to_integer(unsigned(address))); 	-- read
				q <= data;
			else q <= "UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU";
			end if;
		end if; 
	end process;
end behavioral;