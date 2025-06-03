#include <iostream>
#include <vector>
#include <cmath>
#include "forsythe.h"

using namespace std;

const vector<double> x_true = {3, 2, 1, 8, 5, 7, 1, 2};
const vector<double> p_values = {1.0, 0.1, 0.01, 0.0001, 0.000001};

const int N = 8;

vector<vector<double>> build_matrix(double p) {
    vector<vector<double>> A(N, vector<double>(N, 0));

    A[0] = {p+31, -7, -7, -4, -8, -4, -1, 0};
    A[1] = {-7, 27, -4, -4, 0, -1, -4, -7};
    A[2] = {-7, -4, 31, -8, -7, 0, -3, -2};
    A[3] = {-4, -4, -8, 39, -4, -7, -7,-5};
    A[4] = {-8, 0, -7, -4, 29, -7, -2, -1};
    A[5] = {-4, -1, 0, -7, -7, 25, -1, -5};
    A[6] = {-1, -4, -3, -7, -2, -1, 20, -2};
    A[7] = {0, -7, -2, -5, -1, -5, -2, 22};

    return A;
}

vector<double> build_b(double p) {
    vector<double> B(N);

    B = {3*p-29, -28, -104, 198, 29, 59, -71, -54};

    return B;
}

vector<double> solve_system(const vector<vector<double>>& A, const vector<double>& b) {
    DECOMP D(N, A);
    vector<double> x = b;
    D.Solve(x);
    return x;
}

vector<vector<double>> compute_inverse(const vector<vector<double>>& A) {
    vector<vector<double>> inv(N, vector<double>(N));
    for (int j = 0; j < N; j++) {
        vector<double> e(N, 0);
        e[j] = 1.0;
        DECOMP D(N, A);
        D.Solve(e);
        for (int i = 0; i < N; i++) {
            inv[i][j] = e[i];
        }

    }
    return inv;
}

double vector_norm(const vector<double>& v) {
    double sum = 0;
    for (auto x : v) sum += x*x;
    return sqrt(sum);
}

double compute_delta(const vector<double>& x_calculated) {
    double numerator = 0, denominator = vector_norm(x_true);
    for (int i = 0; i < N; i++)
        numerator += pow(x_calculated[i] - x_true[i], 2);
    return sqrt(numerator) / denominator;
}

void analyze_conditioning(double p, double cond, double delta1, double delta2) {
    cout << "p = " << p << endl;
    cout << "Condition number: " << cond << endl;
    cout << "Delta1: " << delta1 << endl;
    cout << "Delta2: " << delta2 << endl << endl;
}


int main() {
    for (auto p : p_values) {
        auto A = build_matrix(p);
        auto b = build_b(p);

        auto x1 = solve_system(A, b);
        auto A_inv = compute_inverse(A);

        vector<double> x2(N, 0);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                x2[i] += A_inv[i][j] * b[j];

        DECOMP D(N, A);
        analyze_conditioning(p, D.Cond(), compute_delta(x1), compute_delta(x2));
    }

    return 0;
}