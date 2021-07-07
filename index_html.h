char *index_html=R"(

<!DOCTYPE html>
<html><head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<style>
html { font-family:Arial; }
div  { background-color:#888888; color:#ffffff; border:0px; padding:0px; margin:0px; text-align:center; width:100%; user-select:none; display:inline-block; }
.x0a { background-color:#C0A0A0; padding:0.2em 0em 0.1em; width:100%; font-size:1.5em; }
.x0b { background-color:#C0A0A0; padding:0.1em 0em 0.2em; width:100%; font-size:1.2em; }
.x0  { background-color:#C0A0A0; padding:0.4em 0em; width:100%; font-size:1.5em; }
.x1  { background-color:#A0B0C0; padding:0.4em 0em; width:100%; font-size:1.5em; }
.x2  { background-color:#888888; padding:0.4em 0em; width:48%; font-size:1.5em; }
.x3  { background-color:#888888; padding:0.4em 0em; width:32%; font-size:1.5em; }
.x4  { background-color:#888888; padding:0.4em 0em; width:24%; font-size:1.5em; }
</style>
<script>

function SSTC2init() {
  sstc2SpeedArray=[1,2,3,4,5,6,7,8,9,10,15,20,25,30,40,50,75,100,200,500]; sstc2Speed=9; sstc2Start=0; sstc2Power=0; lastTouch=Date.now();
  sstc2Octave=1; sstc2SweepA=0; sstc2SweepB=5000; sstc2SweepDur=3000; sstc2FreqA=50; sstc2FreqB=50; sstc2Ratio=50; sstc2RatioA=50; sstc2RatioB=50;
  doDisplay(); }

function doDisplay() {
  document.getElementById("speedBtn").innerHTML="Speed "+Math.round(5000/sstc2SpeedArray[sstc2Speed])/100+" Hz";
  document.getElementById("startBtn").innerHTML="Start "+sstc2Start/1000+" ms";
  document.getElementById("powerBtn").innerHTML="Power "+sstc2Power/1000+" ms";
  document.getElementById("octaveBtn").innerHTML="Octave "+sstc2Octave;
  document.getElementById("sweepaBtn").innerHTML="Sweep A "+sstc2SweepA+" Hz";
  document.getElementById("sweepbBtn").innerHTML="Sweep B "+sstc2SweepB+" Hz";
  document.getElementById("sweepdurBtn").innerHTML="Duration "+sstc2SweepDur+" ms";
  document.getElementById("freqaBtn").innerHTML="Frequency A "+sstc2FreqA+" Hz";
  document.getElementById("freqbBtn").innerHTML="Frequency B "+sstc2FreqB+" Hz";
  document.getElementById("ratioNoteBtn").innerHTML="Ratio "+sstc2Ratio;
  document.getElementById("ratioSweepBtn").innerHTML="Ratio "+sstc2Ratio;
  document.getElementById("ratioaBtn").innerHTML="Ratio A "+sstc2RatioA;
  document.getElementById("ratiobBtn").innerHTML="Ratio B "+sstc2RatioB; }

function speedDef() { sstc2Speed=9; doRange(1); }
function speedDec() { sstc2Speed+=1; doRange(1); }
function speedInc() { sstc2Speed-=1; doRange(1); }
function startDef() { sstc2Start=0; doRange(2); }
function startDec() { sstc2Start-=500; doRange(2); }
function startInc() { sstc2Start+=500; doRange(2); }
function powerDef() { sstc2Power=0; doRange(1); }
function powerDec() { sstc2Power-=500; doRange(1); }
function powerInc() { sstc2Power+=500; doRange(1); }

function octaveDef() { sstc2Octave=1; doRange(0); }
function octaveDec() { sstc2Octave-=1; doRange(0); }
function octaveInc() { sstc2Octave+=1; doRange(0); }
function ratioDef() { sstc2Ratio=50; doRange(0); }
function ratioDec() { sstc2Ratio-=5; doRange(0); }
function ratioInc() { sstc2Ratio+=5; doRange(0); }

function sweepaDef() { sstc2SweepA=0; doRange(0); }
function sweepaDec() { sstc2SweepA-=250; doRange(0); }
function sweepaInc() { sstc2SweepA+=250; doRange(0); }
function sweepbDef() { sstc2SweepB=5000; doRange(0); }
function sweepbDec() { sstc2SweepB-=250; doRange(0); }
function sweepbInc() { sstc2SweepB+=250; doRange(0); }
function sweepdurDef() { sstc2SweepDur=3000; doRange(0); }
function sweepdurDec() { sstc2SweepDur-=250; doRange(0); }
function sweepdurInc() { sstc2SweepDur+=250; doRange(0); }

function freqaDef() { sstc2FreqA=50; doRange(3); }
function freqaDec() { sstc2FreqA-=1; doRange(3); }
function freqaInc() { sstc2FreqA+=1; doRange(3); }
function freqaDec10() { sstc2FreqA-=10; doRange(3); }
function freqaInc10() { sstc2FreqA+=10; doRange(3); }
function freqbDef() { sstc2FreqB=sstc2FreqA; doRange(3); }
function freqbDec() { sstc2FreqB-=1; doRange(3); }
function freqbInc() { sstc2FreqB+=1; doRange(3); }
function freqbDec10() { sstc2FreqB-=10; doRange(3); }
function freqbInc10() { sstc2FreqB+=10; doRange(3); }
function ratioaDef() { sstc2RatioA=50; doRange(3); }
function ratioaDec() { sstc2RatioA-=5; doRange(3); }
function ratioaInc() { sstc2RatioA+=5; doRange(3); }
function ratiobDef() { sstc2RatioB=50; doRange(3); }
function ratiobDec() { sstc2RatioB-=5; doRange(3); }
function ratiobInc() { sstc2RatioB+=5; doRange(3); }

function toneOff() { sendAJAX("setSSTC2Tone,0,0,0,0"); window.setTimeout("sendAJAX('setSSTC2Tone,0,0,0,0');",10); }
function toneC() { sendAJAX("setSSTC2Tone,"+Math.pow(2,(-9/12)+sstc2Octave)*220+","+sstc2Ratio+",0,0"); }
function toneCx() { sendAJAX("setSSTC2Tone,"+Math.pow(2,(-8/12)+sstc2Octave)*220+","+sstc2Ratio+",0,0"); }
function toneD() { sendAJAX("setSSTC2Tone,"+Math.pow(2,(-7/12)+sstc2Octave)*220+","+sstc2Ratio+",0,0"); }
function toneDx() { sendAJAX("setSSTC2Tone,"+Math.pow(2,(-6/12)+sstc2Octave)*220+","+sstc2Ratio+",0,0"); }
function toneE() { sendAJAX("setSSTC2Tone,"+Math.pow(2,(-5/12)+sstc2Octave)*220+","+sstc2Ratio+",0,0"); }
function toneF() { sendAJAX("setSSTC2Tone,"+Math.pow(2,(-4/12)+sstc2Octave)*220+","+sstc2Ratio+",0,0"); }
function toneFx() { sendAJAX("setSSTC2Tone,"+Math.pow(2,(-3/12)+sstc2Octave)*220+","+sstc2Ratio+",0,0"); }
function toneG() { sendAJAX("setSSTC2Tone,"+Math.pow(2,(-2/12)+sstc2Octave)*220+","+sstc2Ratio+",0,0"); }
function toneGx() { sendAJAX("setSSTC2Tone,"+Math.pow(2,(-1/12)+sstc2Octave)*220+","+sstc2Ratio+",0,0"); }
function toneA() { sendAJAX("setSSTC2Tone,"+Math.pow(2,(0/12)+sstc2Octave)*220+","+sstc2Ratio+",0,0"); }
function toneAx() { sendAJAX("setSSTC2Tone,"+Math.pow(2,(1/12)+sstc2Octave)*220+","+sstc2Ratio+",0,0"); }
function toneH() { sendAJAX("setSSTC2Tone,"+Math.pow(2,(2/12)+sstc2Octave)*220+","+sstc2Ratio+",0,0"); }

function sweepUp() { sendAJAX("setSSTC2Sweep,"+sstc2SweepA+","+sstc2SweepB+","+sstc2SweepDur+","+sstc2Ratio); }
function sweepDown() { sendAJAX("setSSTC2Sweep,"+sstc2SweepB+","+sstc2SweepA+","+sstc2SweepDur+","+sstc2Ratio); }

function doTouch(event) {
  event.preventDefault(); if (Date.now()>lastTouch+50) { lastTouch=Date.now(); buttonObj=document.getElementById("touchBtn").getBoundingClientRect();
    if (event.touches[0]) { touchObj=event.touches[0]; x1=touchObj.pageX-buttonObj.left; y1=touchObj.pageY-buttonObj.top;
      if (x1<0 | x1>buttonObj.width | y1<0 | y1>buttonObj.height) { x1=0; y1=0; } } else { x1=0; y1=0; }
    if (event.touches[1]) { touchObj=event.touches[1]; x2=touchObj.pageX-buttonObj.left; y2=touchObj.pageY-buttonObj.top;
      if (x2<0 | x2>buttonObj.width | y2<0 | y2>buttonObj.height) { x2=0; y2=0; } } else { x2=0; y2=0; }
    sendAJAX("setSSTC2Tone,"+Math.floor(Math.pow(x1/buttonObj.width*17.1,3))+","+Math.floor(y1/buttonObj.height*100)+","+Math.floor(Math.pow(x2/buttonObj.width*17.1,3))+","+Math.floor(y2/buttonObj.height*100)); } }

function doRange(start) {
  if (sstc2Speed<0) { sstc2Speed=0; } if (sstc2Speed>19) { sstc2Speed=19; }
  if (sstc2Start<0) { sstc2Start=0; } if (sstc2Start>12000) { sstc2Start=12000; }
  if (sstc2Power<0) { sstc2Power=0; } if (sstc2Power>12000) { sstc2Power=12000; }
  if (sstc2Start+sstc2Power>12000) { if (start==2) { sstc2Power=12000-sstc2Start; } else { sstc2Start=12000-sstc2Power; } }
  if (sstc2Octave<0) { sstc2Octave=0; } if (sstc2Octave>4) { sstc2Octave=4; }
  if (sstc2SweepA<0) { sstc2SweepA=0; } if (sstc2SweepA>5000) { sstc2SweepA=5000; }
  if (sstc2SweepB<0) { sstc2SweepB=0; } if (sstc2SweepB>5000) { sstc2SweepB=5000; }
  if (sstc2SweepDur<0) { sstc2SweepDur=0; } if (sstc2SweepDur>5000) { sstc2SweepDur=5000; }
  if (sstc2FreqA<0) { sstc2FreqA=0; } if (sstc2FreqA>200) { sstc2FreqA=200; }
  if (sstc2FreqB<0) { sstc2FreqB=0; } if (sstc2FreqB>200) { sstc2FreqB=200; }
  if (sstc2Ratio<0) { sstc2Ratio=0; } if (sstc2Ratio>100) { sstc2Ratio=100; }
  if (sstc2RatioA<0) { sstc2RatioA=0; } if (sstc2RatioA>100) { sstc2RatioA=100; }
  if (sstc2RatioB<0) { sstc2RatioB=0; } if (sstc2RatioB>100) { sstc2RatioB=100; }
  doDisplay();
  if (start==1 | start==2) { sendAJAX("setSSTC2Para"+","+sstc2SpeedArray[sstc2Speed]+","+sstc2Start+","+sstc2Power); }
  if (start==3) { sendAJAX("setSSTC2Tone,"+sstc2FreqA+","+sstc2RatioA+","+sstc2FreqB+","+sstc2RatioB); } }

function sendAJAX(value) {
  if (window.XMLHttpRequest) { ajaxObj=new XMLHttpRequest; } else if (window.ActiveXObject) { ajaxObj=new ActiveXObject("Microsoft.XMLHTTP"); }
  ajaxObj.open("GET",value,false); ajaxObj.setRequestHeader("Content-Type","application/x-www-form-urlencoded"); ajaxObj.send(); }

function guiSwitch(value) {
  document.getElementById("guiSparks").style.display="none"; document.getElementById("guiNotes").style.display="none";
  document.getElementById("guiSweeps").style.display="none"; document.getElementById("guiBeating").style.display="none";
  document.getElementById("guiTouch").style.display="none"; document.getElementById(value).style.display="inline-block"; }

</script></head><body onload="SSTC2init();">

<div><div class="x0a">Aurora</div></div>
<div><div class="x0b">SSTC-2 Controller</div></div>

<div><div class="x2" onclick="guiSwitch('guiSparks');">Sparks</div>
     <div class="x2" onclick="guiSwitch('guiNotes');">Notes</div></div>
<div><div class="x3" onclick="guiSwitch('guiSweeps');">Sweeps</div>
     <div class="x3" onclick="guiSwitch('guiBeating');">Beating</div>
     <div class="x3" onclick="guiSwitch('guiTouch');">Touch</div></div>

<div id="guiSparks" style="display:inline-block;">
<div><div class="x0">Fire Sparks</div></div>
<div><div class="x1" id="speedBtn" onclick="speedDef();"></div></div>
<div><div class="x2" onclick="speedDec();">&#8722;</div>
     <div class="x2" onclick="speedInc();">+</div></div>
<div><div class="x1" id="startBtn" onclick="startDef();"></div></div>
<div><div class="x2" onclick="startDec();">&#8722;</div>
     <div class="x2" onclick="startInc();">+</div></div>
<div><div class="x1" id="powerBtn" onclick="powerDef();"></div></div>
<div><div class="x2" onclick="powerDec();">&#8722;</div>
     <div class="x2" onclick="powerInc();">+</div></div>
</div>

<div id="guiNotes" style="display:none;">
<div><div class="x0">Play Music Notes</div></div>
<div><div class="x4" ontouchstart="toneC();" ontouchend="toneOff();">C</div>
     <div class="x4" ontouchstart="toneCx();" ontouchend="toneOff();">C#</div>
     <div class="x4" ontouchstart="toneD();" ontouchend="toneOff();">D</div>
     <div class="x4" ontouchstart="toneDx();" ontouchend="toneOff();">D#</div></div>
<div><div class="x4" ontouchstart="toneE();" ontouchend="toneOff();">E</div>
     <div class="x4" ontouchstart="toneF();" ontouchend="toneOff();">F</div>
     <div class="x4" ontouchstart="toneFx();" ontouchend="toneOff();">F#</div>
     <div class="x4" ontouchstart="toneG();" ontouchend="toneOff();">G</div></div>
<div><div class="x4" ontouchstart="toneGx();" ontouchend="toneOff();">G#</div>
     <div class="x4" ontouchstart="toneA();" ontouchend="toneOff();">A</div>
     <div class="x4" ontouchstart="toneAx();" ontouchend="toneOff();">A#</div>
     <div class="x4" ontouchstart="toneH();" ontouchend="toneOff();">H</div></div>
<div><div class="x1" id="octaveBtn" onclick="octaveDef();"></div></div>
<div><div class="x2" onclick="octaveDec();">&#8722;</div>
     <div class="x2" onclick="octaveInc();">+</div></div>
<div><div class="x1" id="ratioNoteBtn" onclick="ratioDef();"></div></div>
<div><div class="x2" onclick="ratioDec();">&#8722;</div>
     <div class="x2" onclick="ratioInc();">+</div></div>
</div>

<div id="guiSweeps" style="display:none;">
<div><div class="x0">Play Sweeps</div></div>
<div><div class="x2" onclick="sweepUp();">Sweep Up</div>
     <div class="x2" onclick="sweepDown();">Sweep Down</div></div>
<div><div class="x1" id="sweepaBtn" onclick="sweepaDef();"></div></div>
<div><div class="x2" onclick="sweepaDec();">&#8722;</div>
     <div class="x2" onclick="sweepaInc();">+</div></div>
<div><div class="x1" id="sweepbBtn" onclick="sweepbDef();"></div></div>
<div><div class="x2" onclick="sweepbDec();">&#8722;</div>
     <div class="x2" onclick="sweepbInc();">+</div></div>
<div><div class="x1" id="sweepdurBtn" onclick="sweepdurDef();"></div></div>
<div><div class="x2" onclick="sweepdurDec();">&#8722;</div>
     <div class="x2" onclick="sweepdurInc();">+</div></div>
<div><div class="x1" id="ratioSweepBtn" onclick="ratioDef();"></div></div>
<div><div class="x2" onclick="ratioDec();">&#8722;</div>
     <div class="x2" onclick="ratioInc();">+</div></div>
</div>

<div id="guiBeating" style="display:none;">
<div><div class="x0">Beating Tones</div></div>
<div><div class="x2" onclick="toneOff();">Power Off</div>
     <div class="x2" onclick="doRange(3);">Power On</div></div>
<div><div class="x1" id="freqaBtn" onclick="freqaDef();"></div></div>
<div><div class="x4" onclick="freqaDec10();">&#8722;10</div>
     <div class="x4" onclick="freqaDec();">&#8722;1</div>
     <div class="x4" onclick="freqaInc();">+1</div>
     <div class="x4" onclick="freqaInc10();">+10</div></div>
<div><div class="x1" id="freqbBtn" onclick="freqbDef();"></div></div>
<div><div class="x4" onclick="freqbDec10();">&#8722;10</div>
     <div class="x4" onclick="freqbDec();">&#8722;1</div>
     <div class="x4" onclick="freqbInc();">+1</div>
     <div class="x4" onclick="freqbInc10();">+10</div></div>
<div><div class="x1" id="ratioaBtn" onclick="ratioaDef();"></div></div>
<div><div class="x2" onclick="ratioaDec();">&#8722;</div>
     <div class="x2" onclick="ratioaInc();">+</div></div>
<div><div class="x1" id="ratiobBtn" onclick="ratiobDef();"></div></div>
<div><div class="x2" onclick="ratiobDec();">&#8722;</div>
     <div class="x2" onclick="ratiobInc();">+</div></div>
</div>

<div id="guiTouch" style="display:none;">
<div><div class="x0">Touch Controller</div></div>
<div><div class="x1" id="touchBtn" ontouchstart="doTouch(event);" ontouchmove="doTouch(event);" ontouchend="toneOff();" style="height:10em;">&nbsp;</div></div>
</div>

</body></html>

)";
