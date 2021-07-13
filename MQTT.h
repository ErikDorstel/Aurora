#include "mqttreceive.h"

void initMQTT() {
  mqttClient.setServer(mqttBroker.c_str(),1883);
  mqttClient.setCallback(mqttReceive);
  mqttClient.connect("aurora");
  if (mqttClient.connected() & debug) { Serial.println("MQTT Broker " + mqttBroker + " connected."); }
  if (!mqttClient.connected()) { mqttEnabled=false; if (debug) { Serial.println("MQTT Broker " + mqttBroker + " disabled."); } }
  mqttClient.subscribe("tele/aurora/#");
  mqttClient.subscribe("cmnd/aurora/#");
  mqttClient.subscribe("stat/aurora/#");
  mqttClient.publish("tele/aurora/LWT","Online"); }

void mqttWorker() { if (mqttClient.connected()) { mqttClient.loop(); } else { if (millis()>mqttLastConnect+10000) { mqttLastConnect=millis(); initMQTT(); } } }
