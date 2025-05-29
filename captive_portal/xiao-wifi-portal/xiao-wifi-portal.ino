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
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <style>

    body {
      margin: 0;
      padding: 0;
      font-family: 'Orbitron', sans-serif;
      background: linear-gradient(135deg, #000000, #1a1a1a);
      color: #ffffff;
      display: flex;
      justify-content: center;
      align-items: center;
      height: 100vh;
      text-align: center;
    }

    .container {
      max-width: 90%;
    }

    h1 {
      font-size: 2.5em;
      margin-bottom: 0.5em;
    }

    p {
      font-size: 1.2em;
      margin-bottom: 1em;
    }

    img {
      max-width: 200px;
      margin-bottom: 1em;
    }

    .button {
      background-color: #ffffff;
      color: #000000;
      border: none;
      padding: 10px 20px;
      font-size: 1em;
      border-radius: 8px;
      cursor: pointer;
      transition: 0.3s ease;
    }

    .button:hover {
      background-color: #555555;
      color: white;
    }
  </style>
</head>
<body>
  <div class="container">
    <h1>le reseau n'as pas de wifi dommage</h1>
    <p> bien tenté 😎</p>
    <button class="button" onclick="alert('non ca te donneras pas le wifi 😁')">Clique ici</button>
  </div>
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
  WiFi.softAP("OU suis-je ?", NULL);
  delay(100);
  WiFi.setHostname("ITS SEEMS LIKE ITS NOT HERE");

  Serial.println("Setup done");
  dnsServer.start(DNS_PORT, "*", WiFi.softAPIP());
  Serial.println(WiFi.softAPIP());

  // Redirige toutes les requêtes vers la page captif
  server.onNotFound(handleCaptive);

  Serial.println("Captive portal prêt !");
  Serial.println(WiFi.softAPIP());

  server.begin();
  Serial.println("Serveur web démarré.");

}

void loop() {
  dnsServer.processNextRequest();
  server.handleClient();
  Serial.println(WiFi.softAPIP());
  delay(500);



}

