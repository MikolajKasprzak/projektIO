#pragma once
#include "Rownanie.h"
class Rownanie2 : public Rownanie
{
public:
	Rownanie2(Dane* dane) : Rownanie(dane) {};

	void Oblicz();
	void Wyswietl();
};