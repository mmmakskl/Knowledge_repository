global env
# OPEN SOURCE FILES
read [list "$env(HDS_PROJECT_DIR)/my_project_lib/hdl/control_fsm.v" \
           "$env(HDS_PROJECT_DIR)/my_project_lib/hdl/BCDCounter.v" \
           "$env(HDS_PROJECT_DIR)/my_project_lib/hdl/counter_struct.v" \
           "$env(HDS_PROJECT_DIR)/my_project_lib/hdl/mytimer_struct.v"] -format verilog -work my_project_lib -tech apa
present_design .my_project_lib.mytimer.INTERFACE
