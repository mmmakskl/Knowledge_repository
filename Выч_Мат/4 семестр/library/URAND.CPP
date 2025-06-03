/* File converted with FORTRAN CONVERTER utility.
   FORTRAN CONVERTER is written by Grigoriev D., 2081/4.*/

#include "forsythe.h"

static int IY;
void INIT_URAND(int I)
{
    IY = I;
}

REAL URAND()
{

//       URAND-�TO �AT��K PABHOMEPHO PAC�PE�E�EHH�X C���A�H�X
//     ��CE�, OCHOBAHH�� HA TEOP�� � �PE��O�EH��X, CO�EP�A��XC�
//     B KH��E KH�T (1969),TOM 2.
//       �EPE� �EPB�M O�PA�EH�EM K URAND �E�O� �EPEMEHHO� IY
//     C�E��ET �P�CBO�T� �PO��BO��HOE �E�O��C�EHHOE HA�A��-
//     HOE �HA�EH�E. B���BA��A� �PO�PAMMA HE �O��HA ��MEH�T�
//     �HA�EH�E IY ME��� �OC�E�OBATE��H�M� B��OBAM�. �HA�EH��
//     ��HK��� URAND �B���TC� ��C�AM� �� �HTEPBA�A (0,1).

static IA,IC,M,MIC;
static double HALFM;
static REAL S;
static M2 = 0, ITWO = 2;
if(M2!=0)goto _20;

//     EC�� �TO �EPB�� BXO�, TO B���C��T� ���H�
//     �E�O��C�EHHO�O MA��HHO�O C�OBA

M=1;
_10:;
M2=M;
M=ITWO*M2;
if(M > M2)goto _10;
HALFM=M2;

//     B���C��T� MHO��TE�� � �P�PA�EH�E ��HE�HO�O
//     KOH�P��HTHO�O METO�A

IA=8*int(HALFM*atan(1.0)/8.0)+5;
IC=2*int(HALFM*(0.5-sqrt(3.0)/6.0))+1;
MIC=(M2-IC)+M2;

//     S-MAC�TA��P����� MHO��TE�� ��� �PEO�PA�OBAH�� B ��C�O
//     C ��ABA��E� TO�KO�

S=0.5/HALFM;

//     B���C��T� C�E����EE C���A�HOE ��C�O

_20:;
IY=IY*IA;

//     C�E������ O�EPATOP-��� MA��H,KOTOP�E HE �O��CKA�T
//     �EPE�O�HEH�� �E��X ��CE� �P� C�O�EH��

if(IY>MIC)IY=(IY-M2)-M2;
IY=IY+IC;

//     C�E������ O�EPATOP - ��� MA��H, � KOTOP�X ���HA C�OBA
//     ��� C�O�EH�� �O���E, �EM ��� �MHO�EH��

if(IY/2>M2)IY=(IY-M2)-M2;

//     C�E������ O�EPATOP - ��� MA��H, � KOTOP�X �EPE�O�HEH�E
//     �E�O�O ��C�A B���ET HA �HAKOB�� PA�P��

if(IY<0)IY=(IY+M2)+M2;
return REAL(IY)*S;
}                         	// END
