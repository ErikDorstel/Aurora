#include <AppleMIDI.h>
APPLEMIDI_CREATE_DEFAULTSESSION_INSTANCE();

#include "midireceive.h"

void IRAM_ATTR ioChange() {
  if (digitalRead(inGPIOs[0])==LOW & digitalRead(inGPIOs[1])==LOW & digitalRead(inGPIOs[2])==LOW & digitalRead(inGPIOs[3])==LOW &
    digitalRead(inGPIOs[4])==LOW & digitalRead(inGPIOs[5])==LOW & digitalRead(inGPIOs[6])==LOW & digitalRead(inGPIOs[7])==LOW)
    { digitalWrite(phaseOut,HIGH); digitalWrite(onBoardLED,LOW); }
  else { digitalWrite(phaseOut,LOW); digitalWrite(onBoardLED,HIGH); } }

void initMIDI() {
  MIDI.setHandleNoteOn(midiNoteOn);
  MIDI.setHandleNoteOff(midiNoteOff);
  MIDI.setHandleControlChange(midiControlChange);
  MIDI.begin(MIDI_CHANNEL_OMNI);

  for (byte index=0;index<8;index++) {
    pinMode(inGPIOs[index],INPUT);
    pinMode(outGPIOs[index],OUTPUT);
    attachInterrupt(inGPIOs[index],ioChange,CHANGE);
    ledcSetup(channels[index],1000,8); } }

void midiWorker() { MIDI.read(); }
