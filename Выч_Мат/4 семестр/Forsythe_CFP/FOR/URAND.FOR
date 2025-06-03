      REAL FUNCTION URAND(IY)
      INTEGER IY
C
C       URAND-TO „AT—ˆK PABHOMEPHO PACPE„E‹EHH›X C‹“—A‰H›X
C     —ˆCE‹, OCHOBAHH›‰ HA TEOPˆˆ ˆ PE„‹O†EHˆŸX, CO„EP†A™ˆXCŸ
C     B KHˆƒE KH“T (1969),TOM 2.
C       EPE„ EPB›M OPA™EHˆEM K URAND –E‹O‰ EPEMEHHO‰ IY
C     C‹E„“ET PˆCBOˆTœ POˆ‡BO‹œHOE –E‹O—ˆC‹EHHOE HA—A‹œ-
C     HOE ‡HA—EHˆE. B›‡›BAž™AŸ POƒPAMMA HE „O‹†HA ˆ‡MEHŸTœ
C     ‡HA—EHˆE IY ME†„“ OC‹E„OBATE‹œH›Mˆ B›‡OBAMˆ. ‡HA—EHˆŸ
C     ”“HK–ˆˆ URAND ŸB‹ŸžTCŸ —ˆC‹AMˆ ˆ‡ ˆHTEPBA‹A (0,1).
C
      INTEGER IA,IC,ITWO,M2,M,MIC
      DOUBLE PRECISION HALFM
      REAL S
      DOUBLE PRECISION DATAN,DSQRT
      DATA M2/0/,ITWO/2/
      IF(M2.NE.0) GOTO 20
C
C     EC‹ˆ TO EPB›‰ BXO„, TO B›—ˆC‹ˆTœ „‹ˆH“
C     –E‹O—ˆC‹EHHOƒO MA˜ˆHHOƒO C‹OBA
C
      M=1
   10 M2=M
      M=ITWO*M2
      IF(M .GT. M2) GO TO 10
      HALFM=M2
C
C     B›—ˆC‹ˆTœ MHO†ˆTE‹œ ˆ PˆPA™EHˆE ‹ˆHE‰HOƒO
C     KOHƒP“HTHOƒO METO„A
C
      IA=8*IDINT(HALFM*DATAN(1.D0)/8.D0)+5
      IC=2*IDINT(HALFM*(0.5D0-DSQRT(3.D0)/6.D0))+1
      MIC=(M2-IC)+M2
C
C     S-MAC˜TAˆP“ž™ˆ‰ MHO†ˆTE‹œ „‹Ÿ PEOPA‡OBAHˆŸ B —ˆC‹O
C     C ‹ABAž™E‰ TO—KO‰
C
      S=0.5/HALFM
C
C     B›—ˆC‹ˆTœ C‹E„“ž™EE C‹“—A‰HOE —ˆC‹O
C
   20 IY=IY*IA
C
C     C‹E„“ž™ˆ‰ OEPATOP-„‹Ÿ MA˜ˆH,KOTOP›E HE „O“CKAžT
C     EPEO‹HEHˆŸ –E‹›X —ˆCE‹ Pˆ C‹O†EHˆˆ
C
      IF(IY.GT.MIC) IY=(IY-M2)-M2
      IY=IY+IC
C
C     C‹E„“ž™ˆ‰ OEPATOP - „‹Ÿ MA˜ˆH, “ KOTOP›X „‹ˆHA C‹OBA
C     „‹Ÿ C‹O†EHˆŸ O‹œ˜E, —EM „‹Ÿ “MHO†EHˆŸ
C
      IF(IY/2.GT.M2) IY=(IY-M2)-M2
C
C     C‹E„“ž™ˆ‰ OEPATOP - „‹Ÿ MA˜ˆH, “ KOTOP›X EPEO‹HEHˆE
C     –E‹OƒO —ˆC‹A B‹ˆŸET HA ‡HAKOB›‰ PA‡PŸ„
C
      IF(IY.LT.0) IY=(IY+M2)+M2
      URAND=FLOAT(IY)*S
      RETURN
      END
