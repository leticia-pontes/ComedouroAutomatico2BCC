#ifndef CONFIG_H
#define CONFIG_H

const char* WIFI_SSID = "";
const char* WIFI_PASSWORD = "";
const char* NTP_SERVER = "pool.ntp.org";
const long GMT_OFFSET_SEC = -10800;
const int DAYLIGHT_OFFSET_SEC = 0;
const char* DATABASE_URL = "";
const char* API_KEY = "";

// Pinos
const int trigger = 19;
const int echo = 18;
const int pin_servo = 15;

struct Caminho {
  static constexpr const char* horaAlmoco = "hora-refeicao/almoco/hora";
  static constexpr const char* minutoAlmoco = "hora-refeicao/almoco/minuto";
  static constexpr const char* horaJanta = "hora-refeicao/janta/hora";
  static constexpr const char* minutoJanta = "hora-refeicao/janta/minuto";
  static constexpr const char* almocoFeito = "hora-refeicao/almoco/feito";
  static constexpr const char* jantaFeito = "hora-refeicao/janta/feito";
  static constexpr const char* capacidadeContainer = "Comedouro/Container/Vazio";
};

#endif
