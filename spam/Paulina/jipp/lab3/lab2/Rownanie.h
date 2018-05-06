#pragma once
#include <math.h>
class Dane;

class Rownanie {
public:
	Rownanie(Dane* dane);
	virtual void Oblicz() = 0;
	virtual void Wyswietl() = 0;

protected:
	Dane *dane;
	void ObliczDelty();
	void ObliczPierwiastkiDelt();
};