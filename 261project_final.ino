#include <Servo.h>

const int emgPin = A1;  // Analog input pin for EMG signal
const int motorPin = 9;
const int buttonPin = 4;
int direction = 0;
int count;

Servo myservo;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Wait for serial port to connect
  while (!Serial) {
    delay(10);
  }
  myservo.attach(motorPin); 
  
  // Enable the serial plotter
  Serial.println("#A1");
}

void loop() {
  // Read the EMG signal
  int emgValue = analogRead(emgPin);
  
  // Send the voltage value to the serial plotter
  Serial.println(emgValue);
  
  // Small delay to control the plotter update rate
  delay(100);

  if (emgValue > 60) 
  {
    if(myservo.read() == 0 || myservo.read() == 180 ){
      myservo.write(92);
      delay(1000);
    }
    else{
      myservo.write(direction);
      delay(1000);
    }

 }
 
 if(digitalRead(buttonPin)==HIGH && myservo.read() == 92){
    count++;
    delay(500);
 }
 if(count%2==0){
   direction = 0;
 } else {
   direction = 180;
 }

 //Serial.println(count);
}
