#include <WiFi.h>

// Replace these with your WiFi network settings
const char* ssid = "yourSSID";
const char* password = "yourPASSWORD";

const char* host = "server.local.ip"; // The IP address of the server ESP32
const uint16_t port = 80;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }

  // Print the IP address
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  delay(5000);

  Serial.print("Connecting to ");
  Serial.print(host);
  Serial.print(':');
  Serial.println(port);

  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  if (!client.connect(host, port)) {
    Serial.println("Connection failed.");
    return;
  }
  
  // This will send the request to the server
  client.println("Hello from ESP32 client!");
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  Serial.println();
  Serial.println("Connection closed");
}