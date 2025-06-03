module verilog_qs(
                input  wire clk,
                input  wire [10:0] in1, in2, in3, in4, in5, in6, in7, in8, in9, in10,
                output reg  [10:0] out1, out2, out3, out4, out5, out6, out7, out8, out9, out10);

    reg signed [10:1] data [0:10]; // Array to be sorted

	function automatic integer part;
		input integer l, h;
    integer pivot;
    integer left_wall;
    integer i;
    integer temp;
        begin
            pivot = data[h];
            left_wall = l-1;
            for (i = l; i < h; i = i + 1)
            begin
              if (data[i] < pivot)
              begin
                left_wall = left_wall + 1;
                temp = data[i];
                data[i] = data[left_wall];
                data[left_wall] = temp;
              end
            end
            temp = data[h];
            data[h] = data[left_wall+1];
            data[left_wall+1] = temp;
            part = left_wall+1;
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
                ignored = qs(low, pivot-1);
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
            out2 = data[2];
            out3 = data[3];
            out4 = data[4];
            out5 = data[5];
            out6 = data[6];
            out7 = data[7];
            out8 = data[8];
            out9 = data[9];
            out10 = data[10];
    end



	initial begin
	end


endmodule