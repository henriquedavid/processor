#ifndef
#define PC_H

class PC{
private:
	int EA, PE;
	bool lastState;
	ULA ula;
	Registrador reg;
	Memoria mem;
	CP cp;

public:
	PC(ULA ula_, Registrador rg_, Memoria mem_, CP cp_){
		ula = ula_;
		reg = rg_;
		mem = mem_;
		cp = cp_;
	}

	void FTE(){
		switch(EA){
			case 0:
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
}

#endif