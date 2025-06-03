onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -divider -height 25 {New Divider}
add wave -noupdate -format Logic /mytimer_tb/alarm
add wave -noupdate -format Logic /mytimer_tb/clk
add wave -noupdate -format Literal -radix binary /mytimer_tb/d
add wave -noupdate -format Literal -radix unsigned /mytimer_tb/high
add wave -noupdate -format Literal -radix unsigned /mytimer_tb/low
add wave -noupdate -format Logic /mytimer_tb/reset
add wave -noupdate -format Logic /mytimer_tb/start
add wave -noupdate -format Logic /mytimer_tb/stop
add wave -noupdate -divider -height 500 {New Divider}
add wave -noupdate -format Logic -label {HIGH TIMER: cnten} /mytimer_tb/U_0/U_1/U_1/cnten
add wave -noupdate -format Literal -label {COUNTER: dat_in DOESNT LOAD} -radix hexadecimal /mytimer_tb/U_0/U_1/dat_in
add wave -noupdate -format Logic -label {COUNTER: load !!!} /mytimer_tb/U_0/U_1/load
add wave -noupdate -divider {New Divider}
add wave -noupdate -format Literal -radix hexadecimal /mytimer_tb/U_0/U_0/flush
add wave -noupdate -format Literal -radix hexadecimal /mytimer_tb/U_0/U_0/load_u
add wave -noupdate -format Literal -radix hexadecimal /mytimer_tb/U_0/U_0/load_t
add wave -noupdate -format Literal -radix hexadecimal /mytimer_tb/U_0/U_0/getkey
add wave -noupdate -format Literal -radix hexadecimal /mytimer_tb/U_0/U_0/end_count
add wave -noupdate -format Literal -radix hexadecimal /mytimer_tb/U_0/U_0/suspended
add wave -noupdate -format Literal -radix hexadecimal /mytimer_tb/U_0/U_0/counting
add wave -noupdate -format Literal -radix hexadecimal /mytimer_tb/U_0/U_0/standby
add wave -noupdate -format Literal -radix hexadecimal /mytimer_tb/U_0/U_0/alarm
add wave -noupdate -format Literal -label {CONTROL current_state} -radix hexadecimal /mytimer_tb/U_0/U_0/current_state
add wave -noupdate -format Logic -label {CONTROL load} /mytimer_tb/U_0/U_0/load
add wave -noupdate -format Logic /mytimer_tb/U_0/U_0/clear
add wave -noupdate -format Logic /mytimer_tb/U_0/U_0/hold
add wave -noupdate -format Logic /mytimer_tb/U_0/U_0/load
add wave -noupdate -format Literal -radix hexadecimal /mytimer_tb/U_0/U_0/d
add wave -noupdate -format Logic /mytimer_tb/U_0/U_0/start
add wave -noupdate -format Logic /mytimer_tb/U_0/U_0/stop
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {891 ns} 0}
configure wave -namecolwidth 212
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
update
WaveRestoreZoom {0 ns} {4244 ns}
