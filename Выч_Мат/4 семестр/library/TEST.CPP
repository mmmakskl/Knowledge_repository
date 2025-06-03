
#include "forsythe.h"
#include <stdio.h>

void TestZeroin();
void TestUrand();
void TestSVD();
void TestSpline();
void TestDecomp();
void TestQuaNC8();
void TestFMin();
void TestRKF45();

////////////////////////////////////////////////////////////////////////////////
REAL f(REAL x){return x* (x*x - 2.0) - 5.0;}

////////////////////////////////////////////////////////////////////////////////
int main()
{
	TestZeroin();
	getchar();
	TestFMin();
	getchar();
	TestSpline();
	getchar();
	TestQuaNC8();
	getchar();
	TestDecomp();
	getchar();
	//    TestSVD();
	//    getchar();*/
	TestRKF45();
	getchar();
	TestUrand();
    getchar();

	return 0;
}


////////////////////////////////////////////////////////////////////////////////
void TestZeroin()
{
    printf(
"////////////////////////////////////////////////////////////////////////////\n"
"ZEROIN test\n");
    REAL	ans;
    ans = ZEROIN(2.0, 3.0, f, 1e-6);
    printf("Result = %.6g\n", ans);
}

////////////////////////////////////////////////////////////////////////////////
void TestUrand()
{
    printf(
"////////////////////////////////////////////////////////////////////////////\n"
"URAND test\n");
    INIT_URAND(273);
    int     i;
    for(i = 0; i < 20; i++) printf("%f, %f, %f\n",URAND(),URAND(),URAND());
}

////////////////////////////////////////////////////////////////////////////////
void TestSVD()
{
    printf(
"////////////////////////////////////////////////////////////////////////////\n"
"SVD test\n");
    
}

////////////////////////////////////////////////////////////////////////////////
void    fun(REAL T, REAL *Y, REAL *YP)
{
	YP[0] = -1.0*Y[0] + 0.0*Y[1] + 1.0*Y[2];
	YP[1] =  0.0*Y[0] - 1.0*Y[1] + 0.0*Y[2] + 1/(T+0.1);
	YP[2] =  0.0*Y[0] + 0.0*Y[1] - 1.0*Y[2];
}
void TestRKF45()
{
	printf(
"////////////////////////////////////////////////////////////////////////////\n"
"RKF45 test\n");
	REAL	y[3] = {1.0, 2.0, 3.0};
	REAL    t = 0;
	REAL    tOut;
	REAL    relerr = 0.01;
	REAL    abserr = 0.01;
	REAL    WORK[3+6*3];
	int     flag = 1;
	int     i;
	for(i = 1; i < 10; i++)
	{
		tOut = i;
		RKF45(fun,3,y,t,tOut,relerr,abserr,WORK,flag);
		printf("%lg; %lg; %lg; ", y[0], y[1], y[2]);
		printf("flag = %i\n",  flag);
	}
}

////////////////////////////////////////////////////////////////////////////////
void TestSpline()
{
	printf(
"////////////////////////////////////////////////////////////////////////////\n"
"SPLINE class test\n");
	REAL X[] = {-1,0,1,2,3};
	REAL Y[] = {1,0,1,4,9};
	SPLINE  s(5,X,Y);
	printf("1.5**2 = %g\n", s.Eval(1.5));
}

////////////////////////////////////////////////////////////////////////////////
void TestDecomp()
{
	printf(
"////////////////////////////////////////////////////////////////////////////\n"
"DECOMP class test\n");
	REAL    l1[] = {1.0, 0.0, 0.0};
	REAL    l2[] = {0.0, 1.0, 0.0};
	REAL    l3[] = {0.0, 0.0, 1.0};
    REAL    *A[] = {l1, l2, l3};

    REAL    b[] = {2.0, 3.0, 5.0};
    DECOMP  D(3,A);
    D.Solve(b);
    printf("COND= %lg; DET= %lg\n", D.Cond(), D.Det());
    printf("SOLUTION = %lg; %lg; %lg;\n",b[0], b[1], b[2]);
}

////////////////////////////////////////////////////////////////////////////////
void TestQuaNC8()
{
    printf(
"////////////////////////////////////////////////////////////////////////////\n"
"QuaNC8 test\n");
    REAL    ans;
    REAL    err;
    REAL    flag;
    int     n;
    QUANC8(f,-2.0,2.0,1e-5,1e-5, ans,err,n,flag);
    printf("Value = %.7g +/- %.2g. Made %i calculations.(%f)\n",
    ans, err, n, flag);
}

////////////////////////////////////////////////////////////////////////////////
void TestFMin()
{
    printf(
"////////////////////////////////////////////////////////////////////////////\n"
"FMIN test\n");
    REAL	ans;
    ans = FMIN(0.0, 1.0, f, 1e-3);
    printf("Result = %.4g\n", ans);
}

