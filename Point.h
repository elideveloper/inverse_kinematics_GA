#ifndef POINT_H
#define POINT_H

class Point {
public:
	Point();
	Point(double x, double y, double z);
	Point(const Point & point);
	Point & operator= (const Point & point);
	double x;
	double y;
	double z;
	double distanceTo(double x, double y, double z) const;
	double distanceTo(const Point & point) const;
private:
};

#endif