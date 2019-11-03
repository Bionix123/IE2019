//COD SURSA - DISPOZITIV ADITIONAL RKIT-SMARTHOME ID2
//CREARE WEBSERVER
//HANDLE REQUESTS
//TURNON/OFF RELAYS
//READ SENSORS VALUES
#include <MQ2.h>
#include "ESP8266WiFi.h"
#include "ESP8266WebServer.h"
#include <ArduinoJson.h>
#include <DHT.h>
#include <DHT_U.h>

//-----------DEVICE INFO------------

String device_id = "2";
String device_name = "RKIT-SLAVE";
String device_description = "5-SENSORS 1-SWITCHES 0-PWM";

//---------SENSORS and RELAYS--------
#define DHTPIN D1
#define DHTTYPE DHT11
#define ERROR_PIN D1
#define RELAY_1 D2
#define RELAY_2 D3
#define RELAY_3 D5
int relaysValue[3] = {0, 0, 0};
#define NUM_RELAYS 3
#define T_PWM1 D6
#define T_PWM2 D7
#define T_PWM3 D8

//------Initialize DHT & MQ-2 sensor--------
DHT dht(DHTPIN, DHTTYPE, 15);
MQ2 mq2(A0);
float temperature;
float humidity;
int lpg, co, smoke;

//-------------JSON OBJECTS----------
StaticJsonDocument<100> jsonSensorsVal;
StaticJsonDocument<100> jsonRelaysStatus;
StaticJsonDocument<100> jsonDeviceData;
//---------WebServer-----------------
//const char* ssid = "Orange-tFpc";
//const char* password = "RYQxcUkB";
const char* ssid = "InfoEducatie";
const char* password = "";
ESP8266WebServer server(80);
String authPasswd = "noonecanbreakthis123";

void getSensorsData() {
  String response;

  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  lpg = mq2.readLPG();
  co = mq2.readCO();
  smoke = mq2.readSmoke();

  jsonSensorsVal["m_units"] = "C,%,ppm,ppm.ppm;";
  jsonSensorsVal["Temperature"] = temperature;
  jsonSensorsVal["Humidity"] = humidity;
  jsonSensorsVal["LPG"] = lpg;
  jsonSensorsVal["CO"] = co;
  jsonSensorsVal["Smoke"] = lpg;

  serializeJson(jsonSensorsVal, response);

  server.send(200, "application/json", response);
}

void getRelaysStatus() {
  String response;

  jsonRelaysStatus["Relay-1"] = relaysValue[0];
  jsonRelaysStatus["Relay-2"] = relaysValue[1];
  jsonRelaysStatus["Relay-3"] = relaysValue[2];

  serializeJson(jsonRelaysStatus, response);

  server.send(200, "application/json", response);
}

void identifyDevice() {
  String response;

  response += "<html>";
  response += "<head>";
  response += "<title>";
  response += device_name + "-" + device_id;
  response += "</title>";
  response += "</head>";
  response += "<body>";
  response += "<h1>";
  response += "App made by Josanu Rares <br>";
  response += "<a href='https://raresj.ro'>www.RaresJ.ro</a>";
  response += "</h1>";
  response += "</body>";
  response += "</html>";

  server.send(200, "text/html", response);
}

void relayTurnOn() {
  if (server.arg("relay_id") == "")     //Parameter not found
    server.send(401, "text/html", "Error: Missing relay_id");
  else {
    if (server.arg("relay_id") == "1")
      relaysValue[0] = 1;
    else if (server.arg("relay_id") == "2")
      relaysValue[1] = 1;
    else if (server.arg("relay_id") == "3")
      relaysValue[2] = 1;
    else{
      server.send(401, "text/html", "Error: relay with the inserted id was not found!");
    }
    refreshRelays();
    server.send(200, "text/html", "Relay" + server.arg("relay_id") + " turned on");
  }
}

void relayTurnOff() {
 if (server.arg("relay_id") == "")     //Parameter not found
    server.send(401, "text/html", "Error: Missing relay_id");
  else {
    if (server.arg("relay_id") == "1")
      relaysValue[0] = 0;
    else if (server.arg("relay_id") == "2")
      relaysValue[1] = 0;
    else if (server.arg("relay_id") == "3")
      relaysValue[2] = 0;
    else{
      server.send(401, "text/html", "Error: relay with the inserted id was not found!");
    }
  refreshRelays();
  server.send(200, "text/html", "Relay" + server.arg("relay_id") + " turned off");
  }
}
void setup() {

  pinMode(RELAY_1,OUTPUT);
  pinMode(RELAY_2,OUTPUT);
  pinMode(RELAY_3,OUTPUT);
  
  //Open serial port for debugging
  Serial.begin(115200);

  //Start DHT & MQ-2 Readings
  dht.begin();
  mq2.begin();

  //-------WIFI CONNECTION--------
  WiFi.hostname(device_name + "-" + device_id);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {   //Wait for connection

    delay(500);
    Serial.println("Waiting to connect...");
  }
  Serial.print("Connection succesfull! IP ADRESS:");
  Serial.println(WiFi.localIP());


  //----------ROUTES--------------
  server.on("/", identifyDevice);
  server.on("/sensors-read", getSensorsData);
  server.on("/relays-stats", getRelaysStatus);
  server.on("/relay/turnon", relayTurnOn);
  server.on("/relay/turnoff", relayTurnOff);


  server.begin(); //start server
}
void loop() {
  server.handleClient();         //Handling of incoming requests
}

void refreshRelays() {
  digitalWrite(RELAY_1, relaysValue[0]);
  digitalWrite(RELAY_2, relaysValue[1]);
  digitalWrite(RELAY_3, relaysValue[2]);
}
