#include "stdafx.h"
#include <math.h>

void podaj_dane(int *a, int *b, int *c, int *d)
{
	printf("Podaj a: ");	scanf_s("%d", a);
	printf("Podaj b: ");	scanf_s("%d", b);
	printf("Podaj c: ");	scanf_s("%d", c);
	printf("Podaj d: ");	scanf_s("%d", d);
	printf("\n");
}
void formatuj_rnie(int a, int b, int c, int d)
{
	printf("%dxx ", a);
	if (b<0) printf("%dx ", b); else  printf("+%dx ", b);
	if (c<0) printf("%d ", c); else  printf("+%d ", c);
	if (d<0) printf("%di ", d); else  printf("+%di ", d);
}

// oblicz delte rzeczywista
float oblicz_d_r(int a, int b, int c) 
{
	return (float)b*b - 4 * a*c;
}

//oblicz delte urojona
float oblicz_d_u(int a, int d) 
{
	return (float)-4.0*a*d;
}

//oblicz pierwiastek z delty rzeczywistej
float oblicz_p_d_r(float delta_r, float delta_u)
{
	return sqrt((sqrt(delta_r*delta_r + delta_u*delta_u) + delta_u)/2.0);
}

float oblicz_p_d_u(float delta_r, float delta_u) 
{
	return sqrt((sqrt(delta_r*delta_r + delta_u*delta_u) - delta_u) / 2.0);
}

void oblicz_rnie(int a, int b, int c, int d, float *x1r, float *x2r, float *x3r, float *x4r, float *x1u, float *x2u, float *x3u, float *x4u)
{
	if (a != 0 && d == 0)
	{
		float delta_r = oblicz_d_r(a, b, c);
		//punkt 1.1
		if (delta_r > 0)
		{
			*x1r = (float)(-b - sqrt(delta_r)) / (2.0f * a);
			*x2r = (float)(-b + sqrt(delta_r)) / (2.0f * a);
		}
		//punkt 1.2
		else if (delta_r == 0)
		{
			*x1r = (float)-b / (2.0f * a);
		}
		//punkt 1.3
		else if (delta_r < 0)
		{
			*x1r = (float)-b / (2.0f * a);
			*x1u = (float)-(sqrt(fabs(delta_r)) / (2.0f * a));
			*x2r = *x1r;
			*x2u = -*x1u;
		}
	}
	//punkt 2
	else if (a == 0 && b != 0 && d == 0)
	{
		*x1r = (float)-c / b;
	}
	//punkt 3
	else if (a == 0 && b == 0 && (c != 0 || d != 0))
	{
		printf("Rownanie sprzeczne\n");
	}
	//punkt 4
	else if (a == 0 && b == 0 && c == 0 && d == 0)
	{
		printf("Rownanie tozsamosciowe\n");
	}
	//punkt 5
	else if (a == 0 && b != 0 && d != 0)
	{
		*x1r = (float)-c / b;
		*x1u = (float)-d / b;
	}
	//punkt 6
	else if (a != 0 && d != 0)
	{
		float delta_r = oblicz_d_r(a, b, c);
		float delta_u = oblicz_d_u(a, d);
		float pdelta_r = oblicz_p_d_r(delta_r, delta_u);
		float pdelta_u = oblicz_p_d_u(delta_r, delta_u);
		*x1r = (float)(-b - pdelta_r) / (2.0f * a);
		*x2r = (float)(-b - pdelta_r) / (2.0f * a);
		*x3r = (float)(-b + pdelta_r) / (2.0f * a);
		*x4r = (float)(-b + pdelta_r) / (2.0f * a);
		*x1u = (float)(-pdelta_u) / (2.0f * a);
		*x2u = (float)(pdelta_u) / (2.0f * a);
		*x3u = (float)(pdelta_u) / (2.0f * a);
		*x4u = (float)(-pdelta_u) / (2.0f * a);
	}

}

void dodaj(float delta_r, float delta_u, float *x1r, float *x2r, float *x3r, float *x4r, float *x1u, float *x2u, float *x3u, float *x4u, float *su, float*sr)
{
	//przypadek 1
	if (delta_r > 0 && delta_u == 0)
	{
		*sr = *x1r + *x2r;
	}
	//przypadek 2
	if (delta_r < 0 && delta_u == 0)
	{
		*sr = *x1r + *x2r;
		*su = *x1u + *x2u;
	}
	//przypadek 3
	if (delta_u)
	{
		*sr = *x1r + *x2r + *x3r + *x4r;
		*su = *x1u + *x2u + *x3u + *x4u;
	}
}

void odejmij(float delta_r, float delta_u, float *x1r, float *x2r, float *x3r, float *x4r, float *x1u, float *x2u, float *x3u, float *x4u, float *rr, float *ru)
{
	//przypadek 1
	if (delta_r > 0 && delta_u == 0)
	{
		*rr = *x1r - *x2r;
	}
	//przypadek 2
	if (delta_r < 0 && delta_u == 0)
	{
		*rr = *x1r - *x2r;
		*ru = *x1u - *x2u;
	}
	//przypadek 3
	if (delta_u)
	{
		*rr = *x1r - *x2r - *x3r - *x4r;
		*ru = *x1u - *x2u - *x3u - *x4u;
	}
}

