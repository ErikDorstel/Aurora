// SSTC2 Library
// 2021 Erik Dorstel
// call "initSSTC2();" first
// call "setSSTC2Para(speed,start,power);" to set parameters for sync mode with timers
// call "setSSTC2Tone(freqA,ratioA,freqB,ratioB);" to set parameters for async mode with timers
// call "setSSTC2Sweep(freqA,freqB,duration,ratio);" to set parameters for async mode
// call "setSSTC2PWM(voice,freq,ratio);" to set parameters for async mode with pwm

const byte onBoardLED=2, phaseIn=18, phaseOut=19; byte SSTC2mode=0;
hw_timer_t * timer1 = NULL; hw_timer_t * timer2 = NULL; hw_timer_t * timer3 = NULL; hw_timer_t * timer4 = NULL;

byte channels[]={  0,  2,  4,  6,  8, 10, 12, 14};
byte outGPIOs[]={  4, 13, 16, 17, 21, 22, 23, 25};
byte inGPIOs[]= { 26, 27, 32, 33, 34, 35, 36, 39};

void IRAM_ATTR onPhase() { detachInterrupt(phaseIn); timerRestart(timer1); timerAlarmEnable(timer1); timerRestart(timer2); timerAlarmEnable(timer2); }
void IRAM_ATTR onTimerSync1() { attachInterrupt(phaseIn,onPhase,RISING); }
void IRAM_ATTR onTimerSync2() { digitalWrite(phaseOut,LOW); digitalWrite(onBoardLED,HIGH); timerRestart(timer3); timerAlarmEnable(timer3); }
void IRAM_ATTR onTimerSync3() { digitalWrite(phaseOut,HIGH); digitalWrite(onBoardLED,LOW); }
void IRAM_ATTR onTimerAsync1() { digitalWrite(phaseOut,LOW); digitalWrite(onBoardLED,HIGH); timerRestart(timer2); timerAlarmEnable(timer2); }
void IRAM_ATTR onTimerAsync2() { digitalWrite(phaseOut,HIGH); digitalWrite(onBoardLED,LOW); }
void IRAM_ATTR onTimerAsync3() { digitalWrite(phaseOut,LOW); digitalWrite(onBoardLED,HIGH); timerRestart(timer4); timerAlarmEnable(timer4); }
void IRAM_ATTR onTimerAsync4() { digitalWrite(phaseOut,HIGH); digitalWrite(onBoardLED,LOW); }
void IRAM_ATTR ioChange() {
  if (digitalRead(inGPIOs[0])==LOW & digitalRead(inGPIOs[1])==LOW & digitalRead(inGPIOs[2])==LOW & digitalRead(inGPIOs[3])==LOW &
    digitalRead(inGPIOs[4])==LOW & digitalRead(inGPIOs[5])==LOW & digitalRead(inGPIOs[6])==LOW & digitalRead(inGPIOs[7])==LOW)
    { digitalWrite(phaseOut,HIGH); digitalWrite(onBoardLED,LOW); }
  else { digitalWrite(phaseOut,LOW); digitalWrite(onBoardLED,HIGH); } }

void initSSTC2() {
  pinMode(onBoardLED,OUTPUT); pinMode(phaseIn,INPUT); pinMode(phaseOut,OUTPUT);
  digitalWrite(phaseOut,HIGH); digitalWrite(onBoardLED,LOW);
  timer1=timerBegin(0,80,true); timer2=timerBegin(1,80,true); timer3=timerBegin(2,80,true); timer4=timerBegin(3,80,true);
  for (byte index=0;index<8;index++) { pinMode(inGPIOs[index],INPUT); pinMode(outGPIOs[index],OUTPUT);
    digitalWrite(outGPIOs[index],LOW); attachInterrupt(inGPIOs[index],ioChange,CHANGE); } }

