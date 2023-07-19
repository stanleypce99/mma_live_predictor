#include "KO_TKO.h"

double KO_TKO_cutCloseToEyes(double course, double cutImportance, double minute, double round) {

	return 1 + (course - 1) * (1 - 0.4*cutImportance + 0.4 * cutImportance * (1-((3 - round) * 5 + (5 - minute))/15));
}

double KO_TKO_brokenNose(double course, double minute, double round) {

	return 1 + (course - 1) * (1 - 0.3 + 0.3 * (1 - ((3 - round) * 5 + (5 - minute)) / 15));
}

double KO_TKO_handInjury(double course, double injuryImportance, double minute, double round) {

	return 1 + (course - 1) * (1 - 0.4*injuryImportance + 0.4 * injuryImportance * (1 - ((3 - round) * 5 + (5 - minute)) / 15));
}

double KO_TKO_legInjury(double course, double injuryImportance, double minute, double round) {

	return 1 + (course - 1) * (1 - 0.4*injuryImportance + 0.4 * injuryImportance * (1 - ((3 - round) * 5 + (5 - minute)) / 15));
}

double KO_TKO_knockDown(double course, double minute, double round) {

	return 1 + (course - 1) * (1 - 0.4 + 0.4 * (1 - ((3 - round) * 5 + (5 - minute)) / 15));
}

double KO_TKO_heavyPunch(double course, double heaviness, double minute, double round) {

	return 1 + (course - 1) * (1 - 0.4*heaviness + 0.4 * heaviness * (1 - ((3 - round) * 5 + (5 - minute)) / 15));
}

double KO_TKO_getUp(double course, fighter fighter, double position, double minute) {

	double temp = 1;
	if (position == 1) temp = 1 / (0.95 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	if (position == 2) temp = 1 / (0.93 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	if ((position == 3) || (position == 6)) temp = 1 / (0.85 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	if ((position == 4) || (position == 5)) temp = 1 / (0.75 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	return 1 + (course - 1)*temp;
}

double KO_TKO_guard(double course, fighter fighter, double position, double minute) {

	double temp = 1;
	if (position == 1) temp = 1 / (0.95 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	if (position == 2) temp = 1 / (0.93 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	if ((position == 3) || (position == 6)) temp = 1 / (0.85 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	if ((position == 4) || (position == 5)) temp = 1 / (0.75 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	return 1 + (course - 1)*temp*(0.95 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));;
}

double KO_TKO_halfGuard(double course, fighter fighter, double position, double minute) {

	double temp = 1;
	if (position == 1) temp = 1 / (0.95 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	if (position == 2) temp = 1 / (0.93 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	if ((position == 3) || (position == 6)) temp = 1 / (0.85 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	if ((position == 4) || (position == 5)) temp = 1 / (0.75 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	return 1 + (course - 1)*temp*(0.93 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));;

}

double KO_TKO_side(double course, fighter fighter, double position, double minute) {

	double temp = 1;
	if (position == 1) temp = 1 / (0.95 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	if (position == 2) temp = 1 / (0.93 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	if ((position == 3) || (position == 6)) temp = 1 / (0.85 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	if ((position == 4) || (position == 5)) temp = 1 / (0.75 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	return 1 + (course - 1)*temp*(0.85 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));;

}

double KO_TKO_mount(double course, fighter fighter, double position, double minute) {

	double temp = 1;
	if (position == 1) temp = 1 / (0.95 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	if (position == 2) temp = 1 / (0.93 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	if ((position == 3) || (position == 6)) temp = 1 / (0.85 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	if ((position == 4) || (position == 5)) temp = 1 / (0.75 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	return 1 + (course - 1)*temp*(0.75 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));;

}

double KO_TKO_back(double course, fighter fighter, double position, double minute) {

	double temp = 1;
	if (position == 1) temp = 1 / (0.95 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	if (position == 2) temp = 1 / (0.93 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	if ((position == 3) || (position == 6)) temp = 1 / (0.85 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	if ((position == 4) || (position == 5)) temp = 1 / (0.75 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	return 1 + (course - 1)*temp*(0.75 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));;

}

double KO_TKO_northSouth(double course, fighter fighter, double position, double minute) {

	double temp = 1;
	if (position == 1) temp = 1 / (0.95 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	if (position == 2) temp = 1 / (0.93 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	if ((position == 3) || (position == 6)) temp = 1 / (0.85 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	if ((position == 4) || (position == 5)) temp = 1 / (0.75 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));
	return 1 + (course - 1)*temp*(0.85 - 0.2 * (fighter.TKOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) + 0.2 * ((fighter.SUBwin + fighter.TKOwin) / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)) * (1 - (5 - minute) / 5));;

}

double KO_TKO_minutePass(double course, double minute, double round) {

	return 1 + (course - 1) / ((3-round) * 5 + (5-minute) + 1) * ((3 - round) * 5 + (5-minute));
}