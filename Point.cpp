#include "point.h"

#include <math.h>

Point::Point() : x(0.0), y(0.0), z(0.0)
{
}

Point::Point(double x, double y, double z) : x(x), y(y), z(z)
{
}

Point::Point(const Point & point)
{
	this->x = point.x;
	this->y = point.y;
	this->z = point.z;
}

Point & Point::operator=(const Point & point)
{
	if (&point == this) return *this;
	this->x = point.x;
	this->y = point.y;
	this->z = point.z;
	return *this;
}

double Point::distanceTo(double x, double y, double z) const
{
	return sqrt((x - this->x)*(x - this->x) + (y - this->y)*(y - this->y) + (z - this->z)*(z - this->z));
}

double Point::distanceTo(const Point & point) const
{
	return sqrt((point.x - this->x)*(point.x - this->x) + (point.y - this->y)*(point.y - this->y) + (point.z - this->z)*(point.z - this->z));
}
