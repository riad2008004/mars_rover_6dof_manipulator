#ifndef INITIALIZATION_H
#define INITIALIZATION_H

extern const int BASE_SPEED_HIGH;
extern const int BASE_SPEED_LOW;

extern const int ACTUATOR_1_SPEED_HIGH;
extern const int ACTUATOR_1_SPEED_LOW;

extern const int ACTUATOR_2_SPEED_HIGH;
extern const int ACTUATOR_2_SPEED_LOW;

extern const int WRIST_SPEED_HIGH;
extern const int WRIST_SPEED_LOW;

extern const int ROTATION_360_SPEED_HIGH;
extern const int ROTATION_360_SPEED_LOW;

extern const int GRIPPER_SPEED_HIGH;
extern const int GRIPPER_SPEED_LOW;

void arm_pin_config();
void low_initial_shutdown();

#endif