     REAL FUNCTION ZEROIN(AX,BX,F,TOL)
      REAL AX,BX,F,TOL
C
C     H“‹œ ”“HK–ˆˆ F(X) B›—ˆC‹ŸETCŸ B ˆHTEPBA‹E AX,BX
C
C     BXO„HAŸ ˆH”OPMA–ˆŸ..
C
C     AX     ‹EB›‰ KOHE– ˆCXO„HOƒO ˆHTEPBA‹A
C     BX     PAB›‰ KOHE– ˆCXO„HOƒO ˆHTEPBA‹A
C     F      O„POƒPAMMA-”“HK–ˆŸ, KOTOPAŸ B›—ˆC‹ŸET F(X)
C            „‹Ÿ ‹žOƒO X B ˆHTEPBA‹E AX BX
C     TOL    †E‹AEMAŸ „‹ˆHA ˆHTEPBA‹A HEOPE„E‹EHHOCTˆ
C            KOHE—HOƒO PE‡“‹œTATA
C
C     B›XO„HAŸ ˆH”OPMA–ˆŸ...
C
C     ZEROIN AC–ˆCCA, APOKCˆMˆP“ž™AŸ H“‹œ ”“HK–ˆˆ F B
C            ˆHTEPBA‹E AX, BX
C
C        E‡ POBEPKˆ PE„O‹AƒAETCŸ, —TO F(AX) ˆ F(BX) ˆMEžT
C     POTˆBOO‹O†H›E ‡HAKˆ.
C        ZEROIN B›—ˆC‹ŸET H“‹œ X B ‡A„AHHOM ˆHTEPBA‹E AX, BX
C     B PE„E‹AX „O“CKA HA O˜ˆK“  4*MACHEPS*ABS(X) + TOL,
C     ƒ„E MACHEPS-OTHOCˆTE‹œHAŸ MA˜ˆHHAŸ TO—HOCTœ.
C        TA O„POƒPAMMA-”“HK–ˆŸ PE„CTAB‹ŸET COO‰ C‹EƒKA
C     MO„ˆ”ˆ–ˆPOBAHH“ž TPAHC‹Ÿ–ˆž A‹ƒO‹ 60-PO–E„“P› ZERO,
C     PˆBE„EHHO‰ B KHˆƒE RICHARD BRENT, ALGORITHMS FOR
C     MINIMIZATION WITHOUT DERIVATIVES,PRENTICE HALL,INC.(1973).
C
      REAL A,B,C,D,E,EPS,FA,FB,FC,TOL1,XM,P,Q,R,S
C
C     B›—ˆC‹ˆTœ EPS,OTHOCˆTE‹œH“ž MA˜ˆHH“ž TO—HOCTœ
C
      EPS=1.0
   10 EPS=EPS/2.0
      TOL1=1.0+EPS
      IF(TOL1.GT.1.0) GO TO 10
C
C     PˆCBOEHˆE HA—A‹œH›X ‡HA—EHˆ‰
C
      A=AX
      B=BX
      FA=F(A)
      FB=F(B)
C
C     HA—ATœ ˜Aƒ
C
   20 C=A
      FC=FA
      D=B-A
      E=D
   30 IF(ABS(FC).GE.ABS(FB)) GO TO 40
      A=B
      B=C
      C=A
      FA=FB
      FB=FC
      FC=FA
C
C     POBEPKA CXO„ˆMOCTˆ
C
   40 TOL1=2.0*EPS*ABS(B)+0.5*TOL
      XM=0.5*(C-B)
      IF(ABS(XM).LE.TOL1) GO TO 90
C
C     HEOXO„ˆMA ‹ˆ ˆCEK–ˆŸ
C
      IF(FB.EQ.0.0) GO TO 90
      IF(ABS(E).LT.TOL1) GO TO 70
      IF(ABS(FA).LE.ABS(FB)) GO TO 70
C
C     BO‡MO†HA ‹ˆ KBA„PATˆ—HAŸ ˆHTEPO‹Ÿ–ˆŸ
C
      IF(A.NE.C)GO TO 50
C
C     ‹ˆHE‰HAŸ ˆHTEPO‹Ÿ–ˆŸ
C
      S=FB/FA
      P=2.0*XM*S
      Q=1.0-S
      GO TO 60
C
C     OPATHAŸ KBA„PATˆ—HAŸ ˆHTEPO‹Ÿ–ˆŸ
C
   50 Q=FA/FC
      R=FB/FC
      S=FB/FA
       P=S*(2.0*XM*Q*(Q-R)-(B-A)*(R-1.0))
      Q=(Q-1.0)*(R-1.0)*(S-1.0)
C
C     B›PATœ ‡HAKˆ
C
   60 IF(P.GT.0.0) Q=-Q
      P=ABS(P)
C
C     PˆEM‹EMA ‹ˆ ˆHTEPO‹Ÿ–ˆŸ
C
      IF((2.0*P).GE.(3.0*XM*Q-ABS(TOL1*Q))) GO TO 70
      IF(P.GE.ABS(0.5*E*Q)) GO TO 70
      E=D
      D=P/Q
      GO TO 80
C
C     ˆCEK–ˆŸ
C
   70 D=XM
      E=D
C
C     ‡ABEP˜ˆTœ ˜Aƒ
C
   80 A=B
      FA=FB
      IF(ABS(D).GT.TOL1) B=B+D
      IF(ABS(D).LE.TOL1) B=B+SIGN(TOL1,XM)
      FB=F(B)
      IF((FB*(FC/ABS(FC))).GT.0.0) GO TO 20
      GO TO 30
C
C     KOH—EHO
C
   90 ZEROIN=B
      RETURN
      END
