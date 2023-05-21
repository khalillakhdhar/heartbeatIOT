#include <UbidotsMicroESP8266.h>
#include <ESP8266WiFi.h>

#define SSID "your_wifi_ssid"
#define PASSWORD "your_wifi_password"
#define TOKEN "your_ubidots_token"
#define VARIABLE_ID "your_variable_id"

Ubidots client(TOKEN);

void setup() {
  Serial.begin(115200);
  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi!");

  client.wifiConnection(WiFi);
}

void loop() {
  // Read heartbeat sensor data
  int heartbeat = analogRead(A0); // Assuming heartbeat sensor is connected to analog pin A0

  // Send data to Ubidots
  client.add(VARIABLE_ID, heartbeat); // Replace VARIABLE_ID with your Ubidots variable ID
  client.sendAll();

  delay(5000); // Wait for 5 seconds before sending the next data point
}
