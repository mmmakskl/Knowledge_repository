program  TRKF45;
{$N-}
uses FMM, dos, crt;
label 101;
const n=4;
var   t, tout, relerr, abserr,
      tfinal, tprint, alfasq,
      alfa, ecc                  : float;
      iflag                      : integer;
      iwork                      : ivec5;
      work                       : rvecn;
      y, yp                      : floatvector;
      h1, h2, h3, h4,
      k1, k2, k3, k4             : word;
      n1                         : integer absolute h1;
      n2                         : integer absolute h2;
      n3                         : integer absolute h3;
      n4                         : integer absolute h4;
      l1                         : integer absolute k1;
      l2                         : integer absolute k2;
      l3                         : integer absolute k3;
      l4                         : integer absolute k4;

{$F+}
procedure f(t:float;var y,yp:floatvector);
var r:float;
  begin
    r:=y[1]*y[1]+y[2]*y[2];
    r:=r*sqrt(r)/alfasq;
    yp[1]:=y[3];
    yp[2]:=y[4];
    yp[3]:=-y[1]/r;
    yp[4]:=-y[2]/r
  end;
{$F-}

Begin                                    {   M A I N  }
  clrscr;
  write('  Иллюстpиpующая пpогpамма для RKF45');
  ecc:=0.25;
  alfa:=3.141592653589/4;
  alfasq:=alfa*alfa;
  t:=0;
  y[1]:=1-ecc;
  y[2]:=0;
  y[3]:=0;
  y[4]:=alfa*sqrt((1+ecc)/(1-ecc));
  relerr:=1E-9;
  abserr:=0;
  tfinal:=12;
  tprint:=1;
  iflag:=1;
  tout:=t;
{$IFOPT N+}
  writeln('   With 8087/80287 chip   / $N+ /');
{$ELSE}
  writeln('   Without 8087/80287 chip    / $N- /');
{$ENDIF}
  gettime(h1,h2,h3,h4);
  writeln;
  writeln(' Started at  ',h1:2, ':',h2:2,':',h3:2,',',h4:2);
  writeln('________________________________________________________________');
  writeln;
101:
  rkf45(@F,n,y,t,tout,relerr,abserr,iflag,work,iwork);
  writeln('  t= ',t:6:2, '  y[1]=',y[1]:13:9,'  y[2]=',y[2]:13:9,
          '   Flag=',iflag:2);
  case iflag of
      1, 8  :  exit;
      2     :  begin
                 tout:=t+tprint;
                 if t<tfinal then goto 101
               end;
      4     :  goto 101;
      5     :  begin
                 abserr:=1E-9;
                 goto 101
               end;
      6     :  begin
                 relerr:=10*relerr;
                 iflag:=2;
                 goto 101
               end;
      7     :  begin
                 iflag:=2;
                 goto 101
               end
                                       end;
  gettime(k1,k2,k3,k4);
  writeln;
  writeln('______________________________________________________');
  write(' Ended at    ',k1:2, ':',k2:2,':',k3:2,',',k4:2);
  writeln('        Total time = ',
  ((l1-n1)*360000.0+(l2-n2)*6000.0+(l3-n3)*100.0+(l4-n4))/100.0:8:2);
End.






