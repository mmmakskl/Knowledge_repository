/* File converted with FORTRAN CONVERTER utility.
   FORTRAN CONVERTER is written by Grigoriev D., 2081/4.*/

#include "forsythe.h"

REAL FMIN(REAL AX,REAL BX,REAL (F)(REAL X),REAL TOL)
{

//     B���C��ET �P�����EH�E X K TO�KE, ��E F �OCT��AET
//     M�H�M�MA HA �HTEPBA�E (AX,BX)

//     BXO�HA� �H�OPMA���.

//     AX   �EB�� KOHE� �CXO�HO�O �HTEPBA�A
//     BX   �PAB�� KOHE� �CXO�HO�O �HTEPBA�A
//     F    �O��PO�PAMMA-��HK���, KOTOPA� B���C��ET F(X)
//          ��� ���O�O X B �HTEPBA�E (AX,BX)
//    TOL   �E�AEMA� ���HA �HTEPBA�A HEO�PE�E�EHHOCT�
//          KOHE�HO�O PE����TATA (>=0.0)

//    B�XO�HA� �H�OPMA���.

//    FMIN  A�C��CCA, A��POKC�M�P���A� TO�K�,
//          ��E F �OCT��AET M�H�M�MA

//       METO� �C�O����ET KOM��HA��� �O�CKA �O�OTO�O CE�EH��
//    � �OC�E�OBATE��HO� �APA�O���ECKO� �HTEP�O�����. CXO��-
//    MOCT� H�KO��A HE ��BAET �HA��TE��HO X��E, �EM ���
//    �O�CKA ���OHA���. EC�� F �MEET HE�PEP�BH�� BTOP��
//    �PO��BO�H��, �O�O��TE��H�� B TO�KE M�H�M�MA (HE
//    COB�A�A��E� H� C AX,H� C BX), TO CXO��MOCT� CBEPX-
//    ��HE�HA� � O���HO �MEET �OP��OK �P�MEPHO 1.324...
//       ��HK��� F H�KO��A HE B���C��ETC� B �B�X TO�KAX,
//    OTCTO���X �P�� OT �P��A MEHEE �EM HA EPS*ABS(X)+(TOL/3),
//    ��E EPS �P������TE��HO PABHO KBA�PATHOM� KOPH� ��
//    OTHOC�TE��HO� MA��HHO� TO�HOCT�. EC�� F-�H�MO�A��HA�
//    ��HK��� � B���C�EHH�E �HA�EH�� F COXPAH��T �H�MO�A��-
//    HOCT� �P� CO����EH�� �KA�AHHO�O �C�OB�� PA��E�EHHOCT�,
//    TO FMIN A��POKC�M�P�ET A�C��CC� ��O�A��HO�O M�H�M�MA F
//    HA �HTEPBA�E (AX,BX) C O���KO�, MEH��E� 3*EPS*ABS(X)+TOL.
//    EC�� F HE �B��ETC� �H�MO�A��HO�, TO FMIN MO�ET C TO� �E
//    TO�HOCT�� A��POKC�M�POBAT� �OKA��H�� M�H�M�M, BO�MO�HO,
//    HE COB�A�A���� C ��O�A��H�M.
//       �TA �O��PO�PAMMA-��HK��� �B��ETC� C�E�KA MO������PO-
//    BAHHO� BEPC�E� A��O� 60-�PO�E��P� LOCALMIN, �P�BE�EHHO�
//    B KH��E RICARD BRENT, ALGORITHMS FOR MINIMIZATION
//    WITHOUT DERIVATIVES, PRENTICE-HALL, INC.(1973).

REAL A,B,C,D=0.0,E,EPS,XM,P,Q,R,TOL1,TOL2,U,V,W;
REAL FU,FV,FW,FX,X;

//     C ECT� BO�BE�EHHA� B KBA�PAT BE����HA,
//     O�PATHA� K �O�OTOM� CE�EH��

C=0.5*(3.0-SQRT(5.0));

//     EPS �P������TE��HO PABHO KBA�PATHOM� KOPH� ��
//     OTHOC�TE��HO� MA��HHO� TO�HOCT�

EPS=1.0;
_10:;
EPS=EPS/2.0;
TOL1=1.0+EPS;
if(TOL1>1.0)goto _10;
EPS=SQRT(EPS);

//     �P�CBOEH�E HA�A��H�X �HA�EH��

A=AX;
B=BX;
V=A+C*(B-A);
W=V;
X=V;
E=0.0;
FX=F(X);
FV=FX;
FW=FX;

//     ��EC� HA��HAETC� OCHOBHO� ��K�

_20:;
XM=0.5*(A+B);
TOL1=EPS*ABS(X)+TOL/3.0;
TOL2=2.0*TOL1;

//     �POBEP�T� KP�TEP�� OKOH�AH��

if(ABS(X-XM)<=(TOL2-0.5*(B-A)))goto _90;

//     HEO�XO��MO �� �O�OTOE CE�EH�E

if(ABS(E)<=TOL1)goto _40;

//     �OCTPO�T� �APA�O��

R=(X-W)*(FX-FV);
Q=(X-V)*(FX-FW);
P=(X-V)*Q-(X-W)*R;
Q=2.0*(Q-R);
if(Q>0.0)P=-P;
Q=ABS(Q);
R=E;
E=D;

//     �P�EM�EMA �� �APA�O�A

//_30:;  //?!!
if(ABS(P)>=ABS(0.5*Q*R))goto _40;
if(P<=Q*(A-X))goto _40;
if(P>=Q*(B-X))goto _40;

//     �A� �APA�O���ECKO� �HTEP�O�����

D=P/Q;
U=X+D;

//     F HE C�E��ET B���C��T� C���KOM ����KO K AX ��� BX

if((U-A)<TOL2)D=SIGN(TOL1,XM-X);
if((B-U)<TOL2)D=SIGN(TOL1,XM-X);
goto _50;

//     �A� �O�OTO�O CE�EH��

_40:;
if(X>=XM)E=A-X;
if(X<XM)E=B-X;
D=C*E;

//     F HE C�E��ET B���C��T� C���KOM ����KO K X

_50:;
if(ABS(D)>=TOL1)U=X+D;
if(ABS(D)<TOL1)U=X+SIGN(TOL1,D);
FU=F(U);

//     �P�CBO�T� HOB�E �HA�EH�� �APAMETPAM A,B,V,W � X

if(FU>FX)goto _60;
if(U>=X)A=X;
if(U<X)B=X;
V=W;
FV=FW;
W=X;
FW=FX;
X=U;
FX=FU;
goto _20;

_60:;
if(U<X)A=U;
if(U>=X)B=U;
if(FU<=FW)goto _70;
if(W==X)goto _70;
if(FU<=FV)goto _80;
if(V==X)goto _80;
if(V==W)goto _80;
goto _20;

_70:;
V=W;
FV=FW;
W=U;
FW=FU;
goto _20;

_80:;
V=U;
FV=FU;
goto _20;

//     KOHE� OCHOBHO�O ��K�A

_90:;
return X;
}                         	// END
