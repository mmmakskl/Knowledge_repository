module fsm(w,b,a,input2,input1,rst,clk);
output [1:0] w;
output [1:0] b;
output [1:0] a;
input input2;
input input1;
input rst;
input clk;

reg [1:0] w;
reg [1:0] b;
reg [1:0] a;

reg [31:0] array[11:0];
reg [1:0] next_state;
reg [1:0] state;


//dummy_proc:
reg[31:0] data2st2dummy_proc;
reg[25:0] data1st2dummy_proc;
always @(input1 )
   begin

   data1st2dummy_proc=6;
   data2st2dummy_proc=8;
   w  =((2));


   end
//fsm_proc:
reg[31:0] datastfsm_proc;
reg[15:0] addrstfsm_proc;
reg[25:0] data1st1fsm_proc;
reg [1:0] cfsm_proc[3:0];
reg [3:0] ffsm_proc;
always @(input2 or input1 or state )
   begin

   next_state  =(state );
   array [0] =(1);

   cfsm_proc[1]=0;


   case(state )

      'h1a :
      begin
      if (input1 )

         begin

         next_state  =(('h1b1 ));
         a  =(1);
         data1st1fsm_proc=8;

         end

      else if (input2 <input1 )

         begin

         next_state  =(2);
         a  =(0);

         end

      else 

         begin

         next_state  =(1);
         a  =(1);

         end

      end

      'hfaf67 :
      begin
       //hola

      case(input1 )
         'h1, 'h2:
         begin
         case(input1 )
            'h1 :
            begin
            b  =(0);
            end

            'h3 :
            begin
            b  =(1);
            end


         endcase

         b  =(0);
         end

         'h3 :
         begin
         b  =(1);
         end


      endcase



      if (input2 )

         begin

         next_state  =(2);
         b  =(1);

         end

      end

      35 :
      begin
      next_state  =(0);
      end


   endcase


   end
//regs:
always @(negedge rst or posedge clk )
   begin

   if (rst )

      begin

      state  <=(0);

      end

   else 
   state  <=(next_state );

   end

endmodule
