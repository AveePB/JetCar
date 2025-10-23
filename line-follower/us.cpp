/**
 * @file us.cpp
 * @brief Implementation of the Ultrasonic Sensor module for obstacle detection.
 */

#include <Arduino_FreeRTOS.h>
#include <Arduino.h>
#include "us.h"

/**
 * @brief Construct a new Ultrasonic Sensor object.
 * 
 * Initializes the trigger and echo pins based on predefined constants.
 */
us::UltrasonicSensor::UltrasonicSensor() {
  trig = us::TRIG;
  echo = us::ECHO;
}

/**
 * @brief Measure the distance to the nearest obstacle.
 * 
 * Sends a 10µs pulse on the trigger pin and reads the echo pin.
 * Converts the pulse duration to distance in centimeters.
 * 
 * @return float Distance in centimeters
 */
float us::UltrasonicSensor::measureDistance() {
  // Send a 10µs pulse to trigger pin
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Read the echo pin (time in microseconds)
  long duration = pulseIn(echo, HIGH);

  // Convert to centimeters (speed of sound ~343 m/s)
  return duration * 0.0343 / 2;
}

/**
 * @brief FreeRTOS task to continuously detect obstacles.
 * 
 * Creates a local UltrasonicSensor object and repeatedly measures the distance.
 * If the measured distance is below the detection threshold, a message is
 * printed to the serial console. The task sleeps for 150ms between measurements.
 * 
 * @param pvParameters Pointer to task parameters (unused)
 */
void us::detectObstacleTask(void *pvParameters) {
  // Set up enviroment
  us::UltrasonicSensor sensor;
  float detectionRange = 30.0f; // In centimeters
  pinMode(us::TRIG, OUTPUT);
  pinMode(us::ECHO, INPUT);

  while (true) {
    float obstacleDistance = sensor.measureDistance();
    if (obstacleDistance <= detectionRange) {
      Serial.print("Obstacle detected: ");
      Serial.println(obstacleDistance);
    }
    // Force thread to sleep for 150ms
    vTaskDelay(150 / portTICK_PERIOD_MS); 
  }
}