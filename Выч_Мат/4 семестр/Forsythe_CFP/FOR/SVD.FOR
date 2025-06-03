      SUBROUTINE SVD(NM,M,N,A,W,MATU,U,MATV,V,IERR,RV1)
C
      INTEGER I,J,K,L,M,N,II,I1,KK,K1,LL,L1,MN,NM,ITS,IERR
      REAL A(NM,N),W(N),U(NM,N),V(NM,N),RV1(N)
C
      REAL C,F,G,H,S,X,Y,Z,SCALE,ANORM
      LOGICAL MATU,MATV
C
C     TA O„POƒPAMMA ECTœ TPAHC‹Ÿ–ˆŸ A‹ƒO‹-PO–E„“P› SVD,
C     O“‹ˆKOBAHHO‰ ƒO‹“OM ˆ PA‰H˜EM B †“PHA‹E NUMERISCHE
C     MATHEMATIK, 14, 403-420(1970), A TAK†E B KHˆƒE
C     HANDBOOK FOR AUTOMATIC COMPUTATION  VOL.II-LINEAR
C     ALGEBRA, 134-151 (1971).
C
C     TA O„POƒPAMMA B›—ˆC‹ŸET CˆHƒ“‹ŸPHOE PA‡‹O†EHˆE
C          T
C     A=USV  „E‰CTBˆTE‹œHO‰ PŸMO“ƒO‹œHO‰ MATPˆ–› A C PA‡ME-
C     PAMˆ M ˆ N. Pˆ TOM ˆCO‹œ‡“žTCŸ „B“X„ˆAƒOHA‹ˆ‡A–ˆŸ
C     OCPE„CTBOM XA“CXO‹„EPOB›X OTPA†EHˆ‰  ˆ BAPˆAHT
C     QR-A‹ƒOPˆTMA.
C
C     HA BXO„E.
C
C     NM   C‹E„“ET O‹O†ˆTœ PABH›M CTPO—HO‰ PA‡MEPHOCTˆ
C          „B“XMEPH›X MACCˆBOB ,‡AŸB‹EHHO‰ B OEPATOPE PA‡-
C          MEPHOCTˆ B›‡›BAž™E‰ POƒPAMM›. ‡AMETˆM, —TO NM
C          „O‹†HO ›Tœ H  MEHœ˜E,—EM MAKCˆM“M ˆ‡ M ˆ N.
C
C     M    —ˆC‹O CTPOK A (ˆ U).
C
C     N    —ˆC‹O CTO‹–OB A (ˆ U) ˆ OPŸ„OK V.
C
C     A    CO„EP†ˆT PŸMO“ƒO‹œH“ž BXO„H“ž MATPˆ–“, „‹Ÿ
C          KOTOPO‰ HAXO„ˆTCŸ  PA‡‹O†EHˆE.
C
C     MATU „O‹†EH ˆMETœ ‡HA—EHˆE .TRUE., EC‹ˆ H“†HO
C          B›—ˆC‹ŸTœ MATPˆ–“ U ˆ‡ PA‡‹O†EHˆŸ, ˆ ‡HA—EHˆE
C          .FALSE. B POTˆBHOM C‹“—AE.
C
C     MATV „O‹†EH ˆMETœ ‡HA—EHˆE .TRUE., EC‹ˆ H“†HO
C          B›—ˆC‹ŸTœ MATPˆ–“ V ˆ‡ PA‡‹O†EHˆŸ, ˆ ‡HA—EHˆE
C          .FALSE. B POTˆBHOM C‹“—AE.
C
C     HA B›XO„E.
C
C     A    HE ˆ‡MEHŸETCŸ (EC‹ˆ HA EE MECTE HE ‡AˆC›BAžTCŸ
C          U ‹ˆO V).
C
C     W    CO„EP†ˆT N (HEOTPˆ–ATE‹œH›X) CˆHƒ“‹ŸPH›X —ˆCE‹
C          A („ˆAƒOHA‹œH›X ‹EMEHTOB S). OHˆ HE “OPŸ„O—EH›.
C          EC‹ˆ POˆCXO„ˆT B›XO„ O O˜ˆKE, TO „‹Ÿ ‡HA—EHˆ‰
C          IERR+1, IERR+2,...,N CˆHƒ“ ‹ŸPH›E —ˆC‹A „O‹†H›
C          ›Tœ BEPH›.
C
C     U    CO„EP†ˆT MATPˆ–“ U (C OPTOƒOHA‹œH›Mˆ CTO‹–AMˆ)
C          ˆ‡ PA‡‹O†EHˆŸ, EC‹ˆ „‹Ÿ APAMETPA MATU ›‹O
C          ‡A„AHO ‡HA—EHˆE .TRUE. B POTˆBHOM C‹“—AE HA U
C          ˆCO‹œ‡“ETCŸ KAK BPEMEHH›‰ MACCˆB. U TAK†E MO†ET
C          COBA„ATœ C A. EC‹ˆ POˆCXO„ˆT B›XO„
C          O O˜ˆKE, TO CTO‹–› U, COOTBETCTB“ž™ˆE ˆH„EKCAM
C          BEPH›X CˆHƒ“‹ŸPH›X —ˆCE‹, „O‹†H› ›Tœ TAK†E BEPH›.
C
C     V    CO„EP†ˆT MATPˆ–“ V (OPTOƒOHA‹œH“ž) ˆ‡ PA‡‹O†EHˆŸ,
C          EC‹ˆ „‹Ÿ APAMETPA MATV ›‹O ‡A„AHO ‡HA—EHˆE
C          .TRUE. B POTˆBHOM C‹“—AE HA V HE POˆ‡BO„ˆTCŸ
C          CC›‹OK. V TAK†E MO†ET COBA„ATœ C  A, EC‹ˆ U HE
C          B›—ˆC‹ŸETCŸ. EC‹ˆ POˆCXO„ˆT B›XO„ O O˜ˆKE,
C          TO CTO‹–› V, COOTBETCTB“ž™ˆE ˆH„EKCAM BEPH›X
C          CˆHƒ“‹ŸPH›X —ˆCE‹, „O‹†H› ›Tœ TAK†E BEPH›.
C
C     IERR PABHO
C            0,  EC‹ˆ POˆCXO„ˆT HOPMA‹œH›‰ B›XO„ ˆ‡ O„POƒ-
C                PAMM›,
C            K,  EC‹ˆ K-E CˆHƒ“‹ŸPHOE —ˆC‹O HE ›‹O OPE„E-
C                ‹EHO OC‹E 30 ˆTEPA–ˆ‰.
C
C     RV1  TO MACCˆB POME†“TO—HOƒO XPAHEHˆŸ.
C
C     BOPOC› ˆ KOMMEHTAPˆˆ H“†HO HAPAB‹ŸTœ O A„PEC“
C     B.S.GARBOW, APPLIED MATEMATICS DIVISION, ARGONNE
C     NATIONAL LABORATORY
C
C     O„POƒPAMMA MO„ˆ”ˆ–ˆPOBAHA C –E‹œž ˆCK‹ž—ˆTœ
C     EPEMEHHYž MACHEP
C
      IERR=0
      DO 100 I=1,M
      DO 100 J=1,N
      U(I,J)=A(I,J)
  100 CONTINUE
