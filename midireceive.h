void midiNoteOn(byte channel,byte note,byte velocity) {
  ledcWriteTone(0,(pow(2,(float(note)-69)/12))*440);
  ledcWrite(0,velocity/8);
  ledcAttachPin(phaseOut,0);
  if (debug) { Serial.println("MIDI Note " + String(note) + " On on channel " + String(channel) + " received."); } }

void midiNoteOff(byte channel,byte note,byte velocity) {
  ledcDetachPin(phaseOut);
  if (debug) { Serial.println("MIDI Note " + String(note) + " Off on channel " + String(channel) + " received."); } }
