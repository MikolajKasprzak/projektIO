#include "stdafx.h"
#include "Rownanie1.h"
#include "Dane.h"

void Rownanie1::Oblicz()
{
	if (dane->delta.rzeczywista > 0)
	{
		dane->x1.rzeczywisty = (float)(-dane->b - sqrt(dane->delta.rzeczywista)) / (2.0f * dane->a);
		dane->x2.rzeczywisty = (float)(-dane->b + sqrt(dane->delta.rzeczywista)) / (2.0f * dane->a);
	}
	//1.2)
	else if (dane->delta.rzeczywista == 0)
	{
		dane->x1.rzeczywisty = (float)-dane->b / (2.0f * dane->a);
	}
	//1.3)
	else if (dane->delta.rzeczywista < 0)
	{
		dane->x1.rzeczywisty = (float)-dane->b / (2.0f * dane->a);
		dane->x1.urojony = (float)-(sqrt(fabs(dane->delta.rzeczywista)) / (2.0f * dane->a));
		dane->x2.rzeczywisty = dane->x1.rzeczywisty;
		dane->x2.urojony = -dane->x1.urojony;
	}
}

void Rownanie1::Wyswietl()
{
	//1.1)
	if (dane->delta.rzeczywista > 0)
	{
		printf("x1r = %.2f\n", dane->x1.rzeczywisty);
		printf("x2r = %.2f\n", dane->x2.rzeczywisty);
	}
	//1.2)
	else if (dane->delta.rzeczywista == 0)
	{
		printf("x1r = %.2f\n", dane->x1.rzeczywisty);
	}
	//1.3)
	else if (dane->delta.rzeczywista < 0)
	{
		printf("x1r = %.2f\n", dane->x1.rzeczywisty);
		printf("x1u = %.2f\n", dane->x1.urojony);
		printf("x2r = %.2f\n", dane->x2.rzeczywisty);
		printf("x2u = %.2f\n", dane->x2.urojony);
	}
}
