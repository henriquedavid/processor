#include <iostream>

class Memoria{
private:
	int memoria[80];

public:
	Memoria(){
		for(int i = 0; i < 80; i++){
			memoria[i] = 0;
		}
	}

	int read(int address){
		return memoria[address];
	}

	void write(int address, int valor){
		memoria[address] = valor;
	}
}