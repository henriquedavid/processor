#include <iostream>
#include <fstream>
#include <sstream>
#include "pc.h"
#include "ula.h"
#include "regs.h"
#include "mem.h"
#include "ap.h"
void decodificar(std::ifstream & file, Mem & mem, AP & ap, int & valorDeParada)
{
    std::string inst;

    if(file.is_open())
    {
        std::string line;
        int end;

        while(getline(file, line))
        {
            if(line == "")
            {
                continue;
            }

            std::istringstream iss(line);
            iss >> inst;

            if(inst == "NOP")
            {
                mem.writeM(ap.getPosition(), 0);
                mem.writeM(ap.getPosition() + 1, 0);
                valorDeParada++;
            }
            else if(inst == "STA")
            {
                mem.writeM(ap.getPosition(), 1);
                if(not iss.eof())
                {   
                    iss >> end;
                    mem.writeM(ap.getPosition() + 1, end);
                }
                valorDeParada++;
            }
            else if(inst == "LDA")
            {
                mem.writeM(ap.getPosition(), 2);
                if(not iss.eof())
                {
                    iss >> end;
                    mem.writeM(ap.getPosition() + 1, end);
                }
                valorDeParada++;
            }
            else if(inst == "ADD")
            {
                mem.writeM(ap.getPosition(), 3);
                if(not iss.eof())
                {
                    iss >> end;
                    mem.writeM(ap.getPosition() + 1, end);
                }
                valorDeParada++;
            }
            else if(inst == "OR")
            {
                mem.writeM(ap.getPosition(), 4);
                if(not iss.eof())
                {
                    iss >> end;
                    mem.writeM(ap.getPosition() + 1, end);
                }   
                valorDeParada++;
            }
            else if(inst == "AND")
            {
                mem.writeM(ap.getPosition(), 5);
                if(not iss.eof())
                {
                    iss >> end;
                    mem.writeM(ap.getPosition() + 1, end);
                }
                valorDeParada++;
            }
            else if(inst == "NOT")
            {
                mem.writeM(ap.getPosition(), 6);
                mem.writeM(ap.getPosition() + 1, 6);
                valorDeParada++;
            }
            else if(inst == "JMP")
            {
                mem.writeM(ap.getPosition(), 7);
                if(not iss.eof())
                {
                    iss >> end;
                    mem.writeM(ap.getPosition() + 1, end);
                }
                valorDeParada++;
            }
            else if(inst == "JN")
            {
                mem.writeM(ap.getPosition(), 8);
                if(not iss.eof())
                {
                    iss >> end;
                    mem.writeM(ap.getPosition() + 1, end);
                }
                valorDeParada++;
            }
            else if(inst == "JZ")
            {
                mem.writeM(ap.getPosition(), 9);
                if(not iss.eof())
                {
                    iss >> end;
                    mem.writeM(ap.getPosition() + 1, end);
                }
                valorDeParada++;
            }
            else if(inst == "HLT")
            {
                mem.writeM(ap.getPosition(), 10);
                mem.writeM(ap.getPosition() + 1, 10);
                valorDeParada++;
            }
            else{
                std::cerr << "Comando desconhecido!\n";
                break;
            }

            ap.increase();
        }
        file.close();
    }
    else
    {
        std::cerr << "O arquivo não foi aberto!\n";
        return;
    }
}

int main()
{
    Regs regs;
    Mem mem;
    AP ap;
    std::ifstream ifs("programa.txt");
    int valorDeParada = 0;
    
    decodificar(ifs, mem, ap, valorDeParada);

    std::cout << valorDeParada << "\n";

    ULA ula;
    PC pc(ula, regs, mem, ap);

    ap.zerar();

    for(int _clock=0; _clock < valorDeParada; _clock++) {
        
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