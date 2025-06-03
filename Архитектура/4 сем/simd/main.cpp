#include <iostream>
#include <mmintrin.h>  // Для MMX

void mmx_saturated_add() {
    __m64 a = _mm_set_pi8(100, 120, 80, 90, 110, 70, 85, 95);
    __m64 b = _mm_set_pi8(50, 60, 70, 80, 90, 100, 110, 120);
    __m64 result = _mm_adds_pi8(a, b);

    // Используем встроенный ассемблер для сохранения MMX-регистра
    int8_t res[8];
    __asm__("movq %1, %0" : "=m"(res) : "x"(result));  // Сохранение через ассемблер

    std::cout << "MMX (saturated add): ";
    for (int i = 0; i < 8; ++i) std::cout << (int)res[i] << " ";
    std::cout << "n";

    _mm_empty();  // Обязательно очищаем MMX-состояние
}

int main() {
    mmx_saturated_add();
    return 0;
}