#ifndef ULA_H
#define ULA_H

#include <iostream>

#include "ap.h"
#include "mem.h"
#include "regs.h"

class ULA{
	
	public:
		
		ULA(){
			N = 0;
			Z = 0;
			a = 0;
			b = 0;
			s = 0;
		}

		void readA(int value)
		{
			a = value;
		}

		void readB(int value)
		{
			b = value;
		}

		int writeResult()
		{
			return s;
		}

		void op(int ulaOP)
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


	private:
		int a, b, s;
		bool N; //Resultado = negativo.
		bool Z;	//Resultado = zero.
};

#endif