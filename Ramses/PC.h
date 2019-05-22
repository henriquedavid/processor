#ifndef PC_H
#define PC_H

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
	PC(ULA ula_, Registrador rg_, Memoria mem_, CP cp_){
		ula = ula_;
		reg = rg_;
		mem = mem_;
		cp = cp_;
		mem_dat = 128;
	}

	void FTE(){
		switch(EA){	// Cada estado representará uma instrução.

			case 0:	// Definir as condições iniciais de valores.
				mem.write(128, "00000001");
				mem.write(129, "00000001");
				break;

			case 1: // Representando 0001
				std::string inst = mem.read(cp.getPosition());
				// Distribuir para os registradores
				if( inst.substr(5,7) == "00" )
					mem.write( mem_dat , reg.read(0) );
				else if( inst.substr(5, 7) == "01" )
					mem.write( mem_dat , reg.read(1) );
				else if( inst.substr(5, 7) == "10" )
					mem.write( mem_dat , reg.read(2) );
				else{}
				
				mem_dat++;
				PE = cp.getPosition() + 1;
				break;
			
			case 2:	// Representando 0010
				std::string inst = mem.read(cp.getPosition());
				if( inst.substr(5,7) == "00" )
					reg.write( 0 , mem.read(mem_dat) );
				else if( inst.substr(5, 7) == "01" )
					mem.write( 1 , mem.read(mem_dat) );
				else if( inst.substr(5, 7) == "10" )
					mem.write( 2 , mem.read(mem_dat) );
				else{}

				PE = cp.getPosition() + 1;
				break;

			case 3: // Representando 0011
				std::string inst = mem.read(cp.getPosition());
				ula.read_A( stringToInt(mem.read(mem_dat)) );

				if( inst.substr(5,7) == "00" )
					ula.read_B( stringToInt( reg.read(0)) );
				else if( inst.substr(5, 7) == "01" )
					ula.read_B( stringToInt( reg.read(1)) );
				else if( inst.substr(5, 7) == "10" )
					ula.read_B( stringToInt( reg.read(2)) );
				else{}

				ula.op(inst.substr(0,4));

				PE = 4;
				break;

			case 4:
				if( inst.substr(5,7) == "00" )
					reg.write( 0, ula.write_s() );
				else if( inst.substr(5, 7) == "01" )
					reg.write( 1, ula.write_s() );
				else if( inst.substr(5, 7) == "10" )
					reg.write( 2, ula.write_s() );
				else{}
				PE = cp.getPosition() + 1;
				break;

			case 5: // Representando 0100
				std::string inst = mem.read(cp.getPosition());
				ula.read_A( stringToInt(mem.read(mem_dat)) );

				if( inst.substr(5,7) == "00" )
					ula.read_B( stringToInt( reg.read(0)) );
				else if( inst.substr(5, 7) == "01" )
					ula.read_B( stringToInt( reg.read(1)) );
				else if( inst.substr(5, 7) == "10" )
					ula.read_B( stringToInt( reg.read(2)) );
				else{}

				ula.op(inst.substr(0,4));
				PE = 6;
				break;

			case 6:
				if( inst.substr(5,7) == "00" )
					reg.write( 0, ula.write_s() );
				else if( inst.substr(5, 7) == "01" )
					reg.write( 1, ula.write_s() );
				else if( inst.substr(5, 7) == "10" )
					reg.write( 2, ula.write_s() );
				else{}
				PE = cp.getPosition() + 1;
				break;

			case 7: // Representando 0101
				std::string inst = mem.read(cp.getPosition());
				ula.read_A( stringToInt(mem.read(mem_dat)) );

				if( inst.substr(5,7) == "00" )
					ula.read_B( stringToInt( reg.read(0)) );
				else if( inst.substr(5, 7) == "01" )
					ula.read_B( stringToInt( reg.read(1)) );
				else if( inst.substr(5, 7) == "10" )
					ula.read_B( stringToInt( reg.read(2)) );
				else{}

				ula.op(inst.substr(0,4));
				PE = 8;
				break;

			case 8:
				if( inst.substr(5,7) == "00" )
					reg.write( 0, ula.write_s() );
				else if( inst.substr(5, 7) == "01" )
					reg.write( 1, ula.write_s() );
				else if( inst.substr(5, 7) == "10" )
					reg.write( 2, ula.write_s() );
				else{}
				PE = cp.getPosition() + 1;
				break;
			
			case 9: // Representando 0110
				if( inst.substr(5,7) == "00" )
					ula.read_A( stringToInt( reg.read(0)) );
				else if( inst.substr(5, 7) == "01" )
					ula.read_A( stringToInt( reg.read(1)) );
				else if( inst.substr(5, 7) == "10" )
					ula.read_A( stringToInt( reg.read(2)) );
				else{}

				ula.op(inst.substr(0,4));
				PE = 10
				break;

			case 10:
				if( inst.substr(5,7) == "00" )
					reg.write( 0, ula.write_s() );
				else if( inst.substr(5, 7) == "01" )
					reg.write( 1, ula.write_s() );
				else if( inst.substr(5, 7) == "10" )
					reg.write( 2, ula.write_s() );
				else{}
				PE = cp.getPosition() + 1;
				break;

			case 11: // Representando 0111
				std::string inst = mem.read(cp.getPosition());
				ula.read_B( stringToInt(mem.read(mem_dat)) );

				if( inst.substr(5,7) == "00" )
					ula.read_A( stringToInt( reg.read(0)) );
				else if( inst.substr(5, 7) == "01" )
					ula.read_A( stringToInt( reg.read(1)) );
				else if( inst.substr(5, 7) == "10" )
					ula.read_A( stringToInt( reg.read(2)) );
				else{}

				ula.op(inst.substr(0,4));

				PE = 4;
				break;

			case 12:
				if( inst.substr(5,7) == "00" )
					reg.write( 0, ula.write_s() );
				else if( inst.substr(5, 7) == "01" )
					reg.write( 1, ula.write_s() );
				else if( inst.substr(5, 7) == "10" )
					reg.write( 2, ula.write_s() );
				else{}
				PE = cp.getPosition() + 1;
				break;

			case 13: // Representando 1000
				cp.setPosition(mem_dat);
				break;

			case 14: // Representando 1001
				
				break;

			case 15:
				break;
			default: break;
		}
	}

	void FS(){
		switch(EA){
			case 0:
				break;
			default: break;
		}
	}

	void updateState(){
		EA = PE;
	}

	bool getLastState(){
		return lastState;
	}

	int stringToInt(std::string valor_){
		int valor;
		std::istringstream iss(valor_);
		iss >> valor;
		if(iss.good())
			return valor;
	}

	std::string intToString(int valor_){
		std::string valor;
		std::istringstream iss(valor_);
		iss >> valor;
		if(iss.good())
			return valor;
	}
};

#endif