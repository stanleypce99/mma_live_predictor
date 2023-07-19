#include "Techniques.h"


double headPunchByHand(double course, fighterInRound fighter1) {

	return 1 + (course - 1)*(fighter1.powerIncreaser - 0.015);
}

double headPunchByElbow(double course, fighterInRound fighter1) {

	return 1 + (course - 1)*(fighter1.powerIncreaser - 0.03);
}

double headKick(double course, fighterInRound fighter1) {

	return 1 + (course - 1)*(1 - 0.045);
}

double headKickByKnee(double course, fighterInRound fighter1) {

	return 1 + (course - 1)*(1 - 0.05);
}

double bodyPunch(double course, fighterInRound fighter1) {

	return 1 + (course - 1)*(fighter1.powerIncreaser - 0.01);
}

double bodyKick(double course, fighterInRound fighter1) {

	return 1 + (course - 1)*(1 - 0.02);
}

double bodyKickByKnee(double course, fighterInRound fighter1) {

	return 1 + (course - 1)*(fighter1.powerIncreaser - 0.015);
}

double lowKick(double course, fighterInRound fighter1) {

	return 1 + (course - 1)*(1 - 0.015);
}

double calfKick(double course, fighterInRound fighter1) {

	return 1 + (course - 1)*(1 - 0.02);
}
double heavyPunch(double course, double heaviness) {

	return 1 + (course - 1)*(0.95-0.15*heaviness);
}