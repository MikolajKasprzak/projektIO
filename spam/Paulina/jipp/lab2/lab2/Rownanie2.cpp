#include "stdafx.h"
#include "Rownanie2.h"
#include "Dane.h"
void Rownanie2::Oblicz()
{
	dane->x1.rzeczywisty = (float)-dane->c / dane->b;
}

void Rownanie2::Wyswietl()
{
	printf("x1r = %.2f\n", dane->x1.rzeczywisty);
}
