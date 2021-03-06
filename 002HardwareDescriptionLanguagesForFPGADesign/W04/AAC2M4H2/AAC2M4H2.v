/*
*  Using Verilog, Design a FIFO memory. Make it 8-deep, 
* 9 bits wide. 
*  When a read signal is asserted, the output of the 
* FIFO should be enabled, otherwise it should be high 
* impedance. 
*  When the write signal is asserted, write to one of 
* the 9 bit registers. 
*  Use RdInc and WrInc as input signals to increment the 
* pointers that indicate which register to read or write. 
*  Use RdPtrClr and WrPtrClr as input signals which reset 
* the pointers to point to the first register in the array. 
*  Do not implement full or empty signals.   
*/
module FIFO8x9(
  input clk, 						// Clock
  input rst,						// Reset
  input RdPtrClr, 					// Read Pointer Clear, to reset the read pointer
  input WrPtrClr, 					// Write Pointer Clear, to reset the write pointer
  input RdInc, 						// Read pointer increment signal
  input WrInc,						// Write pointer increment signal
  input [8:0] DataIn,				// Data input bus
  output reg [8:0] DataOut,			// Data Output bus
  input rden, 						// read (output) enable
  input wren						// write (input) enable
);

	//signal declarations
	reg [8:0] fifo_array[7:0];
	reg [7:0] wrptr, rdptr;
	wire [7:0] wr_cnt, rd_cnt;
	reg AuxOutput[8:0];

	initial begin
		wrptr <= 8'b00000000;
		rdptr <= 8'b00000000;
	end

	// Positive clock edge
	always @(posedge clk or negedge rst) begin: write_pointer
		if (!rst) begin
			wrptr <= 0;
		end else if (WrPtrClr ) begin
			wrptr <= wrptr + 1;
		end // rst
	end // write_pointer

	// Positive clock edge
	always @(posedge clk or negedge rst) begin: read_pointer
		if (!rst) begin
			rdptr <= 0;
		end else if (RdPtrClr ) begin
			rdptr <= rdptr + 1;
		end // rst
	end // read_pointer

	// Positive clock edge
	always  @ (posedge clk or posedge rst) begin : READ_DATA
  		if (rst) begin
			if(rden) begin
    				//DataOut <= fifo_array[rdptr];
 				DataOut <= wrptr;
			end else begin
				DataOut <= 9'bZZZZZZZZZ;
			end
  		end // rst
	end // READ_DATA

	// Positive clock edge
	always  @ (posedge clk or posedge rst) begin : WRITE_DATA
  		if (rst) begin
			if(wren) begin
    				fifo_array[wrptr] <= DataIn;
			end else begin
				fifo_array[wrptr] <= fifo_array[wrptr];
			end
  		end // rst
	end // WRITE_DATA

endmodule