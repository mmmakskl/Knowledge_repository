//
// Verilog Module quicksort_lib.verilog_qs_tester
//
// Created:
//          by - User.UNKNOWN (VBOX)
//          at - 22:39:32 18.05.2023
//
// using Mentor Graphics HDL Designer(TM) 2005.3 (Build 75)
//
`resetall
`timescale 1ns/10ps
module verilog_qs_tester
(
  clk, in1, in2, in3, in4, in5, in6, in7, in8, in9, in10,
  out1, out2, out3, out4, out5, out6, out7, out8, out9, out10
);

output        clk;
output [10:0] in1;
output [10:0] in2;
output [10:0] in3;
output [10:0] in4;
output [10:0] in5;
output [10:0] in6;
output [10:0] in7;
output [10:0] in8;
output [10:0] in9;
output [10:0] in10;
input [10:0] out1;
input [10:0] out2;
input [10:0] out3;
input [10:0] out4;
input [10:0] out5;
input [10:0] out6;
input [10:0] out7;
input [10:0] out8;
input [10:0] out9;
input [10:0] out10;

reg        clk;
reg [10:0] in1;
reg [10:0] in2;
reg [10:0] in3;
reg [10:0] in4;
reg [10:0] in5;
reg [10:0] in6;
reg [10:0] in7;
reg [10:0] in8;
reg [10:0] in9;
reg [10:0] in10;
wire [10:0] out1;
wire [10:0] out2;
wire [10:0] out3;
wire [10:0] out4;
wire [10:0] out5;
wire [10:0] out6;
wire [10:0] out7;
wire [10:0] out8;
wire [10:0] out9;
wire [10:0] out10;

initial
begin
  clk = 0;
  in1 = 10;
  in2 = 9;
  in3 = 8;
  in4 = 7;
  in5 = 6;
  in6 = 5;
  in7 = 4;
  in8 = 3;
  in9 = 2;
  in10 = 1;
  #10;
  clk = 1;
  #5
  clk = 0;
end
// ### Please start your Verilog code here ### 

endmodule
