--------------------------------------------------------------------------------
--                                                                            --
--               Application Assignment 3 Module 1 Course 2                   --
--                                                                            --
--------------------------------------------------------------------------------
--
-- [Replace [items in brackets] with your content]
-- @file AAC2M1P3.vhd
-- @brief Application Assignment 2-001 Example code with errors to be found
-- @version: 1.0 
-- Date of current revision:  @date YYYY-MM-DD  
-- Target FPGA: [Intel Altera MAX10] 
-- Tools used: [Quartus Prime 16.1] for editing and synthesis 
--             [Modeltech ModelSIM 10.4a Student Edition] for simulation 
--             [Quartus Prime 16.1]  for place and route if applied
--             
--  Functional Description:  This file contains the VHDL which describes the 
--               FPGA implementation of a 4-bit mux. The inputs are a, 4-bit 
--               vector, and a fixed 4-bit number, with c as the select and b
--               as the output. The output is of type std_logic_vector, which
--               means a conversion function is required.  
--  Hierarchy:  There is only one level in this simple design.
--  
--  Designed for: [Customer] 
--                [Address]
--                [City, ST ZIP]
--                [www.customer, phone number]
--  Designed by:  @author [your name] 
--                [Organization]
--                [email] 
-- 
--      Copyright (c) 2018 by Tim Scherr
--
-- Redistribution, modification or use of this software in source or binary
-- forms is permitted as long as the files maintain this copyright. Users are
-- permitted to modify this and use it to learn about the field of HDl code.
-- Tim Scherr and the University of Colorado are not liable for any misuse
-- of this material.
------------------------------------------------------------------------------
-- 

library ieee;                                -- line 1
use ieee.std_logic_1164.all;                 -- line 2
                                             -- line 3
entity find_errors is port(                  -- line 4--
    a: bit_vector(0 to 3);                   -- line 5
    b: out std_logic_vector(3 downto 0);     -- line 6
    c: in bit_vector(0 to 5));           -- line 7
end find_errors;                             -- line 8
                                             -- line 9
architecture not_good of find_errors is      -- line 10
  begin                                      -- line 11
  my_label: process(a, c)                          -- line 12
    begin                                    -- line 13
    if (c = "00" & x"F") then	             -- line 14
      b <= to_stdlogicvector(a);             -- line 15
    else                                     -- line 16
     b <= "0101";                            -- line 17
    end if;                                  -- line 18
  end process;                               -- line 19
end not_good;                                -- line 20
   