#include <Arduino.h>
#include "initialization.h"

const int BASE_SPEED_HIGH = 100;
const int BASE_SPEED_LOW = 20;
const int ACTUATOR_1_SPEED_HIGH = 250;
const int ACTUATOR_1_SPEED_LOW = 50;
const int ACTUATOR_2_SPEED_HIGH = 250;
const int ACTUATOR_2_SPEED_LOW = 50;
const int WRIST_SPEED_HIGH = 100;
const int WRIST_SPEED_LOW = 20;
const int ROTATION_360_SPEED_HIGH = 100;
const int ROTATION_360_SPEED_LOW = 20;
const int GRIPPER_SPEED_HIGH = 200;
const int GRIPPER_SPEED_LOW = 50;

void arm_pin_config()
{
    for (int i = 1; i <= 6; i++)
    {
        pinMode(i, OUTPUT);
    }
}

void low_initial_shutdown()
{
    for (int i = 1; i <= 6; i++)
    {
        digitalWrite(i, LOW);
    }
}