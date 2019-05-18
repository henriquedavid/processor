#ifndef MEM_H
#define MEM_H

class Mem{

	public:

		Mem(){
			mem = new int[256];	//0-127 | 128 - 255.
		}

		int readM(int adress)
		{
			return mem[adress];
		}

		void writeM(int adress, int value)
		{
			mem[adress] = value;
		}

	private:
		int *mem;
};

#endif