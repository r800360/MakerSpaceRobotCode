////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <SoftwareSerial.h>
#define lfMotorPWM 5
#define lbMotorPWM 9
#define rfMotorPWM 6
#define rbMotorPWM 3
#define lfMotor1 A0
#define lfMotor2 A1
#define lbMotor1 12
#define lbMotor2 13
#define rfMotor1 A2
#define rfMotor2 A3
#define rbMotor1 2
#define rbMotor2 4

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
SoftwareSerial bluetooth (10, 11);
String message = "";
char c;
int xPos;
int yPos;
String pos;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup () {
  bluetooth.begin (38400);
  Serial.begin (38400);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop () {
  if (bluetooth.available () > 0) {
    c = bluetooth.read ();
    if (c == '\n') {
      pos = message.substring (1);
      while ( (message.startsWith ("x") && pos.toInt() < 10 && pos.toInt() > -10) || (message.startsWith ("y") && pos.toInt() < 10 && pos.toInt() < -10) ) {

      }
      if (message.startsWith ("x") && pos.toInt () < 200 && pos.toInt () > -200) {
        xPos = (pos.toInt ());
      }
      if (message.startsWith ("y") && pos.toInt () < 200 && pos.toInt () > -200) {
        yPos = (pos.toInt ());
      }
      Serial.print ("the x is ");
      Serial.print (xPos);
      Serial.print ("\t");
      Serial.print ("the y is ");
      Serial.println (yPos);
      message = "";
    }
    else {
      message = message + c;
    }
  }

/*  if (xPos > 0) {
    digitalWrite
  }*/
}
