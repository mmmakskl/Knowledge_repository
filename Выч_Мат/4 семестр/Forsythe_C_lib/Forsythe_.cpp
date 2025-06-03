#include "Forsythe.h"
#include <math.h>
#include <cstdlib>
#include <cstdio>
#include <conio.h>

#include <iostream>
#include <fstream>

using namespace std;

inline void fehl(void (*f)(Float t, Float *Y, Float *dY), unsigned int neqn, Float *Y, Float t, Float h, Float *dY,
			Float *F1, Float *F2, Float *F3, Float *F4, Float *F5, Float *S)
{
	Float ch;
	unsigned int k;

	ch = h/(Float)4;
	for(k=0;k<neqn;k++) F5[k] = Y[k] + ch*dY[k];
	f(t+ch, F5, F1);

	ch = (Float)3*h/(Float)32;// 3*h/32
	for(k=0;k<neqn;k++) F5[k] = Y[k] + ch*(dY[k] + (Float)3*F1[k]);
	f(t+(Float)3*h/(Float)8, F5, F2);

	ch = h/(Float)2197;// h/2197
	for(k=0;k<neqn;k++) F5[k] = Y[k] + ch*((Float)1932*dY[k] + ((Float)7296*F2[k] - (Float)7200*F1[k]));
	f(t+(Float)12*h/(Float)13, F5, F3);

	ch = h/(Float)4104;// h/4104
	for(k=0;k<neqn;k++) F5[k] = Y[k] + ch*(((Float)8341*dY[k] - (Float)845*F3[k]) +
									((Float)29440*F2[k] - (Float)32832*F1[k]));
	f(t+h, F5, F4);

	ch = h/(Float)20520;// h/20520
	for(k=0;k<neqn;k++) F1[k] = Y[k] + ch*(((Float)(-6080)*dY[k] + ((Float)9295*F3[k] - (Float)5643*F4[k])) +
									((Float)41040*F1[k] - (Float)28352*F2[k]));
	f(t+h/(Float)2, F1, F5);

	//Âû÷èñëèòü ïðèáëèæ¸ííîå ðåøåíèå â òî÷êå t+h
	ch = h/(Float)7618050;
	for(k=0;k<neqn;k++) S[k] = Y[k] + ch*(((Float)902880*dY[k] + ((Float)3855735*F3[k] - (Float)1371249*F4[k])) +
									((Float)3953664*F2[k] + (Float)277020*F5[k]));
}

