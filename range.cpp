#include "range.h"
#include <random>// DELETE
Range::Range()
{
}

Range::Range(double max, double min) : _min(min), _max(max)
{
}

Range::Range(const Range & range)
{
	this->_max = range._max;
	this->_min = range._min;
}

int random(int min, int max) {
	return rand() % (max + abs(min)) + min;
}

double Range::getRandom()
{
	return random(this->_min * 1000, this->_max * 1000) / 1000.0;
}