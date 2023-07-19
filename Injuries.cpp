#include "Injuries.h"

double cutCloseToEyes(double course, double cutImportance) {

	return 1 + (course - 1)*(1.1 + 0.2*cutImportance);
}

double brokenNose(double course) {

	return 1 + (course - 1)*1.2;
}

double handInjury(double course, double injuryImportance) {

	return 1 + (course - 1)*(1.1 + 0.2*injuryImportance);
}

double legInjury(double course, double injuryImportance) {

	return 1 + (course - 1)*(1.1 + 0.2*injuryImportance);
}
