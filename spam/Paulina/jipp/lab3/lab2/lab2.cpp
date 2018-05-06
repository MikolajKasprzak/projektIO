#include "stdafx.h"
#include <math.h>
#include "ProgramManager.h"

int main()
{
	ProgramManager program;
	program.Init();

	////1)  1,4,1,0 = ok nieca³e 4 i powyzej 0
	////    1,4,4,0 = 2
	////    1,4,5,0 = -2,-2,-2,1
	////2)  0,4,20,0 = -5
	////3)  0,0,5,1 = sp
	////4)  0,0,0,0 = toz
	////5)  0,4,20,20 = -5, -5
	////6)  2,4,0,1 = ok -1.5, -0.5 i urojone +-0.89
	
	return 0;
}

