#include "stdafx.h"
#include "ProgramManager.h"
#include "Dane.h"
#include "Rownanie.h"
#include "Rownanie1.h"
#include "Rownanie2.h"
#include "Rownanie3.h"
#include "Rownanie4.h"
#include "Rownanie5.h"

void ProgramManager::Init()
{
	dane = new Dane();

	WprowadzDane();
	WyswietlRownanie();
	ZrobRownanie();
}

void ProgramManager::WprowadzDane()
{
	printf("Podaj a: ");	scanf_s("%d", &dane->a);
	printf("Podaj b: ");	scanf_s("%d", &dane->b);
	printf("Podaj c: ");	scanf_s("%d", &dane->c);
	printf("Podaj d: ");	scanf_s("%d", &dane->d);
}

void ProgramManager::WyswietlRownanie()
{
	printf("%dxx ", dane->a);
	if (dane->b<0) printf("%dx ", dane->b); else  printf("+%dx ", dane->b);
	if (dane->c<0) printf("%d ", dane->c); else  printf("+%d ", dane->c);
	if (dane->d<0) printf("%di ", dane->d); else  printf("+%di ", dane->d);
	printf("\n\n");
}


void ProgramManager::Dodaj()
{
	//przypadek 1
	if (dane->delta.rzeczywista > 0 && dane->delta.urojona == 0)
	{
		dane->suma.rzeczywista = dane->x1.rzeczywisty + dane->x2.rzeczywisty;
	}
	//przypadek 2
	if (dane->delta.rzeczywista < 0 && dane->delta.urojona == 0)
	{
		dane->suma.rzeczywista = dane->x1.rzeczywisty + dane->x2.rzeczywisty;
		dane->suma.urojona = dane->x1.urojony + dane->x2.urojony;
	}
	//przypadek 3
	if (dane->delta.urojona)
	{
		dane->suma.rzeczywista = dane->x1.rzeczywisty + dane->x2.rzeczywisty + dane->x3.rzeczywisty + dane->x4.rzeczywisty;
		dane->suma.urojona = dane->x1.urojony + dane->x2.urojony + dane->x3.urojony + dane->x4.urojony;
	}
}

void ProgramManager::Odejmij()
{
	//przypadek 1
	if (dane->delta.rzeczywista > 0 && dane->delta.urojona == 0)
	{
		dane->roznica.rzeczywista = dane->x1.rzeczywisty - dane->x2.rzeczywisty;
	}
	//przypadek 2
	if (dane->delta.rzeczywista < 0 && dane->delta.urojona == 0)
	{
		dane->roznica.rzeczywista = dane->x1.rzeczywisty - dane->x2.rzeczywisty;
		dane->roznica.urojona = dane->x1.urojony - dane->x2.urojony;
	}
	//przypadek 3
	if (dane->delta.urojona)
	{
		dane->roznica.rzeczywista = dane->x1.rzeczywisty - dane->x2.rzeczywisty - dane->x3.rzeczywisty - dane->x4.rzeczywisty;
		dane->roznica.urojona = dane->x1.urojony - dane->x2.urojony - dane->x3.urojony - dane->x4.urojony;
	}
}

void ProgramManager::Pomnoz()
{
	//przypadek 1
	if (dane->delta.rzeczywista > 0 && dane->delta.urojona == 0)
	{
		dane->iloczyn.rzeczywista = dane->x1.rzeczywisty * dane->x2.rzeczywisty;
	}
	//przypadek 2
	if (dane->delta.rzeczywista < 0 && dane->delta.urojona == 0)
	{
		dane->iloczyn.rzeczywista = dane->x1.rzeczywisty * dane->x2.rzeczywisty - dane->x1.urojony * dane->x2.urojony;
		dane->iloczyn.urojona = dane->x1.rzeczywisty*dane->x2.urojony + dane->x2.rzeczywisty*dane->x1.urojony;
	}
	//przypadek 3
	if (dane->delta.urojona)
	{
		dane->iloczyn.rzeczywista = (dane->x1.rzeczywisty*dane->x2.rzeczywisty - dane->x1.urojony * dane->x2.urojony)*(dane->x3.rzeczywisty*dane->x4.rzeczywisty - dane->x3.urojony * dane->x4.urojony) - (dane->x1.rzeczywisty*dane->x2.urojony + dane->x2.rzeczywisty*dane->x1.urojony)*(dane->x3.rzeczywisty*dane->x4.urojony + dane->x4.rzeczywisty*dane->x3.urojony);
		dane->iloczyn.urojona = (dane->x1.rzeczywisty*dane->x2.rzeczywisty - dane->x1.urojony * dane->x2.urojony)*(dane->x3.rzeczywisty*dane->x4.rzeczywisty + dane->x3.urojony * dane->x4.urojony) + (dane->x3.rzeczywisty*dane->x4.rzeczywisty - dane->x3.urojony * dane->x4.urojony)*(dane->x1.rzeczywisty*dane->x2.rzeczywisty + dane->x1.urojony * dane->x2.urojony);
	}
}


void ProgramManager::ZrobRownanie()
{
	//1
	if (dane->a != 0 && dane->d == 0)
	{
		rownanie = new Rownanie1(dane);
		rownanie->Oblicz();
		rownanie->Wyswietl();

	}
	//2)
	else if (dane->a == 0 && dane->b != 0 && dane->d == 0)
	{
		rownanie = new Rownanie2(dane);
		rownanie->Oblicz();
		rownanie->Wyswietl();
	}
	//3)
	else if (dane->a == 0 && dane->b == 0 && (dane->c != 0 || dane->d != 0))
	{
		rownanie = new Rownanie3(dane);
		rownanie->Wyswietl();
	}
	//4)
	else if (dane->a == 0 && dane->b == 0 && dane->c == 0 && dane->d == 0)
	{
		rownanie = new Rownanie3(dane);
		rownanie->Wyswietl();
	}
	//5)
	else if (dane->a == 0 && dane->b != 0 && dane->d != 0)
	{
		rownanie = new Rownanie4(dane);
		rownanie->Oblicz();
		rownanie->Wyswietl();
	}
	//6)
	else if (dane->a != 0 && dane->d != 0)
	{
		rownanie = new Rownanie5(dane);
		rownanie->Oblicz();
		rownanie->Wyswietl();
	}

	//*** Pozostale operacje ***///
	if (dane->delta.rzeczywista > 0 && dane->d == 0 && dane->a != 0)
	{
		Dodaj();
		Odejmij();
		Pomnoz();
		printf("sr = %.2f\n", dane->suma.rzeczywista);
		printf("rr = %.2f\n", dane->roznica.rzeczywista);
		printf("ilr = %.2f\n", dane->iloczyn.rzeczywista);
	}
	if ((dane->delta.rzeczywista < 0 && dane->d == 0) || (dane->a != 0 && dane->d != 0))
	{
		Dodaj();
		Odejmij();
		Pomnoz();
		printf("sr = %.2f\n", dane->suma.rzeczywista);
		printf("su = %.2f\n", dane->suma.urojona);
		printf("rr = %.2f\n", dane->roznica.rzeczywista);
		printf("ru = %.2f\n", dane->roznica.urojona);
		printf("ilr = %.2f\n", dane->iloczyn.rzeczywista);
		printf("ilu = %.2f\n", dane->iloczyn.urojona);
	}
}
