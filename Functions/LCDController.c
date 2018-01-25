
const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;

int codeSelected = 0;

int getCodeSelection()
{
	return codeSelected;
}

//Wait for Press--------------------------------------------------
void waitForPress()
{
	while(nLCDButtons == 0){}
	//clearTimer(T4);
	wait1Msec(5);
}
//----------------------------------------------------------------

//Wait for Release------------------------------------------------
void waitForRelease()
{
	while(nLCDButtons != 0){}
	wait1Msec(5);
}

//bool isHeldFor(short btn, int ms)
//{
//	clearTimer(T3);
//	while(nLCDButtons == btn) {
//		if(time1[T3] >= ms)
//			return true;
//	}
//	wait1Msec(5);
//	return false;
//}

void displayBattery()
{
	string mainBattery, backupBattery;

	while(nLCDButtons != 2)
	{
		clearLCDLine(0);											// Clear line 1 (0) of the LCD
		clearLCDLine(1);											// Clear line 2 (1) of the LCD

		//Display the Primary Robot battery voltage
		displayLCDString(0, 0, "Primary: ");
		sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V'); //Build the value to be displayed
		displayNextLCDString(mainBattery);

		//Display the Backup battery voltage
		displayLCDString(1, 0, "Secondary: ");
		sprintf(backupBattery, "%1.2f%c", SensorValue[battery2]/283.2, 'V');	//Build the value to be displayed
		displayNextLCDString(backupBattery);

		//Short delay for the LCD refresh rate
		wait1Msec(100);
	}
	wait1Msec(250);
}

void codeChooser()
{
	int count = 0;

	//------------- Beginning of User Interface Code ---------------
	//Clear LCD
	clearLCDLine(0);
	clearLCDLine(1);
	//Loop while center button is not pressed
	//while(isHeldFor(centerButton, 1000) == false)
	//{
	while(nLCDButtons != centerButton) {
		//Switch case that allows the user to choose from 4 different options
		switch(count){
			case 0:
				//Display first choice
				displayLCDCenteredString(0, "F-12");
				displayLCDCenteredString(1, "<   Enter   >");
				waitForPress();
				//Increment or decrement "count" based on button press
				if(nLCDButtons == leftButton) {
					waitForRelease();
					count = 3;
				}
				else if(nLCDButtons == rightButton) {
					waitForRelease();
					count++;
				}
				break;
			case 1:
				//Display second choice
				displayLCDCenteredString(0, "F-12, T-R");
				displayLCDCenteredString(1, "<   Enter   >");
				waitForPress();
				//Increment or decrement "count" based on button press
				if(nLCDButtons == leftButton) {
					waitForRelease();
					count--;
				}
				else if(nLCDButtons == rightButton) {
					waitForRelease();
					count++;
				}
				break;
			case 2:
				//Display third choice
				displayLCDCenteredString(0, "F-12, T-L");
				displayLCDCenteredString(1, "<   Enter   >");
				waitForPress();
				//Increment or decrement "count" based on button press
				if(nLCDButtons == leftButton) {
					waitForRelease();
					count--;
				}
				else if(nLCDButtons == rightButton) {
					waitForRelease();
					count++;
				}
				break;
			case 3:
				//Display fourth choice
				displayLCDCenteredString(0, "F-12,T-R,T-L,B-12");
				displayLCDCenteredString(1, "<   Enter   >");
				waitForPress();
				//Increment or decrement "count" based on button press
				if(nLCDButtons == leftButton) {
					waitForRelease();
					count--;
				}
				else if(nLCDButtons == rightButton) {
					waitForRelease();
					count = 0;
				}
				break;
			default:
				count = 0;
				break;
		}
		EndTimeSlice();
	}
	codeSelected = count;
	wait1Msec(250);
}

//void soundSelect() {
//	while(true) {

//	}
//}

