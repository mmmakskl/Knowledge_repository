      SUBROUTINE RKFS(F,NEQN,Y,T,TOUT,RELERR,ABSERR,IFLAG,
     *                YP,H,F1,F2,F3,F4,F5,SAVRE,SAVAE,
     *                NFE,KOP,INIT,JFLAG,KFLAG)
C
C     METO„ P“HƒE-K“TTA-”E‹œEPƒA —ETBEPTOƒO-ŸTOƒO OPŸ„KA
C     RKFS ˆHTEƒPˆP“ET CˆCTEM“ O›KHOBEHH›X „ˆ””E-
C     PEH–ˆA‹œH›X “PABHEHˆ‰ EPBOƒO OPŸ„KA(CM. KOM-
C     MEHTAPˆ‰ K RKF45). MACCˆB› YP,F1,F2,F3,F4 ˆ F5
C     (PA‡MEPHOCTˆ O KPA‰HE‰ MEPE NEQN) ˆ EPEMEH-
C     H›E H,SAVRE,SAVAE,NFE,KOP,INIT,JFLAG ˆ KFLAG
C     ˆCO‹œ‡“žTCŸ BH“TPˆ POƒPAMM› ˆ B›HECEH› B
C     CˆCOK B›‡OBA,—TO› COXPAHˆTœ ˆX OPE„E‹EH-
C     HOCTœ Pˆ OBTOPHOM OPA™EHˆˆ.OTOM“ ˆX ‡HA-
C     —EHˆŸ HE „O‹†H›  ˆ‡MEHŸTœCŸ  O‹œ‡OBATE‹EM.
C     BO‡MO†H›‰ ˆHTEPEC PE„CTAB‹ŸžT APAMETP›
C     YP  -POˆ‡BO„HAŸ BEKTOPA PE˜EHˆŸ B TO—KE T
C     H   -PE„O‹AƒAEM›‰ PA‡MEP ˜AƒA „‹Ÿ O—EPE„HOƒO TAA
C     NFE -C—ET—ˆK —ˆC‹A B›—ˆC‹EHˆ‰ ”“HK–ˆˆ
C
      LOGICAL HFAILD,OUTPUT
C
      INTEGER NEQN,IFLAG,NFE,KOP,INIT,JFLAG,KFLAG
      REAL Y(NEQN),T,TOUT,RELERR,ABSERR,H,YP(NEQN),
     *     F1(NEQN),F2(NEQN),F3(NEQN),F4(NEQN),F5(NEQN),
     *     SAVRE,SAVAE
C
C     EXTERNAL F
C
      REAL A,AE,DT,EE,EEOET,ESTTOL,ET,HMIN,REMIN,
     *     RER,S,SCAL,TOL,TOLN,U26,EPSP1,EPS,YPK
C
      INTEGER K,MAXNFE,MFLAG
C
      REAL AMAX1,AMIN1
C
C     REMIN-TO MˆHˆMA‹œHOE „O“CTˆMOE ‡HA—EHˆE „‹Ÿ
C     RELERR.O›TKˆ O‹“—ˆTœ O TO‰ O„POƒPAMME
C     O‹EE B›COK“ž TO—HOCTœ O›—HO CTOŸT O—EHœ
C     „OPOƒO ˆ ‡A—ACT“ž E‡“CE˜H›.
C
      DATA REMIN/1.E-12/
C
C     CTOˆMOCTœ C—ETA KOHTPO‹ˆP“ETCŸ TPEOBAHˆEM,
C     —TO› KO‹ˆ—ECTBO B›—ˆC‹EHˆ‰ ”“HK–ˆˆ ›‹O Oƒ-
C     PAHˆ—EHO BE‹ˆ—ˆHO‰,Pˆ‹ˆ‡ˆTE‹œHO PABHO‰ ‡HA-
C     —EHˆž APAMETPA MAXNFE.PˆHŸTOE ‡„ECœ ‡HA—E-
C     HˆE PˆMEPHO COOTBETCTB“ET 500 ˜AƒAM.
C
      DATA MAXNFE/3000/
