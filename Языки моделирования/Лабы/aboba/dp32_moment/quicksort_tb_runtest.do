vcom "$DSN\src\sort_types.vhd" 
vcom "$DSN\src\quicksort.vhd" 
vcom "Z:\dp32_moment\quicksort_tb.vhd" 
vsim TESTBENCH_FOR_quicksort 
wave  
wave clk
wave data_in
wave data_out
# The following lines can be used for timing simulation
# vcom <backannotated_vhdl_file_name>
# vcom "Z:\dp32_moment\quicksort_tb_tim_cfg.vhd" 
# vsim TIMING_FOR_quicksort 
