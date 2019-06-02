#ifndef ULA_H
#define ULA_H

#include <string>

class ULA {

private:
	int a, b, s, carry;
	bool cond;

public:

	ULA(){
		cond = false;
	}

	void read_A( int a_ ){
		a = a_;
		std::cout << "REG A => " << a_ << std::endl;
	}

	//Representa o registrador
	void read_B( int b_ ){
		b = b_;
		std::cout << "REG B => " << b_ << std::endl;
	}

	void read_Carry( int c ){
		carry = c;
	}

	int write_s(){
		std::cout << "\nRESULT ULA S => " << s << std::endl;
		return s;
	}

	bool getCond(){
		return cond;
	}

	void op( int op )
	{
		switch (op){
			case 00:
					break;
			case 1:
					s = b;
					break;
			case 10:
					s = a;
					break;
			case 11: s = a + b; std::cout << a << " + " << b << " = " << s; 
					break;
			case 100: s = a or b;
					break;
			case 101: s = a and b;
					break;
			case 110: s = not b;
					break;
			case 111: s = b - a;
			std::cout << b << " - " << a << " = " << s; 
					break;
			case 1000: s = a;
					break;
			case 1001: if( b < 1 ) s = a;
					break;
			case 1010: if( b == 0 ) s = a;
					break;
			case 1011: if( carry == 1-a ) s = a;
					break;
			case 1100: s = a; a++;
					break;
			case 1101: a < 0 ? s = a : s = not a;
					break;
			case 1110: s = a/2;
					break;
			case 1111: break;
			default:
					break;
		}
	}

};

#endif