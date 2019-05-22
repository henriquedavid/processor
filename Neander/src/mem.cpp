#include "mem.h"

int Mem::readM(int adress)
{
	return mem[adress];
}

void Mem::writeM(int adress, int value)
{
	mem[adress] = value;
}