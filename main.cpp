#include<ctime>
#include<iostream>

#include "manipulator.h"
#include "utility.h"


// consider claw 
// terminate if acceptable error is reached
// normalize() function for returning right values for specific servo (270 degree for example)
// introduce a linear joint (change length of link)
// implement revolution joint
// +remove individuals which body intersects obstacle plane


int main() {
	srand(time(0));
	
	clock_t tStart = clock();

	int numLinks = 5;
	Point pos;
	printf("\nPosition: x=%d, y=%d, z=%d", pos.x, pos.y, pos.z);

	Range r(PIdiv4 * 3, -PIdiv4 * 3);
	Link* links = new Link[numLinks];
	Angles startingPos(PIdiv2);
	Point destination(200, 400, 10);

	links[0] = Link(100, new TwistingJoint(r, 0));
	links[1] = Link(150, new RotationJoint(r, 0));
	links[2] = Link(200, new RotationJoint(r, 0));
	links[3] = Link(100, new RotationJoint(r, 0));
	links[4] = Link(100, new RotationJoint(r, 0));
	Manipulator manip(links, numLinks, startingPos);
	pos = manip.computePosition();
	printf("\nError: %d", pos.distanceTo(destination));
	printf("\nPosition: x=%d, y=%d, z=%d", pos.x, pos.y, pos.z);

	manip.reachPosition(destination);
	pos = manip.computePosition();
	printf("\nError: %d", pos.distanceTo(destination));
	printf("\nPosition: x=%d, y=%d, z=%d", pos.x, pos.y, pos.z);
	for (int i = 0; i < numLinks; i++) {
		printf("\nTurn: %d", manip.getJointAngles()[i]);
	}
	printf("\nFor robot analyzer:");
	printf("\nTurn: %d", -manip.getJointAngles()[0]);
	printf("\nTurn: %d", 90+manip.getJointAngles()[1]);
	for (int i = 2; i < numLinks; i++) {
		printf("\nTurn: %d", manip.getJointAngles()[i]);
	}

	printf("\nTime taken: %.8fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);	

	system("pause");
	return 0;
}