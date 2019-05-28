#ifndef PC_H
#define PC_H

#include "ula.h"
#include "regs.h"
#include "mem.h"
#include "ap.h"
#include "regsinst.h"

class PC{
	
	public:
	
		PC(ULA & _ula, Regs & _regs, RegsI & _regsi, Mem & _mem, AP & _ap){
			ula = _ula;
			regs = _regs;
			regsi = _regsi;
			mem = _mem;
			ap = _ap;
			lastState = false;
			EA = 0;
		}

		void FTE();

		void updateState();

		bool getLastState();

		void visualizarEstados();


	private:
		int EA, PE; 		//Estado atual, Próximo estado.
		int lastState;		//Último estado (condição de parada).
		ULA ula;			
		Regs regs;
		RegsI regsi;
		Mem mem;
		AP ap;
};

#endif