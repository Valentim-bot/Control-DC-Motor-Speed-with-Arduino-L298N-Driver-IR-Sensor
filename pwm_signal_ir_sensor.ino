#include <ezButton.h>
int IRsensorDataPin = 8;
ezButton button(IRsensorDataPin); 
int enablePinB = 6; 
int IN2 = 7;


void setup() {
  Serial.begin(9600);
  button.setDebounceTime(100); 
  button.setCountMode(COUNT_FALLING);
  pinMode(IN2,OUTPUT);
  digitalWrite(IN2, HIGH);
  }

void loop() {
  button.loop();
  unsigned long countThroughIRsensor = button.getCount();
  
  if(countThroughIRsensor ==1){
    analogWrite(enablePinB, 255);
    }
 if(countThroughIRsensor == 2){
  analogWrite(enablePinB, 235);
  }
 if(countThroughIRsensor ==3){
  analogWrite(enablePinB, 205);
  }
 if(countThroughIRsensor == 4){
  analogWrite(enablePinB, 185);
  }
 if(countThroughIRsensor ==5){
  analogWrite(enablePinB, 165);
  }
 if(countThroughIRsensor == 6){
  analogWrite(enablePinB,145);
  }
 if(countThroughIRsensor == 7){
    button.resetCount();
    analogWrite(enablePinB, 0);
  }
    Serial.println(countThroughIRsensor);}
