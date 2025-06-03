#include "ZeroCounterTest.h"
#include <iostream>

void ZeroCounterTest::generate_stimuli() {
    // Single-cycle reset at start
    wait();
    reset.write(1);
    wait();
    reset.write(0);
    wait();

    int tests[] = {10, 5, 100, 37};
    for (int idx = 0; idx < 4; ++idx) {
        int n = tests[idx];
        // Drive n zeros
        for (int i = 1; i < n; ++i) {
            in.write(0);
            wait();
        }
        // Single-cycle high pulse on in to freeze
        in.write(1);
        wait();
        // Return in low for hold (doesn't affect running=false)
        in.write(0);
        // Wait 5 cycles before reset
        for (int i = 0; i < 5; ++i) wait();
        // Report
        std::cout << "@" << sc_time_stamp()
            << ": Expected zero_count=" << n
            << ", Observed=" << zero_count.read() << std::endl;

        // Single-cycle reset
        reset.write(1);
        wait();
        reset.write(0);
        wait();
    }
    sc_stop();
}