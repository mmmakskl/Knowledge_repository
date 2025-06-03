#include "ZeroCounter.h"

void ZeroCounter::process_count() {
    // reset behavior
    count_reg = 0;
    running = true;
    zero_count.write(count_reg);
    wait();
    while (true) {
        if (reset.read()) {
            count_reg = 0;
            running = true;
        } else if (running) {
            if (in.read() == 1) {
                running = false;
            } else {
                count_reg = count_reg + 1;
            }
        }
        zero_count.write(count_reg);
        wait();
    }
}
