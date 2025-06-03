#include <iostream>
#include <cmath>
#include "forsythe.h"

using namespace std;

const double HPRINT = 0.0075;
const double H_OPT = 0.0025;
const double EPS = 0.0001;
const int N = 2;
const double Y0[N] = {3.0, -1.0};

void F(double T, double* Y, double* YP);
void rk2_step(void (*F)(double T, double* Y, double* YP), int NEQN, double Y[], double& T, double H);
void solve_with_rkf45();
void solve_with_rk2(double H);

int main() {
    solve_with_rkf45();
    solve_with_rk2(HPRINT);
    solve_with_rk2(H_OPT);
    return 0;
}

void F(double T, double* Y, double* YP) {
    YP[0] = -130 * Y[0] + 900 * Y[1] + exp(-10 * T);
    YP[1] = 30 * Y[0] - 300 * Y[1] + log(1 + 100 * T*T);
}

void rk2_step(void (*F)(double T, double* Y, double* YP), int NEQN, double Y[], double& T, double H) {
    double oldY[N], YP1[N], Y_temp[N], YP2[N];
    for (int i = 0; i < NEQN; ++i) {
        oldY[i] = Y[i];
    }

    F(T, oldY, YP1);

    for (int i = 0; i < NEQN; ++i) {
        Y_temp[i] = oldY[i] + (H / 4) * YP1[i];
    }

    F(T + H/4, Y_temp, YP2);

    for (int i = 0; i < NEQN; ++i) {
        Y[i] = oldY[i] + H * (-YP1[i] + 2 * YP2[i]);
    }

    T += H;
}

void solve_with_rkf45() {
    double Y[N];
    double T, TOUT;
    const int NEQN = N;
    double WORK[3 + 6*N] = {0};
    int IFLAG = 1;

    double relerr = EPS;
    double abserr = EPS;

    printf("\nSOLUTION WITH RKF45 (HPRINT = 0.0075, EPS = 0.0001):\n\n");
    printf("%-10s %-15s %-15s\n", "T", "Y[0]", "Y[1]");
    printf("----------------------------------------\n");

    Y[0] = Y0[0];
    Y[1] = Y0[1];
    T = 0.0;
    printf("%-10.4f %-15.4f %-15.4f\n", T, Y[0], Y[1]);

    for (TOUT = HPRINT; TOUT < 0.15 + 1e-6; TOUT += HPRINT) {
        RKF45(F, NEQN, Y, T, TOUT, relerr, abserr, WORK, IFLAG);
        if (IFLAG > 2) {
            printf("IFLAG ERROR: %d\n", IFLAG);
            break;
        }
        printf("%-10.4f %-15.4f %-15.4f\n", T, Y[0], Y[1]);
    }
    printf("\nFLAG: %d\n", IFLAG);
    printf("----------------------------------------\n");
}

void solve_with_rk2(double H) {
    double Y[N];
    double T;
    const int NEQN = N;

    printf("\nSOLUTION WITH RK2:\n");
    printf("\nSTEP = %.4f\n\n", H);
    printf("%-10s %-15s %-15s\n", "T", "Y[0]", "Y[1]");
    printf("----------------------------------------\n");

    Y[0] = Y0[0];
    Y[1] = Y0[1];
    T = 0.0;
    printf("%-10.4f %-15.4f %-15.4f\n", T, Y[0], Y[1]);

    while (T < 0.15 - 1e-6) {
        rk2_step(F, NEQN, Y, T, H);
        printf("%-10.4f %-15.4f %-15.4f\n", T, Y[0], Y[1]);
    }
    printf("----------------------------------------\n");
}