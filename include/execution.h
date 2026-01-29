#ifndef EXECUTION_H
#define EXECUTION_H

#include <Arduino.h>

void execute_command(String token);

void base_right(int speed);
void base_left(int speed);

void actuator_1_up(int speed);
void actuator_1_down(int speed);

void actuator_2_up(int speed);
void actuator_2_down(int speed);

void wrist_up(int speed);
void wrist_down(int speed);

void rotation_clockwise(int speed);
void rotation_anticlockwise(int speed);

void gripper_extract(int speed);
void gripper_retract(int speed);

#endif