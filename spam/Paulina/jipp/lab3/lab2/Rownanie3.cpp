#include "stdafx.h"
#include "Rownanie3.h"
#include "Dane.h"

void Rownanie3::Oblicz()
{
}

void Rownanie3::Wyswietl()
{
	if(dane->c == 0 && dane->d == 0)printf("Rownanie tozsamosciowe\n");
	else printf("Rownanie sprzeczne\n");


}
