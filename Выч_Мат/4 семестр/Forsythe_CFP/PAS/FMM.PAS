UNIT FMM;
{$N-}
INTERFACE

 Const    ndim  = 25;
          ndimS = 10;
          ndimC = 10;
       maxnfe   = 3000; {Допустимое число вычислений Yp=F(t,Y) для RKF45}

{$IFOPT N+}
type
  Float = double; { 8 byte real, requires 8087 math chip }
{$ELSE}
type
  Float = real;   { 6 byte real, no math chip required }
{$ENDIF}
type  floatvector   = array [1..ndim]           of float;
      floatmatrix   = array [1..ndim,1..ndim]   of float;
      rvecn         = array [1..6*ndim+3]       of float;
      ivec5         = array [1..5]              of integer;
      ivector       = array [1..ndim]           of integer;
      floatvectorS  = array [1..ndimS]          of float;
      floatvectorC  = array [1..ndimC]          of float;
      floatmatrixCS = array [1..ndimS,1..ndimC] of float;



  procedure DECOMP(
                   n  : integer;
             var   A  : floatmatrix ;
             var cond : float   ;
             var ipvt : ivector;
             var work : floatvector
                                   );

  procedure SOLVE (
                   n  : integer;
             var   A  : floatmatrix ;
             var b    : floatvector;
             var ipvt : ivector
                                   );

  procedure LSTSQ(   n, m  : integer;
              var    c     : floatmatrix;
              var    b, z  : floatvector;
              var    nisk,
                     maska : ivector;
              var    w     : floatvector       );

  procedure Spline(  n      : integer;
              var x,y,b,c,d : floatvector);
  function Seval(    n      : integer;
              var u         : float;
              var x,y,b,c,d : floatvector) : float;

  Procedure quanc8(  fun    : pointer;
          a,b,abserr,relerr : float;
              var result,
                  errest    : float;
              var nofun     : longint;
              var flag      : float);


  Procedure rkfs(  F                     : pointer;
                   neqn                  : integer;
              var  y                     : floatvector;
              var  t,tout, relerr,abserr : float;
              var  iflag                 : integer;
              var  yp                    : floatvector;
              var  h                     : float;
              var  f1, f2, f3, f4, f5    : floatvector;
              var  savre, savae          : float;
              var  nfe, kop, init,
                          jflag, kflag   : integer);

  Procedure rkf45( F             : pointer;
                   neqn          : integer;
           var     y             : floatvector;
           var     t,tout        : float;
           var     relerr,abserr : float;
           var     iflag         : integer;
           var     work          : rvecn;
           var     iwork         : ivec5);

function zeroin(       ax,bx,tol : float;
                       F         : pointer) : float;

function fmin(         ax,bx,tol : float;
                       F         : pointer) : float;

procedure SVD(
              m, n  : integer;
         var  a     : floatmatrixCS;
         var  w     : floatvectorC;
              matu  : boolean;
         var  u     : floatmatrixCS;
              matv  : boolean;
         var  v     : floatmatrixCS;
         var  Ierr  : integer;
         var  rv1   : floatvectorC);




  Function powri(    a      : float;
                     b      : integer) : float;
  Function powRR(    a      : float;
                     b      : float)   : float;
  function amax1(    a,b    : float)   : float;
  function amin1(    a,b    : float)   : float;
  function sign(     a,b    : float)   : float;
  function isign(    a,b    : integer) : integer;


  IMPLEMENTATION

Type   Floatworkrecord   = record
        yp           : floatvector;
        h            : float;
        f1           : floatvector;
        f2           : floatvector;
        f3           : floatvector;
        f4           : floatvector;
        f5           : floatvector;
        savre        : float;
        savae        : float;
                   end;
      Integerworkrecord  = record
        nfe, kop, init, jflag, kflag   : integer;
                           end;

{$F+}
{$L Initval.OBJ}
function UserFunction1(     X : float;
                     ProcAddr : Pointer) : float; external;

Procedure UserFunction2(    X : float;
                  var   Y, YP : floatvector;
                     ProcAddr : Pointer) ; external;

Function UserFunction3(     X : float;
                     ProcAddr : Pointer) : float; external;

function UserFunction4(     X : float;
                     ProcAddr : Pointer) : float; external;
{$F-}




Function powri(a:float;b:integer):float;
  var  h:float;
Begin
       if (a=0) then begin
                       if b = 0 then powri:=1
                                else powri:=0;
                       exit
                     end
                else
                     begin
                       h:=exp(b*ln(abs(a)));
                       if (odd(b))and(a<0) then powri:=-h
                                           else powri:=h;
                     end;
End;

Function powRR(a:float;b:float):float;
  var  h:float;
Begin
       if (a=0) then begin
                       if b = 0 then powrr:=1
                                else powrr:=0;
                       exit
                     end
                else
                     begin
                       powrr:=exp(b*ln(abs(a)));
                     end;
End;

    function amax1(a,b:float):float;
begin
  if a>=b then amax1:=a else amax1:=b
end;

function amin1(a,b:float):float;
begin
  if a<=b then amin1:=a else amin1:=b
end;


function sign(a,b:float):float;
begin
  if b=0 then sign:=0 else sign:=b/abs(b)*abs(a)
end;

function isign(a,b:integer):integer;
begin
  isign:=b div abs(b)  *  abs(a)
