
#include <Joystick.h>

#define JOYSTICK_REPORT_ID         0x03
#define JOYSTICK_BUTTON_COUNT        10
#define JOYSTICK_HATSWITCH_COUNT      0
#define JOYSTICK_TYPE_JOYSTICK     0x04
#define JOYSTICK_AXIS_MINIMUM        -1
#define JOYSTICK_AXIS_MAXIMUM         1

#define DIR_UP          7
#define DIR_DOWN        6
#define DIR_LEFT        4
#define DIR_RIGHT       5
#define BUTTON_1       11 //A0
#define BUTTON_2       10 //A1
#define BUTTON_3        8 //A2
#define BUTTON_4       12 // 8
#define BUTTON_5       A0 // 9
#define BUTTON_6       A1 //10
#define BUTTON_7       A2 //11
#define BUTTON_8        9 //12
#define BUTTON_START   A4
#define BUTTON_SELECT  A3

Joystick_ Joystick = Joystick_(
    JOYSTICK_REPORT_ID,
    JOYSTICK_TYPE_JOYSTICK,
    JOYSTICK_BUTTON_COUNT,
    JOYSTICK_HATSWITCH_COUNT,
    true,
    true,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false
);

void setup() {
  pinMode(DIR_UP,        INPUT_PULLUP);
  pinMode(DIR_DOWN,      INPUT_PULLUP);
  pinMode(DIR_LEFT,      INPUT_PULLUP);
  pinMode(DIR_RIGHT,     INPUT_PULLUP);
  pinMode(BUTTON_1,      INPUT_PULLUP);
  pinMode(BUTTON_2,      INPUT_PULLUP);
  pinMode(BUTTON_3,      INPUT_PULLUP);
  pinMode(BUTTON_4,      INPUT_PULLUP);
  pinMode(BUTTON_5,      INPUT_PULLUP);
  pinMode(BUTTON_6,      INPUT_PULLUP);
  pinMode(BUTTON_7,      INPUT_PULLUP);
  pinMode(BUTTON_8,      INPUT_PULLUP);
  pinMode(BUTTON_START,  INPUT_PULLUP);
  pinMode(BUTTON_SELECT, INPUT_PULLUP);

  Joystick.setXAxisRange(JOYSTICK_AXIS_MINIMUM, JOYSTICK_AXIS_MAXIMUM);
  Joystick.setYAxisRange(JOYSTICK_AXIS_MINIMUM, JOYSTICK_AXIS_MAXIMUM);

  Joystick.begin();
}

void loop() {
  if (digitalRead(DIR_LEFT) == HIGH) {
    Joystick.setXAxis(-1);
  } else if (digitalRead(DIR_RIGHT) == HIGH) {
    Joystick.setXAxis(1);
  } else {
    Joystick.setXAxis(0);
  }
  if (digitalRead(DIR_UP) == HIGH) {
    Joystick.setYAxis(-1);
  } else if (digitalRead(DIR_DOWN) == HIGH) {
    Joystick.setYAxis(1);
  } else {
    Joystick.setYAxis(0);
  }

  if (digitalRead(BUTTON_1) == HIGH) {
    Joystick.pressButton(0);
  } else {
    Joystick.releaseButton(0);
  }
  if (digitalRead(BUTTON_2) == HIGH) {
    Joystick.pressButton(1);
  } else {
    Joystick.releaseButton(1);
  }
  if (digitalRead(BUTTON_3) == HIGH) {
    Joystick.pressButton(2);
  } else {
    Joystick.releaseButton(2);
  }
  if (digitalRead(BUTTON_4) == HIGH) {
    Joystick.pressButton(3);
  } else {
    Joystick.releaseButton(3);
  }
  if (digitalRead(BUTTON_5) == HIGH) {
    Joystick.pressButton(4);
  } else {
    Joystick.releaseButton(4);
  }
  if (digitalRead(BUTTON_6) == HIGH) {
    Joystick.pressButton(5);
  } else {
    Joystick.releaseButton(5);
  }
  if (digitalRead(BUTTON_7) == HIGH) {
    Joystick.pressButton(6);
  } else {
    Joystick.releaseButton(6);
  }
  if (digitalRead(BUTTON_8) == HIGH) {
    Joystick.pressButton(7);
  } else {
    Joystick.releaseButton(7);
  }
  if (digitalRead(BUTTON_START) == HIGH) {
    Joystick.pressButton(8);
  } else {
    Joystick.releaseButton(8);
  }
  if (digitalRead(BUTTON_SELECT) == HIGH) {
    Joystick.pressButton(9);
  } else {
    Joystick.releaseButton(9);
  }
  delay(10);
}