bool rkf45(struct rkf *p)
{
	struct rkf_inside *w;
	Float *dY, *F1, *F2, *F3, *F4, *F5,
			dt, u26, rer, scale, ae, hmin, eeoet, esttol, s;
	unsigned int MFlag, k;
	bool output, hfaild;

	//Ïðîâåðÿåì âõîäíûå ïàðàìåòðû
	if(p->neqn < 1 || p->re < (Float)0 || p->ae < (Float)0 || p->flag == 0 || p->flag < -2 || p->flag > 8)
	{
		p->flag = 8;//Îøèáêà âõîäíîé èíôîðìàöèè
		return false;
	}

	MFlag = ABS(p->flag);
	w = (struct rkf_inside *)p->work;
	dY = (Float *)(p->work + sizeof(struct rkf_inside));
	F1 = dY + p->neqn;
	F2 = F1 + p->neqn;
	F3 = F2 + p->neqn;
	F4 = F3 + p->neqn;
	F5 = F4 + p->neqn;

	if(MFlag != 1)//Åñëè ýòî óæå íå ïåðâîå îáðàùåíèå ê rkf45
	{
		//Ïðîâåðèòü âîçìîæíîñòü ïðîäîëæåíèÿ
		if(p->t == p->tout && w->KFlag != 3)
		{
			p->flag = 8;//Îøèáêà âõîäíîé èíôîðìàöèè
			return false;
		}
		if(MFlag != 2)
		{//p->flag = 3,4,5,6,7 èëè 8
			if(p->flag != 3)
			{
				if(p->flag == 4) w->nfe = 0;
				else if(p->flag != 5 || p->ae <= 0) return true;//Èíòåãðèðîâàíèå íåëüçÿ ïðîäîëæàòü, ò.ê.
				//ïîëüçîâàòåëü íå âûïîëíèë èíñòðóêöèé, ñîîòâåòñòâóþùèõ çíà÷åíèÿì p->flag = 5,6,7 èëè 8
			}
			//Ïåðåîïðåäåëèòü çíà÷åíèå p->flag, óñòàíîâëåííîå ïðè ïðåäûäóùåì îáðàùåíèè
			p->flag = w->JFlag;
			if(w->KFlag == 3) MFlag = ABS(w->JFlag);
		}
		else
		{//p->flag = +2 èëè -2
			if(w->KFlag == 3 || w->init == 0)
			{
				//Ïåðåîïðåäåëèòü çíà÷åíèå p->flag, óñòàíîâëåííîå ïðè ïðåäûäóùåì îáðàùåíèè
				p->flag = w->JFlag;
				if(w->KFlag == 3) MFlag = ABS(w->JFlag);
			}
			else
			{
				if(w->KFlag == 4) w->nfe = 0;
				else if(w->KFlag == 5){if(p->ae == 0.0) return true;}
				else if(w->KFlag == 6 && p->re <= w->SaveRE && p->ae <= w->SaveAE) return true;
			}
		}
	}

	//Ñîõðàíèòü âõîäíîå çíà÷åíèå p->flag è óñòàíîâèòü çíà÷åíèå FLAG, ñîîòâåòñòâóþùåå ïðîäîëæåíèþ, äëÿ áóäóùåé ïðîâåðêè
	w->JFlag = p->flag;
	w->KFlag = 0;
	//Ñîõðàíèòü çíà÷åíèÿ p->re & p->ae äëÿ âõîäíîé ïðîâåðêè ïðè ïîñëåäóþùèõ îáðàùåíèÿõ
	w->SaveRE = p->re;
	w->SaveAE = p->ae;

	rer = (Float)2*(Float)EPSILON + (Float)REMIN;
	u26 = (Float)26*(Float)EPSILON;

	if(p->re < rer)
	{
		p->flag = w->KFlag = 3;
		p->re = rer;
		return false;
	}

	dt = p->tout - p->t;

	if(MFlag == 1 || w->init == 0)
	{
		Float temp;
		bool toln;
		if(MFlag == 1)
		{
			w->kop = 0;
			p->f(p->t, p->Y, dY);
			w->nfe = 1;
			if(p->t == p->tout)
			{
				w->init = 0;
				p->flag = 2;
				return false;
			}
		}

		w->init = 1;
		w->h = ABS(dt);
		toln = false;
		for(k = 0; k < p->neqn; k++)
		{
			Float tol;
			tol = p->re*ABS(p->Y[k]) + p->ae;
			if(tol > 0)
			{
				Float ypk;
				toln = true;
				ypk = ABS(dY[k]);
				if(ypk*w->h*w->h*w->h*w->h*w->h > tol) w->h = (Float)pow(tol/ypk, 0.2);
			}
			else break;
		}
		temp = u26*MAX(ABS(p->t), ABS(dt));
		if(!toln || w->h < temp) w->h = temp;
		w->JFlag = (p->flag > 0) ? 2 : -2;
	}

	w->h = SIGN2(w->h, dt);
	if(ABS(w->h) >= 2.0*ABS(dt)) w->kop++;
	if(w->kop == 100)
	{
		w->kop = 0;
		p->flag = 7;
		return false;
	}

	if(ABS(dt) <= u26*ABS(p->t))
	{
		for(k = 0;k < p->neqn;k++)
		{
			p->Y[k] += dt*dY[k];
			p->f(p->tout, p->Y, dY);
			w->nfe++;
		}
		p->t = p->tout;
		p->flag = 2;
		return false;
	}

	output = false;
	scale = (Float)2/p->re;
	ae = scale*p->ae;

	do
	{
		hfaild = false;
		hmin = u26*ABS(p->t);
		dt = p->tout - p->t;

		if(ABS(dt) < 2.0*ABS(w->h))
		{
			if(ABS(dt) > ABS(w->h)) w->h = dt/(Float)2;
			else
			{
				output = true;
				w->h = dt;
			}
		}

		while(1)
		{
			if(w->nfe > MAXNFE)
			{
				p->flag = w->KFlag = 4;
				return false;
			}

			fehl(p->f, p->neqn, p->Y, p->t, w->h, dY, F1, F2, F3, F4, F5, F1);
			w->nfe += 5;
			eeoet = 0.0;

			for(k=0;k<p->neqn;k++)
			{
				Float et;
				et = ABS(p->Y[k]) + ABS(F1[k]) + ae;
				if(et > 0.0)
				{
					Float ee;
					ee = ABS(((Float)(-2090)*dY[k]+((Float)21970*F3[k]-(Float)15048*F4[k]))+((Float)22528*F2[k]-(Float)27360*F5[k]))/et;
					if(eeoet < ee) eeoet = ee;
				}
				else
				{
					p->flag = w->KFlag = 5;
					return false;
				}
			}

			esttol = ABS(w->h)*eeoet*scale/(Float)752400;

			if(esttol <= (Float)1) break;

			hfaild = true;
			output = false;
			s = (Float)0.1;
			if(esttol < (Float)59049) s = (Float)0.9/(Float)pow(esttol, 0.2);
			w->h *= s;
			if(ABS(w->h) <= hmin)
			{
				p->flag = w->KFlag = 6;
				return false;
			}
		}

		p->t += w->h;
		for(k=0;k<p->neqn;k++) p->Y[k] = F1[k];
		p->f(p->t, p->Y, dY);
		w->nfe++;

		s = 5.0;
		if(esttol > (Float)1.889568e-4) s = (Float)0.9/(Float)pow(esttol, 0.2);
		if(hfaild) s = MIN(s, (Float)1.0);

		if(w->h != 0) if(w->h > 0) w->h = ABS(MAX(s*w->h, hmin));
						else w->h = -ABS(MAX(-s*w->h, hmin));

		if(output)
		{
			p->t = p->tout;
			p->flag = 2;
			return false;
		}
	}while(p->flag > 0);

	p->flag = -2;
	return false;
}

