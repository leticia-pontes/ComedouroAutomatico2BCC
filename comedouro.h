#ifndef COMEDOURO_H
#define COMEDOURO_H

#include <ESP32Servo.h>

void liberarRacao(Servo& servo) {

  servo.write(0);
  delay(1300);
  servo.write(90);
}

int verificarCapacidade() {
  
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  int retorno = pulseIn(echo, HIGH);
  
  return retorno / 58.2;
}

#endif
