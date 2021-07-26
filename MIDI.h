#include <AppleMIDI.h>
APPLEMIDI_CREATE_DEFAULTSESSION_INSTANCE();

#include "midireceive.h"

void initMIDI() {
  MIDI.setHandleNoteOn(midiNoteOn);
  MIDI.setHandleNoteOff(midiNoteOff);
  MIDI.begin();
  ledcSetup(0,1000,8); }

void midiWorker() { MIDI.read(); }
