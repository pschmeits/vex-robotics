
void userDrive(int threshold) {
	if(vexRT[Ch3] > threshold || vexRT[Ch3] < -threshold || vexRT[Ch4] > threshold || vexRT[Ch4] < -threshold) {
		if(vexRT[Btn8D] == 1) {
			motor[driveFL] = (vexRT[Ch3] + vexRT[Ch4])/2;
			motor[driveFR] = (vexRT[Ch3] - vexRT[Ch4])/2;
			motor[driveBL] = (vexRT[Ch3] + vexRT[Ch4])/2;
			motor[driveBR] = (vexRT[Ch3] - vexRT[Ch4])/2;
		}
		else {
			if(vexRT[Ch3] > threshold || vexRT[Ch3] < -threshold && !(vexRT[Ch4] > threshold) && !(vexRT[Ch4] < -threshold)) {
		    motor[driveFL] = vexRT[Ch3];
		    motor[driveFR] = vexRT[Ch3];
		    motor[driveBL] = vexRT[Ch3];
		    motor[driveBR] = vexRT[Ch3];
		  }
		  else if(vexRT[Ch4] > threshold || vexRT[Ch4] < -threshold && !(vexRT[Ch3] > threshold) && !(vexRT[Ch3] < -threshold)) {
		    motor[driveFL] = vexRT[Ch4];
		    motor[driveFR] = -vexRT[Ch4];
		    motor[driveBL] = vexRT[Ch4];
		    motor[driveBR] = -vexRT[Ch4];
		  }
		  else {
		  	motor[driveFL] = (vexRT[Ch3] + vexRT[Ch4]);
				motor[driveFR] = (vexRT[Ch3] - vexRT[Ch4]);
				motor[driveBL] = (vexRT[Ch3] + vexRT[Ch4]);
				motor[driveBR] = (vexRT[Ch3] - vexRT[Ch4]);
			}
	  }
	}
	else if(vexRT[Ch1] > threshold || vexRT[Ch1] < -threshold || vexRT[Ch2] > threshold || vexRT[Ch2] < -threshold) {
		if(vexRT[Ch1] > threshold || vexRT[Ch1] < -threshold && !(vexRT[Ch2] > threshold) && !(vexRT[Ch2] < -threshold)) {
	    motor[driveFL] = (vexRT[Ch1])/4;
			motor[driveFR] = (-vexRT[Ch1])/4;
			motor[driveBL] = (vexRT[Ch1])/4;
			motor[driveBR] = (-vexRT[Ch1])/4;
		}
		else if(vexRT[Ch2] > threshold || vexRT[Ch2] < -threshold && !(vexRT[Ch1] > threshold) && !(vexRT[Ch1] < -threshold)) {
    	motor[driveFL] = (vexRT[Ch2])/4;
			motor[driveFR] = (vexRT[Ch2])/4;
			motor[driveBL] = (vexRT[Ch2])/4;
			motor[driveBR] = (vexRT[Ch2])/4;
		}
	}
  else {
  	motor[driveFL] = 0;
    motor[driveFR] = 0;
    motor[driveBL] = 0;
    motor[driveBR] = 0;
	}
}

void btnMotor(short inputUP, short inputDOWN, short nMotor, int power) {
	if(vexRT[inputUP] == 1 && vexRT[inputDOWN] == 0)
		motor[nMotor] = -power;
	else if(vexRT[inputDOWN] == 1 && vexRT[inputUP] == 0)
		motor[nMotor] = power;
	else
		motor[nMotor] = 0;
}
