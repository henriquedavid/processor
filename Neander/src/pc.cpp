#include "pc.h"

void PC::FTE()
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

void PC::updateState()
{
	EA = PE;
}

bool PC::getLastState()
{
	return lastState;
}
