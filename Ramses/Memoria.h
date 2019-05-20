#ifndef MEM_H
#define MEM_H

class Memoria{
private:
	std::string memoria[256];

public:
	Memoria(){
		for(int i = 0; i < 256; i++){
			memoria[i] = "0";
		}
	}

	std::string read(int address){
		return memoria[address];
	}

	void write(int address, std::string valor){
		memoria[address] = valor;
		std::cout << "valor: " << valor << std::endl;
	}
};

#endif