#include "stdafx.h"
#include "Rownanie5.h"
#include "Dane.h"

void Rownanie5::Oblicz()
{
	dane->x1.rzeczywisty = (float)(-dane->b - dane->delta.pierwiastek.rzeczywista) / (2.0f * dane->a);
	dane->x2.rzeczywisty = (float)(-dane->b - dane->delta.pierwiastek.rzeczywista) / (2.0f * dane->a);
	dane->x3.rzeczywisty = (float)(-dane->b + dane->delta.pierwiastek.rzeczywista) / (2.0f * dane->a);
	dane->x4.rzeczywisty = (float)(-dane->b + dane->delta.pierwiastek.rzeczywista) / (2.0f * dane->a);
	dane->x1.urojony = (float)(-dane->delta.pierwiastek.urojona) / (2.0f * dane->a);
	dane->x2.urojony = (float)(dane->delta.pierwiastek.urojona) / (2.0f *dane->a);
	dane->x3.urojony = (float)(dane->delta.pierwiastek.urojona) / (2.0f * dane->a);
	dane->x4.urojony = (float)(-dane->delta.pierwiastek.urojona) / (2.0f * dane->a);
}

void Rownanie5::Wyswietl()
{
	printf("\nx1r = %f \t x1u = %f", dane->x1.rzeczywisty, dane->x1.urojony);
	printf("\nx2r = %f \t x2u = %f", dane->x2.rzeczywisty, dane->x2.urojony);
	printf("\nx3r = %f \t x3u = %f", dane->x3.rzeczywisty, dane->x3.urojony);
	printf("\nx4r = %f \t x4u = %f", dane->x4.rzeczywisty, dane->x4.urojony);
}
