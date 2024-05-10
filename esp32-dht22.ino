#define DEBUG_ESP_PORT Serial

#include <WiFi.h>
#include <PubSubClient.h>
#include "DHTesp.h"
#include <WiFiClientSecure.h>

// Parametros de Conexão
const char *ssid = "Wokwi-GUEST"; // Rede
const char *password = "";        // Senha

// MQTT Broker
const char *mqtt_broker = "maqiatto.com";
const int mqtt_port = 1883;
const char *topic_temperatura = "larissa021222@gmail.com/topico1";
const char *mqtt_username = "larissa021222@gmail.com";
const char *mqtt_password = "-Tourinho1@";

// Configuração de Conexão
WiFiClient espClient;
PubSubClient client(espClient);

// Sensor
const int DHT_PIN = 15;
DHTesp dhtSensor;

void callback(char *topic, byte *payload, unsigned int length);

// Void do WiFi
void setup_wifi() {
  delay(10);
  Serial.print("Conectando em ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.print("Endereço de IP: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.println("Tentando Conexão MQTT...");
    String clientId = "esp32-dht22-clientId-";
    clientId += String(random(0xffff), HEX);

    if (client.connect(clientId.c_str(), mqtt_username, mqtt_password)) {
      Serial.println("Conectado");
    } else {
      Serial.print("Falha ao conectar ao broker MQTT, código do erro = ");
      Serial.print(client.state());
      Serial.println(" tentando novamente em 5 segundos...");

      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  randomSeed(micros());
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);

  setup_wifi();

  client.setServer(mqtt_broker, mqtt_port);
}

float temperatura_antiga = 0;

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  TempAndHumidity data = dhtSensor.getTempAndHumidity();
  float temperatura = data.temperature;
  float umidade = data.humidity;

  if (temperatura_antiga != temperatura) {
    String mensagem = "Temperatura: " + String(temperatura, 2) + "°C, Umidade: " + String(umidade, 2) + "%";
    if (client.publish(topic_temperatura, mensagem.c_str())) {
      Serial.println("Mensagem publicada com sucesso: " + mensagem);
      temperatura_antiga = temperatura;
    } else {
      Serial.println("Falha ao publicar mensagem.");
    }
  }

  delay(1000);
}
