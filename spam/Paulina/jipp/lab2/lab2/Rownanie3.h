#pragma once
#include "Rownanie.h"
class Rownanie3 : public Rownanie
{
public:
	Rownanie3(Dane* dane) : Rownanie(dane) {};
	void Oblicz();
	void Wyswietl();
};