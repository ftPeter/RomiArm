/*
  RomiArm

  Demonstration of Pololu Romi 3-servo arm.

  October 20, 2018
  Peter F. Klemperer

  This example code is in the public domain.

  Gripper PWM: 500 (open) 2400 (closed)
  Shoulder PWM: 1000 (raised, 60 deg), 1900 (lowered, 0 deg)
  Wrist PWM: 1200 (down, 0 deg), 1900 (up, 110 deg)

  http://github.com/ftPeter/RomiArm
*/

#include <Servo.h>

Servo gripper_servo;
Servo wrist_servo;
Servo shoulder_servo;

void setup() {
  // put your setup code here, to run once:
  gripper_servo.attach(10);
  wrist_servo.attach(11);
  shoulder_servo.attach(3);
}

int gripper_opening_to_pwm( int opening_mm ) {
  opening_mm = constrain( opening_mm, 0, 32 );
  int gripper_pwm = map( opening_mm, 0, 32, 500, 2400 );
  return gripper_pwm;
}

int wrist_angle_to_pwm( int wrist_deg ) {
  wrist_deg = constrain( wrist_deg, 0, 110 );
  int wrist_pwm = map( wrist_deg, 0, 110, 1200, 1900 );
  return wrist_pwm;
}

int shoulder_angle_to_pwm( int shoulder_deg ) {
  shoulder_deg = constrain( shoulder_deg, 0, 60 );
  int shoulder_pwm = map( shoulder_deg, 0, 60, 1900, 1000 );
  return shoulder_pwm;
}

void loop() {
  for (int i = 0; i < 100; i++) {
    int gripper_opening = map( i, 0, 99, 0, 32 );
    int gripper_pwm = gripper_opening_to_pwm( gripper_opening );

    int wrist_angle = map( i, 0, 99, 0, 110 );
    int wrist_pwm = wrist_angle_to_pwm( wrist_angle );

    int shoulder_angle = map( i, 0, 99, 0, 60 );
    int shoulder_pwm = shoulder_angle_to_pwm( shoulder_angle );

    gripper_servo.write(gripper_pwm);
    wrist_servo.write(wrist_pwm);
    shoulder_servo.write(shoulder_pwm);
  }

  for (int i = 99; i >= 0; i--) {
    int gripper_opening = map( i, 0, 99, 0, 32 );
    int gripper_pwm = gripper_opening_to_pwm( gripper_opening );

    int wrist_angle = map( i, 0, 99, 0, 110 );
    int wrist_pwm = wrist_angle_to_pwm( wrist_angle );

    int shoulder_angle = map( i, 0, 99, 0, 60 );
    int shoulder_pwm = shoulder_angle_to_pwm( shoulder_angle );

    gripper_servo.write(gripper_pwm);
    wrist_servo.write(wrist_pwm);
    shoulder_servo.write(shoulder_pwm);
  }
}
