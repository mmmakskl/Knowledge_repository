-------------------------------------------------------------------
		ForsytheLib v 0.1 beta 5
	Проги из Форсайтовского пакета, переписаные с Fortran'а на С++
	
	Copyright (c) 2002 Eugene S.B.

	If you find any bugs in this program, please, contact me.
	E-Mail esb@hotbox.ru
-------------------------------------------------------------------

#ifndef __FORSYTHE_H__
#define __FORSYTHE_H__

#include float.h

#define FT_FLOAT	0	'float'
#define FT_DOUBLE	1	'double'
#define FT_LDOUBLE	2	'long double'

Здесь можно переопределить вещественный тип, который будет использоваться в вычислениях.
Если важна скорость - используйте 'float' (т.е. FT_FLOAT), если нужна точность - используйте 'double' (FT_DOUBLE)
или 'long double' (FT_LDOUBLE).
#define FLOATTYPE	FT_DOUBLE

#if FLOATTYPE == FT_FLOAT
	typedef float Float;
	#define EPSILON FLT_EPSILON
	#define MAXIMUM FLT_MAX
#elif FLOATTYPE == FT_DOUBLE
	typedef double Float;
	#define EPSILON DBL_EPSILON
	#define MAXIMUM DBL_MAX
#elif FLOATTYPE == FT_LDOUBLE
	typedef long double Float;
	#define EPSILON LDBL_EPSILON
	#define MAXIMUM LDBL_MAX
#else
	#error Invalid Float Type
#endif

Некоторые полезные макросы
#define ABS(x) (((x) = 0)  (x)  -(x))
#define MAX(x, y) (((x) = (y))  (x)  (y))
#define MIN(x, y) (((x)  (y))  (x)  (y))
#define SIGN0(x) (((x)  0)  1  -1)
#define SIGN(x) (((x) == 0)  0  SIGN0(x))
#define SIGN2(a, b) (SIGN(b)ABS(a))

Структура для входных и выходных параметров rkf45
struct rkf
{
	void (f)(Float t, Float Y, Float dY);
	Float Y, t, tout, re, ae;
	unsigned int neqn;
	int flag;
	unsigned char work;по этому указателю необходимо выделить '6neqnsizeof(Float) + sizeof(struct rkf_inside)' байт
};

Константы для управления работой rkf45

	REMin - это минимальное допустимое значение для относительной погрешности (re). Попытки запросить у
функции более высокую точность обычно неэффективны, и поэтому должны избегаться.
#define REMIN (1.0e-12) Relative error minimum

	Максимальное допустимое значение колличества вычислений производных (т.е. колличество вычислений функции f)
Принятое здесь значение соответствует примерно 5000 шагам
#define MAXNFE 30000 Maximum number of Function E...

 Структура для внутреннего использования в rkf45 
		Eё наиболее интересные поля
 h	-	предполагаемых размер шага для очередного этапа
 nfe	-	счётчик числа вычислений функции
struct rkf_inside
{
	unsigned long nfe, kop, init;
	int JFlag, KFlag;
	Float h, SaveRE, SaveAE;
};
		Если вас интересуют значения полей данной структуры после работы rkf45,
 то их можно получить через указатель work в 'struct rkf', например

	struct rkf_inside p;
	struct rkf RKF;
	unsigned char work[6(NEQNsizeof(Float)) + sizeof(struct rkf_inside)];
	...
	RKF.f = ...
	RKF.t = ...
	RKF.work = work;
	...
	rkf45(&RKF);
	p = (struct rkf_inside )RKF.work;
	... = p-nfe;
	... = p-h;
	...
 

 Метод Рунге-Кутта Фельберга 4-5 порядка 
	По сравнению с оригинальной версией этой программы (Фортрановской) сделаны некоторые изменения
		- при многократных вызовах rkf45 на скорость сильно влияет колличество параметров функции,
 поэтому здесь параметр только 1. Тем не менее все оригинальные параметры находятся в структуре struct rkf.
		- Фортрановские параметры WORK и IWORK объединены в 1 (work; см. описание struct rkf)
		- При нормальной работе функция возвращает false. В случае же фатальных ошибок будет возвращено true.
		!!!!!!  Следует учитывать, что если даже rkf45 вернула false, то из этого не следует, что всё нормально - нужно
 обязательно проверить значение флага на выходе, только тогда можно будет убедиться, что интегрирование завершилось успешно.
 Данный механизм кажется мне более гибким, чем тот который предложен первоначальными авторами (в старой версии
 при возникновении фатальных ошибок завершалась вся программа, не давая программисту возможности обработать данную ситуацию)

Copyright (c) 1976 H.A.Watts, L.F.Shampine (Sandia Laboratories, Albuquerque, New Mexico)
bool rkf45(struct rkf p);

Copyright (c) 1973 Ricard Brent
Float FMin(Float (F)(Float), Float a, Float b, Float tol);
Float Zeroin(Float (F)(Float), Float a, Float b, Float tol);

Float Quanc8(Float (F)(Float), Float a, Float b, Float ae, Float re, Float errest, int nofun, Float flag);
void Decomp(unsigned int n, Float A, Float cond, int ipvt);
void Solve(unsigned int n, Float A, Float b, int ipvt);
void Spline(unsigned int n, Float X, Float Y, Float B, Float C, Float D);
Float SEval(unsigned int n, Float u, Float X, Float Y, Float B, Float C, Float D);

#endif __FORSYTHE_H__