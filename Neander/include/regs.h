#ifndef REGS_H
#define REGS_H

class Regs{

	public:
	
		Regs(){
			regs = new int[1];
			regs[0] = 0;
		}				

		int readR();

		void writeR(int value);

	private:
		int *regs;
};

#endif