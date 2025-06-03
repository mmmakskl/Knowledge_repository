global env
# SET WORKING DIR
set_working_dir "$env(HDS_PROJECT_DIR)/my_project_lib/ls/mytimer/netlists"

# SETUP
source "$env(HDS_PROJECT_DIR)/my_project_lib/ls/mytimer/scripts/setup.tcl"

# READ IN SOURCE FILES
source "$env(HDS_PROJECT_DIR)/my_project_lib/ls/mytimer/scripts/open_files.tcl"

# OPTIMIZE
source "$env(HDS_PROJECT_DIR)/my_project_lib/ls/mytimer/scripts/optimize.tcl"

puts "Info: HDS Synthesis run finished"
