#include "WiFi.h"
#include <WebServer.h>
#include <DNSServer.h>

const byte DNS_PORT = 53;
DNSServer dnsServer;
WebServer server(80);

// Ta page HTML à afficher
const char* html = R"rawliteral(
<!DOCTYPE html>
<html lang="an">
<head>
  <meta charset="UTF-8">
  <title>Welcome</title>
</head>
<body>
</body>
</html>
)rawliteral";

void handleCaptive() {
  server.send(200, "text/html", html);
}


void setup() {
  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_AP);
  WiFi.softAP("network name", "network password");
  delay(100);
  WiFi.setHostname("hostname");

  Serial.println("Setup done");
  dnsServer.start(DNS_PORT, "*", WiFi.softAPIP());
  Serial.println(WiFi.softAPIP());

  // using DNS to redirect all request to esp32 webserver
  server.onNotFound(handleCaptive);

  Serial.println("Captive portal ready !");
  Serial.println(WiFi.softAPIP());

  server.begin();
  Serial.println("Web server OK");

}

void loop() {
  dnsServer.processNextRequest();
  server.handleClient();
  Serial.println(WiFi.softAPIP());
  delay(500);

}

