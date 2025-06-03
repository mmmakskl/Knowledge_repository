ZeroCounterRTL(zero_count,in,reset,clk);
output [31:0] zero_count;
input in;
input reset;
input clk;

reg [31:0] zero_count;

reg next_running;
reg running;
reg [31:0] next_count_reg;
reg [31:0] count_reg;


//seq_logic:
always @(posedge clk )
   begin

   if (reset )
      begin

      count_reg  <=(0);
      running  <=(1);

      end
   else 
      begin

      count_reg  <=(next_count_reg );
      running  <=(next_running );

      end

   zero_count  <=(count_reg );

   end
//comb_logic:
reg [31:0] cntcomb_logicreg runcomb_logicreg [31:0] cnt_nextcomb_logic;
reg run_nextcomb_logic;
always @(reset or in or running or count_reg )
   begin

   =count_reg ;
=running ;



   if (reset )
      begin

      cnt_nextcomb_logic=0;
      run_nextcomb_logic=1;

      end
   else if (runcomb_logic)
      begin

      if (in )
         begin

         cnt_nextcomb_logic=cntcomb_logic;
         run_nextcomb_logic=0;

         end
      else 
         begin

         cnt_nextcomb_logic=cntcomb_logic+1;
         run_nextcomb_logic=1;

         end


      end
   else 
      begin

      cnt_nextcomb_logic=cntcomb_logic;
      run_nextcomb_logic=runcomb_logic;

      end


   next_count_reg  =(cnt_nextcomb_logic);
   next_running  =(run_nextcomb_logic);

   end

endmodule
