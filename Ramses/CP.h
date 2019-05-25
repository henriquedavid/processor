#ifndef AP_H
#define AP_H

class CP{
private:
	int i;
	int total;

public:
	CP(){
		i = 0;
		total = 0;	
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

	void goToEnd(){
		i = total;
	}

	void setEnd(int valor){
		i = valor;
	}
};

#endif