module reg_ind(data_in, write_clk, data_out, read_clk);
  input [7:0] data_in;
  input write_clk;
  output data_out;
  reg data_out_tmp;
  input read_clk;
  reg [7:0] data;
  integer i = 0;


  always @(posedge write_clk) begin
    if (write_clk) begin
      data <= data_in;
    end
  end

  always @(posedge read_clk) begin
    if (read_clk) begin
      data_out_tmp <= data[i];
      i = (i + 1) % 8;
    end
  end

  assign data_out = data_out_tmp;

endmodule
