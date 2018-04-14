#include "stdafx.h"
#include <math.h>

void podaj_dane(int *a, int *b, int *c, int *d)
{
	printf("Podaj dane w kolejnosci a,b,c,d ");
	scanf_s("%d, %d, %d, %d", &a, &b, &c, &d);
}
void formatuj_rnie(int a, int b, int c, int d)
{
	printf("%dxx ", a);
	if (b<0) printf("%dx ", b); else  printf("+%dx ", b);
	if (c<0) printf("%d ", c); else  printf("+%d ", c);
	if (d<0) printf("%di ", d); else  printf("+%di ", d);
}

float oblicz_d_r(int a, int b, int c) 
{
	return b*b - 4 * a*c;
}

float oblicz_d_u(int a, int d) 
{
	return (-4.0*a*d)*(-4.0*a*d);
}

float oblicz_p_d_r(float delta_r, float delta_u)
{
	return sqrt((sqrt(delta_r*delta_r + delta_u*delta_u) + delta_u)/2);
}

float oblicz_p_d_u(float delta_r, float delta_u) 
{
	return sqrt((sqrt(delta_r*delta_r + delta_u*delta_u) - delta_u) / 2);
}

void oblicz_rnie(int a, int b, int c, int d, float *x1r, float *x2r, float *x3r, float *x4r, float *x1u, float *x2u, float *x3u, float *x4u)
{
/*	x1r = (-1.0*b - pdelta_r) / (2.0*a);	 x1u = (-1 * pdelta_u) / (2.0*a);
	x2r = (-1.0*b - pdelta_r) / (2.0*a);	 x2u = (pdelta_u) / (2.0*a);
	x3r = (-1.0*b + pdelta_r) / (2.0*a);	 x3u = (pdelta_u) / (2.0*a);
	x4r = (-1.0*b + pdelta_r) / (2.0*a);	 x4u = (-1 * pdelta_u) / (2.0*a);*/

}

void dodaj(float delta_r, float delta_u, float *x1r, float *x2r, float *x3r, float *x4r, float *x1u, float *x2u, float *x3u, float *x4u, float *su, float*sr)
{
}

void odejmij(float delta_r, float delta_u, float *x1r, float *x2r, float *x3r, float *x4r, float *x1u, float *x2u, float *x3u, float *x4u, float *rr, float *ru)
{
	
}

void pomnoz(float delta_r, float delta_u, float *x1r, float *x2r, float *x3r, float *x4r, float *x1u, float *x2u, float *x3u, float *x4u, float *ilr, float *ilu)
{
}

void wyswietl()
{

}

