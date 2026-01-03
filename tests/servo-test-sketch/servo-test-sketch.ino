// Lbiraries
#include <Servo.h>

// Steering pin
#define STEERING_PIN 11
#define MIN_RANGE 60
#define MAX_RANGE 120

// Create objects
Servo servo;

// Set up servo and serial communication
void setup() {
  Serial.begin(9600);
  servo.attach(STEERING_PIN);
}

// Run program
void loop() {
  // Set min range position
  int degree = MIN_RANGE;

  // Move to max range position
  while (degree <= MAX_RANGE) {
    Serial.println(degree);
    servo.write(degree+=5);
    delay(500);
  }
}