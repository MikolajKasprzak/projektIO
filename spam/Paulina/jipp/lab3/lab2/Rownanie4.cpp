#include "stdafx.h"
#include "Rownanie4.h"
#include "Dane.h"

void Rownanie4::Oblicz()
{
	dane->x1.rzeczywisty = (float)-dane->c / dane->b;
	dane->x1.urojony = (float)-dane->d / dane->b;
}

void Rownanie4::Wyswietl()
{
	printf("x1r = %.2f\n", dane->x1.rzeczywisty);
	printf("x1u = %.2f\n", dane->x1.urojony);
}