void modeSSTC2sync() {
  timerAlarmDisable(timer1); timerAlarmDisable(timer2); timerAlarmDisable(timer3); timerAlarmDisable(timer4); delay(30);
  digitalWrite(phaseOut,HIGH); digitalWrite(onBoardLED,LOW);
  timerAttachInterrupt(timer1,&onTimerSync1,true); timerAlarmWrite(timer1,19000,false); // controls speed by masking various cycles
  timerAttachInterrupt(timer2,&onTimerSync2,true); timerAlarmWrite(timer2,0,false); // controls start by adjusting enable timepoint
  timerAttachInterrupt(timer3,&onTimerSync3,true); timerAlarmWrite(timer3,0,false); // controls power by adjusting disable timepoint
  attachInterrupt(phaseIn,onPhase,RISING); } // trigger on rising edge of input sync signal
  
void modeSSTC2async() {
  detachInterrupt(phaseIn); timerAlarmDisable(timer1); timerAlarmDisable(timer2); timerAlarmDisable(timer3); timerAlarmDisable(timer4); delay(30);
  digitalWrite(phaseOut,HIGH); digitalWrite(onBoardLED,LOW);
  timerAttachInterrupt(timer1,&onTimerAsync1,true); timerAlarmWrite(timer1,0,true); // controls tone a frequency
  timerAttachInterrupt(timer2,&onTimerAsync2,true); timerAlarmWrite(timer2,0,false); // controls tone a ratio
  timerAttachInterrupt(timer3,&onTimerAsync3,true); timerAlarmWrite(timer3,0,true); // controls tone b frequency
  timerAttachInterrupt(timer4,&onTimerAsync4,true); timerAlarmWrite(timer4,0,false); } // controls tone b ratio

void setSSTC2Para(int speed,int start,int power) {
  if (SSTC2mode!=1) { modeSSTC2sync(); SSTC2mode=1; }
  timerAlarmWrite(timer1,(speed*20000)-1000,false); timerAlarmWrite(timer2,start,false); timerAlarmWrite(timer3,power,false); }

void setSSTC2Tone(int freqA, int ratioA, int freqB, int ratioB) {
  if (SSTC2mode!=2) { modeSSTC2async(); SSTC2mode=2; } if (ratioA==100) { ratioA=99; } if (ratioB==100) { ratioB=99; }
  if (freqA>0 & ratioA>0) { timerAlarmWrite(timer1,1000000/freqA,true); timerAlarmWrite(timer2,10000*ratioA/freqA,false); timerRestart(timer1); timerAlarmEnable(timer1); } else { timerAlarmDisable(timer1); }
  if (freqB>0 & ratioB>0) { timerAlarmWrite(timer3,1000000/freqB,true); timerAlarmWrite(timer4,10000*ratioB/freqB,false); timerRestart(timer3); timerAlarmEnable(timer3); } else { timerAlarmDisable(timer3); } }

void setSSTC2PWM(byte voice,int freq,int ratio) {
  if (freq>0 & ratio>0 & voice>=0 & voice<=7) { ledcDetachPin(outGPIOs[voice]); ledcSetup(channels[voice],freq,10); ledcWrite(channels[voice],ratio*10.23); ledcAttachPin(outGPIOs[voice],channels[voice]); }
  else { ledcDetachPin(outGPIOs[voice]); } }

void setSSTC2Sweep(int freq1, int freq2, int duration, int ratio) {
  int step; if (duration>0) { step=abs(freq1-freq2)*20/duration; } else { step=0; }
  if (freq1<freq2 & step>0) { for (int freq=freq1;freq<=freq2;freq+=step) { setSSTC2PWM(0,freq,ratio); delay(20); } setSSTC2PWM(0,0,0); }
  if (freq1>freq2 & step>0) { for (int freq=freq1;freq>=freq2;freq-=step) { setSSTC2PWM(0,freq,ratio); delay(20); } setSSTC2PWM(0,0,0); } }
