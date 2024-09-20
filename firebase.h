#ifndef FIREBASE_H
#define FIREBASE_H

#include <FirebaseESP32.h>
#include "horario.h"
#include "comedouro.h"
#include "config.h"

void conectarFirebase(FirebaseData& fbdo) {

  FirebaseConfig config;
  FirebaseAuth auth;

  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;

  if (Firebase.signUp(&config, &auth, "", "")) {
    Serial.println("Conectado ao Firebase");
  } else {
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void verificarRefeicoes(FirebaseData& fbdo, Servo& servo, const Horario& agora, bool containerVazio) {

  Horario horarioAlmoco = getHorarioRefeicaoFirebase(fbdo, Caminho::horaAlmoco, Caminho::minutoAlmoco);
  Horario horarioJanta = getHorarioRefeicaoFirebase(fbdo, Caminho::horaJanta, Caminho::minutoJanta);

  Refeicao almoco(horarioAlmoco, Firebase.getBool(fbdo, Caminho::almocoFeito));
  Refeicao janta(horarioJanta, Firebase.getBool(fbdo, Caminho::jantaFeito));

  if (almoco.ehHorarioRefeicao(agora) && !almoco.getRefeicaoFeita() && !containerVazio) {
    liberarRacao(servo);
    almoco.completarRefeicao();
    Firebase.setBool(fbdo, Caminho::almocoFeito, true);
  } else if (janta.ehHorarioRefeicao(agora) && !janta.getRefeicaoFeita() && !containerVazio) {
    liberarRacao(servo);
    janta.completarRefeicao();
    Firebase.setBool(fbdo, Caminho::jantaFeito, true);
  }
}

Horario getHorarioRefeicaoFirebase(FirebaseData& fbdo, const char* pathHora, const char* pathMinuto) {
  
  int hora = Firebase.getInt(fbdo, pathHora) ? fbdo.intData() : 0;
  int minuto = Firebase.getInt(fbdo, pathMinuto) ? fbdo.intData() : 0;
  
  return Horario(hora, minuto);
}

#endif
