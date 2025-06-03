module verilog_qs(
                input  wire clk,
                input  wire [10:0] in1, in2, in3, in4, in5, in6, in7, in8, in9, in10,
                output reg  [10:0] out1, out2, out3, out4, out5, out6, out7, out8, out9, out10);
    
    reg signed [10:1] data [0:10]; // Array to be sorted

	function automatic integer part;
		input integer l, h;
        begin
            data[1] = 100;
            part=2;
        end
    endfunction 

	function automatic integer qs;
		input integer low, high;
        integer pivot;
		integer ignored;
        begin
            if (low < high)
            begin
                pivot = part(low, high);
                qs(low, pivot-1);
                ignored = qs(pivot+1, high);
            end
            qs = 0;
        end
    endfunction

    integer ignored;
    // Initialize the array with input data
    always @(posedge clk) begin
            data[1] = in1;
            data[2] = in2;
            data[3] = in3;
            data[4] = in4;
            data[5] = in5;
            data[6] = in6;
            data[7] = in7;
            data[8] = in8;  
            data[9] = in9;
            data[10] = in10;
            ignored = qs(1, 2);
			out1 = data[1];
    end



	initial begin
	end


endmodule