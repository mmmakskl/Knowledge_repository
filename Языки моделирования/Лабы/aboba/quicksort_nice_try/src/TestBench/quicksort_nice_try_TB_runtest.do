vcom "$DSN\src\sort_types.vhd" 
vcom "$DSN\src\quicksort_nice_try.vhd" 
vcom "$DSN\src\TestBench\quicksort_nice_try_TB.vhd" 
vsim TESTBENCH_FOR_quicksort_nice_try 
wave  
wave clk
wave data_in
wave data_out
# The following lines can be used for timing simulation
# vcom <backannotated_vhdl_file_name>
# vcom "$DSN\src\TestBench\quicksort_nice_try_TB_tim_cfg.vhd" 
# vsim TIMING_FOR_quicksort_nice_try 
