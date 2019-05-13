#include <iostream>

class Registrador{
	private:
		int registrador[3];

	public:
		Registrador() {
			// Inicializa o array.
			for(int i = 0 ; i < 3; i++){
				registrador[i] = 0;
			}
		}

		int read( int address ){
			return registrador[address];
		}

		void write(int address, int valor){
			registrador[address] = valor;
		}

}