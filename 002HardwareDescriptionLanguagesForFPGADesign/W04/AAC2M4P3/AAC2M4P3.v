module FSM
#(
	parameter State_width = 2,
	A = 2'b01,
	B = 2'b10,
	C = 2'b11
)
(
  input In1,
  input RST,
  input CLK, 
  output reg Out1
);
/*State regs*/
reg [(State_width-1):0] CurrentState, NextState;
reg OutAux;

	/*FSM*/
	always @(In1 or CurrentState)
	begin: Combinational
		case(CurrentState)
			A: 
			begin
				if(In1 == 0) 
				begin 
					NextState <= A;
				end else
				begin
					NextState <= B;
				end
				Out1 <= 0;
			end // A

			B:
			begin
				if(In1 == 1) 
				begin
					NextState = B;
				end else
				begin
					NextState = C;
				end
				Out1 <= 0;
			end // B
			C:
			begin
				if(In1 == 0) 
				begin
					NextState = C;
				end else 
				begin
					NextState = A;
				end
				Out1 <= 1;
			end // C

			default:
			begin
				NextState <= A;
				Out1 <= 0;
			end // default
		endcase
	end// Combinational

	/*Positive edge of the clock or negative edge of Reset*/
	always@(posedge CLK or negedge RST)
	begin
		if(!RST)
		begin
			CurrentState = CurrentState;
			//Out1 <= 0;
		end else
		begin
			CurrentState = NextState;
		end
	end
	
	/*Assign output*/
	//assign Out1 = OutAux;
	
endmodule