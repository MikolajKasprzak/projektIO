#pragma once
#include "Rownanie.h"
class Rownanie5 : public Rownanie
{
public:
	Rownanie5(Dane* dane) : Rownanie(dane) {};

	void Oblicz();
	void Wyswietl();
};