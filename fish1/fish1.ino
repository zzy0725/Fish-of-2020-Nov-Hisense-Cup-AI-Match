#include <Servo.h>
Servo myservo;//定义舵机对象
void setup() {
  pinMode(13, INPUT);//光电开关引脚L
  pinMode(12, INPUT);//光电开关引脚R
  pinMode(11, INPUT);//前传感器1
  pinMode(10, INPUT);//前传感器2
  myservo.attach(9);//舵机引脚
  pinMode(8, OUTPUT);//LED
  digitalWrite(8, LOW);
}

void loop() {
  while (digitalRead(13) == true && digitalRead(12) == true)
  {
    while (digitalRead(10) == true || digitalRead(11) == true)
    {
      digitalWrite(8, HIGH);
      delay(250);
      digitalWrite(8, LOW);
      delay(250);
    }
    int pos = 40;
    for (pos = 40; pos < 140; pos += 1)
    {
      myservo.write(pos);
      while (digitalRead(13) == false || digitalRead(12) == false)
        loop();
      delay(7);
    }
    for (pos = 140; pos >= 41; pos -= 1)
    {
      myservo.write(pos);
      while (digitalRead(13) == false || digitalRead(12) == false)
        loop();
      delay(7);
    }
  }//两个光电开关都没有检测到障碍直走
  while (digitalRead(13) == true && digitalRead(12) == false)
  {
    while (digitalRead(10) == true || digitalRead(11) == true)
    {
      digitalWrite(8, HIGH);
      delay(250);
      digitalWrite(8, LOW);
      delay(250);
    }
    int pos = 120;
    for (pos = 120; pos < 150; pos += 1)
    {
      myservo.write(pos);
      delay(5);
    }
    for (pos = 150; pos >= 121; pos -= 1)
    {
      myservo.write(pos);
      delay(5);
    }
  }//一个检测到障碍一个没检测到障碍转弯
  while (digitalRead(13) == false && digitalRead(12) == true)
  {
    while (digitalRead(10) == true || digitalRead(11) == true)
    {
      digitalWrite(8, HIGH);
      delay(250);
      digitalWrite(8, LOW);
      delay(250);
    }
    int pos = 30;
    for (pos = 30; pos < 60; pos += 1)
    {
      myservo.write(pos);
      delay(5);
    }
    for (pos = 60; pos >= 31; pos -= 1)
    {
      myservo.write(pos);
      delay(5);
    }
  }//一个检测到障碍一个没检测到障碍转弯
  while (digitalRead(13) == false && digitalRead(12) == false)
  {
    while (digitalRead(10) == true || digitalRead(11) == true)
    {
      digitalWrite(8, HIGH);
      delay(250);
      digitalWrite(8, LOW);
      delay(250);
    }
    int pos = 120;
    for (pos = 120; pos < 150; pos += 1)
    {
      myservo.write(pos);
      delay(5);
    }
    for (pos = 150; pos >= 121; pos -= 1)
    {
      myservo.write(pos);
      delay(5);
    }
  }
}
