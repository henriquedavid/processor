#ifndef FOR_INST
#define FOR_INST

class Instrucoes{
private:
	std::string codigo;
	std::string registrador;
	std::string modo;

public:
	Instrucoes(){
		codigo = "";
		registrador = "";
		modo = "";
	}

	std::string getCodigo(){
		return codigo;
	}

	void setCodigo(std::string codigo_){
		codigo = codigo_;
	}

	std::string getRegistrador(){
		return registrador;
	}

	void setRegistrador(std::string registrador_){
		registrador = registrador_;
	}

	std::string getModo(){
		return modo;
	}

	void setCodigo(std::string modo_){
		modo = modo_;
	}

	
}

#endif