#include "regsinst.h"

int RegsI::readRI()
{
	return regsi[0];
}

void RegsI::writeRI(int value)
{
	regsi[0] = value;
}