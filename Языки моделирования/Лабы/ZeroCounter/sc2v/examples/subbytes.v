module subbytes(sbox_decrypt_o,sbox_data_i,sbox_data_o,data_o,ready_o,data_i,decrypt_i,start_i,reset,clk);
output sbox_decrypt_o;
input [7:0] sbox_data_i;
output [7:0] sbox_data_o;
output [127:0] data_o;
output ready_o;
input [127:0] data_i;
input decrypt_i;
input start_i;
input reset;
input clk;

reg sbox_decrypt_o;
reg [7:0] sbox_data_o;
reg [127:0] data_o;
reg ready_o;

reg next_ready_o;
reg [127:0] next_data_reg;
reg [127:0] data_reg;
reg [4:0] next_state;
reg [4:0] state;


//sub:
reg [127:0] data_i_varsub,data_reg_128sub;
reg [7:0] data_arraysub[15:0],data_reg_varsub[15:0];
always @(data_reg or sbox_data_i or data_i or state or start_i or decrypt_i )
   begin

   `define assign_array_to_128       data_reg_128sub[127:120]=data_reg_varsub[0];data_reg_128sub[119:112]=data_reg_varsub[1];data_reg_128sub[111:104]=data_reg_varsub[2];data_reg_128sub[103:96]=data_reg_varsub[3];data_reg_128sub[95:88]=data_reg_varsub[4];data_reg_128sub[87:80]=data_reg_varsub[5];data_reg_128sub[79:72]=data_reg_varsub[6];data_reg_128sub[71:64]=data_reg_varsub[7];data_reg_128sub[63:56]=data_reg_varsub[8];data_reg_128sub[55:48]=data_reg_varsub[9];data_reg_128sub[47:40]=data_reg_varsub[10];data_reg_128sub[39:32]=data_reg_varsub[11];data_reg_128sub[31:24]=data_reg_varsub[12];data_reg_128sub[23:16]=data_reg_varsub[13];data_reg_128sub[15:8]=data_reg_varsub[14];data_reg_128sub[7:0]=data_reg_varsub[15];
//Dummy Comment


`define shift_array_to_128       data_reg_128sub[127:120]=data_reg_varsub[0];data_reg_128sub[119:112]=data_reg_varsub[5];data_reg_128sub[111:104]=data_reg_varsub[10];data_reg_128sub[103:96]=data_reg_varsub[15];data_reg_128sub[95:88]=data_reg_varsub[4];data_reg_128sub[87:80]=data_reg_varsub[9];data_reg_128sub[79:72]=data_reg_varsub[14];data_reg_128sub[71:64]=data_reg_varsub[3];data_reg_128sub[63:56]=data_reg_varsub[8];data_reg_128sub[55:48]=data_reg_varsub[13];data_reg_128sub[47:40]=data_reg_varsub[2];data_reg_128sub[39:32]=data_reg_varsub[7];data_reg_128sub[31:24]=data_reg_varsub[12];data_reg_128sub[23:16]=data_reg_varsub[1];data_reg_128sub[15:8]=data_reg_varsub[6];data_reg_128sub[7:0]=data_reg_varsub[11];
//Dummy Comment


`define invert_shift_array_to_128       data_reg_128sub[127:120]=data_reg_varsub[0];data_reg_128sub[119:112]=data_reg_varsub[13];data_reg_128sub[111:104]=data_reg_varsub[10];data_reg_128sub[103:96]=data_reg_varsub[7];data_reg_128sub[95:88]=data_reg_varsub[4];data_reg_128sub[87:80]=data_reg_varsub[1];data_reg_128sub[79:72]=data_reg_varsub[14];data_reg_128sub[71:64]=data_reg_varsub[11];data_reg_128sub[63:56]=data_reg_varsub[8];data_reg_128sub[55:48]=data_reg_varsub[5];data_reg_128sub[47:40]=data_reg_varsub[2];data_reg_128sub[39:32]=data_reg_varsub[15];data_reg_128sub[31:24]=data_reg_varsub[12];data_reg_128sub[23:16]=data_reg_varsub[9];data_reg_128sub[15:8]=data_reg_varsub[6];data_reg_128sub[7:0]=data_reg_varsub[3];
//Dummy Comment


   data_i_varsub=data_i ;

   data_arraysub[0]=data_i_varsub[127:120];
   data_arraysub[1]=data_i_varsub[119:112];
   data_arraysub[2]=data_i_varsub[111:104];
   data_arraysub[3]=data_i_varsub[103:96];
   data_arraysub[4]=data_i_varsub[95:88];
   data_arraysub[5]=data_i_varsub[87:80];
   data_arraysub[6]=data_i_varsub[79:72];
   data_arraysub[7]=data_i_varsub[71:64];
   data_arraysub[8]=data_i_varsub[63:56];
   data_arraysub[9]=data_i_varsub[55:48];
   data_arraysub[10]=data_i_varsub[47:40];
   data_arraysub[11]=data_i_varsub[39:32];
   data_arraysub[12]=data_i_varsub[31:24];
   data_arraysub[13]=data_i_varsub[23:16];
   data_arraysub[14]=data_i_varsub[15:8];
   data_arraysub[15]=data_i_varsub[7:0];

   data_reg_varsub[0]=data_reg [127:120];
   data_reg_varsub[1]=data_reg [119:112];
   data_reg_varsub[2]=data_reg [111:104];
   data_reg_varsub[3]=data_reg [103:96];
   data_reg_varsub[4]=data_reg [95:88];
   data_reg_varsub[5]=data_reg [87:80];
   data_reg_varsub[6]=data_reg [79:72];
   data_reg_varsub[7]=data_reg [71:64];
   data_reg_varsub[8]=data_reg [63:56];
   data_reg_varsub[9]=data_reg [55:48];
   data_reg_varsub[10]=data_reg [47:40];
   data_reg_varsub[11]=data_reg [39:32];
   data_reg_varsub[12]=data_reg [31:24];
   data_reg_varsub[13]=data_reg [23:16];
   data_reg_varsub[14]=data_reg [15:8];
   data_reg_varsub[15]=data_reg [7:0];


   sbox_decrypt_o  =(decrypt_i );
   sbox_data_o  =(0);
   next_state  =(state );
   next_data_reg  =(data_reg );

   next_ready_o  =(0);
   data_o  =(data_reg );


   case(state )


      0 :
      begin
      if (start_i )

         begin

         sbox_data_o  =(data_arraysub[0]);
         next_state  =(1);

         end

      end

      16 :
      begin
      data_reg_varsub[15]=sbox_data_i ;
       //Make shift rows stage

      case(decrypt_i )

         0 :
         begin
         `shift_array_to_128
         end

         1 :
         begin
         `invert_shift_array_to_128
         end


      endcase

      next_data_reg  =(data_reg_128sub);
      next_ready_o  =(1);
      next_state  =(0);
      end

      default:
      begin

      sbox_data_o  =(data_arraysub[state ]);
      data_reg_varsub[state -1]=sbox_data_i ;
      `assign_array_to_128
      next_data_reg  =(data_reg_128sub);
      next_state  =(state +1);
      end


   endcase


   end
//registers:
always @(negedge reset or posedge clk )
   begin

   if (!reset )

      begin

      data_reg  <=(0);
      state  <=(0);
      ready_o  <=(0);

      end

   else 

      begin

      data_reg  <=(next_data_reg );
      state  <=(next_state );
      ready_o  <=(next_ready_o );

      end


   end

endmodule