C
C     POBEPˆTœ BXO„H›E APAMETP›
C
      IF(NEQN.LT.1)GO TO 10
      IF((RELERR.LT.0.0).OR.(ABSERR.LT.0.0))GO TO 10
      MFLAG=IABS(IFLAG)
      IF((MFLAG.EQ.0).OR.(MFLAG.GT.8))GO TO 10
      IF(MFLAG.NE.1)GO TO 20
C
C     EPB›‰ B›‡OB,B›—ˆC‹ˆTœ MA˜ˆHHOE Cˆ‹OH
C
      EPS=1.0
    5 EPS=EPS/2.0
      EPSP1=EPS+1.
      IF(EPSP1.GT.1.)GO TO 5
      U26=26.*EPS
      GO TO 50
C
C     O˜ˆKA BXO„HO‰ ˆH”OPMA–ˆˆ
C
   10 IFLAG=8
      RETURN
C
C     POBEPˆTœ BO‡MO†HOCTˆ PO„O‹†EHˆŸ
C
   20 IF((T.EQ.TOUT).AND.(KFLAG.NE.3))GO TO 10
      IF(MFLAG.NE.2)GO TO 25
C
C     IFLAG=+2 ˆ‹ˆ -2
C
      IF((KFLAG.EQ.3).OR.(INIT.EQ.0))GO TO 45
      IF(KFLAG.EQ.4)GO TO 40
      IF((KFLAG.EQ.5).AND.(ABSERR.EQ.0.0))GO TO 30
      IF((KFLAG.EQ.6).AND.(RELERR.LE.SAVRE).AND.
     *(ABSERR.LE.SAVAE))GO TO 30
      GO TO 50
C
C     IFLAG=3,4,5,6,7 ˆ‹ˆ 8
C
   25 IF(IFLAG.EQ.3)GO TO 45
      IF(IFLAG.EQ.4)GO TO 40
      IF((IFLAG.EQ.5).AND.(ABSERR.GT.0.0))GO TO 45
C
C     ˆHTEƒPˆPOBAHˆE HE‹œ‡Ÿ PO„O‹†ATœ,OCKO‹œK“ O‹œ-
C     ‡OBATE‹œ HE B›O‹Hˆ‹ ˆHCTP“K–ˆ‰,COOTBETCTB“ž™ˆX
C     ‡HA—EHˆŸM IFLAG=5,6,7 ˆ‹ˆ 8
C
   30 PRINT 35
   35 FORMAT(/20X,48HˆHTEƒPˆPOBAHˆE PEPBAHO, OCKO‹œK“ O‹œ‡OBATE‹œ ,
     *11HHE B›O‹Hˆ‹/20X,34HˆHCTP“K–ˆ‰ RKF45, COOTBETCTB“ž™ˆX ,
     *27H‡HA—EHˆŸM IFLAG=5,6,7 ˆ‹ˆ 8)
      STOP
C
C     EPEOPE„E‹ˆTœ C—ET—ˆK —ˆC‹A B›—ˆC‹EHˆ‰ ”“HK–ˆˆ
C
   40 NFE=0
      IF(MFLAG.EQ.2)GO TO 50
C
C     EPEOPE„E‹ˆTœ ‡HA—EHˆE FLAG,“CTAHOB‹EHHOE
C     Pˆ PE„›„“™EM OPA™EHˆˆ
C
   45 IFLAG=JFLAG
      IF(KFLAG.EQ.3)MFLAG=IABS(IFLAG)
C
C     COXPAHˆTœ BXO„HOE ‡HA—EHˆE IFLAG ˆ “CTAHOBˆTœ
C     ‡HA—EHˆE FLAG, COOTBETCTB“ž™EE PO„O‹†EHˆž,
C     „‹Ÿ “„“™E‰ POBEPKˆ
C
   50 JFLAG=IFLAG
      KFLAG=0
