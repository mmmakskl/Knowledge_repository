/* File converted with FORTRAN CONVERTER utility.
   FORTRAN CONVERTER is written by Grigoriev D., 2081/4.*/

/*MARKERS: //! = probably incorrect, //? = possibly incorrect*/

#include "forsythe.h"


void SVD(int M,int N,REAL **A,REAL *W,bool MATU,REAL **U,bool MATV,REAL **V,int &IERR,REAL *RV1)
{

int I,J,K,L,II,I1,KK,K1,LL,L1,ITS,MN;
REAL C,F,G,H,S,X,Y,Z,SCALE,ANORM;


//     ÝTA ÏOÄÏPOÃPAMMA ECTÜ TPAHCËßÖÈß AËÃOË-ÏPOÖEÄÓPÛ SVD,
//     OÏÓÁËÈKOBAHHOÉ ÃOËÓÁOM È PAÉHØEM B ÆÓPHAËE NUMERISCHE
//     MATHEMATIK, 14, 403-420(1970), A TAKÆE B KHÈÃE
//     HANDBOOK FOR AUTOMATIC COMPUTATION  VOL.II-LINEAR
//     ALGEBRA, 134-151 (1971).

//     ÝTA ÏOÄÏPOÃPAMMA BÛ×ÈCËßET CÈHÃÓËßPHOE PAÇËOÆEHÈE
//     A=USV'  ÄEÉCTBÈTEËÜHOÉ ÏPßMOÓÃOËÜHOÉ MATPÈÖÛ A C PAÇME-
//     PAMÈ M È N. ÏPÈ ÝTOM ÈCÏOËÜÇÓÞTCß ÄBÓXÄÈAÃOHAËÈÇAÖÈß
//     ÏOCPEÄCTBOM XAÓCXOËÄEPOBÛX OTPAÆEHÈÉ  È BAPÈAHT
//     QR-AËÃOPÈTMA.

//     HA BXOÄE.

//     NM   CËEÄÓET ÏOËOÆÈTÜ PABHÛM CTPO×HOÉ PAÇMEPHOCTÈ
//          ÄBÓXMEPHÛX MACCÈBOB ,ÇAßBËEHHOÉ B OÏEPATOPE PAÇ-
//          MEPHOCTÈ BÛÇÛBAÞÙEÉ ÏPOÃPAMMÛ. ÇAMETÈM, ×TO NM
//          ÄOËÆHO ÁÛTÜ H  MEHÜØE,×EM MAKCÈMÓM ÈÇ M È N.

//     M    ×ÈCËO CTPOK A (È U).

//     N    ×ÈCËO CTOËÁÖOB A (È U) È ÏOPßÄOK V.

//     A    COÄEPÆÈT ÏPßMOÓÃOËÜHÓÞ BXOÄHÓÞ MATPÈÖÓ, ÄËß
//          KOTOPOÉ HAXOÄÈTCß  PAÇËOÆEHÈE.

//     MATU ÄOËÆEH ÈMETÜ ÇHA×EHÈE true, ECËÈ HÓÆHO
//          BÛ×ÈCËßTÜ MATPÈÖÓ U ÈÇ PAÇËOÆEHÈß, È ÇHA×EHÈE
//          false B ÏPOTÈBHOM CËÓ×AE.

//     MATV ÄOËÆEH ÈMETÜ ÇHA×EHÈE true, ECËÈ HÓÆHO
//          BÛ×ÈCËßTÜ MATPÈÖÓ V ÈÇ PAÇËOÆEHÈß, È ÇHA×EHÈE
//          false B ÏPOTÈBHOM CËÓ×AE.

//     HA BÛXOÄE.

//     A    HE ÈÇMEHßETCß (ECËÈ HA EE MECTE HE ÇAÏÈCÛBAÞTCß
//          U ËÈÁO V).

//     W    COÄEPÆÈT N (HEOTPÈÖATEËÜHÛX) CÈHÃÓËßPHÛX ×ÈCEË
//          A (ÄÈAÃOHAËÜHÛX ÝËEMEHTOB S). OHÈ HE ÓÏOPßÄO×EHÛ.
//          ECËÈ ÏPOÈCXOÄÈT BÛXOÄ ÏO OØÈÁKE, TO ÄËß ÇHA×EHÈÉ
//          IERR+1, IERR+2,...,N CÈHÃÓ ËßPHÛE ×ÈCËA ÄOËÆHÛ
//          ÁÛTÜ BEPHÛ.

//     U    COÄEPÆÈT MATPÈÖÓ U (C OPTOÃOHAËÜHÛMÈ CTOËÁÖAMÈ)
//          ÈÇ PAÇËOÆEHÈß, ECËÈ ÄËß ÏAPAMETPA MATU ÁÛËO
//          ÇAÄAHO ÇHA×EHÈE true B ÏPOTÈBHOM CËÓ×AE HA U
//          ÈCÏOËÜÇÓETCß KAK BPEMEHHÛÉ MACCÈB. U TAKÆE MOÆET
//          COBÏAÄATÜ C A. ECËÈ ÏPOÈCXOÄÈT BÛXOÄ
//          ÏO OØÈÁKE, TO CTOËÁÖÛ U, COOTBETCTBÓÞÙÈE ÈHÄEKCAM
//          BEPHÛX CÈHÃÓËßPHÛX ×ÈCEË, ÄOËÆHÛ ÁÛTÜ TAKÆE BEPHÛ.

//     V    COÄEPÆÈT MATPÈÖÓ V (OPTOÃOHAËÜHÓÞ) ÈÇ PAÇËOÆEHÈß,
//          ECËÈ ÄËß ÏAPAMETPA MATV ÁÛËO ÇAÄAHO ÇHA×EHÈE
//          true B ÏPOTÈBHOM CËÓ×AE HA V HE ÏPOÈÇBOÄÈTCß
//          CCÛËOK. V TAKÆE MOÆET COBÏAÄATÜ C  A, ECËÈ U HE
//          BÛ×ÈCËßETCß. ECËÈ ÏPOÈCXOÄÈT BÛXOÄ ÏO OØÈÁKE,
//          TO CTOËÁÖÛ V, COOTBETCTBÓÞÙÈE ÈHÄEKCAM BEPHÛX
//          CÈHÃÓËßPHÛX ×ÈCEË, ÄOËÆHÛ ÁÛTÜ TAKÆE BEPHÛ.

//     IERR PABHO
//            0,  ECËÈ ÏPOÈCXOÄÈT HOPMAËÜHÛÉ BÛXOÄ ÈÇ ÏOÄÏPOÃ-
//                PAMMÛ,
//            K,  ECËÈ K-E CÈHÃÓËßPHOE ×ÈCËO HE ÁÛËO OÏPEÄE-
//                ËEHO ÏOCËE 30 ÈTEPAÖÈÉ.

//     RV1  ÝTO MACCÈB ÏPOMEÆÓTO×HOÃO XPAHEHÈß.

//     BOÏPOCÛ È KOMMEHTAPÈÈ HÓÆHO HAÏPABËßTÜ ÏO AÄPECÓ
//     B.S.GARBOW, APPLIED MATEMATICS DIVISION, ARGONNE
//     NATIONAL LABORATORY

//     ÏOÄÏPOÃPAMMA MOÄÈÔÈÖÈPOBAHA C ÖEËÜÞ ÈCKËÞ×ÈTÜ
//     ÏEPEMEHHYÞ MACHEP

IERR=0;
for( I=1; I<=M; I++){   //? target=100
for( J=1; J<=N; J++){   //? target=100
U[I-1][J-1]=A[I-1][J-1];
//_100:;
}
}                         	// CONTINUE

//     XAÓCXOËÄEPOBO ÏPÈBEÄEHÈE K ÄBÓXÄÈAÃOHAËÜHOÉ ÔOPME

G=0.0;
SCALE=0.0;
ANORM=0.0;

for( I=1; I<=N; I++){   //? target=300
L=I+1;
RV1[I-1]=SCALE*G;
G=0.0;
S=0.0;
SCALE=0.0;
if(I>M)goto _210;

for( K=I; K<=M; K++)SCALE=SCALE+ABS(U[K-1][I-1]);
if(SCALE==0.0)goto _210;

for( K=I; K<=M; K++){   //? target=130
U[K-1][I-1]=U[K-1][I-1]/SCALE;
S=S+U[K-1][I-1]*U[K-1][I-1];
//_130:;
}                         	// CONTINUE

F=U[I-1][I-1];
G=-SIGN(SQRT(S),F);
H=F*G-S;
U[I-1][I-1]=F-G;
if(I==N)goto _190;

for( J=L; J<=N; J++){   //? target=150
S=0.0;
for( K=I; K<=M; K++)S=S+U[K-1][I-1]*U[K-1][J-1];
F=S/H;
for( K=I; K<=M; K++){   //? target=150
U[K-1][J-1]=U[K-1][J-1]+F*U[K-1][I-1];
//_150:;
}
}                         	// CONTINUE

_190:;
for( K=I; K<=M; K++)U[K-1][I-1]=SCALE*U[K-1][I-1];
_210:;
W[I-1]=SCALE*G;
G=0.0;
S=0.0;
SCALE=0.0;
if(I>M||I==N)goto _290;

for( K=L; K<=N; K++)SCALE=SCALE+ABS(U[I-1][K-1]);

if(SCALE==0.0)goto _290;

for( K=L; K<=N; K++){   //? target=230
U[I-1][K-1]=U[I-1][K-1]/SCALE;
S=S+U[I-1][K-1]*U[I-1][K-1];
//_230:;
}                         	// CONTINUE

F=U[I-1][L-1];
G=-SIGN(SQRT(S),F);
H=F*G-S;
U[I-1][L-1]=F-G;

for( K=L; K<=N; K++)RV1[K-1]=U[I-1][K-1]/H;

if(I==M)goto _270;

for( J=L; J<=M; J++){   //? target=260
S=0.0;
for( K=L; K<=N; K++)S=S+U[J-1][K-1]*U[I-1][K-1];
for( K=L; K<=N; K++){   //? target=260
U[J-1][K-1]=U[J-1][K-1]+S*RV1[K-1];
//_260:;
}
}                         	// CONTINUE

_270:;
for( K=L; K<=N; K++)U[I-1][K-1]=SCALE*U[I-1][K-1];

_290:;
ANORM=MAX(ANORM,ABS(W[I-1])+ABS(RV1[I-1]));
//_300:;
}                         	// CONTINUE

//     HAKOÏËEHÈE ÏPABOCTOPOHHÈX ÏPEOÁPAÇOBAHÈÉ

if(!MATV)goto _410;

//     ÄËß I=N C ØAÃOM -1 ÄO 1 BÛÏOËHÈTÜ -

for( II=1; II<=N; II++){   //? target=400
I=N+1-II;
if(I==N)goto _390;
if(G==0.0)goto _360;

for( J=L; J<=N; J++){   //? target=320

//     ÄBOÉHOE ÄEËEHÈE OÁXOÄÈT BOÇMOÆHÛÉ MAØÈHHÛÉ HYËÜ

//_320:;
V[J-1][I-1]=(U[I-1][J-1]/U[I-1][L-1])/G;
}

for( J=L; J<=N; J++){   //? target=350
S=0.0;
for( K=L; K<=N; K++)S=S+U[I-1][K-1]*V[K-1][J-1];
for( K=L; K<=N; K++){   //? target=350
V[K-1][J-1]=V[K-1][J-1]+S*V[K-1][I-1];
//_350:;
}
}                         	// CONTINUE

_360:;
for( J=L; J<=N; J++){   //? target=380
V[I-1][J-1]=0.0;
V[J-1][I-1]=0.0;
//_380:;
}                         	// CONTINUE

_390:;
V[I-1][I-1]=1.0;
G=RV1[I-1];
L=I;
//_400:;
}                         	// CONTINUE

//     HAKOÏËEHÈE ËEBOCTOPOHHÈX ÏPEOÁPAÇOBAHÈÉ

_410:;
if(!MATU)goto _510;

//     ÄËß I=MIN(N,M) C ØAÃOM -1 ÄO 1 BÛÏOËHÈTÜ-

MN=N;
if(M<N)MN=M;

for( II=1; II<=MN; II++){   //? target=500
I=MN+1-II;
L=I+1;
G=W[I-1];
if(I==N)goto _430;

for( J=L; J<=N; J++)U[I-1][J-1]=0.0;

_430:;
if(G==0.0)goto _475;
if(I==MN)goto _460;

for( J=L; J<=N; J++){   //? target=450
S=0.0;
for( K=L; K<=M; K++)S=S+U[K-1][I-1]*U[K-1][J-1];

//     ÄBOÉHOE  ÄEËEHÈE OÁXOÄÈT BOÇMOÆHÛÉ MAØÈHHÛÉ HYËÜ

F=(S/U[I-1][I-1])/G;

for( K=I; K<=M; K++){   //? target=450
U[K-1][J-1]=U[K-1][J-1]+F*U[K-1][I-1];
//_450:;
}
}                         	// CONTINUE
_460:;
for( J=I; J<=M; J++)U[J-1][I-1]=U[J-1][I-1]/G;

goto _490;

_475:;
for( J=I; J<=M; J++)U[J-1][I-1]=0.0;

_490:;
U[I-1][I-1]=U[I-1][I-1]+1.0;
//_500:;
}                         	// CONTINUE

//     ÄÈAÃOHAËÈÇAÖÈß ÄBÓXÄÈAÃOHAËÜHOÉ ÔOPMÛ ÄËß K=N C ØAÃOM
//     -1 ÄO 1 BÛÏOËHÈTÜ

_510:;
for( KK=1; KK<=N; KK++){   //? target=700
K1=N-KK;
K=K1+1;
ITS=0;

//     ÏPOBEPKA BOÇMOÆHOCTÈ PACÙEÏËEHÈß  ÄËß L=K
//     C ØAÃOM -1 ÄO 1 BÛÏOËHÈTÜ

_520:;
for( LL=1; LL<=K; LL++){   //? target=530
L1=K-LL;
L=L1+1;
if(ABS(RV1[L-1])+ANORM==ANORM)goto _565;

//     RV1[0] BCEÃÄA PABHO HÓËÞ. ÏOÝTOMÓ BÛXOÄA
//     ×EPEÇ KOHEÖ ÖÈKËA HE ÁÓÄET

if(ABS(W[L1-1])+ANORM==ANORM)goto _540;
//_530:;
}                         	// CONTINUE

//      ECËÈ L ÁOËÜØE, ×EM 1, TO RV1[L-1]
//      ÏPÈCBAÈBAETCß HÓËEBOE ÇHA×EHÈE

_540:;
C=0.0;
S=1.0;

for( I=L; I<=K; I++){   //? target=560
F=S*RV1[I-1];
RV1[I-1]=C*RV1[I-1];
if(ABS(F)+ANORM==ANORM)goto _565;
G=W[I-1];
H=SQRT(F*F+G*G);
W[I-1]=H;
C=G/H;
S=-F/H;
if(!MATU)goto _560;

for( J=1; J<=M; J++){   //? target=550
Y=U[J-1][L1-1];
Z=U[J-1][I-1];
U[J-1][L1-1]=Y*C+Z*S;
U[J-1][I-1]=-Y*S+Z*C;
//_550:;
}                         	// CONTINUE
_560:;
}                         	// CONTINUE

//     ÏPOBEPKA CXOÄÈMOCTÈ

_565:;
Z=W[K-1];
if(L==K)goto _650;

//     CÄBÈÃ BÛÁÈPAETCß ÈÇ HÈÆHEÃO ÓÃËOBOÃO
//     MÈHOPA ÏOPßÄKA 2

if(ITS==30)goto _1000;
ITS=ITS+1;
X=W[L-1];
Y=W[K1-1];
G=RV1[K1-1];
H=RV1[K-1];
F=((Y-Z)*(Y+Z)+(G-H)*(G+H))/(2.0*H*Y);
G=SQRT(F*F+1.0);
F=((X-Z)*(X+Z)+H*(Y/(F+SIGN(G,F))-H))/X;

//     CËEÄÓÞÙEE QR-ÏPEOÁPAÇOBAHÈE

C=1.0;
S=1.0;

for( I1=L; I1<=K1; I1++){   //? target=600
I=I1+1;
G=RV1[I-1];
Y=W[I-1];
H=S*G;
G=C*G;
Z=SQRT(F*F+H*H);
RV1[I1-1]=Z;
C=F/Z;
S=H/Z;
F=X*C+G*S;
G=-X*S+G*C;
H=Y*S;
Y=Y*C;
if(!MATV)goto _575;

for( J=1; J<=N; J++){   //? target=570
X=V[J-1][I1-1];
Z=V[J-1][I-1];
V[J-1][I1-1]=X*C+Z*S;
V[J-1][I-1]=-X*S+Z*C;
//_570:;
}                         	// CONTINUE

_575:;
Z=SQRT(F*F+H*H);
W[I1-1]=Z;

//     BPAÙEHÈE MOÆET ÁÛTÜ ÏPOÈÇBOËÜHÛM, ECËÈ Z PABHO HÓËÞ

if(Z==0.0)goto _580;
C=F/Z;
S=H/Z;
_580:;
F=C*G+S*Y;
X=-S*G+C*Y;
if(!MATU)goto _600;

for( J=1; J<=M; J++){   //? target=590
Y=U[J-1][I1-1];
Z=U[J-1][I-1];
U[J-1][I1-1]=Y*C+Z*S;
U[J-1][I-1]=-Y*S+Z*C;
//_590:;
}                         	// CONTINUE
_600:;
}                         	// CONTINUE
RV1[L-1]=0.0;
RV1[K-1]=F;
W[K-1]=X;
goto _520;

//     CXOÄÈMOCTÜ

_650:;
if(Z>=0.0)goto _700;

//     W[K-1] ÄEËAETCß HEOTPÈÖATEËÜHÛM

W[K-1]=-Z;
if(!MATV)goto _700;

for( J=1; J<=N; J++)V[J-1][K-1]=-V[J-1][K-1];
_700:;
}                         	// CONTINUE
goto _1001;

//     ÓCTAHOBÈTÜ ÇHA×EHÈE ÏPÈÇHAKA OØÈÁKÈ - ÏOCËE 30
//     ÈTEPAÖÈÉ HET CXOMOCTÈ K CÈHÃÓËßPHOMÓ ×ÈCËÓ

_1000:;
IERR=K;
_1001:;
return;
}                         	// END
