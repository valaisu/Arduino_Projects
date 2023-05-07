#include <IRremote.h>

IRrecv IR(A5);
long int resent = 0; //Store the most recent command recieved
long int input = 0;
long int up = 0XE718FF00; // decoded values of all buttons at the end of the code
long int down = 0XAD52FF00;
// for the IR reciever, connect + to +, - to (common) GND, and S to A0

int speedPin = 11; //EN1 = speed
int dir1L = 10; //IN1 = direction1
int dir2L = 9; //IN2 = direction2
int mSpeed = 255; // controls the motorspeed
// values between 0 and 255, although the motor might not run on low numbers at all
// in the current design the speed cannot be altered (only the value 255 moves the engine)
int d = 0;


void setup() {

  pinMode(speedPin, OUTPUT);
  pinMode(dir1L, OUTPUT);
  pinMode(dir2L, OUTPUT);
  IR.enableIRIn();
  Serial.begin(9600);
}

void loop() {


  if (IR.decode()) {
    input = IR.decodedIRData.decodedRawData;
    if (input != 0) {
      // if new input is same as the previous one, decode gives value of 0
      resent = input;
    }
    // for debugging
    Serial.print(resent, HEX);
    Serial.print(" ");
    Serial.println(up, HEX);

    delay(50);
    IR.resume();
  }

  if (resent == up) {
    // goes forward
    digitalWrite(dir1L, LOW);
    digitalWrite(dir2L, HIGH);
  }
    // goes backwards
  else if (resent == down) {
    digitalWrite(dir1L, HIGH);
    digitalWrite(dir2L, LOW);
  }
  else {
    // halts
    digitalWrite(dir1L, LOW);
    digitalWrite(dir2L, LOW);
  }

  analogWrite(speedPin, mSpeed);

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
