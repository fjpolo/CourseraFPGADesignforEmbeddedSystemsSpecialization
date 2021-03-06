//timescale 1 ns / 1 ps
 
 // Testbenc entity declaration
 module counter_tb();
	// constant declarations
	parameter delay = 10;
	localparam n = 4;
	localparam T = 20;
	// signal decalrations
	reg clock = 0;					// clock if needed, from generator model	
	reg rest = 0;					// reset if needed
	reg [n-1:0] data_tb = 4'b0000;	// data input stimulus 
	reg load = 0;					// input stimulus
	reg en = 0;						// input stimulus
	wire [3:0] q;					// output to check
	reg [n-1:0] checkout = 4'b0000;	//Variable to compare to count or load

// Componen instances 
// instantiate the device under test
counter DUT(
	// Inputs
	.d(data_tb),
	.clk(clock),
	.reset(reset),
	.load(load),
	.en(en),
	// Outputs
	.q(q)
);

// External device simulation processes
// Clock driver
always
begin
	clock = 1'b1;
	#(T/2);
	clock = 1'b0;
	#(T/2);
end
// Reset driver
initial
begin
	reset = 1'b1;
	#(T/2);
	reset = 1'b0;
end
// Test processes
initial
begin
	@(negedge reset)
	@(negedge clock)
		// Test load
		load = 1'b1;
		en = 1'b0;
		for(i=0;i<(2**n);i=i+1)
		begin
			checkout = i;
			data_tb = i;
			@(negedge clock)
			if(q != checkout)
				$display("Load failure %b", q);
		end
		// Test count
		checkcount = 4'b0;
		loadr = 1'b0;
		en = 1'b1;
		repeat = (2*2**n)
		begin
			checkcount = checkcount + 1;
			@(negedge clock)
			if(q != checkcount)
				$display("Count failure at time %g/t at count %b", $time, q);
		end
		$stop;
	end
endmodule