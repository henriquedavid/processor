#ifndef REGS_H
#define REGS_H

class Regs{

	public:
	
		Regs(){
			regs = new int[1];
		}				

		int readR()
		{
			return regs[0];
		}

		void writeR(int value)
		{
			regs[0] = value;
		}

	private:
		int *regs;
};

#endif