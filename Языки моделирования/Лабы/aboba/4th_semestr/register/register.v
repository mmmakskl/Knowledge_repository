module DTrigger(Result, Data, Clock, Reset, Ewr);

      input  Data, Clock, Reset, Ewr;
      output Result;
      reg Res, Buf;

      always @(negedge Clock)
        begin
          if (!Ewr)
                begin
                  Res = Data;
                  Buf = Data;
                end
               else
                  Res = Buf;
        end

       assign Result = !Res;
endmodule

module register (OUTRESULT , EWR, CLOCK, RESET, DATA , EDY);

parameter numbits=7;

       input [numbits:0] DATA;
       input EWR, CLOCK, RESET, EDY;
       output [numbits:0] OUTRESULT ;
       reg [numbits:0] res;
       wire[numbits:0] Res ;

       integer i;

       DTrigger Dtrig1 (Res[0], DATA[0], CLOCK, RESET, EWR);
       DTrigger Dtrig2 (Res[1], DATA[1], CLOCK, RESET, EWR);
       DTrigger Dtrig3 (Res[2], DATA[2], CLOCK, RESET, EWR);
       DTrigger Dtrig4 (Res[3], DATA[3], CLOCK, RESET, EWR);
       DTrigger Dtrig5 (Res[4], DATA[4], CLOCK, RESET, EWR);
       DTrigger Dtrig6 (Res[5], DATA[5], CLOCK, RESET, EWR);
       DTrigger Dtrig7 (Res[6], DATA[6], CLOCK, RESET, EWR);
       DTrigger Dtrig8 (Res[7], DATA[7], CLOCK, RESET, EWR);
       always @ (posedge CLOCK)
         begin
           if (~EDY)
               res = ~Res;
           else res = 'bx;
         end

       assign OUTRESULT = res;
endmodule
