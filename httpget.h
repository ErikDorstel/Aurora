String httpget(String request) {
  String response="";

  // WLAN Choose specific pages

  if (request.indexOf("/connectAP")>=0) {
    int a=request.indexOf(",")+1; int b=request.indexOf(",",a)+1;
    ssidStation=h2a(request.substring(a,b-1)); passwordStation=h2a(request.substring(b));
    if (statusStation==true) { WiFi.disconnect(); delay(100); } WiFi.begin(ssidStation.c_str(),passwordStation.c_str()); delay(1000); }

  else if (request.indexOf("/scanAP")>=0) {
    int indexes=WiFi.scanNetworks(); for (int index=0;index<indexes;++index) { if (WiFi.SSID(index)!="") {
      response+="<div class=\"x1\" onclick=\"setAP\(\'" + WiFi.SSID(index) + "\'\);\">" + WiFi.RSSI(index) + "&nbsp;dB&nbsp;&nbsp;&nbsp;&nbsp;" + WiFi.SSID(index) + "</div>"; } } }

  else if (request.indexOf("/statusAP")>=0) { if (statusStation==true) { response="<div class=\"x1\">WLAN AP " + ssidStation + " connected.</div>"; }
    else { response="<div class=\"x1\">No WLAN AP connected.</div>"; } }

  else if (request.indexOf("/authAP")>=0) { response=a2h(ssidStation) + "," + a2h(passwordStation) + ","; }

  else if (request.indexOf("/chooseAP")>=0) { response=choose_html; }

  // Aurora SSTC-2 specific pages

  else if (request.indexOf("/setSSTC2Para")>=0) {
    int a=request.indexOf(",")+1; int b=request.indexOf(",",a)+1; int c=request.indexOf(",",b)+1;
    setSSTC2Para(request.substring(a,b-1).toInt(),request.substring(b,c-1).toInt(),request.substring(c).toInt()); }

  else if (request.indexOf("/setSSTC2Tone")>=0) {
    int a=request.indexOf(",")+1; int b=request.indexOf(",",a)+1; int c=request.indexOf(",",b)+1; int d=request.indexOf(",",c)+1;
    setSSTC2Tone(request.substring(a,b-1).toInt(),request.substring(b,c-1).toInt(),request.substring(c,d-1).toInt(),request.substring(d).toInt()); }

  else if (request.indexOf("/setSSTC2Sweep")>=0) {
    int a=request.indexOf(",")+1; int b=request.indexOf(",",a)+1; int c=request.indexOf(",",b)+1; int d=request.indexOf(",",c)+1;
    setSSTC2Sweep(request.substring(a,b-1).toInt(),request.substring(b,c-1).toInt(),request.substring(c,d-1).toInt(),request.substring(d).toInt()); }

  else if (request.indexOf("/")>=0) { response=index_html; }

  return response; }
