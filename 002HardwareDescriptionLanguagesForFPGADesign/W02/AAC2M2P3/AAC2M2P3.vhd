library ieee;
use ieee.std_logic_1164.all;

entity FSM is
GENERIC
	(
	stateA : std_logic_vector(1 downto 0) := "00";
	stateB : std_logic_vector(1 downto 0) := "01";
	stateC : std_logic_vector(1 downto 0) := "10"
	);
port (In1: in std_logic;
   RST: in std_logic; 
   CLK: in std_logic;
   Out1 : inout std_logic);
end FSM;

-- Architecture

architecture behavioral of FSM is
signal CurrentState, NextState : std_logic_vector(1 downto 0);
begin
	comb_proc : process(In1, CurrentState)
	begin
		case(CurrentState) is
			when stateA =>
				if(In1 = '0') then NextState <= stateA;
				else NextState <= stateB;
				end if;
				Out1 <= '0';
			when stateB =>
				if(In1 = '1') then NextState <= stateB;
				else NextState <= stateC;
				end if;
				Out1 <= '0';	
			when stateC =>
				if(In1 = '0') then NextState <= stateC;
				else NextState <= stateA;
				end if;
				Out1 <= '1';
			when others =>
				NextState <= stateA;
				Out1 <= '0';	
		end case;
	end process;
	clk_proc : process(RST, CLK)
	begin
		if(RST = '1') then CurrentState <= stateA;
		elsif( rising_Edge(CLK) ) then CurrentState <= NextState;	
		end if;
	end process;
end behavioral;