Float FMin(Float (*F)(Float), Float a, Float b, Float tol)
{
	Float c = (Float)((Float)3.0-(Float)sqrt(5.0))/(Float)2,//ñ - ýòî âîçâåä¸ííàÿ â êâàäðàò âåëè÷èíà, îáðàòíàÿ ê çîëîòîìó ñå÷åíèþ
		d, e = (Float)0, eps = (Float)sqrt(EPSILON),//eps ïðèáëèçèòåëüíî ðàâíî êâàäðàòíîìó êîðíþ èç îòíîñèòåëüíîé ìàøèííîé òî÷íîñòè
		xm, p, q, r, tol1, tol2, u, v = a+c*(b-a), w = v, x = v, fx = F(v), fu, fv = fx, fw = fx;

	while(1)
	{
		xm = (a+b)/(Float)2;
		tol1 = eps*ABS(x) + tol/(Float)3;
		tol2 = tol1*(Float)2;

		//Ïðîâåðèòü êðèòåðèé îêîí÷àíèÿ
		if(ABS(x-xm) <= (tol2-(b-a)/(Float)2)) return x;

		if(ABS(e) > tol1)//Åñëè çîëîòîå ñå÷åíèå íå òðåáóåòñÿ
		{
			//Ïîñòðîèòü ïàðàáîëó
			r = (x-w)*(fx-fv);
			q = (x-v)*(fx-fw);
			p = (x-v)*q - (x-w)*r;
			q = (Float)2*(q-r);
			if(q > 0) p = -p;
			else q = -q;//q = ABS(q)
			r = e;
			e = d;

			//Ïðèåìëåìà ëè ïàðàáîëà
			if(ABS(p) >= ABS(q*r/(Float)2) || p <= q*(a-x) || p >= q*(b-x))
			{
				//Øàã çîëîòîãî ñå÷åíèÿ
				if(x >= xm) e = a-x;
				else e = b-x;
				d = c*e;
			}
			else
			{
				//Øàã ïàðàáîëè÷åñêîé èíòåðïîëÿöèè
				d = p/q;
				u = x+d;
				//F íå ñëåäóåò âû÷èñëÿòü ñëèøêîì áëèçêî ê 'a' èëè 'b'
				if((u-a) < tol2 || (b-u) < tol2) d = SIGN2(tol1, xm-x);
			}
		}
		else
		{
			//Øàã çîëîòîãî ñå÷åíèÿ
			if(x >= xm) e = a-x;
			else e = b-x;
			d = c*e;
		}

		//F íå ñëåäóåò âû÷èñëÿòü ñëèøêîì áëèçêî ê 'x'
		if(ABS(d) >= tol1) u = x+d;
		else u = x + SIGN2(tol1, d);
		fu = F(u);

		//Ïðèñâîèòü íîâûå çíà÷åíèÿ ïàðàìåòðàì 'a', 'b', 'v', 'w' è 'x'
		if(fu <= fx)
		{
			if(u >= x) a = x;
			else b = x;
			v = w;
			fv = fw;
			w = x;
			fw = fx;
			x = u;
			fx = fu;
			continue;
		}
		if(u < x) a = u;
		else b = u;
		if(fu <= fw || w == x)
		{
			v = w;
			fv = fw;
			w = u;
			fw = fu;
		}
		else if(fu <= fv || v == x || v == w)
		{
			v = u;
			fv = fu;
		}
	}

	return x;
}

