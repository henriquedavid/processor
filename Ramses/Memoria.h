#ifndef MEM_H
#define MEM_H

class Memoria{
private:
	std::string memoria[256]; // 0-127 | 128-255

public:
	Memoria(){
		for(int i = 0; i < 256; i++){
			memoria[i] = "0";
			if(i == 128 || i == 129){
				memoria[i] = "2";
			}
		}
	}

	std::string read(int address){
		return memoria[address];
	}

	void write(int address, std::string valor){
		memoria[address] = valor;
	}

	void printAll(){
		for(int i = 0; i < 256 ; i++){
			std::cout << i << ". " << memoria[i] << std::endl;
		}
	}
};

#endif