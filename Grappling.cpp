#include "Grappling.h"

double getUp(double course, fighter fighter, double position) {

	double temp = 1;
	if (position == 1) temp = 1 / (0.95 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	if (position == 2) temp = 1 / (0.93 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	if ((position == 3) || (position == 6)) temp = 1 / (0.85 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	if ((position == 4) || (position == 5)) temp = 1 / (0.75 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	return 1 + (course - 1)*temp;
}

double guard(double course, fighter fighter, double position) {

	double temp = 1;
	if (position == 1) temp = 1 / (0.9 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	if (position == 2) temp = 1 / (0.88 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	if ((position == 3) || (position == 6)) temp = 1 / (0.8 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	if ((position == 4) || (position == 5)) temp = 1 / (0.7 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	return 1 + (course - 1)*temp*(0.9 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
}

double halfGuard(double course, fighter fighter, double position) {

	double temp = 1;
	if (position == 1) temp = 1 / (0.9 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	if (position == 2) temp = 1 / (0.88 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	if ((position == 3) || (position == 6)) temp = 1 / (0.8 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	if ((position == 4) || (position == 5)) temp = 1 / (0.7 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	return 1 + (course - 1)*temp*(0.88 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
}

double side(double course, fighter fighter, double position) {

	double temp = 1;
	if (position == 1) temp = 1 / (0.9 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	if (position == 2) temp = 1 / (0.88 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	if ((position == 3) || (position == 6)) temp = 1 / (0.8 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	if ((position == 4) || (position == 5)) temp = 1 / (0.7 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	return 1 + (course - 1)*temp*(0.8 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
}

double mount(double course, fighter fighter, double position) {

	double temp = 1;
	if (position == 1) temp = 1 / (0.9 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	if (position == 2) temp = 1 / (0.88 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	if ((position == 3) || (position == 6)) temp = 1 / (0.8 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	if ((position == 4) || (position == 5)) temp = 1 / (0.7 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	return 1 + (course - 1)*temp*(0.7 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
}

double back(double course, fighter fighter, double position) {

	double temp = 1;
	if (position == 1) temp = 1 / (0.9 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	if (position == 2) temp = 1 / (0.88 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	if ((position == 3) || (position == 6)) temp = 1 / (0.8 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	if ((position == 4) || (position == 5)) temp = 1 / (0.7 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	return 1 + (course - 1)*temp*(0.7 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
}

double northSouth(double course, fighter fighter, double position) {

	double temp = 1;
	if (position == 1) temp = 1 / (0.9 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	if (position == 2) temp = 1 / (0.88 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	if ((position == 3) || (position == 6)) temp = 1 / (0.8 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	if ((position == 4) || (position == 5)) temp = 1 / (0.7 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
	return 1 + (course - 1)*temp*(0.8 - 0.2 * (fighter.SUBwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
}

double powerSetter(fighter fighter, double position) {

	if (position == 1)return 0.95 - 0.1*(fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin));
	if (position == 2)return 0.92 - 0.1*(fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin));
	if ((position == 3) || (position == 6))return 0.9 - 0.1*(fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin));
	if ((position == 4) || (position == 5))return 0.8 - 0.1*(fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin));

}
