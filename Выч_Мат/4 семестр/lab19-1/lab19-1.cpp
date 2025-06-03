#include <fstream>
#include <iomanip>
#include <iostream>
#include "forsythe.h"

double point;
double h = 0.5;
double x_beg = 0;
double x_end = 3;
int count_points = ((x_end - x_beg)/h) + 1;
double x_beg_compare = 0.25;

double func(double z) {
    return 1.0 / (exp(1.9*z*z) + point);
}

void computeQuanc8(double* x, double* f, int count_points, double h, double x_beg) {
    std::ofstream in("in.txt");
    double ans1, errest, flag;
    int col;

    std::cout << "Integral (quanc8)" << std::endl;
    for (int i = 0; i < count_points; i++) {
        point = x[i];
        QUANC8(func, 0.0, 1, 1e-7, 1e-7, ans1, errest, col, flag);

        std::cout << std::setw(3) << x[i] << std::setw(6) << "int=" << std::setw(8) << ans1
                << std::setw(9) << "errest=" << errest << std::setw(6)
                << "col=" << col << std::setw(7) << "flag=" << flag << std::endl;
        in << ans1 << std::endl;

        f[i] = ans1;
        if (i < (count_points - 1)) {
            x[i + 1] = x[i] + h;
        }
    }
    in.close();
}

void compareQuanc8WithSpline(double* x, double* f, int count_points, double x_beg_compare) {
    std::ofstream s("s.txt"), q("q.txt");
    double ans1, ans2, errest, flag;
    int col;

    SPLINE spline(count_points, x, f);

    std::cout << "\nComparison of quanc8 and spline\n"
            << "----------------------------------------------------------------------\n" <<
            std::setw(20) << "quanc8" << std::setw(17) << "Spline" << std::setw(12) << "Q-S\n"
            << "----------------------------------------------------------------------" << std::endl;

    double xj = x_beg_compare;
    for (int j = 0; j < count_points; j++) {
        point = xj;
        QUANC8(func, 0.0, 1, 1e-7, 1e-7, ans1, errest, col, flag);
        ans2 = spline.Eval(xj);
        std::cout << std::setw(8) << xj << " | "
                << std::setw(12) << ans1 << " | "
                << std::setw(12) << ans2 << " | "
                << std::setw(12) << (ans1 - ans2) << std::endl;
        s << ans2 << std::endl;
        q << ans1 << std::endl;
        xj += 0.5;
    }
    s.close();
    q.close();
}

double omega (double x, int k) {
    double ans = 1;
    double xk = x_beg;
    for (int i = 0; i < count_points; i++) {
        if (i != k) {
            ans *= x - xk;
        }
        xk += h;
    }
    return ans;
}

double Lagrange (double x, double* f) {
    double ans = 0;
    double xk = x_beg;
    for (int i = 0; i < count_points; i++) {
        ans += (omega(x, i)/omega(xk, i))* f[i];
        xk += h;
    }
    return ans;
}

void compareQuanc8WithLagrange(double* x, double* f, double x_beg_compare) {
    std::ofstream l("l.txt");
    double ans1, ans2, errest, flag;
    int col;

    std::cout << "\nComparison of quanc8 and lagrange\n"
            << "----------------------------------------------------------------------\n" <<
            std::setw(20) << "quanc8" << std::setw(17) << "Lagrange" << std::setw(12) << "Q-L\n"
            << "----------------------------------------------------------------------" << std::endl;

    double xj = x_beg_compare;
    for (int j = 0; j < count_points; j++) {
        point = xj;
        QUANC8(func, 0.0, 1.0, 1e-7, 1e-7, ans1, errest, col, flag);
        ans2 = Lagrange(xj, f);
        std::cout << std::setw(8) << xj << " | "
                << std::setw(12) << ans1 << " | "
                << std::setw(12) << ans2 << " | "
                << std::setw(12) << (ans1 - ans2) << std::endl;
        l << ans2 << std::endl;
        xj += 0.5;
    }
    l.close();
}


int main() {
    double x[count_points], f[count_points];
    x[0] = x_beg;

    computeQuanc8(x, f, count_points, h, x_beg);

    compareQuanc8WithSpline(x, f, count_points, x_beg_compare);

    compareQuanc8WithLagrange(x, f, x_beg_compare);

    return 0;
}
