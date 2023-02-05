
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

uint8_t button1State = 0;
uint8_t button2State = 0;
uint8_t button3State = 0;
uint8_t button4State = 0;
uint8_t button5State = 0;
uint8_t button6State = 0;
uint8_t button7State = 0;
uint8_t button8State = 0;
uint8_t buttonStartState = 0;
uint8_t buttonSelectState = 0;

int8_t xAxisState = 0;
int8_t yAxisState = 0;

void checkButton(uint8_t buttonIO, uint8_t buttonNumber, uint8_t *buttonState) {
  uint8_t buttonValue = digitalRead(buttonIO);
  if (buttonValue != *buttonState) {
    *buttonState = buttonValue;
    Joystick.setButton(buttonNumber, buttonValue);
  }
}

void checkXAxis() {
  int8_t value = 0;
  if (digitalRead(DIR_LEFT) == HIGH) {
    value = -1;
  } else if (digitalRead(DIR_RIGHT) == HIGH) {
    value = 1;
  }
  if (value != xAxisState) {
    xAxisState = value;
    Joystick.setXAxis(value);
  }
}

void checkYAxis() {
  int8_t value = 0;
  if (digitalRead(DIR_UP) == HIGH) {
    value = -1;
  } else if (digitalRead(DIR_DOWN) == HIGH) {
    value = 1;
  }
  if (value != yAxisState) {
    yAxisState = value;
    Joystick.setYAxis(value);
  }
}

void loop() {
  checkXAxis();
  checkYAxis();

  checkButton(BUTTON_1, 0, &button1State);
  checkButton(BUTTON_2, 1, &button2State);
  checkButton(BUTTON_3, 2, &button3State);
  checkButton(BUTTON_4, 3, &button4State);
  checkButton(BUTTON_5, 4, &button5State);
  checkButton(BUTTON_6, 5, &button6State);
  checkButton(BUTTON_7, 6, &button7State);
  checkButton(BUTTON_8, 7, &button8State);
  checkButton(BUTTON_START, 8, &buttonStartState);
  checkButton(BUTTON_SELECT, 9, &buttonSelectState);

  delay(30);
}
