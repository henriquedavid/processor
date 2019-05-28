#include "pc.h"
#include <cstring>
#include <cmath>

void PC::FTE()
{
	switch(EA)
	{
		case 0 :	//Colocando valores na memoria.
			mem.writeM(128, 220);	//220
			mem.writeM(129, -220);	//167
			PE = mem.readM(ap.getPosition());
			break;
		case 1 :	//NOP - Não faz nada.

			break;

		case 2:		//STA - Memória <- Acumulador
		
			ula.readA(regs.readR());
			ula.op(mem.readM(ap.getPosition()));
			mem.writeM(mem.readM(ap.getPosition() + 1), ula.writeResult());

	    	ap.increase();
	    	PE = mem.readM(ap.getPosition());
	    	break;
	    /*
	    case 2.1:
		*/
	    
	    case 3:		//LDA - Acumulador <- Memória
	  
			ula.readA(mem.readM(mem.readM(ap.getPosition() + 1)));
			ula.op(mem.readM(ap.getPosition()));
			regs.writeR(ula.writeResult());

			ap.increase();
			PE = mem.readM(ap.getPosition());
	    	break;

	    case 4:		//ADD - Acumulador <- Acumulador + Memória

	    	ula.readA(regs.readR());
	    	ula.readB(mem.readM(mem.readM(ap.getPosition() + 1)));
	    	ula.op(mem.readM(ap.getPosition()));
	    	regs.writeR(ula.writeResult());

			ap.increase();
			PE = mem.readM(ap.getPosition());

			break;

		case 8:		//JMP - Apontador de programa <- endereco

			ula.readA(mem.readM(mem.readM(ap.getPosition() + 1)));
			ula.op(mem.readM(ap.getPosition()));
			ap.setPosition(ula.writeResult());
			
			PE = mem.readM(ap.getPosition());

			break;

		case 11:	//HLT - Finaliza o programa
	
			lastState = true;
			ula.op(11);
			ap.increase();

			break;

	    default: 
	      	break;    
	}
}

void PC::updateState()
{
	EA = PE;
}

bool PC::getLastState()
{
	return lastState;
}

void PC::visualizarEstados()
{
	regsi.writeRI(8);
    std::cout << "Registrador:              " << regs.readR() << std::endl;
    std::cout << "Registrador de instrução: " << regsi.readRI() << std::endl;
    std::cout << "Contador de programa      " << ap.getPosition() << std::endl;
    std::cout << "Zero:                     " << ula.isZero() << std::endl;
    std::cout << "Negativo:                 " << ula.isNegative() << std::endl;
    std::cout << "Operação da ula:          " << ula.getOperation() << std::endl;
    std::cout << "Memória:                  " << std::endl;
    mem.showMemory();
    std::cout << std::endl;
}