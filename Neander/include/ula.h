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

		void readA(int value);

		void readB(int value);

		int writeResult();

		void op(int ulaOP);


	private:
		int a, b, s;
		bool N; //Resultado = negativo.
		bool Z;	//Resultado = zero.
};

#endif