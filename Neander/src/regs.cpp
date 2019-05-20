#include "regs.h"

std::string Regs::readR()
{
	return regs[0];
}

void Regs::writeR(int value)
{
	regs[0] = value;
}