#include <WiFi.h>
#include <Preferences.h>
#include "SSTC-2.h"
#include "hex2ascii.h"
#include "index_html.h"
#include "choose_html.h"
WiFiServer server(80);
Preferences preferences;
const char* ssidAP="SSTC-2 Aurora"; const char* passwordAP="";
String ssidStation=""; String passwordStation="";
String header; boolean debug=false; boolean statusStation=false;

void setup() {
  if (debug) { Serial.begin(115200); }
  initSSTC2(); // Aurora SSTC-2 specific init
  preferences.begin("Aurora",false); ssidStation=preferences.getString("ssidStation",""); passwordStation=preferences.getString("passwordStation",""); preferences.end();
  WiFi.mode(WIFI_AP_STA);
  WiFi.onEvent(WiFiStationConnected,SYSTEM_EVENT_STA_CONNECTED);
  WiFi.onEvent(WiFiStationDisconnected,SYSTEM_EVENT_STA_DISCONNECTED);
  WiFi.softAP(ssidAP,passwordAP); WiFi.begin(ssidStation.c_str(),passwordStation.c_str());
  IPAddress IP=WiFi.softAPIP(); if (debug) { Serial.print("AP IP address: "); Serial.println(IP); }
  server.begin(); }

void WiFiStationConnected(WiFiEvent_t event, WiFiEventInfo_t info) {
  preferences.begin("Aurora",false); preferences.putString("ssidStation",ssidStation); preferences.putString("passwordStation",passwordStation); preferences.end();
  statusStation=true; if (debug) { Serial.println("WIFI Station " + ssidStation + " Connected."); } }
void WiFiStationDisconnected(WiFiEvent_t event, WiFiEventInfo_t info) { statusStation=false; WiFi.disconnect(); if (debug) { Serial.println("WIFI Station Disconnected."); } }

void loop() {
  WiFiClient client=server.available();
  if (client) { String currentLine=""; if (debug) { Serial.println("New HTTP Client."); }
    while (client.connected()) {
      if (client.available()) { char c=client.read(); header+=c; if (debug) { Serial.write(c); }
        if (c=='\n') {
          if (currentLine.length()==0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // WLAN specific pages
            if (header.indexOf("GET /connectAP")>=0) {
              int a=header.indexOf(",")+1; int b=header.indexOf(",",a)+1; int c=header.indexOf(" ",b)+1;
              ssidStation=h2a(header.substring(a,b-1)); passwordStation=h2a(header.substring(b,c-1));
              if (statusStation==true) { WiFi.disconnect(); delay(100); } WiFi.begin(ssidStation.c_str(),passwordStation.c_str()); delay(1000); }
            else if (header.indexOf("GET /scanAP")>=0) {
              int indexes=WiFi.scanNetworks(); for (int index=0;index<indexes;++index) { if (WiFi.SSID(index)!="") {
                client.print("<div class=\"x1\" onclick=\"setAP\(\'"); client.print(WiFi.SSID(index)); client.print("\'\);\">");
                client.print(WiFi.RSSI(index)); client.print("&nbsp;dB&nbsp;&nbsp;&nbsp;&nbsp;"); client.print(WiFi.SSID(index)); client.print("</div>"); } } }
            else if (header.indexOf("GET /statusAP")>=0) { if (statusStation==true) { client.println("<div class=\"x1\">WLAN AP " + ssidStation + " connected.</div>"); }
              else { client.println("<div class=\"x1\">No WLAN AP connected.</div>"); } }
            else if (header.indexOf("GET /authAP")>=0) { client.println(a2h(ssidStation) + "," + a2h(passwordStation) + ","); }
            else if (header.indexOf("GET /chooseAP")>=0) { client.println(choose_html); }

            // Aurora SSTC-2 specific pages
            else if (header.indexOf("GET /setSSTC2Para")>=0) {
              int a=header.indexOf(",")+1; int b=header.indexOf(",",a)+1; int c=header.indexOf(",",b)+1; int d=header.indexOf(" ",c)+1;
              setSSTC2Para(header.substring(a,b-1).toInt(),header.substring(b,c-1).toInt(),header.substring(c,d-1).toInt()); }
            else if (header.indexOf("GET /setSSTC2Tone")>=0) {
              int a=header.indexOf(",")+1; int b=header.indexOf(",",a)+1; int c=header.indexOf(",",b)+1; int d=header.indexOf(",",c)+1; int e=header.indexOf(" ",d)+1;
              setSSTC2Tone(header.substring(a,b-1).toInt(),header.substring(b,c-1).toInt(),header.substring(c,d-1).toInt(),header.substring(d,e-1).toInt()); }
            else if (header.indexOf("GET /setSSTC2Sweep")>=0) {
              int a=header.indexOf(",")+1; int b=header.indexOf(",",a)+1; int c=header.indexOf(",",b)+1; int d=header.indexOf(",",c)+1; int e=header.indexOf(" ",d)+1;
              setSSTC2Sweep(header.substring(a,b-1).toInt(),header.substring(b,c-1).toInt(),header.substring(c,d-1).toInt(),header.substring(d,e-1).toInt()); }
            else { client.println(index_html); }
            
            break; }
          else { currentLine = ""; } }
        else if (c!='\r') {  currentLine+=c; } } }
    header = ""; client.stop(); if (debug) { Serial.println("HTTP Client disconnected."); Serial.println(""); } } }
