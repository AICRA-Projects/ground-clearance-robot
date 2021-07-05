

// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006
#include <Wire.h>
int in1 = 11;  //Motor A 
int in2 = 10;   //Motor A 
int in3 = 9;  // Motor B
int in4 = 8;    //Motor B 
int enA = 6; // pwm Motor A 
int enB = 5;  // pwm Motor B
uint8_t x;
void setup() {
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
pinMode(enA,OUTPUT);
pinMode(enB,OUTPUT);
  Wire.begin(0x8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop() {
  Serial.println(x);
  if (x == 1){

    analogWrite(enA,250);
  analogWrite(enB,250);
digitalWrite(in1,0);
digitalWrite(in2,1);
digitalWrite(in3,1);
digitalWrite(in4,0);
Serial.println("turn: object");
 }
 else if(x == 2){
analogWrite(enA,120);
  analogWrite(enB,120);
digitalWrite(in1,1);
digitalWrite(in2,0);
digitalWrite(in3,1);
digitalWrite(in4,0);
Serial.println("Forward : no object");
 }
  else if(x == 3){
analogWrite(enA,250);
  analogWrite(enB,250);
digitalWrite(in1,0);
digitalWrite(in2,1);
digitalWrite(in3,0);
digitalWrite(in4,0);
Serial.println("left : object");
 }
  else if(x == 4){
  analogWrite(enA,250);
  analogWrite(enB,250);
digitalWrite(in1,0);
digitalWrite(in2,0);
digitalWrite(in3,0);
digitalWrite(in4,1);
Serial.println("Right : object");
 }
 else if(x == 5){
analogWrite(enA,220);
  analogWrite(enB,220);
digitalWrite(in1,1);
digitalWrite(in2,0);
digitalWrite(in3,0);
digitalWrite(in4,0);
Serial.println("frontleft : object");
 }
  else if(x == 6){
analogWrite(enA,220);
  analogWrite(enB,220);
digitalWrite(in1,0);
digitalWrite(in2,0);
digitalWrite(in3,1);
digitalWrite(in4,0);
Serial.println("frontright : object");
 }
   else if(x == 7){
analogWrite(enA,180);
  analogWrite(enB,180);
digitalWrite(in1,0);
digitalWrite(in2,1);
digitalWrite(in3,0);
digitalWrite(in4,1);
Serial.println("frontright left : object");
 }
 else if(x == 8){
  analogWrite(enA,120);
  analogWrite(enB,120);
digitalWrite(in1,1);
digitalWrite(in2,0);
digitalWrite(in3,1);
digitalWrite(in4,0);
Serial.println("right left: object");
 }
 else{
  //myservo.write(60);
 digitalWrite(in1,LOW);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,LOW);
 }
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int z) {
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    //Serial.print(c);         // print the character
  }
  x = Wire.read();    // receive byte as an integer
  Serial.println(x);
 // print the integer
 
}
