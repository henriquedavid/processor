#include <iostream>
#include <fstream>
#include <sstream>
#include "pc.h"
#include "ula.h"
#include "regs.h"
#include "mem.h"
#include "ap.h"
void decodificar(std::ifstream & file, Mem & mem, AP & ap)
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
            }
            else if(inst == "STA")
            {
                mem.writeM(ap.getPosition(), 1);
                if(not iss.eof())
                {   
                    iss >> end;
                    mem.writeM(ap.getPosition() + 1, end);
                }
            }
            else if(inst == "LDA")
            {
                mem.writeM(ap.getPosition(), 2);
                if(not iss.eof())
                {
                    iss >> end;
                    mem.writeM(ap.getPosition() + 1, end);
                }
            }
            else if(inst == "ADD")
            {
                mem.writeM(ap.getPosition(), 3);
                if(not iss.eof())
                {
                    iss >> end;
                    mem.writeM(ap.getPosition() + 1, end);
                }
            }
            else if(inst == "OR")
            {
                mem.writeM(ap.getPosition(), 4);
                if(not iss.eof())
                {
                    iss >> end;
                    mem.writeM(ap.getPosition() + 1, end);
                }   
            }
            else if(inst == "AND")
            {
                mem.writeM(ap.getPosition(), 5);
                if(not iss.eof())
                {
                    iss >> end;
                    mem.writeM(ap.getPosition() + 1, end);
                }
            }
            else if(inst == "NOT")
            {
                mem.writeM(ap.getPosition(), 6);
                mem.writeM(ap.getPosition() + 1, 6);
            }
            else if(inst == "JMP")
            {
                mem.writeM(ap.getPosition(), 7);
                if(not iss.eof())
                {
                    iss >> end;
                    mem.writeM(ap.getPosition() + 1, end);
                }
            }
            else if(inst == "JN")
            {
                mem.writeM(ap.getPosition(), 8);
                if(not iss.eof())
                {
                    iss >> end;
                    mem.writeM(ap.getPosition() + 1, end);
                }
            }
            else if(inst == "JZ")
            {
                mem.writeM(ap.getPosition(), 9);
                if(not iss.eof())
                {
                    iss >> end;
                    mem.writeM(ap.getPosition() + 1, end);
                }
            }
            else if(inst == "HLT")
            {
                mem.writeM(ap.getPosition(), 10);
                mem.writeM(ap.getPosition() + 1, 10);
            }
            else{
                std::cout << "Comando desconhecido!\n";
                break;
            }

            ap.increase();
        }
    }
    file.close();
}

int main()
{
    Regs regs;
    Mem mem;
    AP ap;
    std::ifstream ifs("programa.txt");
    
    decodificar(ifs, mem, ap);

    ULA ula;
    PC pc(ula, regs, mem, ap);

    ap.zerar();

    for(int _clock=0; _clock < 100; _clock++) {
        pc.FTE();
        //std::cout << ap.getPosition() << "\n";
        pc.updateState();

        if(pc.getLastState() == true)
        {
            break;
        }
    }


    std::cout << "\nResultado: " << regs.readR() << "\n";

    return 0;
}