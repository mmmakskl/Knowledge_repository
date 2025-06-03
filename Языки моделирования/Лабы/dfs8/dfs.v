module dfs (
    input clk,
    input reset,
    input [99:0] adjacency_matrix,  // 10x10 adjacency matrix
    input [3:0] start_node,         // Start node from 1 to 10

    output reg [3:0] result0,
    output reg [3:0] result1,
    output reg [3:0] result2,
    output reg [3:0] result3,
    output reg [3:0] result4,
    output reg [3:0] result5,
    output reg [3:0] result6,
    output reg [3:0] result7,
    output reg [3:0] result8,
    output reg [3:0] result9,
    output reg [3:0] result_len,    // Current result length
    output reg done
);

    parameter IDLE = 2'b00;
    parameter INIT = 2'b01;
    parameter PROCESS = 2'b10;
    parameter DONE = 2'b11;

    reg [1:0] state;

    reg [9:0] visited;
    reg [3:0] stack [0:9];
    reg [3:0] stack_ptr;

    reg [3:0] current_node;
    reg [3:0] i;
    reg processing_neighbors;

    wire [9:0] adj_row;

    assign adj_row = (current_node == 1) ? adjacency_matrix[99:90] :
                    (current_node == 2) ? adjacency_matrix[89:80] :
                    (current_node == 3) ? adjacency_matrix[79:70] :
                    (current_node == 4) ? adjacency_matrix[69:60] :
                    (current_node == 5) ? adjacency_matrix[59:50] :
                    (current_node == 6) ? adjacency_matrix[49:40] :
                    (current_node == 7) ? adjacency_matrix[39:30] :
                    (current_node == 8) ? adjacency_matrix[29:20] :
                    (current_node == 9) ? adjacency_matrix[19:10] :
                                          adjacency_matrix[9:0];

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            state <= IDLE;
            visited <= 0;
            result0 <= 0;
            result1 <= 0;
            result2 <= 0;
            result3 <= 0;
            result4 <= 0;
            result5 <= 0;
            result6 <= 0;
            result7 <= 0;
            result8 <= 0;
            result9 <= 0;
            result_len <= 0;
            stack_ptr <= 0;
            done <= 0;
            current_node <= 0;
            i <= 0;
            processing_neighbors <= 0;
        end else begin
            case (state)
                IDLE: begin
                    done <= 0;
                    if (start_node >= 1 && start_node <= 10) begin
                        visited <= 0;
                        result0 <= 0;
                        result1 <= 0;
                        result2 <= 0;
                        result3 <= 0;
                        result4 <= 0;
                        result5 <= 0;
                        result6 <= 0;
                        result7 <= 0;
                        result8 <= 0;
                        result9 <= 0;
                        result_len <= 0;
                        stack_ptr <= 1;
                        stack[0] <= start_node;
                        visited[start_node - 1] <= 1;
                        current_node <= start_node;
                        result0 <= start_node;
                        result_len <= 1;
                        i <= 0;
                        processing_neighbors <= 1;
                        state <= PROCESS;
                    end
                end

                PROCESS: begin
                    if (processing_neighbors) begin
                        if (i < 10) begin
                            if (adj_row[9 - i] && !visited[i]) begin
                                visited[i] <= 1;
                                stack[stack_ptr] <= i + 1;
                                stack_ptr <= stack_ptr + 1;
                                current_node <= i + 1;

                                case (result_len)
                                    1: result1 <= i + 1;
                                    2: result2 <= i + 1;
                                    3: result3 <= i + 1;
                                    4: result4 <= i + 1;
                                    5: result5 <= i + 1;
                                    6: result6 <= i + 1;
                                    7: result7 <= i + 1;
                                    8: result8 <= i + 1;
                                    9: result9 <= i + 1;
                                endcase

                                result_len <= result_len + 1;
                                i <= 0;
                            end else begin
                                i <= i + 1;
                            end
                        end else begin
                            processing_neighbors <= 0;
                        end
                    end else begin
                        if (stack_ptr == 0) begin
                            state <= DONE;
                        end else begin
                            stack_ptr <= stack_ptr - 1;
                            current_node <= stack[stack_ptr - 1];
                            i <= 0;
                            processing_neighbors <= 1;
                        end
                    end
                end

                DONE: begin
                    done <= 1;
                    state <= IDLE;
                end
            endcase
        end
    end

endmodule