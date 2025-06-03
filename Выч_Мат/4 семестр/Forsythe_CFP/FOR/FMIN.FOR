      REAL FUNCTION FMIN(AX,BX,F,TOL)
      REAL AX,BX,F,TOL
C
C     B›—ˆC‹ŸET Pˆ‹ˆ†EHˆE X K TO—KE, ƒ„E F „OCTˆƒAET
C     MˆHˆM“MA HA ˆHTEPBA‹E (AX,BX)
C
C     BXO„HAŸ ˆH”OPMA–ˆŸ.
C
C     AX   ‹EB›‰ KOHE– ˆCXO„HOƒO ˆHTEPBA‹A
C     BX   PAB›‰ KOHE– ˆCXO„HOƒO ˆHTEPBA‹A
C     F    O„POƒPAMMA-”“HK–ˆŸ, KOTOPAŸ B›—ˆC‹ŸET F(X)
C          „‹Ÿ ‹žOƒO X B ˆHTEPBA‹E (AX,BX)
C    TOL   †E‹AEMAŸ „‹ˆHA ˆHTEPBA‹A HEOPE„E‹EHHOCTˆ
C          KOHE—HOƒO PE‡“‹œTATA (.GE.0.0)
C
C    B›XO„HAŸ ˆH”OPMA–ˆŸ.
C
C    FMIN  AC–ˆCCA, APOKCˆMˆP“ž™AŸ TO—K“,
C          ƒ„E F „OCTˆƒAET MˆHˆM“MA
C
C       METO„ ˆCO‹œ‡“ET KOMˆHA–ˆž OˆCKA ‡O‹OTOƒO CE—EHˆŸ
C    ˆ OC‹E„OBATE‹œHO‰ APAO‹ˆ—ECKO‰ ˆHTEPO‹Ÿ–ˆˆ. CXO„ˆ-
C    MOCTœ HˆKOƒ„A HE ›BAET ‡HA—ˆTE‹œHO X“†E, —EM „‹Ÿ
C    OˆCKA ”ˆOHA——ˆ. EC‹ˆ F ˆMEET HEPEP›BH“ž BTOP“ž
C    POˆ‡BO„H“ž, O‹O†ˆTE‹œH“ž B TO—KE MˆHˆM“MA (HE
C    COBA„Až™E‰ Hˆ C AX,Hˆ C BX), TO CXO„ˆMOCTœ CBEPX-
C    ‹ˆHE‰HAŸ ˆ O›—HO ˆMEET OPŸ„OK PˆMEPHO 1.324...
C       ”“HK–ˆŸ F HˆKOƒ„A HE B›—ˆC‹ŸETCŸ B „B“X TO—KAX,
C    OTCTOŸ™ˆX „P“ƒ OT „P“ƒA MEHEE —EM HA EPS*ABS(X)+(TOL/3),
C    ƒ„E EPS Pˆ‹ˆ‡ˆTE‹œHO PABHO KBA„PATHOM“ KOPHž ˆ‡
C    OTHOCˆTE‹œHO‰ MA˜ˆHHO‰ TO—HOCTˆ. EC‹ˆ F-“HˆMO„A‹œHAŸ
C    ”“HK–ˆŸ ˆ B›—ˆC‹EHH›E ‡HA—EHˆŸ F COXPAHŸžT “HˆMO„A‹œ-
C    HOCTœ Pˆ CO‹ž„EHˆˆ “KA‡AHHOƒO “C‹OBˆŸ PA‡„E‹EHHOCTˆ,
C    TO FMIN APOKCˆMˆP“ET AC–ˆCC“ ƒ‹OA‹œHOƒO MˆHˆM“MA F
C    HA ˆHTEPBA‹E (AX,BX) C O˜ˆKO‰, MEHœ˜E‰ 3*EPS*ABS(X)+TOL.
C    EC‹ˆ F HE ŸB‹ŸETCŸ “HˆMO„A‹œHO‰, TO FMIN MO†ET C TO‰ †E
C    TO—HOCTœž APOKCˆMˆPOBATœ ‹OKA‹œH›‰ MˆHˆM“M, BO‡MO†HO,
C    HE COBA„Až™ˆ‰ C ƒ‹OA‹œH›M.
C       TA O„POƒPAMMA-”“HK–ˆŸ ŸB‹ŸETCŸ C‹EƒKA MO„ˆ”ˆ–ˆPO-
C    BAHHO‰ BEPCˆE‰ A‹ƒO‹ 60-PO–E„“P› LOCALMIN, PˆBE„EHHO‰
C    B KHˆƒE RICARD BRENT, ALGORITHMS FOR MINIMIZATION
C    WITHOUT DERIVATIVES, PRENTICE-HALL, INC.(1973).
C
      REAL A,B,C,D,E,EPS,XM,P,Q,R,TOL1,TOL2,U,V,W
      REAL FU,FV,FW,FX,X,ABS,SIGN
