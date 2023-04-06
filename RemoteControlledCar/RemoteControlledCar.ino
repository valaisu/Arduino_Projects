#include <IRremote.h>

IRrecv IR(A0);
long int resent = 0; //Store the most recent command recieved
long int input = 0;
long int up = 0XE718FF00;
// for the IR reciever, connect + to +, - to (common) GND, and S to A0

int speedPin = 11; //EN1
int dir1 = 10; //IN1
int dir2 = 9; //IN2
int mSpeed = 255; // controls the motorspeed
// values between 0 and 255, although the motor might not run on low numbers at all



void setup() {
  // put your setup code here, to run once:
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  IR.enableIRIn();
  Serial.begin(9600);
}

void loop() {

  digitalWrite(dir1, LOW);
  if (resent == up) {
    digitalWrite(dir2, HIGH);
  }
  else {
    digitalWrite(dir2, LOW);    
  }
  
  analogWrite(speedPin, mSpeed);


  
  if (IR.decode()) {
    input = IR.decodedIRData.decodedRawData;
    if (input != 0) {
      resent = input;
    }
    Serial.print(resent);
    Serial.print(" ");
    Serial.println(up);
    
        
    delay(1000);
    IR.resume();
  }
}

//Buttons
//
//BA45FF00 1
//B946FF00 2
//B847FF00 3
//BB44FF00 4
//BF40FF00 5
//BC43FF00 6
//F807FF00 7
//EA15FF00 8
//F609FF00 9
//E916FF00 *
//E619FF00 0
//F20DFF00 #
//C5BF34DD u
//F708FF00 l
//E31CFF00 ok
//A55AFF00 r
//AD52FF00 d
