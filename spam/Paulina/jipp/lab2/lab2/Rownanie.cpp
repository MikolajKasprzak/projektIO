#include "stdafx.h"
#include "Dane.h"
#include "Rownanie.h"

Rownanie::Rownanie(Dane* dane)
{
	this->dane = dane;
	ObliczDelty();
	ObliczPierwiastkiDelt();
}

void Rownanie::ObliczDelty()
{
	dane->delta.urojona = (float)-4.0*dane->a*dane->d;
	dane->delta.rzeczywista = (float)dane->b*dane->b - 4 * dane->a*dane->c;

}
void Rownanie::ObliczPierwiastkiDelt()
{
	dane->delta.pierwiastek.urojona = sqrt((sqrt(dane->delta.rzeczywista*dane->delta.rzeczywista + dane->delta.urojona*dane->delta.urojona) - dane->delta.urojona) / 2.0);
	dane->delta.pierwiastek.rzeczywista = sqrt((sqrt(dane->delta.rzeczywista*dane->delta.rzeczywista + dane->delta.urojona*dane->delta.urojona) + dane->delta.urojona) / 2.0);
}
