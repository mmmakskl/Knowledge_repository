module DTrigger(Result, Data, Clock, Reset, Ewr);
	input Data, Clock, Reset, Ewr;
	output Result;
	reg Res, Buf;

	always @(negedge Clock or posedge Reset) begin
		if (Reset) begin
			Res <= 0;
			Buf <= 0;
		end
		else begin
			if (!Ewr) begin
				Res <= Data;
				Buf <= Data;
			end
			else begin
				Res <= Buf;
			end
		end
	end

	assign Result = !Res;
endmodule

module MainRegister(OUTRESULT, EWR, CLOCK, RESET, DATA, EDY);
	parameter numbits=8;
	input [numbits-1:0] DATA;
	input EWR, CLOCK, RESET, EDY;
	output [numbits-1:0] OUTRESULT;
	reg [numbits-1:0] res;
	wire [numbits-1:0] Res;

	integer i;

	DTrigger Dtrig0 (Res[0], DATA[0], CLOCK, RESET, EWR);
	DTrigger Dtrig1 (Res[1], DATA[1], CLOCK, RESET, EWR);
	DTrigger Dtrig2 (Res[2], DATA[2], CLOCK, RESET, EWR);
	DTrigger Dtrig3 (Res[3], DATA[3], CLOCK, RESET, EWR);
	DTrigger Dtrig4 (Res[4], DATA[4], CLOCK, RESET, EWR);
	DTrigger Dtrig5 (Res[5], DATA[5], CLOCK, RESET, EWR);
	DTrigger Dtrig6 (Res[6], DATA[6], CLOCK, RESET, EWR);
	DTrigger Dtrig7 (Res[7], DATA[7], CLOCK, RESET, EWR);

	always @(posedge CLOCK or posedge RESET) begin
		if (RESET) begin
			res <= 0;
		end
		else begin
			if (~EDY) begin
				res <= ~Res;
			end
			else begin
				res <= {numbits{1'bz}};
			end
		end
	end
	
	assign OUTRESULT = res;
endmodule