global env
# OPTIMIZE
 optimize .my_project_lib.mytimer.INTERFACE -target apa -effort quick -chip  -hierarchy auto
 optimize_timing -force .my_project_lib.mytimer.INTERFACE

 # WRITE DESIGN NETLIST
 auto_write -format edif "$env(HDS_PROJECT_DIR)/my_project_lib/ls/mytimer/netlists/mytimer.edf"

 # WRITE XDB FILE
 auto_write -format xdb "$env(HDS_PROJECT_DIR)/my_project_lib/ls/mytimer/xdb/mytimer.xdb"

 # WRITE REPORTS
 report_area -cell_usage > "$env(HDS_PROJECT_DIR)/my_project_lib/ls/mytimer/reports/mytimer_INTERFACE_sum.txt"
 report_delay -num_paths 1 -clock_frequency >> "$env(HDS_PROJECT_DIR)/my_project_lib/ls/mytimer/reports/mytimer_INTERFACE_sum.txt"
 file copy -force "$env(HDS_PROJECT_DIR)/my_project_lib/ls/mytimer/reports/mytimer_INTERFACE_sum.txt" "$env(HDS_PROJECT_DIR)/my_project_lib/ls/mytimer/netlists/mytimer_INTERFACE_sum"

 # Specify output file location (LS2000.1a2 and later)
 set output_file "$env(HDS_PROJECT_DIR)/my_project_lib/ls/mytimer/netlists/mytimer.edf"
