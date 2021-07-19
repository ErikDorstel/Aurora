#include "mqttreceive.h"

void initMQTT() {
  mqttClient.setSocketTimeout(5);
  mqttClient.setServer(mqttBroker.c_str(),1883);
  mqttClient.setCallback(mqttReceive);
  if (mqttClient.connect("aurora.tesla","tele/aurora.tesla/LWT",0,1,"Offline")) {
    mqttClient.subscribe("cmnd/aurora.tesla/#");
    mqttClient.publish("tele/aurora.tesla/LWT","Online",1);
    if (debug) { Serial.println("MQTT Broker " + mqttBroker + " connected."); } }
  else { mqttEnabled=false; if (debug) { Serial.println("MQTT Broker " + mqttBroker + " disabled."); } } }

void mqttWorker() {
  if (mqttEnabled) { if (mqttClient.connected()) { mqttClient.loop(); }
    else if (millis()>mqttLastConnect+5000) { mqttLastConnect=millis(); initMQTT(); } } }
