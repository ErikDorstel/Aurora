#include <WiFi.h>
WiFiServer tcpServer(80);
WiFiClient mqttProtocol;
WiFiUDP dnsServer;
#include <Preferences.h>
Preferences preferences;
#include <PubSubClient.h>
PubSubClient mqttClient(mqttProtocol);

const char* ssidAP="SSTC-2 Aurora"; const char* passwordAP="";
String ssidStation=""; String passwordStation=""; boolean statusStation=false;
String mqttBroker=""; boolean mqttEnabled=false; long mqttLastConnect=millis();

void WiFiStationConnected(WiFiEvent_t event, WiFiEventInfo_t info) {
  preferences.begin("Aurora",false); preferences.putString("ssidStation",ssidStation); preferences.putString("passwordStation",passwordStation);
  preferences.putString("mqttBroker",mqttBroker); preferences.putBool("mqttEnabled",mqttEnabled); preferences.end();
  statusStation=true; if (debug) { Serial.println("WLAN Station " + ssidStation + " connected."); } }

void WiFiStationDisconnected(WiFiEvent_t event, WiFiEventInfo_t info) { statusStation=false; WiFi.disconnect(); if (debug) { Serial.println("WLAN Station disconnected."); } }

void initWLAN() {
  preferences.begin("Aurora",false); ssidStation=preferences.getString("ssidStation",""); passwordStation=preferences.getString("passwordStation","");
  mqttBroker=preferences.getString("mqttBroker",""); mqttEnabled=preferences.getBool("mqttEnabled",false); preferences.end();
  WiFi.mode(WIFI_AP_STA);
  WiFi.onEvent(WiFiStationConnected,SYSTEM_EVENT_STA_CONNECTED);
  WiFi.onEvent(WiFiStationDisconnected,SYSTEM_EVENT_STA_DISCONNECTED);
  WiFi.softAP(ssidAP,passwordAP); WiFi.softAPConfig(IPAddress(192,168,4,1),IPAddress(192,168,4,1),IPAddress(255,255,255,0));
  WiFi.begin(ssidStation.c_str(),passwordStation.c_str());
  if (debug) { Serial.println("WLAN AP with IP address " + WiFi.softAPIP().toString() + " enabled."); }
  tcpServer.begin(); dnsServer.begin(53); }

void reconnectWLAN() {
  if (mqttClient.connected()) { mqttProtocol.flush(); mqttProtocol.stop(); mqttClient.disconnect(); delay(250); }
  if (statusStation==true) { WiFi.disconnect(); delay(250); }
  mqttLastConnect=millis()+5000; WiFi.begin(ssidStation.c_str(),passwordStation.c_str()); }
