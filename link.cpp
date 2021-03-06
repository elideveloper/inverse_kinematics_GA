#include "link.h"

#include "utility.h"
#include <math.h>
#include <iostream>

Link::Link() : _joint(nullptr)
{
}

Link::Link(int length, Joint* joint, Angles angles) : _length(length), _currAngles(angles)
{
	this->_joint = joint->clone();
}

Link::Link(const Link & link)
{
	this->_a = link._a;
	this->_b = link._b;
	this->_length = link._length;
	this->_currAngles = link._currAngles;
	this->_joint = link._joint->clone();
}

Link & Link::operator=(const Link & link)
{
	if (&link == this) return *this;
	this->_a = link._a;
	this->_b = link._b;
	this->_length = link._length;
	this->_currAngles = link._currAngles;
	if (this->_joint != nullptr) delete this->_joint;
	this->_joint = link._joint->clone();
	return *this;
}

Point Link::computeB()
{
	this->_joint->changeAngles(this->_currAngles);
	this->_b.x = this->_a.x + cos(degreeToRadian(this->_currAngles.rotationAngle)) * this->_length * sin(degreeToRadian(this->_currAngles.twistingAngle));
	this->_b.y = this->_a.y + cos(degreeToRadian(this->_currAngles.rotationAngle)) * this->_length * cos(degreeToRadian(this->_currAngles.twistingAngle));
	this->_b.z = this->_a.z + sin(degreeToRadian(this->_currAngles.rotationAngle)) * this->_length;
	//printf("\n computeB(): x=%d, y=%d, z=%d", this->_b.x, this->_b.y, this->_b.z);
	return this->_b;
}

Point Link::computeB(const Link & prevLink)
{
	// TODO: take in account revolutions of prev links
	this->_joint->changeAngles(this->_currAngles);
	this->_b.x = this->_a.x + cos(degreeToRadian(this->_currAngles.rotationAngle)) * this->_length * sin(degreeToRadian(this->_currAngles.twistingAngle));
	this->_b.y = this->_a.y + cos(degreeToRadian(this->_currAngles.rotationAngle)) * this->_length * cos(degreeToRadian(this->_currAngles.twistingAngle));
	this->_b.z = this->_a.z + sin(degreeToRadian(this->_currAngles.rotationAngle)) * this->_length;
	//printf("\n computeB(prevLink): x=%d, y=%d, z=%d", this->_b.x, this->_b.y, this->_b.z);
	return this->_b;
}

int Link::getLength() const
{
	return this->_length;
}

int Link::getTurn() const
{
	return this->_joint->getAngle();
}

void Link::setA(Point a)
{
	this->_a = a;
}

void Link::setAngles(Angles angles)
{
	this->_currAngles = angles;
}

Angles Link::getAngles() const
{
	return this->_currAngles;
}

void Link::randomizeAngle()
{
	this->_joint->randomizeAngle();
}

void Link::swapJoints(Link & link)
{
	Joint* tmp = link._joint;
	link._joint = this->_joint;
	this->_joint = tmp;
}

bool Link::isIntersectsHorizPlane(int z)
{
	return ((z - this->_a.z) * (z - this->_b.z) < 0);
}
