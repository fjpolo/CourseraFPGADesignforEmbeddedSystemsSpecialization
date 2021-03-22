//
// Copyright 1991-2016 Mentor Graphics Corporation
//
// All Rights Reserved.
//
// THIS WORK CONTAINS TRADE SECRET AND PROPRIETARY INFORMATION WHICH IS THE PROPERTY OF 
// MENTOR GRAPHICS CORPORATION OR ITS LICENSORS AND IS SUBJECT TO LICENSE TERMS.
//   

`timescale 1ns / 1ns
module test_counter;

reg clk, reset;
wire [7:0] count;

counter dut (count, clk, reset);

initial // Clock generator
  begin
    clk = 0;
    forever #10 clk = !clk;
  end
  
initial	// Test stimulus
  begin
    reset = 0;
    #5 reset = 1;
    #4 reset = 0;
  end
  
initial
    $monitor($stime,, reset,, clk,,, count); 
    
endmodule    