C
C     XA“CXO‹„EPOBO PˆBE„EHˆE K „B“X„ˆAƒOHA‹œHO‰ ”OPME
C
      G=0.0
      SCALE=0.0
      ANORM=0.0
C
      DO 300 I=1,N
         L=I+1
         RV1(I)=SCALE*G
         G=0.0
         S=0.0
         SCALE=0.0
         IF(I.GT.M)GO TO 210
C
         DO 120 K=I,M
  120       SCALE=SCALE+ABS(U(K,I))
         IF(SCALE.EQ.0.0)GO TO 210
C
         DO 130 K=I,M
            U(K,I)=U(K,I)/SCALE
            S=S+U(K,I)**2
  130    CONTINUE
C
         F=U(I,I)
         G=-SIGN(SQRT(S),F)
         H=F*G-S
         U(I,I)=F-G
         IF(I.EQ.N)GO TO 190
C
         DO 150 J=L,N
            S=0.0
            DO 140 K=I,M
  140          S=S+U(K,I)*U(K,J)
               F=S/H
            DO 150 K=I,M
               U(K,J)=U(K,J)+F*U(K,I)
  150    CONTINUE
C
  190    DO 200 K=I,M
  200       U(K,I)=SCALE*U(K,I)
  210    W(I)=SCALE*G
         G=0.0
         S=0.0
         SCALE=0.0
         IF(I.GT.M.OR.I.EQ.N)GO TO 290
