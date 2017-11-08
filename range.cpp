#include "range.h"
#include "utility.h"
Range::Range()
{
}

Range::Range(int max, int min) : _min(min), _max(max)
{
}

Range::Range(const Range & range)
{
	this->_max = range._max;
	this->_min = range._min;
}

int Range::getRandom()
{
	return random(this->_min, this->_max);
}