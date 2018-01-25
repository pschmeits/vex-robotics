
void resetEncoders() {
	resetMotorEncoder(driveFL);
  resetMotorEncoder(driveFR);
  resetMotorEncoder(driveBL);
  resetMotorEncoder(driveBR);
}

void turnLeftDeg(int degrees, int power)
{
  resetEncoders();

  //Determine tickGoal
  int tickGoal = round((degrees/360)*392);

  //Start the motors in a left point turn.
  motor[driveBL] = -power;
  motor[driveBR] = power;
  motor[driveFL] = -power;
  motor[driveFR] = power;

  //Since the wheels may go at slightly different speeds due to manufacturing tolerances, etc.,
  //we need to test both encoders and control both motors separately. This may result in one motor
  //going for longer than another but it will ultimately result in a much more accurate turn.
  while(getMotorEncoder(driveBR) < tickGoal || getMotorEncoder(driveBL) > -tickGoal) {
    if(getMotorEncoder(driveBR) > tickGoal) {motor[driveBR] = 0; motor[driveFR] = 0;}
    if(getMotorEncoder(driveBL) < -tickGoal) {motor[driveBL] = 0; motor[driveFL] = 0;}
  }
  //Make sure both motors stop at the end of the turn.
 	motor[driveBL] = 0;
  motor[driveBR] = 0;
  motor[driveFL] = 0;
  motor[driveFR] = 0;
}

void turnRightDeg(int degrees, int power)
{
  resetEncoders();

  //Determine tickGoal
  int tickGoal = round((degrees/360)*392);

  //Start the motors in a left point turn.
  motor[driveBL] = power;
  motor[driveBR] = -power;
  motor[driveFL] = power;
  motor[driveFR] = -power;

  //Since the wheels may go at slightly different speeds due to manufacturing tolerances, etc.,
  //we need to test both encoders and control both motors separately. This may result in one motor
  //going for longer than another but it will ultimately result in a much more accurate turn.
  while(getMotorEncoder(driveBL) < tickGoal || getMotorEncoder(driveBR) > -tickGoal) {
    if(getMotorEncoder(driveBL) > tickGoal) {motor[driveBL] = 0; motor[driveFL] = 0;}
    if(getMotorEncoder(driveBR) < -tickGoal) {motor[driveBR] = 0; motor[driveFR] = 0;}
  }
  //Make sure both motors stop at the end of the turn.
 	motor[driveBL] = 0;
  motor[driveBR] = 0;
  motor[driveFL] = 0;
  motor[driveFR] = 0;
}

//void pivot(int degrees, int power) {
//	resetEncoders();
//	setMotorTarget(driveFL, ((((degrees/360)*2*PI*9)/(2*PI*2))*392), power, false);
//  setMotorTarget(driveFR, (-(((degrees/360)*2*PI*9)/(2*PI*2))*392), power, false);
//  setMotorTarget(driveBL, ((((degrees/360)*2*PI*9)/(2*PI*2))*392), power, false);
//  setMotorTarget(driveBR, (-(((degrees/360)*2*PI*9)/(2*PI*2))*392), power, false);

//  waitUntilMotorStop(driveFL);
//  waitUntilMotorStop(driveFR);
//  waitUntilMotorStop(driveBL);
//  waitUntilMotorStop(driveBR);

//  wait1Msec(50);
//}

//void pivot(int degrees, int power) {
//	resetEncoders();
//	while(getMotorEncoder(driveBL) != (((degrees/360)*PI*18)/(2*PI*2))*392 || getMotorEncoder(driveBR) != (((degrees/360)*PI*18)/(2*PI*2))*392) {
//		if(getMotorEncoder(driveBL) != (((degrees/360)*PI*18)/(2*PI*2))*392) {
//			motor[driveFL] = (degrees/abs(degrees))*power;
//			motor[driveBL] = (degrees/abs(degrees))*power;
//		}
//		else {
//			motor[driveFL] = 0;
//			motor[driveBL] = 0;
//		}
//		if(getMotorEncoder(driveBR) != (((degrees/360)*PI*18)/(2*PI*2))*392) {
//			motor[driveFR] = -(degrees/abs(degrees))*power;
//			motor[driveBR] = -(degrees/abs(degrees))*power;
//		}
//		else {
//			motor[driveFR] = 0;
//			motor[driveBR] = 0;
//		}
//		wait1Msec(5);
//	}
//	motor[driveFL] = 0;
//	motor[driveBL] = 0;
//	motor[driveFR] = 0;
//	motor[driveBR] = 0;

//  waitUntilMotorStop(driveFL);
//  waitUntilMotorStop(driveFR);
//  waitUntilMotorStop(driveBL);
//  waitUntilMotorStop(driveBR);

//  wait1Msec(50);
//}

void turnLeft(int power) {
	turnLeftDeg(90, power);
}

void turnRight(int power) {
	turnRightDeg(90, power);
}

void driveForDistance(int distance, int power) { //INCHES
	resetEncoders();
	setMotorTarget(driveFL, (distance/(2*PI*2))*392, power, false);
  setMotorTarget(driveFR, (distance/(2*PI*2))*392, power, false);
  setMotorTarget(driveBL, (distance/(2*PI*2))*392, power, false);
  setMotorTarget(driveBR, (distance/(2*PI*2))*392, power, false);

  waitUntilMotorStop(driveFL);
  waitUntilMotorStop(driveFR);
  waitUntilMotorStop(driveBL);
  waitUntilMotorStop(driveBR);

  wait1Msec(50);
}

//void driveForDistance(int distance, int radius, int countPerRev, int power) { //INCHES
//	resetEncoders();
//	setMotorTarget(driveFL, (distance/(2*PI*radius))*countPerRev, power, true);
//  setMotorTarget(driveFR, (distance/(2*PI*radius))*countPerRev, power, true);
//  setMotorTarget(driveBL, (distance/(2*PI*radius))*countPerRev, power, true);
//  setMotorTarget(driveBR, (distance/(2*PI*radius))*countPerRev, power, true);
//  waitUntil(getMotorTargetCompleted(driveFL) && getMotorTargetCompleted(driveFR) && getMotorTargetCompleted(driveBL) && getMotorTargetCompleted(driveBR));
//  wait1Msec(50);
//}

void Autonomous1() {
	driveForDistance(24, 90);
	wait1Msec(1000);
	driveForDistance(-24, 90);
}

void Autonomous2() {
	//driveForDistance(24, 90);
	turnRightDeg(90, 127);
}

void Autonomous3() {
	driveForDistance(24, 90);
	turnLeft(90);
}

void Autonomous4() {
	driveForDistance(24, 90);
	turnRight(90);
	turnLeft(90);
	driveForDistance(-24, 90);
}
