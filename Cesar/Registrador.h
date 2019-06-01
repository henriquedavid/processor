#ifndef REG_H
#define REG_H

class Registrador{
	private:
		std::string registrador[3];

	public:
		Registrador() {
			// Inicializa o array.
			for(int i = 0 ; i < 3; i++){
				registrador[i] = "0";
			}
		}

		std::string read( int address ){
			return registrador[address];
		}

		void write(int address, std::string valor){
			registrador[address] = valor;
		}

		void printRegistradores(){
			std::cout << registrador[0] << " - " << registrador[1] << " - " << registrador[2] << std::endl;
		}

};

#endif