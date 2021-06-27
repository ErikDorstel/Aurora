// SSTC2 Library
// 2021 Erik Dorstel
// call "initSSTC2();" first
// call "modeSSTC2sync();" or "modeSSTC2async();" second
// call "setSSTC2Para(speed,start,power);" to set parameters for sync mode
// call "setSSTC2Tone(freq,power);" to set parameters for async mode

const byte onBoardLED=2, phaseIn=18, phaseOut=19; byte SSTC2mode=0;
hw_timer_t * timer1 = NULL; hw_timer_t * timer2 = NULL; hw_timer_t * timer3 = NULL;

void IRAM_ATTR onPhase() { detachInterrupt(phaseIn); timerRestart(timer1); timerAlarmEnable(timer1); timerRestart(timer2); timerAlarmEnable(timer2); }
void IRAM_ATTR onTimer1() { attachInterrupt(phaseIn,onPhase,RISING); }
void IRAM_ATTR onTimer2() { digitalWrite(phaseOut,LOW); digitalWrite(onBoardLED,HIGH); timerRestart(timer3); timerAlarmEnable(timer3); }
void IRAM_ATTR onTimer3() { digitalWrite(phaseOut,HIGH); digitalWrite(onBoardLED,LOW); }

void initSSTC2() {
  pinMode(onBoardLED,OUTPUT); pinMode(phaseIn,INPUT); pinMode(phaseOut,OUTPUT);
  digitalWrite(phaseOut,HIGH); digitalWrite(onBoardLED,LOW);
  // controls speed by masking various cycles
  timer1=timerBegin(0,80,true); timerAttachInterrupt(timer1,&onTimer1,true); timerAlarmWrite(timer1,19000,false);
  // controls start by adjusting enable timepoint
  timer2=timerBegin(1,80,true); timerAttachInterrupt(timer2,&onTimer2,true); timerAlarmWrite(timer2,0,false);
  // controls power by adjusting disable timepoint
  timer3=timerBegin(2,80,true); timerAttachInterrupt(timer3,&onTimer3,true); timerAlarmWrite(timer3,0,false); }

void modeSSTC2sync() {
  ledcDetachPin(phaseOut); delay(30);
  digitalWrite(phaseOut,HIGH); digitalWrite(onBoardLED,LOW);
  // trigger on rising edge of input sync signal
  attachInterrupt(phaseIn,onPhase,RISING); }
  
void modeSSTC2async() {
  detachInterrupt(phaseIn); delay(30);
  digitalWrite(phaseOut,HIGH); digitalWrite(onBoardLED,LOW); }

void setSSTC2Para(int speed,int start,int power) {
  if (SSTC2mode!=1) { modeSSTC2sync(); SSTC2mode=1; }
  timerAlarmWrite(timer1,(speed*20000)-1000,false);
  timerAlarmWrite(timer2,start,false);
  timerAlarmWrite(timer3,power,false); }

void setSSTC2Tone(int freq, int power) {
  if (SSTC2mode!=2) { modeSSTC2async(); SSTC2mode=2; }
  if (freq==0) { ledcDetachPin(phaseOut); digitalWrite(phaseOut,HIGH); digitalWrite(onBoardLED,LOW); }
  // uses channel 0 on timer 0
  else { ledcSetup(0,freq,8); ledcAttachPin(phaseOut,0); ledcWrite(0,255-power); digitalWrite(onBoardLED,HIGH); } }

void setSSTC2Sweep(int freq1, int freq2, int duration, int power) {
  if (freq1<freq2) { for (int freq=freq1;freq<=freq2;freq+=(freq2-freq1)*20/duration) { setSSTC2Tone(freq,127); delay(20); } setSSTC2Tone(0,0); }
  if (freq1>freq2) { for (int freq=freq1;freq>=freq2;freq-=(freq1-freq2)*20/duration) { setSSTC2Tone(freq,127); delay(20); } setSSTC2Tone(0,0); } }
  