Float Zeroin(Float (*F)(Float), Float a, Float b, Float tol)
{
	Float c, d, e, fa = F(a), fb = F(b), fc, tol1, xm, p, q, r, s;

	while(1)
	{
		c = a;
		fc = fa;
		e = d = b-a;
		do
		{
			if(ABS(fc) < ABS(fb))
			{
				a = b;
				b = c;
				c = a;
				fa = fb;
				fb = fc;
				fc = fa;
			}
			//Ïðîâåðêà ñõîäèìîñòè
			tol1 = (Float)2*EPSILON*ABS(b) + tol/(Float)2;
			xm = (c-b)/(Float)2;
			if(ABS(xm) <= tol1 || fb == 0) return b;
			//Íåîáõîäèìà ëè áèñåêöèÿ
			if(ABS(e) >= tol1 && ABS(fa) > ABS(fb))
			{
				//Âîçìîæíà ëè êâàäðàòè÷íàÿ èíòåðïîëÿöèÿ
				if(a != c)
				{
					//Îáðàòíàÿ êâàäðàòè÷íàÿ èíòåðïîëÿöèÿ
					q = fa/fc;
					r = fb/fc;
					s = fb/fa;
					p = s*((Float)2*xm*q*(q-r) - (b-a)*(r-(Float)1));
					q = (q-(Float)1)*(r-(Float)1)*(s-(Float)1);
				}
				else
				{
					//Ëèíåéíàÿ èíòåðïîëÿöèÿ
					s = fb/fa;
					p = (Float)2*xm*s;
					q = (Float)1 - s;
				}
				//Âûáðàòü çíàêè
				if(p > 0) q = -q;
				else p = -p;//p = ABS(p)

				//Ïðèåìëåìà ëè èíòåðïîëÿöèÿ
				if(((Float)2*p) >= ((Float)3*xm*q - ABS(tol1*q)) || p >= ABS(e*q/(Float)2)) e = d = xm;//Áèñåêöèÿ
				else
				{
					e = d;
					d = p/q;
				}
			}
			else e = d = xm;//Áèñåêöèÿ
			//Çàâåðøèòü øàã
			a = b;
			fa = fb;
			if(ABS(d) > tol1) b += d;
			else b += SIGN2(tol1, xm);
			fb = F(b);
		}while(fb*SIGN(fc) <= 0);
	}
}

