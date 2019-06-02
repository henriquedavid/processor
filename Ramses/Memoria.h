#ifndef MEM_H
#define MEM_H

class Memoria{
private:
	std::string memoria[256]; // 0-127 | 128-255

public:
	Memoria(){
		for(int i = 0; i < 256; i++){
			memoria[i] = "-1";
			if(i == 128){
				memoria[i] = "5";
			}
			if(i == 129){
				memoria[i] = "5";
			}
			if(i == 130){
				memoria[i] = "9";
			}
			if(i == 131){
				memoria[i] = "3";
			}
			if(i == 132){
				memoria[i] = "4";
			}
			if(i == 133){
				memoria[i] = "2";
			}
			if(i == 134){
				memoria[i] = "0";
			}
			if(i == 135){
				memoria[i] = "1";	// incrementador
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
			std::cout << i << ". " << memoria[i] << "\n";
		}
	}
};

#endif