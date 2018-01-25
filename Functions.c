#include "Functions\userControl.c"
#include "Functions\Autonomous.c"
#include "Functions\LCDController.c"
//#include "Sounds\Library.c"
//#include "Functions\setAutonomous.c"

void setPIDCtrl()
{
	nMotorPIDSpeedCtrl[driveFL] = mtrSpeedReg;
	nMotorPIDSpeedCtrl[driveFR] = mtrSpeedReg;
	nMotorPIDSpeedCtrl[driveBL] = mtrSpeedReg;
	nMotorPIDSpeedCtrl[driveBR] = mtrSpeedReg;
}

void initializeRobot()
{
	resetEncoders();
	setPIDCtrl();
	startTask(LCDController);
}
