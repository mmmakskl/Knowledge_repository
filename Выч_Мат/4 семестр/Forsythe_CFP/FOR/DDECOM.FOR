      SUBROUTINE DECOMP(NDIM,N,A,COND,IPVT,WORK)
C
      INTEGER NDIM,N
      REAL*8 A(NDIM,N),COND,WORK(N)
      INTEGER IPVT(N)
C
C     POƒPAMMA B›—ˆC‹ŸET PA‡‹O†EHˆE BE™ECTBEHHO‰ MATPˆ–›
C     OCPE„CTBOM ƒA“CCOBA ˆCK‹ž—EHˆŸ ˆ O–EHˆBAET
C     O“C‹OB‹EHHOCTœ  MATPˆ–›.
C
C     OHA ˆCO‹œ‡“ETCŸ „‹Ÿ B›—ˆC‹EHˆŸ PE˜EHˆ‰
C     ‹ˆHE‰H›X CˆCTEM.
C
C     BXO„HAŸ ˆH”OPMA–ˆŸ.
C
C     NDIM -‡AŸB‹EHHAŸ CTPO—HAŸ PA‡MEPHOCTœ MACCˆBA,
C           CO„EP†A™EƒO A.
C
C     N    -OPŸ„OK MATPˆ–›.
C
C     A    -MATPˆ–A,KOTOP“ž H“†HO PA‡‹O†ˆTœ.
C
C     B›XO„HAŸ ˆH”OPMA–ˆŸ.
C
C     A     CO„EP†ˆT BEPXHžž TPE“ƒO‹œH“ž MATPˆ–“ U
C           ˆ “—ˆT›BAž™“ž EPECTAHOBKˆ BEPCˆž
C           Hˆ†HE‰ TPE“ƒO‹œHO‰ MATPˆ–› I-L,TAKˆE,
C           —TO (MATPˆ–A  EPECTAHOBOK) *A=L*U
C
C     COND -O–EHKA O“C‹OB‹EHHOCTˆ A.
C           „‹Ÿ ‹ˆHE‰HO‰ CˆCTEM› A*X=B ˆ‡MEHEHˆŸ B A ˆ B
C           MOƒ“T B›‡BATœ  ˆ‡MEHEHˆŸ B X,O‹œ˜ˆE B COND PA‡.
C           EC‹ˆ COND+1.0.EQ.COND, TO  A B PE„E‹AX MA˜ˆHHO‰
C           TO—HOCTˆ ŸB‹ŸETCŸ B›PO†„EHHO‰ MATPˆ–E‰. COND
C           O‹AƒAETCŸ PABH›M 1.0E+32,EC‹ˆ OHAP“†EHA TO—HAŸ
C           B›PO†„EHHOCTœ.
C
C     IPVT -BEKTOP BE„“™ˆX ‹EMEHTOB.
C           IPVT(K)=ˆH„EKC K-‰ BE„“™E‰ CTPOKˆ
C           IPVT(N)=(-1)**(—ˆC‹O EPECTAHOBOK)
C
C     PAO—EE O‹E. BEKTOP WORK „O‹†EH ›Tœ OˆCAH ˆ
C             BK‹ž—EH B B›‡OB. EƒO BXO„HOE CO„EP†AHˆE O›—HO
C             HE „AET BA†HO‰ ˆH”OPMA–ˆˆ.
C
C     OPE„E‹ˆTE‹œ MATPˆ–› A MO†ET ›Tœ O‹“—EH HA B›XO„E
C     O ”OPM“‹E:
C          DET(A)=IPVT(N)*A(1,1)*A(2,2)*...*A(N,N).
C
      REAL*8 EK,T,ANORM,YNORM,ZNORM
      INTEGER NM1,I,J,K,KP1,KB,KM1,M
C
      IPVT(N)=1
      IF(N.EQ.1)GO TO 80
      NM1=N-1
C
C     B›—ˆC‹ˆTœ 1-HOPM“ MATPˆ–› A
C
      ANORM=0.0D+00
      DO 10 J=1,N
        T=0.0D+00
        DO 5 I=1,N
          T=T+DABS(A(I,J))
    5   CONTINUE
        IF(T.GT.ANORM) ANORM=T
   10 CONTINUE
C
C     ƒA“CCOBO ˆCK‹ž—EHˆE C —ACTˆ—H›M B›OPOM
C     BE„“™EƒO ‹EMEHTA
C
      DO 35 K=1,NM1
        KP1=K+1
