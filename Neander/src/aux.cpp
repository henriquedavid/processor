#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstring>
#include "pc.h"
#include "ula.h"
#include "regs.h"
#include "mem.h"
#include "ap.h"
#include "aux.h"

int converter(std::string valorBinario)
{
    char vetor[valorBinario.length() + 1]; 
    strcpy(vetor, valorBinario.c_str()); 
    int valor = 0;

    for(unsigned int i = 0; i < valorBinario.length(); i++)
    {
        if(vetor[i] == '1')
        {
            valor += pow(2, valorBinario.length() - i - 1);
            std::cout << valor << "\n";
        }
    }

    return valor;
}


void decodificar(std::ifstream & file, Mem & mem, AP & ap, int & qtd_operacoes)
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
                qtd_operacoes++;
            }
            else if(inst == "STA")
            {
                mem.writeM(ap.getPosition(), 1);
                if(not iss.eof())
                {   
                    iss >> end;
                    mem.writeM(ap.getPosition() + 1, end);
                }
                qtd_operacoes++;
            }
            else if(inst == "LDA")
            {
                mem.writeM(ap.getPosition(), 2);
                if(not iss.eof())
                {
                    iss >> end;
                    mem.writeM(ap.getPosition() + 1, end);
                }
                qtd_operacoes++;
            }
            else if(inst == "ADD")
            {
                mem.writeM(ap.getPosition(), 3);
                if(not iss.eof())
                {
                    iss >> end;
                    mem.writeM(ap.getPosition() + 1, end);
                }
                qtd_operacoes++;
            }
            else if(inst == "OR")
            {
                mem.writeM(ap.getPosition(), 4);
                if(not iss.eof())
                {
                    iss >> end;
                    mem.writeM(ap.getPosition() + 1, end);
                }   
                qtd_operacoes++;
            }
            else if(inst == "AND")
            {
                mem.writeM(ap.getPosition(), 5);
                if(not iss.eof())
                {
                    iss >> end;
                    mem.writeM(ap.getPosition() + 1, end);
                }
                qtd_operacoes++;
            }
            else if(inst == "NOT")
            {
                mem.writeM(ap.getPosition(), 6);
                mem.writeM(ap.getPosition() + 1, 6);
                qtd_operacoes++;
            }
            else if(inst == "JMP")
            {
                mem.writeM(ap.getPosition(), 7);
                if(not iss.eof())
                {
                    iss >> end;
                    mem.writeM(ap.getPosition() + 1, end);
                }
                qtd_operacoes++;
            }
            else if(inst == "JN")
            {
                mem.writeM(ap.getPosition(), 8);
                if(not iss.eof())
                {
                    iss >> end;
                    mem.writeM(ap.getPosition() + 1, end);
                }
                qtd_operacoes++;
            }
            else if(inst == "JZ")
            {
                mem.writeM(ap.getPosition(), 9);
                if(not iss.eof())
                {
                    iss >> end;
                    mem.writeM(ap.getPosition() + 1, end);
                }
                qtd_operacoes++;
            }
            else if(inst == "HLT")
            {
                mem.writeM(ap.getPosition(), 10);
                mem.writeM(ap.getPosition() + 1, 10);
                qtd_operacoes++;
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