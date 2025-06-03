/* File converted with FORTRAN CONVERTER utility.
   FORTRAN CONVERTER is written by Grigoriev D., 2081/4.*/

/*MARKERS: //! = probably incorrect, //? = possibly incorrect*/

#include "forsythe.h"


DECOMP :: DECOMP(int _N, const std::vector<std::vector<double>> &_A)
{

N = _N;
A = _A;
IPVT = new int[N];
//WORK = new REAL[N];
WORK = std::vector<double>(N);

REAL EK,T,ANORM,YNORM,ZNORM;
int NM1,I,J,K,KP1,KB,KM1,M;

IPVT[N-1]=1;
if(N==1)goto _80;
NM1=N-1;

ANORM=0.0;
for( J=1; J<=N; J++){   //? target=10
T=0.0;
for( I=1; I<=N; I++){   //? target=5
T=T+ABS(A[I-1][J-1]);
//_5:;
}                         	// CONTINUE
if(T>ANORM)ANORM=T;
//_10:;
}                         	// CONTINUE

for( K=1; K<=NM1; K++){   //? target=35
KP1=K+1;

M=K;
for( I=KP1; I<=N; I++){   //? target=15
if(ABS(A[I-1][K-1])>ABS(A[M-1][K-1]))M=I;
//_15:;
}                         	// CONTINUE
IPVT[K-1]=M;
if(M!=K)IPVT[N-1]=-IPVT[N-1];
T=A[M-1][K-1];
A[M-1][K-1]=A[K-1][K-1];
A[K-1][K-1]=T;

if(T==0.0)goto _35;

for( I=KP1; I<=N; I++){   //? target=20
A[I-1][K-1]=-A[I-1][K-1]/T;
//_20:;
}                         	// CONTINUE

for( J=KP1; J<=N; J++){   //? target=30
T=A[M-1][J-1];
A[M-1][J-1]=A[K-1][J-1];
A[K-1][J-1]=T;
if(T==0.0)goto _30;
for( I=KP1; I<=N; I++){   //? target=25
A[I-1][J-1]=A[I-1][J-1]+A[I-1][K-1]*T;
//_25:;
}                         	// CONTINUE
_30:;
}                         	// CONTINUE
_35:;
}                         	// CONTINUE

for( K=1; K<=N; K++){   //? target=50
T=0.0;
if(K==1)goto _45;
KM1=K-1;
for( I=1; I<=KM1; I++){   //? target=40
T=T+A[I-1][K-1]*WORK[I-1];
//_40:;
}                         	// CONTINUE
_45:;
EK=1.0;
if(T<0.0)EK=-1.0;
if(A[K-1][K-1]==0.0)goto _90;
WORK[K-1]=-(EK+T)/A[K-1][K-1];
//_50:;
}                         	// CONTINUE
for( KB=1; KB<=NM1; KB++){   //? target=60
K=N-KB;
T=WORK[K-1];
KP1=K+1;
for( I=KP1; I<=N; I++){   //? target=55
T=T+A[I-1][K-1]*WORK[I-1];
//_55:;
}                         	// CONTINUE
WORK[K-1]=T;
M=IPVT[K-1];
if(M==K)goto _60;
T=WORK[M-1];
WORK[M-1]=WORK[K-1];
WORK[K-1]=T;
_60:;
}                         	// CONTINUE

YNORM=0.0;
for( I=1; I<=N; I++){   //? target=65
YNORM=YNORM+ABS(WORK[I-1]);
//_65:;
}                         	// CONTINUE

//     PE��T� C�CTEM� A*Z=Y

Solve(WORK);

ZNORM=0.0;
for( I=1; I<=N; I++){   //? target=70
ZNORM=ZNORM+ABS(WORK[I-1]);
//_70:;
}                         	// CONTINUE

COND=ANORM*ZNORM/YNORM;
if(COND<1.0)COND=1.0;
return;  //?

_80:;
COND=1.0;
if(A[0][0]!=0.0)return;  //?

_90:;
//}                         	// CONTINUE
COND=1.0E+32;
return;
}                             	// END

DECOMP :: ~DECOMP()
{
    //delete [] WORK;
    delete [] IPVT;

}

REAL DECOMP :: Det()
{
    REAL    det = REAL(IPVT[N-1]);
    for(int i = 0; i < N; i++) det *= A[i][i];
    return det;
}

void DECOMP :: Solve(std::vector<double> &B)
{

int KB,KM1,NM1,KP1,I,K,M;
REAL T;

if(N==1)goto _50;
NM1=N-1;
for( K=1; K<=NM1; K++){   //? target=20
KP1=K+1;
M=IPVT[K-1];
T=B[M-1];
B[M-1]=B[K-1];
B[K-1]=T;
for( I=KP1; I<=N; I++){   //? target=10
B[I-1]=B[I-1]+A[I-1][K-1]*T;
//_10:;
}                         	// CONTINUE
//_20:;
}                         	// CONTINUE

for( KB=1; KB<=NM1; KB++){   //? target=40
KM1=N-KB;
K=KM1+1;
B[K-1]=B[K-1]/A[K-1][K-1];
T=-B[K-1];
for( I=1; I<=KM1; I++){   //? target=30
B[I-1]=B[I-1]+A[I-1][K-1]*T;
//_30:;
}                         	// CONTINUE
//_40:;
}                         	// CONTINUE
_50:;
B[0]=B[0]/A[0][0];
return;
}                              	// END