void pomnoz(float delta_r, float delta_u, float *x1r, float *x2r, float *x3r, float *x4r, float *x1u, float *x2u, float *x3u, float *x4u, float *ilr, float *ilu)
{
	//przypadek 1
	if (delta_r > 0 && delta_u == 0)
	{
		*ilr = *x1r * (*x2r);
	}
	//przypadek 2
	if (delta_r < 0 && delta_u == 0)
	{
		*ilr = *x1r**x2r - *x1u**x2u;
		*ilu = *x1r**x2u + *x2r**x1u;
	}
	//przypadek 3
	if (delta_u)
	{
		*ilr = (*x1r**x2r - *x1u**x2u)*(*x3r**x4r - *x3u**x4u) - (*x1r**x2u + *x2r**x1u)*(*x3r**x4r + *x4r**x3u);
		*ilu = (*x1r**x2r - *x1u**x2u)*(*x3r**x4u + *x4r**x3u) + (*x3r**x4r - *x3u**x4u)*(*x1r**x2u + *x2r**x1u);
	}
}

void wyswietl(int a, int b, int c, int d, float x1r, float x2r, float x3r, float x4r, float x1u, float x2u, float x3u, float x4u, float sr, float su, float rr, float ru, float ilr, float ilu)
{
	float delta_r = oblicz_d_r(a, b, c);
	float delta_u = oblicz_d_u(a, d);
	//punkt 1
	if (a != 0 && d == 0)
	{
		//punkt 1.1
		if (delta_r > 0)
		{
			printf("x1r = %.2f\n", x1r);
			printf("x2r = %.2f\n", x2r);
		}
		//punkt 1.2
		else if (delta_r == 0)
		{
			printf("x1r = %.2f\n", x1r);
		}
		//punkt 1.3
		else if (delta_r < 0)
		{
			printf("x1r = %.2f\n", x1r);
			printf("x1u = %.2f\n", x1u);
			printf("x2r = %.2f\n", x2r);
			printf("x2u = %.2f\n", x2u);
		}
	}
	//punkt 2
	else if (a == 0 && b != 0 && d == 0)
	{
		printf("x1r = %.2f\n", x1r);
	}
	//punkt 5
	else if (a == 0 && b != 0 && d != 0)
	{
		printf("x1r = %.2f\n", x1r);
		printf("x1u = %.2f\n", x1u);
	}
	//punkt 6
	else if (a != 0 && d != 0)
	{
		printf("\nx1r = %f \t x1u = %f", x1r, x1u);
		printf("\nx2r = %f \t x2u = %f", x2r, x2u);
		printf("\nx3r = %f \t x3u = %f", x3r, x3u);
		printf("\nx4r = %f \t x4u = %f", x4r, x4u);
	}
	if (delta_r > 0 && d == 0 && a != 0)
	{
		printf("sr = %.2f\n", sr);
		printf("rr = %.2f\n", rr);
		printf("ilr = %.2f\n", ilr);
	}
	if ((delta_r < 0 && d == 0) || (a != 0 && d != 0))
	{
		printf("sr = %.2f\n", sr);
		printf("su = %.2f\n", su);
		printf("rr = %.2f\n", rr);
		printf("ru = %.2f\n", ru);
		printf("ilr = %.2f\n", ilr);
		printf("ilu = %.2f\n", ilu);
	}
}

int main()
{
	//int a = 1, b = 1, c = -1, d = 0; //1.1) dla delty  0
	//int a = -1, b = 4, c = -4, d = 0; //1.2) dla delty = 0
	//int a = 2, b = -3, c = 2, d = 0; //1.3)dla delty < 0
	//int a = 0, b = 1, c = -1, d = 0; //2) 
	//int a = 0, b = 0, c = -1, d = 0; //3) 
	//int a = 0, b = 0, c = 0, d = 0; //4) 
	//int a = 0, b = 5, c = 0, d = 5; //5) 
	//int a = 5, b = 0, c = 0, d = 5; //6) delta = -100i
	//int a, b, c, d;
	int a, b, c, d;
	float delta_r = 0, delta_u = 0, x1r = 0, x2r = 0, x3r = 0, x4r = 0, x1u = 0, x2u = 0, x3u = 0, x4u = 0, pdelta_r = 0, pdelta_u = 0;
	float sr = 0, su = 0, rr = 0, ru = 0, ilr = 0, ilu = 0;

	/*a = -2;
	b = -3;
	c = -4;
	d = -5;
	a = 0;
	b = 4;
	c = 40;
	d = 20;*/
	//1)  1,4,1,0
	//    1,4,4,0
	//    1,4,5,0
	//2)  0,4,20,0
	//3)  0,0,5,1
	//4)  0,0,0,0
	//5)  0,4,20,20
	podaj_dane(&a, &b, &c, &d);
	formatuj_rnie(a, b, c, d);
	delta_r = oblicz_d_r(a, b, c);
	delta_u = oblicz_d_u(a, d);
	oblicz_rnie(a, b, c, d, &x1r, &x2r, &x3r, &x4r, &x1u, &x2u, &x3u, &x4u);
	dodaj(delta_r, delta_u, &x1r, &x2r, &x3r, &x4r, &x1u, &x2u, &x3u, &x4u, &su, &sr);
	odejmij(delta_r, delta_u, &x1r, &x2r, &x3r, &x4r, &x1u, &x2u, &x3u, &x4u, &ru, &rr);
	pomnoz(delta_r, delta_u, &x1r, &x2r, &x3r, &x4r, &x1u, &x2u, &x3u, &x4u, &ilu, &ilr);
	wyswietl(a, b, c, d, x1r, x2r, x3r, x4r, x1u, x2u, x3u, x4u, sr, su, rr, ru, ilr, ilu);
	
	return 0;
}

