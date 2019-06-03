#ifndef PC_H
#define PC_H

#include <string.h>
#include <algorithm>
#include <math.h>

class PC{
private:
	int EA, PE;
	bool lastState;
	ULA ula;
	Registrador reg;
	Memoria mem;
	CP cp;
	int mem_dat;

public:
	PC(ULA & ula_, Registrador & rg_, Memoria &  mem_, CP & cp_){
		ula = ula_;
		reg = rg_;
		mem = mem_;
		cp = cp_;
		EA = 0;
		PE = 1;
		mem_dat = 128;
	}

	int stringToInt(std::string valor_){
		int valor;
		std::istringstream iss(valor_);
		iss >> valor;
		return valor;
	}

	std::string intToString(int valor_){
		std::string valor = std::to_string(valor_);
		return valor;
	}

	int stringBittoInt(std::string valor){
		int valor_ = 0;

		for(unsigned i = 0u ; i < valor.size(); i++){
			if(valor[i] == '1'){
				valor_ += std::pow(2, i);
			}
		}

		return valor_;

	}

	std::string inttoBitString(int valor){

		std::string r = "";
		int num = valor;

		if(valor == 0)
			return "00000000";

		std::vector<std::string> bin;

		while(num != 1){
			int resto = num % 2;
			if(resto == 0){
				bin.push_back("0");
			} else{
				bin.push_back("1");
			}
			num = num / 2;
		}

		bin.push_back("1");

		for(int a = bin.size(); a < 8; a++){
			bin.push_back("0");
		}

		std::reverse(bin.begin(), bin.end());

		for(std::vector<std::string>::iterator it = bin.begin(); it!= bin.end(); ++it)
			r += *it;

		return r;

	}

	void CASO00(){
		cp.increase();
		cp.setPosition(1);
		PE = 1;
	}

	void CASO01(){	//STR
		std::string inst;
		inst = mem.read( cp.getPosition() );

		std::cout << "INST = " << inst << std::endl;

		if(inst != "-1"){
			bool pegar = false;
			std::string valor = "";

			for( unsigned i = 0u; i < inst.size() ; i++ ){
				if(inst[i] == ' ' || inst[i] == '+'){
					pegar = !pegar;
					}
				if(pegar == true){
					valor += inst[i];
				}
			}

			if( (inst.substr(4,5)).substr(0,2) == "00" )
				mem.write( stringToInt(valor) , reg.read(0) );
			else if( (inst.substr(4,5)).substr(0,2) == "01" )
				mem.write( stringToInt(valor) , reg.read(1) );
			else if( (inst.substr(4,5)).substr(0,2) == "10" )
				mem.write( stringToInt(valor) , reg.read(2) );
			else{}
		
			reg.printRegistradores();
			cp.increase();
		} else{
			cp.setPosition(22);
			PE = 22;
		}
	}

	void CASO02(){		// LDR
		std::cout << "LEITURA\n";

		std::string inst = mem.read(cp.getPosition());


		bool pegar = false;
		std::string valor = "";

		if(inst != "-1"){

		for( unsigned i = 0u; i < inst.size() ; i++ ){
			if(inst[i] == ' ' || inst[i] == '+'){
				pegar = !pegar;
			}
			if(pegar == true){
				valor += inst[i];
			}
			
		}

		if( (inst.substr(4,5)).substr(0,2) == "00" )
			reg.write( 0 , mem.read(stringToInt(valor)) );
		else if( (inst.substr(4,5)).substr(0,2) == "01" )
			reg.write( 1 , mem.read(stringToInt(valor)) );
		else if( (inst.substr(4,5)).substr(0,2) == "10" )
			reg.write( 2 , mem.read(stringToInt(valor)) );
		else{
			std::cout << "ERROR!\n\n";
		}

		reg.printRegistradores();
		cp.increase();
	} else{
		cp.setPosition(22);
		PE = 22;
	}
	}

