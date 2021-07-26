void midiNoteOn(byte channel,byte note,byte velocity) {
  setSSTC2Tone((pow(2,(float(note)-69)/12))*440,velocity/2,0,0);
  if (debug) { Serial.println("MIDI Note " + String(note) + " On received."); } }

void midiNoteOff(byte channel,byte note,byte velocity) {
  setSSTC2Tone(0,0,0,0);
  if (debug) { Serial.println("MIDI Note " + String(note) + " Off received."); } }
