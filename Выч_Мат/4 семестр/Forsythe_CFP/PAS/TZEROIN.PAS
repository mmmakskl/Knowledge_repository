program tzeroin;
{$N-}
uses FMM, crt;
Var a, b, z, tol : float;
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
  writeln('    Иллюстpиpующая пpогpамма для ZEROIN');
  writeln;
  writeln('  Опpеделяется коpень полинома F(X) = X**3 - 2*X - 5');
  writeln('  пpи 1 < X < 4 ');
  writeln;
  a:=1;
  b:=4;
  tol:=1e-1;
  writeln('       Tol                 Root           Nofun');
  writeln;
  for i:=-2 downto -11 do begin
                            j:=0;
                            tol:=tol*0.1;
                            writeln(tol,'   ',zeroin(a,b,tol,@F1),
                                        '       ',j);
                         end;
end.