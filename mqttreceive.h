void mqttReceive(char* chartopic, byte* bytemessage, unsigned int bytelength) {
  String topic; for (int index=0;index<strlen(chartopic);index++) { topic+=(char)chartopic[index]; }
  String message; for (int index=0;index<bytelength;index++) { message+=(char)bytemessage[index]; }
  if (debug) { Serial.println("MQTT Message " + topic + " " + message + " from " + mqttBroker + "."); }

  if (topic=="cmnd/aurora/status" & (message=="0" | message=="10")) {
    String response="{\"StatusSNS\":{\"Device\":\"Aurora SSTC-2\",\"Topics\":{\"cmnd/aurora/para\",\"cmnd/aurora/tone\",\"cmnd/aurora/sweep\"}}}";
    mqttClient.publish("stat/aurora/STATUS10",response.c_str()); }

  if (topic=="cmnd/aurora/status" & (message=="0" | message=="11")) {
    String response="{\"StatusSTS\":{\"POWER\":\"OFF\",\"WLAN\":{\"SSID\":\"" + ssidStation + "\",\"IP\":\"" + WiFi.localIP().toString() + "\",\"RSSI\":\"" + WiFi.RSSI() + " dB\"}}}";
    mqttClient.publish("stat/aurora/STATUS11",response.c_str()); }

  else if (topic=="cmnd/aurora/para") {
    int a=message.indexOf(",")+1; int b=message.indexOf(",",a)+1;
    setSSTC2Para(message.substring(0,a-1).toInt(),message.substring(a,b-1).toInt(),message.substring(b).toInt()); }

  else if (topic=="cmnd/aurora/tone") {
    int a=message.indexOf(",")+1; int b=message.indexOf(",",a)+1; int c=message.indexOf(",",b)+1;
    setSSTC2Tone(message.substring(0,a-1).toInt(),message.substring(a,b-1).toInt(),message.substring(b,c-1).toInt(),message.substring(c).toInt()); }

  else if (topic=="cmnd/aurora/sweep") {
    int a=message.indexOf(",")+1; int b=message.indexOf(",",a)+1; int c=message.indexOf(",",b)+1;
    setSSTC2Sweep(message.substring(0,a-1).toInt(),message.substring(a,b-1).toInt(),message.substring(b,c-1).toInt(),message.substring(c).toInt()); } }