Float Quanc8(Float (*F)(Float), Float a, Float b, Float ae, Float re, Float *errest, int *nofun, Float *flag)
{
	const Float w0 = (Float)3956/(Float)14175,
				w1 = (Float)23552/(Float)14175,
				w2 = (Float)(-3712)/(Float)14175,
				w3 = (Float)41984/(Float)14175,
				w4 = (Float)(-18160)/(Float)14175;
	Float result = 0.0, area = 0.0, x0 = a, f0, stone = (b-a)/(Float)16, step, cor11 = 0.0, qprev = 0.0, qnow, qdiff, qleft, esterr, tolerr,
		qright[31], f[16], x[16], fsave[8][30], xsave[8][30];

	//*** ÝÒÀÏ 1 *** Ïðèñâîåíèå íà÷àëüíûõ çíà÷åíèé ïåðåìåííûì, íå çàâèñÿùèì îò èíòåðâàëà. Ãåíåðèðîâàíèå êîíñòàíò.
	#define LEVMIN	1
	#define LEVMAX	30
	#define LEVOUT	6
	#define NOMAX	5000
	int levmax = LEVMAX, nofin = NOMAX - 8*(LEVMAX-LEVOUT+(1<<(LEVOUT+1))),//Åñëè '*nofun' äîñòèãàåò çíà÷åíèÿ 'nofin', òî òðåâîãà
		lev = 0, nim = 1, i, j;

	//Ïðèñâîèòü íóëåâûå çíà÷åíèÿ ïåðåìåííûì ñóììàì
	*flag = 0.0;
	*errest = 0.0;
	*nofun = 0;

	if(a == b) return 0.0;

	//*** ÝÒÀÏ 2 *** Ïðèñâîåíèå íà÷àëüíûõ çíà÷åíèé ïåðåìåííûì, çàâèñÿùèì îò èíòåðâàëà, â ñîîòâåòñòâèè ñ ïåðâûì èíòåðâàëîì
	x[15] = b;
	f0 = F(x0);
	x[7] = (x0+b)/(Float)2;
	x[3] = (x0+x[7])/(Float)2;
	x[11] = (x[7]+b)/(Float)2;
	x[1] = (x0+x[3])/(Float)2;
	x[5] = (x[3]+x[7])/(Float)2;
	x[9] = (x[7]+x[11])/(Float)2;
	x[13] = (x[11]+b)/(Float)2;

	for(j=1;j<=15;j+=2) f[j] = F(x[j]);
	*nofun = 9;

	//*** ÝÒÀÏ 3 *** Îñíîâíûå âû÷èñëåíèÿ
	while(1)
	{
		x[0] = (x0+x[1])/(Float)2;
		f[0] = F(x[0]);
		for(j=2;j<=14;j+=2)
		{
			x[j] = (x[j-1]+x[j+1])/(Float)2;
			f[j] = F(x[j]);
		}
		nofun += 8;
		step = (x[15]-x0)/(Float)16;
		qleft = (w0*(f0+f[7]) + w1*(f[0]+f[6]) + w2*(f[1]+f[5]) + w3*(f[2]+f[4]) + w4*f[3]) * step;
		qright[lev] = (w0*(f[7]+f[15]) + w1*(f[8]+f[14]) + w2*(f[9]+f[13]) + w3*(f[10]+f[12]) + w4*f[11]) * step;
		qnow = qleft + qright[lev];
		qdiff = qnow - qprev;
		area += qdiff;

		//*** ÝTAÏ 4 *** Ïðîâåðêà ñõîäèìîñòè äëÿ èíòåðâàëà
		esterr = ABS(qdiff)/(Float)1023;
		tolerr = MAX(ae, re*ABS(area))*(step/stone);

		if(lev < LEVMIN || ((lev < levmax) && (*nofun <= nofin) && (esterr > tolerr)))
		{
			//*** ÝTAÏ 5 *** Ñõîäèìîñòè íåò. Óñòàíîâèòü ñëåäóþùèé èíòåðâàë
			nim <<= 1;
			lev++;
			//Çàïîìíèòü ýëåìåíòû, îòíîñÿùèåñÿ ê ïðàâîé ïîëîâèíå èíòåðâàëà, äëÿ áóäóùåãî èñïîëüçîâàíèÿ
			for(i=0;i<8;i++)
			{
				fsave[i][lev-1] = f[i+8];
				xsave[i][lev-1] = x[i+8];
			}
			//Ñîáðàòü ýëåìåíòû, îòíîñÿùèåñÿ ê ëåâîé ïîëîâèíå èíòåðâàëà äëÿ íåìåäëåííîãî èñïîëüçîâàíèÿ
			qprev = qleft;
			for(i=7;i>=0;i--)
			{
				f[i*2+1] = f[i];
				x[i*2+1] = x[i];
			}
			continue;
		}

		if(lev >= levmax) *flag += (Float)1.0;
		else if(*nofun > nofin)
		{
			nofin <<= 1;
			levmax = LEVOUT;
			*flag += (b-x0)/(b-a);
			//Òåêóùåå ïðåäåëüíîå çíà÷åíèå ãëóáèíû äåëåíèÿ ïîïîëàì ðàâíî 'levmax'
		}

		//*** ÝTAÏ 7 *** Ñõîäèìîñòü äëÿ èíòåðâàëà èìååò ìåñòî. Ïðèáàâèòü î÷åðåäíûå ñëàãàåìûå ê ïåðåìåííûì ñóììàì
		result += qnow;
		*errest += esterr;
		cor11 += qdiff/(Float)1023;

		//Óñòàíîâèòü ñëåäóþùèé èíòåðâàë
		while(nim & 1)//åñëè nim - íå÷¸òíîå
		{
			nim /= 2;
			lev--;
		}
		nim++;
		if(lev <= 0) break;

		//Ñîáðàòü ýëåìåíòû, íåîáõîäèìûå äëÿ ñëåäóþùåãî èíòåðâàëà
		qprev = qright[lev-1];
		x0 = x[15];
		f0 = f[15];
		for(i=0;i<8;i++)
		{
			f[i*2+1] = fsave[i][lev-1];
			x[i*2+1] = xsave[i][lev-1];
		}
	}

	//*** ÝTAÏ 8 *** Çàêëþ÷èòåëüíûå îïåðàöèè è âûõîä
	result += cor11;
	//Îáåñïå÷èòü, ÷òîáû çíà÷åíèå ïåðåìåííîé '*errest' áûëî íå ìåíüøå óðîâíÿ îêðóãëåíèé
	if(*errest == (Float)0.0) return result;
	Float temp;
	while(1)
	{
		temp = ABS(result) + *errest;
		if(temp != ABS(result)) return result;
		*errest *= (Float)2;
	}
}

