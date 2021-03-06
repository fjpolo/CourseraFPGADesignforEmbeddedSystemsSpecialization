module ALU ( 
  input [2:0] Op_code,
  input [31:0] A, B,
  output reg [31:0] Y
);

reg [31:0]Yaux;

	/*Change*/
	always @(A,B, Op_code)
	begin
		case(Op_code)
		
		/*A*/
		3'b000:
			Y <= A;
		
		/*Add*/
		3'b001:
			Y <= A + B;
		
		/*Substract*/
		3'b010:
			Y <= A - B;
		
		/*AND*/
		3'b011:
			Y <= A & B;
		
		/*OR*/
		3'b100:
			Y <= A | B;
		
		/*Increment A*/
		3'b101:
			Y <= A + 1;
		
		/*Decrement A*/
		3'b110:
			Y <= A - 1;
		
		/*B*/
		3'b111:
			Y <= B;
		
		/**/
		default:
			Y <= 0;
		
		endcase
	end
	/*Assign output*/
	//assign Y = Yaux;
endmodule