      SUBROUTINE SOLVE(NDIM,N,A,B,IPVT)
C
      INTEGER NDIM,N,IPVT(N)
      REAL A(NDIM,N),B(N)
C
C     PE˜EHˆE ‹ˆHE‰HO‰ CˆCTEM› A*X=B
C     O„POƒPAMMY HE C‹E„YET ˆCO‹œ‡OBATœ,
C     EC‹ˆ DECOMP OHAPY†ˆ‹ B›PO†„EHHOCTœ
C
C     BXO„HAŸ ˆH”OPMA–ˆŸ.
C
C     NDIM -‡AŸB‹EHHAŸ CTPO—HAŸ PA‡MEPHOCTœ
C           MACCˆBA,CO„EP†A™EƒO A.
C     N    -OPŸ„OK MATPˆ–›.
C     A    -”AKTOPˆ‡OBAHHAŸ MATPˆ–A,O‹Y—EHHAŸ ˆ‡ DECOMP
C     B    -BEKTOP PAB›X —ACTE‰.
C     IPVT -BEKTOP BE„Y™ˆX ‹EMEHTOB,O‹Y—EHH›‰ ˆ‡ DECOMP
C
C     B›XO„HAŸ ˆH”OPMA–ˆŸ.
C
C     B    =BEKTOP PE˜EHˆŸ X.
C
      INTEGER KB,KM1,NM1,KP1,I,K,M
      REAL T
C
C     PŸMO‰ XO„
C
      IF(N.EQ.1) GO TO 50
      NM1=N-1
      DO 20 K=1,NM1
        KP1=K+1
        M=IPVT(K)
        T=B(M)
        B(M)=B(K)
        B(K)=T
        DO 10 I=KP1,N
          B(I)=B(I)+A(I,K)*T
   10   CONTINUE
   20 CONTINUE
C
C     OPATHAŸ O„CTAHOBKA
C
      DO 40 KB=1,NM1
        KM1=N-KB
        K=KM1+1
        B(K)=B(K)/A(K,K)
        T=-B(K)
        DO 30 I=1,KM1
          B(I)=B(I)+A(I,K)*T
   30   CONTINUE
   40 CONTINUE
   50 B(1)=B(1)/A(1,1)
      RETURN
      END