void Decomp(unsigned int n, Float *A, Float *cond, int *ipvt)
{
	unsigned int i, j, k;
	int kp1, m;
	Float ek, t, anorm, ynorm, znorm, *work;
	if(!n) return;//ðàçìåðíîñòü ìàòðèöû íå ìîæåò áûòü íóëåâîé
	ipvt[n-1]=1;
	if(n == 1)//Ñëó÷àé ìàòðèöû 1x1
	{
		*cond = 1.0;
		if(*A == 0.0) *cond = MAXIMUM;//Òî÷íàÿ âûðîæäåííîñòü
		return;
	}

	//Âû÷èñëèòü 1-íîðìó ìàòðèöû A
	anorm = 0.0;
	for(j=0;j<n;j++)
	{
		t=0.0;
		for(i=j;i<n*n;i+=n) t += ABS(A[i]);
		if (t > anorm) anorm = t;
	}

	//Ãàóññîâà èñêëþ÷åíèå ñ ÷àñòè÷íûì âûáîðîì âåäóùåãî ýëåìåíòà
	for(k=0;k<(n-1);k++)
	{
		kp1 = k + 1;
		//Íàéòè âåäóùèé ýëåìåíò
		m = k*n+k;
		for(i=(kp1*n + k);i<n*n;i+=n) if(ABS(A[i]) > ABS(A[m])) m = i;
		m /= n;
		ipvt[k] = m;
		if(m != k) ipvt[n-1] = -ipvt[n-1];

		t = A[m*n+k];
		A[m*n+k] = A[k*(n+1)];
		A[k*(n+1)] = t;

		//Ïðîïóñòèòü ýòîò øàã, åñëè âåäóùèé ýëåìåíò ðàâåí íóëþ
		if(t != 0.0)
		{
			//Âû÷èñëèòü ìíîæèòåëè
			for(i=(kp1*n + k);i<n*n;i+=n) A[i] = -A[i]/t;
			//Ïåðåñòàâëÿòü è èñêëþ÷àòü ïî ñòîëáöàì
			for(j=kp1;j<n;j++)
			{
				int temp = k-j;

				t = A[m*n+j];
				A[m*n+j] = A[k*n+j];
				A[k*n+j] = t;

				if(t != 0.0) for(i=(kp1*n+j);i<n*n;i+=n) A[i] += A[i+temp]*t;
			}
		}
	}

	work = new Float[n];
	//Ðåøèòü ñèñòåìó (òðàíñïîíèðîâàííàÿ A)*Y = I
	for(k=0;k<n;k++)
	{
		t=0.0;
		if(k != 0) for(i=k,j=0;j<(k-1);i+=n, j++) t += A[i]*work[j];
		if(t < 0.0) ek = -1.0;
		else ek = 1.0;
		Float temp = A[k*(n+1)];
		if(temp == 0.0)
		{
			*cond = MAXIMUM;
			delete [] work;
			return;
		}
		work[k] = -(ek+t)/temp;
	}

	k = n-2;
	do
	{
		t = work[k];
		kp1 = k+1;
		for(i=kp1*n+k,j=kp1; j<n; i+=n,j++) t += A[i]*work[j];
		work[k] = t;
		m = ipvt[k];
		if(m != k)
		{
			t = work[m];
			work[m] = work[k];
			work[k] = t;
		}
	}while(k--);

	ynorm = 0.0;
	for(i=0;i<n;i++) ynorm += ABS(work[i]);
	//Ðåøèòü ñèñòåìó A*Z = Y
	Solve(n, A, work, ipvt);
	znorm=0.0;
	for(i=0;i<n;i++) znorm += ABS(work[i]);
	//Îöåíèòü îáóñëîâëåííîñòü
	*cond = anorm*znorm/ynorm;
	if (*cond < 1.0) *cond = 1.0;
	delete [] work;
}