C
C     C ECTœ BO‡BE„EHHAŸ B KBA„PAT BE‹ˆ—ˆHA,
C     OPATHAŸ K ‡O‹OTOM“ CE—EHˆž
C
      C=0.5*(3.0-SQRT(5.0))
C
C     EPS Pˆ‹ˆ‡ˆTE‹œHO PABHO KBA„PATHOM“ KOPHž ˆ‡
C     OTHOCˆTE‹œHO‰ MA˜ˆHHO‰ TO—HOCTˆ
C
      EPS=1.0
   10 EPS=EPS/2.0
      TOL1=1.0+EPS
      IF(TOL1.GT.1.0) GO TO 10
      EPS=SQRT(EPS)
C
C     PˆCBOEHˆE HA—A‹œH›X ‡HA—EHˆ‰
C
      A=AX
      B=BX
      V=A+C*(B-A)
      W=V
      X=V
      E=0.0
      FX=F(X)
      FV=FX
      FW=FX
C
C     ‡„ECœ HA—ˆHAETCŸ OCHOBHO‰ –ˆK‹
C
   20 XM=0.5*(A+B)
      TOL1=EPS*ABS(X)+TOL/3.0
      TOL2=2.0*TOL1
C
C     POBEPˆTœ KPˆTEPˆ‰ OKOH—AHˆŸ
C
      IF(ABS(X-XM).LE.(TOL2-0.5*(B-A))) GO TO 90
C
C     HEOXO„ˆMO ‹ˆ ‡O‹OTOE CE—EHˆE
C
      IF(ABS(E).LE.TOL1) GO TO 40
C
C     OCTPOˆTœ APAO‹“
C
      R=(X-W)*(FX-FV)
      Q=(X-V)*(FX-FW)
      P=(X-V)*Q-(X-W)*R
      Q=2.0*(Q-R)
      IF(Q.GT.0.0) P=-P
      Q=ABS(Q)
      R=E
      E=D
C
C     PˆEM‹EMA ‹ˆ APAO‹A
C
   30 IF(ABS(P).GE.ABS(0.5*Q*R)) GO TO 40
      IF(P.LE.Q*(A-X)) GO TO 40
      IF(P.GE.Q*(B-X)) GO TO 40
C
C     ˜Aƒ APAO‹ˆ—ECKO‰ ˆHTEPO‹Ÿ–ˆˆ
C
      D=P/Q
      U=X+D
C
C     F HE C‹E„“ET B›—ˆC‹ŸTœ C‹ˆ˜KOM ‹ˆ‡KO K AX ˆ‹ˆ BX
C
      IF((U-A).LT.TOL2) D=SIGN(TOL1,XM-X)
      IF((B-U).LT.TOL2) D=SIGN(TOL1,XM-X)
      GO TO 50
C
C     ˜Aƒ ‡O‹OTOƒO CE—EHˆŸ
C
   40 IF(X.GE.XM) E=A-X
      IF(X.LT.XM)E=B-X
      D=C*E
C
C     F HE C‹E„“ET B›—ˆC‹ŸTœ C‹ˆ˜KOM ‹ˆ‡KO K X
C
   50 IF(ABS(D).GE.TOL1) U=X+D
      IF(ABS(D).LT.TOL1) U=X+SIGN(TOL1,D)
      FU=F(U)
C
C     PˆCBOˆTœ HOB›E ‡HA—EHˆŸ APAMETPAM A,B,V,W ˆ X
C
      IF(FU.GT.FX) GO TO 60
      IF(U.GE.X) A=X
      IF(U.LT.X) B=X
      V=W
      FV=FW
      W=X
      FW=FX
      X=U
      FX=FU
      GO TO 20
C
   60 IF(U.LT.X) A=U
      IF(U.GE.X) B=U
      IF(FU.LE.FW) GO TO 70
      IF(W.EQ.X) GO TO 70
      IF(FU.LE.FV) GO TO 80
      IF(V.EQ.X) GO TO 80
      IF(V.EQ.W) GO TO 80
      GO TO 20
C
   70 V=W
      FV=FW
      W=U
      FW=FU
      GO TO 20
C
   80 V=U
      FV=FU
      GO TO 20
C
C     KOHE– OCHOBHOƒO –ˆK‹A
C
   90 FMIN=X
      RETURN
      END
