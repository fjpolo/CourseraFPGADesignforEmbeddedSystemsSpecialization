LIBRARY ieee;
USE ieee.std_logic_1164.all;

-- This is an example of a serial adder.
ENTITY serial IS 
	PORT(
		A			:IN	STD_LOGIC_VECTOR(7 DOWNTO 0);
		B			:IN	STD_LOGIC_VECTOR(7 DOWNTO 0);
		start		:IN	STD_LOGIC;
		resetn	:IN	STD_LOGIC;
		clock		:IN	STD_LOGIC;
		sum		:OUT	STD_LOGIC_VECTOR(8 DOWNTO 0)
	);
END serial;

ARCHITECTURE Behaviour OF serial IS

	-- Registers
	SIGNAL	A_reg		:STD_LOGIC_VECTOR(7 DOWNTO 0);
	SIGNAL	B_reg		:STD_LOGIC_VECTOR(7 DOWNTO 0);
	SIGNAL	sum_reg	:STD_LOGIC_VECTOR(8 DOWNTO 0);
	SIGNAL	cin		:STD_LOGIC;

	-- Wires
	SIGNAL	reset		:STD_LOGIC;
	SIGNAL	enable	:STD_LOGIC;
	SIGNAL	load		:STD_LOGIC;
	SIGNAL	bit_sum	:STD_LOGIC;
	SIGNAL	bit_carry:STD_LOGIC;

	-- Component declarations
	COMPONENT FSM IS
	GENERIC(
		WAIT_STATE	:STD_LOGIC_VECTOR(1 DOWNTO 0)	:= B"00";
		WORK_STATE	:STD_LOGIC_VECTOR(1 DOWNTO 0)	:= B"01";
		END_STATE	:STD_LOGIC_VECTOR(1 DOWNTO 0)	:= B"11"
	);
	PORT(
		start		:IN	STD_LOGIC;
		clock		:IN	STD_LOGIC;
		resetn	:IN	STD_LOGIC;
		reset		:OUT	STD_LOGIC;
		enable	:OUT	STD_LOGIC;
		load		:OUT	STD_LOGIC
	);
	END COMPONENT;
	
	COMPONENT shift_reg IS
	GENERIC(
		n 			:INTEGER		:= 8
	);
	PORT(
		clock		:IN	STD_LOGIC;
		reset		:IN	STD_LOGIC;
		data		:IN	STD_LOGIC_VECTOR(n-1 DOWNTO 0);
		bit_in	:IN	STD_LOGIC;
		enable	:IN	STD_LOGIC;
		load		:IN	STD_LOGIC;
		q			:OUT	STD_LOGIC_VECTOR(n-1 DOWNTO 0)
	);
	END COMPONENT;
	

BEGIN
	PROCESS (clock)
	BEGIN
		IF clock'EVENT AND clock = '1' THEN
			IF (enable = '1') THEN
				IF (reset = '1') THEN
					cin <= '0';
				ELSE
					cin <= bit_carry;
				END IF;
			END IF;
		END IF;
	END PROCESS;
	
	-- Component instantiations
	-- Control FSM
	my_control : FSM 
	PORT MAP(start, clock, resetn, reset, enable, load);
	
	-- Datapath
	reg_A :shift_reg 
	PORT MAP(clock, '0', A, '0', enable, load, A_reg);
	
	reg_B :shift_reg
	PORT MAP(clock, '0', B, '0', enable, load, B_reg);

	-- a full adder
	bit_carry 	<= (A_reg(0) AND B_reg(0)) OR (A_reg(0) AND cin) OR (B_reg(0) AND cin);
	bit_sum 		<= A_reg(0) XOR B_reg(0) XOR cin;
	
	reg_sum :shift_reg
	GENERIC MAP(9)
	PORT MAP(clock, reset, B"000000000", bit_sum, enable, '0', sum);
		
END Behaviour;


LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY shift_reg IS
	GENERIC(
		n 			:INTEGER		:= 8
	);
	PORT(
		clock		:IN		STD_LOGIC;
		reset		:IN		STD_LOGIC;
		data		:IN		STD_LOGIC_VECTOR(n-1 DOWNTO 0);
		bit_in	:IN		STD_LOGIC;
		enable	:IN		STD_LOGIC;
		load		:IN		STD_LOGIC;
		q			:BUFFER	STD_LOGIC_VECTOR(n-1 DOWNTO 0)
	);
END shift_reg;

ARCHITECTURE Behaviour OF shift_reg IS
BEGIN
	PROCESS (clock)
	BEGIN
		IF clock'EVENT AND clock = '1' THEN
			IF (enable = '1') THEN
				IF (reset = '1') THEN
					q <= (OTHERS => '0');
				ELSE
					IF (load = '1') THEN
						q <= data;
					ELSE
						q(n-2 DOWNTO 0) <= q(n-1 DOWNTO 1);
						q(n-1) <= bit_in;
					END IF;
				END IF;
			END IF;
		END IF;
	END PROCESS;
END Behaviour;


LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_unsigned.all;
USE ieee.numeric_std.all;

ENTITY FSM IS
	GENERIC(
		WAIT_STATE	:STD_LOGIC_VECTOR(1 DOWNTO 0)	:= B"00";
		WORK_STATE	:STD_LOGIC_VECTOR(1 DOWNTO 0)	:= B"01";
		END_STATE	:STD_LOGIC_VECTOR(1 DOWNTO 0)	:= B"11"
	);
	PORT(
		start		:IN		STD_LOGIC;
		clock		:IN		STD_LOGIC;
		resetn	:IN		STD_LOGIC;
		reset		:BUFFER	STD_LOGIC;
		enable	:BUFFER	STD_LOGIC;
		load		:BUFFER	STD_LOGIC
	);
END FSM;

ARCHITECTURE Behaviour OF FSM IS
	SIGNAL	current_state	:STD_LOGIC_VECTOR(1 DOWNTO 0);
	SIGNAL	next_state		:STD_LOGIC_VECTOR(1 DOWNTO 0);
	SIGNAL	counter			:STD_LOGIC_VECTOR(3 DOWNTO 0);

BEGIN
	-- next state logic 
	PROCESS(current_state, start, next_state, counter)
	BEGIN
		CASE(current_state) IS
			WHEN WAIT_STATE =>
				IF (start = '1') THEN
					next_state <= WORK_STATE;
				ELSE
					next_state <= WAIT_STATE;
				END IF;
			WHEN WORK_STATE =>
				IF (counter = B"1000") THEN
					next_state <= END_STATE;
				ELSE
					next_state <= WORK_STATE;
				END IF;
			WHEN END_STATE =>
				IF (start = '0') THEN
					next_state <= WAIT_STATE; 
				ELSE
					next_state <= END_STATE;
				END IF;
			WHEN OTHERS =>
				next_state <= '-' & '-'; -- don't care
		END CASE;
	END PROCESS;

	-- state registers and a counter
	PROCESS(clock, resetn)
	BEGIN 
		IF (resetn = '0') THEN
			current_state 	<= WAIT_STATE;
			counter 			<= (OTHERS => '0');
		ELSIF (clock'EVENT AND clock = '1') THEN
			current_state <= next_state;
			IF (current_state = WAIT_STATE) THEN
				counter <= (OTHERS => '0');
			ELSIF (current_state = WORK_STATE) THEN
				counter <= counter + '1';
			END IF;
		END IF;
	END PROCESS;
	
	-- Outputs
	reset		<= '1' WHEN (current_state = WAIT_STATE) AND (start = '1') ELSE '0';
	load		<= '1' WHEN (current_state = WAIT_STATE) AND (start = '1') ELSE '0';
	enable	<= '1' WHEN (load = '1') OR (current_state = WORK_STATE) ELSE '0';
END Behaviour;

	