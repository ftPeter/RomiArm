/*
  RomiArm

  Demonstration of Pololu Romi 3-servo arm.

  October 20, 2018
  Peter F. Klemperer

  This example code is in the public domain.

  Gripper PWM: 500 (open) 2400 (closed)
  Shoulder PWM: 1000 (raised, 60 deg), 1900 (lowered, 0 deg)
  Wrist PWM: 1200 (down, 0 deg), 1900 (up, 110 deg)

  NEXT TASKS:
  * Add printing for sampling potentiometer tap inputs
  * Add methods for converting potentiometer taps to positions

  http://github.com/ftPeter/RomiArm
*/

#include <Servo.h>


// These pins correspond to my 328PB configuration
// SERVO PINS
#define GRIPPER_SERVO_PIN (10)
#define WRIST_SERVO_PIN (11)
#define SHOULDER_SERVO_PIN (3)
// SERVO POTENTIOMETER TAP PINS
#define GRIPPER_POT_PIN (A4)
#define WRIST_POT_PIN (A5)
#define SHOULDER_POT_PIN (A6)

Servo gripper_servo;
Servo wrist_servo;
Servo shoulder_servo;

int gripper_pot;
int wrist_pot;
int shoulder_pot;

void setup() {
  gripper_servo.attach(GRIPPER_SERVO_PIN);
  wrist_servo.attach(WRIST_SERVO_PIN);
  shoulder_servo.attach(SHOULDER_SERVO_PIN);

  pinMode(GRIPPER_POT_PIN, INPUT);
  pinMode(WRIST_POT_PIN, INPUT);
  pinMode(SHOULDER_POT_PIN, INPUT);
}

void loop() {

  // move the gripper up and open
  for (int i = 0; i < 100; i++) {
    int gripper_opening_mm = map( i, 0, 99, 0, 32 );
    int gripper_pwm = gripper_opening_to_pwm( gripper_opening_mm );

    int wrist_angle_deg = map( i, 0, 99, 0, 110 );
    int wrist_pwm = wrist_angle_to_pwm( wrist_angle_deg );

    int shoulder_angle_deg = map( i, 0, 99, 0, 60 );
    int shoulder_pwm = shoulder_angle_to_pwm( shoulder_angle_deg );

    gripper_servo.write(gripper_pwm);
    wrist_servo.write(wrist_pwm);
    shoulder_servo.write(shoulder_pwm);
  }

  // move the gripper down and closed
  for (int i = 99; i >= 0; i--) {
    int gripper_opening_mm = map( i, 0, 99, 0, 32 );
    int gripper_pwm = gripper_opening_to_pwm( gripper_opening_mm );

    int wrist_angle_deg = map( i, 0, 99, 0, 110 );
    int wrist_pwm = wrist_angle_to_pwm( wrist_angle_deg );

    int shoulder_angle_deg = map( i, 0, 99, 0, 60 );
    int shoulder_pwm = shoulder_angle_to_pwm( shoulder_angle_deg );

    gripper_servo.write(gripper_pwm);
    wrist_servo.write(wrist_pwm);
    shoulder_servo.write(shoulder_pwm);
  }
}
