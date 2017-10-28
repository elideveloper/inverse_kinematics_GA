#include "Point.h"

#include <cmath>

Point::Point() : x(0), y(0)
{
}

Point::Point(double x, double y) : x(x), y(y)
{
}

double Point::distanceTo(double x, double y) const
{
	return sqrt((x - this->x)*(x - this->x) + (y - this->y)*(y - this->y));
}
