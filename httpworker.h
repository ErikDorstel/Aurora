void httpworker() {
  String header="";
  WiFiClient httpClient=tcpServer.available();
  if (httpClient) { String currentLine=""; if (debug) { Serial.println("New HTTP Client connected."); }
    while (httpClient.connected()) {
      if (httpClient.available()) { char c=httpClient.read(); header+=c; if (debug) { Serial.write(c); }
        if (c=='\n') {
          if (currentLine.length()==0) {
            httpClient.println("HTTP/1.1 200 OK");
            httpClient.println("Content-type:text/html");
            httpClient.println("Connection: close");
            httpClient.println();
            int a=header.indexOf("GET "); int b=header.indexOf(" ",a+4); if (a>=0) { httpClient.println(httpget(header.substring(a+4,b))); }
            break; }
          else { currentLine=""; } }
        else if (c!='\r') {  currentLine+=c; } } }
    header = ""; httpClient.stop(); if (debug) { Serial.println("HTTP Client disconnected."); Serial.println(""); } } }