void MissionImpossible() {
  //        100 = Tempo
  //          6 = Default octave
  //    Quarter = Default note length
  //        10% = Break between notes
  //
  playTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
  playTone(  933,    7); wait1Msec(  75);  // Note(D#, Duration(32th))
  playTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
  playTone(  933,    7); wait1Msec(  75);  // Note(D#, Duration(32th))
  playTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
  playTone(  933,    7); wait1Msec(  75);  // Note(D#, Duration(32th))
  playTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
  playTone(  933,    7); wait1Msec(  75);  // Note(D#, Duration(32th))
  playTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
  playTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
  playTone(  933,    7); wait1Msec(  75);  // Note(D#, Duration(32th))
  playTone(  988,    7); wait1Msec(  75);  // Note(E, Duration(32th))
  playTone( 1047,    7); wait1Msec(  75);  // Note(F, Duration(32th))
  playTone( 1109,    7); wait1Msec(  75);  // Note(F#, Duration(32th))
  playTone( 1175,    7); wait1Msec(  75);  // Note(G, Duration(32th))
  playTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
  playTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
  playTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
  playTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
  playTone( 1398,   14); wait1Msec( 150);  // Note(A#, Duration(16th))
  playTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
  playTone(  784,   14); wait1Msec( 150);  // Note(C, Duration(16th))
  playTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
  playTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
  playTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
  playTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
  playTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
  playTone( 1047,   14); wait1Msec( 150);  // Note(F, Duration(16th))
  playTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
  playTone( 1109,   14); wait1Msec( 150);  // Note(F#, Duration(16th))
  playTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
  playTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
  playTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
  playTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
  playTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
  playTone( 1398,   14); wait1Msec( 150);  // Note(A#, Duration(16th))
  playTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
  playTone(  784,   14); wait1Msec( 150);  // Note(C, Duration(16th))
  playTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
  playTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
  playTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
  playTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
  playTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
  playTone( 1047,   14); wait1Msec( 150);  // Note(F, Duration(16th))
  playTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
  playTone( 1109,   14); wait1Msec( 150);  // Note(F#, Duration(16th))
  playTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
  playTone( 1398,   14); wait1Msec( 150);  // Note(A#, Duration(16th))
  playTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
  playTone(  880,  108); wait1Msec(1200);  // Note(D, Duration(Half))
  playTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
  playTone( 1398,   14); wait1Msec( 150);  // Note(A#, Duration(16th))
  playTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
  playTone(  831,  108); wait1Msec(1200);  // Note(C#, Duration(Half))
  playTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
  playTone( 1398,   14); wait1Msec( 150);  // Note(A#, Duration(16th))
  playTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
  playTone(  784,  108); wait1Msec(1200);  // Note(C, Duration(Half))
  playTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
  playTone(  932,   14); wait1Msec( 150);  // Note(A#5, Duration(16th))
  playTone(  784,   14); wait1Msec( 150);  // Note(C, Duration(16th))
  return;
}


//void autonomousOptions() {
//	int selection = 0;
//	while(isHeldFor(centerButton, 1000)) {
//		while(nLCDButtons != centerButton) {
//			switch(selection) {
//				case 0:
//					displayLCDCenteredString(0, "Code Select");
//					displayLCDCenteredString(1, "");
//					waitForPress();
//					//Increment or decrement "count" based on button press
//					if(nLCDButtons == leftButton) {
//						waitForRelease();
//						count = 1;
//					}
//					else if(nLCDButtons == rightButton) {
//						waitForRelease();
//						count++;
//					}
//					break;
//				case 1:
//					displayLCDCenteredString(0, "");
//					displayLCDCenteredString(1, "");
//					waitForPress();
//					//Increment or decrement "count" based on button press
//					if(nLCDButtons == leftButton) {
//						waitForRelease();
//						count = 1;
//					}
//					else if(nLCDButtons == rightButton) {
//						waitForRelease();
//						count++;
//					}
//					break;
//			}

//		}
//	}
//}

//task timedBacklight() {
//	while(time1[T4] <= 5000) {
//		bLCDBacklight = true;
//	}
//	bLCDBacklight = false;
//}

task LCDController() {
	bLCDBacklight = true;
	int count = 0;
	while(true) {
		wait1Msec(50);
		//------------- Beginning of User Interface Code ---------------
		//Clear LCD
		clearLCDLine(0);
		clearLCDLine(1);
		//Loop while center button is not pressed
		while(nLCDButtons != centerButton) {
			//Switch case that allows the user to choose from 4 different options
			switch(count) {
				case 0:
					//Display first choice
					displayLCDCenteredString(0, "Battery");
					displayLCDCenteredString(1, "<   Enter   >");
					waitForPress();
					//Increment or decrement "count" based on button press
					if(nLCDButtons == leftButton) {
						waitForRelease();
						count = 1;
					}
					else if(nLCDButtons == rightButton) {
						waitForRelease();
						count++;
					}
					break;
				case 1:
					//Display second choice
					displayLCDCenteredString(0, "Autonomous");
					displayLCDCenteredString(1, "<   Enter   >");
					waitForPress();
					//Increment or decrement "count" based on button press
					if(nLCDButtons == leftButton) {
						waitForRelease();
						count--;
					}
					else if(nLCDButtons == rightButton) {
						waitForRelease();
						count++;
					}
					break;
				case 2:
					//Display third choice
					displayLCDCenteredString(0, "Speaker");
					displayLCDCenteredString(1, "<   Enter   >");
					waitForPress();
					//Increment or decrement "count" based on button press
					if(nLCDButtons == leftButton) {
						waitForRelease();
						count--;
					}
					else if(nLCDButtons == rightButton) {
						waitForRelease();
						count = 0;
					}
					break;
				default:
					count = 0;
					break;
			}
			EndTimeSlice();
		}
		wait1Msec(250);
		if(count == 0) {
			displayBattery();
		}
		else if(count == 1) {
			codeChooser();
		}
		else if(count == 2) {
			MissionImpossible();
		}
	}
}
