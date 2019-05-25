#ifndef PC_H
#define PC_H

#include "ula.h"
#include "regs.h"
#include "mem.h"
#include "ap.h"

class PC{
	
	public:
	
		PC(ULA & _ula, Regs & _regs, Mem & _mem, AP & _ap){
			ula = _ula;
			regs = _regs;
			mem = _mem;
			ap = _ap;
			lastState = false;
			EA = 0;
		}

		void FTE();

		void updateState();

		bool getLastState();

		int binaryToDecimal(std::string);


	private:
		int EA, PE; 		//Estado atual, Próximo estado.
		int lastState;		//Último estado (condição de parada).
		ULA ula;			
		Regs regs;
		Mem mem;
		AP ap;
};

#endif