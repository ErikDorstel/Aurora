String httpget(String request) {
  String response="";

  // Aurora SSTC-2 specific pages

  if (request.indexOf("/setSSTC2Para")>=0) {
    int a=request.indexOf(",")+1; int b=request.indexOf(",",a)+1; int c=request.indexOf(",",b)+1;
    setSSTC2Para(request.substring(a,b-1).toInt(),request.substring(b,c-1).toInt(),request.substring(c).toInt()); }

  else if (request.indexOf("/setSSTC2Tone")>=0) {
    int a=request.indexOf(",")+1; int b=request.indexOf(",",a)+1; int c=request.indexOf(",",b)+1; int d=request.indexOf(",",c)+1;
    setSSTC2PWM(0,request.substring(a,b-1).toInt(),request.substring(b,c-1).toInt()*2.55);
    setSSTC2PWM(1,request.substring(c,d-1).toInt(),request.substring(d).toInt()*2.55); }
    //setSSTC2Tone(request.substring(a,b-1).toInt(),request.substring(b,c-1).toInt(),request.substring(c,d-1).toInt(),request.substring(d).toInt()); }

  else if (request.indexOf("/setSSTC2Sweep")>=0) {
    int a=request.indexOf(",")+1; int b=request.indexOf(",",a)+1; int c=request.indexOf(",",b)+1; int d=request.indexOf(",",c)+1;
    setSSTC2Sweep(request.substring(a,b-1).toInt(),request.substring(b,c-1).toInt(),request.substring(c,d-1).toInt(),request.substring(d).toInt()); }

  // WLAN Choose specific pages

  else if (request.indexOf("/chooseAP")>=0) { response=choose_html; }

  else if (request.indexOf("/statusAP")>=0) { if (statusStation==true) { response="<div class=\"x1\">WLAN AP " + ssidStation + " connected.</div>";
    response+="<div class=\"x1\">IP Address " + WiFi.localIP().toString() + "</div>"; } else { response="<div class=\"x1\">No WLAN AP connected.</div>"; } }

  else if (request.indexOf("/configAP")>=0) { response=a2h(ssidStation) + "," + a2h(passwordStation) + "," + a2h(mqttBroker) + "," + String(mqttEnabled) + ","; }

  else if (request.indexOf("/statusMQTT")>=0) { if (mqttClient.connected()==true) { response="<div class=\"x1\">MQTT Broker " + mqttBroker + " connected.</div>"; }
    else { response="<div class=\"x1\">MQTT Broker not connected.</div>"; } }

  else if (request.indexOf("/scanAP")>=0) {
    int indexes=WiFi.scanNetworks(); for (int index=0;index<indexes;++index) { if (WiFi.SSID(index)!="") {
      response+="<div class=\"x1\" onclick=\"setAP(\'" + WiFi.SSID(index) + "\');\">" + WiFi.RSSI(index) + "&nbsp;dB&nbsp;&nbsp;&nbsp;&nbsp;" + WiFi.SSID(index) + "</div>"; } } }

  else if (request.indexOf("/connectAP")>=0) {
    int a=request.indexOf(",")+1; int b=request.indexOf(",",a)+1; int c=request.indexOf(",",b)+1; int d=request.indexOf(",",c)+1;
    ssidStation=h2a(request.substring(a,b-1)); passwordStation=h2a(request.substring(b,c-1)); mqttBroker=h2a(request.substring(c,d-1));
    if (request.substring(d)=="false") { mqttEnabled=false; } else { mqttEnabled=true; } reconnectWLAN(); }

  // Default page

  else { response=index_html; }

  return response; }
