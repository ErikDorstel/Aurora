#include "SSTC-2.h"
#include <WiFi.h>
WiFiServer server(80);
const char* ssid="SSTC-2 Aurora";
const char* password="";
String header;
int sstc2SpeedArray[]={1,2,3,4,5,6,7,8,9,10,15,20,25,30,40,50,75,100,200,500}, sstc2Speed=0, sstc2Power=0;

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  server.begin();
  initSSTC2(); }

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

            if (header.indexOf("GET /speed/def") >= 0) { Serial.println("Speed default");
              sstc2Speed=0; setSSTC2Para(sstc2SpeedArray[sstc2Speed]-1,sstc2Power); }
            if (header.indexOf("GET /speed/inc") >= 0) { Serial.println("Speed increment");
              sstc2Speed-=1; if (sstc2Speed<0) { sstc2Speed=0; } setSSTC2Para(sstc2SpeedArray[sstc2Speed]-1,sstc2Power); }
            if (header.indexOf("GET /speed/dec") >= 0) { Serial.println("Speed decrement");
              sstc2Speed+=1; if (sstc2Speed>19) { sstc2Speed=19; } setSSTC2Para(sstc2SpeedArray[sstc2Speed]-1,sstc2Power); }
            if (header.indexOf("GET /power/def") >= 0) { Serial.println("Power default");
              sstc2Power=0; setSSTC2Para(sstc2SpeedArray[sstc2Speed]-1,sstc2Power); }
            if (header.indexOf("GET /power/inc") >= 0) { Serial.println("Power increment");
              sstc2Power+=500; if (sstc2Power>12000) { sstc2Power=12000; } setSSTC2Para(sstc2SpeedArray[sstc2Speed]-1,sstc2Power); }
            if (header.indexOf("GET /power/dec") >= 0) { Serial.println("Power decrement");
              sstc2Power-=500; if (sstc2Power<00) { sstc2Power=0; } setSSTC2Para(sstc2SpeedArray[sstc2Speed]-1,sstc2Power); }
            
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #C0D0E0; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #888888; font-size: 50px;}</style></head>");
            client.println("<body><h1>Aurora</h1><h2>SSTC-2 Controller</h2>");

            client.println("<p><a href=\"/speed/def\"><button class=\"button\">Speed "); client.println(1/(sstc2SpeedArray[sstc2Speed]*0.02)); client.println(" Hz</button></a></p>");
            client.println("<p><a href=\"/speed/dec\"><button class=\"button button2\">&#8722;</button></a>");
            client.println("   <a href=\"/speed/inc\"><button class=\"button button2\">+</button></a></p>");
            client.println("<p><a href=\"/power/def\"><button class=\"button\">Power "); client.println(sstc2Power*0.001); client.println(" ms</button></a></p>");
            client.println("<p><a href=\"/power/dec\"><button class=\"button button2\">&#8722;</button></a>");
            client.println("   <a href=\"/power/inc\"><button class=\"button button2\">+</button></a></p>");
            
            client.println("</body></html>");
            client.println();
            break; }
          else { currentLine = ""; } }
        else if (c != '\r') {  currentLine += c; } } }
    header = ""; client.stop(); Serial.println("Client disconnected."); Serial.println(""); } }
