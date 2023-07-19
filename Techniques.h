#pragma once

#include "Grappling.h"

class fighterInRound {
public:
	double headStrikes = 0;
	double bodyStrikes = 0;
	double legStrikes = 0;
	double knockdown = 0;
	double foul = 0;
	double minusPoints = 0;
	double powerIncreaser = 1;
	double control = 0;
	double controlPhase = 1;
	double controlClinch = 0;
	double controlPhaseClinch = 1;
	double position = 0;
	double points = 0;
	double roundWinned = 0;
};

double headPunchByHand(double course, fighterInRound fighter1);

double headPunchByElbow(double course, fighterInRound fighter1);

double headKick(double course, fighterInRound fighter1);

double headKickByKnee(double course, fighterInRound fighter1);

double bodyPunch(double course, fighterInRound fighter1);

double bodyKick(double course, fighterInRound fighter1);

double bodyKickByKnee(double course, fighterInRound fighter1);

double lowKick(double course, fighterInRound fighter1);

double calfKick(double course, fighterInRound fighter1);

double heavyPunch(double course,double heaviness);