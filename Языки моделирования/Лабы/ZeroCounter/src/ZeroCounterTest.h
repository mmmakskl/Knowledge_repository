#ifndef ZEROCOUNTERTEST_H
#define ZEROCOUNTERTEST_H

#include <systemc.h>

SC_MODULE(ZeroCounterTest) {
    sc_in_clk clk;
    sc_out<bool> reset;
    sc_out<bool> in;
    sc_in<sc_uint<32>> zero_count;

    void generate_stimuli();

    SC_CTOR(ZeroCounterTest) {
        SC_THREAD(generate_stimuli);
        sensitive << clk.pos();
    }
};

#endif // ZEROCOUNTERTEST_H
