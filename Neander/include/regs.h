#ifndef REGS_H
#define REGS_H

class Regs{

	public:
	
		Regs(){
			regs = new int[1];
		}				

		int readR(int adress)
		{
			return regs[adress];
		}

		void writeR(int adress, int value)
		{
			regs[adress] = value;
		}

	private:
		int *regs;
};

#endif