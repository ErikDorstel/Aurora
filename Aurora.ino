boolean debug=false;

#include "SSTC-2.h"
#include "WLAN.h"
#include "DNS.h"
#include "HTTP.h"
#include "MQTT.h"
#include "MIDI.h"

void setup() {
  if (debug) { Serial.begin(115200); }
  initSSTC2(); initWLAN(); initMIDI(); }

void loop() { httpWorker(); mqttWorker(); dnsWorker(); midiWorker(); }
