#include <systemc.h>
#include "ZeroCounter.h"
#include "ZeroCounterTest.h"

int sc_main(int argc, char* argv[]) {
    sc_clock clk("clk", 10, SC_NS);

    sc_signal<bool> reset_sig;
    sc_signal<bool> in_sig;
    sc_signal<sc_uint<32>> count_sig;

    ZeroCounter zc("ZeroCounter");
    ZeroCounterTest tb("ZeroCounterTest");

    // Bind ports
    zc.clk(clk);
    zc.reset(reset_sig);
    zc.in(in_sig);
    zc.zero_count(count_sig);

    tb.clk(clk);
    tb.reset(reset_sig);
    tb.in(in_sig);
    tb.zero_count(count_sig);

    // Trace
    sc_trace_file* tf = sc_create_vcd_trace_file("zero_counter_tb");
    tf->set_time_unit(1, SC_NS);
    sc_trace(tf, clk, "clk");
    sc_trace(tf, reset_sig, "reset");
    sc_trace(tf, in_sig, "in");
    sc_trace(tf, count_sig, "zero_count");

    sc_start(20000, SC_NS);
    sc_close_vcd_trace_file(tf);
    return 0;
}