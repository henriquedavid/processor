#include "regs.h"

int Regs::readR()
{
	return regs[0];
}

void Regs::writeR(int value)
{
	regs[0] = value;
}