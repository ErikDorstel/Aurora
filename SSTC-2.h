// SSTC2 Library
// 2021 Erik Dorstel
// call "initSSTC2();" first
// call "setSSTC2Para(speed,start,power);" to set parameters

const byte onBoardLED=2, phaseIn=18, phaseOut=19;
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
  timer3=timerBegin(2,80,true); timerAttachInterrupt(timer3,&onTimer3,true); timerAlarmWrite(timer3,0,false);

  // trigger on rising edge of input sync signal
  attachInterrupt(phaseIn,onPhase,RISING); }

void setSSTC2Para(int speed,int start,int power) { timerAlarmWrite(timer1,19000+(speed*20000),false); timerAlarmWrite(timer2,start,false); timerAlarmWrite(timer3,power,false); }
