module ImpulseGen(impulses,count,sync,reset,clk);
output impulses;
input [3:0] count;
input sync;
input reset;
input clk;

reg impulses;

wire [3:0] count_left;


//on_tick:
always @(posedge clk )
   begin
   if (reset )
      begin
      count_left =0;
      impulses =0;
      on_tick =;
      end


   if (count_left >1)

      begin

      if (impulses )

         begin

         count_left =count_left -1;
         impulses =0;

         end

      else 

         begin

         impulses =1;

         end


      end

   else 

      begin

      if (sync )

         begin

         count_left =count ;
         impulses =count !=0;

         end

      else 

         begin

         count_left =0;
         impulses =0;

         end


      end


   end

endmodule
