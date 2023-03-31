#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

#include <Arduino.h>


#define Motor1 25
#define Motor2 26

#define Motor3 27
#define Motor4 14


void setup() {
  pinMode(Motor1, OUTPUT);
  pinMode(Motor2, OUTPUT);
  pinMode(Motor3, OUTPUT);
  pinMode(Motor4, OUTPUT);
  
  // put your setup code here, to run once:
  Serial.begin(115200);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin("MyEsp32");       //set bluetooth name of your device
}

void loop() {
  Dabble.processInput();//this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  Serial.print("KeyPressed: ");
  if (GamePad.isUpPressed())
  {
    Serial.print("Up");
    moveForward();
  } else if (GamePad.isDownPressed())
  {
    Serial.print("Down");
    moveBackward();
  } else if (GamePad.isLeftPressed())
  {
    Serial.print("Left");
    rotateLeft();
  } else if (GamePad.isRightPressed())
  {
    Serial.print("Right");
    rotateRight();
  } else
  {
    stopMoving();
  }

  /*if (GamePad.isStartPressed())
    {
    Serial.print("Start");
    }

    if (GamePad.isSelectPressed())
    {
    Serial.print("Select");
    } */
  Serial.print('\t');

  // int a = GamePad.getAngle();
  // Serial.print("Angle: ");
  // Serial.print(a);
  // Serial.print('\t');
  // int b = GamePad.getRadius();
  // Serial.print("Radius: ");
  // Serial.print(b);
  // Serial.print('\t');
  // float c = GamePad.getXaxisData();
  // Serial.print("x_axis: ");
  // Serial.print(c);
  // Serial.print('\t');
  // float d = GamePad.getYaxisData();
  // Serial.print("y_axis: ");
  // Serial.println(d);
  Serial.println();
}

void moveForward() {
  digitalWrite(Motor1, HIGH);
  digitalWrite(Motor2, LOW);
  digitalWrite(Motor3, LOW);
  digitalWrite(Motor4, HIGH);
}

void moveBackward() {
  digitalWrite(Motor1, LOW);
  digitalWrite(Motor2, HIGH);
  digitalWrite(Motor3, HIGH);
  digitalWrite(Motor4, LOW);
}

void rotateRight() {
  digitalWrite(Motor1, HIGH);
  digitalWrite(Motor2, LOW);
  digitalWrite(Motor3, HIGH);
  digitalWrite(Motor4, LOW);
}

void rotateLeft() {
  digitalWrite(Motor1, LOW);
  digitalWrite(Motor2, HIGH);
  digitalWrite(Motor3, LOW);
  digitalWrite(Motor4, HIGH);
}


void stopMoving() {
  digitalWrite(Motor1, LOW);
  digitalWrite(Motor2, LOW);
  digitalWrite(Motor3, LOW);
  digitalWrite(Motor4, LOW);
}
