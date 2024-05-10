# Temperatura com ESP32 - Protocolo MQTT 

Utilizar a plataforma Wowki para desenvolver no ESP32 um sensor de temperatura e umidade, esses dados devem ser publicados via MQTT em um broker.

## Funcionalidades 🛠️

| Funcionalidade          | Descrição                                                                                       |
|-------------------------|-------------------------------------------------------------------------------------------------|
| Enviar dados da Temperatura e Umidade        | O usuário consegue enviar dados e receber eles no Broker |


## Tecnologias Utilizadas 🚀

- **Maqiatto.com**: Broker web free.

## Como Usar 📋

1. Acesse: ``https://wokwi.com/projects/397429753843668993``.
2. Copie o projeto para o seu Wowki, para isso é só estar logado e clicar em Save.
3. Renomeie como desejar.
4. Troque os dados abaixo para os de sua configuração e preferência.

```cpp
// MQTT Broker
const char *mqtt_broker = "maqiatto.com";
const int mqtt_port = 1883;
const char *topic_temperatura = "seuTopico";
const char *mqtt_username = "seuUsername";
const char *mqtt_password = "suaSenha";
```

## Desenvolvimento

| Desenvolvimento                           | Descrição                                                                                                                                                                            |
|-------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Sensor de Temperatura | Foi utilizado um projeto padrão da própria Wowki para criação do Sensor de Temperatura                                                  |
| Código de conexão com o Broker  | Desenvolvimento do código para conexão com o Broker |

## 🎥 Materiais de Apoio Utilizados

Aqui estão alguns vídeos que utilizei como apoio durante o desenvolvimento:

- [![YouTube Video 1](https://img.shields.io/badge/Assistir-Video%202-red)](https://www.youtube.com/watch?v=EHTpWQ5s-No&t=797s) **ESP8266 - envio e recebimento de dados via MQTT**


## Simulação 🎬

Aqui está uma simulação do sistema em funcionamento: 

https://github.com/LarissaSL/Esp32_Temperatura_MQTT/assets/112571317/face2608-0c71-49cc-b7ba-5d21039beaad

