#include "stdafx.h"
#include <iostream>

using namespace std;

struct rzeczywista {
	float x1, x2, s, r, il, ir;
};
struct urojona
{
	float x1, x2, s, r, il, ir;
};

struct dane {
	int *wspolczynnik; // a,b,c
	float d, m1, m2, fi1, fi2;
	float gamma, delta;
};


class Rownanie
{
	rzeczywista *r;
	urojona *u;
	dane *d;

public:
	Rownanie();
	~Rownanie();
	void Podaje_Dane();
	void Wyswietl_Rownanie();
	void Oblicz_Delte();
	void Oblicz_Pierwiastki();
	void Dodaj();
	void Odejmij();
	void Pomnoz();
	void Podziel();
	void Postac_Trygonometryczna();
	void Wyswietl_Wynik();
	float sgn();
	void Pierwiastkuj();

};

Rownanie::Rownanie()
{

	d = new dane;
	r = new rzeczywista;
	u = new urojona;

	d->wspolczynnik = new int[3];

	r->x1 = 0;		r->x2 = 0;
	r->r = 0;		r->s = 0;
	r->il = 0;		r->ir = 0;

	u->x1 = 0;		u->x2 = 0;	
	u->s = 0;		u->r = 0;
	u->il = 0;		u->ir = 0;

	d->m1 = 0;		d->m2 = 0;
	d->fi1 = 0;		d->fi2 = 0;
	d->d = 0;		d->gamma = 0;
	d->delta = 0;
}

Rownanie::~Rownanie()
{
	delete[] d->wspolczynnik;
	delete d;
	delete r;
	delete u;

	cout << "Destruktor wywolany" << endl;
}

void Rownanie::Podaje_Dane()
{
	cout << "Podaj a: ";         cin >> d->wspolczynnik[0];
	cout << endl << "Podaj b: "; cin >> d->wspolczynnik[1];
	cout << endl << "Podaj c: "; cin >> d->wspolczynnik[2];
	cout << endl;
}

void Rownanie::Wyswietl_Rownanie()
{
	if (d->wspolczynnik[0] != 0)
	{
		if (d->wspolczynnik[0] == 1)
			cout << "xx";
		else if (d->wspolczynnik[0] == -1)
			cout << "-xx";
		else
			cout << d->wspolczynnik[0] << "xx";

		if (d->wspolczynnik[1] == 0 && d->wspolczynnik[2] == 0)
			cout << " = 0" << endl;

	}
	fflush(stdout);

	if (d->wspolczynnik[1] != 0)
	{
		if (d->wspolczynnik[1] > 1 && d->wspolczynnik[0] == 0)
			cout << d->wspolczynnik[1] << "x";
		else if (d->wspolczynnik[1] == 1 && d->wspolczynnik[0] == 0)
			cout << "x";
		else if (d->wspolczynnik[1] == 1)
			cout << "+x";
		else if (d->wspolczynnik[1] == -1)
			cout << "-x";
		else if (d->wspolczynnik[1] > 1 && d->wspolczynnik[0] != 0)
			cout << "+" << d->wspolczynnik[1] << "x";
		else if (d->wspolczynnik[1] < 0 && d->wspolczynnik[0] != 0)
			cout << d->wspolczynnik[1] << "x";
		else if (d->wspolczynnik[1] > 1 && d->wspolczynnik[0] == 0)
			cout << d->wspolczynnik[1] << "x";

		if (d->wspolczynnik[0] == 0 && d->wspolczynnik[2] == 0)
			cout << " = 0" << endl;

	}

	if (d->wspolczynnik[2] != 0)
	{
		if (d->wspolczynnik[1] != 0)
		{
			if (d->wspolczynnik[2] > 0)
				printf("+%d = 0\n", d->wspolczynnik[2]);
			if (d->wspolczynnik[2] < 0)
				printf("%d = 0\n", d->wspolczynnik[2]);
		}
		else if (d->wspolczynnik[0] != 0)
		{
			if (d->wspolczynnik[2] > 0)
				printf("+%d = 0\n", d->wspolczynnik[2]);
			if (d->wspolczynnik[2] < 0)
				printf("%d = 0\n", d->wspolczynnik[2]);
		}
		else
		{
			if (d->wspolczynnik[2] > 0)
				printf("%d = 0\n", d->wspolczynnik[2]);
			if (d->wspolczynnik[2] < 0)
				printf("%d = 0\n", d->wspolczynnik[2]);
		}
	}

	if (d->wspolczynnik[2] == 0 && d->wspolczynnik[0] != 0 && d->wspolczynnik[1] != 0)
	{
		cout << " = 0" << endl;
	}

	if (d->wspolczynnik[0] == 0 && d->wspolczynnik[1] == 0 && d->wspolczynnik[2] != 0)
	{
		cout << "Rownanie sprzeczne" << endl;
		exit(0);
	}
	else if (d->wspolczynnik[0] == 0 && d->wspolczynnik[1] == 0 && d->wspolczynnik[2] == 0)
	{
		cout << "Rownanie nie tozsamosciowe" << endl;
		exit(0);
	}
}

