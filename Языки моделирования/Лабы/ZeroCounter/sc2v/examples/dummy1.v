module dummy1(w,b,a,input2,input1,rst,clk);
output [1:0] w;
output [1:0] b;
output [1:0] a;
input [1:0] input2;
input [1:0] input1;
input rst;
input clk;

reg [1:0] b;
reg [1:0] a;

parameter  AAA =0;

reg est;

parameter  EE =0,
           S3 =1,
           S2 =2,
           S1 =3,
           S0 =4;

reg [2:0] estado;

parameter  B =0,
           A =1;

wire [1:0] b_a;
wire [3:0] temp;
reg next_state;
reg state;

moduleA modb (.m1_out(b_a), .m1_in(input2));
moduleA moda (.m1_out(w), .m1_in(b_a));

`define HOLA 1
`define CONCAT 1
function [1:0] func1;

input [1:0] a;
input [1:0] b;

reg [1:0] cfunc1;

   begin

   cfunc1=a +b ;
   func1 =cfunc1+5;

   end
endfunction

//fsm_proc:
reg [1:0] cfsm_proc;
reg [3:0] ffsm_proc;
integer ifsm_proc;
always @(input2 or input1 or state )
   begin

   cfsm_proc ={a [1:0],b [1:0]};




   next_state  =(state );
   a  =(func1 (a ,b ));
   b  =(`HOLA);

`ifdef   CONCAT
   cfsm_proc =({a [1:0],b [1:0]});
`else
   cfsm_proc =({a ,a });
`endif


   case(state )

      'h1 :
      begin
       //Case0
      if (input1 )

         begin

         next_state  =(S1 );
         a  =(1);

         end

      else if (input2 <input1 )

         begin

         next_state  =(S2 );
         a  =(0);

         end

      else 

         begin

         next_state  =(S0 );
         a  =(1);

         end

      end


      S2 :
      begin
      for (ifsm_proc =0;ifsm_proc<1+10;ifsm_proc=ifsm_proc+1)
         begin

         cfsm_proc =(ifsm_proc);

         end

      next_state  =(S0 );
      end


   endcase


   end
//regs:
always @(negedge rst or posedge clk )
   begin

   if (rst )

      begin

      state  <=(S0 );

      end

   else 
   state  <=(next_state );

   end

endmodule
