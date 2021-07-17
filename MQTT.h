#include "mqttreceive.h"

void initMQTT() {
  mqttClient.setServer(mqttBroker.c_str(),1883);
  mqttClient.setCallback(mqttReceive);
  if (mqttClient.connect("aurora","tele/aurora/LWT",0,1,"Offline")) {
    mqttClient.subscribe("cmnd/aurora/#");
    mqttClient.publish("tele/aurora/LWT","Online",1);
    if (debug) { Serial.println("MQTT Broker " + mqttBroker + " connected."); } }
  else { mqttEnabled=false; if (debug) { Serial.println("MQTT Broker " + mqttBroker + " disabled."); } } }

void mqttWorker() {
  if (mqttEnabled) { if (mqttClient.connected()) { mqttClient.loop(); }
    else if (millis()>mqttLastConnect+10000) { mqttLastConnect=millis(); initMQTT(); } } }
