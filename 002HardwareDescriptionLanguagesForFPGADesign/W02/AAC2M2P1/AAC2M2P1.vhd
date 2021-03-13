LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
-- USE IEEE.std_logic_unsigned.all;


entity AAC2M2P1 is port (                 	
   CP: 	in std_logic; 				-- clock
   SR:  in std_logic;  				-- Active low, synchronous reset
   P:    in std_logic_vector(3 downto 0);  	-- Parallel input
   PE:   in std_logic; 				-- Parallel Enable (Load)
   CEP: in std_logic;  				-- Count enable parallel input
   CET:  in std_logic; 				-- Count enable trickle input
   Q:   out std_logic_vector(3 downto 0); 	-- paralell output           			
    TC:  out std_logic  			-- Terminal Count
);            		
end AAC2M2P1;

-- Behavioral architecture
architecture behavioral of AAC2M2P1 is 
begin
	TC <= Q(3) and Q(2) and Q(1) and Q(0) and CET;		-- Per Datasheet
	process
	begin
		wait until CP = '1';
		if(SR = '0') then
			Q <= "0000";						-- Clear
		elsif(PE = '0' and SR = '1') then
			Q <= P;							-- Load
		elsif(CEP = '1' and CET = '1' and SR = '1' and PE = '1' ) then
			Q <= std_logic_vector(unsigned(Q)+1);	-- Count
		end if; 
	end process; 
end behavioral;