C
C     COXPAHˆTœ ‡HA—EHˆŸ RELERR ˆ ABSERR „‹Ÿ BXO„HO‰
C     POBEPKˆ Pˆ OC‹E„“ž™ˆX OPA™EHˆŸX
C
      SAVRE=RELERR
      SAVAE=ABSERR
C
C     “CTAHOBˆTœ ‡HA—EHˆE ƒPAHˆ–› „‹Ÿ OTHOCˆTE‹œ-
C     HO‰ OƒPE˜HOCTˆ,PABHOE KAK MˆHˆM“M 2*EPS+
C     REMIN,—TO› ˆ‡E†ATœ TP“„HOCTE‰,CBŸ‡AHH›X
C     C TPEOBAHˆEM HE„OCTˆ†ˆMO‰ TO—HOCTˆ
C
      RER=2.*EPS+REMIN
      IF(RELERR.GE.RER)GO TO 55
C
C     ‡A„AHHAŸ ƒPAHˆ–A OTHOCˆTE‹œHO‰ OƒPE˜HOCTˆ
C     C‹ˆ˜KOM MA‹A
C
      RELERR=RER
      IFLAG=3
      KFLAG=3
      RETURN
C
   55 DT=TOUT-T
C
      IF(MFLAG.EQ.1)GO TO 60
      IF(INIT.EQ.0)GO TO 65
      GO TO 80
C
C     PˆCBOEHˆE HA—A‹œH›X ‡HA—EHˆ‰ (ˆHˆ–ˆˆPOBA-
C             HˆE)-“CTAHOBˆTœ ‡HA—EHˆE “KA‡ATE‹Ÿ
C             OKOH—AHˆŸ ˆHˆ–ˆˆPOBAHˆŸ,INIT
C             “CTAHOBˆTœ ‡HA—EHˆE “KA‡ATE‹Ÿ C‹ˆ˜-
C             KOM O‹œ˜OƒO ‡ATPEOBAHHOƒO —ˆC‹A B›-
C             XO„H›X TO—EK,KOP
C             B›—ˆC‹ˆTœ HA—A‹œH›E POˆ‡BO„H›E
C             “CTAHOBˆTœ ‡HA—EHˆE C—ET—ˆKA —ˆC‹A
C             B›—ˆC‹EHˆ‰ ”“HK–ˆˆ,NFE
C             O–EHˆTœ HA—E‹œH“ž BE‹ˆ—ˆH“ ˜AƒA
C
   60 INIT=0
      KOP=0
C
      A=T
      CALL F(A,Y,YP)
      NFE=1
      IF(T.NE.TOUT)GO TO 65
      IFLAG=2
      RETURN
C
   65 INIT=1
      H=ABS(DT)
      TOLN=0.
      DO 70 K=1,NEQN
      TOL=RELERR*ABS(Y(K))+ABSERR
      IF(TOL.LE.0)GO TO 70
      TOLN=TOL
      YPK=ABS(YP(K))
      IF(YPK*H**5.GT.TOL)H=(TOL/YPK)**0.2
   70 CONTINUE
      IF(TOLN.LE.0.0)H=0.0
      H=AMAX1(H,U26*AMAX1(ABS(T),ABS(DT)))
      JFLAG=ISIGN(2,IFLAG)
C
C     PˆCBOˆTœ BE‹ˆ—ˆHE ˜AƒA ‡HAK,COOTBETCTB“ž™ˆ‰
C     ˆHTEƒPˆPOBAHˆž B HAPAB‹EHˆˆ OT T K TOUT
C
   80 H=SIGN(H,DT)
C
C     POBEPKA, HACKO‹œKO CEPœE‡HO B‹ˆŸHˆE HA RKF45
C     C‹ˆ˜KOM O‹œ˜OƒO ‡ATPEOBAHHOƒO —ˆC‹A B›XO„-
C     H›X TO—EK
C
      IF(ABS(H).GE.2.0*ABS(DT))KOP=KOP+1
      IF(KOP.NE.100)GO TO 85
