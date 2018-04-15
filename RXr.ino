//DynamicSpeedGovernor v--0.1.1
//Rxr
//coded as part of academic project @ MET's school of engineering,Mala
//by <prinzpiuz><prinzpiuz@disroot.org>
//under the  guidance of <prof Ramji dr>
//for more details https://github.com/prinzpiuz/Dynamic-speed-governer
//or feel free to ping @ <prinzpiuz@disroot.org>
#include <RCSwitch.h>
#include <Stepper.h>
#define STEPS 48
//const int stepsPerRevolution = 500;

RCSwitch mySwitch = RCSwitch();
Stepper myStepper(STEPS, 3, 5, 4, 6);


void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  myStepper.setSpeed(200);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
}

void loop() {
  if (mySwitch.available()) {
    digitalWrite(LED_BUILTIN, HIGH); 
   myStepper.step(-450);
  // myStepper.step(400);
   delay(2000);
  myStepper.step(600);
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
 mySwitch.resetAvailable();
  }
  digitalWrite(LED_BUILTIN, LOW); 
}
