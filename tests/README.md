# Tests (directory)
This directory contains multiple tests for jetcar. I strongly recommend to run them after assembling your car to check basic functionalities of the car.

## Servo test sketch
This sketch uses Servo.h arduino library to control servo motor that is responsible for steering the driection fo the car. You can think about it as the steering wheel of the car. This is how servo looks like:

<p align="center">
    <img src="./assets/servo-test.gif" width="300"/>
</p>

> The goal of this test was to determine the optimal steering range for the car. We don't want it to break steering mechanism! 
> The steering wheel range is from 80 to 120 degrees, 100 degree sets wheels straight.