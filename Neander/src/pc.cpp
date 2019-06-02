#include "pc.h"
#include <cstring>
#include <cmath>

void PC::FTE()
{
	switch(EA)
	{
		case 0 :	
			//Colocando valores na memoria para a operação de soma e subtração.
			mem.writeM(128, 220);	
			mem.writeM(129, 100);
			mem.writeM(130, 12);

			PE = mem.readM(ap.getPosition());
			break;
		





		case 1 :	//NOP - Não faz nada.
			PE = mem.readM(ap.getPosition());
			break;

		




		case 2:		//STA - Memória <- Acumulador
			ula.readA(regs.readR());
			regsi.writeRI(mem.readM(ap.getPosition()));
	    	PE = 21;
	    	break;
	    case 21:
	   		ula.op(regsi.readRI());
	   		PE = 22;
	   		break;
	   	case 22:
	   		mem.writeM(mem.readM(ap.getPosition() + 1), ula.writeResult());
	   		ap.increase();
	    	PE = mem.readM(ap.getPosition());
	   		break;
	    




	    case 3:		//LDA - Acumulador <- Memória
			ula.readA(mem.readM(mem.readM(ap.getPosition() + 1)));
			regsi.writeRI(mem.readM(ap.getPosition()));
			PE = 31;
	    	break;

	    case 31:
	    	ula.op(regsi.readRI());
	    	PE = 32;
	    	break;
	    case 32:
	    	regs.writeR(ula.writeResult());
			ap.increase();
			PE = mem.readM(ap.getPosition());
	    	break;

	    




	    case 4:		//ADD - Acumulador <- Acumulador + Memória
	    	ula.readA(regs.readR());
	    	ula.readB(mem.readM(mem.readM(ap.getPosition() + 1)));
	    	regsi.writeRI(mem.readM(ap.getPosition()));
	    	PE = 41;
			break;
		case 41:
			ula.op(regsi.readRI());
			PE = 42;
			break;
		case 42:
			regs.writeR(ula.writeResult());
			ap.increase();
			PE = mem.readM(ap.getPosition());
			break;





		case 5:		//NOT - Acumulador <- Acumulador or Memória
			ula.readA(regs.readR());
			ula.readB(mem.readM(mem.readM(ap.getPosition() + 1)));
			regsi.writeRI(mem.readM(ap.getPosition()));
			PE = 51;
			break;
		case 51:
			ula.op(regsi.readRI());
			PE = 52;
			break;
		case 52:
			regs.writeR(ula.writeResult());
			ap.increase();
			PE = mem.readM(ap.getPosition());
			break;





		case 6:		//And - Acumulador <- Acumulador and Memória
			ula.readA(regs.readR());
			ula.readB(mem.readM(mem.readM(ap.getPosition() + 1)));
			regsi.writeRI(mem.readM(ap.getPosition()));
			PE = 61;
			break;
		case 61:
			ula.op(regsi.readRI());
			PE = 62;
			break;
		case 62:
			regs.writeR(ula.writeResult());
			ap.increase();
			PE = mem.readM(ap.getPosition());
			break;




		case 7:
			ula.readA(regs.readR());
			regsi.writeRI(mem.readM(ap.getPosition()));
			PE = 71;
			break;
		case 71:
			ula.op(regsi.readRI());
			PE = 72;
			break;
		case 72:
			regs.writeR(ula.writeResult());
			ap.increase();
			PE = mem.readM(ap.getPosition());
			break;





		case 8:		//JMP - Apontador de programa <- endereco
			ula.readA(mem.readM(ap.getPosition() + 1));
			regsi.writeRI(mem.readM(ap.getPosition()));
			PE = 81;
			break;
		case 81:
			ula.op(regsi.readRI());
			PE = 82;
			break;
		case 82:
			ap.setPosition(ula.writeResult());
			PE = mem.readM(ap.getPosition());		
			break;




		case 9:		//JN - Condicional - Apontador de programa <- endereco
			ula.readA(mem.readM(ap.getPosition() + 1));
			regsi.writeRI(mem.readM(ap.getPosition()));
			PE = 91;
			break;
		case 91:
			ula.readB(ap.getPosition() + 2);
			ula.op(regsi.readRI());
			PE = 92;
			break;
		case 92:
			ap.setPosition(ula.writeResult());
			PE = mem.readM(ap.getPosition());		
			break;


		

		case 10:	//JZ - Condicional - Apontador de programa <- endereco
			ula.readA(mem.readM(ap.getPosition() + 1));
			regsi.writeRI(mem.readM(ap.getPosition()));
			PE = 101;
			break;
		case 101:
			ula.readB(ap.getPosition() + 2);
			ula.op(regsi.readRI());
			PE = 102;
			break;
		case 102:
			ap.setPosition(ula.writeResult());
			PE = mem.readM(ap.getPosition());		
			break;




		case 11:	//HLT - Finaliza o programa
			regsi.writeRI(mem.readM(ap.getPosition()));
			PE = 111; 
			break;
		case 111:
			ula.op(regsi.readRI());
			lastState = true;
			break;





		case 12:		//SUB - Acumulador <- Acumulador - Memória
	    	ula.readA(regs.readR());
	    	ula.readB(mem.readM(mem.readM(ap.getPosition() + 1)));
	    	regsi.writeRI(mem.readM(ap.getPosition()));
	    	PE = 121;
			break;
		case 121:
			ula.op(regsi.readRI());
			PE = 122;
			break;
		case 122:
			regs.writeR(ula.writeResult());
			ap.increase();
			PE = mem.readM(ap.getPosition());
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