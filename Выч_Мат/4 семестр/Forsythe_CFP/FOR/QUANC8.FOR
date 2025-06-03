      SUBROUTINE QUANC8(FUN,A,B,ABSERR,RELERR,RESULT,
     *                  ERREST,NOFUN,FLAG)
C
      REAL FUN,A,B,ABSERR,RELERR,RESULT,ERREST,FLAG
      INTEGER NOFUN
C
C     O–EHˆTœ ˆHTEƒPA‹ „‹Ÿ FUN(X) OT A „O B C ‡A„AHHO‰
C     O‹œ‡OBATE‹EM TO—HOCTœž
C     ABTOMATˆ—ECKAŸ A„ATˆBHAŸ POƒPAMMA, OCHOBAHHAŸ HA
C     ”OPM“‹E HœžTOHA-KOTE–A 8-OƒO OPŸ„KA
C
C     BXO„HAŸ ˆH”OPMA–ˆŸ
C
C    FUN    -ˆMŸ BHE˜HE‰ ”“HK–ˆˆ,PEA‹ˆ‡“ž™E‰
C            B›—ˆC‹EHˆE O„ˆHTEƒPA‹œHO‰ ”“HK–ˆˆ
C
C    A      -Hˆ†Hˆ‰  PE„E‹ ˆHTEƒPˆPOBAHˆŸ
C
C    B      -BEPXHˆ‰ PE„E‹ ˆHTEƒPˆPOBAHˆŸ (B MO†ET
C            ›Tœ MEHœ˜E, —EM  A)
C
C    RELERR -OTHOCˆTE‹œHAŸ †E‹AEMAŸ OƒPE˜HOCTœ
C
C    ABSERR -ACO‹žTHAŸ †E‹AEMAŸ  OƒPE˜HOCTœ
C
C    B›XO„HAŸ ˆH”OPMA–ˆŸ
C
C    RESULT -Pˆ‹ˆ†EHHOE ‡HA—EHˆE ˆHTEƒPA‹A
C
C    ERREST -O–EHKA BE‹ˆ—ˆH› „E‰CTBˆTE‹œHO‰ O˜ˆKˆ
C
C    NOFUN  -—ˆC‹O ‡HA—EHˆ‰ ”“HK–ˆˆ,ˆCO‹œ‡OBAHH›X
C            Pˆ B›—ˆC‹EHˆˆ ˆHTEƒPA‹A.
C
C    FLAG   -ˆH„ˆKATOP HA„E†HOCTˆ. EC‹ˆ FLAG PABEH H“‹ž,
C            TO RESULT “„OB‹ETBOPŸET ‡A„AHHO‰ ƒPAHˆ–E
C            OƒPE˜HOCTˆ. EC‹ˆ FLAG=XXX.YYY, TO  XXX-—ˆC‹O
C            ˆHTEPBA‹OB „‹Ÿ KOTOP›X HE ›‹O CXO„ˆMOCTˆ,
C            A 0.YYY-„O‹Ÿ OCHOBHOƒO ˆHTEPBA‹A, OCTAB˜AŸCŸ
C            „‹Ÿ OPAOTKˆ B TOT MOMEHT,KOƒ„A O„POƒPAMMA
C            Pˆ‹ˆ‡ˆ‹ACœ K PE„E‹œHOM“ —ˆC‹“ „‹Ÿ NOFUN.
C
      REAL W0,W1,W2,W3,W4,AREA,X0,F0,STONE,STEP,COR11,TEMP
      REAL QPREV,QNOW,QDIFF,QLEFT,ESTERR,TOLERR
      REAL QRIGHT(31),F(16),X(16),FSAVE(8,30),XSAVE(8,30)
C
C     *** TA1 *** PˆCBOEHˆE HA—A‹œH›X ‡HA—EHˆ‰
C     EPEMEHH›M, HE ‡ABˆCŸ™ˆM OT ˆHTEPBA‹A.
C     ƒEHEPˆPOBAHˆE KOHCTAHT.
C
      INTEGER LEVMIN,LEVMAX,LEVOUT,NOMAX,NOFIN,LEV,NIM,I,J
      LEVMIN=1
      LEVMAX=30
      LEVOUT=6
      NOMAX=5000
      NOFIN=NOMAX-8*(LEVMAX-LEVOUT+2**(LEVOUT+1))
C
C     EC‹ˆ NOFUN „OCTˆƒAET ‡HA—EHˆŸ NOFIN, TO TPEBOƒA
C
      W0=3956.0/14175.0
      W1=23552.0/14175.0
      W2=-3712.0/14175.0
      W3=41984.0/14175.0
      W4=-18160.0/14175.0
C
C     PˆCBOˆTœ H“‹EB›E ‡HA—EHˆŸ EPEMEHH›M C“MMAM
C
      FLAG=0.0
      RESULT=0.0
      COR11=0.0
      ERREST=0.0
      AREA=0.0
      NOFUN=0
      IF(A.EQ.B)RETURN
C
C     *** TA 2 *** PˆCBOEHˆE HA—A‹œH›X ‡HA—EHˆ‰
C     EPEMEHH›M, ‡ABˆCŸ™ˆM OT ˆHTEPBA‹A, B
C     COOTBETCTBˆˆ C EPB›M ˆHTEPBA‹OM
C
      LEV=0
      NIM=1
      X0=A
      X(16)=B
      QPREV=0.0
      F0=FUN(X0)
      STONE=(B-A)/16.0
      X(8)=(X0+X(16))/2.0
      X(4)=(X0+X(8))/2.0
      X(12)=(X(8)+X(16))/2.0
      X(2)=(X0+X(4))/2.0
      X(6)=(X(4)+X(8))/2.0
      X(10)=(X(8)+X(12))/2.0
      X(14)=(X(12)+X(16))/2.0
      DO 25 J=2,16,2
      F(J)=FUN(X(J))
   25 CONTINUE
      NOFUN=9