void Rownanie::Oblicz_Delte()
{
	if (d->wspolczynnik[0] != 0)
	{
		printf("Delta = %.2f\n", (float)(d->wspolczynnik[1] * d->wspolczynnik[1]) - (float)(4 * d->wspolczynnik[0] * d->wspolczynnik[2]));
		d->d = (float)(d->wspolczynnik[1] * d->wspolczynnik[1]) - (float)(4 * d->wspolczynnik[0] * d->wspolczynnik[2]);
	}
}

void Rownanie::Oblicz_Pierwiastki()
{
	if (d->wspolczynnik[0] == 0)
	{
		r->x1 = (float)(-(d->wspolczynnik[2] / d->wspolczynnik[1]));
	}
	else
	{
		if (d->d > 0)
		{
			r->x1 = (float)(-(d->wspolczynnik[1]) - sqrt(d->d)) / (float)(2 * d->wspolczynnik[0]);
			r->x2 = (float)(-(d->wspolczynnik[1]) + sqrt(d->d)) / (float)(2 * d->wspolczynnik[0]);

			printf("x1r: %.2f\nx2r: %.2f\n", r->x1, r->x2);
		}
		else if (d->d == 0)
		{
			r->x1 = (float)-(d->wspolczynnik[1]) / (float)(2 * d->wspolczynnik[0]);
			printf("x1r: %.2f\n", r->x1);
		}
		else if (d->d < 0)
		{
			r->x1 = (float)-(d->wspolczynnik[1]) / (float)(2 * d->wspolczynnik[0]);
			u->x1 = (float)-(sqrt(fabs(d->d))) / (float)(2 * d->wspolczynnik[0]);

			r->x2 = r->x1;
			u->x2 = -(u->x1);

			if (u->x1 < 0)
				printf("x1r + x1u: %f%fi\n", r->x1, u->x1);
			else
				printf("x1r + x1u: %f+%fi\n", r->x1, u->x1);

			if (u->x2 < 0)
				printf("x2r + x2u: %f%fi\n", r->x2, u->x2);
			else
				printf("x2r + x2u: %f+%fi\n", r->x2, u->x2);
		}
	}
}

void Rownanie::Dodaj()
{
	if (d->d > 0)
	{
		r->s = r->x1 + r->x2;
		printf("Suma: %.2f\n", r->s);
	}
	else if (d->d < 0)
	{

		r->s = r->x1 + r->x2;
		u->s = u->x1 + u->x2;

		if (u->s < 0)
			printf("Suma: %.2f%.2fi\n", r->s, u->s);
		else
			printf("Suma: %.2f+%.2fi\n", r->s, u->s);
	}
}

void Rownanie::Odejmij()
{
	if (d->d > 0)
	{
		r->r = r->x1 - r->x2;
		printf("Roznica: %.2f\n", r->r);
	}
	else if (d->d < 0)
	{
		r->r = r->x1 - r->x2;
		u->r = u->x1 - u->x2;
		if (u->r < 0)
			printf("Roznica: %.2f%.2fi\n", r->r, u->r);
		else
			printf("Roznica: %.2f+%.2fi\n", r->r, u->r);

	}
}

void Rownanie::Pomnoz()
{
	if (d->d > 0)
	{
		r->il = (float)((r->x1) * (r->x2));
		printf("Iloczyn: %.2f\n", r->il);
	}
	else if (d->d < 0)
	{
		r->il = (float)((r->x1) * (r->x2)) - (float)((u->x1) * (u->x2));
		u->il = (float)((r->x1) * (r->x2)) + (float)((u->x1) * (u->x2));

		if (u->il < 0)
			printf("Iloczyn: %.2f%.2fi\n", r->il, u->il);
		else
			printf("Iloczyn: %.2f+%.2fi\n", r->il, u->il);
	}
}

void Rownanie::Podziel()
{
	if (d->d > 0)
	{
		if (r->x2 != 0)
		{
			r->ir = (float)(r->x1) / (r->x2);
			printf("Iloraz: %.2f\n", r->ir);
		}
		else
		{
			printf("Iloraz: nie dziel przez zero!\n");
		}

	}
	else if (d->d < 0)
	{
		r->ir = (float)((r->x1 * r->x2) + (u->x1 * u->x2)) / (pow(r->x2, 2) + pow(u->x2, 2));
		u->ir = (float)((r->x1 * r->x2) - (u->x1 * u->x2)) / (pow(r->x2, 2) + pow(u->x2, 2));
		if (u->ir < 0)
			printf("Iloraz: %.2f%.2fi\n", r->ir, u->ir);
		else
			printf("Iloraz: %.2f+%.2fi\n", r->ir, u->ir);
	}

}

