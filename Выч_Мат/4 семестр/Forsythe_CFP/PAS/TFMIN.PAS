program tfmin;
{$N-}
uses FMM, crt;
Var
      a, b, z, tol : float;
      i, j         : integer;
{$F+}
function f1(x : float) : float;
begin
 f1:=x*(x*x-2)-5;
 inc(j);
end;
{$F-}

Begin
  clrscr;
  writeln('    Иллюстpиpующая пpогpамма для FMIN');
  writeln;
  a:=0;
  b:=1;
  writeln('  Опpеделяется минимум функции  F(X) = X**3 - 2*X - 5');
  writeln('      пpи',a:2:0,' < X < ',b:2:0);
  writeln;
  tol:=1e-1;
  writeln('       Tol                 Xmin           Nofun');
  writeln;
  tol:=1e-1;
  for i:=-2 downto -15 do begin
                            j:=0;
                            tol:=tol*0.1;
                            writeln(tol,'     ',fmin(a,b,tol,@F1):12:8,
                                        '          ',j);

                         end;
end.