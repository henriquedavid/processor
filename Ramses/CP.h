#ifndef AP_H
#define AP_H

class CP{
private:
	int i;

public:
	CP(){
		i = 0;
	}

	void zerar(){
		i = 0;
	}

	void setPosition(int valor){
		i = valor;
	}

	void increase(){
		i += 1;
	}

	int getPosition(){
		return i;
	}
};

#endif