void Solve(unsigned int n, Float *A, Float *b, int *ipvt)
{
	unsigned int k, i;
	int m;
	Float t;
	if(!n) return;
	//Ïðÿìîé õîä
	if(n == 1)
	{
		b[0] /= *A;
		return;
	}

	for(k=0;k<(n-1);k++)
	{
		m = ipvt[k];

		t = b[m];
		b[m] = b[k];
		b[k] = t;

		for(i=k+1;i<n;i++) b[i] += A[i*n+k]*t;
	}
	//Îáðàòíàÿ ïîäñòàíîâêà
	for(k=n-1;k>0;k--)
	{
		b[k] /= A[k*(n+1)];
		t = -b[k];
		for(i=0;i<k;i++) b[i] += A[i*n+k]*t;
	}
	b[0] /= *A;
}

void Spline(unsigned int n, Float *X, Float *Y, Float *B, Float *C, Float *D)
{
	if(n <= 2)
	{
		if(n == 2)
		{
			B[1] = B[0] = (Y[1]-Y[0])/(X[1]-X[0]);
			C[0] = C[1] = D[0] = D[1] = (Float)0;
		}
		return;
	}

	int i;
	Float t;
	n--;
	//Ïîñòðîèòü òð¸õäèàãîíàëüíóþ ñèñòåìó
	//B - Äèàãîíàëü; D - Íàääèàãîíàëü; C - ïðàâûå ÷àñòè
	D[0] = X[1] - X[0];
	C[1] = (Y[1] - Y[0])/D[0];
	for(i=1;i<(int)n;i++)
	{
		D[i] = X[i+1] - X[i];
		B[i] = (Float)2*(D[i-1]+D[i]);
		C[i+1] = (Y[i+1]-Y[i])/D[i];
		C[i] = C[i+1] - C[i];
	}
	//Ãðàíè÷íûå óñëîâèÿ. Òðåòüè ïðîèçâîäíûå â òî÷êàõ X[0] è X[n-1] âû÷èñëÿþòñÿ ñ ïîìîùüþ ðàçäåë¸ííûõ ðàçíîñòåé
	B[0] = -D[0];
	B[n] = -D[n-1];
	C[0] = C[n] = (Float)0;

	if(n != 2)
	{
		C[0] = C[2]/(X[3] - X[1]) - C[1]/(X[2]-X[0]);
		C[n] = C[n-1]/(X[n] - X[n-2]) - C[n-2]/(X[n-1]-X[n-3]);
		C[0] *= D[0]*D[0]/(X[3]-X[0]);
		C[n] *= -D[n-1]*D[n-1]/(X[n] - X[n-3]);
	}

	//Ïðÿìîé õîä
	for(i=1;i<=(int)n;i++)
	{
		t = D[i-1]/B[i-1];
		B[i] -= t*D[i-1];
		C[i] -= t*C[i-1];
	}

	//Îáðàòíàÿ ïîäñòàíîâêà
	C[n] /= B[n];
	for(i=(n-1);i>=0;i--) C[i] = (C[i] - D[i]*C[i+1])/B[i];

	//Âû÷èñëèòü êîýôôèöèåíòû ïîëèíîìîâ
	B[n] = (Y[n] - Y[n-1])/D[n-1] + D[n-1]*(C[n-1]+(Float)2*C[n]);
	for(i=0;i<(int)n;i++)
	{
		B[i] = (Y[i+1]-Y[i])/D[i] - D[i]*(C[i+1]+(Float)2*C[i]);
		D[i] = (C[i+1]-C[i])/D[i];
		C[i] *= (Float)3;
	}
	C[n] *= (Float)3;
	D[n] = D[n-1];
}

