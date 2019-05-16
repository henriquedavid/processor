#ifndef PC_H
#define PC_H

#include "ula.h"
#include "regs.h"
class PC{
	
	public:
	
		PC(Ula _ula, Regs _regs){
			ula = _ula;
			regs = _regs;
			lastState = false;
			EA = 0;
		}

		void FTE()
		{
			switch(EA)
			{
				case 0 :	
					regs.writeR(0, 36);				//Fornece-se um valor (36) para obeter a raiz.
					regs.writeR(1, 0);				//Valor da raiz ao final da execução.
					regs.writeR(2, 1);				//Incrementa em 1.
					regs.writeR(3, 2);				//Incrementa em 2.
	           		regs.writeR(4, 1);				//Número impar.
	        	    PE = 1;			 
	                break;    
	            case 1:
	            	ula.readA(regs.readR(0));
	            	ula.readB(regs.readR(4));
	            	ula.op(6);
	            	if(ula.getCond2() == false)
	            	{
	            		PE = 5;
	            	}
	            	else
	            	{
	            		PE = 2;
	            	}
	            	break;
	            case 2 :
	            	ula.readA(regs.readR(0)); 
                    ula.readB(regs.readR(4));
                    ula.op(1);
                    regs.writeR(0, ula.writeResult());
                    PE = 3;
                    break; 
	            case 3 :
	            	ula.readA(regs.readR(4));
	            	ula.readB(regs.readR(3));
	            	ula.op(0);
	            	regs.writeR(4, ula.writeResult());
	            	PE = 4;
	            	break;
	            case 4 :
	            	ula.readA(regs.readR(1));
	            	ula.readB(regs.readR(2));
	            	ula.op(0);
	            	regs.writeR(1, ula.writeResult());
	            	PE = 1;
	            	break;
	            case 5 :  
	            	lastState= true; //Último estado
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
		Ula ula;			
		Regs regs;
};

#endif