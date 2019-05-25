#include "mem.h"
#include <iostream>

int Mem::readM(int adress)
{
	return mem[adress];
}

void Mem::writeM(int adress, int value)
{
	mem[adress] = value;
}

void Mem::showMemory()
{
	for(int i = 0; i < 256; i++)
	{
		std::cout << mem[i] << " ";
	}

	std::cout << "\n";
}