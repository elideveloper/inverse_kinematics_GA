#ifndef UTILITY_H
#define UTILITY_H

const double PImul3 = 9.4248;
const double PImul2 = 6.2832;
const double PI_ = 3.1416;
const double PIdiv2 = 1.5708;
const double PIdiv3 = 1.0472;
const double PIdiv4 = 0.7854;

double radianToDegree(double angle);
double degreeToRadian(double angle);

int random(int max);
int random(int min, int max);

#endif