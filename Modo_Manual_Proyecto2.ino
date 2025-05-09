#include <Servo.h>

Servo servo1, servo2, servo3, servo4;

const int pot1 = A0, pot2 = A1, pot3 = A2, pot4 = A3;
const int ledManual = 8;  // Esta led indica que se encuentra en el modo manual


void setup() {
  Serial.begin(9600);
  servo1.attach(7);
  servo2.attach(6);
  servo3.attach(5);
  servo4.attach(4);
  
  pinMode(ledManual, OUTPUT);
  digitalWrite(ledManual, HIGH);
}

void loop() {
  int posicion1 = map(analogRead(pot1), 0, 1023, 0, 180);
  int posicion2 = map(analogRead(pot2), 0, 1023, 0, 180);
  int posicion3 = map(analogRead(pot3), 0, 1023, 0, 180);
  int posicion4 = map(analogRead(pot4), 0, 1023, 0, 180);

  servo1.write(posicion1);
  servo2.write(posicion2);
  servo3.write(posicion3);
  servo4.write(posicion4);

  delay(100);
}
