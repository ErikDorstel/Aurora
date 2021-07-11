#include <WiFi.h>
WiFiServer tcpServer(80);
#include <Preferences.h>
Preferences preferences;

const char* ssidAP="SSTC-2 Aurora"; const char* passwordAP="";
String ssidStation=""; String passwordStation=""; boolean statusStation=false;
boolean debug=false;

#include "SSTC-2.h"
#include "hex2ascii.h"
#include "index_html.h"
#include "choose_html.h"
#include "httpget.h"
#include "httpworker.h"

void setup() {
  if (debug) { Serial.begin(115200); }
  initSSTC2(); // Aurora SSTC-2 specific init
  preferences.begin("Aurora",false); ssidStation=preferences.getString("ssidStation",""); passwordStation=preferences.getString("passwordStation",""); preferences.end();
  WiFi.mode(WIFI_AP_STA);
  WiFi.onEvent(WiFiStationConnected,SYSTEM_EVENT_STA_CONNECTED);
  WiFi.onEvent(WiFiStationDisconnected,SYSTEM_EVENT_STA_DISCONNECTED);
  WiFi.softAP(ssidAP,passwordAP); WiFi.begin(ssidStation.c_str(),passwordStation.c_str());
  IPAddress IP=WiFi.softAPIP(); if (debug) { Serial.print("AP IP address: "); Serial.println(IP); }
  tcpServer.begin(); }

void WiFiStationConnected(WiFiEvent_t event, WiFiEventInfo_t info) {
  preferences.begin("Aurora",false); preferences.putString("ssidStation",ssidStation); preferences.putString("passwordStation",passwordStation); preferences.end();
  statusStation=true; if (debug) { Serial.println("WIFI Station " + ssidStation + " connected."); } }

void WiFiStationDisconnected(WiFiEvent_t event, WiFiEventInfo_t info) { statusStation=false; WiFi.disconnect(); if (debug) { Serial.println("WIFI Station disconnected."); } }

void loop() { httpworker(); }