double SEval(unsigned int n, double u, double *X, double *Y, double *B, double *C, double *D)
{
	int i = 0;
	if(n < 2) return (Float)0;//Êîëè÷åñòâî ýêñïåðèìåíòàëüíûõ òî÷åê íå ìîæåò áûòü ìåíüøå äâóõ
	if(u < X[0] || u > X[1])
	{
		int j = n, k;
		//Äâîè÷íûé ïîèñê
		do
		{
			k = (i + j)/2;
			if(u < X[k]) j = k;
			else i = k;
		}while(j > (i+1));
	}
	//Âû÷èñëèòü ñïëàéí
	Float dx = u - X[i];
	return Y[i] + dx*(B[i] + dx*(C[i] + dx*D[i]));
}

double X(int k){
	return 0.3*k;
}
double F(double x){
	return 1 - exp(-x);
}

double W(double x, int K){

	double w = 1;
	for (int k = 0; k < 11; k++){
		if (K != k)
			w *= x - X(k);
	}

	return w;
}
//ïîëèíîì Ëîãðàíæà
double Q10(double x){

	//íàõîæäåíèå ïîëèíîìà Ëîãðàíæà 10-é ñòåïåíè
	double Q = 0;
	for (int k = 0; k < 10; k++){
		Q += W(x, k) / W(X(k), k) * F(X(k));
	}

	return Q;
}


void main1(){

	cout << "Integrate F(x)... ";
	cout << (3 - exp(-3)) - (0 - exp(-0)) << endl << endl;

	cout << "Integrate Q(x)... ";
	Float result, errest, flag;
	double a, b, relerr, abserr;
	int nofun;
	a = 3;
	b = 0;
	relerr = 1.0e-6;
	abserr = 0.0;

}