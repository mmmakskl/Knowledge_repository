module delay_line(num_out,num_in,reset,clk);
output [7:0] num_out;
input [7:0] num_in;
input reset;
input clk;

reg [7:0] num_out;

reg [7:0] pipe_3;
reg [7:0] pipe_2;
reg [7:0] pipe_1;
reg [7:0] pipe_0;


//registers:
reg [7:0] var1registers,var2registers;
always @(posedge clk )
   begin

   if (reset ==1)

      begin

      pipe_0  <=(0);
      pipe_1  <=(0);
      pipe_2  <=(0);
      pipe_3  <=(0);

      var1registers=0;
      var2registers=0;

      num_out  <=(0);

      end

   else 

      begin

      pipe_0  <=(num_in );
      pipe_1  <=(pipe_0 );
      pipe_2  <=(pipe_1 );
      pipe_3  <=(pipe_2 );

      var1registers=pipe_0 ;
      var2registers=var1registers;

      num_out  <=(pipe_3 );

      end


   end

endmodule