C
C     *** TA 3 *** OCHOBH›E B›—ˆC‹EHˆŸ
C     TPE“žTCŸ QPREV, X0, X2, X4,...,X16, F0, F2, F4,...
C     ,F16. B›—ˆC‹ŸžTCŸ X1, X3,...,X15, F1, F3,...,F15,
C     QLEFT,QRIGHT,QNOW,QDIF,AREA
C
   30 X(1)=(X0+X(2))/2.0
      F(1)=FUN(X(1))
      DO 35 J=3,15,2
      X(J)=(X(J-1)+X(J+1))/2.0
      F(J)=FUN(X(J))
   35 CONTINUE
      NOFUN=NOFUN+8
      STEP=(X(16)-X0)/16.0
      QLEFT=(W0*(F0+F(8))+W1*(F(1)+F(7))+W2*
     *      (F(2)+F(6))+W3*(F(3)+F(5))+W4*F(4))*STEP
      QRIGHT(LEV+1)=(W0*(F(8)+F(16))+W1*(F(9)+F(15))+
     *       W2*(F(10)+F(14))+W3*(F(11)+F(13))+W4*F(12))*STEP
      QNOW=QLEFT+QRIGHT(LEV+1)
      QDIFF=QNOW-QPREV
      AREA=AREA+QDIFF
C
C     *** TA 4 *** POBEPKA CXO„ˆMOCTˆ „‹Ÿ ˆHTEPBA‹A
C
      ESTERR=ABS(QDIFF)/1023.0
      TOLERR=AMAX1(ABSERR,RELERR*ABS(AREA))*(STEP/STONE)
      IF(LEV.LT.LEVMIN)GO TO 50
      IF(LEV.GE.LEVMAX)GO TO 62
      IF(NOFUN.GT.NOFIN)GO TO 60
      IF(ESTERR.LE.TOLERR)GO TO 70
C
C     *** TA 5 *** CXO„ˆMOCTˆ HET.
C     “CTAHOBˆTœ C‹E„“ž™ˆ‰ ˆHTEPBA‹
C
   50 NIM=2*NIM
      LEV=LEV+1
C
C     ‡AOMHˆTœ ‹EMEHT›, OTHOCŸ™ˆECŸ K PABO‰ O‹OBˆHE
C     ˆHTEPBA‹A, „‹Ÿ “„“™EƒO ˆCO‹œ‡OBAHˆŸ.
C
      DO 52 I=1,8
      FSAVE(I,LEV)=F(I+8)
      XSAVE(I,LEV)=X(I+8)
   52 CONTINUE
C
C     COPATœ ‹EMEHT›, OTHOCŸ™ˆECŸ K ‹EBO‰ O‹OBˆHE
C     ˆHTEPBA‹A „‹Ÿ HEME„‹EHHOƒO ˆCO‹œ‡OBAHˆŸ
C
      QPREV=QLEFT
      DO 55 I=1,8
      J=-I
      F(2*J+18)=F(J+9)
      X(2*J+18)=X(J+9)
   55 CONTINUE
      GO TO 30
C
C     *** TA 6 *** "O†APH›‰" PA‡„E‹
C     —ˆC‹O ‡HA—EHˆ‰ ”“HK–ˆˆ ‹ˆ‡KO K TOM“, —TO›
C     PEB›CˆTœ “CTAHOB‹EHH›‰ PE„E‹.
C
   60 NOFIN=2*NOFIN
      LEVMAX=LEVOUT
      FLAG=FLAG+(B-X0)/(B-A)
      GO TO 70
C
C     TEK“™EE PE„E‹œHOE ‡HA—EHˆE ƒ‹“ˆH› „E‹EHˆŸ
C     OO‹AM PABHO LEVMAX
C
   62 FLAG=FLAG+1.0
C
C     *** TA 7 *** CXO„ˆMOCTœ „‹Ÿ ˆHTEPBA‹A ˆMEET MECTO
C     PˆABˆTœ O—EPE„H›E C‹AƒAEM›E K EPEMEHH›M C“MMAM.
C
   70 RESULT=RESULT+QNOW
      ERREST=ERREST+ESTERR
      COR11=COR11+QDIFF/1023.0
C
C     “CTAHOBˆTœ C‹E„“ž™ˆ‰ ˆHTEPBA‹.
C
   72 IF(NIM.EQ.2*(NIM/2))GO TO 75
      NIM=NIM/2
      LEV=LEV-1
      GO TO 72
   75 NIM=NIM+1
      IF(LEV.LE.0)GO TO 80
C
C     COPATœ ‹EMEHT›, HEOXO„ˆM›E „‹Ÿ C‹E„“ž™EƒO ˆHTEBA‹A
C
      QPREV=QRIGHT(LEV)
      X0=X(16)
      F0=F(16)
      DO 78 I=1,8
      F(2*I)=FSAVE(I,LEV)
      X(2*I)=XSAVE(I,LEV)
   78 CONTINUE
      GO TO 30
C
C     *** TA 8 *** ‡AK‹ž—ˆTE‹œH›E OEPA–ˆˆ ˆ B›XO„
C
   80 RESULT=RESULT+COR11
C
C     OECE—ˆTœ, —TO› ‡HA—EHˆE EPEMEHHO‰ ERREST
C     ›‹O HE MEHœ˜E “POBHŸ OKP“ƒ‹EHˆ‰
C
      IF(ERREST.EQ.0.0)RETURN
   82 TEMP=ABS(RESULT)+ERREST
      IF(TEMP.NE.ABS(RESULT))RETURN
      ERREST=2.0*ERREST
      GO TO 82
      END
