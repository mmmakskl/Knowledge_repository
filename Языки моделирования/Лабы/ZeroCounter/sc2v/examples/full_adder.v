module full_adder(carry_out,sum,carry_in,b,a);
output carry_out;
output sum;
input carry_in;
input b;
input a;

reg carry_out;

wire c2;
wire s1;
wire c1;

half_adder ha2_ptr (.carry(c2), .sum(sum), .b(carry_in), .a(s1));
half_adder ha1_ptr (.carry(c1), .sum(s1), .b(b), .a(a));

//prc_or:
always @(c2 or c1 )
   begin

   carry_out  =(c1 |c2 );

   end

endmodule
