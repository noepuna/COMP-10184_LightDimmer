//I, Noe Puna, 000781646, I acknowledge that this my own work and no other
// person's work has been copied without acknowledgement.

#include <Arduino.h> 

int dialPosition = 0;
bool bState = false;

//buton states
#define BTN_UP 0
#define BTN_DOWN 1

// button levels
#define DOWN 0
#define Up 1

int iBtnState = BTN_UP;
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
 
  // configure pin D5 as digital input - this is the pushbutton 
  pinMode(D5, INPUT_PULLUP); 

  // configure pin D4 as a digital output - this is the LED 
  pinMode(D4, OUTPUT); 
 
  // set default PWM range 
  analogWriteRange(1023); 
} 
 
 
void loop() { 
   

  if(digitalRead(D5) == DOWN){
    if(iBtnState == BTN_UP){
      iBtnState = BTN_DOWN;
      // flip state
      bState = !bState;
    }
  } else {
    iBtnState = BTN_UP;
  }

  if (bState == false) {
    // light is off
    analogWrite(D4, 1023);
  } else {
    // light is on and controlled by variable resistor
    // read digitized value from the D1 Mini's A/D convertor 
    dialPosition = analogRead(A0);
    analogWrite(D4, dialPosition); 
  }

  delay(1);

  //Serial.println(dialPosition);

  
   

 
} 