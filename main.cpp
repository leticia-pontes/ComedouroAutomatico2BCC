#include <WiFi.h>
#include "time.h"
#include <FirebaseESP32.h>
#include <ESP32Servo.h>
#include "config.h"
#include "comedouro.h"
#include "horario.h"
#include "firebase.h"

// Variáveis globais
FirebaseData fbdo;
unsigned long tempoChecagemAnteriorMillis = 0;
const unsigned long intervaloChecagemDadosMillis = 8000;
Servo servo;

void setup() {
  Serial.begin(115200);
  Serial.println("\nIniciando ESP32!");

  conectarWifi();
  configurarHorarioAtualNTP();
  conectarFirebase(fbdo);

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  servo.attach(pin_servo);
  servo.write(90);
}

void loop() {
  
  unsigned long tempoChecagemAtualMillis = millis();

  if (tempoChecagemAtualMillis - tempoChecagemAnteriorMillis >= intervaloChecagemDadosMillis) {
    
    tempoChecagemAnteriorMillis = tempoChecagemAtualMillis;

    if (Firebase.ready()) {
      
      int distancia = verificarCapacidade();
      bool containerVazio = (distancia >= 20);
      Firebase.setBool(fbdo, Caminho::capacidadeContainer, containerVazio);

      Serial.print("\nContainer ");
      Serial.print(containerVazio ? "vazio" : "cheio");
      Serial.print("\nDistância: ");
      Serial.print(distancia);
      Serial.print(" cm\n");

      Horario agora = getHorarioAtualNTP();
      agora.mostrarHorario();

      if (agora.ehMeiaNoite()) {
        resetarRefeicoes();
      }

      verificarRefeicoes(fbdo, servo, agora, containerVazio);
    }
  }
}