int main()
{
	//int a = 1, b = 1, c = -1, d = 0; //1.1) dla delty  0
	//int a = -1, b = 4, c = -4, d = 0; //1.2) dla delty = 0
	//int a = 2, b = -3, c = 2, d = 0; //1.3)dla delty < 0
	//int a = 0, b = 1, c = -1, d = 0; //2) 
	//int a = 0, b = 0, c = -1, d = 0; //3) 
	//int a = 0, b = 0, c = 0, d = 0; //4) 
	int a = 0, b = 5, c = 0, d = 5; //5) 
	//int a = 5, b = 0, c = 0, d = 5; //6) delta = -100i
	//int a, b, c, d;
	float delta_r, pdelta_r, delta_u, pdelta_u, x1r, x2r, x3r, x4r, x1u, x2u, x3u, x4u;

	//podaj_dane(a, b, c, d);
	formatuj_rnie(a, b, c, d);
	delta_r = oblicz_d_r(a, b, c);
	delta_u = oblicz_d_u(a, d);
	pdelta_r = oblicz_p_d_r(delta_r, delta_u);
	pdelta_u = oblicz_p_d_u(delta_r, delta_u);

	//1
	if (a != 0 && d == 0)
	{
		delta_r = b*b - 4 * a*c;
		// Pierwiastek
		pdelta_r = 0.5*(delta_r + delta_r / delta_r);
		pdelta_r = 0.5*(pdelta_r + (delta_r / pdelta_r));
	skokPierwiastek:
		pdelta_r = 0.5*(pdelta_r + (delta_r / pdelta_r));
		if (0.5*(pdelta_r + (delta_r / pdelta_r)) - pdelta_r>0.001)
		{
			goto skokPierwiastek;
		}
		printf("\delta = %f", delta_r);
		//1.1
		if (delta_r > 0)
		{
			x1r = (-b - pdelta_r) / (2 * a);
			x2r = (-b + pdelta_r) / (2 * a);
			printf("\nx1r = %f", x1r);
			printf("\nx2r = %f", x2r);
		}
		//1.2
		if (delta_r == 0)
		{
			x1r = -b / (2 * a);
			printf("\nx1r = %f", x1r);
		}
		//1.3
		if (delta_r < 0)
		{
			x1r = -b / (2 * a);
			x1u = -pdelta_r / (2 * a);
			x2r = x1r;
			x2u = x1u;
			printf("\nx1r = %f", x1r);
			printf("\nx1u = %f", x1u);
			printf("\nx2r = %f", x2r);
			printf("\nx2u = %f", x2u);
		}
	}
	//2
	if (a == 0 && b != 0 && d == 0)
	{

		x1r = -c / b;
		printf("\nx1r = %f", x1r);
	}
	//3
	if (a == 0 && b == 0 && (c != 0 || d != 0))
	{
		printf("\nRonwnanie sprzeczne");
	}
	//4
	if (a == 0 && b == 0 && c == 0 && d == 0)
	{
		printf("\nRownanie tozsamosciowe");
	}
	//5
	if (a == 0 && b != 0 && d != 0)
	{
		x1r = -c / b;
		x1u = -d / b;
		printf("\nx1r = %f", x1r);
		printf("\nx1u = %f", x1u);
	}
	//6
	if (a != 0 && d != 0)
	{
		//*** Cz�� rzeczywista ***//
		//m^2+n^2 	
		delta_r = (1.0*b*b - 4.0*a*c)*(1.0*b*b - 4.0*a*c) + (-4.0*a*d)*(-4.0*a*d);

		//ma�y pierwiastek
		pdelta_r = delta_r / 2;
	skokPierwiastek2:
		pdelta_r = (pdelta_r + delta_r / pdelta_r) / 2;
		if ((pdelta_r - (delta_r) / pdelta_r) > 0.000001) {

			goto skokPierwiastek2;
		}

		//ma�y pierwiastek na dwa
		delta_r = pdelta_r;
		delta_r = (delta_r + (1.0*b*b - 4.0*a*c)) / 2;

		//du�y pierwiastek
		pdelta_r = delta_r / 2;
	skokPierwiastek3:
		pdelta_r = (pdelta_r + delta_r / pdelta_r) / 2;
		if ((pdelta_r - (delta_r) / pdelta_r) > 0.000001) {

			goto skokPierwiastek3;
		}


		//*** Cz�� urojona ***//
		//m^2+n^2
		delta_u = (1.0*b*b - 4.0*a*c)*(1.0*b*b - 4.0*a*c) + (-4.0*a*d)*(-4.0*a*d);

		//ma�y pierwiastek
		pdelta_u = delta_u / 2;
	skokPierwiastek4:
		pdelta_u = (pdelta_u + delta_u / pdelta_u) / 2;
		if ((pdelta_u - (delta_u) / pdelta_u) > 0.000001) {

			goto skokPierwiastek4;
		}

		//ma�y pierwiastek na dwa
		delta_u = pdelta_u;
		delta_u = (delta_u - (1.0*b*b - 4.0*a*c)) / 2;

		//du�y pierwiastek
		pdelta_u = delta_u / 2;
	skokPierwiastek5:
		pdelta_u = (pdelta_u + delta_u / pdelta_u) / 2;
		if ((pdelta_u - (delta_u) / pdelta_u) > 0.000001) {

			goto skokPierwiastek5;
		}

		x1r = (-1.0*b - pdelta_r) / (2.0*a);	 x1u = (-1 * pdelta_u) / (2.0*a);
		x2r = (-1.0*b - pdelta_r) / (2.0*a);	 x2u = (pdelta_u) / (2.0*a);
		x3r = (-1.0*b + pdelta_r) / (2.0*a);	 x3u = (pdelta_u) / (2.0*a);
		x4r = (-1.0*b + pdelta_r) / (2.0*a);	 x4u = (-1 * pdelta_u) / (2.0*a);

		printf("\nx1r = %f \t x1u = %f", x1r, x1u);
		printf("\nx2r = %f \t x2u = %f", x2r, x2u);
		printf("\nx3r = %f \t x3u = %f", x3r, x3u);
		printf("\nx4r = %f \t x4u = %f", x4r, x4u);
	}
	return 0;
}

