program TSVD;
uses FMM, crt;
var
   A, U, V               :  floatmatrixCS;
   S, W                  :  floatvectorc;
   i, err, j, m, nm, n   :  integer;
Begin
  clrscr;
  writeln('    Иллюстpиpующая пpогpамма для SVD - вычисляется    т');
  writeln('       сингуляpное  pазложение  матpицы      A = U*S*V');
  writeln;
  nm:=5; m:=5; n:=3;
  for i:=1 to m do for j:=1 to n do a[i,j]:=i+(j-1)*m;
  for i:=1 to m do begin
                     for j:=1 to n do write(a[i,j]:8:3,' ');
                     writeln;
                   end;
  gotoxy(35,4); writeln('  initial matrix A');
  gotoxy(1,10);
  SVD(m, n, a, s, true, u, true, v, err, w);
  writeln(' Error code = ',err);
  writeln;

  for j:= 1 to n do write(s[j]:8:3,' '); write('          vector S');
  writeln; writeln;
  for i:=1 to m do begin
                     for j:=1 to n do write(u[i,j]:8:3,' ');
                     writeln;
                   end;
  gotoxy(35,14); writeln('   matrix U');
  gotoxy(1,20);
  for i:=1 to n do begin
                     for j:=1 to n do write(v[i,j]:8:3,' ');
                     writeln;
                   end;
  gotoxy(35,20); writeln('   matrix V');
  gotoxy(1,24);
End.