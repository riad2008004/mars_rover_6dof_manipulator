#include <Arduino.h>
#include "initialization.h"
#include "pinconfig.h"
#include "execution.h"

#define TOKEN_EXECUTION_TIME 200

void setup()
{
  Serial.begin(9600);
  arm_pin_config();
  low_initial_shutdown();
}

void loop()
{
  if (Serial.available() > 0)
  {
    String token = Serial.readStringUntil('\n');
    token.trim();
    execute_command(token);
    delay(TOKEN_EXECUTION_TIME);
    low_initial_shutdown();
  }
}