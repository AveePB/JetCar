/**
 * @file l298n.h
 * @brief Definitions of the L298n module for motor control.
 */

#pragma once
#ifndef L298N_H
#define L298N_H

namespace motors {

  /**
   * @brief Indicates forward direction
   */
  const bool FORWARD = false;
  
  /**
   * @brief Indicates backward direction
   */ 
  const bool BACKWARD = true;
  
  /**
   * @brief Enable pin for motor A (ENA)
   */
  const int ENA = 9;
  
  /**
   * @brief Enable pin for motor B (ENB)
   */
  const int ENB = 10;
  
  /**
   * @brief Input pin 1 for motor A (IN1)
   */
  const int IN1 = 8;
  
  /**
   * @brief Input pin 2 for motor A (IN2)
   */
  const int IN2 = 11;
  
  /**
   * @brief Input pin 3 for motor B (IN3)
   */
  const int IN3 = 12;
  
  /**
   * @brief Input pin 4 for motor B (IN4)
   */
  const int IN4 = 13;

  /**
   * @brief Class representing a l298n module.
   *
   * This class provides functionality to control direction
   * and speed of the motors using the L298N motor driver IC.
   */
  class L298n {
    private:
      
      /**
       * @brief Enable pin for motor A (ENA)
       */ 
      int ena;
      
      /**
       * @brief Enable pin for motor B (ENB)
       */
      int enb;
      
      /**
       * @brief Input pin 1 for motor A (IN1)
       */
      int in1;
      
      /**
       * @brief Input pin 2 for motor A (IN2)
       */
      int in2;
      
      /**
       * @brief Input pin 3 for motor B (IN3)
       */
      int in3;
      
      /**
       * @brief Input pin 4 for motor B (IN4)
       */
      int in4;
    
    public:
      
      /**
       * @brief Constructor for L298n class.
       *
       * This constructor initializes the default pins 
       * for the motor driver IC.
       */
      L298n();

      /**
       * @brief Sets the direction of the left motor
       *
       * @param direction The direction to set. Use FORWARD (false) or BACKWARD (true)
       */
      void setLeftMotorDirection(bool direction);

      /**
       * @brief Sets the speed of the left motor
       *
       * @param speed The speed to set. Value range: 0 (stop) to 255 (maximum speed)
       */
      void setLeftMotorSpeed(int speed);

      /**
       * @brief Sets the direction of the right motor
       *
       * @param direction The direction to set. Use FORWARD (false) or BACKWARD (true)
       */
      void setRightMotorDirection(bool direction);

      /**
       * @brief Sets the speed of the right motor
       *
       * @param speed The speed to set. Value range: 0 (stop) to 255 (maximum speed)
       */
      void setRightMotorSpeed(int speed);
  };
};

#endif
