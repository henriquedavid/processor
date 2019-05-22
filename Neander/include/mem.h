#ifndef MEM_H
#define MEM_H

class Mem{

	public:

		Mem(){
			mem = new int[256];	//0-127 | 128 - 255.
		}

		int readM(int adress);

		void writeM(int adress, int value);

	private:
		int *mem;
};

#endif