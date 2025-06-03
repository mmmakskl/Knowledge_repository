        SUBROUTINE SPLINE(N,X,Y,B,C,D)
        INTEGER N
        REAL X(N),Y(N),B(N),C(N),D(N)
C
C     B›—ˆC‹ŸžTCŸ KO””ˆ–ˆEHT› B(I),C(I) ˆ D(I),I=1,
C     2,...,N, „‹Ÿ K“ˆ—ECKOƒO ˆHTEPO‹Ÿ–ˆOHHOƒO
C     C‹A‰HA
C
C       S(X)=Y(I)+B(I)*(X-X(I))+C(I)*(X-X(I))**2+
C       +D(I)*(X-X(I))**3
C       „‹Ÿ X(I).LE.X.LE.X(I+1)
C
C     BXO„HAŸ ˆH”OPMA–ˆŸ.
C
C       N     =—ˆC‹O ‡A„AHH›X TO—EK ˆ‹ˆ “‡‹OB(N.GE.2)
C       X     =AC–ˆCC› “‡‹OB B CTPOƒO BO‡PACTAž™EM
C              OPŸ„KE
C       Y     =OP„ˆHAT› “‡‹OB
C
C     B›XO„HAŸ ˆH”OPMA–ˆŸ.
C
C       B,C,D =MACCˆB› OPE„E‹EHH›X B›˜E KO””ˆ-
C             –ˆEHTOB C‹A‰HA.
C
C     EC‹ˆ OO‡HA—ˆTœ —EPE‡ P CˆMBO‹ „ˆ””EPEH–ˆP0-
C     BAHˆŸ,TO
C
C       Y(I)=S(X(I))
C       B(I)=SP(X(I))
C       C(I)=SPP(X(I))/2
C       D(I)=SPPP(X(I))/6 (PABOCTOPOHŸŸ POˆ‡BO„HAŸ)
C
C     C OMO™œž COPOBO†„Až™E‰ O„POƒPAMM›-”“HK-
C     –ˆˆ SEVAL MO†HO B›—ˆC‹ŸTœ ‡HA—EHˆŸ C‹A‰HA.
C
        INTEGER NM1,IB,I
        REAL T
C
        NM1=N-1
        IF(N.LT.2) RETURN
        IF(N.LT.3) GO TO 50
C
C     OCTPOˆTœ TPEX„ˆAƒOHA‹œH“ž CˆCTEM“
C
C     B=„ˆAƒOHA‹œ,D=HA„„ˆAƒOHA‹œ,C=PAB›E —ACTˆ.
C
        D(1)=X(2)-X(1)
        C(2)=(Y(2)-Y(1))/D(1)
        DO 10 I=2,NM1
           D(I)=X(I+1)-X(I)
           B(I)=2.*(D(I-1)+D(I))
           C(I+1)=(Y(I+1)-Y(I))/D(I)
           C(I)=C(I+1)-C(I)
 10     CONTINUE
C     ƒPAHˆ—H›E “C‹OBˆŸ.TPETœˆ POˆ‡BO„H›E B TO—KAX
C     X(1) ˆ X(N) B›—ˆC‹ŸžTCŸ C OMO™œž PA‡„E‹EHH›X
C     PA‡HOCTE‰
C
        B(1)=-D(1)
        B(N)=-D(N-1)
        C(1)=0.
        C(N)=0.
        IF(N.EQ.3) GO TO 15
        C(1)=C(3)/(X(4)-X(2))-C(2)/(X(3)-X(1))
        C(N)=C(N-1)/(X(N)-X(N-2))-C(N-2)/(X(N-1)-X(N-3))
        C(1)=C(1)*D(1)**2/(X(4)-X(1))
        C(N)=-C(N)*D(N-1)**2/(X(N)-X(N-3))
C
C     PŸMO‰ XO„
C
 15     DO 20 I=2,N
           T=D(I-1)/B(I-1)
           B(I)=B(I)-T*D(I-1)
           C(I)=C(I)-T*C(I-1)
 20     CONTINUE
C
C     OPATHAŸ O„CTAHOBKA
C
        C(N)=C(N)/B(N)
        DO 30 IB=1,NM1
           I=N-IB
           C(I)=(C(I)-D(I)*C(I+1))/B(I)
 30     CONTINUE
C
C     B C(I) TEEPœ XPAHˆTCŸ BE‹ˆ—ˆHA SIGMA(I),OPE„E‹EH-
C     HAŸ B  4.4
C
C     B›—ˆC‹ˆTœ KO””ˆ–ˆEHT› O‹ˆHOMOB
C
        B(N)=(Y(N)-Y(NM1))/D(NM1)+D(NM1)*(C(NM1)+2.*C(N))
        DO 40 I=1,NM1
           B(I)=(Y(I+1)-Y(I))/D(I)-D(I)*(C(I+1)+2.*C(I))
           D(I)=(C(I+1)-C(I))/D(I)
           C(I)=3.*C(I)
 40     CONTINUE
         C(N)=3.*C(N)
         D(N)=D(N-1)
         RETURN
C
 50     B(1)=(Y(2)-Y(1))/(X(2)-X(1))
        C(1)=0.
        D(1)=0.
        B(2)=B(1)
        C(2)=0.
        D(2)=0.
        RETURN
        END
