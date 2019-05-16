#ifndef ULA_H
#define ULA_H

class Ula{
	
	public:
		
		Ula(){
			cond1 = false; //Condição de parada.	
		}

		void readA(int value)
		{
			a = value;
		}

		void readB(int value)
		{
			b = value;
		}

		int writeResult()
		{
			return s;
		}

		void op(int ulaOP)
		{
			switch(ulaOP)
			{
				case 0:
					std::cout << "NOP\n";
					break;
				case 1:
					s = a;
					std::cout << "STA\n";
					break;
				case 2:
					s = a;
					std::cout << "LDA\n";
					break;
				case 3: 
					s = a + b;
					std::cout << a << " + " << b << " = " << s << std::endl;
					break;
				case 4:
					s = a or b;
					std::cout << a << " | " << b << " = " << s << std::endl;
					break;
				case 5:
					s = a and b;
					std::cout << a << " & " << b << " = " << s << std::endl;
					break;
				case 6:
					s = not a;
					std::cout << " ~ " << a << " = " << s << std::end;
					break;
				default:
					break;
			}
		}

		bool getCond1()
		{
			return cond1;
		}

	private:
		int a, b, s;
		bool cond1;
};

#endif