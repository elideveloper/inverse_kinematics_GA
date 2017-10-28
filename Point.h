#pragma once

class Point {
	double x;
	double y;
public:
	Point();
	Point(double x, double y);
	double distanceTo(double x, double y) const;
};
