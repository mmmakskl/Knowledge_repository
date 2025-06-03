      SUBROUTINE RKF45(F,NEQN,Y,T,TOUT,RELERR,ABSERR,
     *                 IFLAG,WORK,IWORK)
C
C     METO„ P“HƒE-K“TTA ”E‹œEPƒA —ETBEPTOƒO-ŸTOƒO OPŸ„KA
C
C     COCTABˆTE‹ˆ POƒPAMM›-H.A.WATTS,L.F.SHAMPINE
C                SANDIA LABORATORIES
C              ALBUQUERQUE, NEW MEXICO
C
C     RKF45 PE„HA‡HA—EHA ƒ‹ABH›M OPA‡OM „‹Ÿ PE˜EHˆŸ
C     HE†ECTKˆX ˆ C‹AO †ECTKˆX „ˆ””EPEH–ˆA‹œH›X “PABHEHˆ‰,
C     KOƒ„A B›—ˆC‹EHˆE POˆ‡BO„H›X HE C‹ˆ˜KOM „OPOƒOCTOŸ™EE.
C     RKF45, BOO™E ƒOBOPŸ,HE C‹E„“ET ˆCO‹œ‡OBATœ
C     EC‹ˆ O‹œ‡OBATE‹ž TPE“ETCŸ B›COKAŸ TO—HOCTœ
C
C     PE‡žME
C
C     O„POƒPAMMA RKF45 ˆHTEƒPˆP“ET CˆCTEM“ ˆ‡ NEQN
C     O›KHOBEHH›X „ˆ””EPEH–ˆA‹œH›X “PABHEHˆ‰ EPBOƒO
C     OPŸ„KA C‹E„“ž™EƒO Bˆ„A:
C
C            DY(I)/DT=F(T,Y(1),Y(2),...,Y(NEQN),
C
C     ƒ„E Y(I) ‡A„AH› B T.
C     O›—HO O„POƒPAMM“ PˆMEHŸžT „‹Ÿ ˆHTEƒPˆPOBAHˆŸ
C     OT T „O TOUT, O„HAKO EE MO†HO ˆCO‹œ‡OBATœ ˆ KAK
C     O„HO˜AƒOB›‰ ˆHTEƒPATOP,—TO› PO„O‹†ˆTœ PE˜EHˆE HA
C     O„ˆH ˜Aƒ B HAPAB‹EHˆˆ TOUT.HA B›XO„E APAMETPAM,
C     ”ˆƒ“PˆP“ž™ˆM B CˆCKE B›‡OBA, PˆCBAˆBAžTCŸ ‡HA—EHˆŸ,
C     HEOXO„ˆM›E „‹Ÿ PO„O‹†EHˆŸ ˆHTEƒPˆPOBAHˆŸ. O‹œ‡O-
C     BATE‹ž H“†HO ‹ˆ˜œ E™E PA‡ OPATˆTœCŸ K RKF45
C     (ˆ,BO‡MO†HO,OPE„E‹ˆTœ HOBOE ‡HA—EHˆE „‹Ÿ TOUT).
C     B „E‰CTBˆTE‹œHOCTˆ RKF45-TO POƒPAMMA ˆHTEP”E‰CA,
C     KOTOPAŸ B›‡›BAET O„POƒPAMM“ RKFS, OC“™ECTB‹Ÿž™“ž
C     PO–ECC PE˜EHˆŸ.RKFS B CBOž O—EPE„œ B›‡›BAET O„POƒ-
C     PAMM“ FEHL, KOTOPAŸ B›—ˆC‹ŸET Pˆ‹ˆ†EHHOE PE˜EHˆE
C     HA O„ˆH ˜Aƒ.
C
C     RKF45 ˆCO‹œ‡“ET METO„ P“HƒE-K“TTA-”E‹œEPƒA, OˆCAHH›‰
C     B C‹E„“ž™E‰ “‹ˆKA–ˆˆ:E.FEHLBERG,LOW-ORDER CLASSICAL
C     RUNGE-KUTTA FORMULAS WITH STEPSIZE CONTROL,NASA TR R-315
C
C     CTˆ‹œ PAOT› POƒPAMM› RKF45 ˆ‹‹žCTPˆP“ETCŸ B C‹E„“ž™ˆX
C     “‹ˆKA–ˆŸX:L.F.SHAMPINE,H.A.WATTS,S.DAVENPORT, SOLVING
C     NON-STIFF ORDINARY DIFFERENTIAL EQUATIONS-THE STAT OF
C     THE ART,SANDIA LABORATORIES REPORT SAND75-0182,SIAM
C     REVIEW,18(1976), N3,376-411.
C
C     APAMETP› POƒPAMM›:
C
C     F       -O„POƒPAMMA F(T,Y,YP) „‹Ÿ B›—ˆC‹EHˆŸ
C              POˆ‡BO„H›X YP(I)=DY(I)/DT
C     NEQN    -—ˆC‹O ˆHTEƒPˆP“EM›X “PABHEHˆ‰
C     Y(*)    -PE˜EHˆE B TO—KE T
C     T       -HE‡ABˆCˆMAŸ EPEMEHHAŸ
C     TOUT    -TO—KA B›XO„A,B KOTOPO‰ H“†HO OPE„E‹ˆTœ
C              ‡HA—EHˆE PE˜EHˆŸ
C     RELERR  -ƒPAHˆ–A OTHOCˆTE‹œHO‰ OƒPE˜HOCTˆ
C              „‹Ÿ TECTA ‹OKA‹œHO‰ O˜ˆKˆ.
C     ABSERR  -ƒPAHˆ–A ABCO‹žTHO‰ OƒPE˜HOCTˆ
C              „‹Ÿ TECTA ‹OKA‹œHO‰ O˜ˆKˆ.
C              HA KA†„OM ˜AƒE POƒPAMMA TPE“ET B›O‹HEHˆŸ “C‹OBˆŸ
C              ABS(LOCAL ERROR).LE.RELERR*ABS(Y)+ABSERR
C              „‹Ÿ KA†„O‰ KOMOHEHT› BEKTOPOB ‹OKA‹œHO‰
C              O˜ˆKˆ ˆ PE˜EHˆŸ
C     IFLAG   -“KA‡ATE‹œ PE†ˆMA ˆHTEƒPˆPOBAHˆŸ.
C     WORK(*) -MACCˆB,CO„EP†A™ˆ‰ ˆH”OPMA–ˆž,BH“TPEHHžž „‹Ÿ RKF45,
C              KOTOPAŸ HEOXO„ˆMA Pˆ OC‹E„“ž™ˆX B›‡OBAX.EƒO
C              PA‡MEPHOCTœ „O‹†HA ›Tœ HE MEHœ˜E 3+6*NEQN
C     IWORK(*)-–E‹›‰ MACCˆB,CO„EP†A™ˆ‰ ˆH”OPMA–ˆž,BH“TPEHHžž „‹Ÿ
C              RKF45,KOTOPAŸ HEOXO„ˆMA Pˆ OC‹E„“ž™ˆX B›‡OBAX.
C              EƒO PA‡MEPHOCTœ „O‹†HA ›Tœ HE MEHœ˜E 5.
C
C     EPBOE OPA™EHˆE K RKF45
C
C     O‹œ‡OBATE‹œ „O‹†EH PE„“CMOTPETœ B CBOE‰ B›‡›BAž™E‰
C     POƒPAMME AMŸTœ „‹Ÿ C‹E„“ž™ˆX MACCˆBOB, ”ˆƒ“PˆP“ž™ˆX
C     B CˆCKE B›‡OBA- Y(NEQN), WORK(3+6*NEQN), IWORK(5);
C     KPOME TOƒO, OH „O‹†EH O'ŸBˆTœ F B OEPATOPE EXTERNAL,
C     O„ƒOTOBˆTœ O„POƒPAMM“ F(T,Y,YP) ˆ PˆCBOˆTœ HA—A‹œ-
C     H›E ‡HA—EHˆŸ APAMETPAM-
C
C     NEQN  -—ˆC‹O ˆHTEƒPˆP“EM›X “PABHEHˆ‰ (NEQN.GE.1)
C     Y(*)  -BEKTOP HA—A‹œH›X “C‹OBˆ‰
C     T     -HA—A‹œHAŸ TO—KA ˆHTEƒPˆPOBAHˆŸ,
C            T „O‹†HO ›Tœ EPEMEHHO‰.
C     TOUT  -TO—KA B›XO„A,B KOTOPO‰ H“†HO HA‰Tˆ ‡HA—EHˆE
C            PE˜EHˆŸ. T=TOUT BO‡MO†HO ‹ˆ˜œ Pˆ EPBOM
C            OPA™EHˆˆ.B TOM C‹“—AE B›XO„ ˆ‡ RKF45 POˆ-
C            CXO„ˆT CO ‡HA—EHˆEM APAMETPA IFLAG=2,EC‹ˆ
C            MO†HO PO„O‹†ATœ ˆHTEƒPˆPOBAHˆE.
C     RELERR-ƒPAHˆ–A „‹Ÿ OTHOCˆTE‹œHO‰ ‹OKA‹œH›‰ OƒPE˜HOCTEˆ.
C     ABSERR-ƒPAHˆ–A „‹Ÿ ACO‹žTHO‰    ‹OKA‹œH›‰ OƒPE˜HOCTEˆ.
C            Tˆ ƒPAHˆ–› „O‹†H› ›Tœ HEOTPˆ–ATE‹œH›.
C            RELERR „O‹†HA ›Tœ EPEMEHHO‰,A ABSERR MO†ET
C            ›Tœ ˆ KOHCTAHTO‰.POƒPAMME, BOO™E ƒOBOPŸ
C            HE C‹E„“ET ‡A„ABATœ ƒPAHˆ–“ „‹Ÿ OTHOCˆTE‹œHO‰
C            O˜ˆKˆ,MEHœ˜“ž, —EM PˆMEPHO 1.E-7. „A› ˆ‡E†ATœ
C            TP“„HOCTE‰ ,CBŸ‡AHH›X C O—EHœ B›COKˆMˆ ‡APOCAMˆ
C            K TO—HOCTˆ, POƒPAMMA TPE“ET,—TO› RELERR
C            ›‹A O‹œ˜E, —EM HEKOTOP›‰ APAMETP OTHOCˆTE‹œHO‰
C            O˜ˆKˆ,B›—ˆC‹ŸEM›‰ BH“TPˆ EE ˆ ‡ABˆCŸ™ˆ‰ OT
C            MA˜ˆH›.B —ACTHOCTˆ,HE PA‡PE˜AETCŸ ‡A„AHˆE TO‹œKO
C            ACO‹žTHO‰ O˜ˆKˆ.EC‹ˆ †E ‡A„AHO ‡HA—EHˆE RELERR,
C            MEHœ˜EE „O“CTˆMOƒO, TO RKF45 “BE‹ˆ—ˆBAET RELERR
C            HA„‹E†A™ˆM OPA‡OM ˆ BO‡BPA™AET “PAB‹EHˆE O‹œ-
C            ‡OBATE‹ž, PE†„E —EM PO„O‹†ATœ ˆHTEƒPˆPOBAHˆE.
C     IFLAG-+1,-1.TO “KA‡ATE‹œ HACTPO‰Kˆ POƒPAMM› „‹Ÿ KA†„O‰
C            HOBO‰ ‡A„A—ˆ. HOPMA‹œHOE BXO„HOE ‡HA—EHˆE PABHO+1.
C            O‹œ‡OBATE‹œ „O‹†EH ‡A„ABATœ IFLAG=-1 ‹ˆ˜œ B TOM
C            C‹“—AE,  KOƒ„A HEOXO„ˆMO “PAB‹EHˆE O„HO˜AƒOB›M
C            ˆHTEƒPATOPOM.B TOM C‹“—AE RKF45 ›TAETCŸ PO„O‹†ˆTœ
C            PE˜EHˆE HA O„ˆH ˜Aƒ B HAPAB‹EHˆˆ TOUT Pˆ KA†„OM
C            O—EPE„HOM B›‡OBE. OCKO‹œK“ TOT PE†ˆM PAOT›
C            BECœMA HEKOHOMˆ—EH, EƒO C‹E„“ET PˆMEHŸTœ
C            ‹ˆ˜œ B C‹“—AE KPA‰HE‰ HEOXO„ˆMOCTˆ.
C
C     ˆH”OPMA–ˆŸ HA B›XO„E
C
C     Y(*)    -PE˜EHˆE B TO—KE T
C     T       -OC‹E„HŸŸ TO—KA,„OCTˆƒH“TAŸ Pˆ ˆHTEƒPˆPOBAHˆˆ.
C     IFLAG=2 -PˆˆHTEƒPˆPOBAHˆˆ „OCTˆƒH“TO TOUT.TO ‡HA—EHˆE
C              APAMETPA “KA‡›BAET HA “CE˜H›‰ B›XO„ ˆ
C              ŸB‹ŸETCŸ HOPMA‹œH›M PE†ˆMOM „‹Ÿ PO„O‹†EHˆŸ
C              ˆHTEƒPˆPOBAHˆŸ.
C          =3 -ˆHTEƒPˆPOBAHˆE HE ›‹O ‡AKOH—EHO ˆ‡-‡A TOƒO,
C              —TO ‡A„AHHOE ‡HA—EHˆE ƒPAHˆ–› „‹Ÿ OTHOCˆTE‹œHO‰
C              O˜ˆKˆ OKA‡A‹OCœ C‹ˆ˜KOM MA‹O. „‹Ÿ PO„O‹†EHˆŸ
C              ˆHTEƒPˆPOBAHˆŸ RELERR ›‹O HA„‹E†A™ˆM OPA‡OM
C              “BE‹ˆ—EHO.
C          =4 -ˆHTEƒPˆPOBAHˆE HE ›‹O ‡AKOH—EHO ˆ‡-‡A TOƒO,
C              —TO OTPEOBA‹OCœ O‹EE 3000 B›—ˆC‹EHˆ‰ PO-
C              ˆ‡BO„HO‰.TO COOTBETCTBYET Pˆ‹ˆ‡ˆTE‹œHO
C              500 ˜AƒAM.
C          =5 -ˆHTEƒPˆPOBAHˆE HE ›‹O ‡AKOH—EHO ˆ‡-‡A TOƒO,
C              —TO PE˜EHˆE OPATˆ‹OCœ B HY‹œ,BC‹E„CTBˆE —EƒO
C              TECT TO‹œKO OTHOCˆTE‹œHO‰ O˜ˆKˆ HE POXO„ˆT.
C              „‹Ÿ PO„O‹†EHˆŸ HEOXO„ˆMO HEHY‹EBOE ‡HA—EHˆE
C              APAMETPA ABSERR. ˆCO‹œ‡OBAHˆE HA O„ˆH ˜Aƒ
C              PE†ˆMA O˜AƒOBOƒO ˆHTEƒPˆPOBAHˆŸ ŸB‹ŸETCŸ
C              PA‡YMH›M B›XO„OM ˆ‡ O‹O†EHˆŸ.
C          =6 -ˆHTEƒPˆPOBAHˆE  HE ›‹O ‡AKOH—EHO ˆ‡-‡A TOƒO,
C              —TO TPEYEMAŸ TO—HOCTœ HE MOƒ‹A ›Tœ „OCTˆƒH“TA
C              „A†E Pˆ HAˆMEHœ˜E‰ „O“CTˆ MO‰ BE‹ˆ—ˆHE ˜AƒA.
C              O‹œ‡OBATE‹œ „O‹†EH “BE‹ˆ—ˆTœ ƒPAHˆ–“ OƒPE˜-
C              HOCTˆ,PE†„E —EM MO†HO “„ET O›TATœCŸ
C              PO„O‹†ATœ ˆHTEƒPˆPOBAHˆE.
C          =7 -O BCE‰ Bˆ„ˆMOCTˆ, RKF45 HE””EKTˆBHA Pˆ
C              PE˜EHˆˆ TO‰ ‡A„A—ˆ. C‹ˆ˜KOM O‹œ˜OE —ˆC‹O
C              TPE“EM›X B›XO„H›X TO—EK PEŸTCTB“ET B›OP“
C              ECTECTBEHHO‰ BE‹ˆ—ˆH› ˜AƒA.C‹E„“ET ˆCO‹œ‡OBATœ
C              PE†ˆM O˜AƒOBOƒO ˆHTEƒPˆPOBAHˆŸ.
C          =8 -HEPABˆ‹œHOE ‡A„AHˆE BXO„H›X APAMETPOB.TO
C              ‡HA—EHˆE OŸB‹ŸETCŸ,EC‹ˆ „O“™EHA O„HA ˆ‡
C              C‹E„“ž™ˆX O˜ˆOK-
C                              NEQN.LE.0
C                  T=TOUT  ˆ  IFLAG.NE.+1  ˆ‹ˆ -1
C                  RELERR  ˆ‹ˆ  ABSERR.LT.0
C                  IFLAG.EQ.0  ˆ‹ˆ .LT.-2  ˆ‹ˆ .GT.8
C     WORK(*) -ˆH”OPMA–ˆŸ, KOTOPAŸ O›—HO HE PE„CTAB‹ŸET ˆHTE-
C              PECA „‹Ÿ O‹œ‡OBATE‹Ÿ, HO HEOXO„ˆMA Pˆ OC‹E-
C              „“ž™ˆX B›‡OBAX. WORK(1),...,WORK(NEQN) CO„EP†AT
C              EPB›E POˆ‡BO„H›E BEKTOPA PE˜EHˆŸ Y B TO—KE T.
C              WORK(NEQN+1) XPAHˆT BE‹ˆ—ˆH“ ˜AƒA H,C KOTOPO‰
C              MO†HO O›TATœCŸ POBECTˆ C‹E„“ž™ˆ‰ ˜Aƒ.
C     IWORK(*) -ˆH”OPMA–ˆŸ, KOTOPAŸ O›—HO HE PE„CTAB‹ŸET ˆHTE-
C               PECA „‹Ÿ O‹œ‡OBATE‹Ÿ, HO HEOXO„ˆMA Pˆ OC‹E-
C               „“ž™ˆX B›‡OBAX. B IWORK(1) CO„EP†ˆTCŸ
C               C—ET—ˆK —ˆC‹A B›—ˆC‹EHˆ‰ POˆ‡BO„H›X.
C
C     OC‹E„“ž™ˆE OPA™EHˆŸ K RKF45
C
C          HA B›XO„E O„POƒPAMM› RKF45 ˆMEETCŸ BCŸ ˆH”OPMA–ˆŸ,
C     HEOXO„ˆMAŸ  „‹Ÿ PO„O‹†EHˆŸ ˆHTEƒPˆPOBAHˆŸ.EC‹ˆ Pˆ
C     ˆHTEƒPˆPOBAHˆˆ „OCTˆƒH“TO TOUT,TO O‹œ‡OBATE‹ž „OCTA-
C     TO—HO OPE„E‹ˆTœ HOBOE ‡HA—EHˆE  TOUT ˆ CHOBA OPATˆTœ-
C     CŸ K RKF45.
C          B PE†ˆME O˜AƒOBOƒO ˆHTEƒPˆPOBAHˆŸ (IFLAG=-2)
C     O‹œ‡OBATE‹œ „O‹†EH ˆMETœ B Bˆ„“,—TO KA†„›‰ ˜Aƒ
C     B›O‹HŸETCŸ B HAPAB‹EHˆˆ TEK“™EƒO ‡HA—EHˆŸ TOUT
C     (CˆƒHA‹ˆ‡ˆP“EMOM  ˆ‡MEHEHˆEM IFLAG HA 2). O‹œ‡OBATE‹œ
C     „O‹†EH ‡A„ATœ HOBOE ‡HA—EHˆE TOUT ˆ EPEOPE„E‹ˆTœ
C     IFLAG HA -2, —TO› PO„O‹†ATœ B PE†ˆME O˜AƒOBOƒO
C     ˆHTEƒPˆPOBAHˆŸ.
C          EC‹ˆ ˆHTEƒPˆPOBAHˆE HE ›‹O ‡AKOH—EHO,HO
C     O‹œ‡OBATE‹œ XO—ET PO„O‹†ATœ (C‹“—Aˆ IFLAG=3,4), OH
C     OPOCT“ CHOBA OPA™AETCŸ K RKF45.Pˆ IFLAG=3 APA-
C     METP RELERR ›‹  ˆ‡MEHEH HA„‹E†A™ˆM „‹Ÿ PO„O‹†EHˆŸ
C     ˆHTEƒPˆPOBAHˆŸ OPA‡OM.B C‹“—AE IFLAG=4 C—ET—ˆK
C     —ˆC‹A ‡HA—EHˆ‰ ”“HK–ˆˆ “„ET EPEOPE„E‹EH HA 0, ˆ
C     “„“T PA‡PE˜EH› E™E 3000 B›—ˆC‹EHˆ‰ ”“HK–ˆˆ.
C          O„HAKO B C‹“—AE IFLAG=5, PE†„E —EM MO†HO “„ET
C     PO„O‹†ATœ ˆHTEƒPˆPOBAHˆE,O‹œ‡OBATE‹œ „O‹†EH CHA—A‹A
C     ˆ‡MEHˆTœ KPˆTEPˆ‰ O˜ˆKˆ, ‡A„AB O‹O†ˆTE‹œHOE ‡HA—EHˆE
C     „‹Ÿ ABSERR. EC‹ˆ OH HE C„E‹AET TOƒO, B›O‹HEHˆE PO-
C     ƒPAMM› “„ET PEKPA™EHO.
C        TO—HO TAK †E,B C‹“—AE IFLAG=6,PE†„E —EM PO„O‹-
C     †ATœ ˆHTEƒPˆPOBAHˆE,O‹œ‡OBATE‹ž HEOXO„ˆMO EPEOPE-
C     „E‹ˆTœ IFLAG HA 2 (ˆ‹ˆ -2, EC‹ˆ ˆCO‹œ‡“ETCŸ PE†ˆM
C     O˜AƒOBOƒO ˆHTEƒPˆPOBAHˆŸ) ˆ “BE‹ˆ—ˆTœ ‡HA—EHˆE „‹Ÿ
C     ABSERR ‹ˆO RELERR,‹ˆO ˆ „‹Ÿ TOƒO,ˆ „‹Ÿ „P“ƒOƒO.
C     EC‹ˆ TO HE “„ET C„E‹AHO,B›O‹HEHˆE POƒPAMM›
C     PEKPA™AETCŸ. OŸB‹EHˆE IFLAG=6 “KA‡›BAET HA HEPEƒ“-
C     ‹ŸPHOCTœ (PE˜EHˆE ›CTPO MEHŸETCŸ ˆ‹ˆ, BO‡MO†HO,
C     ˆMEETCŸ OCOEHHOCTœ),ˆ —ACTO B O„OH›X C‹“—AŸX
C     HE ˆMEET CM›C‹A PO„O‹†ATœ ˆHTEƒPˆPOBAHˆE.
C          EC‹ˆ “„ET O‹“—EHO ‡HA—EHˆE IFLAG=7,TO O‹œ‡O-
C     BATE‹œ „O‹†EH EPE‰Tˆ K PE†ˆM“ O˜AƒOBOƒO ˆHTEƒPˆPO-
C     BAHˆŸ C BE‹ˆ—ˆHO‰ ˜AƒA,OPE„E‹ŸEMO‰ POƒPAMMO‰, ˆ‹ˆ
C     PACCMOTPETœ BO‡MO†HOCTTœ EPEXO„A HA POƒPAMM› METO„OB
C     A„AMCA.EC‹ˆ BCE †E O‹œ‡OBATE‹œ XO—ET PO„O‹†ATœ
C     ˆHTEƒPˆPOBAHˆE O O„POƒPAMME RKF45,OH „O‹†EH „O HOBOƒO
C     OPA™EHˆŸ K HE‰ EPEOPE„E‹ˆTœ IFLAG HA 2.B POTˆBHOM
C     C‹“—AE B›O‹HEHˆE POƒPAMM› “„ET PEKPA™EHO.
C          EC‹ˆ O‹“—EHO ‡HA—EHˆE IFLAG=8,TO ˆHTEƒPˆPOBAHˆE
C     HE‹œ‡Ÿ PO„O‹†ATœ,OKA HE “„“T ˆCPAB‹EH› O˜ˆO—H›E
C     BXO„H›E APAMETP›. H“†HO OTMETˆTœ,—TO MACCˆB› WORK ˆ
C     IWORK CO„EP†AT ˆH”OPMA–ˆž,HEOXO„ˆM“ž „‹Ÿ „A‹œHE‰˜EƒO
C     ˆHTEƒPˆPOBAHˆŸ.OTOM“ B Tˆ MACCˆB› HE‹œ‡Ÿ BHOCˆTœ
C     ˆ‡MEHEHˆ‰.
C
      EXTERNAL F
      INTEGER NEQN,IFLAG,IWORK(5)
      REAL Y(NEQN),T,TOUT,RELERR,ABSERR,WORK(1)
C
C     EC‹ˆ TPAHC‹ŸTOP POBEPŸET ˆH„EKC›, TO ‡AMEHˆTœ
C     WORK(1) HA WORK(3+6*NEQN)
C
      INTEGER K1,K2,K3,K4,K5,K6,K1M
C
C     B›—ˆC‹ˆTœ ˆH„EKC› „‹Ÿ PAC™E‹EHˆŸ PAO—EƒO MACCˆBA
C
      K1M=NEQN+1
      K1=K1M+1
      K2=K1+NEQN
      K3=K2+NEQN
      K4=K3+NEQN
      K5=K4+NEQN
      K6=K5+NEQN
C
C     TA POME†YTO—HAŸ POƒPAMMA POCTO COKPA™AET „‹Ÿ
C     O‹œ‡OBATE‹Ÿ „‹ˆHH›‰ CˆCOK B›‡OBA YTEM PAC™E‹EHˆŸ
C     „BYX PAO—ˆX MACCˆBOB. EC‹ˆ TO HE COBMECTˆMO C
C     TPAHC‹ŸTOPOM,TO OH „O‹†EH OPA™ATœCŸ HEOCPE„CTBEHHO
C     K O„POƒPAMME RKFS .
C
      CALL RKFS(F,NEQN,Y,T,TOUT,RELERR,ABSERR,IFLAG,
     *          WORK(1),WORK(K1M),WORK(K1),WORK(K2),
     *          WORK(K3),WORK(K4),WORK(K5),WORK(K6),
     *          WORK(K6+1),IWORK(1),IWORK(2),
     *          IWORK(3),IWORK(4),IWORK(5))
      RETURN
      END
