      SUBROUTINE FEHL(F,NEQN,Y,T,H,YP,F1,F2,F3,F4,F5,S)
C
C     METO„ P“HƒE-K“TTA-”E‹œEPƒA —ETBEPTOƒO-ŸTOƒO OPŸ„KA
C
C     O„POƒPAMMA FEHL ˆHTEƒPˆP“ET CˆCTEM“ ˆ‡ NEQN
C     O›KHOBEHH›X „ˆ””EPEH–ˆA‹œH›X “PABHEHˆ‰ EPBOƒO
C     OPŸ„KA C‹E„“ž™EƒO Bˆ„A
C
C          DY(I)/DT=F(T,Y(1),...Y(NEQN)),
C
C     ƒ„E HA—A‹œH›E ‡HA—EHˆŸ Y(I) ˆ HA—A‹œH›E POˆ‡BO„H›E
C     YP(I) ‡A„AH› B HA—A‹œHO‰ TO—KE T. FEHL PO„O‹†AET
C     PE˜EHˆE HA ”ˆKCˆPOBAHH›‰ ˜Aƒ H ˆ OME™AET B MACCˆB
C     S(I) Pˆ‹ˆ†EHˆE K PE˜EHˆž B TO—KE T+H, ˆMEž™EE ŸT›‰
C     OPŸ„OK TO—HOCTˆ (‹OKA‹œH›‰ OPŸ„OK PABEH ˜ECTˆ).
C     F1,...F5-MACCˆB› PA‡MEPHOCTˆ NEQN,HEOXO„ˆM›E BH“TPˆ
C     POƒPAMM›.
C          B ”OPM“‹AX POˆ‡BE„EHA ƒP“ˆPOBKA C –E‹œž
C     “MEHœ˜ˆTœ OTEPž BEPH›X ‡HAKOB.
C          —TO› MO†HO ›‹O PA‡‹ˆ—ATœ PA‡H›E HE‡ABˆCˆM›E
C     APƒ“MEHT›, Pˆ OPA™EHˆˆ K FEHL HE C‹E„“ET ‡A„ABATœ
C     „‹Ÿ H ‡HA—EHˆE,MEHœ˜EE “MHO†EHHHO‰ HA 13 O˜ˆKˆ
C     OKP“ƒ‹EHˆŸ B T.
C
      INTEGER NEQN
      REAL Y(NEQN),YP(NEQN),F1(NEQN),F2(NEQN),
     *     F3(NEQN),F4(NEQN),F5(NEQN),S(NEQN)
      REAL CH
      INTEGER K
C
      CH=H/4.0
      DO 221 K=1,NEQN
  221 F5(K)=Y(K)+CH*YP(K)
C
      CALL F(T+CH,F5,F1)
      CH=3.0*H/32.0
      DO 222 K=1,NEQN
  222 F5(K)=Y(K)+CH*(YP(K)+3.0*F1(K))
      CALL F(T+3.0*H/8.0,F5,F2)
C
      CH=H/2197.0
      DO 223 K=1,NEQN
  223 F5(K)=Y(K)+CH*(1932.0*YP(K)+(7296.0*F2(K)-7200.0*F1(K)))
      CALL F(T+12.0*H/13.0,F5,F3)
C
      CH=H/4104.0
      DO 224 K=1,NEQN
  224 F5(K)=Y(K)+CH*((8341.0*YP(K)-845.0*F3(K))+
     *      (29440.0*F2(K)-32832.0*F1(K)))
      CALL F(T+H,F5,F4)
C
      CH=H/20520.0
      DO 225 K=1,NEQN
  225 F1(K)=Y(K)+CH*((-6080.0*YP(K)+(9295.0*F3(K)-
     *      5643.0*F4(K)))+(41040.0*F1(K)-28352.0*F2(K)))
      CALL F(T+H/2.0,F1,F5)
C
C     B›—ˆC‹ˆTœ Pˆ‹ˆ†EHHOE PE˜EHˆE B TO—KE T+H
C
      CH=H/7618050.0
      DO 230 K=1,NEQN
  230 S(K)=Y(K)+CH*((902880.0*YP(K)+(3855735.0*F3(K)-
     *     1371249.0*F4(K)))+(3953664.0*F2(K)+277020.0*F5(K)))
C
      RETURN
      END