C
C     —PE‡MEPHAŸ —ACTOTA B›XO„OB
C
      KOP=0
      IFLAG=7
      RETURN
C
   85 IF(ABS(DT).GT.U26*ABS(T))GO TO 95
C
C     EC‹ˆ O—EHœ ‹ˆ‡KO K TO—KE B›XO„A,POKCTPAO-
C     ‹ˆPOBATœ ˆ BEPH“TœCŸ O MECT“ B›‡OBA
C
      DO 90 K=1,NEQN
   90 Y(K)=Y(K)+DT*YP(K)
      A=TOUT
      CALL F(A,Y,YP)
      NFE=NFE+1
      GO TO 300
C
C     PˆCBOˆTœ HA—A‹œHOE ‡HA—EHˆE ˆH„ˆKATOP“ TO—Kˆ
C     B›XO„A
C
   95 OUTPUT=.FALSE.
C
C     —TO› ˆ‡E†ATœ HEOPAB„AHHOƒO MA˜ˆHHOƒO H“‹Ÿ
C     Pˆ B›—ˆC‹EHˆˆ ”“HK–ˆˆ OT ƒPAHˆ– OƒPE˜HO-
C     CTE‰,POMAC˜TAˆPOBATœ Tˆ ƒPAHˆ–›
C
      SCALE=2./RELERR
      AE=SCALE*ABSERR
C
C     O˜AƒOBOE ˆHTEƒPˆPOBAHˆE
C
  100 HFAILD=.FALSE.
C
C     “CTAHOBˆTœ HAˆMEHœ˜“ž „O“CTˆM“ž BE‹ˆ—ˆH“ ˜AƒA
C
      HMIN=U26*ABS(T)
C
C     ˆCPABˆTœ Pˆ HEOXO„ˆMOCTˆ BE‹ˆ—ˆH“ ˜AƒA,
C     —TO› „OCTˆƒH“Tœ TO—Kˆ B›XO„A. PACC—ˆTATœ HA
C     „BA ˜AƒA BEPE„,—TO› ˆ‡E†ATœ C‹ˆ˜KOM PE‡KˆX
C     ˆ‡MEHEHˆ‰ B BE‹ˆ—ˆHE ˜AƒA ˆ TEM CAM›M “MEHœ-
C     ˜ˆTœ B‹ˆŸHˆE B›XO„H›X TO—EK HA POƒPAMM“.
C
      DT=TOUT-T
      IF(ABS(DT).GE.2.*ABS(H))GO TO 200
      IF(ABS(DT).GT.ABS(H))GO TO 150
C
C     C‹E„“ž™ˆ‰ “CE˜H›‰ ˜Aƒ ‡ABEP˜ˆT ˆHTEƒPˆPO-
C     BAHˆE „O “KA‡AHHO‰ TO—Kˆ B›XO„A
C
      OUTPUT=.TRUE.
      H=DT
      GO TO 200
C
  150 H=0.5*DT
