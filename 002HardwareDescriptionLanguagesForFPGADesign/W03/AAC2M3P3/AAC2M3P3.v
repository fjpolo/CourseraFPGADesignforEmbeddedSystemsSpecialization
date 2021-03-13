/*//////////////////////////////////////////////////////////////////////////////
//                                                                            //
//               Application Assignment Problem 2 Module 3 Course 2           //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
//
// [Replace [items in brackets] with your content]
// @file AAC2M1P2.vhd
// @brief Application Assignment 2-007 Example code with errors to be found
// @version: 1.0 
// Date of current revision:  @date 2019-06-20  
// Target FPGA: [Intel Altera MAX10] 
// Tools used: [Quartus Prime 16.1 or Sigasi] for editing and/or synthesis 
//             [Modeltech ModelSIM 10.4a Student Edition] for simulation 
//             [Quartus Prime 16.1]  for place and route if applied
//             
//  Functional Description:  This file contains the Verilog which describes the 
//               FPGA implementation of a fixed/variable 4-bit mux. The inputs 
//               are a, a 4-bit vector, a fixed 4-bit vector, and c, a 6-bit
//               selector, with b, a 4-bit vector as the output.  

//  Hierarchy:  There is only one level in this simple design.
//  
//  Designed by:  @author [your name] 
//                [Organization]
//                [email] 
// 
//      Copyright (c) 2019 by Tim Scherr
//
// Redistribution, modification or use of this software in source or binary
// forms is permitted as long as the files maintain this copyright. Users are
// permitted to modify this and use it to learn about the field of HDl code.
// Tim Scherr and the University of Colorado are not liable for any misuse
// of this material.
//////////////////////////////////////////////////////////////////////////////
// 
*/
module find_errors(                           // line 1
  input  [0:3]a,                             // line 2,  
  output [3:0]b,                             // line 3
  input [5:0]c);                             // line 4
                                             // line 5
  wire [0:3]aw;                              // line 6
  wire [3:0]bw;                              // line 7
  reg [5:0]creg;                             // line 8 
  /**/
  assign aw = a;                             // line 10
  assign b = bw;                             // line 11
  always @* creg <= c;                       // line 12
  assign bw = (creg == 6'h3F) ? aw : 4'b0101;
/*always                                       // line 13 
  begin                                      // line 14
    if (creg = 4'h F)                        // line 15 
       bw <= aw;                             // line 16  
    else                                     // line 17
     bw <= '0101';                           // line 18   
    end;                                     // line 19
  end process;                               // line 20  
*/
endmodule                                          // line 21   

    