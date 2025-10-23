/**
 * @file us.h
 * @brief Definitions of the Ultrasonic Sensor module for obstacle detection.
 */

#pragma once
#ifndef US_H
#define US_H

namespace us {
  
  /**
   * @brief Pin connected to the ultrasonic sensor trigger.
   */
  const int TRIG = 5;

  /**
   * @brief Pin connected to the ultrasonic sensor echo.
   */
  const int ECHO = 6;

  /**
   * @brief Class representing an ultrasonic distance sensor.
   *
   * This class provides functionality to measure distances using
   * the TRIG and ECHO pins.
   */
  class UltrasonicSensor {
    private:
      int trig; ///< Trigger pin number
      int echo; ///< Echo pin number
    
    public:
      
      /**
       * @brief Construct a new Ultrasonic Sensor object.
       * 
       * Initializes the trigger and echo pins based on predefined constants.
       */
      UltrasonicSensor();

      /**
       * @brief Measure the distance to the nearest obstacle.
       * 
       * Sends a 10µs pulse on the trigger pin and reads the echo pin.
       * Converts the pulse duration to distance in centimeters.
       * 
       * @return float Distance in centimeters
       */
      float measureDistance();
  };
  
  /**
   * @brief FreeRTOS task to continuously detect obstacles.
   * 
   * Creates a local UltrasonicSensor object and repeatedly measures the distance.
   * If the measured distance is below the detection threshold, a message is
   * printed to the serial console. The task sleeps for 150ms between measurements.
   * 
   * @param pvParameters Pointer to task parameters (unused)
   */
  void detectObstacleTask(void *pvParameters);
};

#endif