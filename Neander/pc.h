#ifndef PC_H
#define PC_H

#include "ula.h"
#include "regs.h"
#include "mem.h"
#include "ap.h"

class PC{
	
	public:
	
		PC(ULA _ula, Regs _regs, Mem _mem, AP & _ap){
			ula = _ula;
			regs = _regs;
			mem = _mem;
			ap = _ap;
			ap.zerar();
			lastState = false;
			EA = 0;
		}

		void FTE()
		{
			std::cout << ap.getPosition() << "\n";
			switch(EA)
			{
				case 0 :	
					mem.writeM(128, 256);
					mem.writeM(129, 250);
					mem.writeM(200, 5);
	        	    PE = 1;			 
	                break;    
	            case 1 :
	            	ula.readA(mem.readM(mem.readM(ap.getPosition() + 1)));
                    PE = 2;
                    break; 
	            case 2 :
	            	ula.readB(regs.readR());
	            	PE = 3;
	            	break;
	            case 3 :
	            	ula.op(mem.readM(ap.getPosition()));
	            	ap.increase();
	            	PE = 4;
	            	break;
	            case 4 :  
	            	regs.writeR(ula.writeResult());
	            	PE = 0;
	            	break;
	            default: 
	            	break;    
			}
		}

		void updateState()
		{
			EA = PE;
		}

		bool getLastState()
		{
			return lastState;
		}


	private:
		int EA, PE; 		//Estado atual, Próximo estado.
		int lastState;		//Último estado (condição de parada).
		ULA ula;			
		Regs regs;
		Mem mem;
		AP ap;
};

#endif