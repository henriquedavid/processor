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

bool ULA::isZero()
{
	return Z;
}

bool ULA::isNegative()
{
	return N;
}

std::string ULA::getOperation()
{
	return currentOperation;
}

void ULA::op(int ulaOP)
{
	switch(ulaOP)
	{
		case 1:
			currentOperation = "NOP";
			break;
		case 2:
			s = a;
			currentOperation = "STA";
			break;
		case 3:
			s = a;
			currentOperation = "LDA";
			break;
		case 4: 
			s = a + b;

			if( s == 0)
			{
				Z = true;
			}
			else
			{
				Z = false;
			}

			if(s < 0)
			{
				N = true;
			}
			else
			{
				N = false;
			}

			currentOperation = "ADD";
			break;

		case 5:
			s = a or b;

			if( s == 0)
			{
				Z = true;
			}
			else
			{
				Z = false;
			}

			if(s < 0)
			{
				N = true;
			}
			else
			{
				N = false;
			}

			currentOperation = "OR";
			break;
		case 6:

			s = a and b;

			if( s == 0)
			{
				Z = true;
			}
			else
			{
				Z = false;
			}

			if(s < 0)
			{
				N = true;
			}
			else
			{
				N = false;
			}

			currentOperation = "AND";
			break;
		case 7:
			s = not a;

			if( s == 0)
			{
				Z = true;
			}
			else
			{
				Z = false;
			}

			if(s < 0)
			{
				N = true;
			}
			else
			{
				N = false;
			}

			currentOperation = "NOT";
			break;
		case 8:
			s = a;
			currentOperation = "JMP";
			break;
		case 9:
			if(N == true) 
			{
				s = a;
			}
			else
			{
				s = b;
			}
			currentOperation = "JN";
			break;
		case 10:
			if(Z == true)
			{
				s = a;
			}
			else
			{
				s = b;
			}
			currentOperation = "JZ";
			break;
		case 11:
			currentOperation = "HLT";
			break;
		default:
			break;
	}
}