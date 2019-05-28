#ifndef ULA_H
#define ULA_H

#include <iostream>

#include "ap.h"
#include "mem.h"
#include "regs.h"

class ULA{
	
	public:
		
		ULA(){
			N = false;
			Z = false;
			a = 0;
			b = 0;
			s = 0;
			currentOperation = "";

		}

		void readA(int value);

		void readB(int value);

		int writeResult();

		void op(int ulaOP);

		bool isZero();

		bool isNegative();

		std::string getOperation();


	private:
		int a, b, s;
		std::string currentOperation;
		bool N; //Resultado = negativo.
		bool Z;	//Resultado = zero.
};

#endif