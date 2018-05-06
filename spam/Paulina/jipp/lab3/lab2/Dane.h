#pragma once
#include "Delta.h"
#include "Pierwiastek.h"
#include "LiczbaZespolona.h"
struct Dane
{
	int a, b, c, d;
	Delta delta;
	Pierwiastek x1, x2, x3, x4;
	LiczbaZespolona suma, roznica, iloczyn;
};
