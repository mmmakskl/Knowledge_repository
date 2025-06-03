program tsolve;  { Иллюстpиpующая пpогpамма для  DECOMP & SOLVE }
{$N-}

    uses FMM, printer,crt;
const ndim = 20;
type  floatmatrix = array[1..ndim,1..ndim] of real;

Var
       a  : floatmatrix;
 b,z,  w  : floatvector;
ni,ma, ip : ivector;
 cond,c   : float;
 i,j      : integer;

Begin
 clrscr;
 writeln('Size of A = ', sizeof(a), '    Ndim= ',Ndim);

 a[1,1]:= 10;  a[1,2]:= -7;  a[1,3]:=  0;
 a[2,1]:= -3;  a[2,2]:=  2;  a[2,3]:=  6;
 a[3,1]:=  5;  a[3,2]:= -1;  a[3,3]:=  5;
 b[1]:=7;
 b[2]:=4;
 b[3]:=6;
 writeln('Иллюстpиpующая пpогpамма для  DECOMP & SOLVE');
 writeln;
 writeln('       Решается уpавнение  A * X = B');
 writeln;
 writeln('  Matrix A                             vector B');
 for i := 1 to 3 do begin
                         write('        ');
                         for j:=1 to 3 do write(a[i,j]:8:2);
                         writeln('              ',b[i]:6:2);
                    end;
 decomp(3,a,cond,ip,w);
 writeln;
 writeln('  Cond = ',cond:8:2);
 writeln;
 writeln('  Solution');
 solve(3,a,b,ip);
 for i:=1 to 3 do
    writeln('            X[',i:1,'] =',b[i]:9:5);
    repeat until keypressed;
 end.