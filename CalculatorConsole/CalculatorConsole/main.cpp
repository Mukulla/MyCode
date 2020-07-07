#include "MainHeader.h"

#include "Calculator.h"

int _tmain(int argc, _TCHAR* argv[])
{	
	while(argc-- > 1)
	{
		//source expression and result
		std::cout << "Result " << Calculate(*++argv) << endl;
	}	
	return 0;
}