C
         DO 220 K=L,N
  220       SCALE=SCALE+ABS(U(I,K))
C
         IF(SCALE.EQ.0.0)GO TO 290
C
         DO 230 K=L,N
            U(I,K)=U(I,K)/SCALE
            S=S+U(I,K)**2
  230    CONTINUE
C
         F=U(I,L)
         G=-SIGN(SQRT(S),F)
         H=F*G-S
         U(I,L)=F-G
C
         DO 240 K=L,N
  240       RV1(K)=U(I,K)/H
C
         IF(I.EQ.M)GO TO 270
C
         DO 260 J=L,M
            S=0.0
            DO 250 K=L,N
  250          S=S+U(J,K)*U(I,K)
            DO 260 K=L,N
               U(J,K)=U(J,K)+S*RV1(K)
  260    CONTINUE
C
  270    DO 280 K=L,N
  280    U(I,K)=SCALE*U(I,K)
C
  290    ANORM=AMAX1(ANORM,ABS(W(I))+ABS(RV1(I)))
  300 CONTINUE
C
C     HAKO‹EHˆE PABOCTOPOHHˆX PEOPA‡OBAHˆ‰
C
      IF(.NOT.MATV)GO TO 410
C
C     „‹Ÿ I=N C ˜AƒOM -1 „O 1 B›O‹HˆTœ -
C
      DO 400 II=1,N
         I=N+1-II
         IF(I.EQ.N)GO TO 390
         IF(G.EQ.0.0)GO TO 360
C
         DO 320 J=L,N
C
C     „BO‰HOE „E‹EHˆE OXO„ˆT BO‡MO†H›‰ MA˜ˆHH›‰ HY‹œ
C
  320    V(J,I)=(U(I,J)/U(I,L))/G
C
         DO 350 J=L,N
            S=0.0
            DO 340 K=L,N
  340       S=S+U(I,K)*V(K,J)
            DO 350 K=L,N
            V(K,J)=V(K,J)+S*V(K,I)
  350 CONTINUE
C
  360    DO 380 J=L,N
            V(I,J)=0.0
            V(J,I)=0.0
  380    CONTINUE
C
  390    V(I,I)=1.0
         G=RV1(I)
         L=I
  400 CONTINUE
C
C     HAKO‹EHˆE ‹EBOCTOPOHHˆX PEOPA‡OBAHˆ‰
C
  410 IF(.NOT.MATU)GO TO 510
C
C     „‹Ÿ I=MIN(N,M) C ˜AƒOM -1 „O 1 B›O‹HˆTœ-
C
      MN=N
      IF(M.LT.N)MN=M
C
      DO 500 II=1,MN
         I=MN+1-II
         L=I+1
         G=W(I)
         IF(I.EQ.N)GO TO 430
C
         DO 420 J=L,N
  420    U(I,J)=0.0
C
  430    IF(G.EQ.0.0)GO TO 475
         IF(I.EQ.MN)GO TO 460
C
         DO 450 J=L,N
            S=0.0
            DO 440 K=L,M
  440       S=S+U(K,I)*U(K,J)
C
C     „BO‰HOE  „E‹EHˆE OXO„ˆT BO‡MO†H›‰ MA˜ˆHH›‰ HY‹œ
C
            F=(S/U(I,I))/G
C
            DO 450 K=I,M
               U(K,J)=U(K,J)+F*U(K,I)
  450    CONTINUE
                                                                                                                                                                                                                                                               
  460    DO 470 J=I,M
  470    U(J,I)=U(J,I)/G
C
         GO TO 490
C
  475    DO 480 J=I,M
  480    U(J,I)=0.0
C
  490    U(I,I)=U(I,I)+1.0
  500 CONTINUE
C
C     „ˆAƒOHA‹ˆ‡A–ˆŸ „B“X„ˆAƒOHA‹œHO‰ ”OPM› „‹Ÿ K=N C ˜AƒOM
C     -1 „O 1 B›O‹HˆTœ
C
  510 DO 700 KK=1,N
         K1=N-KK
         K=K1+1
         ITS=0
C
C     POBEPKA BO‡MO†HOCTˆ PAC™E‹EHˆŸ  „‹Ÿ L=K
C     C ˜AƒOM -1 „O 1 B›O‹HˆTœ
C
  520    DO 530 LL=1,K
            L1=K-LL
            L=L1+1
            IF(ABS(RV1(L))+ANORM.EQ.ANORM)GO TO 565
