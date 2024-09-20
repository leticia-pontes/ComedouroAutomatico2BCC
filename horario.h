#ifndef HORARIO_H
#define HORARIO_H

#include <Arduino.h>
#include "time.h"

class Horario {

  private:
    int hora;
    int minuto;

  public:
    Horario(int h, int m) : hora(h), minuto(m) {}

    void mostrarHorario() const {
      Serial.print(hora);
      Serial.print(":");
      Serial.println(minuto);
    }

    bool ehMeiaNoite() const {
      return hora == 0 && minuto == 0;
    }

    bool operator==(const Horario& outro) const {
      return hora == outro.hora && minuto == outro.minuto;
    }
};

Horario getHorarioAtualNTP() {
  
  struct tm timeinfo;

  if (!getLocalTime(&timeinfo)) {
    Serial.println("Erro ao obter horário");
    return Horario(0, 0);
  }

  int hora = timeinfo.tm_hour;
  int minuto = timeinfo.tm_min;
  
  return Horario(hora, minuto);
}

#endif
