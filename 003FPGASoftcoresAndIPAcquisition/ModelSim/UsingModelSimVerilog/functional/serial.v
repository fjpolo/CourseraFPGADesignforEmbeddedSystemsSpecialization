// This is an example of a serial adder.
module serial(A, B, start, resetn, clock, sum);
	input [7:0] A, B;
	input resetn, start, clock;
	output [8:0] sum;

	// Registers
	wire [7:0] 	A_reg,B_reg;
	reg		cin;

	
	// Wires
	wire reset, enable, load;
	wire bit_sum, bit_carry;

	// Control FSM
	FSM my_control(start, clock, resetn, reset, enable, load);
	
	// Datapath
	shift_reg reg_A( clock, 1'b0, A, 1'b0, enable, load, A_reg);
	shift_reg reg_B( clock, 1'b0, B, 1'b0, enable, load, B_reg);

	// a full adder
	assign {bit_carry, bit_sum} = A_reg[0] + B_reg[0] + cin;

	always @(posedge clock)
		if (enable)
			if (reset)
				cin <= 1'b0;
			else
				cin <= bit_carry;
				
	shift_reg reg_sum( clock, reset, 9'd0, bit_sum, enable, 1'b0, sum);
		defparam reg_sum.n = 9;
endmodule

module shift_reg( clock, reset, data, bit_in, enable, load, q);
	parameter n = 8;

	input clock, reset, enable, load, bit_in;
	input 	[n-1:0] data;
	output reg 	[n-1:0] q;

	always @(posedge clock)
	begin
		if (enable)
			if (reset)
				q <= 'd0;
			else
			begin
				if (load)
					q<=data;
				else
				begin
					q[n-2:0] <= q[n-1:1];
					q[n-1] <= bit_in;
				end
			end
	end
endmodule


module FSM(start, clock, resetn, reset, enable, load);
	parameter WAIT_STATE = 2'b00, WORK_STATE = 2'b01, END_STATE = 2'b11;
	input start, clock, resetn;
	output reset, enable, load;

	reg [1:0]	current_state, next_state;
	reg [3:0]	counter;

	// next state logic 
	always@(*)
	begin
		case(current_state)
			WAIT_STATE:
				if (start)
					next_state <= WORK_STATE;
				else
					next_state <= WAIT_STATE;
					
			WORK_STATE:
				if (counter == 4'd8)
					next_state <= END_STATE;
				else
					next_state <= WORK_STATE;
					
			END_STATE:
				if (~start) 
					next_state <= WAIT_STATE; 
				else
					next_state <= END_STATE;
					
			default: next_state <= 2'bxx;
		endcase
	end

	// state registers and a counter
	always@(posedge clock or negedge resetn)
	begin
		if (~resetn)
		begin
			current_state <= WAIT_STATE;
			counter = 'd0;
		end
		else
		begin
			current_state <= next_state;
			if (current_state == WAIT_STATE)
				counter <= 'd0;
			else if (current_state == WORK_STATE)
				counter <= counter + 1'b1;
		end
	end
	
	// Outputs
	assign reset = (current_state == WAIT_STATE) & start;
	assign load = (current_state == WAIT_STATE) & start;
	assign enable = load | (current_state == WORK_STATE);
endmodule

	