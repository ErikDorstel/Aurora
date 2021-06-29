#include <WiFi.h>
#include "SSTC-2.h"
#include "index_html.h"
WiFiServer server(80);
const char* ssid="SSTC-2 Aurora";
const char* password="";
String header;

void setup() {
  Serial.begin(115200);
  initSSTC2();
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: "); Serial.println(IP);
  server.begin(); }

void loop() {
  WiFiClient client = server.available();
  if (client) { Serial.println("New Client."); String currentLine = "";
    while (client.connected()) {
      if (client.available()) { char c = client.read(); Serial.write(c); header += c;
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            if (header.indexOf("GET /setSSTC2Para") >= 0) {
              int a=header.indexOf(",")+1; int b=header.indexOf(",",a)+1; int c=header.indexOf(",",b)+1; int d=header.indexOf(" ",c)+1;
              setSSTC2Para(header.substring(a,b-1).toInt(),header.substring(b,c-1).toInt(),header.substring(c,d-1).toInt()); }
            else if (header.indexOf("GET /setSSTC2Tone") >= 0) {
              int a=header.indexOf(",")+1; int b=header.indexOf(",",a)+1; int c=header.indexOf(",",b)+1; int d=header.indexOf(",",c)+1; int e=header.indexOf(" ",d)+1;
              setSSTC2Tone(header.substring(a,b-1).toInt(),header.substring(b,c-1).toInt(),header.substring(c,d-1).toInt(),header.substring(d,e-1).toInt()); }
            else if (header.indexOf("GET /setSSTC2Sweep") >= 0) {
              int a=header.indexOf(",")+1; int b=header.indexOf(",",a)+1; int c=header.indexOf(",",b)+1; int d=header.indexOf(",",c)+1; int e=header.indexOf(" ",d)+1;
              setSSTC2Sweep(header.substring(a,b-1).toInt(),header.substring(b,c-1).toInt(),header.substring(c,d-1).toInt(),header.substring(d,e-1).toInt()); }
            else { client.println(index_html); }
            break; }
          else { currentLine = ""; } }
        else if (c != '\r') {  currentLine += c; } } }
    header = ""; client.stop(); Serial.println("Client disconnected."); Serial.println(""); } }
