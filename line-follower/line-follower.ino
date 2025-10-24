/**
 * @file line-follower.ino
 * @brief Main file of the arduino project (contains setup and loop functions).
 */

#include <Arduino_FreeRTOS.h>
#include <Arduino.h>
#include "us.h"

/**
 * @brief Speed of the serial communication, measured in bits per second.
 */
const int BAUD_RATE = 9600;

/**
 * @brief Arduino setup function.
 */
void setup() {
  Serial.begin(BAUD_RATE);
  
  xTaskCreate(us::detectObstacleTask, "Obstacle detection", 128, NULL, 1, NULL);
}

/**
 * @brief Arduino loop function (unused).
 */
void loop() { }
