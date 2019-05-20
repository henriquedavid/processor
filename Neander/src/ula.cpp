#include "ula.h"

void ULA::readA(int value)
{
	a = value;
}

void ULA::readB(int value)
{
	b = value;
}

int ULA::writeResult()
{
	return s;
}

void ULA::op(int ulaOP)
{
	switch(ulaOP)
	{
		case 0:
			std::cout << "NOP\n";
			break;
		case 1:
			s = a;
			std::cout << "STA\n";
			break;
		case 2:
			s = a;
			std::cout << "LDA\n";
			break;
		case 3: 
			s = a + b;
			std::cout << a << " + " << b << " = " << s << std::endl;
			break;
		case 4:
			s = a or b;
			std::cout << a << " | " << b << " = " << s << std::endl;
			break;
		case 5:
			s = a and b;
			std::cout << a << " & " << b << " = " << s << std::endl;
			break;
		case 6:
			s = not a;
			std::cout << " ~ " << a << " = " << s << std::endl;
			break;
		case 7:
			//ap.setPosition(a);
			std::cout << "JMP a" << std::endl;
			break;
		case 8:
			if(N == 1) s = a;
			std::cout << "JN a" << std::endl;
			break;
		case 9:
			if(Z == 1) s = a;
			std::cout << "JZ a" << std::endl;
		default:
			break;
	}
}