	void CASO03(){

		std::cout << "SOMA\n";
		std::cout << cp.getPosition() << std::endl;

		std::string inst = mem.read(cp.getPosition());

		bool pegar = false;
		std::string valor = "";

		for( unsigned i = 0u; i < inst.size() ; i++ ){
			if(inst[i] == ' ' || inst[i] == '+'){
				pegar = !pegar;
			}
			if(pegar == true){
				valor += inst[i];
			}
			
		}

		std::cout << "USAR = " << valor << std::endl;


		ula.read_A( stringToInt(mem.read(stringToInt(valor))) );

		if( (inst.substr(4,5)).substr(0,2) == "00" )
			ula.read_B( stringToInt( reg.read(0)) );
		else if( (inst.substr(4,5)).substr(0,2) == "01" ){
			ula.read_B( stringToInt( reg.read(1)) );
		}
		else if( (inst.substr(4,5)).substr(0,2) == "10" )
			ula.read_B( stringToInt( reg.read(2)) );
		else{
			std::cout << "ERROR\n";
		}

		reg.printRegistradores();

		ula.op(11);

		if( (inst.substr(4,5)).substr(0,2) == "00" ){
			reg.write( 0, intToString(ula.write_s()) );
		}
		else if( (inst.substr(4,5)).substr(0,2) == "01" )
			reg.write( 1, intToString(ula.write_s()) );
		else if( (inst.substr(4,5)).substr(0,2) == "10" ){
			reg.write( 2, intToString(ula.write_s()) );
		}else{}

		PE = 0;
		reg.printRegistradores();
		cp.increase();
		PE = cp.getPosition();
	}

	void CASO04(){
	}

			void CASO05(){
				std::string inst = mem.read(cp.getPosition());
				ula.read_A( stringToInt(mem.read(mem_dat)) );

				if( (inst.substr(4,5)).substr(0,2) == "00" )
					ula.read_B( stringToInt( reg.read(0)) );
				else if( (inst.substr(4,5)).substr(0,2) == "01" )
					ula.read_B( stringToInt( reg.read(1)) );
				else if( (inst.substr(4,5)).substr(0,2) == "10" )
					ula.read_B( stringToInt( reg.read(2)) );
				else{}

				ula.op(stringToInt(inst.substr(0,4)));
				PE = 6;
			}

			void CASO06(){
				std::string inst = mem.read(cp.getPosition());
				if( (inst.substr(4,5)).substr(0,2) == "00" )
					reg.write( 0, intToString(ula.write_s()) );
				else if( (inst.substr(4,5)).substr(0,2) == "01" )
					reg.write( 1, intToString(ula.write_s()) );
				else if( (inst.substr(4,5)).substr(0,2) == "10" )
					reg.write( 2, intToString(ula.write_s()) );
				else{}
				PE = cp.getPosition() + 1;
		}

		void CASO07(){

				std::string inst = mem.read(cp.getPosition());
				ula.read_A( stringToInt(mem.read(mem_dat)) );

				if( (inst.substr(4,5)).substr(0,2) == "00" )
					ula.read_B( stringToInt( reg.read(0)) );
				else if( (inst.substr(4,5)).substr(0,2) == "01" )
					ula.read_B( stringToInt( reg.read(1)) );
				else if( (inst.substr(4,5)).substr(0,2) == "10" )
					ula.read_B( stringToInt( reg.read(2)) );
				else{}

				ula.op(stringToInt(inst.substr(0,4)));
				PE = 8;
			}

			void CASO08(){
				std::string inst = mem.read(cp.getPosition());

				if( (inst.substr(4,5)).substr(0,2) == "00" )
					reg.write( 0, intToString(ula.write_s()) );
				else if( (inst.substr(4,5)).substr(0,2) == "01" )
					reg.write( 1, intToString(ula.write_s()) );
				else if( (inst.substr(4,5)).substr(0,2) == "10" )
					reg.write( 2, intToString(ula.write_s()) );
				else{}
				PE = cp.getPosition() + 1;
			}

			void CASO09(){			

				std::string inst = mem.read(cp.getPosition());
				if( (inst.substr(4,5)).substr(0,2) == "00" )
					ula.read_A( stringToInt( reg.read(0)) );
				else if( (inst.substr(4,5)).substr(0,2) == "01" )
					ula.read_A( stringToInt( reg.read(1)) );
				else if( (inst.substr(4,5)).substr(0,2) == "10" )
					ula.read_A( stringToInt( reg.read(2)) );
				else{}

				ula.op(stringToInt(inst.substr(0,4)));
				PE = 10;
			}

			void CASO10(){
				std::string inst = mem.read(cp.getPosition());

				if( (inst.substr(4,5)).substr(0,2) == "00" )
					reg.write( 0, intToString(ula.write_s()) );
				else if( (inst.substr(4,5)).substr(0,2) == "01" )
					reg.write( 1, intToString(ula.write_s()) );
				else if( (inst.substr(4,5)).substr(0,2) == "10" )
					reg.write( 2, intToString(ula.write_s()) );
				else{}
				PE = cp.getPosition() + 1;
			}

