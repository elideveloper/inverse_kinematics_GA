#include "range.h"
#include "utility.h"
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

double Range::getRandom()
{
	return random(this->_min * 100, this->_max * 100) / 100.0;
}