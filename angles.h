#ifndef ANGLES_H
#define ANGLES_H

struct Angles {
	double rotationAngle;
	double twistingAngle;
	double revolutionAngle;
	//Angles();
	Angles(double rotationAngle = 0.0, double twistingAngle = 0.0, double revolutionAngle = 0.0);
	Angles(const Angles & angles);
	Angles & operator= (const Angles & angles);
};

#endif