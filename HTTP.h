#include "index_html.h"
#include "choose_html.h"
#include "hex2ascii.h"
#include "httpget.h"

void httpWorker() {
  WiFiClient httpClient=tcpServer.available(); String header="";
  if (httpClient) { String currentLine="";
    while (httpClient.connected()) {
      if (httpClient.available()) { char c=httpClient.read(); header+=c;
        if (c=='\n') {
          if (currentLine.length()==0) {
            httpClient.println("HTTP/1.1 200 OK");
            httpClient.println("Content-type:text/html");
            httpClient.println("Connection: close");
            httpClient.println();
            int a=header.indexOf("GET "); int b=header.indexOf(" ",a+4);
            if (a>=0) { httpClient.println(httpget(header.substring(a+4,b)));
              if (debug) { Serial.println("HTTP Request " + header.substring(a+4,b) + " received."); } }
            break; }
          else { currentLine=""; } }
        else if (c!='\r') { currentLine+=c; } } }
    header = ""; httpClient.stop(); } }
