#include "mem.h"

std::string Mem::readM(int adress)
{
	return mem[adress];
}

void Mem::writeM(int adress, int value)
{
	mem[adress] = value;
}