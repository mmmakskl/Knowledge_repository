#ifndef FORSYTHE_H
#define FORSYTHE_H

/*
 Grigoriev D. I.
 gr 2081/4
 350-22-94
*/

#include <math.h>
#include <stdlib.h>
#include <functional>
#include <vector>
#define REAL double
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define EXP(x) exp(x)
#define SQRT(x) sqrt(x)
#define SIN(x) sin(x)
#define COS(x) cos(x)
#define TAN(x) tan(x)
#define ATAN(x) atan(x)

//enum bool{false, true}; //remove if using MS VC

inline double absval(double x)
{
    return fabs(x);
}
inline int absval(int x)
{
	return abs(x);
}
#define ABS(x) absval(x)
#define SIGN(a,b) (b<0) ? (-absval(a)) : absval(a)

REAL ZEROIN(REAL AX,REAL BX,REAL (F)(REAL X),REAL TOL);
void INIT_URAND(int I);
REAL URAND();
void SVD(int M,int N,REAL **A,REAL *W,bool MATU,REAL **U,bool MATV,REAL **V,int &IERR,REAL *RV1);
void QUANC8(std::function<double (double)> FUN,REAL A,REAL B,REAL ABSERR,REAL RELERR,REAL &RESULT,REAL &ERREST,int &NOFUN,REAL &FLAG);
REAL FMIN(REAL AX,REAL BX,REAL (F)(REAL X),REAL TOL);
void RKF45(void(F)(REAL T,REAL*Y,REAL*YP),int NEQN,REAL *Y,REAL &T,REAL TOUT,REAL &RELERR,REAL &ABSERR,REAL *WORK,int &IFLAG);

class SPLINE
{
    REAL    *X,
	    *Y,
	    *B,
	    *C,
	    *D;
    int     N;
    public:
	    SPLINE(int _N,REAL *_X,REAL *_Y);
	    ~SPLINE();
    REAL    Eval(REAL U);
};

class DECOMP
{
    int     N;
    std::vector<std::vector<double>> A;
    int     *IPVT;
    std::vector<double> WORK;
    REAL    COND;
    public:
	    DECOMP(int _N, const std::vector<std::vector<double>> &_A);
	    ~DECOMP();
    REAL    Cond(){return COND;};
    REAL    Det();
    void    Solve(std::vector<double> &B);
};

#endif // FORSYTHE_H