C
C
C
C     BH“TPEHHˆ‰ O„HO˜AƒOB›‰ ˆHTEƒPATOP
C
C     ƒPAHˆ–› OƒPE˜HOCTE‰ ›‹ˆ POMAC˜TAˆPOBAH›,
C     —TO› ˆ‡E†ATœ HEOPAB„AHHOƒO MA˜ˆHHOƒO H“‹Ÿ
C     Pˆ B›—ˆC‹EHˆˆ ”“HK–ˆˆ OT HˆX.
C     —TO› ˆ‡E†ATœ OPA™EHˆŸ B H“‹œ ‡HAMEHATE‹Ÿ
C     B TECTE,OTHOCˆTE‹œHAŸ O˜ˆKA ˆ‡MEPŸETCŸ  O
C     OTHO˜EHˆž K CPE„HEM“  ˆ‡ BE‹ˆ—ˆH PE˜EHˆŸ
C     B HA—A‹E ˆ KOH–E ˜AƒA.
C     B ”OPM“‹E,O–EHˆBAž™E‰ O˜ˆK“,POˆ‡BE„EHA
C     ƒP“ˆPOBKA C‹AƒAEM›X,“MEHœ˜Až™AŸ OTEPž
C     BEPH›X ‡HAKOB.
C     —TO› PA‡‹ˆ—ATœ ME†„“ COO‰ PA‡H›E APƒ“MEHT›,
C     „‹Ÿ H HE „O“CKAžTCŸ ‡HA—EHˆŸ,MEHœ˜ˆE “MHO-
C     †EHHO‰ HA 26 O˜ˆKˆ OKP“ƒ‹EHˆŸ B T.
C     BBE„EH› PAKTˆ—ECKˆE OƒPAHˆ—EHˆŸ HA CKOPOCTœ
C     ˆ‡MEHEHˆŸ BE‹ˆ—ˆH› ˜AƒA,—TO› Cƒ‹A„ˆTœ PO-
C     –ECC B›OPA TO‰ BE‹ˆ—ˆH› ˆ ˆ‡E†ATœ —PE‡MEP-
C     HOƒO EE PA‡POCA B ‡A„A—AX C HAP“˜EHˆEM HEPE-
C     P›BHOCTˆ.
C     ˆ‡ PE„OCTOPO†HOCTˆ POƒPAMMA EPET 9/10 OT TO‰
C     BE‹ˆ—ˆH› ˜AƒA,KOTOPAŸ H“†HA O EE O–EHKE.
C     EC‹ˆHA „AHHOM ˜AƒE ›‹A HE“„A—HAŸ O›TKA
C     TO Pˆ ‹AHˆPOBAHˆˆ C‹E„“ž™EƒO “BE‹ˆ—EHˆE
C     „‹ˆH› ˜AƒA HE „O“CKAETCŸ. TO OB›˜AET ””EK-
C     TˆBHOCTœ POƒPAMM› „‹Ÿ ‡A„A— C PA‡P›BAMˆ ˆ
C     B O™EM C‹“—AE,OCKO‹œK“ ˆCO‹œ‡“ETCŸ ‹OKA‹œ-
C     HAŸ KCTPAO‹Ÿ–ˆŸ ˆ „OO‹HˆTE‹œHAŸ PE„OCTO-
C     PO†HOCTœ KA†ETCŸ OPAB„AHHO‰.
C
C
C     POBEPˆTœ —ˆC‹O B›—ˆC‹EHˆ‰ POˆ‡BO„H›X.EC‹ˆ
C     OHO HE PEB›˜AET “CTAHOB‹EHHOƒO PE„E‹A,O-
C     POOBATœ PO„O‹†ˆTœ ˆHTEƒPˆPOBAHˆE C T „O T+H
C
  200 IF(NFE.LE.MAXNFE)GO TO 220
C
C     C‹ˆ˜KOM O‹œ˜AŸ PAOTA
C
      IFLAG=4
      KFLAG=4
      RETURN
C
C     PO„O‹†ˆTœ Pˆ‹ˆ†EHHOE PE˜EHˆE HA O„ˆH ˜Aƒ „‹ˆH› H
C
  220 CALL FEHL(F,NEQN,Y,T,H,YP,F1,F2,F3,F4,F5,F1)
      NFE=NFE+5
C
C     B›—ˆC‹ˆTœ ˆ CPABHˆTœ „O“CTˆM›E ƒPAHˆ–› ˆ
C     O–EHKˆ ‹OKA‹œHO‰ O˜ˆ,A ‡ATEM CHŸTœ MAC˜TA-
C     ˆPOBAHˆE ƒPAHˆ–.‡AMETœTE,—TO OTHOCˆTE‹œHAŸ
C     O˜ˆKA ˆ‡MEPŸETCŸ O OTHO˜EHˆž K CPE„HEM“ ˆ‡
C     BE‹ˆ—ˆH PE˜EHˆŸ B HA—A‹E ˆ KOH–E ˜AƒA.
C
      EEOET=0.
      DO 250 K=1,NEQN
      ET=ABS(Y(K))+ABS(F1(K))+AE
      IF(ET.GT.0.)GO TO 240
