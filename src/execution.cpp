#include <Arduino.h>
#include "execution.h"
#include "pinconfig.h"
#include "initialization.h"

void execute_command(String token)
{
    int first_seperation = token.indexOf('&');
    int second_seperation = token.indexOf('&', first_seperation + 1);

    if (first_seperation == -1 || second_seperation == -1)
    {
        return;
    }

    String actuator_name = token.substring(0, first_seperation);
    String direction = token.substring(first_seperation + 1, second_seperation);
    String speed_string = token.substring(second_seperation + 1);

    int speed = speed_string.toInt();

    if (actuator_name == "BASE")
    {
        if (direction == "RIGHT")
            base_right(speed);
        else if (direction == "LEFT")
            base_left(speed);
    }
    else if (actuator_name == "ACTUATOR1")
    {
        if (direction == "UP")
            actuator_1_up(speed);
        else if (direction == "DOWN")
            actuator_1_down(speed);
    }
    else if (actuator_name == "ACTUATOR2")
    {
        if (direction == "UP")
            actuator_2_up(speed);
        else if (direction == "DOWN")
            actuator_2_down(speed);
    }
    else if (actuator_name == "WRIST")
    {
        if (direction == "UP")
            wrist_up(speed);
        else if (direction == "DOWN")
            wrist_down(speed);
    }
    else if (actuator_name == "ROTATION")
    {
        if (direction == "CLOCK")
            rotation_clockwise(speed);
        else if (direction == "ANTI")
            rotation_anticlockwise(speed);
    }
    else if (actuator_name == "GRIPPER")
    {
        if (direction == "EXTRACT")
            gripper_extract(speed);
        else if (direction == "RETRACT")
            gripper_retract(speed);
    }
}

void base_right(int temp_speed)
{
    int speed = map(temp_speed, 0, 100, BASE_SPEED_LOW, BASE_SPEED_HIGH);
    analogWrite(BASE_RIGHT, speed);
    analogWrite(BASE_LEFT, 0);
}

void base_left(int temp_speed)
{
    int speed = map(temp_speed, 0, 100, BASE_SPEED_LOW, BASE_SPEED_HIGH);
    analogWrite(BASE_LEFT, speed);
    analogWrite(BASE_RIGHT, 0);
}

void actuator_1_up(int temp_speed)
{
    int speed = map(temp_speed, 0, 100, ACTUATOR_1_SPEED_LOW, ACTUATOR_1_SPEED_HIGH);
    analogWrite(ACTUATOR_1_UP, speed);
    analogWrite(ACTUATOR_1_DOWN, 0);
}

void actuator_1_down(int temp_speed)
{
    int speed = map(temp_speed, 0, 100, ACTUATOR_1_SPEED_LOW, ACTUATOR_1_SPEED_HIGH);
    analogWrite(ACTUATOR_1_DOWN, speed);
    analogWrite(ACTUATOR_1_UP, 0);
}

void actuator_2_up(int temp_speed)
{
    int speed = map(temp_speed, 0, 100, ACTUATOR_2_SPEED_LOW, ACTUATOR_2_SPEED_HIGH);
    analogWrite(ACTUATOR_2_UP, speed);
    analogWrite(ACTUATOR_2_DOWN, 0);
}

void actuator_2_down(int temp_speed)
{
    int speed = map(temp_speed, 0, 100, ACTUATOR_2_SPEED_LOW, ACTUATOR_2_SPEED_HIGH);
    analogWrite(ACTUATOR_2_DOWN, speed);
    analogWrite(ACTUATOR_2_UP, 0);
}

void wrist_up(int temp_speed)
{
    int speed = map(temp_speed, 0, 100, WRIST_SPEED_LOW, WRIST_SPEED_HIGH);
    analogWrite(WRIST_UP, speed);
    analogWrite(WRIST_DOWN, 0);
}

void wrist_down(int temp_speed)
{
    int speed = map(temp_speed, 0, 100, WRIST_SPEED_LOW, WRIST_SPEED_HIGH);
    analogWrite(WRIST_DOWN, speed);
    analogWrite(WRIST_UP, 0);
}

void rotation_clockwise(int temp_speed)
{
    int speed = map(temp_speed, 0, 100, ROTATION_360_SPEED_LOW, ROTATION_360_SPEED_HIGH);
    analogWrite(ROTATION_360_CLOCK, speed);
    analogWrite(ROTATION_360_ANTI_CLOCK, 0);
}

void rotation_anticlockwise(int temp_speed)
{
    int speed = map(temp_speed, 0, 100, ROTATION_360_SPEED_LOW, ROTATION_360_SPEED_HIGH);
    analogWrite(ROTATION_360_ANTI_CLOCK, speed);
    analogWrite(ROTATION_360_CLOCK, 0);
}

void gripper_extract(int temp_speed)
{
    int speed = map(temp_speed, 0, 100, GRIPPER_SPEED_LOW, GRIPPER_SPEED_HIGH);
    analogWrite(GRIPPER_EXTRACT, speed);
    analogWrite(GRIPPER_RETRACT, 0);
}

void gripper_retract(int temp_speed)
{
    int speed = map(temp_speed, 0, 100, GRIPPER_SPEED_LOW, GRIPPER_SPEED_HIGH);
    analogWrite(GRIPPER_RETRACT, speed);
    analogWrite(GRIPPER_EXTRACT, 0);
}
void stop()
{
    for (int i = 1; i <= 13; i++)
    {
        analogWrite(i, 0);
    }
}
