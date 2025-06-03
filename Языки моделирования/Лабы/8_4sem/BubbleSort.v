module BubbleSort #(parameter N = 8, parameter WIDTH = 8) (
    input clk,
    input rst,
    input start,
    input [N*WIDTH-1:0] data_in,
    output reg [N*WIDTH-1:0] data_out,
    output reg done
);

    reg [WIDTH-1:0] mem [0:N-1];
    reg [WIDTH-1:0] array [0:N-1];
    reg [3:0] i, j, k;
    reg [WIDTH-1:0] temp;
    reg sorting;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            done <= 0;
            sorting <= 0;
            i <= 0;
            j <= 0;
        end else if (start && !sorting) begin
            sorting <= 1;
            done <= 0;
			for (i = 0; i < N; i = i + 1) begin
                mem[i] = data_in[i*WIDTH +: WIDTH];
            end
            i <= 0;
            j <= 0;
        end else if (sorting) begin
            if (i < N - 1) begin
                if (j < N - 1 - i) begin
                    if (mem[j] > mem[j + 1]) begin
                        temp = mem[j];
                        mem[j] = mem[j + 1];
                        mem[j + 1] = temp;
                    end
                    j <= j + 1;
                end else begin
                    j <= 0;
                    i <= i + 1;
                end

            end else begin
                sorting <= 0;
                done <= 1;
            end
        end

		for (k = 0; k < N; k = k + 1) begin
            data_out[k*WIDTH +: WIDTH] = mem[k];
        end
    end
endmodule
