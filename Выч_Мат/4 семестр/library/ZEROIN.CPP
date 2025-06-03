/* File converted with FORTRAN CONVERTER utility.
   FORTRAN CONVERTER is written by Grigoriev D., 2081/4.*/

#include "forsythe.h"

REAL ZEROIN(REAL AX,REAL BX,REAL (F)(REAL X),REAL TOL)
{
//     H��� ��HK��� F(X) B���C��ETC� B �HTEPBA�E AX,BX

//     BXO�HA� �H�OPMA���..

//     AX     �EB�� KOHE� �CXO�HO�O �HTEPBA�A
//     BX     �PAB�� KOHE� �CXO�HO�O �HTEPBA�A
//     F      �O��PO�PAMMA-��HK���, KOTOPA� B���C��ET F(X)
//            ��� ���O�O X B �HTEPBA�E AX BX
//     TOL    �E�AEMA� ���HA �HTEPBA�A HEO�PE�E�EHHOCT�
//            KOHE�HO�O PE����TATA

//     B�XO�HA� �H�OPMA���...

//     ZEROIN A�C��CCA, A��POKC�M�P���A� H��� ��HK��� F B
//            �HTEPBA�E AX, BX

//        �E� �POBEPK� �PE��O�A�AETC�, �TO F(AX) � F(BX) �ME�T
//     �POT�BO�O�O�H�E �HAK�.
//        ZEROIN B���C��ET H��� X B �A�AHHOM �HTEPBA�E AX, BX
//     B �PE�E�AX �O��CKA HA O���K�  4*MACHEPS*ABS(X) + TOL,
//     ��E MACHEPS-OTHOC�TE��HA� MA��HHA� TO�HOCT�.
//        �TA �O��PO�PAMMA-��HK��� �PE�CTAB��ET CO�O� C�E�KA
//     MO������POBAHH�� TPAHC����� A��O� 60-�PO�E��P� ZERO,
//     �P�BE�EHHO� B KH��E RICHARD BRENT, ALGORITHMS FOR
//     MINIMIZATION WITHOUT DERIVATIVES,PRENTICE HALL,INC.(1973).

REAL A,B,C,D,E,EPS,FA,FB,FC,TOL1,XM,P,Q,R,S;

//     B���C��T� EPS,OTHOC�TE��H�� MA��HH�� TO�HOCT�

EPS=1.0;
_10:;
EPS=EPS/2.0;
TOL1=1.0+EPS;
if(TOL1>1.0)goto _10;

//     �P�CBOEH�E HA�A��H�X �HA�EH��

A=AX;
B=BX;
FA=F(A);
FB=F(B);

//     HA�AT� �A�

_20:;
C=A;
FC=FA;
D=B-A;
E=D;
_30:;
if(ABS(FC)>=ABS(FB))goto _40;
A=B;
B=C;
C=A;
FA=FB;
FB=FC;
FC=FA;

//     �POBEPKA CXO��MOCT�

_40:;
TOL1=2.0*EPS*ABS(B)+0.5*TOL;
XM=0.5*(C-B);
if(ABS(XM)<=TOL1)goto _90;

//     HEO�XO��MA �� ��CEK���

if(FB==0.0)goto _90;
if(ABS(E)<TOL1)goto _70;
if(ABS(FA)<=ABS(FB))goto _70;

//     BO�MO�HA �� KBA�PAT��HA� �HTEP�O�����

if(A!=C)goto _50;

//     ��HE�HA� �HTEP�O�����

S=FB/FA;
P=2.0*XM*S;
Q=1.0-S;
goto _60;

//     O�PATHA� KBA�PAT��HA� �HTEP�O�����

_50:;
Q=FA/FC;
R=FB/FC;
S=FB/FA;
P=S*(2.0*XM*Q*(Q-R)-(B-A)*(R-1.0));
Q=(Q-1.0)*(R-1.0)*(S-1.0);

//     B��PAT� �HAK�

_60:;
if(P>0.0)Q=-Q;
P=ABS(P);

//     �P�EM�EMA �� �HTEP�O�����

if((2.0*P)>=(3.0*XM*Q-ABS(TOL1*Q)))goto _70;
if(P>=ABS(0.5*E*Q))goto _70;
E=D;
D=P/Q;
goto _80;

//     ��CEK���

_70:;
D=XM;
E=D;

//     �ABEP��T� �A�

_80:;
A=B;
FA=FB;
if(ABS(D)>TOL1)B=B+D;
if(ABS(D)<=TOL1)B=B+SIGN(TOL1,XM);
FB=F(B);
if((FB*(FC/ABS(FC)))>0.0)goto _20;
goto _30;

//     KOH�EHO

_90:;
return B;
}                         	// END