C
C       HA‰Tˆ BE„“™ˆ‰ ‹EMEHT
C
        M=K
        DO 15 I=KP1,N
          IF(DABS(A(I,K)).GT.DABS(A(M,K))) M=I
   15   CONTINUE
        IPVT(K)=M
        IF(M.NE.K)IPVT(N)=-IPVT(N)
        T=A(M,K)
        A(M,K)=A(K,K)
        A(K,K)=T
C
C       PO“CTˆTœ TOT ˜Aƒ,EC‹ˆ BE„“™ˆ‰ ‹EMEHT PABEH H“‹ž
C
        IF(T.EQ.0.0D+00)GO TO 35
C
C       B›—ˆC‹ˆTœ MHO†ˆTE‹ˆ
C
        DO 20 I=KP1,N
          A(I,K)=-A(I,K)/T
   20   CONTINUE
C
C       EPECTAB‹ŸTœ ˆ ˆCK‹ž—ATœ O CTO‹–AM
C
        DO 30 J=KP1,N
          T=A(M,J)
          A(M,J)=A(K,J)
          A(K,J)=T
          IF(T.EQ.0.0D+00)GO TO 30
          DO 25 I=KP1,N
            A(I,J)=A(I,J)+A(I,K)*T
   25     CONTINUE
   30   CONTINUE
   35 CONTINUE
C
C     COND=(1-HOPMA MATPˆ–› A)*(O–EHKA „‹Ÿ 1-HOPM› MATPˆ–›,
C     OPATHO‰ K A)
C     O–EHKA O‹“—AETCŸ OCPE„CTBOM O„HOƒO ˜AƒA METO„A
C     OPATH›X ˆTEPA–ˆ‰ „‹Ÿ HAˆMEHœ˜EƒO CˆHƒ“‹ŸPHOƒO
C     BEKTOPA. TO TPE“ET PE˜EHˆŸ „B“X CˆCTEM “PABHEHˆ‰,
C     (TPAHCOHˆPOBAHHAŸ „‹Ÿ A) *Y=E ˆ A*Z=Y, ƒ„E E-BEKTOP
C     ˆ‡ +1 ˆ -1, B›PAHH›‰ TAK, —TO› MAKCˆMˆ‡ˆPOBATœ
C     BE‹ˆ—ˆH“ Y.
C     ESTIMATE=(1-HOPMA Z)/(1-HOPMA Y)
C
C     PE˜ˆTœ CˆCTEM“ (TPAHCOHˆPOBAHHAŸ „‹Ÿ A)*Y=E
C
      DO 50 K=1,N
        T=0.0D+00
        IF(K.EQ.1)GO TO 45
        KM1=K-1
        DO 40 I=1,KM1
          T=T+A(I,K)*WORK(I)
   40   CONTINUE
   45   EK=1.0D+00
        IF(T.LT.0.0D+00) EK=-1.0D+00
        IF(A(K,K).EQ.0.0D+00)GO TO 90
        WORK(K)=-(EK+T)/A(K,K)
   50 CONTINUE
      DO 60 KB=1,NM1
        K=N-KB
        T=WORK(K)
        KP1=K+1
        DO 55 I=KP1,N
          T=T+A(I,K)*WORK(I)
   55   CONTINUE
        WORK(K)=T
        M=IPVT(K)
        IF(M.EQ.K)GO TO 60
        T=WORK(M)
        WORK(M)=WORK(K)
        WORK(K)=T
   60 CONTINUE
C
      YNORM=0.0D+00
      DO 65 I=1,N
        YNORM=YNORM+DABS(WORK(I))
   65 CONTINUE
C
C     PE˜ˆTœ CˆCTEM“ A*Z=Y
C
      CALL DSOLVE(NDIM,N,A,WORK,IPVT)
C
      ZNORM=0.0D+00
      DO 70 I=1,N
        ZNORM=ZNORM+DABS(WORK(I))
   70 CONTINUE
C
C     O–EHˆTœ O“C‹OB‹EHHOCTœ
C
      COND=ANORM*ZNORM/YNORM
      IF(COND.LT.1.0D+00) COND=1.0D+00
      RETURN
C
C     C‹“—A‰ MATPˆ–› 1*1
C
   80 COND=1.0D+00
      IF(A(1,1).NE.0.0D+00)RETURN
C
C     TO—HAŸ B›PO†„EHHOCTœ
C
   90 CONTINUE
      COND=1.0D+64
      RETURN
      END
