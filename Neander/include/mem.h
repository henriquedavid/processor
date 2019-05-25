#ifndef MEM_H
#define MEM_H

#include <iostream>

class Mem{

	public:

		Mem(){
			mem = new int[256];	//0-127 | 128 - 255.
			
			for(int i = 0; i < 256; i++)
			{
				mem[i] = 0;
			}
		}

		int readM(int adress);

		void writeM(int adress, int valor);

		void showMemory();

	private:
		int *mem;
};

#endif