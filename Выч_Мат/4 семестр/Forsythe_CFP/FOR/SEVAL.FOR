      REAL FUNCTION SEVAL(N,U,X,Y,B,C,D)
      INTEGER N
      REAL U,X(N),Y(N),B(N),C(N),D(N)
C
C  TA O„POƒPAMMA B›—ˆC‹ŸET ‡HA—EHˆE K“ˆ—ECKOƒO
C  C‹A‰HA
C
C  SEVAL=Y(I)+B(I)*(U-X(I))+C(I)*(U-X(I))**2+
C             D(I)*(U-X(I))**3
C
C  ƒ„E X(I).LT.U.LT.X(I+1). ˆCO‹œ‡“ETCŸ CXEMA
C  ƒOPHEPA
C
C  EC‹ˆ U.LT.X(1), TO EPETCŸ ‡HA—EHˆE I=1.
C  EC‹ˆ U.GE.X(N), TO EPETCŸ ‡HA—EHˆE I=N.
C
C  BXO„HAŸ ˆH”OPMA–ˆŸ.
C
C     N     -—ˆC‹O ‡A„AHH›X TO—EK
C     U     -AC–ˆCCA, „‹Ÿ KOTOPO‰ B›—ˆC‹ŸETCŸ ‡HA—EHˆE
C            C‹A‰HA
C     X,Y   -MACCˆB› ‡A„AHH›X AC–ˆCC ˆ OP„ˆHAT
C     B,C,D -MACCˆB› KO””ˆ–ˆEHTOB C‹A‰HA, B›—ˆC‹EHH›E
C            O„POƒPAMMO‰ SPLINE
C
C  EC‹ˆ O CPABHEHˆž C PE„›„“™ˆM B›‡OBOM U HE
C  HAXO„ˆTCŸ B TOM †E ˆHTEPBA‹E, TO „‹Ÿ PA‡›CKAHˆŸ
C  H“†HOƒO ˆHTEPBA‹A PˆMEHŸETCŸ „BOˆ—H›‰ OˆCK.
C
      INTEGER I,J,K
      REAL DX
      DATA I/1/
      IF(I.GE.N) I=1
      IF(U.LT.X(I)) GO TO 10
      IF(U.LE.X(I+1)) GO TO 30
C
C  „BOˆ—H›‰ OˆCK
C
 10   I=1
      J=N+1
 20   K=(I+J)/2
      IF(U.LT.X(K))J=K
      IF(U.GE.X(K))I=K
      IF(J.GT.I+1)GO TO 20
C
C  B›—ˆC‹ˆTœ C‹A‰H
C
 30   DX=U-X(I)
      SEVAL=Y(I)+DX*(B(I)+DX*(C(I)+DX*D(I)))
      RETURN
      END
