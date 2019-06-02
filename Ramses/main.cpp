#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Registrador.h"
#include "Memoria.h"
#include "ULA.h"
#include "CP.h"
#include "PC.h"

void readFile( Memoria & memoria, CP & cp_ ){

	int mem_codigo = 0;

	std::string line;
  	std::ifstream myfile ("adicao_variaveis_8bits.txt");
  	std::string inst;
  	std::string reg;

	if (myfile.is_open())
	{
    	while ( getline (myfile, line) )
    	{

    		if(line == ""){
    			continue;
    		}

    		std::istringstream iss(line);
    		iss >> inst;

    		if(inst == "NOP"){
    			memoria.write(mem_codigo, 0000);
    			mem_codigo++;
    		} else if(inst == "STR"){
    			if(not iss.eof()){
    				iss >> inst;
    				if(inst == "RA"){
    					if(not iss.eof()){
    						iss >> inst;
	    					memoria.write(mem_codigo, "000100 "+ inst);
	    					mem_codigo++;
    					}
    				} else if(inst == "RB"){
    					if(not iss.eof()){
    						iss >> inst;
	    					memoria.write(mem_codigo, "000101 "+ inst);
	    					mem_codigo++;
    					}
    				} else if(inst == "RX"){
    					if(not iss.eof()){
    						iss >> inst;
							memoria.write(mem_codigo, "000110 " + inst);
	    					mem_codigo++;
    					}
    				}
    			}
    		} else if(inst == "LDR"){
    			if(not iss.eof()){
    				iss >> inst;
    				if(inst == "RA"){
    					if(not iss.eof()){
    						iss >> inst;
	    					memoria.write(mem_codigo, "001000 "+ inst);
	    					mem_codigo++;
    					}
    				} else if(inst == "RB"){
    					if(not iss.eof()){
    						iss >> inst;
	    					memoria.write(mem_codigo, "001001 " + inst);
	    					mem_codigo++;
    					}
    				} else if(inst == "RX"){
    					if(not iss.eof()){
    						iss >> inst;
	    					memoria.write(mem_codigo, "001010 " + inst);
	    					mem_codigo++;
    					}
    				}
    			}
    			
    		} else if(inst == "ADD"){
    			if(not iss.eof()){
    				iss >> inst;
    				if(inst == "RA"){
    					if(not iss.eof()){
    						iss >> inst;
	    					memoria.write(mem_codigo, "001100 "+inst);
	    					mem_codigo++;
    					}
    				} else if(inst == "RB"){
    					if(not iss.eof()){
    						iss >> inst;
	    					memoria.write(mem_codigo, "001101 " + inst);
	    					mem_codigo++;
    					}
    				} else if(inst == "RX"){
    					if(not iss.eof()){
    						iss >> inst;
	    					memoria.write(mem_codigo, "001110 "+inst);
	    					mem_codigo++;
    					}
    				}
    			}
    			
    		} else if(inst == "OR"){
    			if(not iss.eof()){
    				iss >> inst;
    				if(inst == "RA"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "01000000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "01000001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "01000010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "01000011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RB"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "01000100");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "01000101");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "01000110");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "01000111");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RX"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "01001000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "01001001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "01001010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "01001011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				}
    			}
    			
    		} else if(inst == "AND"){
    			if(not iss.eof()){
    				iss >> inst;
    				if(inst == "RA"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "01010000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "01010001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "01010010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "01010011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RB"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "01010100");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "01010101");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "01010110");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "01010111");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RX"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "01011000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "01011001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "01011010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "01011011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				}
    			}
    			
    		} else if(inst == "NOT"){
    			if(not iss.eof()){
    				iss >> inst;
    				if(inst == "RA"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "01100000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "01100001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "01100010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "01100011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RB"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "01100100");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "01100101");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "01100110");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "01100111");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RX"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "01101000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "01101001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "01101010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "01101011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				}
    			}
    			
    		} else if(inst == "SUB"){
    			if(not iss.eof()){
    				iss >> inst;
    				if(inst == "RA"){
    					if(not iss.eof()){
    						iss >> inst;
	    					memoria.write(mem_codigo, "011100 "+inst);
	    					mem_codigo++;
    					}
    				} else if(inst == "RB"){
    					if(not iss.eof()){
    						iss >> inst;
	    					memoria.write(mem_codigo, "011101 "+inst);
	    					mem_codigo++;
    					}
    				} else if(inst == "RX"){
    					if(not iss.eof()){
    						iss >> inst;
	    					memoria.write(mem_codigo, "011110 "+inst);
	    					mem_codigo++;
    					}
    				}
    			}
    			
    		} else if(inst == "JMP"){
    			if(not iss.eof()){
    				iss >> inst;
    				memoria.write(mem_codigo, "1000 "+inst);
    			}
    			else{
    				// nothing
    			}
    			mem_codigo++;
    			
    		} else if(inst == "JN"){
    			if(not iss.eof()){
    				iss >> inst;
    				memoria.write(mem_codigo, "1001 "+inst);
    			}
    			else{
    				// nothing
    			}
    			mem_codigo++;
    			
    		} else if(inst == "JZ"){
    			if(not iss.eof()){
    				iss >> inst;
    				memoria.write(mem_codigo, "1010"+inst);
    			}
    			else{
    				// nothing
    			}
    			mem_codigo++;

    		} else if(inst == "JC"){
    			if(not iss.eof()){
    				iss >> inst;
    				memoria.write(mem_codigo, "1011"+inst);
    			}
    			else{
    				// nothing
    			}
    			mem_codigo++;

    			
    		} else if(inst == "JSR"){
    			if(not iss.eof()){
    				iss >> inst;
    				memoria.write(mem_codigo, "1100"+inst);
    			}
    			else{
    				// nothing
    			}
    			mem_codigo++;
    			
    		} else if(inst == "NEG"){
    			if(not iss.eof()){
    				iss >> inst;
    				if(inst == "RA"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "11010000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "11010001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "11010010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "11010011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RB"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "11010100");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "11010101");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "11010110");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "11010111");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RX"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "11011000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "11011001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "11011010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "11011011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				}
    			}
    			
    		} else if(inst == "SHR"){
    			if(not iss.eof()){
    				iss >> inst;
    				if(inst == "RA"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "11100000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "11100001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "11100010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "11100011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RB"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "11100100");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "11100101");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "11100110");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "11100111");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RX"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "11101000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "11101001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "11101010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "11101011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				}
    			}
    			
    		} else if(inst == "HLT"){

    			memoria.write(mem_codigo, "11110000");
    			mem_codigo++;
    			
    		} else {
    			std::cout << "Foi encontrado um código não válido.\n";
    		}

    	}
    	myfile.close();
		
  	}
	else std::cout << "Unable to open file"; 


	int a = 0;
	for(int i = 0; i < 256; i++){
		if(memoria.read(i) != "0")
			a++;
	}
	cp_.setEnd(a);

}

int main(){

	Registrador reg;
	Memoria mem;
	CP cp;
	ULA ula;
	

	readFile(mem, cp);
	mem.printAll();
	cp.zerar();
	PC pc(ula, reg, mem, cp);

	for(int clock = 0; clock < 1000000; clock++){

		pc.FTE();

		pc.updateState();

		if(pc.getLastState() == true)
			break;
	}

	return 0;
}