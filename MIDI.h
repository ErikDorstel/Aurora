#include <AppleMIDI.h>
APPLEMIDI_CREATE_DEFAULTSESSION_INSTANCE();

#include "midireceive.h"

void initMIDI() {
  MIDI.begin();
  MIDI.setHandleNoteOn(midiNoteOn);
  MIDI.setHandleNoteOff(midiNoteOff); }

void midiWorker() { MIDI.read(); }
