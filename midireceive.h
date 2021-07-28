byte channels[]={  0,  2,  4,  6,  8, 10, 12, 14};
byte outGPIOs[]={  4, 13, 16, 17, 21, 22, 23, 25};
byte inGPIOs[]= { 26, 27, 32, 33, 34, 35, 36, 39};
byte midiChan[]={  0,  0,  0,  0,  0,  0,  0,  0};
byte midiNote[]={255,255,255,255,255,255,255,255};

void playTone(byte voice,int tone,byte velocity) {
  if (tone>0) { ledcWriteTone(channels[voice],tone);
    ledcWrite(channels[voice],velocity/8);
    ledcAttachPin(outGPIOs[voice],channels[voice]); }
  else { ledcDetachPin(outGPIOs[voice]); } }

byte mountVoice(byte channel,byte note) {
  byte voice=255; for (byte index=0;index<8;index++) { if (midiNote[index]==255) { voice=index; break; } }
  if (voice!=255) { midiNote[voice]=note; midiChan[voice]=channel; } return voice; }

byte unmountVoice(byte channel,byte note) {
  byte voice=255; for (byte index=0;index<8;index++) { if (midiNote[index]==note & midiChan[index]==channel) { voice=index; break; } }
  if (voice!=255) { midiNote[voice]=255; midiChan[voice]=0; } return voice; }

void midiNoteOn(byte channel,byte note,byte velocity) {
  byte voice=mountVoice(channel,note);
  if (voice!=255) { playTone(voice,(pow(2,(float(note)-69)/12))*440,velocity); }
  if (debug) { Serial.println("MIDI Note " + String(note) + " On on channel " + String(channel) + " received. Play on voice " + String(voice) +"."); } }

void midiNoteOff(byte channel,byte note,byte velocity) {
  byte voice=unmountVoice(channel,note);
  if (voice!=255) { playTone(voice,0,0); }
  if (debug) { Serial.println("MIDI Note " + String(note) + " Off on channel " + String(channel) + " received. Stop on voice " + String(voice) +"."); } }

void midiControlChange(byte channel,byte data1,byte data2) {
  if (data1==120 | data1==123) { for (byte voice=0;voice<8;voice++) { playTone(voice,0,0); midiNote[voice]=255; midiChan[voice]=0; }
    if (debug) { Serial.println("MIDI stop all sounds received."); } } }
