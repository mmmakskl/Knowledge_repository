      SUBROUTINE ELTRA(NM,N,LOW,IGH,A,INT,Z)
C
      INTEGER I,J,N,KL,MM,MP,NM,IGH,LOW,MP1
      REAL A(NM,IGH),Z(NM,N)
      INTEGER INT(IGH)
C
C     **********INITIALIZE Z TO IDENTITY MATRIX**********
      DO 80 I=1,N
C
      DO 60 J=1,N
   60 Z(I,J)=0.0
C
      Z(I,I)=1.0
   80 CONTINUE
C
      KL=IGH-LOW-1
      IF(KL.LT.1) GO TO 200
C     **********FOR MP=IGH-1 STEP -1 UNTIL LOW+1 DO --**********
      DO 140 MM=1,KL
      MP=IGH-MM
      MP1=MP+1
C
      DO 100 I=MP1,IGH
  100 Z(I,MP)=A(I,MP-1)
C
      I=INT(MP)
      IF(I.EQ.MP) GO TO 140
C
      DO 130 J=MP,IGH
      Z(MP,J)=Z(I,J)
      Z(I,J)=0.0
  130 CONTINUE
C
      Z(I,MP)=1.0
  140 CONTINUE
C
  200 RETURN
      END
