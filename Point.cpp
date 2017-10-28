#include "Point.h"

#include <cmath>

Point::Point() : x(0), y(0), z(0)
{
}

Point::Point(double x, double y, double z) : x(x), y(y), z(z)
{
}

double Point::distanceTo(double x, double y, double z) const
{
	return sqrt((x - this->x)*(x - this->x) + (y - this->y)*(y - this->y) + (z - this->z)*(z - this->z));
}
