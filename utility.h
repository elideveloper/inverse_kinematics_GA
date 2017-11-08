#ifndef UTILITY_H
#define UTILITY_H

const int PImul3 = 540;
const int PImul2 = 360;
const int PI_ = 180;
const int PIdiv2 = 90;
const int PIdiv3 = 60;
const int PIdiv4 = 45;

int radianToDegree(double angle);
double degreeToRadian(int angle);

int random(int max);
int random(int min, int max);

#endif