#pragma config(UserModel, "E:/A - RobotC/A - MainCode/Config.h")

#pragma platform(VEX2)

#pragma competitionControl(Competition)

#include "Vex_Competition_Includes.c"
#include "Functions.c"
//#include "displayBattery.c"
//#include "codeChooser.c"
//#include "LCDController.c"
//#include "setAutonomous.c"


int codeSelection = 0;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  bStopTasksBetweenModes = false;

	bDisplayCompetitionStatusOnLcd = false;

	//setPIDCtrl();
	startTask(LCDController);

	initializeRobot();
}


task autonomous()
{
	setPIDCtrl();

	codeSelection = getCodeSelection();

	switch(codeSelection) {
		case 0:
			Autonomous2();
			break;
		case 1:
			Autonomous2();
			break;
		case 2:
			Autonomous3();
			break;
		case 3:
			Autonomous4();
			break;
		//default:
		//	driveForDistance(12, 127);
		//	break;
	}
}


task usercontrol()
{
  setPIDCtrl();

  while (true)
  {
		userDrive(25);

		btnMotor(Btn6U, Btn6D, mgL, 127);
		btnMotor(Btn6U, Btn6D, mgR, 127);
  }
}
