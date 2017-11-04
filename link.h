#ifndef LINK_H
#define LINK_H

#include "joint.h"

class Link {
public:
	Link();
	Link(int length, Joint* joint, Angles angles = Angles());
	Link(const Link & link);
	Link & operator=(const Link & link);
	Point computeB();
	Point computeB(const Link & prevLink);
	int getLength() const;
	double getTurn() const;
	void setA(Point a);
	void setAngles(Angles angles);
	Angles getAngles() const;
	void randomizeAngle();
	void swapJoints(Link & link);
	bool isIntersectsHorizPlane(double z);
private:
	Point _a;
	Point _b;
	int _length;
	Joint* _joint;
	Angles _currAngles;
};

#endif