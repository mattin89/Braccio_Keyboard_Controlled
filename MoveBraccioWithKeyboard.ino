#include <Braccio.h>
#include <Servo.h>

Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_ver;
Servo wrist_rot;
Servo gripper;

const int MOTORS = 6;
int angle[MOTORS] = {0 , 45, 180, 180, 90, 90};

const int increment = 10;

void setup() {

  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
  Braccio.begin(SOFT_START_DISABLED);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    executeCommand(command);
  }
}

void executeCommand(char command) {
  switch (command) {
    case 'q': // Move the base clockwise
      if (angle[0] + increment <= 180) {
        angle[0] += increment;
      }
      break;
    case 'w': // Move the base counterclockwise
      if (angle[0] - increment >= 0) {
        angle[0] -= increment;
      }
      break;
    case 'a': // Move shoulder up
      if (angle[1] + increment <= 165) {
        angle[1] += increment;
      }
      break;
    case 's': // Move shoulder down
      if (angle[1] - increment >= 15) {
        angle[1] -= increment;
      }
      break;
    case 'z': // Move elbow up
      if (angle[2] + increment <= 180) {
        angle[2] += increment;
      }
      break;
    case 'x': // Move elbow down
      if (angle[2] - increment >=0) {
        angle[2] -= increment;
      }
      break;
    case 'e': // Move wrist up
      if (angle[3] + increment <= 180) {
        angle[3] += increment;
      }
      break;
    case 'r': // Move wrist down
      if (angle[3] - increment >=0) {
        angle[3] -= increment;
      }
      break;
    case 'd': // Spin hand clockwise
      if (angle[4] + increment <= 180) {
        angle[4] += increment;
      }
      break;
    case 'f': // Spin hand counterclockwise
      if (angle[4] - increment >=0) {
        angle[4] -= increment;
      }
      break;
    case 'c': // Open gripper
      if (angle[5] + increment <= 73) {
        angle[5] += increment;
      }
      break;
    case 'v': // Close gripper
      if (angle[5] - increment >= 10) {
        angle[5] -= increment;
      }
      break;
    default:
      break;
  }
  Braccio.ServoMovement(20        , angle[0], angle[1], angle[2], angle[3], angle[4], angle[5]);
}
