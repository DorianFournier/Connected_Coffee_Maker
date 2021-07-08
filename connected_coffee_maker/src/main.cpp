#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

const char* ssid = "WifiName";
const char* password = "yourPassword";

const int startCoffeeMaker = 4;
const int bigCoffee = 5;
const int smallCoffee = 18;
const int waterSensor = 34;

AsyncWebServer server(80);

void setup()
{
  Serial.begin(115200);
  Serial.println("\n");

  //--- INIT GPIO ---//
  pinMode(startCoffeeMaker, OUTPUT);
  digitalWrite(startCoffeeMaker, LOW);

  pinMode(bigCoffee, OUTPUT);
  digitalWrite(bigCoffee, LOW);

  pinMode(smallCoffee, OUTPUT);
  digitalWrite(smallCoffee, LOW);

  pinMode(waterSensor, INPUT);

  //--- SPIFFS ---//
  if(!SPIFFS.begin())
  {
    Serial.println("Erreur SPIFFS...");
    return;
  }

  File root = SPIFFS.open("/");
  File file = root.openNextFile();

  while(file)
  {
    Serial.print("File: ");
    Serial.println(file.name());
    file.close();
    file = root.openNextFile();
  }

  //--- WIFI ---//
  WiFi.begin(ssid, password);
	Serial.print("Tentative de connexion...");
	
	while(WiFi.status() != WL_CONNECTED)
	{
		Serial.print(".");
		delay(100);
	}
	
	Serial.println("\n");
	Serial.println("Connexion etablie!");
	Serial.print("Adresse IP: ");
	Serial.println(WiFi.localIP());

  //--- SERVER REQUEST ---//
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send(SPIFFS, "/index.html", "text/html");
  });

  server.on("/w3.css", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send(SPIFFS, "/w3.css", "text/css");
  });

  server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send(SPIFFS, "/script.js", "text/javascript");
  });

  server.on("/readWaterLevel", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    int val = analogRead(waterSensor);
    String levelValue = String(val);
    request->send(200, "text/plain", levelValue);
  });

  server.on("/on", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    digitalWrite(startCoffeeMaker, HIGH);
    request->send(200);
  });

  server.on("/off", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    digitalWrite(startCoffeeMaker, LOW);
    request->send(200);
  });

  server.on("/small", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    digitalWrite(smallCoffee, HIGH);
    delay(1000);
    digitalWrite(smallCoffee, LOW);
    request->send(200);
  });

  server.on("/big", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    digitalWrite(bigCoffee, HIGH);
    delay(1000);
    digitalWrite(bigCoffee, LOW);
    request->send(200);
  });

  server.begin();
  Serial.println("Serveur actif!");
}

void loop()
{

}