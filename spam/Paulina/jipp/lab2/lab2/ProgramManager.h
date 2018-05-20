#pragma once
//#include "Dane.h"
//#include "Rownanie.h"

class Dane;
class Rownanie;

class ProgramManager {
public:
	void Init();	
private:
	Dane* dane;
	Rownanie* rownanie;
	void WprowadzDane();
	void WyswietlRownanie();
	void ZrobRownanie();
	void Dodaj();
	void Odejmij();
	void Pomnoz();

};