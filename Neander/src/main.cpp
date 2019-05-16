#include <iostream>
#include "pc.h"
#include "ula.h"
#include "regs.h"

int main()
{
	Ula ula;
    Regs regs;
    PC pc(ula, regs);
    
    //Calcula raiz de 36

    for(int _clock=0; _clock < 100; _clock++) {
        pc.FTE();
        pc.updateState();
        if(pc.getLastState() == true) 
        	break;
    }

    std::cout << "\nResultado: " << regs.readR(1) << "\n";
}