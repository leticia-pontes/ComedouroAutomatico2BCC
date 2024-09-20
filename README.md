# Comedouro Automático para Pets

## Descrição do Projeto

Este projeto foi desenvolvido como parte da disciplina **Fábrica de Projetos Ágeis II** durante o 2° semestre de 2023. O objetivo é automatizar a alimentação de animais de estimação, utilizando um servo motor controlado por um ESP32 que, por meio de dados de um banco de dados Firebase, verifica o horário das refeições e, com um sensor ultrassônico, analisa a quantidade de ração disponível no comedouro. Caso o horário coincida e o comedouro esteja com ração, o sistema libera a quantidade correta para a refeição e marca a refeição como completa no banco de dados.

## Funcionalidades

- **Verificação de horário de refeições**: Conecta-se ao servidor NTP para obter o horário e compará-lo com os horários armazenados no Firebase.
- **Liberação de ração automática**: Quando é detectado o horário correto e há ração disponível, o servo motor é acionado para liberar a ração.
- **Atualização de status da refeição**: Após a refeição ser liberada, o sistema atualiza o status da refeição no banco de dados como "completa".
- **Verificação do nível de ração**: Um sensor ultrassônico mede a distância até o topo do comedouro para verificar se há ração suficiente no recipiente.
- **Integração com Firebase**: Utiliza Firebase para armazenar e recuperar dados relacionados aos horários das refeições, status do recipiente, e se a refeição foi realizada.

## Tecnologias Utilizadas

- **ESP32**: Microcontrolador responsável pelo controle geral do sistema.
- **Firebase**: Plataforma utilizada para armazenar dados, como horários de refeições e status de refeições completas.
- **Servo Motor**: Utilizado para liberar a ração automaticamente.
- **Sensor Ultrassônico**: Mede a quantidade de ração disponível no comedouro.
- **NTP (Network Time Protocol)**: Sincroniza o horário do sistema.

## Estrutura do Código

O código está organizado da seguinte forma:

- **Comedouro**: Classe responsável pelo controle do servo motor e pela verificação da capacidade do recipiente de ração.
- **Refeicao**: Classe que gerencia os horários de cada refeição (almoço e janta) e o status de completude.
- **Horario**: Classe para manipulação e comparação de horários.
- **Funções principais**:
  - `conectarWifi()`: Estabelece a conexão com a rede Wi-Fi.
  - `configurarHorarioAtualNTP()`: Sincroniza o horário utilizando NTP.
  - `conectarFirebase()`: Configura e conecta ao Firebase.
  - `getHorarioAtualNTP()`: Obtém o horário atual via NTP.
  - `getHorarioRefeicaoFirebase()`: Recupera os horários das refeições do Firebase.
  - `verificarCapacidade()`: Mede a distância até o topo do recipiente de ração usando o sensor ultrassônico.

## Pré-requisitos

Para rodar o projeto, é necessário:

- **Placa ESP32**
- **Servo Motor**
- **Sensor Ultrassônico**
- **Bibliotecas Arduino**:
  - `WiFi.h`
  - `time.h`
  - `FirebaseESP32.h`
  - `ESP32Servo.h`

## Instalação e Execução

1. **Conectar os dispositivos**: Conecte o servo motor e o sensor ultrassônico ao ESP32.
2. **Configurar o Firebase**: Adicione as suas credenciais do Firebase no arquivo do código.
3. **Carregar o código no ESP32**: Compile e envie o código para a placa ESP32 utilizando a IDE do Arduino.
4. **Monitorar**: Utilize o monitor serial da IDE do Arduino para visualizar o funcionamento do sistema.

## Possíveis Melhorias

- Implementação de interface de usuário para facilitar a configuração dos horários de refeição.
- Notificações via aplicativo ou mensagens para o proprietário do pet.
- Verificação e ajustes mais avançados de horário, para considerar fusos horários diferentes.

---

Projeto desenvolvido durante a disciplina **Fábrica de Projetos Ágeis II** como método avaliativo no 2° semestre de 2023.

