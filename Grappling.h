#pragma once
#include <string>
using namespace std;
#include "Techniques.h"

class fighter {
public:
	string firstName;
	string lastName;
	double KOwin;
	double TKOwin;
	double SUBwin;
	double DECwin;
	double KOloss;
	double TKOloss;
	double SUBloss;
	double DECloss;
	double draw;
};

double getUp(double course, fighter fighter, double position);

double guard(double course, fighter fighter, double position);

double halfGuard(double course, fighter fighter, double position);

double side(double course, fighter fighter, double position);

double mount(double course, fighter fighter, double position);

double back(double course, fighter fighter, double position);

double northSouth(double course, fighter fighter, double position);

double powerSetter(fighter fighter, double position);