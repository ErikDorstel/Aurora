boolean debug=true;

#include "SSTC-2.h"
#include "WLAN.h"
#include "HTTP.h"
#include "MQTT.h"

void setup() {
  if (debug) { Serial.begin(115200); }
  initSSTC2(); initWLAN(); }

void loop() { httpWorker(); mqttWorker(); }
