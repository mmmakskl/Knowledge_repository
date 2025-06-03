#include "ZeroCounterRTL.h"

void ZeroCounterRTL::comb_logic() {
    sc_uint<32> cnt      = count_reg.read();
    bool        run      = running.read();
    sc_uint<32> cnt_next;
    bool        run_next;

    if (reset.read()) {
        cnt_next = 0;
        run_next = true;
    } else if (run) {
        if (in.read()) {
            cnt_next = cnt;
            run_next = false;
        } else {
            cnt_next = cnt + 1;
            run_next = true;
        }
    } else {
        cnt_next = cnt;
        run_next = run;
    }

    next_count_reg.write(cnt_next);
    next_running.write(run_next);
}

void ZeroCounterRTL::seq_logic() {
    if (reset.read()) {
        count_reg.write(0);
        running.write(true);
    } else {
        count_reg.write(next_count_reg.read());
        running.write(next_running.read());
    }
    zero_count.write(count_reg.read());
}
