#pragma once
#include "Rownanie.h"

struct Dane;
class Rownanie1 : public Rownanie
{
public:
	Rownanie1(Dane* dane) : Rownanie( dane ) {};

	void Oblicz();
	void Wyswietl();
};