			void CASO11(){
				std::cout << "SUB!\n";
				std::string inst = mem.read(cp.getPosition());


				
				bool pegar = false;
				std::string valor = "";

				for( unsigned i = 0u; i < inst.size() ; i++ ){
					if(inst[i] == ' ' || inst[i] == '+'){
						pegar = !pegar;
					}
					if(pegar == true){
						valor += inst[i];
					}
			
				}


				ula.read_B( stringToInt(mem.read(stringToInt(valor) + stringToInt(reg.read(2)))) );

				if( (inst.substr(4,5)).substr(0,2) == "00" )
					ula.read_A( stringToInt( reg.read(0)) );
				else if( (inst.substr(4,5)).substr(0,2) == "01" ){
					ula.read_A( stringToInt( reg.read(1)) );
				}
				else if( (inst.substr(4,5)).substr(0,2) == "10" )
					ula.read_A( stringToInt( reg.read(2)) );
				else{
					std::cout << "ERROR\n";
				}

				reg.printRegistradores();

				ula.op(stringToInt(inst.substr(0,4)));


				if( (inst.substr(4,5)).substr(0,2) == "00" ){
					reg.write( 0, intToString(ula.write_s()) );
				}
				else if( (inst.substr(4,5)).substr(0,2) == "01" )
					reg.write( 1, intToString(ula.write_s()) );
				else if( (inst.substr(4,5)).substr(0,2) == "10" ){
					reg.write( 2, intToString(ula.write_s()) );
				}
				else{}

				cp.increase();
				reg.printRegistradores();
			}

			void CASO12(){}

			void CASO13(){
				std::string inst = mem.read(cp.getPosition());
				if(inst != "-1"){
				bool pegar = false;
				std::string valor = "";

				for( unsigned i = 0u; i < inst.size() ; i++ ){
					if(inst[i] == ' ' || inst[i] == '+'){
						pegar = !pegar;
					}
					if(pegar == true){
						valor += inst[i];
					}
			
				}

				std::cout << "JMP " << valor << std::endl;
				cp.increase();
				cp.setPosition(stringToInt(valor) - 1);
				PE = stringToInt(valor) - 1;

				std::cout << mem.read(cp.getPosition()).substr(0, 4) << std::endl;
			} else{
				PE = 22;
			}

			}

			void CASO14(){
				std::string inst = mem.read(cp.getPosition());
				std::cout << "JN = " << inst << std::endl;
				
				bool pegar = false;
				std::string valor = "";

				for( unsigned i = 0u; i < inst.size() ; i++ ){
					if(inst[i] == ' ' || inst[i] == '+'){
						pegar = !pegar;
					}
					if(pegar == true){
						valor += inst[i];
					}
			
				}

				if(stringToInt(reg.read(0)) > 0){
					cp.setPosition(stringToInt(valor) - 1);
					PE = stringToInt(valor) -1;
				} else{
					cp.setPosition(22);
					PE = 22;
				}

				
			}

			void CASO15(){
				std::cout << "A FAZER!\n";
			}

			void CASO16(){
				std::cout << "A FAZER!\n";
			}

			void CASO17(){
				std::cout << "Chamada de Subrotina!" << std::endl;
				std::string inst = mem.read(cp.getPosition());
				mem.write(130, intToString(cp.getPosition()));
				cp.increase();
				PE = 3;

			}

			void CASO18(){
				std::string inst = mem.read(cp.getPosition());

				if( (inst.substr(4,5)).substr(0,2) == "00" )
					ula.read_A( stringToInt(reg.read(0)) );
				else if( (inst.substr(4,5)).substr(0,2) == "01" )
					ula.read_A( stringToInt(reg.read(0)) );
				else if( (inst.substr(4,5)).substr(0,2) == "10" )
					ula.read_A( stringToInt(reg.read(0)) );
				else{}
					PE = 19;
			}

			void CASO19(){
				std::string inst = mem.read(cp.getPosition());

				ula.op(stringToInt("1101"));
				if( (inst.substr(4,5)).substr(0,2) == "00" )
					reg.write( 0, intToString(ula.write_s()) );
				else if( (inst.substr(4,5)).substr(0,2) == "01" )
					reg.write( 1, intToString(ula.write_s()) );
				else if( (inst.substr(4,5)).substr(0,2) == "10" )
					reg.write( 2, intToString(ula.write_s()) );
				else{}
				PE = cp.getPosition() + 1;
			}