end;



  procedure DECOMP(
                   n  : integer;
             var   A  : floatmatrix ;
             var cond : float   ;
             var ipvt : ivector;
             var work : floatvector
                                   );
  VAR

	nm1,i,j,k,kp1,kb,km1,m  : integer;
	ek,t,anorm,ynorm,znorm  : float;
begin
	ipvt[n]:=1;
	if n = 1  then	begin
                          cond:=1.0;
                          if a[1,1] <> 0.0 then exit
                                           else begin
                                                  cond:=1.0e+32;
                                                  exit
                                                end
                        end;
	nm1:=n-1;
	anorm:=0.0;
	for j:=1 to n do begin
		              t:=0.0;
		              for i:=1 to n do  t:=t+abs(a[i,j]);
		              if t > anorm then anorm:=t;
                         end;
{do 35} for k:=1 to  nm1 do begin
            kp1:=k + 1;
            m:=k;
            for i:=kp1 to n do
                         if abs(a[i,k]) > abs(a[m,k]) then m:=i;
            ipvt[k]:=m;
            if m <> k then ipvt[n]:=-ipvt[n];
            t:=a[m,k];
            a[m,k]:=a[k,k];
            a[k,k]:=t;
            if t <>  0.0 then begin
{20}        for i:=kp1 to n do a[i,k]:=-a[i,k]/t;
{do 30}     for j:=kp1 to n do   begin
                                   t:=a[m,j];
	                           a[m,j]:=a[k,j];
	                           a[k,j]:=t;
	                           if t <> 0.0 then for i:=kp1 to n do
{25}                                          a[i,j]:=a[i,j] + a[i,k]*t;
{30}                              end;
{35}                           end;
                            end;
{do 50}for k:=1 to n do begin
		                   t:=0.0;
		                   if k <> 1 then begin
		                                    km1:=k-1;
		                                    for i:=1 to km1 do
                                                 t:=t + a[i,k] * work[i];
                                                  end;
{45}                               ek:=1.0;
             if t < 0.0 then ek:=-1.0;
             if a[k,k] = 0.0 then begin
                                    cond:=1.0E+32;
                                    exit
                                  end;
             work[k]:=-(ek+t)  / a[k,k];
{50}                    end;
{do 60}for kb:=1 to nm1 do begin
		k:=n-kb;
		t:=0.0;
		kp1:=k + 1;
		for i:=kp1 to n do t:=t + a[i,k] * work[k];
		work[k]:=t;
		m:=ipvt[k];
		if m <> k then begin
		                 t:=work[m];
		                 work[m]:=work[k];
		                 work[k]:=t
                               end;
{60}                       end;
	ynorm:=0.0;
	for i:=1 to n do  ynorm:=ynorm + abs(work[i]);
	solve(n,a,work,ipvt);
	znorm:=0.0;
	for i:=1 to n do znorm:=znorm + abs(work[i]);
	cond:=anorm*znorm/ynorm;
	if cond < 1.0	then cond:=1.0;
	exit
END;

  procedure SOLVE (
                   n  : integer;
             var   A  : floatmatrix ;
             var b    : floatvector;
             var ipvt : ivector
                                   );

VAR
        kb,km1,nm1,kp1,i,k,m     : integer;
        t                        : float;
 begin
	if n =1   then begin
                         b[1]:=b[1] / a[1,1];
                         exit
                       end;
	nm1:=n-1;
{do 20} for k:=1 to nm1 do begin
                             kp1:=k+1;
                             m:=ipvt[k];
                             t:=b[m];
                             b[m ]:=b[k];
                             b[k]:=t;
                             for i:=kp1 to n do b[i]:=b[i] + a[i,k]*t;
{20}                       end;
{do 40} for kb:=1 to nm1 do begin
                              km1:=n-kb;
                              k:=km1 + 1;
                              b[k]:=b[k]/a[k,k];
                              t:=-b[k];
                              for i:=1 to km1 do b[i]:=b[i] + a[i,k]*t;
{40}                        end;
          b[1]:=b[1] / a[1,1];
	end;


procedure LSTSQ( n, m  : integer;
          var    c     : floatmatrix;
          var    b, z  : floatvector;
          var    nisk,
                 maska : ivector;
          var    w     : floatvector      );

        {  n  - число строк матрицы С             }
        {  m  - число столбцов матрицы С          }
        {  C  - матрица системы                   }
        {  B  - вектор правых частей              }
        {  Z  - решение                           }
        {  nisk, maska, w - рабочие вектора       }

LABEL 13, 16, 18, 20, 28, 32;

VAR   i, j, j1, Imax, Jmax, l, m1, k    : integer;
      Amax, Pmax, a, s                  : float;

