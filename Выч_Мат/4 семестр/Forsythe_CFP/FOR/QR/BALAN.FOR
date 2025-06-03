      SUBROUTINE BALAN(NM,N,A,LOW,IGH,SCALE)
C
      INTEGER I,J,K,L,M,N,JJ,NM,IGH,LOW,IEXC
      REAL A(NM,N),SCALE(N)
      REAL C,F,G,R,S,B2,RADIX
      REAL ABS
      LOGICAL NOCONV
C
C     *******RADIX IS A MACHINE DEPENDED
C            PARAMETR SPECIFING THE BASE
C            OF THE MACHINE FLOATING POINT
C            REPRESENTATION.
C     *******
      RADIX=2.
      B2=RADIX*RADIX
      K=1
      L=N
      GO TO 100
C      *********IN-LINE PROCEDURE ROR RCN
C               AND COLUMN EXCEANCE******
   20 SCALE(M)=J
      IF(J.EQ.M) GO TO 50
C
      DO 30 I=1,L
      F=A(I,J)
      A(I,J)=A(I,M)
      A(I,M)=F
   30 CONTINUE
C
      DO 40 I=K,N
      F=A(J,I)
      A(J,I)=A(M,I)
      A(M,I)=F
   40 CONTINUE
C
   50 GO TO (80,130),IEXC
C     *********SEARCH FOR ROWS ISOLATING
C              AN EIGENVALUE AND PUSH THEM DOWN
   80 IF(L.EQ.1)GO TO 280
      L=L-1
C     ********FOR J=I STEP -1 UNTIL 1 DO  *****
  100 DO 120 JJ=1,L
      J=L+1-JJ
C
      DO 110 I=1,L
      IF(I.EQ.J)GO TO 110
      IF(A(J,I).NE.0.0)GO TO 120
  110 CONTINUE
C
      M=L
      IEXC=1
      GO TO 20
  120 CONTINUE
C
      GO TO 140
C     **********SEARCH FOR COLUMS ISOLATING
C               AN EIGENENVALUE AND PUSH THEM LEFT
C
  130 K=K+1
C
  140 DO 170 J=K,L
C
      DO 150 I=K,L
      IF(I.EQ.J)GO TO 150
      IF(A(I,J).NE.0.0)GO TO 170
  150 CONTINUE
C
       M=K
       IEXC=2
      GO TO 20
  170 CONTINUE
C      *****NOW BALANCE THE SUBMATRIX IN ROWS K TO L **
      DO 180 I=K,L
  180 SCALE(I)=1.0
C     *********ITERATIVE LOOP FOR NORM REDUCTION ******
  190 NOCONV=.FALSE.
C
      DO 270 I=K,L
      C=0.0
      R=0.0
C
      DO 200 J=K,L
      IF(J.EQ.I)GO TO 200
      C=C+ABS(A(J,I))
      R=R+ABS(A(I,J))
  200 CONTINUE
C
      G=R/RADIX
      F=1.0
      S=C+R
  210 IF(C.GE.G)GO TO 220
      F=F*RADIX
      C=C*B2
      GO TO 210
  220 G=R*RADIX
  230 IF(C.LT.G)GO TO 240
       F=F/RADIX
       C=C/B2
      GO TO 230
C       ******NOW BALANCE  *******
  240 IF((C+R)/F.GE.0.95*S)GO TO 270
      G=1./F
      SCALE(I)=SCALE(I)*F
      NOCONV=.TRUE.
C
      DO 250 J=K,N
  250 A(I,J)=A(I,J)*G
C
      DO 260 J=1,L
  260 A(J,I)=A(J,I)*F
  270 CONTINUE
C
      IF(NOCONV)GO TO 190
C
  280 LOW=K
      IGH=L
      RETURN
      END
