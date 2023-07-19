#pragma once
#include "Techniques.h"
#include "Grappling.h"

double KO_TKO_cutCloseToEyes(double course, double cutImportance, double minute, double round);

double KO_TKO_brokenNose(double course, double minute, double round);

double KO_TKO_handInjury(double course, double injuryImportance, double minute, double round);

double KO_TKO_legInjury(double course, double injuryImportance, double minute, double round);

double KO_TKO_knockDown(double course, double minute, double round);

double KO_TKO_heavyPunch(double course, double heaviness, double minute, double round);

double KO_TKO_getUp(double course, fighter fighter, double position, double minute);

double KO_TKO_guard(double course, fighter fighter, double position, double minute);

double KO_TKO_halfGuard(double course, fighter fighter, double position, double minute);

double KO_TKO_side(double course, fighter fighter, double position, double minute);

double KO_TKO_mount(double course, fighter fighter, double position, double minute);

double KO_TKO_back(double course, fighter fighter, double position, double minute);

double KO_TKO_northSouth(double course, fighter fighter, double position, double minute);

double KO_TKO_minutePass(double course, double minute, double round);