
#ifndef ZEROCOUNTERRTL_H
#define ZEROCOUNTERRTL_H

#include <systemc.h>

/**
 * ZeroCounterRTL
 *
 * Счетчик количества нулевых тактов до первого единичного входа.
 * Синтезируемая RTL-реализация на SystemC.
 */
SC_MODULE(ZeroCounterRTL) {
    // Порты
    sc_in_clk       clk;           // тактовый сигнал
    sc_in<bool>     reset;         // асинхронный сигнал сброса (активен high)
    sc_in<bool>     in;            // входной бит: 0 -> считаем, 1 -> останавливаем счет
    sc_out<sc_uint<32>> zero_count; // выход: текущее значение счетчика

    // Внутренние сигналы для хранения состояния
    sc_signal<sc_uint<32>> count_reg, next_count_reg;
    sc_signal<bool>        running,    next_running;

    // Комбинаторная логика: вычисление следующего состояния
    void comb_logic();

    // Последовательная логика: обновление регистров и выходов
    void seq_logic();

    // Конструктор
    SC_CTOR(ZeroCounterRTL) {
        SC_METHOD(comb_logic);
        sensitive << count_reg << running << in << reset;

        SC_METHOD(seq_logic);
        sensitive << clk.pos();
    }
};

#endif // ZEROCOUNTERRTL_H
