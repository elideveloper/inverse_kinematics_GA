#include "joint.h"

Joint::Joint()
{
}

Joint::~Joint()
{
}

Joint::Joint(Range angleRange, double angle) : _angleRange(angleRange), _angle(angle)
{
}

double Joint::getAngle() const
{
	return this->_angle;
}

void Joint::randomizeAngle()
{
	this->_angle = this->_angleRange.getRandom();
}

RotationJoint::RotationJoint() : Joint()
{
}

RotationJoint::~RotationJoint()
{
}

RotationJoint::RotationJoint(Range angleRange, double angle) : Joint(angleRange, angle)
{
}

RotationJoint::RotationJoint(const RotationJoint & joint)
{
	this->_angle = joint._angle;
	this->_angleRange = joint._angleRange;
}

Joint* RotationJoint::clone()
{
	return new RotationJoint(*this);
}

void RotationJoint::changeAngles(Angles & angles)
{
	angles.rotationAngle += this->_angle;
}

TwistingJoint::TwistingJoint() : Joint()
{
}

TwistingJoint::~TwistingJoint()
{
}

TwistingJoint::TwistingJoint(Range angleRange, double angle) : Joint(angleRange, angle)
{
}

TwistingJoint::TwistingJoint(const TwistingJoint & joint)
{
	this->_angle = joint._angle;
	this->_angleRange = joint._angleRange;
}

Joint* TwistingJoint::clone()
{
	return new TwistingJoint(*this);
}

void TwistingJoint::changeAngles(Angles & angles)
{
	angles.twistingAngle += this->_angle;
}

RevolutionJoint::RevolutionJoint() : Joint()
{
}

RevolutionJoint::~RevolutionJoint()
{
}

RevolutionJoint::RevolutionJoint(Range angleRange, double angle) : Joint(angleRange, angle)
{
}

RevolutionJoint::RevolutionJoint(const RevolutionJoint & joint)
{
	this->_angle = joint._angle;
	this->_angleRange = joint._angleRange;
}

Joint* RevolutionJoint::clone()
{
	return new RevolutionJoint(*this);
}

void RevolutionJoint::changeAngles(Angles & angles)
{
	angles.revolutionAngle += this->_angle;
}