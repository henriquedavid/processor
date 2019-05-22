#include <iostream>
#include <fstream>
#include "pc.h"
#include "ula.h"
#include "regs.h"
#include "mem.h"
#include "ap.h"
#include "aux.h"

int main()
{
    Regs regs;
    Mem mem;
    AP ap;
    std::ifstream ifs("programa.txt");
    int qtd_operacoes = 0;
    int qtd_estados = 5;
    
    decodificar(ifs, mem, ap, qtd_operacoes);

    ULA ula;
    PC pc(ula, regs, mem, ap);

    for(int _clock=0; _clock < qtd_operacoes*qtd_estados; _clock++) {
        
        pc.FTE();
    
        pc.updateState();

        if(pc.getLastState() == true)
        {
            break;
        }
    }


    std::cout << "\nResultado: " << regs.readR() << "\n";


    return 0;
}