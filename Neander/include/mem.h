#ifndef MEM_H
#define MEM_H

class Mem{

	public:

		Mem(){
			mem = new std::string[256];	//0-127 | 128 - 255.
		}

		std::string readM(int adress);

		void writeM(int adress, std::string value);

	private:
		std::string *mem;
};

#endif