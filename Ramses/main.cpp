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

void readFile( Memoria & memoria ){

	int mem_codigo = 0;

	std::string line;
  	std::ifstream myfile ("data.txt");
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
    						if(inst == "00")
	    						memoria.write(mem_codigo, "00010000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "00010001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "00010010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "00010011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RB"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "00010100");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "00010101");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "00010110");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "00010111");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RX"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "00011000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "00011001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "00011010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "00011011");
	    					else{
	    						// nothing;
	    					}
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
    						if(inst == "00")
	    						memoria.write(mem_codigo, "00100000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "00100001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "00100010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "00100011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RB"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "00100100");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "00100101");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "00100110");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "00100111");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RX"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "00101000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "00101001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "00101010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "00101011");
	    					else{
	    						// nothing;
	    					}
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
    						if(inst == "00")
	    						memoria.write(mem_codigo, "00110000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "00110001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "00110010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "00110011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RB"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "00110100");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "00110101");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "00110110");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "00110111");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RX"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "00111000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "00111001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "00111010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "00111011");
	    					else{
	    						// nothing;
	    					}
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
    						if(inst == "00")
	    						memoria.write(mem_codigo, "01110000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "01110001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "01110010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "01110011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RB"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "01110100");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "01110101");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "01110110");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "01110111");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RX"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "01111000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "01111001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "01111010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "01111011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				}
    			}
    			
    		} else if(inst == "JMP"){
    			if(not iss.eof()){
    				iss >> inst;
    				if(inst == "RA"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "10000000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "10000001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "10000010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "10000011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RB"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "10000100");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "10000101");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "10000110");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "10000111");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RX"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "10001000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "10001001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "10001010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "10001011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				}
    			}
    			
    		} else if(inst == "JN"){
    			if(not iss.eof()){
    				iss >> inst;
    				if(inst == "RA"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "10010000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "10010001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "10010010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "10010011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RB"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "10010100");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "10010101");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "10010110");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "10010111");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RX"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "10011000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "10011001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "10011010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "10011011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				}
    			}
    			
    		} else if(inst == "JZ"){
    			if(not iss.eof()){
    				iss >> inst;
    				if(inst == "RA"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "10100000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "10100001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "10100010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "10100011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RB"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "10100100");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "10100101");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "10100110");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "10100111");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RX"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "10101000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "10101001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "10101010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "10101011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				}
    			}
    			
    		} else if(inst == "JC"){
    			if(not iss.eof()){
    				iss >> inst;
    				if(inst == "RA"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "10110000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "10110001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "10110010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "10110011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RB"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "10110100");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "10110101");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "10110110");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "10110111");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RX"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "10111000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "10111001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "10111010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "10111011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				}
    			}
    			
    		} else if(inst == "JSR"){
    			if(not iss.eof()){
    				iss >> inst;
    				if(inst == "RA"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "11000000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "11000001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "11000010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "11000011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RB"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "11000100");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "11000101");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "11000110");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "11000111");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RX"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "11001000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "11001001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "11001010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "11001011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				}
    			}
    			
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
    			
    		} else if(inst == "HTL"){

    			if(not iss.eof()){
    				iss >> inst;
    				if(inst == "RA"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "11110000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "11110001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "11110010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "11110011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RB"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "11110100");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "11110101");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "11110110");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "11110111");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				} else if(inst == "RX"){
    					if(not iss.eof()){
    						iss >> inst;
    						if(inst == "00")
	    						memoria.write(mem_codigo, "11111000");
	    					else if(inst == "01")
	    						memoria.write(mem_codigo, "11111001");
	    					else if(inst == "10")
	    						memoria.write(mem_codigo, "11111010");
	    					else if(inst == "11")
	    						memoria.write(mem_codigo, "11111011");
	    					else{
	    						// nothing;
	    					}
	    					mem_codigo++;
    					}
    				}
    			}
    			
    		} else {
    			std::cout << "Foi encontrado um código não válido.\n";
    		}

    	}
    	myfile.close();
		
  	}
	else std::cout << "Unable to open file"; 


}

int main(){

	Registrador reg;
	Memoria mem;
	CP cp;
	ULA ula;
	PC pc(ula, reg, mem, cp);

	readFile(mem);
	mem.printAll();

	for(int clock = 0; clock < 100; clock++){
		pc.FS();
		pc.FTE();

		pc.updateState();

		if(pc.getLastState() == true)
			break;
	}


	return 0;
}