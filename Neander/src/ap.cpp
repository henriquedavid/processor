#include "ap.h"

void AP::increase()
{
	end += 2;
}

void AP::setPosition(int _end)
{
	end = _end;
}

int AP::getPosition()
{
	return end;
}

void AP::zerar()
{
	end = 0;
}