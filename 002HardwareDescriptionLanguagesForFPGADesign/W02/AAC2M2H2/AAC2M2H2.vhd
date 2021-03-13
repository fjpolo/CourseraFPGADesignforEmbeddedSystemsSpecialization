library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use IEEE.std_logic_unsigned.all;


entity FIFO8x9 is
   port(
      clk, rst:		in std_logic;
      RdPtrClr, WrPtrClr:	in std_logic;    
      RdInc, WrInc:	in std_logic;
      DataIn:	 in std_logic_vector(8 downto 0);
      DataOut: out std_logic_vector(8 downto 0);
      rden, wren: in std_logic
	);
end FIFO8x9;

architecture RTL of FIFO8x9 is
	--signal declarations
	type fifo_array is array(7 downto 0) of std_logic_vector(8 downto 0);  -- makes use of VHDL’s enumerated type
	signal fifo:  fifo_array;
	signal wrptr, rdptr: unsigned(2 downto 0);
	-- signal en: std_logic_vector(7 downto 0);
	-- signal dmuxout: std_logic_vector(8 downto 0);

begin
	-- Process
	fifo_proc : process (clk)
	begin
		-- Clock
		if rising_edge(clk) then
			-- Reset
			if(rst = '1') then
				-- RdPtr reset
				if(RdPtrClr = '1') then
					rdptr <= "000";
				end if; -- RdPtr reset
				-- WrPtr reset
				if(WrPtrClr = '1') then
					wrptr <= "000";
				end if; -- WrPtr reset
			-- No reset
			else
				-- RdInc
				if(RdInc = '1') then
					rdptr <= rdptr + 1;
				end if; -- RdInc
				-- Wrinc
				if(Wrinc = '1') then
					wrptr <= wrptr + 1;
				end if; -- Wrinc
				-- Write
				if(wren = '1') then
					fifo(to_integer(wrptr)) <= DataIn;
				end if; -- wren
			end if; -- Reset
		end if; -- Clock rising edge
			-- Read
		if(rden = '1') then
			DataOut <= fifo(to_integer(rdptr));
		else
			DataOut <= "ZZZZZZZZZ";
		end if;
	end process; -- fifo_proc
end RTL;