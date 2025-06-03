
#include "forsythe.h"
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

// void TestZeroin();
// void TestUrand();
// void TestSVD();
// void TestSpline();
void TestDecomp();
vector<vector<double>> compute_inverse(const vector<vector<double>>& A);
// void TestQuaNC8();
// void TestFMin();
// void TestRKF45();

const double N = 8;

vector<vector<double>> build_matrix(double p) {
    vector<vector<double>> A(N, vector<double>(N, 0));

    A[0] = {0.1+31, -7, -7, -4, -8, -4, -1, 0};
    A[1] = {-7, 27, -4, -4, 0, -1, -4, -7};
    A[2] = {-7, -4, 31, -8, -7, 0, -3, -2};
    A[3] = {-4, -4, -8, 39, -4, -7, -7,-5};
    A[4] = {-8, 0, -7, -4, 29, -7, -2, -1};
    A[5] = {-4, -1, 0, -7, -7, 25, -1, -5};
    A[6] = {-1, -4, -3, -7, -2, -1, 20, -2};
    A[7] = {0, -7, -2, -5, -1, -5, -2, 22};

    return A;
}

////////////////////////////////////////////////////////////////////////////////
REAL f(REAL x){return x* (x*x - 2.0) - 5.0;}

////////////////////////////////////////////////////////////////////////////////
int main()
{
	// TestZeroin();
	// getchar();
	// TestFMin();
	// getchar();
	// TestSpline();
	// getchar();
	// // TestQuaNC8();
	// getchar();
	TestDecomp();
	// getchar();
	//    TestSVD();
	//    getchar();*/
	// TestRKF45();
	// getchar();
	// TestUrand();
    // getchar();


	auto A = build_matrix(1);

	auto A_inv = compute_inverse(A);
	// Проверка: A * A_inv ≈ E
	for (auto row : A_inv) {
		for (auto x : row) cout << x << " ";
		cout << endl;
	}

	for (auto row : A) {
		for (auto x : row) cout << x << " ";
		cout << endl;
	}

	return 0;
}

vector<vector<double>> compute_inverse(const vector<vector<double>>& A) {
    const int n = A.size();
    vector<vector<double>> inv(n, vector<double>(n));

    // 1. Создаем объект DECOMP для матрицы A (выполняем LU-декомпозицию один раз)
    DECOMP decomp_obj(n, A);

    // 2. Для каждого столбца единичной матрицы решаем систему A * inv_col = e_j
    for (int j = 0; j < n; j++) {
        vector<double> e(n, 0.0); // Базисный вектор
        e[j] = 1.0;

        // Решаем систему A * inv_col = e_j
        decomp_obj.Solve(e); // Результат сохраняется в e

        // Записываем полученный вектор в j-й столбец обратной матрицы
        for (int i = 0; i < n; i++) {
            inv[i][j] = e[i];
        }
    }

    return inv;
}

////////////////////////////////////////////////////////////////////////////////
// void TestZeroin()
// {
//     printf(
// "////////////////////////////////////////////////////////////////////////////\n"
// "ZEROIN test\n");
//     REAL	ans;
//     ans = ZEROIN(2.0, 3.0, f, 1e-6);
//     printf("Result = %.6g\n", ans);
// }

// ////////////////////////////////////////////////////////////////////////////////
// void TestUrand()
// {
//     printf(
// "////////////////////////////////////////////////////////////////////////////\n"
// "URAND test\n");
//     INIT_URAND(273);
//     int     i;
//     for(i = 0; i < 20; i++) printf("%f, %f, %f\n",URAND(),URAND(),URAND());
// }

// ////////////////////////////////////////////////////////////////////////////////
// void TestSVD()
// {
//     printf(
// "////////////////////////////////////////////////////////////////////////////\n"
// "SVD test\n");
    
// }

// ////////////////////////////////////////////////////////////////////////////////
// void    fun(REAL T, REAL *Y, REAL *YP)
// {
// 	YP[0] = -1.0*Y[0] + 0.0*Y[1] + 1.0*Y[2];
// 	YP[1] =  0.0*Y[0] - 1.0*Y[1] + 0.0*Y[2] + 1/(T+0.1);
// 	YP[2] =  0.0*Y[0] + 0.0*Y[1] - 1.0*Y[2];
// }
// void TestRKF45()
// {
// 	printf(
// "////////////////////////////////////////////////////////////////////////////\n"
// "RKF45 test\n");
// 	REAL	y[3] = {1.0, 2.0, 3.0};
// 	REAL    t = 0;
// 	REAL    tOut;
// 	REAL    relerr = 0.01;
// 	REAL    abserr = 0.01;
// 	REAL    WORK[3+6*3];
// 	int     flag = 1;
// 	int     i;
// 	for(i = 1; i < 10; i++)
// 	{
// 		tOut = i;
// 		RKF45(fun,3,y,t,tOut,relerr,abserr,WORK,flag);
// 		printf("%lg; %lg; %lg; ", y[0], y[1], y[2]);
// 		printf("flag = %i\n",  flag);
// 	}
// }

// ////////////////////////////////////////////////////////////////////////////////
// void TestSpline()
// {
// 	printf(
// "////////////////////////////////////////////////////////////////////////////\n"
// "SPLINE class test\n");
// 	REAL X[] = {-1,0,1,2,3};
// 	REAL Y[] = {1,0,1,4,9};
// 	SPLINE  s(5,X,Y);
// 	printf("1.5**2 = %g\n", s.Eval(1.5));
// }

////////////////////////////////////////////////////////////////////////////////
void TestDecomp()
{
	printf(
"////////////////////////////////////////////////////////////////////////////\n"
"DECOMP class test\n");
	std::vector<std::vector<double>> A = {
	{1.0, 2.0, 3.0},
	{4.0, 5.0, 6.0},
	{7.0, 8.0, 10.0} // Пример матрицы 3x3
	};

	std::vector<double> b = {2.0, 3.0, 5.0};
    DECOMP D(3,A);
    D.Solve(b);
    printf("COND= %lg; DET= %lg\n", D.Cond(), D.Det());
    printf("SOLUTION = %lg; %lg; %lg;\n",b[0], b[1], b[2]);
}

////////////////////////////////////////////////////////////////////////////////
// void TestQuaNC8()
// {
//     printf(
// "////////////////////////////////////////////////////////////////////////////\n"
// "QuaNC8 test\n");
//     REAL    ans;
//     REAL    err;
//     REAL    flag;
//     int     n;
//     QUANC8(f,-2.0,2.0,1e-5,1e-5, ans,err,n,flag);
//     printf("Value = %.7g +/- %.2g. Made %i calculations.(%f)\n",
//     ans, err, n, flag);
// }

// ////////////////////////////////////////////////////////////////////////////////
// void TestFMin()
// {
//     printf(
// "////////////////////////////////////////////////////////////////////////////\n"
// "FMIN test\n");
//     REAL	ans;
//     ans = FMIN(0.0, 1.0, f, 1e-3);
//     printf("Result = %.4g\n", ans);
// }

