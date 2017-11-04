#include<ctime>
#include<iostream>

#include "manipulator.h"
#include "utility.h"


// consider claw 
// set right values for randoms in given range (considering assymetric ranges)
// terminate if acceptable error is reached
// normalize() function for returning right values for specific servo (270 degree for example)
// introduce a linear joint (change length of link)
// implement revolution
// remove individuals which body intersects obstruction plane


int main() {
	srand(time(0));

	clock_t tStart = clock();

	int numLinks = 3;
	Point pos;
	printf("\nPosition: x=%.2f, y=%.2f, z=%.2f", pos.x, pos.y, pos.z);

	Range r(PIdiv2, -PIdiv2);
	Link* links = new Link[numLinks];
	Angles startingPos(PIdiv2);

	links[0] = Link(10, new TwistingJoint(r, PIdiv4), startingPos);
	links[1] = Link(10, new RotationJoint(r, 0));
	links[2] = Link(10, new RotationJoint(r, 0));
	Manipulator manip(links, numLinks);

	pos = manip.computePosition();
	printf("\nPosition: x=%.2f, y=%.2f, z=%.2f", pos.x, pos.y, pos.z);

	manip.setStartingPosition(startingPos);
	manip.reachPosition(Point());
	pos = manip.computePosition();
	printf("\nPosition: x=%.2f, y=%.2f, z=%.2f", pos.x, pos.y, pos.z);



	printf("Time taken: %.8fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	printf("Size of one Link: %d", sizeof(Link(10, new TwistingJoint(r, PIdiv4), startingPos)));

	system("pause");
	return 0;
}