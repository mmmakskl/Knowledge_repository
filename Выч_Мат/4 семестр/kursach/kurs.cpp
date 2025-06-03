#include <iostream>
#include <cmath>
#include "forsythe.h"
#include <iomanip>
#include <fstream>

using namespace std;

const double EPS = 1e-6;
const double HPRINT = 0.4;
const int N = 2;
const double X0[N] = {0.0, 2.0};
double epsilon;
double omega;

void calculateOmega(double& omega);
void calculateEpsilon(double& epsilon);
void integrateSystem(double epsilon, double omega, double X0[], double T, double H);
void evaluateErrorImpact(double epsilon, double omega, double X0[], double T, double H);

void funDiff(double t, double x[], double dxdt[]) {
    dxdt[0] = epsilon * (1 - x[1]*x[1]) * x[0] - omega*omega * x[1];
    dxdt[1] = x[0];
}

double funInt(double x) {
    return 1.0 / sqrt((1 - x*x)*(1 - 0.25*x*x));
}

int main() {
    calculateOmega(omega);
    calculateEpsilon(epsilon);

    double X0[2] = {0, 2};

    printf("=== Basic calculation ===\n");
    integrateSystem(epsilon, omega, X0, 12.0, HPRINT);

    epsilon *= 0.99;
    omega *= 0.99;

    printf("\n\n=== Estimation of the impact of the error ===\n");
    integrateSystem(epsilon, omega, X0, 12.0, HPRINT);

    return 0;
}

void calculateOmega(double& omega) {
    double a = 0.0, b = 0.5;
    double epsrel = 1e-10, epsabs = 0.0;
    double result, errest, flag;
    int nofun;

    QUANC8(funInt, a, b, epsabs, epsrel, result, errest, nofun, flag);
    omega = 1.888828 * result;
}

void calculateEpsilon(double& epsilon) {
    double x = 1.0;
    for(int i = 0; i < 10; i++) {
        double f = x - pow(1.1, x);
        double df = 1 - pow(1.1, x) * log(1.1);
        if(fabs(f) < 1e-12) break;
        x -= f / df;
    }
    epsilon = 0.1798913 * x;
}

void integrateSystem(double eps, double omg, double X0[], double T, double H) {
    const int neqn = 2;
    double X[neqn] = {X0[0], X0[1]};
    double t = 0.0;
    double work[3 + 6*neqn];
    int iflag = 1;

    double relerr = EPS;
    double abserr = EPS;

    printf("epsilon = %.8f  omega = %.8f \n", eps, omg);
    printf("-----------------------------------------\n");
    printf("   t       U              U'         Flag\n");
    printf("%-5.1f %-15.6f %-15.6f\n", t, X[1], X[0]);


    while(t<T) {
        double tout = min(t+H, T);
        RKF45(funDiff, neqn, X, t, tout, relerr, abserr, work, iflag);

        printf("%-5.1f %-15.6f %-15.6f %-4d \n", t, X[1], X[0], iflag);
    }
}