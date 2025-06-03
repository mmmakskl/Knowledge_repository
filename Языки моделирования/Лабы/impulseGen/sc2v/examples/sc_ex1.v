module icu(control_out,alu_start,instr_in,alu_ready,reset,clk);
output [7:0] control_out;
output alu_start;
input [3:0] instr_in;
input alu_ready;
input reset;
input clk;

reg [7:0] control_out;
reg alu_start;



`define ROT 0
`define POPX 1
//decoder_io:
reg [7:0] tmpdecoder_io;
always @(posedge clk )
   begin

   tmpdecoder_io=`POPX;
   if (reset ==1)

      begin

      control_out  <=(0);

      end

   else 

      begin

      if (alu_ready ==1)

         begin


         case(instr_in )

             //this sort of works !case (ROT ) :
            `ROT :
            begin
             //this does not work
            control_out  <=('h1); //neither does this
            end

            1 :
            begin
            control_out  <=('h2);
            end

            default:
            begin


         end
         endcase


         end

      else  //needed ?

         begin


         end


      end


   end

endmodule
