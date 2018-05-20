#pragma once
#include "Rownanie.h"
class Rownanie4 : public Rownanie
{
public:
	Rownanie4(Dane* dane) : Rownanie(dane) {};

	void Oblicz();
	void Wyswietl();
};