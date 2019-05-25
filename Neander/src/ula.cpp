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
		case 1:
			std::cout << "NOP\n";
			break;
		case 2:
			s = a;
			std::cout << "STA\n";
			break;
		case 3:
			s = a;
			std::cout << "LDA\n";
			break;
		case 4: 
			s = a + b;

			if( s == 0)
			{
				Z = 1;
			}

			if(s < 0)
			{
				N = 1;
			}

			std::cout << "ADD" << std::endl;
			break;

		case 5:
			s = a or b;

			if( s == 0)
			{
				Z = 1;
			}

			if(s < 0)
			{
				N = 1;
			}

			std::cout << "OR" << std::endl;
			break;
		case 6:

			s = a and b;

			if( s == 0)
			{
				Z = 1;
			}

			if(s < 0)
			{
				N = 1;
			}

			std::cout << "AND" << std::endl;
			break;
		case 7:
			s = not a;

			if( s == 0)
			{
				Z = 1;
			}

			if(s < 0)
			{
				N = 1;
			}

			std::cout << "NOT" << std::endl;
			break;
		case 8:
			s = a;
			std::cout << "JMP" << std::endl;
			break;
		case 9:
			if(N == 1) s = a;
			std::cout << "JN" << std::endl;
			break;
		case 10:
			if(Z == 1) s = a;
			std::cout << "JZ" << std::endl;
		default:
			break;
	}
}