/**
 * @file l298n.h
 * @brief Implementations of the L298n module for motor control.
 */

#include <Arduino.h>
#include "l298n.h"

/**
 * @brief Constructor for L298n class.
 *
 * This constructor initializes the default pins 
 * for the motor driver IC.
 */
motors::L298n::L298n() {
  ena = motors::ENA;
  enb = motors::ENB;
  in1 = motors::IN1;
  in2 = motors::IN2;
  in3 = motors::IN3;
  in4 = motors::IN4;
}

/**
 * @brief Sets the direction of the left motor
 *
 * @param direction The direction to set. Use FORWARD (false) or BACKWARD (true)
 */
void motors::L298n::setLeftMotorDirection(bool direction) {
  if (direction == FORWARD) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  } 
  
  else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }
}

/**
 * @brief Sets the speed of the left motor
 *
 * @param speed The speed to set. Value range: 0 (stop) to 255 (maximum speed)
 */
void motors::L298n::setLeftMotorSpeed(int speed) {
  analogWrite(ena, constrain(speed, 0, 255));
}

/**
 * @brief Sets the direction of the right motor
 *
 * @param direction The direction to set. Use FORWARD (false) or BACKWARD (true)
 */
void motors::L298n::setRightMotorDirection(bool direction) {
  if (direction == FORWARD) {
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  } 
  
  else {
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
}

/**
 * @brief Sets the speed of the right motor
 *
 * @param speed The speed to set. Value range: 0 (stop) to 255 (maximum speed)
 */
void motors::L298n::setRightMotorSpeed(int speed) {
  analogWrite(enb, constrain(speed, 0, 255));
}