#include "pc.h"
#include "aux.h"
#include <cstring>

void PC::FTE()
{
	if(mem.readM(ap.getPosition()) == 0)
	{
		EA = 1;
	}
	else if(mem.readM(ap.getPosition) == 1)
	{
		EA = 2;
	}
	else if(mem.readM(ap.getPosition()) == 2)
	{
		EA = 3;
	}
	else if(mem.readM(ap.getPosition()) == 3)
	{
		EA = 3;
	}
	else if(mem.readM(ap.getPosition()) == 6)
	{
		EA = 8;
	}
	else if(mem.readM(ap.getPosition()) == 7)
	{
		EA = 9;
	}
	else if(mem.readM(ap.getPosition()) == 8)
	{
		EA = 10;
	}
	else if(mem.readM(ap.getPosition()) == 9)
	{
		EA = 11;
	}

	switch(EA)
	{
		case 0 :
			EA = 10;
			break;
		case 1 :
			ula.readA(regs.readR());
			ula.op(1);
			mem.writeM(ap.getPosition() + 1, ula.writeResult());
			break;
		case 2 :
			break;

		case 3 :	
			mem.writeM(128, converter("11011100"));	//220
			mem.writeM(129, converter("10100111"));	//167
			mem.writeM(200, converter("10110001"));	//177
	        PE = 4;			 
	        break;    
	    case 4 :
	     	ula.readA(mem.readM(mem.readM(ap.getPosition() + 1)));	//
            PE = 5;													//
            break; 													//
	    case 5 :													//
	        ula.readB(regs.readR());								//
	        PE = 6;													//
	        break;													//
	    case 6 :													//
	        ula.op(mem.readM(ap.getPosition()));					//
	        ap.increase();											//
	        PE = 7;													//					
	    	break;													//
	    case 7 :  													//
	        regs.writeR(ula.writeResult());							//ADD e LDA
	        PE = 10;
	        break;
	    case 8 :													//STA
	    	break;
	    case 9 : 
	    	break;
	    case 10 :
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