C
C     HEPABˆ‹œHAŸ ƒPAHˆ–A OƒPE˜HOCTˆ
C
      IFLAG=5
      KFLAG=5
      RETURN
C
  240 EE=ABS((-2090.*YP(K)+(21970.*F3(K)-15048.*F4(K)))
     *  +(22528.*F2(K)-27360.*F5(K)))
  250 EEOET=AMAX1(EEOET,EE/ET)
C
      ESTTOL=ABS(H)*EEOET*SCALE/752400.
C
      IF(ESTTOL.LE.1.0)GO TO 260
C
C
C     HE“„A—H›‰ ˜Aƒ
C            “MEHœ˜ˆTœ BE‹ˆ—ˆH“ ˜AƒA ˆ CHOBA O-
C            POOBATœ
C            “MEHœ˜EHˆE OƒPAHˆ—ˆBAETCŸ CHˆ‡“ MHO-
C            †ˆTE‹EM 1/10
C
      HFAILD=.TRUE.
      OUTPUT=.FALSE.
      S=0.1
      IF(ESTTOL.LT.59049.)S=0.9/ESTTOL**0.2
      H=S*H
      IF(ABS(H).GT.HMIN)GO TO 200
C
C     ‡A„AHHAŸ ƒPAHˆ–A O˜ˆKˆ HE„OCTˆ†ˆMA „A†E Pˆ
C     HAˆMEHœ˜E‰ „O“CTˆMO‰ BE‹ˆ—ˆHE ˜AƒA
C
      IFLAG=6
      KFLAG=6
      RETURN
C
C
C     “CE˜H›‰ ˜Aƒ
C            OMECTˆTœ B MACCˆB Y PE˜EHˆE B TO—KE
C            T+H ˆ B›—ˆC‹ˆTœ POˆ‡BO„H›E B TO‰
C            TO—KE
C
  260 T=T+H
      DO 270 K=1,NEQN
  270 Y(K)=F1(K)
      A=T
      CALL F(A,Y,YP)
      NFE=NFE+1
C
C
C     B›PATœ BE‹ˆ—ˆH“ C‹E„“ž™EƒO ˜AƒA
C     “BE‹ˆ—EHˆE OƒPAHˆ—EHO MHO†ˆTE‹EM 5
C     EC‹ˆ HA „AHHOM ˜AƒE ›‹A HE“„A—HAŸ
C     O›TKA,TO „‹Ÿ C‹E„“ž™EƒO HE „O“-
C     CKAETCŸ B›OP O‹œ˜E‰ BE‹ˆ—ˆH› ˜AƒA
C
      S=5.
      IF(ESTTOL.GT.1.889568E-4)S=0.9/ESTTOL**0.2
      IF(HFAILD)S=AMIN1(S,1.0)
      H=SIGN(AMAX1(S*ABS(H),HMIN),H)
C
C     KOHE– O„HO˜AƒOBOƒO ˆHTEƒPATOPA
C
C
C     H“†HO ‹ˆ „E‹ATœ O—EPE„HO‰ ˜Aƒ
C
      IF(OUTPUT)GO TO 300
      IF(IFLAG.GT.0)GO TO 100
C
C
C     ˆHTEƒPˆPOBAHˆE “CE˜HO ‡ABEP˜EHO
C
C     PE†ˆM O„HO˜AƒOBOƒO ˆHTEƒPˆPOBAHˆŸ
C
      IFLAG=-2
      RETURN
C
C     PE†ˆM ˆHTEƒPˆPOBAHˆŸ HA ˆHTEPBA‹E
C
  300 T=TOUT
      IFLAG=2
      RETURN
C
      END
