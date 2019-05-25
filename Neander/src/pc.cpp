#include "pc.h"
#include <cstring>
#include <cmath>

void PC::FTE()
{
	switch(EA)
	{
		case 0 :	//Colocando valores na memoria.
			mem.writeM(128, binaryToDecimal("11011100"));	//220
			mem.writeM(129, binaryToDecimal("10100111"));	//167
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
			std::cout << ula.writeResult() << "\n";
			
			PE = mem.readM(ap.getPosition());

			break;

		case 11:	//HLT - Finaliza o programa
	
			lastState = true;

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

int PC::binaryToDecimal(std::string s)
{
	char str[s.length()];

	strcpy(str, s.c_str());

	int value = 0;
	
	for(unsigned int i = s.length() - 1; i >= 0; i--)
	{
		if(str[i] == '0')
		{
			str[i] = '1';
		}
		else
		{
			str[i] = '0';
		}
	}

	for(unsigned int i = s.length - 1; i >= 0; i--)
	{
		if(str[i] == '0')
		{
			str[i] = '1';
			break;
		}
		else
		{
			str[i] = '0';
		}
	}

	return value;
}