C
C     RV1(1) BCEƒ„A PABHO H“‹ž. OTOM“ B›XO„A
C     —EPE‡ KOHE– –ˆK‹A HE “„ET
C
            IF(ABS(W(L1))+ANORM.EQ.ANORM)GO TO 540
  530    CONTINUE
C
C      EC‹ˆ L O‹œ˜E, —EM 1, TO RV1(L)
C      PˆCBAˆBAETCŸ H“‹EBOE ‡HA—EHˆE
C
  540    C=0.0
         S=1.0
C
         DO 560 I=L,K
            F=S*RV1(I)
            RV1(I)=C*RV1(I)
            IF(ABS(F)+ANORM.EQ.ANORM)GO TO 565
            G=W(I)
            H=SQRT(F*F+G*G)
            W(I)=H
            C=G/H
            S=-F/H
            IF(.NOT.MATU)GO TO 560
C
            DO 550 J=1,M
               Y=U(J,L1)
               Z=U(J,I)
               U(J,L1)=Y*C+Z*S
               U(J,I)=-Y*S+Z*C
  550       CONTINUE
  560    CONTINUE
C
C     POBEPKA CXO„ˆMOCTˆ
C
  565    Z=W(K)
         IF(L.EQ.K)GO TO 650
C
C     C„Bˆƒ B›ˆPAETCŸ ˆ‡ Hˆ†HEƒO “ƒ‹OBOƒO
C     MˆHOPA OPŸ„KA 2
C
         IF(ITS.EQ.30)GO TO 1000
         ITS=ITS+1
         X=W(L)
         Y=W(K1)
         G=RV1(K1)
         H=RV1(K)
         F=((Y-Z)*(Y+Z)+(G-H)*(G+H))/(2.0*H*Y)
         G=SQRT(F*F+1.0)
         F=((X-Z)*(X+Z)+H*(Y/(F+SIGN(G,F))-H))/X
C
C     C‹E„“ž™EE QR-PEOPA‡OBAHˆE
C
         C=1.0
         S=1.0
C
         DO 600 I1=L,K1
            I=I1+1
            G=RV1(I)
            Y=W(I)
            H=S*G
            G=C*G
            Z=SQRT(F*F+H*H)
            RV1(I1)=Z
            C=F/Z
            S=H/Z
            F=X*C+G*S
            G=-X*S+G*C
            H=Y*S
            Y=Y*C
            IF(.NOT.MATV)GO TO 575
C
            DO 570 J=1,N
               X=V(J,I1)
               Z=V(J,I)
               V(J,I1)=X*C+Z*S
               V(J,I)=-X*S+Z*C
  570       CONTINUE
C
  575       Z=SQRT(F*F+H*H)
            W(I1)=Z
C
C     BPA™EHˆE MO†ET ›Tœ POˆ‡BO‹œH›M, EC‹ˆ Z PABHO H“‹ž
C
            IF(Z.EQ.0.0)GO TO 580
            C=F/Z
            S=H/Z
  580       F=C*G+S*Y
            X=-S*G+C*Y
            IF(.NOT.MATU)GO TO 600
C
            DO 590 J=1,M
               Y=U(J,I1)
               Z=U(J,I)
               U(J,I1)=Y*C+Z*S
               U(J,I)=-Y*S+Z*C
  590       CONTINUE
  600    CONTINUE
         RV1(L)=0.0
         RV1(K)=F
         W(K)=X
         GO TO 520
C
C     CXO„ˆMOCTœ
C
  650    IF(Z.GE.0.0)GO TO 700
C
C     W(K) „E‹AETCŸ HEOTPˆ–ATE‹œH›M
C
         W(K)=-Z
         IF(.NOT.MATV)GO TO 700
C
         DO 690 J=1,N
  690    V(J,K)=-V(J,K)
  700 CONTINUE
      GO TO 1001
C
C     “CTAHOBˆTœ ‡HA—EHˆE Pˆ‡HAKA O˜ˆKˆ - OC‹E 30
C     ˆTEPA–ˆ‰ HET CXOMOCTˆ K CˆHƒ“‹ŸPHOM“ —ˆC‹“
C
 1000 IERR=K
 1001 RETURN
      END
