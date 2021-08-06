#include <AppleMIDI.h>
APPLEMIDI_CREATE_INSTANCE(WiFiUDP,MIDI,"SSTC-2 Aurora",5004);

#include "midireceive.h"

void initMIDI() {
  MIDI.setHandleNoteOn(midiNoteOn);
  MIDI.setHandleNoteOff(midiNoteOff);
  MIDI.setHandleControlChange(midiControlChange);
  MIDI.begin(MIDI_CHANNEL_OMNI); }

void midiWorker() { MIDI.read(); }
