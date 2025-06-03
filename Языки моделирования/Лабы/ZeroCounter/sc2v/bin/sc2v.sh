#!/bin/bash

if [ -z "$1" ]; then
    echo "SystemC 2 Verilog converter"
    echo "Usage: $0 <Module name without extension>"
    exit 1
fi

MODULE="$1"
SCRIPT_DIR=$(dirname "$0")

check_file() {
    if [ ! -f "$1" ]; then
        echo "Can't find $1"
        exit 1
    fi
}

check_file "${MODULE}.cpp"
check_file "${MODULE}.h"

echo "Processing ${MODULE}"
"${SCRIPT_DIR}/sc2v_step1" < "${MODULE}.cpp" || exit 1

echo "Processing ${MODULE}.h"
"${SCRIPT_DIR}/sc2v_step2" < "${MODULE}.h" > "${MODULE}.sc2v" || exit 1

echo "Generating verilog file"
"${SCRIPT_DIR}/sc2v_step3" < "${MODULE}.sc2v" > "${MODULE}.v" || exit 1

echo "Done"

# Cleanup
rm -f "${MODULE}.sc2v" *.sc2v 2>/dev/null