void Rownanie::Postac_Trygonometryczna()
{
	float M_PI = 3.14159265358979323846;
	if ((d->wspolczynnik[0] != 0) && (d->d < 0))
	{
		d->m1 = fabs(((r->x1) * (r->x1)) + ((u->x1) * (u->x1)));
		d->m2 = fabs(((r->x2) * (r->x2)) + ((u->x2) * (u->x2)));
		d->fi1 = atan2(u->x1, r->x1) * 180 / M_PI;
		d->fi2 = atan2(u->x2, r->x2) * 180 / M_PI;

	}
}

void Rownanie::Wyswietl_Wynik()
{
	if (d->wspolczynnik[0] == 0 && d->wspolczynnik[1] == 0 && d->wspolczynnik[2] != 0)
	{
		printf("Rownanie sprzeczne\n");
	}
	else if (d->wspolczynnik[0] == 0 && d->wspolczynnik[1] == 0 && d->wspolczynnik[2] == 0)
	{
		printf("Rownanie nie tozsamosciowe\n");
	}
	else if (d->wspolczynnik[0] == 0)
	{
		printf("\na = %d\n", d->wspolczynnik[0]);
		printf("b = %d\n", d->wspolczynnik[1]);
		printf("c = %d\n", d->wspolczynnik[2]);
		printf("x1r = %.2f\n", r->x1);
	}
	else if (d->d > 0)
	{
		printf("\na = %d\n", d->wspolczynnik[0]);
		printf("b = %d\n", d->wspolczynnik[1]);
		printf("c = %d\n", d->wspolczynnik[2]);
		printf("d = %.2f\n", d->d);
		printf("x1r = %.2f\n", r->x1);
		printf("x2r = %.2f\n", r->x2);
		printf("sr = %.2f\n", r->s);
		printf("rr = %.2f\n", r->r);
		printf("ilr = %.2f\n", r->il);
		printf("ivr = %.2f\n", r->ir);
	}
	else
	{
		printf("\na = %d\n", d->wspolczynnik[0]);
		printf("b = %d\n", d->wspolczynnik[1]);
		printf("c = %d\n", d->wspolczynnik[2]);
		printf("d = %.2f\n", d->d);
		printf("x1r = %.2f\n", r->x1);
		printf("x2r = %.2f\n", r->x2);
		printf("x1u = %.2f\n", u->x1);
		printf("x2u = %.2f\n", u->x2);
		printf("sr = %.2f\n", r->s);
		printf("su = %.2f\n", u->s);
		printf("rr = %.2f\n", r->r);
		printf("ru = %.2f\n", u->r);
		printf("ilr = %.2f\n", r->il);
		printf("ilu = %.2f\n", u->il);
		printf("ivr = %.2f\n", r->ir);
		printf("ivu = %.2f\n", u->ir);
		printf("m1 = %.2f\n", d->m1);
		printf("m2 = %.2f\n", d->m2);
		printf("fi1 = %.2f\n", d->fi1);
		printf("fi2 = %.2f\n", d->fi2);
		printf("%.2f(cos%.2f+isin%.2f)\n", d->m1, d->fi1, d->fi1);
		printf("%.2f(cos%.2f+isin%.2f)\n", d->m2, d->fi2, d->fi2);
		printf("Gamma = %.2f\n", d->gamma);
		printf("Delta = %.2f\n", d->delta);
	}


}

float Rownanie::sgn()
{
	if (u->x1 < 0)
		return -1;
	else if (u->x1 == 0)
		return 0;
	else if (u->x1>0)
		return 1;
}

void Rownanie::Pierwiastkuj()
{
	if (d->wspolczynnik[0] != 0 && d->d < 0)
	{
		d->gamma = sqrt((r->x1 + sqrt(r->x1 * r->x1 + u->x1 * u->x1)) / 2);

		if (u->x1 < 0)
			d->delta = (-1) * sqrt((-r->x1 + sqrt(r->x1 * r->x1 + u->x1 * u->x1)) / 2);
		if (u->x1 == 0)
			d->delta = 0 * sqrt((-r->x1 + sqrt(r->x1 * r->x1 + u->x1 * u->x1)) / 2);
		if (u->x1 > 0)
			d->delta = 1 * sqrt((-r->x1 + sqrt(r->x1 * r->x1 + u->x1 * u->x1)) / 2);
	}
}



int main()
{
	Rownanie *row = new Rownanie();

	row->Podaje_Dane();
	row->Wyswietl_Rownanie();
	row->Oblicz_Delte();
	row->Oblicz_Pierwiastki();
	row->Dodaj();
	row->Odejmij();
	row->Pomnoz();
	row->Podziel();
	row->Postac_Trygonometryczna();
	row->Pierwiastkuj();
	row->Wyswietl_Wynik();
	delete row;
	//row->~Rownanie();

	getchar();
	getchar();
	getchar();
	return 0;
}