BEGIN
   for i:=1 to m do begin
                      nisk[i]:=0;
                      maska[i]:=1;
                    end;

   for l:=1 to m do begin                                   { do 100 }
     for j:= 1 to m do z[j]:=0;
     amax:=0;
     for i:= 1 to m do begin                                { do 3   }
       if maska[i] <> 0 then begin
                               Imax:=1;
                               Pmax:=abs(c[1,i]);
                               for j:=2 to n do             { do 5   }
                    if (Pmax <= abs(c[j,i])) then begin
                                                    Pmax:=abs(c[j,i]);
                                                    Imax:=j;
                                                  end;
                               s:=0;
                               for j:=1 to n do if j <> Imax then begin
                                        a:=c[j,i] / Pmax;
                                        s:=s + a*a;
                                                                  end;
                               s:=(s + 1.0) * Pmax * Pmax;
                               if Amax <= s then begin
                                                   Jmax:=i;
                                                   Amax:=s;
                                                 end;
                             end;                            {if maska}
                        end;                                 {  3     }
     nisk[Jmax]:=l;
     maska[Jmax]:=0;
     if amax = 0 then goto 28;
     z[Jmax]:=Amax;
     for i:=1 to m do begin                                  { do 10  }
                        if maska[i] <> 0 then begin
          for j:=1 to n do w[j]:=c[j,Jmax] * c[j,i];
          j1:=n;
16:       j:=1;
13:       w[j]:=w[j] + w[j1];
          inc(j);
          dec(j1);
          if j  < j1 then goto 13;
          if j1 >  1 then goto 16;
          z[i]:=w[1];
                                              end;           { if maska}
                      end;                                   { 10      }
     for j:=1 to n do w[j]:=c[j,Jmax] * b[j];                { 17      }
     j1:=n;
20:  j:=1;
18:  w[j]:=w[j] + w[j1];
     inc(j);
     dec(j1);
     if j  < j1 then goto 18;
     if j1 >  1 then goto 20;
     for i:=1 to m do if maska[i] <> 0 then z[i]:=z[i] / Amax; {22    }
     z[Jmax]:=w[1] / Amax;
     if l = m then goto 28;
     for i:=1 to m do if maska[i] <> 0 then for j:=1 to n do { 24     }
                     c[j,i]:=c[j,i] - z[i]*c[j,Jmax];
     for j:=1 to n do b[j]:=b[j] - z[Jmax]*c[j,Jmax];        { 27     }
28:  for i:=1 to n do c[i,Jmax]:=0.0;
     for i:=1 to m do c[i,Jmax]:=z[i];
   end;                                                      { 100    }
   if m = 1 then exit;
   maska[Jmax]:=1;
   m1:=m - 1;
   l:=m;
   for i:=1 to m1 do begin                                   { do 200 }
                       dec(l);
                       for j:= 1 to m do if nisk[j] = l then goto 32;
32: for k:=1 to m do if maska[k] <> 0 then c[j,j]:=c[j,j] - c[k,j]*z[k];
                       maska[j]:=1;
                       z[j]:=c[j,j];
                     end;                                    { 200    }
   exit;
end;


procedure Spline(n:integer; var x,y,b,c,d:floatvector);
label 10,20,30;
 var i,ib,nm1:integer;
     t:float;

   begin
    nm1:=n-1;
     if n < 2 then exit;
     if n < 3 then goto 20;
    d[1]:=x[2]-x[1];
    c[2]:=(y[2]-y[1])/d[1];
     for i:=2 to nm1 do
        begin
          d[i]:=x[i+1]-x[i];
          b[i]:=2*(d[i-1]+d[i]);
          c[i+1]:=(y[i+1]-y[i])/d[i];
          c[i]:=c[i+1]-c[i];
        end;
    b[1]:=-d[1];
    b[n]:=-d[n-1];
    c[1]:=0;
    c[n]:=0;
     if n = 3 then goto 10;
    c[1]:=c[3]/(x[4]-x[2])-c[2]/(x[3]-x[1]);
    c[n]:=c[n-1]/(x[n]-x[n-2])-c[n-2]/(x[n-1]-x[n-3]);
    c[1]:=c[1]*sqr(d[1])/(x[4]-x[1]);
    c[n]:=-c[n]*sqr(d[n-1])/(x[n]-x[n-3]);

10:    for i:=2 to n do
          begin
            t:=d[i-1]/b[i-1];
            b[i]:=b[i]-t*d[i-1];
            c[i]:=c[i]-t*c[i-1];
          end;
    c[n]:=c[n]/b[n];
      for ib:=1 to nm1 do
         begin
           i:=n-ib;
           c[i]:=(c[i]-d[i]*c[i+1])/b[i];
         end;

    b[n]:=(y[n]-y[nm1])/d[nm1]+d[nm1]*(c[nm1]+2*c[n]);
       for i:=1 to nm1 do
          begin
            b[i]:=(y[i+1]-y[i])/d[i]-d[i]*(c[i+1]+2*c[i]);
            d[i]:=(c[i+1]-c[i])/d[i];
            c[i]:=3*c[i];
          end;

     c[n]:=3*c[n];
     d[n]:=d[n-1];
     exit;
20:  b[1]:=(y[2]-y[1])/(x[2]-x[1]);
     c[1]:=0;
     d[1]:=0;
     b[2]:=b[1];
     c[2]:=0;
     d[2]:=0;

30: end; {Spline}

  function Seval(n:integer; var u:float;
                 var x,y,b,c,d:floatvector):float;
  label 10,20,30;
   var i,j,k:integer;
       dx:float;
   begin
   i:=1;
    if i >= n then i:=1;
     if u < x[i] then goto 10;
      if u <= x[i+1] then goto 30;

10: i:=1;
    j:=n+1;

20: k:=(i+j) div 2;
     if u < x[k] then j:=k;
      if u >= x[k] then i:=k;
       if j > (i+1) then goto 20;

