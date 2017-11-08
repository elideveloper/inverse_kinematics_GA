#ifndef ANGLES_H
#define ANGLES_H

struct Angles {
	int rotationAngle;
	int twistingAngle;
	int revolutionAngle;
	//Angles();
	Angles(int rotationAngle = 0, int twistingAngle = 0, int revolutionAngle = 0);
	Angles(const Angles & angles);
	Angles & operator= (const Angles & angles);
};

#endif