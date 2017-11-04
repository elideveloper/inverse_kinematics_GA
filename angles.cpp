#include "angles.h"

/*Angles::Angles()
{
}*/

Angles::Angles(double rotationAngle, double twistingAngle, double revolutionAngle) 
	: rotationAngle(rotationAngle), twistingAngle(twistingAngle), revolutionAngle(revolutionAngle)
{
}

Angles::Angles(const Angles & angles)
{
	this->rotationAngle = angles.rotationAngle;
	this->twistingAngle = angles.twistingAngle;
	this->revolutionAngle = angles.revolutionAngle;
}

Angles & Angles::operator=(const Angles & angles)
{
	if (this == &angles) return *this;
	this->rotationAngle = angles.rotationAngle;
	this->twistingAngle = angles.twistingAngle;
	this->revolutionAngle = angles.revolutionAngle;
	return *this;
}