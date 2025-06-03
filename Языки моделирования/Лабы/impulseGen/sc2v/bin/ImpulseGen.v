module ImpulseGenRTL(impulses,count,sync,reset,clk);
output impulses;
input [3:0] count;
input sync;
input reset;
input clk;

reg impulses;

reg [3:0] new_count_left;
reg [3:0] count_left;
reg new_impulses;


//comb_logic:
always @(count or impulses or count_left or sync )
   begin

   if (count_left !=0)

      begin

      if (impulses !=0)

         begin

         new_count_left  =(count_left -1);
         new_impulses  =(0);

         end

      else 

         begin

         new_count_left  =(count_left );
         new_impulses  =(1);

         end


      end

   else 

      begin

      if (sync )

         begin

         new_count_left  =(count );
         new_impulses  =(count !=0);

         end

      else 

         begin

         new_count_left  =(count_left );
         new_impulses  =(0);

         end


      end


   end
//seq_logic:
always @(posedge clk )
   begin

   if (reset )

      begin

      count_left  <=(0);
      impulses  <=(0);

      end

   else 

      begin

      count_left  <=(new_count_left );
      impulses  <=(new_impulses );

      end


   end

endmodule
