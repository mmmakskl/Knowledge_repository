#include <iostream>
#include <mmintrin.h>   // MMX
#include <xmmintrin.h>  // SSE
#include <immintrin.h>  // AVX

using std::cout;
using std::endl;

// Custom functions for SIMD operations
__m64 my_mm_sub(__m64 m1, __m64 m2) {
    __asm__ volatile (
        "psubsb %1, %0"
        : "+x" (m1)
        : "x" (m2)
    );
    return m1;
}

__m128 my_mm_mul(__m128 m1, __m128 m2) {
    __asm__ volatile (
        "mulps %2, %1\n\t"
        "movaps %1, %0"
        : "=x" (m1)
        : "x" (m1), "x" (m2)
    );
    return m1;
}

__m256 my_mm_mul(__m256 m1, __m256 m2) {
    __asm__ volatile (
        "vmulps %2, %1, %0"
        : "=v" (m1)
        : "v" (m1), "v" (m2)
    );
    return m1;
}

int main() {
    // MMX
    int qw1[2] = {10, 20};
    int qw2[2] = {3, 7};
    __asm__ volatile (
        "movq %1, %%mm0\n\t"
        "movq %2, %%mm1\n\t"
        "psubd %%mm1, %%mm0\n\t"
        "movq %%mm0, %0\n\t"
        "emms"
        : "=m" (qw1)
        : "m" (qw1), "m" (qw2)
        : "%mm0", "%mm1"
    );
    cout << "MMX Sub: " << qw1[0] << " " << qw1[1] << endl;

    // SSE
    float c[4] = {9, 16, 25, 36};
    float d[4] = {3, 4, 5, 6};
    float res[4];
    __m128 vec1 = _mm_loadu_ps(c);
    __m128 vec2 = _mm_loadu_ps(d);
    vec1 = _mm_div_ps(vec1, vec2);
    _mm_storeu_ps(res, vec1);
    cout << "SSE Div: ";
    for (float f : res) cout << f << " ";
    cout << endl;

    // AVX
    double avx1[4] = {1, 2, 3, 4};
    double avx2[4] = {5, 6, 7, 8};
    __m256d ymm1 = _mm256_loadu_pd(avx1);
    __m256d ymm2 = _mm256_loadu_pd(avx2);
    ymm1 = _mm256_mul_pd(ymm1, ymm2);
    _mm256_storeu_pd(avx1, ymm1);
    cout << "AVX Mul: " << avx1[0] << " " << avx1[1] << endl;

    // Horizontal add (SSE3)
    float ha1[4] = {1.0, 2.0, 3.0, 4.0};
    __m128 hvec1 = _mm_loadu_ps(ha1);
    __m128 hadd_result = _mm_hadd_ps(hvec1, hvec1);
    _mm_storeu_ps(ha1, hadd_result);
    cout << "Horizontal Add: ";
    for (float f : ha1) cout << f << " ";
    cout << endl;

    // Subtraction with saturation (MMX)
    __m64 mm1 = _mm_set_pi8(100, -100, 50, -50, 25, -25, 10, -10);
    __m64 mm2 = _mm_set_pi8(50, 50, 50, 50, 50, 50, 50, 50);
    __m64 sub_result = my_mm_sub(mm1, mm2);
    int8_t sub_res[8];
    _mm_storeu_si64((__m64*)sub_res, sub_result);
    cout << "Subtraction with Saturation: ";
    for (int i = 0; i < 8; ++i) cout << (int)sub_res[i] << " ";
    cout << endl;

    return 0;
}