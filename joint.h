#ifndef JOINT_H
#define JOINT_H

#include "range.h"
#include "angles.h"
#include "point.h"

class Joint {
public:
	Joint();
	virtual ~Joint();
	Joint(Range angleRange, double angle = 0.0);
	virtual Joint* clone() = 0;
	virtual void changeAngles(Angles & angles) = 0; // computeResultingPoint
	double getAngle() const;
	void randomizeAngle();
protected:
	Range _angleRange;
	double _angle;
};

// rotation in vertical plane
class RotationJoint : public Joint {
public:
	RotationJoint();
	virtual ~RotationJoint();
	RotationJoint(Range angleRange, double angle = 0.0);
	RotationJoint(const RotationJoint & joint);
	virtual Joint* clone();
	virtual void changeAngles(Angles & angles);
};

// twisting in horizontal plane
class TwistingJoint : public Joint {
public:
	TwistingJoint();
	virtual ~TwistingJoint();
	TwistingJoint(Range angleRange, double angle = 0.0);
	TwistingJoint(const TwistingJoint & joint);
	virtual Joint* clone();
	virtual void changeAngles(Angles & angles);
};

// revolution around its axis
class RevolutionJoint : public Joint {
public:
	RevolutionJoint();
	virtual ~RevolutionJoint();
	RevolutionJoint(Range angleRange, double angle = 0.0);
	RevolutionJoint(const RevolutionJoint & joint);
	virtual Joint* clone();
	virtual void changeAngles(Angles & angles);
};

#endif
