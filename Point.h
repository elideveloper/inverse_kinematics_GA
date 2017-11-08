#ifndef POINT_H
#define POINT_H

class Point {
public:
	Point();
	Point(int x, int y, int z);
	Point(const Point & point);
	Point & operator= (const Point & point);
	int x;
	int y;
	int z;
	int distanceTo(int x, int y, int z) const;
	int distanceTo(const Point & point) const;
};

#endif