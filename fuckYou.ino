#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
  pwm.begin();
  pwm.setPWMFreq(50);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0) {
    Serial.read();
    for (int i =0; i < 1000;i++){
      pwm.writeMicroseconds(0, 1000);
      pwm.writeMicroseconds(2, 2000);
    }
  }else {
    pwm.writeMicroseconds(0, 0);
    pwm.writeMicroseconds(2, 0);
  }
}