30: dx:=u-x[i];
    Seval:=y[i]+dx*(b[i]+dx*(c[i]+dx*d[i]))

 end; {Seval}

Procedure quanc8(fun:pointer;a,b,abserr,relerr:float;var result,
                  errest:float;var nofun:longint;var flag:float);
label 72,90,30,50,62,60,70,75,80,82;
var
 w0,w1,w2,w3,w4,area,x0,f0,stone,step,cor11,temp : float;
 qprev,qnow,qdiff,qleft,esterr,tolerr            : float;
 f,x                                             : array [1..16] of float;
 fsave,xsave                                     : array [1..8,1..30] of float;
 qright                                          : array [1..31] of float;
 levmin,levmax,levout,nomax,nofin,lev,nim,i,j,
 kk,stepp                                        : longint;
begin
{writeln('Q8 start a,b,abserr,relerr,result,errest, nofun',
#13,#10,a,b,abserr,relerr,result,errest, nofun);}
 levmin:=1;
 levmax:=30;
 levout:=6;
 nomax:=5000;
 stepp:=1; for kk:=1 to levout+1 do stepp:=stepp*2;
 nofin:=nomax-8*(levmax-levout+stepp);
 w0:=3956.0/14175.0;
 w1:=23552.0/14175.0;
 w2:=-3712.0/14175.0;
 w3:=41984.0/14175.0;
 w4:=-18160.0/14175.0;
 flag:=0.0;
 result:=0.0;
 cor11:=0.0;
 errest:=0.0;
 area:=0.0;
 nofun:=0;
 if a=b then goto 90;{end procedure}
 lev:=0;
 nim:=1;
 x0:=a;
 x[16]:=b;
 qprev:=0.0;
 f0:=userfunction1(x0,fun);
 stone:=(b-a)/16.0;
 x[8]:=(x0+x[16])/2.0;
 x[4]:=(x0+x[8])/2.0;
 x[12]:=(x[8]+x[16])/2.0;
 x[2]:=(x0+x[4])/2.0;
 x[6]:=(x[4]+x[8])/2.0;
 x[10]:=(x[8]+x[12])/2.0;
 x[14]:=(x[12]+x[16])/2.0;
 j:=2;
 while j<=16 do begin
                 f[j]:=userfunction1(x[j],fun);
                 j:=j+2;
                end;
 nofun:=9;
30:  x[1]:=(x0+x[2])/2.0;
     f[1]:=userfunction1(x[1],fun);
     j:=3;
     while j<=15 do begin
                     x[j]:=(x[j-1]+x[j+1])/2.0;
                     f[j]:=userfunction1(x[j],fun);
                     j:=j+2;
                    end;
 nofun:=nofun+8;
 step:=(x[16]-x0)/16.0;
 qleft:=(w0*(f0+f[8])+w1*(f[1]+f[7])+w2*(f[2]+f[6])+w3*(f[3]+f[5])+w4*f[4])*step;
 qright[lev+1]:=(w0*(f[8]+f[16])+w1*(f[9]+f[15])+w2*(f[10]+f[14])+w3*(f[11]+f[13])+w4*f[12])*step;
 qnow:=qleft+qright[lev+1];
 qdiff:=qnow-qprev;
 area:=area+qdiff;
 esterr:=abs(qdiff)/1023.0;
 if abserr>=(relerr*abs(area)) then tolerr:=abserr*(step/stone)
                             else tolerr:=relerr*abs(area)*(step/stone);
 if lev<levmin then goto 50;
 if lev>=levmax then goto 62;
 if nofun>nofin then goto 60;
 if esterr<=tolerr then goto 70;
50: nim:=2*nim;
    lev:=lev+1;
    for i:=1 to 8 do begin
                      fsave[i,lev]:=f[i+8];
                      xsave[i,lev]:=x[i+8];
                     end;
 qprev:=qleft;
 for i:=-1 downto -8 do begin
                   f[2*i+18]:=f[i+9];
                   x[2*i+18]:=x[i+9];
                  end;
 goto 30;
60: nofin:=2*nofin;
    levmax:=levout;
    flag:=flag+(b-x0)/(b-a);
    goto 70;
62: flag:=flag+1.0;
70: result:=result+qnow;
    errest:=errest+esterr;
    cor11:=cor11+qdiff/1023.0;
72: if nim=2*(nim div 2) then goto 75;
               nim:=nim div 2;
               lev:=lev-1;
    goto 72;
75: nim:=nim+1;
if lev<=0 then goto 80;
 qprev:=qright[lev];
 x0:=x[16];
 f0:=f[16];
 for i:=1 to 8 do begin
                   f[2*i]:=fsave[i,lev];
                   x[2*i]:=xsave[i,lev];
                  end;
goto 30;
80: result:=result+cor11;
    if errest=0.0 then goto 90;{end procedure}
82: temp:=abs(result)+errest;
    if temp<>abs(result) then goto 90;
    errest:=2.0*errest;
    goto 82;
90: exit; end;


procedure fehl(                               F : pointer;
                                           neqn : integer;
               var                         t, h : float;
               var y, yp, f1, f2, f3, f4, f5, s : floatvector);

  var ch:float;
      k:integer;
Begin
  ch:=h/4;
  for k:=1 to neqn do f5[k]:=y[k]+ch*yp[k];
  UserFunction2(t+ch,f5,f1,F);
  ch:=3*h/32;
  for k:=1 to neqn do f5[k]:=y[k]+ch*(yp[k]+3*f1[k]);
  UserFunction2(t+3*h/8,f5,f2,F);
  ch:=h/2197;
  for k:=1 to neqn do f5[k]:=y[k]+ch*(1932*yp[k]+(7296*f2[k]-7200*f1[k]));
  UserFunction2(t+12*h/13,f5,f3,F);
  ch:=h/4104;
  for k:=1 to neqn do
  f5[k]:=y[k]+ch*((8341*yp[k]-845*f3[k]+(29440*f2[k]-32832*f1[k])));
  UserFunction2(t+h,f5,f4,F);
  ch:=h/20520;
  for k:=1 to neqn do
     f1[k]:=y[k]+ch*((-6080*yp[k]+(9295*f3[k]-5643*f4[k]))+(41040*f1[k]-
                  28352*f2[k]));
  UserFunction2(t+h/2,f1,f5,F);
  ch:=h/7618050;
  for k:=1 to neqn do
     s[k]:=y[k]+ch*((902880*yp[k]+(3855735*f3[k]-1371249*f4[k]))+
                     (3953664*f2[k]+277020*f5[k]))
End;

Procedure rkfs(  F                     : pointer;
                 neqn                  : integer;
            var  y                     : floatvector;
            var  t,tout, relerr,abserr : float;
            var  iflag                 : integer;
            var  yp                    : floatvector;
            var  h                     : float;
            var  f1, f2, f3, f4, f5    : floatvector;
            var  savre, savae          : float;
            var  nfe, kop, init,
                        jflag, kflag   : integer);

  label 5,10,20,25,30,40,45,50,55,60,65,70,80,85,
        95,100,150,200,220,240,260,300,400;

Const remin : float = 1.e-12;
      eps   : float = 1.;
      u26   : float = 26.;
 fierstcall : boolean = true;
  var hf,out:boolean;
      a, ae, dt, ee, eeoet, esttol,
      et, hmin, rer, s, scale, tol,
      toln,  epsp1,  ypk                     :  float;
      k, mflag                               :  integer;

Begin                                             {  RKFS  }
    if neqn<1 then goto 10;
    if (relerr<0)or(abserr<0) then goto 10;
    mflag:=abs(iflag);
    if (mflag=0)or(mflag>8)then goto 10;
    if mflag<>1 then goto 20;
    if fierstcall then begin
5:                       eps:=eps/2.;
                         epsp1:=eps+1.;
                         if epsp1 > 1. then goto 5;
                         u26:=26. * eps;
                         fierstcall:=false;
                         goto 50;
                       end
                  else goto 50;
 10:iflag:=8;
    exit;
 20:if (t=tout) and (kflag<>3) then goto 10;
    if mflag<>2 then goto 25;
    if (kflag=3) or (init=0) then goto 45;
    if kflag=4 then goto 40;
    if (kflag=5) and (abserr=0) then goto 30;
    if (kflag=6) and (relerr<=savre) and (abserr<=savae) then goto 30;
    goto 50;
 25:if iflag=3 then goto 45;
    if iflag=4 then goto 40;
    if (iflag=5)and(abserr>0) then goto 45;
 30:writeln;
    writeln('Интегpиpование пpеpвано, т.к. не выполнена инстpукция');
    writeln('соответствующая IFLAG = 5-8');
    halt(1);
 40:nfe:=40;
    if mflag=2 then goto 50;
 45:iflag:=jflag;
    if kflag=3 then mflag:=abs(iflag);
 50:jflag:=iflag;
    kflag:=0;
    savre:=relerr;
    savae:=abserr;
    rer:=2*eps+remin;
    if (relerr>=rer) then goto 55;
    relerr:=rer;
    iflag:=3;
    kflag:=3;
    exit;
 55:dt:=tout-t;
    if mflag=1 then goto 60;
    if init=0 then goto 65;
    goto 80;
 60:init:=0;
    kop:=0;
    a:=t;
    userfunction2(a,y,yp,F);
    nfe:=1;
    if t<>tout then goto 65;
    iflag:=2;
    exit;
 65:init:=1;
    h:=abs(dt);
    toln:=0;
    for k:=1 to neqn do begin
                          tol:=relerr*abs(y[k])+abserr;
                          if (tol > 0) then begin
                                              toln:=tol;
                                              ypk:=abs(yp[k]);
                                              if (ypk*powri(h,5) > tol) then
                                                    h:=powrr(tol/ypk,0.2);
                                            end;
70:                     end;
    if toln<=0 then h:=0;
    h:=amax1(h,u26*amax1(abs(t),abs(dt)));
    jflag:=isign(2,iflag);
 80:h:=sign(h,dt);
    if (abs(h)>=2*abs(dt)) then inc(kop);
    if kop<>100 then goto 85;
    kop:=0;
    iflag:=7;
    exit;
 85:if (abs(dt)>u26*abs(t))then goto 95;
    for k:=1 to neqn do y[k]:=y[k]+dt*yp[k];
    a:=tout;
    userfunction2(a,y,yp,F);
    inc(nfe);
    goto 300;
 95:out:=false;
    scale:=2/relerr;
    ae:=scale*abserr;
100:hf:=false;
    hmin:=u26*abs(t);
    dt:=tout-t;
    if (abs(dt)>= 2*abs(h)) then goto 200;
    if (abs(dt)>abs(h)) then goto 150;
    out:=true;
    h:=dt;
    goto 200;
150:h:=0.5*dt;
200:if nfe<=maxnfe then goto  220;
    iflag:=4;
    kflag:=4;
    exit;
220:fehl(F,neqn,t,h,y,yp,f1,f2,f3,f4,f5,f1);
    inc(nfe,5);
    eeoet:=0;
    for k:=1 to neqn do begin
                          et:=abs(y[k]+abs(f1[k]))+ae;
                          if et>0 then goto 240;
                          iflag:=5;
                          kflag:=5;
                          exit;
240:                      ee:=abs((-2090*yp[k]+(21970*f3[k]-15048*f4[k]))
                                      + (22528*f2[k]-27360*f5[k]));
                          eeoet:=amax1(eeoet,ee/et)
                        end;
    esttol:=abs(h)*eeoet*scale/752400;
    if esttol<=1 then goto 260;
    hf:=true;
    out:=false;
    s:=0.1;
    if esttol<59049 then s:=0.9/powrr(esttol,0.2);
    h:=s*h;
    if abs(h)>hmin then goto 200;
    iflag:=6;
    kflag:=6;
    exit;
260:t:=t+h;
    for k:=1 to neqn do y[k]:=f1[k];
    a:=t;
    userfunction2(a,y,yp,F);
    inc(nfe);
    s:=5;
    if (esttol>1.889568E-4) then s:=0.9/powrr(esttol,0.2);
    if hf  then s:=amin1(s,1.0);
    h:=sign(amax1(s*abs(h),hmin),h);
    if out then goto 300;
    if iflag>0 then goto 100;
    iflag:=-2;
    exit;
300:t:=tout;
    iflag:=2;
    exit;
end;                                                { RKFS }

Procedure rkf45( F             : pointer;
                 neqn          : integer;
         var     y             : floatvector;
         var     t,tout        : float;
         var     relerr,abserr : float;
         var     iflag         : integer;
         var     work          : rvecn;
         var     iwork         : ivec5);

  var      fwr : floatworkrecord   absolute work;
           iwr : integerworkrecord absolute iwork;
  begin     {rkf45}
    rkfs(F, neqn, y, t, tout, relerr, abserr, iflag,
    fwr.yp, fwr.h, fwr.f1, fwr.f2, fwr.f3, fwr.f4, fwr.f5,
    fwr.savre, fwr.savae,
    iwr.nfe, iwr.kop, iwr.init, iwr.jflag, iwr.kflag);
  end;

function zeroin(ax,bx,tol : float; F : pointer) : float;

Label 10, 20, 30, 40, 50, 60, 70, 80, 90;
Const fierstcall : boolean = true;
      eps        : float   = 1.0;
var      a,b,c,d,e,fa,fb,fc,tol1,xm,p,q,r,s : float;
Begin
    if fierstcall then begin
10:                      eps:=eps/2.0;
                         tol1:=1.0+eps;
                         if(tol1 > 1.0)  then goto 10;
                       end;
    a:=ax;
    b:=bx;
    fa:=userfunction3(a,F);
    fb:=userfunction3(b,F);
20: c:=a;
    fc:=fa;
    d:=b-a;
    e:=d;
30: if(abs(fc) >= abs(fb)) then goto 40;
    a:=b;
    b:=c;
    c:=a;
    fa:=fb;
    fb:=fc;
    fc:=fa;
40: tol1:=2.0*eps*abs(b)+0.5*tol;
    xm:=0.5*(c-b);
    if(abs(xm) <= tol1)  then goto 90;
    if(fb = 0.0)  then goto 90;
    if(abs(e) < tol1)  then goto 70;
    if(abs(fa) <= abs(fb))  then goto 70;
    if(a <> c)  then goto 50;
    s:=fb/fa;
    p:=2.0*xm*s;
    q:=1.0-s;
    goto 60;
50: q:=fa/fc;
    r:=fb/fc;
    s:=fb/fa;
    p:=s*(2.0*xm*q*(q-r)-(b-a)*(r-1.0));
    q:=(q-1.0)*(r-1.0)*(s-1.0);
60: if(p > 0.0) then q:=-q;
    p:=abs(p);
    if((2.0*p) >= (3.0*xm*q-abs(tol1*q)))  then goto 70;
    if(p >= abs(0.5*e*q))  then goto 70;
    e:=d;
    d:=p/q;
    goto 80;
70: d:=xm;
    e:=d;
80: a:=b;
    fa:=fb;
    if(abs(d) > tol1)  then b:=b+d;
    if(abs(d) <= tol1)  then b:=b+sign(tol1,xm);
    fb:=userfunction3(b,F);
    if((fb*(fc/abs(fc))) > 0.0)  then goto 20;
    goto 30;
90: zeroin:=b;
end;


function fmin(ax,bx,tol : float; F : pointer) : float;
label 10, 20, 30, 40, 50, 60, 70, 80, 90;
const
            fierstcall                  :  boolean = true;
            eps                         :  float   = 1;
            c                           :  float   = 1;
Var
 a,b,  d,e,    xm,p,q,r,tol1,tol2,u,v,w :  float;
            fu,fv,fw,fx,x               :  float;

Begin
 if fierstcall then begin
                      c:=0.5*(3.0-sqrt(5.0));
                      eps:=1.0;
10:                   eps:=eps/2.0;
                      tol1:=1.0+eps;
                      if(tol1 > 1.0) then goto 10;
                      eps:=sqrt(eps);
                      fierstcall:=false;
                    end;
    a:=ax;
    b:=bx;
    v:=a+c*(b-a);
    w:=v;
    x:=v;
    e:=0.0;
    fx:=userfunction3(x,F);
    fv:=fx;
    fw:=fx;
20: xm:=0.5*(a+b);
    tol1:=eps*abs(x)+tol/3.0;
    tol2:=2.0*tol1;
    if (abs(x-xm) <= (tol2-0.5*(b-a))) then goto 90;
    if (abs(e) <=  tol1) then goto 40;
    r:=(x-w)*(fx-fv);
    q:=(x-v)*(fx-fw);
    p:=(x-v)*q-(x-w)*r;
    q:=2.0*(q-r);
    if(q > 0.0) then p:=-p;
    q:=abs(q);
    r:=e;
    e:=d;
30: if(abs(p) >= abs(0.5*q*r)) then goto 40;
    if(p <= q*(a-x))  then goto 40;
    if(p >=q*(b-x))  then goto 40;
    d:=p/q;
    u:=x+d;
    if((u-a) < tol2)  then d:=sign(tol1,xm-x);
    if((b-u) < tol2)  then d:=sign(tol1,xm-x);
    goto 50;
40: if(x >=xm)  then e:=a-x;
    if(x < xm) then e:=b-x;
    d:=c*e;
50: if(abs(d) >=tol1)  then u:=x+d;
    if(abs(d) < tol1) then  u:=x+sign(tol1,d);
    fu:=userfunction3(u,F);
    if(fu > fx)  then goto 60;
    if(u >=x)  then a:=x;
    if(u < x)  then b:=x;
    v:=w;
    fv:=fw;
    w:=x;
    fw:=fx;
    x:=u;
    fx:=fu;
    goto 20;
60: if(u < x)  then a:=u;
    if(u >=x)  then b:=u;
    if(fu <= fw)  then goto 70;
    if(w = x)  then goto 70;
    if(fu <= fv)  then goto 80;
    if(v = x)  then goto 80;
    if(v = w)  then goto 80;
    goto 20;
70: v:=w;
    fv:=fw;
    w:=u;
    fw:=fu;
    goto 20;
80: v:=u;
    fv:=fu;
    goto 20;
90: fmin:=x;
    exit;
end;


procedure SVD(
              m, n  : integer;
         var  a     : floatmatrixCS;
         var  w     : floatvectorC;
              matu  : boolean;
         var  u     : floatmatrixCS;
              matv  : boolean;
         var  v     : floatmatrixCS;
         var  Ierr  : integer;
         var  rv1   : floatvectorC);

Label 190, 210, 270, 290, 360, 390, 410, 430, 460, 475, 490,
      510, 520, 540, 565, 650, 575, 1000;
VAR       i,j,k,l,ii,i1,kk,k1,ll,l1,mn,nm,its   : integer;
          c,f,g,h,s,x,y,z,scale,anorm           : float;
Begin
ierr:=0;
for i:=1 to m do for j:=1 to n do u[i,j]:=a[i,j];
g:=0.0; scale:=0.0; anorm:=0.0;
for i:=1 to n do begin                 { do 300 }
                   l:=i+1; rv1[i]:=scale*g;
                   g:=0.0; s:=0.0; scale:=0.0;
                   if(i > m) then goto 210;
                   for k:=i to m do scale:=scale+abs(u[k,i]);
                   if(scale = 0.0) then goto  210;
                   for k:=i to m do begin
                                      u[k,i]:=u[k,i]/scale;
                                      s:=s+sqr(u[k,i]);
                                    end;
                   f:=u[i,i];
                   g:=-sign(sqrt(s),f);
                   h:=f*g-s;
                   u[i,i]:=f-g;
                   if(i = n) then goto  190;
{do 150}           for j:=l to n do begin
                                      s:=0.0;
                                      for k:=i to m do s:=s+u[k,i]*u[k,j];
                                      f:=s/h;
                                      for k:=i to m do u[k,j]:=u[k,j]+f*u[k,i];
                                    end;
190:               for k:=i to m do u[k,i]:=scale*u[k,i];
210:               w[i]:=scale*g;
                   g:=0.0; s:=0.0; scale:=0.0;
                   if(i > m) or (i = n) then goto  290;
                   for k:=l to n do  scale:=scale+abs(u[i,k]);
                   if(scale = 0.0) then goto  290;
                   for k:=l to n do begin
                                      u[i,k]:=u[i,k]/scale;
                                      s:=s+sqr(u[i,k]);
                                    end;
                   f:=u[i,l];
                   g:=-sign(sqrt(s),f);
                   h:=f*g-s;
                   u[i,l]:=f-g;
                   for k:=l to n do rv1[k]:=u[i,k]/h;
                   if(i = m) then goto  270;
                   for j:=l to m do begin            {do 260}
                                      s:=0.0;
                                      for k:=l to n do s:=s+u[j,k]*u[i,k];
                                      for k:=l to n do u[j,k]:=u[j,k]+s *
                                                              rv1[k];
{260}                               end;
270:               for k:=l to n do u[i,k]:=scale*u[i,k];
290:               anorm:=amax1(anorm,abs(w[i])+abs(rv1[i]));
     { 300 }     end;

if (not matv) then goto  410;
for ii:=1 to n do begin               { do 400 }
                    i:=n+1-ii;
                    if i = n then goto  390;
                    if g = 0 then goto  360;
                    for j:=l to n do v[j,i]:=(u[i,j]/u[i,l])/g;
{ do 350 }          for j:=l to n do begin
                                       s:=0.0;
                                       for k:=l to n do s:=s+u[i,k]*v[k,j];
                                       for k:=l to n do v[k,j]:=v[k,j]+s*v[k,i];
{    350 }                           end;
360:                for j:=l to n do begin               {do 380}
                                       v[i,j]:=0.0;
                                       v[j,i]:=0.0;
{380}                                end;
390:                v[i,i]:=1.0;
                    g:=rv1[i];
                    l:=i;
{   400 }         end;
410:
if( not matu) then goto  510;
mn:=n;
if m < n then mn:=m;
for ii:=1 to mn do begin            { do 500 }
                     i:=mn+1-ii;
                     l:=i+1;
                     g:=w[i];
                     if i = n  then goto 430;
                     for j:=l  to n do u[i,j]:=0;
430:                 if g = 0  then goto  475;
                     if i = mn then goto  460;
                     for j:=l to n do begin         { do 450 }
                                        s:=0.0;
                                        for k:=l to m do s:=s+u[k,i]*u[k,j];
                                        f:=(s/u[i,i])/g;
                                        for k:=i to m do u[k,j]:=u[k,j]+f*u[k,i];
{ 450 }                               end;
460:                 for j:=i to m do  u[j,i]:=u[j,i]/g;
                     goto  490;
475:                 for j:=i to m do u[j,i]:=0;
490:                 u[i,i]:=u[i,i]+1.0;
{ 500 }            end;

510:
for kk:=1 to n do begin     {do 700}
                    k1:=n-kk;
                    k:=k1+1;
                    its:=0;
520:                for ll:=1 to k do begin   {do 530}
                                        l1:=k-ll;
                                        l:=l1+1;
                                        if abs(rv1[l])+anorm = anorm
                                                       then  goto  565;
                                        if abs(w[l1])+anorm  = anorm
                                                       then  goto  540;
{ 530 }                               end;
540:                c:=0.0;
                    s:=1.0;
                    for i:=l to k do begin        {do 560}
                                       f:=s*rv1[i];
                                       rv1[i]:=c*rv1[i];
                                       if abs(f)+anorm = anorm
                                                       then goto  565;
                                       g:=w[i];
                                       h:=sqrt(f*f+g*g);
                                       w[i]:=h;
                                       c:=g/h;
                                       s:=-f/h;
                                       if matu then
                                          for j:=1 to m do begin {do 550}
                                                      y:=u[j,l1];
                                                      z:=u[j,i];
                                                      u[j,l1]:=y*c+z*s;
                                                      u[j,i]:=-y*s+z*c;
{ 550 }                                                    end;
{ 560 }                              end;
565:                z:=w[k];
                    if l = k then goto  650;
                    if its = 30 then goto  1000;
                    inc(its);
                    x:=w[l];
                    y:=w[k1];
                    g:=rv1[k1];
                    h:=rv1[k];
                    f:=((y-z)*(y+z)+(g-h)*(g+h))/(2.0*h*y);
                    g:=sqrt(f*f+1.0);
                    f:=((x-z)*(x+z)+h*(y/(f+sign(g,f))-h))/x;
                    c:=1.0;
                    s:=1.0;
                    for i1:=l to k1 do begin  { do 600}
                                         i:=i1+1;
                                         g:=rv1[i];
                                         y:=w[i];
                                         h:=s*g;
                                         g:=c*g;
                                         z:=sqrt(f*f+h*h);
                                         rv1[i1]:=z;
                                         c:=f/z;
                                         s:=h/z;
                                         f:=x*c+g*s;
                                         g:=-x*s+g*c;
                                         h:=y*s;
                                         y:=y*c;
{do 570}                                 if  matv then for j:=1 to n do begin
                                                x:=v[j,i1];
                                                z:=v[j,i];
                                                v[j,i1]:=x*c+z*s;
                                                v[j,i]:=-x*s+z*c;
{570}                                                                   end;
575:                                     z:=sqrt(f*f+h*h);
                                         w[i1]:=z;
                                         if z <> 0 then begin
                                                          c:=f/z;
                                                          s:=h/z;
                                                        end;
                                         f:=c*g+s*y;
                                         x:=-s*g+c*y;
 { do 590}                               if matu then
                                                 for j:=1 to m do begin;
                                            y:=u[j,i1];
                                            z:=u[j,i];
                                            u[j,i1]:=y*c+z*s;
                                            u[j,i]:=-y*s+z*c;
{590}                                                             end;
{600}                                  end;
                   rv1[l]:=0.0;
                   rv1[k]:=f;
                   w[k]:=x;
                   goto  520;
650:               if z < 0 then begin
                                   w[k]:=-z;
                                   if matv then
                                     for j:=1 to n do v[j,k]:=-v[j,k];
                                 end;
{700}             end;
exit;
1000:
ierr:=k;
End;
END.