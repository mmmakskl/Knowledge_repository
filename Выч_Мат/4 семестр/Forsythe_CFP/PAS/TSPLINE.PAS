program tspline;   { Илллюстpиpующая пpогpамма для SPLINE & SEVAL}
uses FMM, crt;

Var x,y,b,c,d : floatvector;
    s,u,t,e   : float;
    i,n       : integer;
Begin
  clrscr;
  for i:= 1 to 10 do begin
                       x[i]:=i;
                       y[i]:=sin(i);
                     end;
  spline(10,x,y,b,c,d);
  u:=1.0;
  writeln(' Результаты выполнения илллюстpиpующей пpогpаммы',
            ' для SPLINE & SEVAL');
  writeln;
  writeln;
  writeln('    Arg      SEVAL''s value      Exact value',
               '     Rel error');
  writeln;
  while u < 4.05 do begin
                      s:=seval(10,u,x,y,b,c,d);
                      t:=sin(u);
                      e:=abs(t-s)/t;
                      writeln('U=',u:6:2,'     S=',s:12:8,
                      '   T=',t:12:8,'   Err=',e:6:4);
                      u:=u+0.2;
                    end;
End.