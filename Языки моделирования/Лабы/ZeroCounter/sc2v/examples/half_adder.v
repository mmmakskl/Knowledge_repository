module half_adder(carry,sum,b,a);
output carry;
output sum;
input b;
input a;

reg carry;
reg sum;



//prc_half_adder:
always @(b or a )
   begin

   //Line3
    //sum =a ^b ; //Line4 a
   sum  =(a ^b ); //Line4
    //carry =a &b ; //Line5 a
   carry  =(a &b ); //Line5

   end

endmodule
