#include <WiFi.h>

// Replace these with your WiFi network settings
const char* ssid = "yourSSID";
const char* password = "yourPASSWORD";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New Client.");
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // You can also do something with the data
        // e.g., client.print(c) to echo the data back
      }
    }
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
