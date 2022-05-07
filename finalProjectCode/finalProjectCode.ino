
#include <Servo.h>
Servo s1;
Servo s2;
Servo s3;
Servo s4;
Servo s5;
Servo s6;
Servo s7;
Servo s8;
Servo s9;



String serialInput;
char* hightValues;

int __GridSize__ = 9;
int hightMap [4];

void setup() {
  Serial.begin(9600);

  s6.attach(6);
  s7.attach(7); 
  s8.attach(8);
  s9.attach(9);
}

void loop() {
  if (Serial.available() > 0) {

    serialInput = Serial.readString();
    delay(5);
    Serial.println(serialInput);

    int end;
    int index = 0;
    String str = serialInput;
    while ((end = str.indexOf(",")) != -1) {
      String num = str.substring(0, end);
      str = str.substring(end + 1, str.length());
      hightMap[index] = num.toInt();
      index++;
    }

    s6.write(hightMap[0]);
    s7.write(hightMap[1]); 
    s8.write(hightMap[2]);
    s9.write(hightMap[3]);


  }
}
