// ZeroCounter.h
#ifndef ZEROCOUNTER_H
#define ZEROCOUNTER_H

#include <systemc.h>

SC_MODULE(ZeroCounter) {
    // INPUTS
    sc_in_clk clk;
    sc_in<bool> reset;
    sc_in<bool> in;          // data bit: 0->count, 1->freeze

    // OUTPUT
    sc_out<sc_uint<32>> zero_count;

private:
    sc_uint<32> count_reg;
    bool running;            // true while counting, false after freeze

    void process_count();

public:
    SC_CTOR(ZeroCounter) : count_reg(0), running(true) {
        SC_CTHREAD(process_count, clk.pos());
        reset_signal_is(reset, true);
    }
};

#endif // ZEROCOUNTER_H
