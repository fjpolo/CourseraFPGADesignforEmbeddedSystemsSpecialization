// http://langster1980.blogspot.com/2019/

module LS161a(
    input [3:0] D,        // Parallel Input
    input CLK,            // Clock
    input CLR_n,          // Active Low Asynchronous Reset
    input LOAD_n,         // Enable Parallel Input
    input ENP,            // Count Enable Parallel
    input ENT,            // Count Enable Trickle
    output [3:0]Q,         // Parallel Output 	
    output RCO            // Ripple Carry Output (Terminal Count)
); 

	reg [3:0]auxQ;

	/*Positive edge of the clock*/
	always @(posedge CLK)
	begin
		/*Clear*/
		if (!CLR_n)
		begin
			//if clear is low, set the count outputs to 0
			auxQ <= 4'b0;
		end // END clear
		/*Load*/
		if( (CLR_n) && (!LOAD_n) )
		begin
			//if load is set low, set count output to match the input
			auxQ <= D;
		end // END load
		/*Count*/
		if (CLR_n && LOAD_n && ENP && ENT)
		begin
			//if clear, load, ent and enp are set high, increment the count by one
			auxQ <= Q + 1;
		end
	end	// END posedge clk
	/*RCO - TC*/
	// assign RCO = ENT ? (CET && Q[0] && Q[1] && Q[2] && Q[3] ): 0;
	assign RCO = ( Q[0] && Q[1] && Q[2] && Q[3] );	// error at 350ns. Solved by dropping the dependency of RCO on ENT.
	/**/
assign Q = auxQ;
endmodule