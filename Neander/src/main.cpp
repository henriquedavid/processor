#include <iostream>
#include <fstream>
#include <sstream>
#include "pc.h"
#include "ula.h"
#include "regs.h"
#include "mem.h"
#include "ap.h"
void inserirInstrucoes(std::ifstream & file, Mem & mem)
{
    if(not file.is_open())
    {
        std::cout << "O arquivo não pôde ser aberto!\n";
        return;
    }
    else
    {   std::string palavra;
        std::string instrucao;
        int endereco;
        int contador = 0;
        while(getline(file, palavra))                       //Percorre as linhas do arquivo.
        {
            std::istringstream iss(palavra);
            iss >> instrucao;

            if(not iss.eof())
            {
                if(instrucao == "STA")                      //STA -> 2
                {
                    iss >> endereco;
                    mem.writeM(contador, 2); 
                    mem.writeM(contador + 1, endereco);     
                }
                else if(instrucao == "LDA")                 //LDA -> 3
                {
                    iss >> endereco;
                    mem.writeM(contador, 3); 
                    mem.writeM(contador + 1, endereco);     
                }
                else if(instrucao == "ADD")                 //ADD -> 4
                {
                    iss >> endereco;
                    mem.writeM(contador, 4); 
                    mem.writeM(contador + 1, endereco);   
                }
                else if(instrucao == "OR")                  //OR -> 5
                {
                    iss >> endereco;
                    mem.writeM(contador, 5); 
                    mem.writeM(contador + 1, endereco);   
                }
                else if(instrucao == "AND")                 //AND -> 6
                {
                    iss >> endereco;
                    mem.writeM(contador, 6); 
                    mem.writeM(contador + 1, endereco);   
                }
                else if(instrucao == "JMP")                 //JMP -> 8
                {
                    iss >> endereco;
                    mem.writeM(contador, 8); 
                    mem.writeM(contador + 1, endereco);   
                }
                else if(instrucao == "JN")                  //JN -> 9
                {
                    iss >> endereco;
                    mem.writeM(contador, 9); 
                    mem.writeM(contador + 1, endereco);   
                }
                else if(instrucao == "JZ")                  //JZ -> 10
                {
                    iss >> endereco;
                    mem.writeM(contador, 10); 
                    mem.writeM(contador + 1, endereco);   
                }
            }
            else
            {
                if(instrucao == "NOP")                      //NOP -> 1
                {
                    mem.writeM(contador, 1);
                }
                else if(instrucao == "NOT")
                {
                    mem.writeM(contador, 7);                //NOP -> 7
                } 
                else if(instrucao == "HLT")
                {
                    mem.writeM(contador, 11);               //HLT -> 11
                }
            }

            contador += 2; //Acrescenta de dois, pois a primeira posicao é comando e a segunda endereco.
        }
    }
}

void visualizarEstados(Regs & regs, Mem & mem, AP & ap, PC & pc, ULA & ula)
{
    std::cout << "Registrador:              " << regs.readR() << std::endl;
    //std::cout << "Registrador de instrução: " << regs. << std::endl;
    std::cout << "Contador de programa      " << ap.getPosition() << std::endl;
    std::cout << "Zero:                     " << ula.isZero() << std::endl;
    std::cout << "Negativo:                 " << ula.isNegative() << std::endl;
    std::cout << "Operação da ula:          " << ula.getOperation() << std::endl;
    std::cout << "Memória:                  " << std::endl;
    mem.showMemory();
    std::cout << std::endl;
}


int main()
{
    Regs regs;
    RegsI regsi;
    Mem mem;
    AP ap;
    ULA ula;
    std::ifstream ifs("programa.txt");
    inserirInstrucoes(ifs, mem);
    PC pc(ula, regs, regsi, mem, ap);


    for(int _clock=1; _clock <= 300; _clock++) {
        
        pc.FTE();
    
        pc.updateState();

        pc.visualizarEstados();

        if(pc.getLastState() == true)
        {
            break;
        }
    }


    std::cout << "\nResultado: " << regs.readR() << "\n";

    //mem.showMemory();

    return 0;
}