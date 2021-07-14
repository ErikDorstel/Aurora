boolean debug=false;

#include "SSTC-2.h"
#include "WLAN.h"
#include "DNS.h"
#include "HTTP.h"
#include "MQTT.h"

void setup() {
  if (debug) { Serial.begin(115200); }
  initSSTC2(); initWLAN(); }

void loop() { httpWorker(); mqttWorker(); dnsWorker(); }
