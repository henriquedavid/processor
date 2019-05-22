#ifndef ULA_H
#define ULA_H

class ULA {

private:
	int a, b, s, carry;
	bool cond;

public:

	ULA(){
		cond = false;
	}

	void read_end_A( int a_ ){
		a = a_;
	}

	//Representa o registrador
	void read_B( int b_ ){
		b = b_;
	}

	void read_Carry( int c ){
		carry = c;
	}

	int write_s(){
		return s;
	}

	bool getCond(){
		return cond;
	}

	void operacao( int op )
	{
		switch (op){
			case 0000:
					break;
			case 0001:
					s = b;
					break;
			case 0010:
					s = a;
					break;
			case 0011: s = a + b;
					break;
			case 0100: s = a or b;
					break;
			case 0101: s = a and b;
					break;
			case 0110: s = not b;
					break;
			case 0111: s = b - a;
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