#include <iostream>
#include <cmath>
#include <string>
using namespace std;

#include "Techniques.h"
#include "Injuries.h"
#include "Grappling.h"
#include "KO_TKO.h"

double courseCount(double course);

double courseCorrection(double course);

double courseSet(void);

double knockDown(double course, fighter fighter);

double pointDown(double course, fighter fighter);

double foul(double course, fighter fighter);


int main() {

	fighter fighter1;
	fighter fighter2;

	cout << "First fighter first name.\n";
	cin >> fighter1.firstName;

	cout << "First fighter last name.\n";
	cin >> fighter1.lastName;
	
	cout << fighter1.lastName << "'s number of wins by KO.\n";
	cin >> fighter1.KOwin;

	cout << fighter1.lastName << "'s number of wins by TKO.\n";
	cin >> fighter1.TKOwin;

	cout << fighter1.lastName << "'s number of wins by submissions.\n";
	cin >> fighter1.SUBwin;

	cout << fighter1.lastName << "'s number of wins by decision.\n";
	cin >> fighter1.DECwin;

	cout << fighter1.lastName << "'s number of loss by KO.\n";
	cin >> fighter1.KOloss;

	cout << fighter1.lastName << "'s number of loss by TKO.\n";
	cin >> fighter1.TKOloss;

	cout << fighter1.lastName << "'s number of loss by submissions.\n";
	cin >> fighter1.SUBloss;

	cout << fighter1.lastName << "'s number of loss by decision.\n";
	cin >> fighter1.DECloss;

	cout << fighter1.lastName << "'s number of draws.\n";
	cin >> fighter1.draw;

	cout << "\n";

	double win1 = fighter1.KOwin + fighter1.TKOwin + fighter1.SUBwin + fighter1.DECwin;
	double loss1 = fighter1.KOloss + fighter1.TKOloss + fighter1.SUBloss + fighter1.DECloss;

	////////////////////////////////////////////////////////////////

	cout << fighter1.firstName << " " << fighter1.lastName << "\n";
	cout << win1 << " - " << loss1 << " - " << fighter1.draw << "\n";
	cout << "\n";

	////////////////////////////////////////////////////////////////

	cout << "Second fighter first name.\n";
	cin >> fighter2.firstName;

	cout << "Second fighter last name.\n";
	cin >> fighter2.lastName;

	cout << fighter2.lastName << "'s number of wins by KO.\n";
	cin >> fighter2.KOwin;

	cout << fighter2.lastName << "'s number of wins by TKO.\n";
	cin >> fighter2.TKOwin;

	cout << fighter2.lastName << "'s number of wins by submissions.\n";
	cin >> fighter2.SUBwin;

	cout << fighter2.lastName << "'s number of wins by decision.\n";
	cin >> fighter2.DECwin;

	cout << fighter2.lastName << "'s number of loss by KO.\n";
	cin >> fighter2.KOloss;

	cout << fighter2.lastName << "'s number of loss by TKO.\n";
	cin >> fighter2.TKOloss;

	cout << fighter2.lastName << "'s number of loss by submissions.\n";
	cin >> fighter2.SUBloss;

	cout << fighter2.lastName << "'s number of loss by decision.\n";
	cin >> fighter2.DECloss;

	cout << fighter2.lastName << "'s number of draws.\n";
	cin >> fighter2.draw;
		
	cout << "\n";

	double win2 = fighter2.KOwin + fighter2.TKOwin + fighter2.SUBwin + fighter2.DECwin;
	double loss2 = fighter2.KOloss + fighter2.TKOloss + fighter2.SUBloss + fighter2.DECloss;

	////////////////////////////////////////////////////////////////

	cout << fighter2.firstName << " " << fighter2.lastName << "\n";
	cout << win2 << " - " << loss2 << " - " << fighter2.draw << "\n";

	////////////////////////////////////////////////////////////////

	cout << "Both fighters info collected.\n\n";

	double wincourse1;
	double wincourse2;

	cout << "Course on " << fighter1.firstName << " " << fighter1.lastName << ":\n";
	cin >> wincourse1;
	cout << "Course on " << fighter2.firstName << " " << fighter2.lastName << ":\n";
	cin >> wincourse2;
	cout << "\n";

	double KO_TKOcourse;

	cout << "Course on match ending by KO/TKO:\n";
	cin >> KO_TKOcourse;
	double NoKO_TKOcourse = courseCount(KO_TKOcourse);
	cout << "\n";

	double SUBcourse;

	cout << "Course on match ending by submission:\n";
	cin >> SUBcourse;
	double NoSUBcourse = courseCount(SUBcourse);
	cout << "\n";

	double DECcourse;

	cout << "Course on match ending by decision:\n";
	cin >> DECcourse;
	double NoDECcourse = courseCount(DECcourse);
	cout << "\n";

	double lessThan1_5Rounds;

	cout << "Course on less than 1,5 round will be started:\n";
	cin >> lessThan1_5Rounds;
	cout << "\n";

	double moreThan1_5Rounds;

	cout << "Course on more than 1,5 round will be started:\n";
	cin >> moreThan1_5Rounds;
	cout << "\n";

	double lessThan2_5Rounds;

	cout << "Course on less than 2,5 round will be started:\n";
	cin >> lessThan2_5Rounds;
	cout << "\n";

	double moreThan2_5Rounds;

	cout << "Course on more than 2,5 round will be started:\n";
	cin >> moreThan2_5Rounds;
	cout << "\n";

	////////////////////////////////////////////////////////////////
	
	int round = 1;
	string who = "who";
	string where = "where";
	string situation = "situation";
	double cutImportance = 0;
	double injuryImportance = 0;
	double timeGround = 0;
	double timeClinch = 0;
	double heaviness = 0;
	double minute = 0;

	////////////////////////////////////////////////////////////////

	fighterInRound fighter1FirstRound;
	fighterInRound fighter2FirstRound;

	////////////////////////////////////////////////////////////////

	cout << "By writing spicific words you can simulate a match.\n";
	cout << "First you write last name of fighter,if the action was while standing, in clinch or on ground and action itself.\n\n";
	cout << "Actions:\nHeadPunchByHand HeadPunchByElbow HeadKick HeadKickByKnee BodyPunch  BodyKick BodyKickByKnee LowKick CalfKick - Standing\n";
	cout << "HeadPunchByHand HeadPunchByElbow HeadKickByKnee BodyPunch BodyKickByKnee - Clinch\n";
	cout << "HeadPunchByHand HeadPunchByElbow BodyPunch BodyKickByKnee Guard Halfguard Side Mount Back NorthSouth - Ground\n";
	cout << "If fighter was on ground in better position and looses this possition and fighters stand up, write name of fighter that was dominating and GetUp\n\n";
	cout << "As well you can use control time. So when figter control opponent in clinch or on ground for some seconds, you write his name, than GroundControl/ClinchControl and time (in sec.) of that control.\n\n"; 
	cout << "Example:\nProchazka\nStanding\nLowkick\n\n";
	cout << "When fighter knocksdown opponent, write his name, and Knockdown\n";
	cout << "When fighter makes a heavy punch, that affect opponent, write his name, HeavyPunch and number of heaviness\n\n";
	cout << "When someone has injury, you start with name, than injury, than what body part was injured.\n";
	cout << "Injuries:\nCutCloseToEyes BrokenNose HandInjury LegInjury\n";
	cout << "When a fighter has a cut close to eyes (or on head), you have to add number of importance.(same for importance of hand or leg injury)\n\n";
	cout << "When a point is taken from somebody, write hisname and PointDown, when someone cause a foul, write his name and Foul.\n";
	cout << "When a minute pass by, write Minute.(In all rounds at 1:00, 2:00, 3:00 adn 4:00)\n";
	cout << "If you want to set fighters course, write his name, CourseSet and value of that course.\n";
	cout << "When the round is stopped, write RoundEnd.\n\n";

	////////////////////////////////////////////////////////////////

	cout << "Start of first round. (ding ding)\n\n";

	////////////////////////////////////////////////////////////////

	while (round == 1) {

		cout << "Who?\n";
		cin >> who;
		if (!(who == "RoundEnd")) {
			cout << "What?/Where?\n";
			cin >> where;
			if (!(where == "PointDown") && !(where == "GetUp") && !(where == "Injury") && !(where == "Foul") && !(where == "Knockdown") && !(where == "GroundControl") && !(where == "CourseSet") && !(where == "HeavyPunch")) {

				cout << "Situation?\n";
				cin >> situation;
			}
		}

		if ((who == fighter1.firstName) || who == (fighter1.lastName)){

			///////////////////////////////////////////////////////
			if (where == "CourseSet") {
				wincourse1 = courseSet();
				wincourse2 = courseCount(wincourse1);
			}
			///////////////////////////////////////////////////////
			if (where == "Knockdown") {
				wincourse1 = knockDown(wincourse1, fighter1);
				wincourse2 = courseCount(wincourse1);
				KO_TKOcourse = KO_TKO_knockDown(KO_TKOcourse, minute, round);
				NoKO_TKOcourse = courseCount(KO_TKOcourse);
				fighter1FirstRound.knockdown++;
				fighter1FirstRound.points += 12;
			}
			///////////////////////////////////////////////////////
			else if (where == "Injury") {
				cout << "What injury?\n";
				cin >> situation;
				if (situation == "CutCloseToEyes") {
					cout << "How important cut?\nin range 0-1 | 0 - not important | 1 - most important (focus on probability of doctor stoppage or if blood goes into fighters eyes)\n";
					cin >> cutImportance;
					wincourse1 = cutCloseToEyes(wincourse1, cutImportance);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_cutCloseToEyes(KO_TKOcourse, cutImportance, minute, round);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
				}
				else if (situation == "BrokenNose") {
					wincourse1 = brokenNose(wincourse1);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_brokenNose(KO_TKOcourse, minute, round);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
				}
				else if (situation == "HandInjury") {
					cout << "How important injury?\nin range 0-1 | 0 - not important | 1 - most important\n";
					cin >> injuryImportance;
					wincourse1 = handInjury(wincourse1, injuryImportance);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_handInjury(KO_TKOcourse, injuryImportance, minute, round);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
				}
				else if (situation == "LegInjury") {
					cout << "How important injury?\nin range 0-1 | 0 - not important | 1 - most important\n";
					cin >> injuryImportance;
					wincourse1 = legInjury(wincourse1, injuryImportance);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_legInjury(KO_TKOcourse, injuryImportance, minute, round);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
				}
				else {
					cout << "Wrong injury describe. Try again.\n";
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "PointDown") {
				wincourse1 = pointDown(wincourse1, fighter1);
				wincourse2 = courseCount(wincourse1);
				fighter1FirstRound.minusPoints++;
			}
			///////////////////////////////////////////////////////
			else if (where == "Foul") {
				wincourse1 = foul(wincourse1, fighter1);
				wincourse2 = courseCount(wincourse1);
				fighter1FirstRound.foul++;
			}
			///////////////////////////////////////////////////////
			else if (where == "Standing") {

				if (situation == "HeadPunchByHand") {
					if (fighter1FirstRound.headStrikes > 2) {
						wincourse1 = headPunchByHand(wincourse1, fighter1FirstRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1FirstRound.headStrikes++;
					fighter1FirstRound.points += 1;
				}
				else if (situation == "HeadPunchByElbow") {
					if (fighter1FirstRound.headStrikes > 2) {
						wincourse1 = headPunchByElbow(wincourse1, fighter1FirstRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1FirstRound.headStrikes++;
					fighter1FirstRound.points += 2;
				}
				else if (situation == "HeadKick") {
					if (fighter1FirstRound.headStrikes > 2) {
						wincourse1 = headKick(wincourse1, fighter1FirstRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1FirstRound.headStrikes++;
					fighter1FirstRound.points += 3;
				}
				else if (situation == "HeadKickByKnee") {
					if (fighter1FirstRound.headStrikes > 2) {
						wincourse1 = headKickByKnee(wincourse1, fighter1FirstRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1FirstRound.headStrikes++;
					fighter1FirstRound.points += 4;
				}
				else if (situation == "BodyPunch") {
					if (fighter1FirstRound.bodyStrikes > 2) {
						wincourse1 = bodyPunch(wincourse1, fighter1FirstRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1FirstRound.bodyStrikes++;
					fighter1FirstRound.points += 1;
				}
				else if (situation == "BodyKick") {
					if (fighter1FirstRound.bodyStrikes > 2) {
						wincourse1 = bodyKick(wincourse1, fighter1FirstRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1FirstRound.bodyStrikes++;
					fighter1FirstRound.points += 2;
				}
				else if (situation == "BodyKickByKnee") {
					if (fighter1FirstRound.bodyStrikes > 2) {
						wincourse1 = bodyKickByKnee(wincourse1, fighter1FirstRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1FirstRound.bodyStrikes++;
					fighter1FirstRound.points += 2;
				}
				else if (situation == "LowKick") {
					if (fighter1FirstRound.legStrikes > 2) {
						wincourse1 = lowKick(wincourse1, fighter1FirstRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1FirstRound.legStrikes++;
					fighter1FirstRound.points += 1;
				}
				else if (situation == "CalfKick") {
					if (fighter1FirstRound.legStrikes > 2) {
						wincourse1 = calfKick(wincourse1, fighter1FirstRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1FirstRound.legStrikes++;
					fighter1FirstRound.points += 1;
				}
				else {
					cout << "Wrong action describe. Try again.\n";
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "Clinch") {

				if (situation == "HeadPunchByHand") {
					if (fighter1FirstRound.headStrikes > 2) {
						wincourse1 = headPunchByHand(wincourse1, fighter1FirstRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1FirstRound.headStrikes++;
					fighter1FirstRound.points += 1;
				}
				else if (situation == "HeadPunchByElbow") {
					if (fighter1FirstRound.headStrikes > 2) {
						wincourse1 = headPunchByElbow(wincourse1, fighter1FirstRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1FirstRound.headStrikes++;
					fighter1FirstRound.points += 2;
				}
				else if (situation == "HeadKickByKnee") {
					if (fighter1FirstRound.headStrikes > 2) {
						wincourse1 = headKickByKnee(wincourse1, fighter1FirstRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1FirstRound.headStrikes++;
					fighter1FirstRound.points += 3;
				}
				else if (situation == "BodyPunch") {
					if (fighter1FirstRound.bodyStrikes > 2) {
						wincourse1 = bodyPunch(wincourse1, fighter1FirstRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1FirstRound.bodyStrikes++;
					fighter1FirstRound.points += 1;
				}
				else if (situation == "BodyKickByKnee") {
					if (fighter1FirstRound.bodyStrikes > 2) {
						wincourse1 = bodyKickByKnee(wincourse1, fighter1FirstRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1FirstRound.bodyStrikes++;
					fighter1FirstRound.points += 2;
				}
				else {
					cout << "Wrong action describe. Try again.\n";
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "Ground") {

				if (situation == "HeadPunchByHand") {
					if (fighter1FirstRound.headStrikes > 2) {
						wincourse1 = headPunchByHand(wincourse1, fighter1FirstRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1FirstRound.headStrikes++;
					fighter1FirstRound.points += 1;
				}
				else if (situation == "HeadPunchByElbow") {
					if (fighter1FirstRound.headStrikes > 2) {
						wincourse1 = headPunchByElbow(wincourse1, fighter1FirstRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1FirstRound.headStrikes++;
					fighter1FirstRound.points += 3;
				}
				else if (situation == "BodyPunch") {
					if (fighter1FirstRound.headStrikes > 2) {
						wincourse1 = bodyPunch(wincourse1, fighter1FirstRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1FirstRound.bodyStrikes++;
					fighter1FirstRound.points += 1;
				}
				else if (situation == "BodyKickByKnee") {
					if (fighter1FirstRound.headStrikes > 2) {
						wincourse1 = bodyKickByKnee(wincourse1, fighter1FirstRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1FirstRound.bodyStrikes++;
					fighter1FirstRound.points += 2;
				}
				else if (situation == "Guard") {
					wincourse1 = guard(wincourse1, fighter1, fighter1FirstRound.position);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_guard(KO_TKOcourse, fighter1, fighter1FirstRound.position, minute);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
					fighter1FirstRound.position = 1;
					fighter1FirstRound.powerIncreaser = powerSetter(fighter1, fighter1FirstRound.position);
				}
				else if (situation == "Halfguard") {
					wincourse1 = halfGuard(wincourse1, fighter1, fighter1FirstRound.position);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_halfGuard(KO_TKOcourse, fighter1, fighter1FirstRound.position, minute);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
					fighter1FirstRound.position = 2;
					fighter1FirstRound.powerIncreaser = powerSetter(fighter1, fighter1FirstRound.position);
				}
				else if (situation == "Side") {
					wincourse1 = side(wincourse1, fighter1, fighter1FirstRound.position);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_side(KO_TKOcourse, fighter1, fighter1FirstRound.position, minute);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
					fighter1FirstRound.position = 3;
					fighter1FirstRound.powerIncreaser = powerSetter(fighter1, fighter1FirstRound.position);
				}
				else if (situation == "Mount") {
					wincourse1 = mount(wincourse1, fighter1, fighter1FirstRound.position);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_mount(KO_TKOcourse, fighter1, fighter1FirstRound.position, minute);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
					fighter1FirstRound.position = 4;
					fighter1FirstRound.powerIncreaser = powerSetter(fighter1, fighter1FirstRound.position);
				}
				else if (situation == "Back") {
					wincourse1 = back(wincourse1, fighter1, fighter1FirstRound.position);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_back(KO_TKOcourse, fighter1, fighter1FirstRound.position, minute);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
					fighter1FirstRound.position = 5;
					fighter1FirstRound.powerIncreaser = powerSetter(fighter1, fighter1FirstRound.position);
				}
				else if (situation == "NorthSouth") {
					wincourse1 = northSouth(wincourse1, fighter1, fighter1FirstRound.position);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_northSouth(KO_TKOcourse, fighter1, fighter1FirstRound.position, minute);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
					fighter1FirstRound.position = 6;
					fighter1FirstRound.powerIncreaser = powerSetter(fighter1, fighter1FirstRound.position);
				}
				else {
					cout << "Wrong action describe. Try again.\n";
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "GetUp") {
				fighter1FirstRound.position = 0;
				wincourse1 = getUp(wincourse1, fighter1, fighter1FirstRound.position);
				wincourse2 = courseCount(wincourse1);
				KO_TKOcourse = KO_TKO_getUp(KO_TKOcourse, fighter1, fighter1FirstRound.position, minute);
				NoKO_TKOcourse = courseCount(KO_TKOcourse);
				fighter1FirstRound.powerIncreaser = 1;
			}
			///////////////////////////////////////////////////////
			else if (where == "GroundControl") {
				cout << "How long? (in sec)?\n";
				cin >> timeGround;
				fighter1FirstRound.control += timeGround;
				if (timeGround > 100 && fighter1FirstRound.control < 100) {
					fighter1FirstRound.controlPhase = fighter1FirstRound.controlPhase + 1;
					wincourse1 = 1 + (wincourse1 - 1)*0.9;
					wincourse2 = courseCount(wincourse1);
				}
				if (timeGround > 200) {
					fighter1FirstRound.controlPhase = fighter1FirstRound.controlPhase + 2;
					wincourse1 = 1 + (wincourse1 - 1)*0.81;
					wincourse2 = courseCount(wincourse1);
				}
				timeGround = 0;

				if (fighter1FirstRound.control < 100) {
					if (fighter1FirstRound.controlPhase == 1) {
						wincourse1 = 1 + (wincourse1 - 1)*0.9;
						wincourse2 = courseCount(wincourse1);
						fighter1FirstRound.controlPhase = 2;
						fighter1FirstRound.points += 5;
					}
				}
				else if (fighter1FirstRound.control > 100 && fighter1FirstRound.control < 200) {
					if (fighter1FirstRound.controlPhase == 2) {
						wincourse1 = 1 + (wincourse1 - 1)*0.9;
						wincourse2 = courseCount(wincourse1);
						fighter1FirstRound.controlPhase = 3;
						fighter1FirstRound.points += 15;
					}
				}
				else if (fighter1FirstRound.control > 200) {
					if (fighter1FirstRound.controlPhase == 3) {
						wincourse1 = 1 + (wincourse1 - 1)*0.9;
						wincourse2 = courseCount(wincourse1);
						fighter1FirstRound.controlPhase = 4;
						fighter1FirstRound.points += 30;
					}
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "ClinchControl") {
			cout << "How long? (in sec)?\n";
			cin >> timeClinch;
			fighter1FirstRound.controlClinch += timeClinch;
			if (timeClinch > 100 && fighter1FirstRound.controlClinch < 100) {
				fighter1FirstRound.controlPhaseClinch = fighter1FirstRound.controlPhaseClinch + 1;
				wincourse1 = 1 + (wincourse1 - 1)*0.95;
				wincourse2 = courseCount(wincourse1);
			}
			if (timeClinch > 200) {
				fighter1FirstRound.controlPhaseClinch = fighter1FirstRound.controlPhaseClinch + 2;
				wincourse1 = 1 + (wincourse1 - 1)*0.9025;
				wincourse2 = courseCount(wincourse1);
			}
			timeClinch = 0;

			if (fighter1FirstRound.controlClinch < 100) {
				if (fighter1FirstRound.controlPhaseClinch == 1) {
					wincourse1 = 1 + (wincourse1 - 1)*0.95;
					wincourse2 = courseCount(wincourse1);
					fighter1FirstRound.controlPhase = 2;
				}
			}
			else if (fighter1FirstRound.controlClinch > 100 && fighter1FirstRound.controlClinch < 200) {
				if (fighter1FirstRound.controlPhaseClinch == 2) {
					wincourse1 = 1 + (wincourse1 - 1)*0.95;
					wincourse2 = courseCount(wincourse1);
					fighter1FirstRound.controlPhaseClinch = 3;
				}
			}
			else if (fighter1FirstRound.controlClinch > 200) {
				if (fighter1FirstRound.controlPhaseClinch == 3) {
					wincourse1 = 1 + (wincourse1 - 1)*0.95;
					wincourse2 = courseCount(wincourse1);
					fighter1FirstRound.controlPhaseClinch = 4;
				}
			}
			}
			///////////////////////////////////////////////////////
			else if (where == "HeavyPunch") {
			cout << "How much did the punch affect opponent?\nin range 0-1 | 0 - not much | 1 - very much\n(1 means almost knockdown, but opponent is still standing)\n";
			heaviness = 0;
			cin >> heaviness;
			wincourse1 = heavyPunch(wincourse1, heaviness);
			wincourse2 = courseCount(wincourse1);
			KO_TKOcourse = KO_TKO_heavyPunch(KO_TKOcourse, heaviness, minute, round);
			NoKO_TKOcourse = courseCount(KO_TKOcourse);
			fighter1FirstRound.headStrikes++;
			fighter1FirstRound.points += 10;
			}
			///////////////////////////////////////////////////////
			else {
				cout << "Something went wrong. Try again.\n";
			}
		}// end of fighter1 actions

		///////////////////////////////////////////////////////

		else if ((who == fighter2.firstName) || who == (fighter2.lastName)) {

		///////////////////////////////////////////////////////
		if (where == "CourseSet") {
			wincourse2 = courseSet();
			wincourse1 = courseCount(wincourse2);
		}
		///////////////////////////////////////////////////////
		if (where == "Knockdown") {
			wincourse2 = knockDown(wincourse2, fighter2);
			wincourse1 = courseCount(wincourse2);
			KO_TKOcourse = KO_TKO_knockDown(KO_TKOcourse, minute, round);
			NoKO_TKOcourse = courseCount(KO_TKOcourse);
			fighter2FirstRound.knockdown++;
			fighter2FirstRound.points += 12;
		}
		///////////////////////////////////////////////////////
		else if (where == "Injury") {
			cout << "What injury?\n";
			cin >> situation;
			if (situation == "CutCloseToEyes") {
				cout << "How important cut?\nin range 0-1 | 0 - not important | 1 - most important (focus on probability of doctor stoppage or if blood goes into fighters eyes)\n";
				cin >> cutImportance;
				wincourse2 = cutCloseToEyes(wincourse2, cutImportance);
				wincourse1 = courseCount(wincourse2);
				KO_TKOcourse = KO_TKO_cutCloseToEyes(KO_TKOcourse, cutImportance, minute, round);
				NoKO_TKOcourse = courseCount(KO_TKOcourse);
			}
			else if (situation == "BrokenNose") {
				wincourse2 = brokenNose(wincourse2);
				wincourse1 = courseCount(wincourse2);
				KO_TKOcourse = KO_TKO_brokenNose(KO_TKOcourse, minute, round);
				NoKO_TKOcourse = courseCount(KO_TKOcourse);
			}
			else if (situation == "HandInjury") {
				cout << "How important injury?\nin range 0-1 | 0 - not important | 1 - most important\n";
				cin >> injuryImportance;
				wincourse2 = handInjury(wincourse2, injuryImportance);
				wincourse1 = courseCount(wincourse2);
				KO_TKOcourse = KO_TKO_handInjury(KO_TKOcourse, injuryImportance, minute, round);
				NoKO_TKOcourse = courseCount(KO_TKOcourse);
			}
			else if (situation == "LegInjury") {
				cout << "How important injury?\nin range 0-1 | 0 - not important | 1 - most important\n";
				cin >> injuryImportance;
				wincourse2 = legInjury(wincourse2, injuryImportance);
				wincourse1 = courseCount(wincourse2);
				KO_TKOcourse = KO_TKO_legInjury(KO_TKOcourse, injuryImportance, minute, round);
				NoKO_TKOcourse = courseCount(KO_TKOcourse);
			}
			else {
				cout << "Wrong injury describe. Try again.\n";
			}
		}
		///////////////////////////////////////////////////////
		else if (where == "PointDown") {
			wincourse2 = pointDown(wincourse2, fighter2);
			wincourse1 = courseCount(wincourse2);
			fighter2FirstRound.minusPoints++;
		}
		///////////////////////////////////////////////////////
		else if (where == "Foul") {
			wincourse2 = foul(wincourse2, fighter2);
			wincourse1 = courseCount(wincourse2);
			fighter2FirstRound.foul++;
		}
		///////////////////////////////////////////////////////
		else if (where == "Standing") {

			if (situation == "HeadPunchByHand") {
				if (fighter2FirstRound.headStrikes > 2) {
					wincourse2 = headPunchByHand(wincourse2, fighter2FirstRound);
					wincourse1 = courseCount(wincourse2);
				}
				fighter2FirstRound.headStrikes++;
				fighter2FirstRound.points += 1;
			}
			else if (situation == "HeadPunchByElbow") {
				if (fighter2FirstRound.headStrikes > 2) {
					wincourse2 = headPunchByElbow(wincourse2, fighter2FirstRound);
					wincourse1 = courseCount(wincourse2);
				}
				fighter2FirstRound.headStrikes++;
				fighter2FirstRound.points += 2;
			}
			else if (situation == "HeadKick") {
				if (fighter2FirstRound.headStrikes > 2) {
					wincourse2 = headKick(wincourse2, fighter2FirstRound);
					wincourse1 = courseCount(wincourse2);
				}
				fighter2FirstRound.headStrikes++;
				fighter2FirstRound.points += 3;
			}
			else if (situation == "HeadKickByKnee") {
				if (fighter2FirstRound.headStrikes > 2) {
					wincourse2 = headKickByKnee(wincourse2, fighter2FirstRound);
					wincourse1 = courseCount(wincourse2);
				}
				fighter2FirstRound.headStrikes++;
				fighter2FirstRound.points += 4;
			}
			else if (situation == "BodyPunch") {
				if (fighter2FirstRound.bodyStrikes > 2) {
					wincourse2 = bodyPunch(wincourse2, fighter2FirstRound);
					wincourse1 = courseCount(wincourse2);
				}
				fighter2FirstRound.bodyStrikes++;
				fighter2FirstRound.points += 1;
			}
			else if (situation == "BodyKick") {
				if (fighter2FirstRound.bodyStrikes > 2) {
					wincourse2 = bodyKick(wincourse2, fighter2FirstRound);
					wincourse1 = courseCount(wincourse2);
				}
				fighter2FirstRound.bodyStrikes++;
				fighter2FirstRound.points += 2;
			}
			else if (situation == "BodyKickByKnee") {
				if (fighter2FirstRound.bodyStrikes > 2) {
					wincourse2 = bodyKickByKnee(wincourse2, fighter2FirstRound);
					wincourse1 = courseCount(wincourse2);
				}
				fighter2FirstRound.bodyStrikes++;
				fighter2FirstRound.points += 2;
			}
			else if (situation == "LowKick") {
				if (fighter2FirstRound.legStrikes > 2) {
					wincourse2 = lowKick(wincourse2, fighter2FirstRound);
					wincourse1 = courseCount(wincourse2);
				}
				fighter2FirstRound.legStrikes++;
				fighter2FirstRound.points += 1;
			}
			else if (situation == "CalfKick") {
				if (fighter2FirstRound.legStrikes > 2) {
					wincourse2 = calfKick(wincourse2, fighter2FirstRound);
					wincourse1 = courseCount(wincourse2);
				}
				fighter2FirstRound.legStrikes++;
				fighter2FirstRound.points += 1;
			}
			else {
				cout << "Wrong action describe. Try again.\n";
			}
		}
		///////////////////////////////////////////////////////
		else if (where == "Clinch") {

			if (situation == "HeadPunchByHand") {
				if (fighter2FirstRound.headStrikes > 2) {
					wincourse2 = headPunchByHand(wincourse2, fighter2FirstRound);
					wincourse1 = courseCount(wincourse2);
				}
				fighter2FirstRound.headStrikes++;
				fighter2FirstRound.points += 1;
			}
			else if (situation == "HeadPunchByElbow") {
				if (fighter2FirstRound.headStrikes > 2) {
					wincourse2 = headPunchByElbow(wincourse2, fighter2FirstRound);
					wincourse1 = courseCount(wincourse2);
				}
				fighter2FirstRound.headStrikes++;
				fighter2FirstRound.points += 2;
			}
			else if (situation == "HeadKickByKnee") {
				if (fighter2FirstRound.headStrikes > 2) {
					wincourse2 = headKickByKnee(wincourse2, fighter2FirstRound);
					wincourse1 = courseCount(wincourse2);
				}
				fighter2FirstRound.headStrikes++;
				fighter2FirstRound.points += 3;
			}
			else if (situation == "BodyPunch") {
				if (fighter2FirstRound.bodyStrikes > 2) {
					wincourse2 = bodyPunch(wincourse2, fighter2FirstRound);
					wincourse1 = courseCount(wincourse2);
				}
				fighter2FirstRound.bodyStrikes++;
				fighter2FirstRound.points += 1;
			}
			else if (situation == "BodyKickByKnee") {
				if (fighter2FirstRound.bodyStrikes > 2) {
					wincourse2 = bodyKickByKnee(wincourse2, fighter2FirstRound);
					wincourse1 = courseCount(wincourse2);
				}
				fighter2FirstRound.bodyStrikes++;
				fighter2FirstRound.points += 2;
			}
			else {
				cout << "Wrong action describe. Try again.\n";
			}
		}
		///////////////////////////////////////////////////////
		else if (where == "Ground") {

			if (situation == "HeadPunchByHand") {
				if (fighter2FirstRound.headStrikes > 2) {
					wincourse2 = headPunchByHand(wincourse2, fighter2FirstRound);
					wincourse1 = courseCount(wincourse2);
				}
				fighter2FirstRound.headStrikes++;
				fighter2FirstRound.points += 1;
			}
			else if (situation == "HeadPunchByElbow") {
				if (fighter2FirstRound.headStrikes > 2) {
					wincourse2 = headPunchByElbow(wincourse2, fighter2FirstRound);
					wincourse1 = courseCount(wincourse2);
				}
				fighter2FirstRound.headStrikes++;
				fighter2FirstRound.points += 3;
			}
			else if (situation == "BodyPunch") {
				if (fighter2FirstRound.headStrikes > 2) {
					wincourse2 = bodyPunch(wincourse2, fighter2FirstRound);
					wincourse1 = courseCount(wincourse2);
				}
				fighter2FirstRound.bodyStrikes++;
				fighter2FirstRound.points += 1;
			}
			else if (situation == "BodyKickByKnee") {
				if (fighter2FirstRound.headStrikes > 2) {
					wincourse2 = bodyKickByKnee(wincourse2, fighter2FirstRound);
					wincourse1 = courseCount(wincourse2);
				}
				fighter2FirstRound.bodyStrikes++;
				fighter2FirstRound.points += 2;
			}
			else if (situation == "Guard") {
				wincourse2 = guard(wincourse2, fighter2, fighter2FirstRound.position);
				wincourse1 = courseCount(wincourse2);
				fighter2FirstRound.position = 1;
				fighter2FirstRound.powerIncreaser = powerSetter(fighter2, fighter2FirstRound.position);
			}
			else if (situation == "Halfguard") {
				wincourse2 = halfGuard(wincourse2, fighter2, fighter2FirstRound.position);
				wincourse1 = courseCount(wincourse2);
				fighter2FirstRound.position = 2;
				fighter2FirstRound.powerIncreaser = powerSetter(fighter2, fighter2FirstRound.position);
			}
			else if (situation == "Side") {
				wincourse2 = side(wincourse2, fighter2, fighter2FirstRound.position);
				wincourse1 = courseCount(wincourse2);
				fighter2FirstRound.position = 3;
				fighter2FirstRound.powerIncreaser = powerSetter(fighter2, fighter2FirstRound.position);
			}
			else if (situation == "Mount") {
				wincourse2 = mount(wincourse2, fighter2, fighter2FirstRound.position);
				wincourse1 = courseCount(wincourse2);
				fighter2FirstRound.position = 4;
				fighter2FirstRound.powerIncreaser = powerSetter(fighter2, fighter2FirstRound.position);
			}
			else if (situation == "Back") {
				wincourse2 = back(wincourse2, fighter2, fighter2FirstRound.position);
				wincourse1 = courseCount(wincourse2);
				fighter2FirstRound.position = 5;
				fighter2FirstRound.powerIncreaser = powerSetter(fighter2, fighter2FirstRound.position);
			}
			else if (situation == "NorthSouth") {
				wincourse2 = northSouth(wincourse2, fighter2, fighter2FirstRound.position);
				wincourse1 = courseCount(wincourse2);
				fighter2FirstRound.position = 6;
				fighter2FirstRound.powerIncreaser = powerSetter(fighter2, fighter2FirstRound.position);
			}
			else {
				cout << "Wrong action describe. Try again.\n";
			}
		}
		///////////////////////////////////////////////////////
		else if (where == "GetUp") {
			fighter2FirstRound.position = 0;
			wincourse2 = getUp(wincourse2, fighter2, fighter2FirstRound.position);
			wincourse1 = courseCount(wincourse2);
			KO_TKOcourse = KO_TKO_getUp(KO_TKOcourse, fighter2, fighter2FirstRound.position, minute);
			NoKO_TKOcourse = courseCount(KO_TKOcourse);
			fighter2FirstRound.powerIncreaser = 1;
		}
		///////////////////////////////////////////////////////
		else if (where == "GroundControl") {
			cout << "How long? (in sec)?\n";
			cin >> timeGround;
			fighter2FirstRound.control += timeGround;
			if (timeGround > 100 && fighter2FirstRound.control < 100) {
				fighter2FirstRound.controlPhase = fighter2FirstRound.controlPhase + 1;
				wincourse2 = 1 + (wincourse2 - 1)*0.9;
				wincourse1 = courseCount(wincourse2);
			}
			if (timeGround > 200) {
				fighter2FirstRound.controlPhase = fighter2FirstRound.controlPhase + 2;
				wincourse2 = 1 + (wincourse2 - 1)*0.81;
				wincourse1 = courseCount(wincourse2);
			}
			timeGround = 0;

			if (fighter2FirstRound.control < 100) {
				if (fighter2FirstRound.controlPhase == 1) {
					wincourse2 = 1 + (wincourse2 - 1)*0.9;
					wincourse1 = courseCount(wincourse2);
					fighter2FirstRound.controlPhase = 2;
					fighter2FirstRound.points += 5;
				}
			}
			else if (fighter2FirstRound.control > 100 && fighter2FirstRound.control < 200) {
				if (fighter2FirstRound.controlPhase == 2) {
					wincourse2 = 1 + (wincourse2 - 1)*0.9;
					wincourse1 = courseCount(wincourse2);
					fighter2FirstRound.controlPhase = 3;
					fighter2FirstRound.points += 15;
				}
			}
			else if (fighter2FirstRound.control > 200) {
				if (fighter2FirstRound.controlPhase == 3) {
					wincourse2 = 1 + (wincourse2 - 1)*0.9;
					wincourse1 = courseCount(wincourse2);
					fighter2FirstRound.controlPhase = 4;
					fighter2FirstRound.points += 30;
				}
			}
		}
		///////////////////////////////////////////////////////
		else if (where == "ClinchControl") {
		cout << "How long? (in sec)?\n";
		cin >> timeClinch;
		fighter2FirstRound.controlClinch += timeClinch;
		if (timeClinch > 100 && fighter2FirstRound.controlClinch < 100) {
			fighter2FirstRound.controlPhaseClinch = fighter2FirstRound.controlPhaseClinch + 1;
			wincourse2 = 1 + (wincourse2 - 1)*0.95;
			wincourse1 = courseCount(wincourse2);
		}
		if (timeClinch > 200) {
			fighter2FirstRound.controlPhaseClinch = fighter2FirstRound.controlPhaseClinch + 2;
			wincourse2 = 1 + (wincourse2 - 1)*0.9025;
			wincourse1 = courseCount(wincourse2);
		}
		timeClinch = 0;

		if (fighter2FirstRound.controlClinch < 100) {
			if (fighter2FirstRound.controlPhaseClinch == 1) {
				wincourse2 = 1 + (wincourse2 - 1)*0.95;
				wincourse1 = courseCount(wincourse2);
				fighter2FirstRound.controlPhase = 2;
			}
		}
		else if (fighter2FirstRound.controlClinch > 100 && fighter2FirstRound.controlClinch < 200) {
			if (fighter2FirstRound.controlPhaseClinch == 2) {
				wincourse2 = 1 + (wincourse2 - 1)*0.95;
				wincourse1 = courseCount(wincourse2);
				fighter2FirstRound.controlPhaseClinch = 3;
			}
		}
		else if (fighter2FirstRound.controlClinch > 200) {
			if (fighter2FirstRound.controlPhaseClinch == 3) {
				wincourse2 = 1 + (wincourse2 - 1)*0.95;
				wincourse1 = courseCount(wincourse2);
				fighter2FirstRound.controlPhaseClinch = 4;
			}
		}
		}
		///////////////////////////////////////////////////////
		else if (where == "HeavyPunch") {
			cout << "How much did the punch affect opponent?\nin range 0-1 | 0 - not much | 1 - very much\n(1 means almost knockdown, but opponent is still standing)\n";
			heaviness = 0;
			cin >> heaviness;
			wincourse2 = heavyPunch(wincourse2, heaviness);
			wincourse1 = courseCount(wincourse2);
			KO_TKOcourse = KO_TKO_heavyPunch(KO_TKOcourse, heaviness, minute, round);
			NoKO_TKOcourse = courseCount(KO_TKOcourse);
			fighter2FirstRound.headStrikes++;
			fighter2FirstRound.points += 10;
		}
		///////////////////////////////////////////////////////
		else {
			cout << "Something went wrong. Try again.\n";
		}
		}// end of fighter2 actions
		
		///////////////////////////////////////////////////////

		else if (who == "RoundEnd") {
				round = 2;
		}

		///////////////////////////////////////////////////////

		else if (who == "Minute") {
		
			minute++;
			KO_TKO_minutePass(NoKO_TKOcourse, minute, round);
			KO_TKOcourse = courseCount(NoKO_TKOcourse);

		}

		///////////////////////////////////////////////////////

		else {
				cout << "Something went wrong. Try again.\n";
		}

		wincourse1 = courseCorrection(wincourse1);
		wincourse2 = courseCorrection(wincourse2);

		cout << "///////////////////////////////////////////////////////\n";
		cout << "///////////////////////////////////////////////////////\n";
		cout << fighter1.lastName << " " << wincourse1 << " - " << wincourse2 << " " << fighter2.lastName << "\n";
		cout << "///////////////////////////////////////////////////////\n";
		cout << "///////////////////////////////////////////////////////\n";

	} // end of round 1

	if (fighter1FirstRound.points > fighter2FirstRound.points + 5) {
		if (fighter1FirstRound.points > fighter2FirstRound.points + 40) {
			fighter1FirstRound.roundWinned += 2;
		}
		else fighter1FirstRound.roundWinned++;
	}
	if (fighter2FirstRound.points > fighter1FirstRound.points + 5) {
		fighter2FirstRound.roundWinned++;
	}

	if (fighter1FirstRound.roundWinned - fighter1FirstRound.minusPoints > fighter2FirstRound.roundWinned - fighter2FirstRound.minusPoints) {
		if (fighter1FirstRound.roundWinned - fighter1FirstRound.minusPoints > fighter2FirstRound.roundWinned - fighter2FirstRound.minusPoints + 1) {
			if (fighter1FirstRound.foul > 0) {
				wincourse1 = 1 + (wincourse1 - 1)*0.85;
				wincourse2 = courseCount(wincourse1);
			}
			else {
				wincourse1 = 1 + (wincourse1 - 1)*0.8;
				wincourse2 = courseCount(wincourse1);
			}
		}
		if (fighter1FirstRound.foul > 0) {
			wincourse1 = 1 + (wincourse1 - 1)*0.95;
			wincourse2 = courseCount(wincourse1);
		}
		else {
			wincourse1 = 1 + (wincourse1 - 1)*0.9;
			wincourse2 = courseCount(wincourse1);
		}
	}

	if (fighter2FirstRound.roundWinned - fighter2FirstRound.minusPoints > fighter1FirstRound.roundWinned - fighter1FirstRound.minusPoints) {
		if (fighter2FirstRound.roundWinned - fighter2FirstRound.minusPoints > fighter1FirstRound.roundWinned - fighter1FirstRound.minusPoints+1) {
			if (fighter2FirstRound.foul > 0) {
				wincourse2 = 1 + (wincourse2 - 1)*0.85;
				wincourse1 = courseCount(wincourse2);
			}
			else {
				wincourse2 = 1 + (wincourse2 - 1)*0.8;
				wincourse1 = courseCount(wincourse2);
			}
		}
		if (fighter2FirstRound.foul > 0) {
			wincourse2 = 1 + (wincourse2 - 1)*0.95;
			wincourse1 = courseCount(wincourse2);
		}
		else {
			wincourse2 = 1 + (wincourse2 - 1)*0.9;
			wincourse1 = courseCount(wincourse2);
		}
	}

	wincourse1 = courseCorrection(wincourse1);
	wincourse2 = courseCorrection(wincourse2);

	////////////////////////////////////////////////////////////////

	cout << "Rirst round stats\n" << fighter1.lastName << "\n";
	cout << fighter1FirstRound.headStrikes << " Head strikes\n" << fighter1FirstRound.bodyStrikes << " Body strikes\n" << fighter1FirstRound.legStrikes << " Leg strikes\n" << fighter1FirstRound.minusPoints << " Minus points\n";
	cout << fighter2.lastName << "\n";
	cout << fighter2FirstRound.headStrikes << " Head strikes\n" << fighter2FirstRound.bodyStrikes << " Body strikes\n" << fighter2FirstRound.legStrikes << " Leg strikes\n" << fighter2FirstRound.minusPoints << " Minus points\n\n";
	cout << "\n";

	////////////////////////////////////////////////////////////////
	
	fighterInRound fighter1SecondRound;
	fighterInRound fighter2SecondRound;

	minute = 0;

	cout << " Start of round two.\n";

	while (round == 2) {

		cout << "Who?\n";
		cin >> who;
		if (!(who == "RoundEnd")) {
			cout << "What?/Where?\n";
			cin >> where;
			if (!(where == "PointDown") && !(where == "GetUp") && !(where == "Injury") && !(where == "Foul") && !(where == "Knockdown") && !(where == "GroundControl") && !(where == "CourseSet") && !(where == "HeavyPunch")) {

				cout << "Situation?\n";
				cin >> situation;
			}
		}

		if ((who == fighter1.firstName) || who == (fighter1.lastName)) {

			///////////////////////////////////////////////////////
			if (where == "CourseSet") {
				wincourse1 = courseSet();
				wincourse2 = courseCount(wincourse1);
			}
			///////////////////////////////////////////////////////
			if (where == "Knockdown") {
				wincourse1 = knockDown(wincourse1, fighter1);
				wincourse2 = courseCount(wincourse1);
				KO_TKOcourse = KO_TKO_knockDown(KO_TKOcourse, minute, round);
				NoKO_TKOcourse = courseCount(KO_TKOcourse);
				fighter1SecondRound.knockdown++;
				fighter1SecondRound.points += 12;
			}
			///////////////////////////////////////////////////////
			else if (where == "Injury") {
				cout << "What injury?\n";
				cin >> situation;
				if (situation == "CutCloseToEyes") {
					cout << "How important cut?\nin range 0-1 | 0 - not important | 1 - most important (focus on probability of doctor stoppage or if blood goes into fighters eyes)\n";
					cin >> cutImportance;
					wincourse1 = cutCloseToEyes(wincourse1, cutImportance);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_cutCloseToEyes(KO_TKOcourse, cutImportance, minute, round);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
				}
				else if (situation == "BrokenNose") {
					wincourse1 = brokenNose(wincourse1);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_brokenNose(KO_TKOcourse, minute, round);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
				}
				else if (situation == "HandInjury") {
					cout << "How important injury?\nin range 0-1 | 0 - not important | 1 - most important\n";
					cin >> injuryImportance;
					wincourse1 = handInjury(wincourse1, injuryImportance);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_handInjury(KO_TKOcourse, injuryImportance, minute, round);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
				}
				else if (situation == "LegInjury") {
					cout << "How important injury?\nin range 0-1 | 0 - not important | 1 - most important\n";
					cin >> injuryImportance;
					wincourse1 = legInjury(wincourse1, injuryImportance);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_legInjury(KO_TKOcourse, injuryImportance, minute, round);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
				}
				else {
					cout << "Wrong injury describe. Try again.\n";
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "PointDown") {
				wincourse1 = pointDown(wincourse1, fighter1);
				wincourse2 = courseCount(wincourse1);
				fighter1SecondRound.minusPoints++;
			}
			///////////////////////////////////////////////////////
			else if (where == "Foul") {
				wincourse1 = foul(wincourse1, fighter1);
				wincourse2 = courseCount(wincourse1);
				fighter1SecondRound.foul++;
			}
			///////////////////////////////////////////////////////
			else if (where == "Standing") {

				if (situation == "HeadPunchByHand") {
					if (fighter1SecondRound.headStrikes > 2) {
						wincourse1 = headPunchByHand(wincourse1, fighter1SecondRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1SecondRound.headStrikes++;
					fighter1SecondRound.points += 1;
				}
				else if (situation == "HeadPunchByElbow") {
					if (fighter1SecondRound.headStrikes > 2) {
						wincourse1 = headPunchByElbow(wincourse1, fighter1SecondRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1SecondRound.headStrikes++;
					fighter1SecondRound.points += 2;
				}
				else if (situation == "HeadKick") {
					if (fighter1SecondRound.headStrikes > 2) {
						wincourse1 = headKick(wincourse1, fighter1SecondRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1SecondRound.headStrikes++;
					fighter1SecondRound.points += 3;
				}
				else if (situation == "HeadKickByKnee") {
					if (fighter1SecondRound.headStrikes > 2) {
						wincourse1 = headKickByKnee(wincourse1, fighter1SecondRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1SecondRound.headStrikes++;
					fighter1SecondRound.points += 4;
				}
				else if (situation == "BodyPunch") {
					if (fighter1SecondRound.bodyStrikes > 2) {
						wincourse1 = bodyPunch(wincourse1, fighter1SecondRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1SecondRound.bodyStrikes++;
					fighter1SecondRound.points += 1;
				}
				else if (situation == "BodyKick") {
					if (fighter1SecondRound.bodyStrikes > 2) {
						wincourse1 = bodyKick(wincourse1, fighter1SecondRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1SecondRound.bodyStrikes++;
					fighter1SecondRound.points += 2;
				}
				else if (situation == "BodyKickByKnee") {
					if (fighter1SecondRound.bodyStrikes > 2) {
						wincourse1 = bodyKickByKnee(wincourse1, fighter1SecondRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1SecondRound.bodyStrikes++;
					fighter1SecondRound.points += 2;
				}
				else if (situation == "LowKick") {
					if (fighter1SecondRound.legStrikes > 2) {
						wincourse1 = lowKick(wincourse1, fighter1SecondRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1SecondRound.legStrikes++;
					fighter1SecondRound.points += 1;
				}
				else if (situation == "CalfKick") {
					if (fighter1SecondRound.legStrikes > 2) {
						wincourse1 = calfKick(wincourse1, fighter1SecondRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1SecondRound.legStrikes++;
					fighter1SecondRound.points += 1;
				}
				else {
					cout << "Wrong action describe. Try again.\n";
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "Clinch") {

				if (situation == "HeadPunchByHand") {
					if (fighter1SecondRound.headStrikes > 2) {
						wincourse1 = headPunchByHand(wincourse1, fighter1SecondRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1SecondRound.headStrikes++;
					fighter1SecondRound.points += 1;
				}
				else if (situation == "HeadPunchByElbow") {
					if (fighter1SecondRound.headStrikes > 2) {
						wincourse1 = headPunchByElbow(wincourse1, fighter1SecondRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1SecondRound.headStrikes++;
					fighter1SecondRound.points += 2;
				}
				else if (situation == "HeadKickByKnee") {
					if (fighter1SecondRound.headStrikes > 2) {
						wincourse1 = headKickByKnee(wincourse1, fighter1SecondRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1SecondRound.headStrikes++;
					fighter1SecondRound.points += 3;
				}
				else if (situation == "BodyPunch") {
					if (fighter1SecondRound.bodyStrikes > 2) {
						wincourse1 = bodyPunch(wincourse1, fighter1SecondRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1SecondRound.bodyStrikes++;
					fighter1SecondRound.points += 1;
				}
				else if (situation == "BodyKickByKnee") {
					if (fighter1SecondRound.bodyStrikes > 2) {
						wincourse1 = bodyKickByKnee(wincourse1, fighter1SecondRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1SecondRound.bodyStrikes++;
					fighter1SecondRound.points += 2;
				}
				else {
					cout << "Wrong action describe. Try again.\n";
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "Ground") {

				if (situation == "HeadPunchByHand") {
					if (fighter1SecondRound.headStrikes > 2) {
						wincourse1 = headPunchByHand(wincourse1, fighter1SecondRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1SecondRound.headStrikes++;
					fighter1SecondRound.points += 1;
				}
				else if (situation == "HeadPunchByElbow") {
					if (fighter1SecondRound.headStrikes > 2) {
						wincourse1 = headPunchByElbow(wincourse1, fighter1SecondRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1SecondRound.headStrikes++;
					fighter1SecondRound.points += 3;
				}
				else if (situation == "BodyPunch") {
					if (fighter1SecondRound.headStrikes > 2) {
						wincourse1 = bodyPunch(wincourse1, fighter1SecondRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1SecondRound.bodyStrikes++;
					fighter1SecondRound.points += 1;
				}
				else if (situation == "BodyKickByKnee") {
					if (fighter1SecondRound.headStrikes > 2) {
						wincourse1 = bodyKickByKnee(wincourse1, fighter1SecondRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1SecondRound.bodyStrikes++;
					fighter1SecondRound.points += 2;
				}
				else if (situation == "Guard") {
					wincourse1 = guard(wincourse1, fighter1, fighter1SecondRound.position);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_guard(KO_TKOcourse, fighter1, fighter1SecondRound.position, minute);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
					fighter1SecondRound.position = 1;
					fighter1SecondRound.powerIncreaser = powerSetter(fighter1, fighter1SecondRound.position);
				}
				else if (situation == "Halfguard") {
					wincourse1 = halfGuard(wincourse1, fighter1, fighter1SecondRound.position);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_halfGuard(KO_TKOcourse, fighter1, fighter1SecondRound.position, minute);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
					fighter1SecondRound.position = 2;
					fighter1SecondRound.powerIncreaser = powerSetter(fighter1, fighter1SecondRound.position);
				}
				else if (situation == "Side") {
					wincourse1 = side(wincourse1, fighter1, fighter1SecondRound.position);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_side(KO_TKOcourse, fighter1, fighter1SecondRound.position, minute);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
					fighter1SecondRound.position = 3;
					fighter1SecondRound.powerIncreaser = powerSetter(fighter1, fighter1SecondRound.position);
				}
				else if (situation == "Mount") {
					wincourse1 = mount(wincourse1, fighter1, fighter1SecondRound.position);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_mount(KO_TKOcourse, fighter1, fighter1SecondRound.position, minute);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
					fighter1SecondRound.position = 4;
					fighter1SecondRound.powerIncreaser = powerSetter(fighter1, fighter1SecondRound.position);
				}
				else if (situation == "Back") {
					wincourse1 = back(wincourse1, fighter1, fighter1SecondRound.position);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_back(KO_TKOcourse, fighter1, fighter1SecondRound.position, minute);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
					fighter1SecondRound.position = 5;
					fighter1SecondRound.powerIncreaser = powerSetter(fighter1, fighter1SecondRound.position);
				}
				else if (situation == "NorthSouth") {
					wincourse1 = northSouth(wincourse1, fighter1, fighter1SecondRound.position);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_northSouth(KO_TKOcourse, fighter1, fighter1SecondRound.position, minute);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
					fighter1SecondRound.position = 6;
					fighter1SecondRound.powerIncreaser = powerSetter(fighter1, fighter1SecondRound.position);
				}
				else {
					cout << "Wrong action describe. Try again.\n";
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "GetUp") {
				fighter1SecondRound.position = 0;
				wincourse1 = getUp(wincourse1, fighter1, fighter1SecondRound.position);
				wincourse2 = courseCount(wincourse1);
				KO_TKOcourse = KO_TKO_getUp(KO_TKOcourse, fighter1, fighter1SecondRound.position, minute);
				NoKO_TKOcourse = courseCount(KO_TKOcourse);
				fighter1SecondRound.powerIncreaser = 1;
			}
			///////////////////////////////////////////////////////
			else if (where == "GroundControl") {
				cout << "How long? (in sec)?\n";
				cin >> timeGround;
				fighter1SecondRound.control += timeGround;
				if (timeGround > 100 && fighter1SecondRound.control < 100) {
					fighter1SecondRound.controlPhase = fighter1SecondRound.controlPhase + 1;
					wincourse1 = 1 + (wincourse1 - 1)*0.9;
					wincourse2 = courseCount(wincourse1);
				}
				if (timeGround > 200) {
					fighter1SecondRound.controlPhase = fighter1SecondRound.controlPhase + 2;
					wincourse1 = 1 + (wincourse1 - 1)*0.81;
					wincourse2 = courseCount(wincourse1);
				}
				timeGround = 0;

				if (fighter1SecondRound.control < 100) {
					if (fighter1SecondRound.controlPhase == 1) {
						wincourse1 = 1 + (wincourse1 - 1)*0.9;
						wincourse2 = courseCount(wincourse1);
						fighter1SecondRound.controlPhase = 2;
						fighter1SecondRound.points += 5;
					}
				}
				else if (fighter1SecondRound.control > 100 && fighter1SecondRound.control < 200) {
					if (fighter1SecondRound.controlPhase == 2) {
						wincourse1 = 1 + (wincourse1 - 1)*0.9;
						wincourse2 = courseCount(wincourse1);
						fighter1SecondRound.controlPhase = 3;
						fighter1SecondRound.points += 15;
					}
				}
				else if (fighter1SecondRound.control > 200) {
					if (fighter1SecondRound.controlPhase == 3) {
						wincourse1 = 1 + (wincourse1 - 1)*0.9;
						wincourse2 = courseCount(wincourse1);
						fighter1SecondRound.controlPhase = 4;
						fighter1SecondRound.points += 30;
					}
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "ClinchControl") {
				cout << "How long? (in sec)?\n";
				cin >> timeClinch;
				fighter1SecondRound.controlClinch += timeClinch;
				if (timeClinch > 100 && fighter1SecondRound.controlClinch < 100) {
					fighter1SecondRound.controlPhaseClinch = fighter1SecondRound.controlPhaseClinch + 1;
					wincourse1 = 1 + (wincourse1 - 1)*0.95;
					wincourse2 = courseCount(wincourse1);
				}
				if (timeClinch > 200) {
					fighter1SecondRound.controlPhaseClinch = fighter1SecondRound.controlPhaseClinch + 2;
					wincourse1 = 1 + (wincourse1 - 1)*0.9025;
					wincourse2 = courseCount(wincourse1);
				}
				timeClinch = 0;

				if (fighter1SecondRound.controlClinch < 100) {
					if (fighter1SecondRound.controlPhaseClinch == 1) {
						wincourse1 = 1 + (wincourse1 - 1)*0.95;
						wincourse2 = courseCount(wincourse1);
						fighter1SecondRound.controlPhase = 2;
					}
				}
				else if (fighter1SecondRound.controlClinch > 100 && fighter1SecondRound.controlClinch < 200) {
					if (fighter1SecondRound.controlPhaseClinch == 2) {
						wincourse1 = 1 + (wincourse1 - 1)*0.95;
						wincourse2 = courseCount(wincourse1);
						fighter1SecondRound.controlPhaseClinch = 3;
					}
				}
				else if (fighter1SecondRound.controlClinch > 200) {
					if (fighter1SecondRound.controlPhaseClinch == 3) {
						wincourse1 = 1 + (wincourse1 - 1)*0.95;
						wincourse2 = courseCount(wincourse1);
						fighter1SecondRound.controlPhaseClinch = 4;
					}
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "HeavyPunch") {
				cout << "How much did the punch affect opponent?\nin range 0-1 | 0 - not much | 1 - very much\n(1 means almost knockdown, but opponent is still standing)\n";
				heaviness = 0;
				cin >> heaviness;
				wincourse1 = heavyPunch(wincourse1, heaviness);
				wincourse2 = courseCount(wincourse1);
				KO_TKOcourse = KO_TKO_heavyPunch(KO_TKOcourse, heaviness, minute, round);
				NoKO_TKOcourse = courseCount(KO_TKOcourse);
				fighter1SecondRound.headStrikes++;
				fighter1FirstRound.points += 10;
			}
			///////////////////////////////////////////////////////
			else {
				cout << "Something went wrong. Try again.\n";
			}
		}// end of fighter1 actions

		///////////////////////////////////////////////////////

		else if ((who == fighter2.firstName) || who == (fighter2.lastName)) {

			///////////////////////////////////////////////////////
			if (where == "CourseSet") {
				wincourse2 = courseSet();
				wincourse1 = courseCount(wincourse2);
			}
			///////////////////////////////////////////////////////
			if (where == "Knockdown") {
				wincourse2 = knockDown(wincourse2, fighter2);
				wincourse1 = courseCount(wincourse2);
				KO_TKOcourse = KO_TKO_knockDown(KO_TKOcourse, minute, round);
				fighter2SecondRound.knockdown++;
				fighter2SecondRound.points += 12;
			}
			///////////////////////////////////////////////////////
			else if (where == "Injury") {
				cout << "What injury?\n";
				cin >> situation;
				if (situation == "CutCloseToEyes") {
					cout << "How important cut?\nin range 0-1 | 0 - not important | 1 - most important (focus on probability of doctor stoppage or if blood goes into fighters eyes)\n";
					cin >> cutImportance;
					wincourse2 = cutCloseToEyes(wincourse2, cutImportance);
					wincourse1 = courseCount(wincourse2);
					KO_TKOcourse = KO_TKO_cutCloseToEyes(KO_TKOcourse, cutImportance, minute, round);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
				}
				else if (situation == "BrokenNose") {
					wincourse2 = brokenNose(wincourse2);
					wincourse1 = courseCount(wincourse2);
					KO_TKOcourse = KO_TKO_brokenNose(KO_TKOcourse, minute, round);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
				}
				else if (situation == "HandInjury") {
					cout << "How important injury?\nin range 0-1 | 0 - not important | 1 - most important\n";
					cin >> injuryImportance;
					wincourse2 = handInjury(wincourse2, injuryImportance);
					wincourse1 = courseCount(wincourse2);
					KO_TKOcourse = KO_TKO_handInjury(KO_TKOcourse, injuryImportance, minute, round);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
				}
				else if (situation == "LegInjury") {
					cout << "How important injury?\nin range 0-1 | 0 - not important | 1 - most important\n";
					cin >> injuryImportance;
					wincourse2 = legInjury(wincourse2, injuryImportance);
					wincourse1 = courseCount(wincourse2);
					KO_TKOcourse = KO_TKO_legInjury(KO_TKOcourse, injuryImportance, minute, round);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
				}
				else {
					cout << "Wrong injury describe. Try again.\n";
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "PointDown") {
				wincourse2 = pointDown(wincourse2, fighter2);
				wincourse1 = courseCount(wincourse2);
				fighter2SecondRound.minusPoints++;
			}
			///////////////////////////////////////////////////////
			else if (where == "Foul") {
				wincourse2 = foul(wincourse2, fighter2);
				wincourse1 = courseCount(wincourse2);
				fighter2SecondRound.foul++;
			}
			///////////////////////////////////////////////////////
			else if (where == "Standing") {

				if (situation == "HeadPunchByHand") {
					if (fighter2SecondRound.headStrikes > 2) {
						wincourse2 = headPunchByHand(wincourse2, fighter2SecondRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2SecondRound.headStrikes++;
					fighter2SecondRound.points += 1;
				}
				else if (situation == "HeadPunchByElbow") {
					if (fighter2SecondRound.headStrikes > 2) {
						wincourse2 = headPunchByElbow(wincourse2, fighter2SecondRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2SecondRound.headStrikes++;
					fighter2SecondRound.points += 2;
				}
				else if (situation == "HeadKick") {
					if (fighter2SecondRound.headStrikes > 2) {
						wincourse2 = headKick(wincourse2, fighter2SecondRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2SecondRound.headStrikes++;
					fighter2SecondRound.points += 3;
				}
				else if (situation == "HeadKickByKnee") {
					if (fighter2SecondRound.headStrikes > 2) {
						wincourse2 = headKickByKnee(wincourse2, fighter2SecondRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2SecondRound.headStrikes++;
					fighter2SecondRound.points += 4;
				}
				else if (situation == "BodyPunch") {
					if (fighter2SecondRound.bodyStrikes > 2) {
						wincourse2 = bodyPunch(wincourse2, fighter2SecondRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2SecondRound.bodyStrikes++;
					fighter2SecondRound.points += 1;
				}
				else if (situation == "BodyKick") {
					if (fighter2SecondRound.bodyStrikes > 2) {
						wincourse2 = bodyKick(wincourse2, fighter2SecondRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2SecondRound.bodyStrikes++;
					fighter2SecondRound.points += 2;
				}
				else if (situation == "BodyKickByKnee") {
					if (fighter2SecondRound.bodyStrikes > 2) {
						wincourse2 = bodyKickByKnee(wincourse2, fighter2SecondRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2SecondRound.bodyStrikes++;
					fighter2SecondRound.points += 2;
				}
				else if (situation == "LowKick") {
					if (fighter2SecondRound.legStrikes > 2) {
						wincourse2 = lowKick(wincourse2, fighter2SecondRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2SecondRound.legStrikes++;
					fighter2SecondRound.points += 1;
				}
				else if (situation == "CalfKick") {
					if (fighter2SecondRound.legStrikes > 2) {
						wincourse2 = calfKick(wincourse2, fighter2SecondRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2SecondRound.legStrikes++;
					fighter2SecondRound.points += 1;
				}
				else {
					cout << "Wrong action describe. Try again.\n";
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "Clinch") {

				if (situation == "HeadPunchByHand") {
					if (fighter2SecondRound.headStrikes > 2) {
						wincourse2 = headPunchByHand(wincourse2, fighter2SecondRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2SecondRound.headStrikes++;
					fighter2SecondRound.points += 1;
				}
				else if (situation == "HeadPunchByElbow") {
					if (fighter2SecondRound.headStrikes > 2) {
						wincourse2 = headPunchByElbow(wincourse2, fighter2SecondRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2SecondRound.headStrikes++;
					fighter2SecondRound.points += 2;
				}
				else if (situation == "HeadKickByKnee") {
					if (fighter2SecondRound.headStrikes > 2) {
						wincourse2 = headKickByKnee(wincourse2, fighter2SecondRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2SecondRound.headStrikes++;
					fighter2SecondRound.points += 3;
				}
				else if (situation == "BodyPunch") {
					if (fighter2SecondRound.bodyStrikes > 2) {
						wincourse2 = bodyPunch(wincourse2, fighter2SecondRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2SecondRound.bodyStrikes++;
					fighter2SecondRound.points += 1;
				}
				else if (situation == "BodyKickByKnee") {
					if (fighter2SecondRound.bodyStrikes > 2) {
						wincourse2 = bodyKickByKnee(wincourse2, fighter2SecondRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2SecondRound.bodyStrikes++;
					fighter2SecondRound.points += 2;
				}
				else {
					cout << "Wrong action describe. Try again.\n";
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "Ground") {

				if (situation == "HeadPunchByHand") {
					if (fighter2SecondRound.headStrikes > 2) {
						wincourse2 = headPunchByHand(wincourse2, fighter2SecondRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2SecondRound.headStrikes++;
					fighter2SecondRound.points += 1;
				}
				else if (situation == "HeadPunchByElbow") {
					if (fighter2SecondRound.headStrikes > 2) {
						wincourse2 = headPunchByElbow(wincourse2, fighter2SecondRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2SecondRound.headStrikes++;
					fighter2SecondRound.points += 3;
				}
				else if (situation == "BodyPunch") {
					if (fighter2SecondRound.headStrikes > 2) {
						wincourse2 = bodyPunch(wincourse2, fighter2SecondRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2SecondRound.bodyStrikes++;
					fighter2SecondRound.points += 1;
				}
				else if (situation == "BodyKickByKnee") {
					if (fighter2SecondRound.headStrikes > 2) {
						wincourse2 = bodyKickByKnee(wincourse2, fighter2SecondRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2SecondRound.bodyStrikes++;
					fighter2SecondRound.points += 2;
				}
				else if (situation == "Guard") {
					wincourse2 = guard(wincourse2, fighter2, fighter2SecondRound.position);
					wincourse1 = courseCount(wincourse2);
					fighter2SecondRound.position = 1;
					fighter2SecondRound.powerIncreaser = powerSetter(fighter2, fighter2SecondRound.position);
				}
				else if (situation == "Halfguard") {
					wincourse2 = halfGuard(wincourse2, fighter2, fighter2SecondRound.position);
					wincourse1 = courseCount(wincourse2);
					fighter2SecondRound.position = 2;
					fighter2SecondRound.powerIncreaser = powerSetter(fighter2, fighter2SecondRound.position);
				}
				else if (situation == "Side") {
					wincourse2 = side(wincourse2, fighter2, fighter2SecondRound.position);
					wincourse1 = courseCount(wincourse2);
					fighter2SecondRound.position = 3;
					fighter2SecondRound.powerIncreaser = powerSetter(fighter2, fighter2SecondRound.position);
				}
				else if (situation == "Mount") {
					wincourse2 = mount(wincourse2, fighter2, fighter2SecondRound.position);
					wincourse1 = courseCount(wincourse2);
					fighter2SecondRound.position = 4;
					fighter2SecondRound.powerIncreaser = powerSetter(fighter2, fighter2SecondRound.position);
				}
				else if (situation == "Back") {
					wincourse2 = back(wincourse2, fighter2, fighter2SecondRound.position);
					wincourse1 = courseCount(wincourse2);
					fighter2SecondRound.position = 5;
					fighter2SecondRound.powerIncreaser = powerSetter(fighter2, fighter2SecondRound.position);
				}
				else if (situation == "NorthSouth") {
					wincourse2 = northSouth(wincourse2, fighter2, fighter2SecondRound.position);
					wincourse1 = courseCount(wincourse2);
					fighter2SecondRound.position = 6;
					fighter2SecondRound.powerIncreaser = powerSetter(fighter2, fighter2SecondRound.position);
				}
				else {
					cout << "Wrong action describe. Try again.\n";
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "GetUp") {
				fighter2SecondRound.position = 0;
				wincourse2 = getUp(wincourse2, fighter2, fighter2SecondRound.position);
				wincourse1 = courseCount(wincourse2);
				KO_TKOcourse = KO_TKO_getUp(KO_TKOcourse, fighter2, fighter2SecondRound.position, minute);
				NoKO_TKOcourse = courseCount(KO_TKOcourse);
				fighter2SecondRound.powerIncreaser = 1;
			}
			///////////////////////////////////////////////////////
			else if (where == "GroundControl") {
				cout << "How long? (in sec)?\n";
				cin >> timeGround;
				fighter2SecondRound.control += timeGround;
				if (timeGround > 100 && fighter2SecondRound.control < 100) {
					fighter2SecondRound.controlPhase = fighter2SecondRound.controlPhase + 1;
					wincourse2 = 1 + (wincourse2 - 1)*0.9;
					wincourse1 = courseCount(wincourse2);
				}
				if (timeGround > 200) {
					fighter2SecondRound.controlPhase = fighter2SecondRound.controlPhase + 2;
					wincourse2 = 1 + (wincourse2 - 1)*0.81;
					wincourse1 = courseCount(wincourse2);
				}
				timeGround = 0;

				if (fighter2SecondRound.control < 100) {
					if (fighter2SecondRound.controlPhase == 1) {
						wincourse2 = 1 + (wincourse2 - 1)*0.9;
						wincourse1 = courseCount(wincourse2);
						fighter2SecondRound.controlPhase = 2;
						fighter2SecondRound.points += 5;
					}
				}
				else if (fighter2SecondRound.control > 100 && fighter2SecondRound.control < 200) {
					if (fighter2SecondRound.controlPhase == 2) {
						wincourse2 = 1 + (wincourse2 - 1)*0.9;
						wincourse1 = courseCount(wincourse2);
						fighter2SecondRound.controlPhase = 3;
						fighter2SecondRound.points += 15;
					}
				}
				else if (fighter2SecondRound.control > 200) {
					if (fighter2SecondRound.controlPhase == 3) {
						wincourse2 = 1 + (wincourse2 - 1)*0.9;
						wincourse1 = courseCount(wincourse2);
						fighter2SecondRound.controlPhase = 4;
						fighter2SecondRound.points += 30;
					}
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "ClinchControl") {
				cout << "How long? (in sec)?\n";
				cin >> timeClinch;
				fighter2SecondRound.controlClinch += timeClinch;
				if (timeClinch > 100 && fighter2SecondRound.controlClinch < 100) {
					fighter2SecondRound.controlPhaseClinch = fighter2SecondRound.controlPhaseClinch + 1;
					wincourse2 = 1 + (wincourse2 - 1)*0.95;
					wincourse1 = courseCount(wincourse2);
				}
				if (timeClinch > 200) {
					fighter2SecondRound.controlPhaseClinch = fighter2SecondRound.controlPhaseClinch + 2;
					wincourse2 = 1 + (wincourse2 - 1)*0.9025;
					wincourse1 = courseCount(wincourse2);
				}
				timeClinch = 0;

				if (fighter2SecondRound.controlClinch < 100) {
					if (fighter2SecondRound.controlPhaseClinch == 1) {
						wincourse2 = 1 + (wincourse2 - 1)*0.95;
						wincourse1 = courseCount(wincourse2);
						fighter2SecondRound.controlPhase = 2;
					}
				}
				else if (fighter2SecondRound.controlClinch > 100 && fighter2SecondRound.controlClinch < 200) {
					if (fighter2SecondRound.controlPhaseClinch == 2) {
						wincourse2 = 1 + (wincourse2 - 1)*0.95;
						wincourse1 = courseCount(wincourse2);
						fighter2SecondRound.controlPhaseClinch = 3;
					}
				}
				else if (fighter2SecondRound.controlClinch > 200) {
					if (fighter2SecondRound.controlPhaseClinch == 3) {
						wincourse2 = 1 + (wincourse2 - 1)*0.95;
						wincourse1 = courseCount(wincourse2);
						fighter2SecondRound.controlPhaseClinch = 4;
					}
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "HeavyPunch") {
				cout << "How much did the punch affect opponent?\nin range 0-1 | 0 - not much | 1 - very much\n(1 means almost knockdown, but opponent is still standing)\n";
				heaviness = 0;
				cin >> heaviness;
				wincourse2 = heavyPunch(wincourse2, heaviness);
				wincourse1 = courseCount(wincourse2);
				KO_TKOcourse = KO_TKO_heavyPunch(KO_TKOcourse, heaviness, minute, round);
				NoKO_TKOcourse = courseCount(KO_TKOcourse);
				fighter2SecondRound.headStrikes++;
				fighter2SecondRound.points += 10;
			}
			///////////////////////////////////////////////////////
			else {
				cout << "Something went wrong. Try again.\n";
			}
		}// end of fighter2 actions

		///////////////////////////////////////////////////////

		else if (who == "RoundEnd") {
			round = 3;
		}

		///////////////////////////////////////////////////////

		else {
			cout << "Something went wrong. Try again.\n";
		}

		wincourse1 = courseCorrection(wincourse1);
		wincourse2 = courseCorrection(wincourse2);

		cout << "///////////////////////////////////////////////////////\n";
		cout << "///////////////////////////////////////////////////////\n";
		cout << fighter1.lastName << " " << wincourse1 << " - " << wincourse2 << " " << fighter2.lastName << "\n";
		cout << "///////////////////////////////////////////////////////\n";
		cout << "///////////////////////////////////////////////////////\n";

	} // end of round 2

	if (fighter1SecondRound.points > fighter2SecondRound.points + 5) {
		if (fighter1SecondRound.points > fighter2SecondRound.points + 40) {
			fighter1SecondRound.roundWinned += 2;
		}
		else fighter1SecondRound.roundWinned++;
	}
	if (fighter2SecondRound.points > fighter1SecondRound.points + 5) {
		if (fighter2SecondRound.points > fighter1SecondRound.points + 40) {
			fighter2SecondRound.roundWinned += 2;
		}
		else fighter2SecondRound.roundWinned++;
	}

	if ((fighter1FirstRound.roundWinned + fighter1SecondRound.roundWinned) - (fighter1FirstRound.minusPoints + fighter1SecondRound.minusPoints) > (fighter2FirstRound.roundWinned + fighter2SecondRound.roundWinned) - (fighter2FirstRound.minusPoints + fighter2SecondRound.minusPoints)) {
		if ((fighter1FirstRound.roundWinned + fighter1SecondRound.roundWinned) - (fighter1FirstRound.minusPoints + fighter1SecondRound.minusPoints) > (fighter2FirstRound.roundWinned + fighter2SecondRound.roundWinned) - (fighter2FirstRound.minusPoints + fighter2SecondRound.minusPoints) + 1) {
			if ((fighter1FirstRound.roundWinned + fighter1SecondRound.roundWinned) - (fighter1FirstRound.minusPoints + fighter1SecondRound.minusPoints) > (fighter2FirstRound.roundWinned + fighter2SecondRound.roundWinned) - (fighter2FirstRound.minusPoints + fighter2SecondRound.minusPoints) + 2) {
				wincourse1 = 1 + (wincourse1 - 1)*0.65;
				wincourse2 = courseCount(wincourse1);
			}
			wincourse1 = 1 + (wincourse1 - 1)*0.65;
			wincourse2 = courseCount(wincourse1);
		}
		if (fighter1FirstRound.foul + fighter1SecondRound.foul > 0) {
			wincourse1 = 1 + (wincourse1 - 1)*0.65;
			wincourse2 = courseCount(wincourse1);
		}
		else {
			wincourse1 = 1 + (wincourse1 - 1)*0.6;
			wincourse2 = courseCount(wincourse1);
		}
	}

	if ((fighter2FirstRound.roundWinned + fighter2SecondRound.roundWinned) - (fighter2FirstRound.minusPoints + fighter2SecondRound.minusPoints) > (fighter1FirstRound.roundWinned + fighter1SecondRound.roundWinned) - (fighter1FirstRound.minusPoints + fighter1SecondRound.minusPoints)) {
		if ((fighter2FirstRound.roundWinned + fighter2SecondRound.roundWinned) - (fighter2FirstRound.minusPoints + fighter2SecondRound.minusPoints) > (fighter1FirstRound.roundWinned + fighter1SecondRound.roundWinned) - (fighter1FirstRound.minusPoints + fighter1SecondRound.minusPoints) + 1) {
			if ((fighter2FirstRound.roundWinned + fighter2SecondRound.roundWinned) - (fighter2FirstRound.minusPoints + fighter2SecondRound.minusPoints) > (fighter1FirstRound.roundWinned + fighter1SecondRound.roundWinned) - (fighter1FirstRound.minusPoints + fighter1SecondRound.minusPoints) + 2) {
				wincourse2 = 1 + (wincourse2 - 1)*0.65;
				wincourse1 = courseCount(wincourse2);
			}
			wincourse2 = 1 + (wincourse2 - 1)*0.65;
			wincourse1 = courseCount(wincourse2);
		}
		if (fighter2FirstRound.foul + fighter2SecondRound.foul > 0) {
			wincourse2 = 1 + (wincourse2 - 1)*0.65;
			wincourse1 = courseCount(wincourse2);
		}
		else {
			wincourse2 = 1 + (wincourse2 - 1)*0.6;
			wincourse1 = courseCount(wincourse2);
		}
	}

	wincourse1 = courseCorrection(wincourse1);
	wincourse2 = courseCorrection(wincourse2);

	////////////////////////////////////////////////////////////////

	cout << "Stats after two rounds\n" << fighter1.lastName << "\n";
	cout << fighter1FirstRound.headStrikes + fighter1SecondRound.headStrikes << " Head strikes\n" << fighter1FirstRound.bodyStrikes + fighter1SecondRound.bodyStrikes << " Body strikes\n" << fighter1FirstRound.legStrikes + fighter1SecondRound.legStrikes << " Leg strikes\n" << fighter1FirstRound.minusPoints + fighter1SecondRound.minusPoints << " Minus points\n";
	cout << fighter2.lastName << "\n";
	cout << fighter2FirstRound.headStrikes + fighter2SecondRound.headStrikes << " Head strikes\n" << fighter2FirstRound.bodyStrikes + fighter2SecondRound.bodyStrikes << " Body strikes\n" << fighter2FirstRound.legStrikes + fighter2SecondRound.legStrikes << " Leg strikes\n" << fighter2FirstRound.minusPoints + fighter2SecondRound.minusPoints << " Minus points\n\n";
	cout << "\n";

	////////////////////////////////////////////////////////////////

	fighterInRound fighter1ThirdRound;
	fighterInRound fighter2ThirdRound;

	minute = 0;

	cout << " Start of round three.\n";

	while (round == 3) {

		cout << "Who?\n";
		cin >> who;
		if (!(who == "RoundEnd")) {
			cout << "What?/Where?\n";
			cin >> where;
			if (!(where == "PointDown") && !(where == "GetUp") && !(where == "Injury") && !(where == "Foul") && !(where == "Knockdown") && !(where == "GroundControl") && !(where == "CourseSet") && !(where == "HeavyPunch")) {

				cout << "Situation?\n";
				cin >> situation;
			}
		}

		if ((who == fighter1.firstName) || who == (fighter1.lastName)) {

			///////////////////////////////////////////////////////
			if (where == "CourseSet") {
				wincourse1 = courseSet();
				wincourse2 = courseCount(wincourse1);
			}
			///////////////////////////////////////////////////////
			if (where == "Knockdown") {
				wincourse1 = knockDown(wincourse1, fighter1);
				wincourse2 = courseCount(wincourse1);
				KO_TKOcourse = KO_TKO_knockDown(KO_TKOcourse, minute, round);
				fighter1ThirdRound.knockdown++;
				fighter1ThirdRound.points += 12;
			}
			///////////////////////////////////////////////////////
			else if (where == "Injury") {
				cout << "What injury?\n";
				cin >> situation;
				if (situation == "CutCloseToEyes") {
					cout << "How important cut?\nin range 0-1 | 0 - not important | 1 - most important (focus on probability of doctor stoppage or if blood goes into fighters eyes)\n";
					cin >> cutImportance;
					wincourse1 = cutCloseToEyes(wincourse1, cutImportance);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_cutCloseToEyes(KO_TKOcourse, cutImportance, minute, round);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
				}
				else if (situation == "BrokenNose") {
					wincourse1 = brokenNose(wincourse1);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_brokenNose(KO_TKOcourse, minute, round);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
				}
				else if (situation == "HandInjury") {
					cout << "How important injury?\nin range 0-1 | 0 - not important | 1 - most important\n";
					cin >> injuryImportance;
					wincourse1 = handInjury(wincourse1, injuryImportance);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_handInjury(KO_TKOcourse, injuryImportance, minute, round);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
				}
				else if (situation == "LegInjury") {
					cout << "How important injury?\nin range 0-1 | 0 - not important | 1 - most important\n";
					cin >> injuryImportance;
					wincourse1 = legInjury(wincourse1, injuryImportance);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_legInjury(KO_TKOcourse, injuryImportance, minute, round);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
				}
				else {
					cout << "Wrong injury describe. Try again.\n";
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "PointDown") {
				wincourse1 = pointDown(wincourse1, fighter1);
				wincourse2 = courseCount(wincourse1);
				fighter1ThirdRound.minusPoints++;
			}
			///////////////////////////////////////////////////////
			else if (where == "Foul") {
				wincourse1 = foul(wincourse1, fighter1);
				wincourse2 = courseCount(wincourse1);
				fighter1ThirdRound.foul++;
			}
			///////////////////////////////////////////////////////
			else if (where == "Standing") {

				if (situation == "HeadPunchByHand") {
					if (fighter1ThirdRound.headStrikes > 2) {
						wincourse1 = headPunchByHand(wincourse1, fighter1ThirdRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1ThirdRound.headStrikes++;
					fighter1ThirdRound.points += 1;
				}
				else if (situation == "HeadPunchByElbow") {
					if (fighter1ThirdRound.headStrikes > 2) {
						wincourse1 = headPunchByElbow(wincourse1, fighter1ThirdRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1ThirdRound.headStrikes++;
					fighter1ThirdRound.points += 2;
				}
				else if (situation == "HeadKick") {
					if (fighter1ThirdRound.headStrikes > 2) {
						wincourse1 = headKick(wincourse1, fighter1ThirdRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1ThirdRound.headStrikes++;
					fighter1ThirdRound.points += 3;
				}
				else if (situation == "HeadKickByKnee") {
					if (fighter1ThirdRound.headStrikes > 2) {
						wincourse1 = headKickByKnee(wincourse1, fighter1ThirdRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1ThirdRound.headStrikes++;
					fighter1ThirdRound.points += 4;
				}
				else if (situation == "BodyPunch") {
					if (fighter1ThirdRound.bodyStrikes > 2) {
						wincourse1 = bodyPunch(wincourse1, fighter1ThirdRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1ThirdRound.bodyStrikes++;
					fighter1ThirdRound.points += 1;
				}
				else if (situation == "BodyKick") {
					if (fighter1ThirdRound.bodyStrikes > 2) {
						wincourse1 = bodyKick(wincourse1, fighter1ThirdRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1ThirdRound.bodyStrikes++;
					fighter1ThirdRound.points += 2;
				}
				else if (situation == "BodyKickByKnee") {
					if (fighter1ThirdRound.bodyStrikes > 2) {
						wincourse1 = bodyKickByKnee(wincourse1, fighter1ThirdRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1ThirdRound.bodyStrikes++;
					fighter1ThirdRound.points += 2;
				}
				else if (situation == "LowKick") {
					if (fighter1ThirdRound.legStrikes > 2) {
						wincourse1 = lowKick(wincourse1, fighter1ThirdRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1ThirdRound.legStrikes++;
					fighter1ThirdRound.points += 1;
				}
				else if (situation == "CalfKick") {
					if (fighter1ThirdRound.legStrikes > 2) {
						wincourse1 = calfKick(wincourse1, fighter1ThirdRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1ThirdRound.legStrikes++;
					fighter1ThirdRound.points += 1;
				}
				else {
					cout << "Wrong action describe. Try again.\n";
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "Clinch") {

				if (situation == "HeadPunchByHand") {
					if (fighter1ThirdRound.headStrikes > 2) {
						wincourse1 = headPunchByHand(wincourse1, fighter1ThirdRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1ThirdRound.headStrikes++;
					fighter1ThirdRound.points += 1;
				}
				else if (situation == "HeadPunchByElbow") {
					if (fighter1ThirdRound.headStrikes > 2) {
						wincourse1 = headPunchByElbow(wincourse1, fighter1ThirdRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1ThirdRound.headStrikes++;
					fighter1ThirdRound.points += 2;
				}
				else if (situation == "HeadKickByKnee") {
					if (fighter1ThirdRound.headStrikes > 2) {
						wincourse1 = headKickByKnee(wincourse1, fighter1ThirdRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1ThirdRound.headStrikes++;
					fighter1ThirdRound.points += 3;
				}
				else if (situation == "BodyPunch") {
					if (fighter1ThirdRound.bodyStrikes > 2) {
						wincourse1 = bodyPunch(wincourse1, fighter1ThirdRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1ThirdRound.bodyStrikes++;
					fighter1ThirdRound.points += 1;
				}
				else if (situation == "BodyKickByKnee") {
					if (fighter1ThirdRound.bodyStrikes > 2) {
						wincourse1 = bodyKickByKnee(wincourse1, fighter1ThirdRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1ThirdRound.bodyStrikes++;
					fighter1ThirdRound.points += 2;
				}
				else {
					cout << "Wrong action describe. Try again.\n";
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "Ground") {

				if (situation == "HeadPunchByHand") {
					if (fighter1ThirdRound.headStrikes > 2) {
						wincourse1 = headPunchByHand(wincourse1, fighter1ThirdRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1ThirdRound.headStrikes++;
					fighter1ThirdRound.points += 1;
				}
				else if (situation == "HeadPunchByElbow") {
					if (fighter1ThirdRound.headStrikes > 2) {
						wincourse1 = headPunchByElbow(wincourse1, fighter1ThirdRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1ThirdRound.headStrikes++;
					fighter1ThirdRound.points += 3;
				}
				else if (situation == "BodyPunch") {
					if (fighter1ThirdRound.headStrikes > 2) {
						wincourse1 = bodyPunch(wincourse1, fighter1ThirdRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1ThirdRound.bodyStrikes++;
					fighter1ThirdRound.points += 1;
				}
				else if (situation == "BodyKickByKnee") {
					if (fighter1ThirdRound.headStrikes > 2) {
						wincourse1 = bodyKickByKnee(wincourse1, fighter1ThirdRound);
						wincourse2 = courseCount(wincourse1);
					}
					fighter1ThirdRound.bodyStrikes++;
					fighter1ThirdRound.points += 2;
				}
				else if (situation == "Guard") {
					wincourse1 = guard(wincourse1, fighter1, fighter1ThirdRound.position);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_guard(KO_TKOcourse, fighter1, fighter1ThirdRound.position, minute);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
					fighter1ThirdRound.position = 1;
					fighter1ThirdRound.powerIncreaser = powerSetter(fighter1, fighter1ThirdRound.position);
				}
				else if (situation == "Halfguard") {
					wincourse1 = halfGuard(wincourse1, fighter1, fighter1ThirdRound.position);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_halfGuard(KO_TKOcourse, fighter1, fighter1ThirdRound.position, minute);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
					fighter1ThirdRound.position = 2;
					fighter1ThirdRound.powerIncreaser = powerSetter(fighter1, fighter1ThirdRound.position);
				}
				else if (situation == "Side") {
					wincourse1 = side(wincourse1, fighter1, fighter1ThirdRound.position);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_side(KO_TKOcourse, fighter1, fighter1ThirdRound.position, minute);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
					fighter1ThirdRound.position = 3;
					fighter1ThirdRound.powerIncreaser = powerSetter(fighter1, fighter1ThirdRound.position);
				}
				else if (situation == "Mount") {
					wincourse1 = mount(wincourse1, fighter1, fighter1ThirdRound.position);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_mount(KO_TKOcourse, fighter1, fighter1ThirdRound.position, minute);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
					fighter1ThirdRound.position = 4;
					fighter1ThirdRound.powerIncreaser = powerSetter(fighter1, fighter1ThirdRound.position);
				}
				else if (situation == "Back") {
					wincourse1 = back(wincourse1, fighter1, fighter1ThirdRound.position);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_back(KO_TKOcourse, fighter1, fighter1ThirdRound.position, minute);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
					fighter1ThirdRound.position = 5;
					fighter1ThirdRound.powerIncreaser = powerSetter(fighter1, fighter1ThirdRound.position);
				}
				else if (situation == "NorthSouth") {
					wincourse1 = northSouth(wincourse1, fighter1, fighter1ThirdRound.position);
					wincourse2 = courseCount(wincourse1);
					KO_TKOcourse = KO_TKO_northSouth(KO_TKOcourse, fighter1, fighter1ThirdRound.position, minute);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
					fighter1ThirdRound.position = 6;
					fighter1ThirdRound.powerIncreaser = powerSetter(fighter1, fighter1ThirdRound.position);
				}
				else {
					cout << "Wrong action describe. Try again.\n";
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "GetUp") {
				fighter1ThirdRound.position = 0;
				wincourse1 = getUp(wincourse1, fighter1, fighter1ThirdRound.position);
				wincourse2 = courseCount(wincourse1);
				KO_TKOcourse = KO_TKO_getUp(KO_TKOcourse, fighter1, fighter1ThirdRound.position, minute);
				NoKO_TKOcourse = courseCount(KO_TKOcourse);
				fighter1ThirdRound.powerIncreaser = 1;
			}
			///////////////////////////////////////////////////////
			else if (where == "GroundControl") {
				cout << "How long? (in sec)?\n";
				cin >> timeGround;
				fighter1ThirdRound.control += timeGround;
				if (timeGround > 100 && fighter1ThirdRound.control < 100) {
					fighter1ThirdRound.controlPhase = fighter1ThirdRound.controlPhase + 1;
					wincourse1 = 1 + (wincourse1 - 1)*0.9;
					wincourse2 = courseCount(wincourse1);
				}
				if (timeGround > 200) {
					fighter1ThirdRound.controlPhase = fighter1ThirdRound.controlPhase + 2;
					wincourse1 = 1 + (wincourse1 - 1)*0.81;
					wincourse2 = courseCount(wincourse1);
				}
				timeGround = 0;

				if (fighter1ThirdRound.control < 100) {
					if (fighter1ThirdRound.controlPhase == 1) {
						wincourse1 = 1 + (wincourse1 - 1)*0.9;
						wincourse2 = courseCount(wincourse1);
						fighter1ThirdRound.controlPhase = 2;
						fighter1ThirdRound.points += 5;
					}
				}
				else if (fighter1ThirdRound.control > 100 && fighter1ThirdRound.control < 200) {
					if (fighter1ThirdRound.controlPhase == 2) {
						wincourse1 = 1 + (wincourse1 - 1)*0.9;
						wincourse2 = courseCount(wincourse1);
						fighter1ThirdRound.controlPhase = 3;
						fighter1ThirdRound.points += 15;
					}
				}
				else if (fighter1ThirdRound.control > 200) {
					if (fighter1ThirdRound.controlPhase == 3) {
						wincourse1 = 1 + (wincourse1 - 1)*0.9;
						wincourse2 = courseCount(wincourse1);
						fighter1ThirdRound.controlPhase = 4;
						fighter1ThirdRound.points += 30;
					}
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "ClinchControl") {
				cout << "How long? (in sec)?\n";
				cin >> timeClinch;
				fighter1ThirdRound.controlClinch += timeClinch;
				if (timeClinch > 100 && fighter1ThirdRound.controlClinch < 100) {
					fighter1ThirdRound.controlPhaseClinch = fighter1ThirdRound.controlPhaseClinch + 1;
					wincourse1 = 1 + (wincourse1 - 1)*0.95;
					wincourse2 = courseCount(wincourse1);
				}
				if (timeClinch > 200) {
					fighter1ThirdRound.controlPhaseClinch = fighter1ThirdRound.controlPhaseClinch + 2;
					wincourse1 = 1 + (wincourse1 - 1)*0.9025;
					wincourse2 = courseCount(wincourse1);
				}
				timeClinch = 0;

				if (fighter1ThirdRound.controlClinch < 100) {
					if (fighter1ThirdRound.controlPhaseClinch == 1) {
						wincourse1 = 1 + (wincourse1 - 1)*0.95;
						wincourse2 = courseCount(wincourse1);
						fighter1ThirdRound.controlPhase = 2;
					}
				}
				else if (fighter1ThirdRound.controlClinch > 100 && fighter1ThirdRound.controlClinch < 200) {
					if (fighter1ThirdRound.controlPhaseClinch == 2) {
						wincourse1 = 1 + (wincourse1 - 1)*0.95;
						wincourse2 = courseCount(wincourse1);
						fighter1ThirdRound.controlPhaseClinch = 3;
					}
				}
				else if (fighter1ThirdRound.controlClinch > 200) {
					if (fighter1ThirdRound.controlPhaseClinch == 3) {
						wincourse1 = 1 + (wincourse1 - 1)*0.95;
						wincourse2 = courseCount(wincourse1);
						fighter1ThirdRound.controlPhaseClinch = 4;
					}
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "HeavyPunch") {
				cout << "How much did the punch affect opponent?\nin range 0-1 | 0 - not much | 1 - very much\n(1 means almost knockdown, but opponent is still standing)\n";
				heaviness = 0;
				cin >> heaviness;
				wincourse1 = heavyPunch(wincourse1, heaviness);
				wincourse2 = courseCount(wincourse1);
				KO_TKOcourse = KO_TKO_heavyPunch(KO_TKOcourse, heaviness, minute, round);
				NoKO_TKOcourse = courseCount(KO_TKOcourse);
				fighter1ThirdRound.headStrikes++;
				fighter1ThirdRound.points += 10;
			}
			///////////////////////////////////////////////////////
			else {
				cout << "Something went wrong. Try again.\n";
			}
		}// end of fighter1 actions

		///////////////////////////////////////////////////////

		else if ((who == fighter2.firstName) || who == (fighter2.lastName)) {

			///////////////////////////////////////////////////////
			if (where == "CourseSet") {
				wincourse2 = courseSet();
				wincourse1 = courseCount(wincourse2);
			}
			///////////////////////////////////////////////////////
			if (where == "Knockdown") {
				wincourse2 = knockDown(wincourse2, fighter2);
				wincourse1 = courseCount(wincourse2);
				KO_TKOcourse = KO_TKO_knockDown(KO_TKOcourse, minute, round);
				fighter2ThirdRound.knockdown++;
				fighter2ThirdRound.points += 12;
			}
			///////////////////////////////////////////////////////
			else if (where == "Injury") {
				cout << "What injury?\n";
				cin >> situation;
				if (situation == "CutCloseToEyes") {
					cout << "How important cut?\nin range 0-1 | 0 - not important | 1 - most important (focus on probability of doctor stoppage or if blood goes into fighters eyes)\n";
					cin >> cutImportance;
					wincourse2 = cutCloseToEyes(wincourse2, cutImportance);
					wincourse1 = courseCount(wincourse2);
					KO_TKOcourse = KO_TKO_cutCloseToEyes(KO_TKOcourse, cutImportance, minute, round);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
				}
				else if (situation == "BrokenNose") {
					wincourse2 = brokenNose(wincourse2);
					wincourse1 = courseCount(wincourse2);
					KO_TKOcourse = KO_TKO_brokenNose(KO_TKOcourse, minute, round);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
				}
				else if (situation == "HandInjury") {
					cout << "How important injury?\nin range 0-1 | 0 - not important | 1 - most important\n";
					cin >> injuryImportance;
					wincourse2 = handInjury(wincourse2, injuryImportance);
					wincourse1 = courseCount(wincourse2);

					KO_TKOcourse = KO_TKO_handInjury(KO_TKOcourse, injuryImportance, minute, round);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
				}
				else if (situation == "LegInjury") {
					cout << "How important injury?\nin range 0-1 | 0 - not important | 1 - most important\n";
					cin >> injuryImportance;
					wincourse2 = legInjury(wincourse2, injuryImportance);
					wincourse1 = courseCount(wincourse2);
					KO_TKOcourse = KO_TKO_legInjury(KO_TKOcourse, injuryImportance, minute, round);
					NoKO_TKOcourse = courseCount(KO_TKOcourse);
				}
				else {
					cout << "Wrong injury describe. Try again.\n";
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "PointDown") {
				wincourse2 = pointDown(wincourse2, fighter2);
				wincourse1 = courseCount(wincourse2);
				fighter2ThirdRound.minusPoints++;
			}
			///////////////////////////////////////////////////////
			else if (where == "Foul") {
				wincourse2 = foul(wincourse2, fighter2);
				wincourse1 = courseCount(wincourse2);
				fighter2ThirdRound.foul++;
			}
			///////////////////////////////////////////////////////
			else if (where == "Standing") {

				if (situation == "HeadPunchByHand") {
					if (fighter2ThirdRound.headStrikes > 2) {
						wincourse2 = headPunchByHand(wincourse2, fighter2ThirdRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2ThirdRound.headStrikes++;
					fighter2ThirdRound.points += 1;
				}
				else if (situation == "HeadPunchByElbow") {
					if (fighter2ThirdRound.headStrikes > 2) {
						wincourse2 = headPunchByElbow(wincourse2, fighter2ThirdRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2ThirdRound.headStrikes++;
					fighter2ThirdRound.points += 2;
				}
				else if (situation == "HeadKick") {
					if (fighter2ThirdRound.headStrikes > 2) {
						wincourse2 = headKick(wincourse2, fighter2ThirdRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2ThirdRound.headStrikes++;
					fighter2ThirdRound.points += 3;
				}
				else if (situation == "HeadKickByKnee") {
					if (fighter2ThirdRound.headStrikes > 2) {
						wincourse2 = headKickByKnee(wincourse2, fighter2ThirdRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2ThirdRound.headStrikes++;
					fighter2ThirdRound.points += 4;
				}
				else if (situation == "BodyPunch") {
					if (fighter2ThirdRound.bodyStrikes > 2) {
						wincourse2 = bodyPunch(wincourse2, fighter2ThirdRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2ThirdRound.bodyStrikes++;
					fighter2ThirdRound.points += 1;
				}
				else if (situation == "BodyKick") {
					if (fighter2ThirdRound.bodyStrikes > 2) {
						wincourse2 = bodyKick(wincourse2, fighter2ThirdRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2ThirdRound.bodyStrikes++;
					fighter2ThirdRound.points += 2;
				}
				else if (situation == "BodyKickByKnee") {
					if (fighter2ThirdRound.bodyStrikes > 2) {
						wincourse2 = bodyKickByKnee(wincourse2, fighter2ThirdRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2ThirdRound.bodyStrikes++;
					fighter2ThirdRound.points += 2;
				}
				else if (situation == "LowKick") {
					if (fighter2ThirdRound.legStrikes > 2) {
						wincourse2 = lowKick(wincourse2, fighter2ThirdRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2ThirdRound.legStrikes++;
					fighter2ThirdRound.points += 1;
				}
				else if (situation == "CalfKick") {
					if (fighter2ThirdRound.legStrikes > 2) {
						wincourse2 = calfKick(wincourse2, fighter2ThirdRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2ThirdRound.legStrikes++;
					fighter2ThirdRound.points += 1;
				}
				else {
					cout << "Wrong action describe. Try again.\n";
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "Clinch") {

				if (situation == "HeadPunchByHand") {
					if (fighter2ThirdRound.headStrikes > 2) {
						wincourse2 = headPunchByHand(wincourse2, fighter2ThirdRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2ThirdRound.headStrikes++;
					fighter2ThirdRound.points += 1;
				}
				else if (situation == "HeadPunchByElbow") {
					if (fighter2ThirdRound.headStrikes > 2) {
						wincourse2 = headPunchByElbow(wincourse2, fighter2ThirdRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2ThirdRound.headStrikes++;
					fighter2ThirdRound.points += 2;
				}
				else if (situation == "HeadKickByKnee") {
					if (fighter2ThirdRound.headStrikes > 2) {
						wincourse2 = headKickByKnee(wincourse2, fighter2ThirdRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2ThirdRound.headStrikes++;
					fighter2ThirdRound.points += 3;
				}
				else if (situation == "BodyPunch") {
					if (fighter2ThirdRound.bodyStrikes > 2) {
						wincourse2 = bodyPunch(wincourse2, fighter2ThirdRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2ThirdRound.bodyStrikes++;
					fighter2ThirdRound.points += 1;
				}
				else if (situation == "BodyKickByKnee") {
					if (fighter2ThirdRound.bodyStrikes > 2) {
						wincourse2 = bodyKickByKnee(wincourse2, fighter2ThirdRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2ThirdRound.bodyStrikes++;
					fighter2ThirdRound.points += 2;
				}
				else {
					cout << "Wrong action describe. Try again.\n";
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "Ground") {

				if (situation == "HeadPunchByHand") {
					if (fighter2ThirdRound.headStrikes > 2) {
						wincourse2 = headPunchByHand(wincourse2, fighter2ThirdRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2ThirdRound.headStrikes++;
					fighter2ThirdRound.points += 1;
				}
				else if (situation == "HeadPunchByElbow") {
					if (fighter2ThirdRound.headStrikes > 2) {
						wincourse2 = headPunchByElbow(wincourse2, fighter2ThirdRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2ThirdRound.headStrikes++;
					fighter2ThirdRound.points += 3;
				}
				else if (situation == "BodyPunch") {
					if (fighter2ThirdRound.headStrikes > 2) {
						wincourse2 = bodyPunch(wincourse2, fighter2ThirdRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2ThirdRound.bodyStrikes++;
					fighter2ThirdRound.points += 1;
				}
				else if (situation == "BodyKickByKnee") {
					if (fighter2ThirdRound.headStrikes > 2) {
						wincourse2 = bodyKickByKnee(wincourse2, fighter2ThirdRound);
						wincourse1 = courseCount(wincourse2);
					}
					fighter2ThirdRound.bodyStrikes++;
					fighter2ThirdRound.points += 2;
				}
				else if (situation == "Guard") {
					wincourse2 = guard(wincourse2, fighter2, fighter2ThirdRound.position);
					wincourse1 = courseCount(wincourse2);
					fighter2ThirdRound.position = 1;
					fighter2ThirdRound.powerIncreaser = powerSetter(fighter2, fighter2ThirdRound.position);
				}
				else if (situation == "Halfguard") {
					wincourse2 = halfGuard(wincourse2, fighter2, fighter2ThirdRound.position);
					wincourse1 = courseCount(wincourse2);
					fighter2ThirdRound.position = 2;
					fighter2ThirdRound.powerIncreaser = powerSetter(fighter2, fighter2ThirdRound.position);
				}
				else if (situation == "Side") {
					wincourse2 = side(wincourse2, fighter2, fighter2ThirdRound.position);
					wincourse1 = courseCount(wincourse2);
					fighter2ThirdRound.position = 3;
					fighter2ThirdRound.powerIncreaser = powerSetter(fighter2, fighter2ThirdRound.position);
				}
				else if (situation == "Mount") {
					wincourse2 = mount(wincourse2, fighter2, fighter2ThirdRound.position);
					wincourse1 = courseCount(wincourse2);
					fighter2ThirdRound.position = 4;
					fighter2ThirdRound.powerIncreaser = powerSetter(fighter2, fighter2ThirdRound.position);
				}
				else if (situation == "Back") {
					wincourse2 = back(wincourse2, fighter2, fighter2ThirdRound.position);
					wincourse1 = courseCount(wincourse2);
					fighter2ThirdRound.position = 5;
					fighter2ThirdRound.powerIncreaser = powerSetter(fighter2, fighter2ThirdRound.position);
				}
				else if (situation == "NorthSouth") {
					wincourse2 = northSouth(wincourse2, fighter2, fighter2ThirdRound.position);
					wincourse1 = courseCount(wincourse2);
					fighter2ThirdRound.position = 6;
					fighter2ThirdRound.powerIncreaser = powerSetter(fighter2, fighter2ThirdRound.position);
				}
				else {
					cout << "Wrong action describe. Try again.\n";
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "GetUp") {
				fighter2ThirdRound.position = 0;
				wincourse2 = getUp(wincourse2, fighter2, fighter2ThirdRound.position);
				wincourse1 = courseCount(wincourse2);
				KO_TKOcourse = KO_TKO_getUp(KO_TKOcourse, fighter2, fighter2ThirdRound.position, minute);
				NoKO_TKOcourse = courseCount(KO_TKOcourse);
				fighter2ThirdRound.powerIncreaser = 1;
			}
			///////////////////////////////////////////////////////
			else if (where == "GroundControl") {
				cout << "How long? (in sec)?\n";
				cin >> timeGround;
				fighter2ThirdRound.control += timeGround;
				if (timeGround > 100 && fighter2ThirdRound.control < 100) {
					fighter2ThirdRound.controlPhase = fighter2ThirdRound.controlPhase + 1;
					wincourse2 = 1 + (wincourse2 - 1)*0.9;
					wincourse1 = courseCount(wincourse2);
				}
				if (timeGround > 200) {
					fighter2ThirdRound.controlPhase = fighter2ThirdRound.controlPhase + 2;
					wincourse2 = 1 + (wincourse2 - 1)*0.81;
					wincourse1 = courseCount(wincourse2);
				}
				timeGround = 0;

				if (fighter2ThirdRound.control < 100) {
					if (fighter2ThirdRound.controlPhase == 1) {
						wincourse2 = 1 + (wincourse2 - 1)*0.9;
						wincourse1 = courseCount(wincourse2);
						fighter2ThirdRound.controlPhase = 2;
						fighter2ThirdRound.points += 5;
					}
				}
				else if (fighter2ThirdRound.control > 100 && fighter2ThirdRound.control < 200) {
					if (fighter2ThirdRound.controlPhase == 2) {
						wincourse2 = 1 + (wincourse2 - 1)*0.9;
						wincourse1 = courseCount(wincourse2);
						fighter2ThirdRound.controlPhase = 3;
						fighter2ThirdRound.points += 15;
					}
				}
				else if (fighter2ThirdRound.control > 200) {
					if (fighter2ThirdRound.controlPhase == 3) {
						wincourse2 = 1 + (wincourse2 - 1)*0.9;
						wincourse1 = courseCount(wincourse2);
						fighter2ThirdRound.controlPhase = 4;
						fighter2ThirdRound.points += 30;
					}
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "ClinchControl") {
				cout << "How long? (in sec)?\n";
				cin >> timeClinch;
				fighter2ThirdRound.controlClinch += timeClinch;
				if (timeClinch > 100 && fighter2ThirdRound.controlClinch < 100) {
					fighter2ThirdRound.controlPhaseClinch = fighter2ThirdRound.controlPhaseClinch + 1;
					wincourse2 = 1 + (wincourse2 - 1)*0.95;
					wincourse1 = courseCount(wincourse2);
				}
				if (timeClinch > 200) {
					fighter2ThirdRound.controlPhaseClinch = fighter2ThirdRound.controlPhaseClinch + 2;
					wincourse2 = 1 + (wincourse2 - 1)*0.9025;
					wincourse1 = courseCount(wincourse2);
				}
				timeClinch = 0;

				if (fighter2ThirdRound.controlClinch < 100) {
					if (fighter2ThirdRound.controlPhaseClinch == 1) {
						wincourse2 = 1 + (wincourse2 - 1)*0.95;
						wincourse1 = courseCount(wincourse2);
						fighter2ThirdRound.controlPhase = 2;
					}
				}
				else if (fighter2ThirdRound.controlClinch > 100 && fighter2ThirdRound.controlClinch < 200) {
					if (fighter2ThirdRound.controlPhaseClinch == 2) {
						wincourse2 = 1 + (wincourse2 - 1)*0.95;
						wincourse1 = courseCount(wincourse2);
						fighter2ThirdRound.controlPhaseClinch = 3;
					}
				}
				else if (fighter2ThirdRound.controlClinch > 200) {
					if (fighter2ThirdRound.controlPhaseClinch == 3) {
						wincourse2 = 1 + (wincourse2 - 1)*0.95;
						wincourse1 = courseCount(wincourse2);
						fighter2ThirdRound.controlPhaseClinch = 4;
					}
				}
			}
			///////////////////////////////////////////////////////
			else if (where == "HeavyPunch") {
				cout << "How much did the punch affect opponent?\nin range 0-1 | 0 - not much | 1 - very much\n(1 means almost knockdown, but opponent is still standing)\n";
				heaviness = 0;
				cin >> heaviness;
				wincourse2 = heavyPunch(wincourse2, heaviness);
				wincourse1 = courseCount(wincourse2);
				KO_TKOcourse = KO_TKO_heavyPunch(KO_TKOcourse, heaviness, minute, round);
				NoKO_TKOcourse = courseCount(KO_TKOcourse);
				fighter2ThirdRound.headStrikes++;
				fighter2ThirdRound.points += 10;
			}
			///////////////////////////////////////////////////////
			else {
				cout << "Something went wrong. Try again.\n";
			}
		}// end of fighter2 actions

		///////////////////////////////////////////////////////

		else if (who == "RoundEnd") {
			round = 4;
		}

		///////////////////////////////////////////////////////

		else {
			cout << "Something went wrong. Try again.\n";
		}

		wincourse1 = courseCorrection(wincourse1);
		wincourse2 = courseCorrection(wincourse2);

		cout << "///////////////////////////////////////////////////////\n";
		cout << "///////////////////////////////////////////////////////\n";
		cout << fighter1.lastName << " " << wincourse1 << " - " << wincourse2 << " " << fighter2.lastName << "\n";
		cout << "///////////////////////////////////////////////////////\n";
		cout << "///////////////////////////////////////////////////////\n";

	} // end of round 3


	////////////////////////////////////////////////////////////////

	cout << "Stats after three rounds\n" << fighter1.lastName << "\n";
	cout << fighter1FirstRound.headStrikes + fighter1SecondRound.headStrikes + fighter1ThirdRound.headStrikes << " Head strikes\n" << fighter1FirstRound.bodyStrikes + fighter1SecondRound.bodyStrikes + fighter1ThirdRound.bodyStrikes << " Body strikes\n" << fighter1FirstRound.legStrikes + fighter1SecondRound.legStrikes + fighter1ThirdRound.legStrikes << " Leg strikes\n";
	cout << fighter2.lastName << "\n";
	cout << fighter2FirstRound.headStrikes + fighter2SecondRound.headStrikes + fighter2ThirdRound.headStrikes << " Head strikes\n" << fighter2FirstRound.bodyStrikes + fighter2SecondRound.bodyStrikes + fighter2ThirdRound.bodyStrikes << " Body strikes\n" << fighter2FirstRound.legStrikes + fighter2SecondRound.legStrikes + fighter2ThirdRound.legStrikes << " Leg strikes\n\n";
	cout << "\n";

	////////////////////////////////////////////////////////////////
	cout << "End of match.\n";
	return 0;
	
} //end of main

double courseCount(double course) {

	return 1.85/(2-(1.85/course));
}

double courseCorrection(double course) {

	if(course < 1)return 1;
	else return course;
}

double courseSet(void) {

	double temp = 0;
	cout << "Value of course?\n";
	cin >> temp;
	return temp;
}

double knockDown(double course, fighter fighter) {

	return 1 + (course - 1)*(0.8 - 0.3*(fighter.KOwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
}

double pointDown(double course, fighter fighter) {

	return 1 + (course - 1)*(1.1 + 0.3*(fighter.DECwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
}

double foul(double course, fighter fighter) {

	return 1 + (course - 1)*(1.1 + 0.05*(fighter.DECwin / (fighter.KOwin + fighter.DECwin + fighter.SUBwin + fighter.TKOwin)));
}

///////////////////////////////////////////////////////////////////////////////////////////