			void CASO20(){
				std::string inst = mem.read(cp.getPosition());

				if( (inst.substr(4,5)).substr(0,2) == "00" )
					ula.read_A( stringToInt(reg.read(0)) );
				else if( (inst.substr(4,5)).substr(0,2) == "01" )
					ula.read_A( stringToInt(reg.read(0)) );
				else if( (inst.substr(4,5)).substr(0,2) == "10" )
					ula.read_A( stringToInt(reg.read(0)) );
				else{}
				PE = 21;
			}

			void CASO21(){
				std::string inst = mem.read(cp.getPosition());

				ula.op(stringToInt("1110"));
				if( (inst.substr(4,5)).substr(0,2) == "00" )
					reg.write( 0, intToString(ula.write_s()) );
				else if( (inst.substr(4,5)).substr(0,2) == "01" )
					reg.write( 1, intToString(ula.write_s()) );
				else if( (inst.substr(4,5)).substr(0,2) == "10" )
					reg.write( 2, intToString(ula.write_s()) );
				else{}
				PE = cp.getPosition() + 1;
			}
			
			void CASO22(){ // Representando 1111 HTL
				PE = cp.getPosition() + 1;

			}

			


	void FTE(){

		//std::cout << "Posição: "<< cp.getPosition() <<"\nValor na Memória = " << mem.read(cp.getPosition()) << std::endl;
		//reg.printRegistradores();
		if(mem.read(cp.getPosition()).substr(0,4) != "-1"){

		if(PE != 0 ){
			if( mem.read(cp.getPosition()).substr(0, 4) == "0000" )
				EA = 0;
			else if( mem.read(cp.getPosition()).substr(0, 4) == "0001" )
				EA = 1;
			else if( mem.read(cp.getPosition()).substr(0, 4) == "0010" )
				EA = 2;
			else if( mem.read(cp.getPosition()).substr(0, 4) == "0011" )
				EA = 3;
			else if( mem.read(cp.getPosition()).substr(0, 4) == "0100" )
				EA = 5;
			else if( mem.read(cp.getPosition()).substr(0, 4) == "0101" )
				EA = 7;
			else if( mem.read(cp.getPosition()).substr(0, 4) == "0110" )
				EA = 9;
			else if( mem.read(cp.getPosition()).substr(0, 4) == "0111" )
				EA = 11;
			else if( mem.read(cp.getPosition()).substr(0, 4) == "1000" )
				EA = 13;
			else if( mem.read(cp.getPosition()).substr(0, 4) == "1001" )
				EA = 14;
			else if( mem.read(cp.getPosition()).substr(0, 4) == "1010" )
				EA = 15;
			else if( mem.read(cp.getPosition()).substr(0, 4) == "1011" )
				EA = 16;
			else if( mem.read(cp.getPosition()).substr(0, 4) == "1100" )
				EA = 17;
			else if( mem.read(cp.getPosition()).substr(0, 4) == "1101" )
				EA = 18;
			else if( mem.read(cp.getPosition()).substr(0, 4) == "1110" )
				EA = 20;
			else if( mem.read(cp.getPosition()).substr(0, 4) == "1111" )
				EA = 22;
			else{
				// nothing
			}
		}else{
				EA = PE;
		}

		if(EA >= 0 && EA <= 22 ){

		switch(EA){	// Cada estado representará uma instrução.

			case 0:	CASO00(); break;

			case 1: CASO01(); break;
			
			case 2:	CASO02(); break;

			case 3: CASO03(); break;

			case 4: CASO04(); break;

			case 5: CASO05(); break;

			case 6: CASO06(); break;

			case 7: CASO07(); break;

			case 8: CASO08(); break;

			case 9: CASO09(); break;

			case 10: CASO10(); break;

			case 11: CASO11(); break;

			case 12: CASO12(); break;

			case 13: CASO13(); break;

			case 14: CASO14(); break;

			case 15: CASO15(); break;

			case 16: CASO16(); break;

			case 17: CASO17(); break;

			case 18: CASO18(); break;

			case 19: CASO19(); break;

			case 20: CASO20(); break;

			case 21: CASO21(); break;

			case 22: CASO22(); break;

			default:
				break;
		}

}} else{
}
	}


	void updateState(){
		EA = PE;
	}

	bool getLastState(){
		return lastState;
	}

	
};

#endif