char *index_html=R"(

<!DOCTYPE html>
<html><head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<style>
html { font-family:Arial; }
div  { background-color:#888888; color:#ffffff; border:0px; padding:0px; margin:0px; text-align:center; width:100%; user-select:none; display:inline-block; }
.x0  { background-color:#C0A0A0; padding:0.5em 0em; width:100%; font-size:1.5em; }
.x1  { background-color:#A0B0C0; padding:0.5em 0em; width:100%; font-size:1.5em; }
.x2  { background-color:#888888; padding:0.5em 0em; width:48%; font-size:1.5em; }
.x3  { background-color:#888888; padding:0.5em 0em; width:32%; font-size:1.5em; }
.x4  { background-color:#888888; padding:0.5em 0em; width:24%; font-size:1.5em; }
</style>
<script>

function SSTC2init() {
  sstc2SpeedArray=[1,2,3,4,5,6,7,8,9,10,15,20,25,30,40,50,75,100,200,500]; sstc2Speed=0; sstc2Start=0; sstc2Power=0;
  sstc2Octave=1; sstc2SweepA=0; sstc2SweepB=5000; sstc2SweepDur=3000; sstc2FreqA=50; sstc2FreqB=50; sstc2RatioA=50; sstc2RatioB=50;
  document.getElementById("speedBtn").innerHTML="Speed "+Math.round(5000/sstc2SpeedArray[sstc2Speed])/100+" Hz";
  document.getElementById("startBtn").innerHTML="Start "+sstc2Start/1000+" ms";
  document.getElementById("powerBtn").innerHTML="Power "+sstc2Power/1000+" ms";
  document.getElementById("octaveBtn").innerHTML="Octave "+sstc2Octave;
  document.getElementById("sweepaBtn").innerHTML="Sweep A "+sstc2SweepA+" Hz";
  document.getElementById("sweepbBtn").innerHTML="Sweep B "+sstc2SweepB+" Hz";
  document.getElementById("sweepdurBtn").innerHTML="Duration "+sstc2SweepDur+" ms";
  document.getElementById("freqaBtn").innerHTML="Frequency A "+sstc2FreqA+" Hz";
  document.getElementById("freqbBtn").innerHTML="Frequency B "+sstc2FreqB+" Hz";
  document.getElementById("ratioaBtn").innerHTML="Ratio "+sstc2RatioA;
  document.getElementById("ratiobBtn").innerHTML="Ratio "+sstc2RatioB; }

function speedDef() { sstc2Speed=0; doRangeSync(0); }
function speedDec() { sstc2Speed+=1; doRangeSync(0); }
function speedInc() { sstc2Speed-=1; doRangeSync(0); }
function startDef() { sstc2Start=0; doRangeSync(1); }
function startDec() { sstc2Start-=500; doRangeSync(1); }
function startInc() { sstc2Start+=500; doRangeSync(1); }
function powerDef() { sstc2Power=0; doRangeSync(0); }
function powerDec() { sstc2Power-=500; doRangeSync(0); }
function powerInc() { sstc2Power+=500; doRangeSync(0); }

function octaveDef() { sstc2Octave=1; doRangeAsync(0); }
function octaveDec() { sstc2Octave-=1; doRangeAsync(0); }
function octaveInc() { sstc2Octave+=1; doRangeAsync(0); }

function sweepaDef() { sstc2SweepA=0; doRangeAsync(0); }
function sweepaDec() { sstc2SweepA-=250; doRangeAsync(0); }
function sweepaInc() { sstc2SweepA+=250; doRangeAsync(0); }
function sweepbDef() { sstc2SweepB=5000; doRangeAsync(0); }
function sweepbDec() { sstc2SweepB-=250; doRangeAsync(0); }
function sweepbInc() { sstc2SweepB+=250; doRangeAsync(0); }
function sweepdurDef() { sstc2SweepDur=3000; doRangeAsync(0); }
function sweepdurDec() { sstc2SweepDur-=250; doRangeAsync(0); }
function sweepdurInc() { sstc2SweepDur+=250; doRangeAsync(0); }

function freqaDef() { sstc2FreqA=50; doRangeAsync(1); }
function freqaDec() { sstc2FreqA-=1; doRangeAsync(1); }
function freqaInc() { sstc2FreqA+=1; doRangeAsync(1); }
function freqaDec10() { sstc2FreqA-=10; doRangeAsync(1); }
function freqaInc10() { sstc2FreqA+=10; doRangeAsync(1); }
function freqbDef() { sstc2FreqB=sstc2FreqA; doRangeAsync(1); }
function freqbDec() { sstc2FreqB-=1; doRangeAsync(1); }
function freqbInc() { sstc2FreqB+=1; doRangeAsync(1); }
function freqbDec10() { sstc2FreqB-=10; doRangeAsync(1); }
function freqbInc10() { sstc2FreqB+=10; doRangeAsync(1); }
function ratioaDef() { sstc2RatioA=50; doRangeAsync(1); }
function ratioaDec() { sstc2RatioA-=5; doRangeAsync(1); }
function ratioaInc() { sstc2RatioA+=5; doRangeAsync(1); }
function ratiobDef() { sstc2RatioB=50; doRangeAsync(1); }
function ratiobDec() { sstc2RatioB-=5; doRangeAsync(1); }
function ratiobInc() { sstc2RatioB+=5; doRangeAsync(1); }

function toneOff() { sendAJAX("setSSTC2Tone,0,0,0,0"); }
function toneC() { sendAJAX("setSSTC2Tone"+","+Math.pow(2,(-9/12)+sstc2Octave)*220+",0,"+sstc2RatioA+",0"); }
function toneD() { sendAJAX("setSSTC2Tone"+","+Math.pow(2,(-7/12)+sstc2Octave)*220+",0,"+sstc2RatioA+",0"); }
function toneE() { sendAJAX("setSSTC2Tone"+","+Math.pow(2,(-5/12)+sstc2Octave)*220+",0,"+sstc2RatioA+",0"); }
function toneF() { sendAJAX("setSSTC2Tone"+","+Math.pow(2,(-4/12)+sstc2Octave)*220+",0,"+sstc2RatioA+",0"); }
function toneG() { sendAJAX("setSSTC2Tone"+","+Math.pow(2,(-2/12)+sstc2Octave)*220+",0,"+sstc2RatioA+",0"); }
function toneA() { sendAJAX("setSSTC2Tone"+","+Math.pow(2,(0/12)+sstc2Octave)*220+",0,"+sstc2RatioA+",0"); }
function toneH() { sendAJAX("setSSTC2Tone"+","+Math.pow(2,(2/12)+sstc2Octave)*220+",0,"+sstc2RatioA+",0"); }
function toneCn() { sendAJAX("setSSTC2Tone"+","+Math.pow(2,(3/12)+sstc2Octave)*220+",0,"+sstc2RatioA+",0"); }

function sweepUp() { sendAJAX("setSSTC2Sweep,"+sstc2SweepA+","+sstc2SweepB+","+sstc2SweepDur+","+sstc2RatioA); }
function sweepDown() { sendAJAX("setSSTC2Sweep,"+sstc2SweepB+","+sstc2SweepA+","+sstc2SweepDur+","+sstc2RatioA); }

function doRangeSync(start) {
  if (sstc2Speed<0) { sstc2Speed=0; } if (sstc2Speed>19) { sstc2Speed=19; }
  if (sstc2Start<0) { sstc2Start=0; } if (sstc2Start>12000) { sstc2Start=12000; }
  if (sstc2Power<0) { sstc2Power=0; } if (sstc2Power>12000) { sstc2Power=12000; }
  if (sstc2Start+sstc2Power>12000) { if (start==1) { sstc2Power=12000-sstc2Start; } else sstc2Start=12000-sstc2Power; }
  document.getElementById("speedBtn").innerHTML="Speed "+Math.round(5000/sstc2SpeedArray[sstc2Speed])/100+" Hz";
  document.getElementById("startBtn").innerHTML="Start "+sstc2Start/1000+" ms";
  document.getElementById("powerBtn").innerHTML="Power "+sstc2Power/1000+" ms";
  sendAJAX("setSSTC2Para"+","+sstc2SpeedArray[sstc2Speed]+","+sstc2Start+","+sstc2Power); }

function doRangeAsync(start) {
  if (sstc2Octave<0) { sstc2Octave=0; }
  if (sstc2Octave>4) { sstc2Octave=4; }
  if (sstc2SweepA<0) { sstc2SweepA=0; }
  if (sstc2SweepA>5000) { sstc2SweepA=5000; }
  if (sstc2SweepB<0) { sstc2SweepB=0; }
  if (sstc2SweepB>5000) { sstc2SweepB=5000; }
  if (sstc2SweepDur<0) { sstc2SweepDur=0; }
  if (sstc2SweepDur>5000) { sstc2SweepDur=5000; }
  if (sstc2FreqA<0) { sstc2FreqA=0; }
  if (sstc2FreqA>200) { sstc2FreqA=200; }
  if (sstc2FreqB<0) { sstc2FreqB=0; }
  if (sstc2FreqB>200) { sstc2FreqB=200; }
  if (sstc2RatioA<0) { sstc2RatioA=0; }
  if (sstc2RatioA>100) { sstc2RatioA=100; }
  if (sstc2RatioB<0) { sstc2RatioB=0; }
  if (sstc2RatioB>100) { sstc2RatioB=100; }
  document.getElementById("octaveBtn").innerHTML="Octave "+sstc2Octave;
  document.getElementById("sweepaBtn").innerHTML="Sweep A "+sstc2SweepA+" Hz";
  document.getElementById("sweepbBtn").innerHTML="Sweep B "+sstc2SweepB+" Hz";
  document.getElementById("sweepdurBtn").innerHTML="Duration "+sstc2SweepDur+" ms";
  document.getElementById("freqaBtn").innerHTML="Frequency A "+sstc2FreqA+" Hz";
  document.getElementById("freqbBtn").innerHTML="Frequency B "+sstc2FreqB+" Hz";
  document.getElementById("ratioaBtn").innerHTML="Ratio "+sstc2RatioA;
  document.getElementById("ratiobBtn").innerHTML="Ratio "+sstc2RatioB;
  if (start==1) { sendAJAX("setSSTC2Tone"+","+sstc2FreqA+","+sstc2FreqB+","+sstc2RatioA+","+sstc2RatioB); } }

function sendAJAX(value) {
  if (window.XMLHttpRequest) { ajaxObj=new XMLHttpRequest; } else if (window.ActiveXObject) { ajaxObj=new ActiveXObject("Microsoft.XMLHTTP"); }
  ajaxObj.open("GET",value,false); ajaxObj.setRequestHeader("Content-Type","application/x-www-form-urlencoded"); ajaxObj.send(); }

</script></head><body onload="SSTC2init();">
<div><div class="x0">Aurora</div></div>
<div><div class="x0">SSTC-2 Controller</div></div>

<div><div class="x1" id="speedBtn" onclick="speedDef();"></div></div>
<div><div class="x2" onclick="speedDec();">&#8722;</div>
     <div class="x2" onclick="speedInc();">+</div></div>
<div><div class="x1" id="startBtn" onclick="startDef();"></div></div>
<div><div class="x2" onclick="startDec();">&#8722;</div>
     <div class="x2" onclick="startInc();">+</div></div>
<div><div class="x1" id="powerBtn" onclick="powerDef();"></div></div>
<div><div class="x2" onclick="powerDec();">&#8722;</div>
     <div class="x2" onclick="powerInc();">+</div></div>

<div><div class="x0">Play Note</div></div>

<div><div class="x1" id="octaveBtn" onclick="octaveDef();"></div></div>
<div><div class="x2" onclick="octaveDec();">&#8722;</div>
     <div class="x2" onclick="octaveInc();">+</div></div>
<div><div class="x4" ontouchstart="toneC();" ontouchend="toneOff();">C</div>
     <div class="x4" ontouchstart="toneD();" ontouchend="toneOff();">D</div>
     <div class="x4" ontouchstart="toneE();" ontouchend="toneOff();">E</div>
     <div class="x4" ontouchstart="toneF();" ontouchend="toneOff();">F</div></div>
<div><div class="x4" ontouchstart="toneG();" ontouchend="toneOff();">G</div>
     <div class="x4" ontouchstart="toneA();" ontouchend="toneOff();">A</div>
     <div class="x4" ontouchstart="toneH();" ontouchend="toneOff();">H</div>
     <div class="x4" ontouchstart="toneCn();" ontouchend="toneOff();">C</div></div>

<div><div class="x0">Play Sweep</div></div>

<div><div class="x1" id="sweepaBtn" onclick="sweepaDef();"></div></div>
<div><div class="x2" onclick="sweepaDec();">&#8722;</div>
     <div class="x2" onclick="sweepaInc();">+</div></div>
<div><div class="x1" id="sweepbBtn" onclick="sweepbDef();"></div></div>
<div><div class="x2" onclick="sweepbDec();">&#8722;</div>
     <div class="x2" onclick="sweepbInc();">+</div></div>
<div><div class="x1" id="sweepdurBtn" onclick="sweepdurDef();"></div></div>
<div><div class="x2" onclick="sweepdurDec();">&#8722;</div>
     <div class="x2" onclick="sweepdurInc();">+</div></div>
<div><div class="x2" onclick="sweepUp();">Sweep Up</div>
     <div class="x2" onclick="sweepDown();">Sweep Down</div></div>

<div><div class="x0">Beating</div></div>

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
<div><div class="x2" onclick="doRangeAsync(1);">Tone On</div>
     <div class="x2" onclick="toneOff();">Tone Off</div></div>

<div><div class="x0">Duty Cycle</div></div>

<div><div class="x1" id="ratioaBtn" onclick="ratioaDef();"></div></div>
<div><div class="x2" onclick="ratioaDec();">&#8722;</div>
     <div class="x2" onclick="ratioaInc();">+</div></div>
<div><div class="x1" id="ratiobBtn" onclick="ratiobDef();"></div></div>
<div><div class="x2" onclick="ratiobDec();">&#8722;</div>
     <div class="x2" onclick="ratiobInc();">+</div></div>

</body></html>

)";
