#ifndef REGS_H
#define REGS_H

class Regs{

	public:
	
		Regs(){
			regs = new std::string[1];
		}				

		std::string readR();

		void writeR(int value);

	private:
		std::string *regs;
};

#endif