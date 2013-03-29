/*
  ON_OFF_DETECTION
  GitHub: https://github.com/edvler/Icinga_Nagios_Traffic_Light
  Web-Blog: http://www.edvler-blog.de/icinga_nagios_traffic_light_ampel
  
  Author: Matthias Maderer
  Date: 29.03.2013

  Info: Look at the Readme.txt or the Web-Blog
  
  How to setup?
  
  Step1:
  Setup your Hardware as shown on the pictures under the Fritzing folder! If you dont have the Fritzing folder look at the GitHub Link or the Blog!
  The shown setup is a simple Pull-up circuit. This means, if the resistance of the LDR high the value of analogRead would be high and goes near 1024.
  If the resistance of the LDR is low, the value is low and goes near 0.
  
  Step2:
  Set the analog input PIN you use. See analogPin variable.
  Upload this scetch on your arduino!
  
  Step3:
  Open the Serial Monitor. Maybe you have to reset your device with the reset button.
  Now place your signal light on front of the LDR and turn it on and off.
  You will see that the value differs significant when turned on or off.
  Note the aproximitly value for on and off on a paper.
  Keep in mind, that other light sources may influence!! 
  
  Step4:
  Change the lightOnBelow variable.
  Look at your paper for the value you noted when the light was on. You should set lightOnBelow about +100 higher.
  Example.   You noted a value of ~950 when the signal light was of.
             You noted a value of ~370 when the signal light was on.
             
  Then i would choose 500 for the lightOnBelow variable.
  
  Step5:
  Upload your scetch again. Now if you turn on the signal light, LED 13 on the arduino board also should light up and goes off if you turn off your signal light.
  
 */

// define the Arduino analog PIN
int analogPin = A7; 

// below which value is the "detection" light off
int lightOnBelow = 300;

// How many milliseconds the value needs to be stable above or below the lightOnBelow variable the to be treated as change from 0 (off) to 1 (on) or 1 to 0
// This prevents the variable deviceOn from flapping when the light is turned on or off.
// As higher the value as slower is the reaction to light changes.
int ms_no_change = 300; 

// Variable for on/off
byte deviceOn = 0;


// 3 Variables for flapping protection.
byte state; // actual state value for this loop pass
byte last_state; // value from the last loop pass
unsigned long last_change; // how many milliseconds passed since the last change

int onoffstatus_LED = 13;

// the setup routine runs once when you press reset:
void setup() {
  // set the status LED to output.
  pinMode(onoffstatus_LED, OUTPUT); 
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}


// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin:
  int sensorValue = analogRead(analogPin);
  
  // check if the value is below the value of the lightOnBelow variable
  if (sensorValue < lightOnBelow) {
    state = 1;   // yes, its below!
  } else {
    state = 0;   // no, its above! 
  }
  
  // is the state of the last loop pass the same
  if (state != last_state) {
      // if not set last_change to now!
      last_change = millis();
  }
  
  // check if now - last_change is bigger than ms_no_change
  if ((millis() - last_change) > ms_no_change) {
    // if its true, the value is stable! Set deviceOn to the actual state!
    deviceOn = state;
  } 
  
  // save the state of this loop pass for the next loop pass
  last_state = state;
  
  // print the actual state
  Serial.println(sensorValue);
  
  if (deviceOn == 1) {
    digitalWrite(onoffstatus_LED,HIGH); 
  } else {
    digitalWrite(onoffstatus_LED,LOW); 
  }
}
