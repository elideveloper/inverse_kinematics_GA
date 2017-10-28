#pragma once

class Point {
	double x;
	double y;
	double z;
public:
	Point();
	Point(double x, double y, double z);
	double distanceTo(double x, double y, double z) const;
};
