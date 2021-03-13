module RAM128x32 
#(
  parameter Data_width = 32,  //Nr of bits in word
            Addr_width = 7  // Nr of address bits
  )
  (  //ports
    input wire clk,
    input wire we,
    input wire [(Addr_width-1):0] address, 
    input wire [(Data_width-1):0] d,
    output wire [(Data_width-1):0] q
  );

/*Signal declaration*/
reg[Data_width-1:0] ram [2**Addr_width-1:0];
/*2-dimensional array for RAM storage*/
reg [Data_width-1:0] data_reg;

	/*Positive edge of the clock*/
	always @(posedge clk)
	begin
		/*Write*/
		if(we)
			/*Store*/
			ram[address] <= d;
		/*Read*/
		data_reg <= ram[address];
	end
	/*Assign output*/
	assign q = data_reg;
endmodule