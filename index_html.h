char *index_html=R"(

<!DOCTYPE html>
<html><head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="icon" href="data:,">
<style>
html { font-family:Arial; }
div  { background-color:#888888; border:0px; padding:0px 0px; margin:0px; text-align:center; width:100%; }
.x0  { background-color:#E0C0C0; border:0px; padding:0.5em 0em; margin:0px; width:100%; color:#ffffff; display:inline-block; font-size:1.5em; user-select:none; }
.x1  { background-color:#C0D0E0; border:0px; padding:0.5em 0em; margin:0px; width:100%; color:#ffffff; display:inline-block; font-size:1.5em; user-select:none; }
.x2  { background-color:#888888; border:0px; padding:0.5em 0em; margin:0px; width:48%; color:#ffffff; display:inline-block; font-size:1.5em; user-select:none; }
.x3  { background-color:#888888; border:0px; padding:0.5em 0em; margin:0px; width:32%; color:#ffffff; display:inline-block; font-size:1.5em; user-select:none; }
.x4  { background-color:#888888; border:0px; padding:0.5em 0em; margin:0px; width:24%; color:#ffffff; display:inline-block; font-size:1.5em; user-select:none; }
</style>
<script>

function SSTC2init() {
  sstc2SpeedArray=[1,2,3,4,5,6,7,8,9,10,15,20,25,30,40,50,75,100,200,500]; sstc2Speed=0; sstc2Start=0; sstc2Power=0;
  sstc2SweepA=0; sstc2SweepB=5000; sstc2SweepDur=3000; sstc2FreqA=50; sstc2FreqB=50; sstc2Ratio=180;
  document.getElementById("speedBtn").innerHTML="Speed "+Math.round(5000/sstc2SpeedArray[sstc2Speed])/100+" Hz";
  document.getElementById("startBtn").innerHTML="Start "+sstc2Start/1000+" ms";
  document.getElementById("powerBtn").innerHTML="Power "+sstc2Power/1000+" ms";
  document.getElementById("sweepaBtn").innerHTML="Sweep A "+sstc2SweepA+" Hz";
  document.getElementById("sweepbBtn").innerHTML="Sweep B "+sstc2SweepB+" Hz";
  document.getElementById("sweepdurBtn").innerHTML="Duration "+sstc2SweepDur+" ms";
  document.getElementById("freqaBtn").innerHTML="Frequency A "+sstc2FreqA+" Hz";
  document.getElementById("freqbBtn").innerHTML="Frequency B "+sstc2FreqB+" Hz";
  document.getElementById("ratioBtn").innerHTML="Ratio "+sstc2Ratio; }

function speedDef() { sstc2Speed=0; doRangeSync(0); }
function speedDec() { sstc2Speed+=1; doRangeSync(0); }
function speedInc() { sstc2Speed-=1; doRangeSync(0); }
function startDef() { sstc2Start=0; doRangeSync(1); }
function startDec() { sstc2Start-=500; doRangeSync(1); }
function startInc() { sstc2Start+=500; doRangeSync(1); }
function powerDef() { sstc2Power=0; doRangeSync(0); }
function powerDec() { sstc2Power-=500; doRangeSync(0); }
function powerInc() { sstc2Power+=500; doRangeSync(0); }

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
function ratioDef() { sstc2Ratio=180; doRangeAsync(1); }
function ratioDec() { sstc2Ratio-=15; doRangeAsync(1); }
function ratioInc() { sstc2Ratio+=15; doRangeAsync(1); }

function toneOff() { sendAJAX("setSSTC2Tone,0,0,0,0"); }
function toneC() { sendAJAX("setSSTC2Tone"+","+Math.pow(2,((60-69)/12))*440+",0,"+sstc2Ratio+",0"); }
function toneD() { sendAJAX("setSSTC2Tone"+","+Math.pow(2,((62-69)/12))*440+",0,"+sstc2Ratio+",0"); }
function toneE() { sendAJAX("setSSTC2Tone"+","+Math.pow(2,((64-69)/12))*440+",0,"+sstc2Ratio+",0"); }
function toneF() { sendAJAX("setSSTC2Tone"+","+Math.pow(2,((65-69)/12))*440+",0,"+sstc2Ratio+",0"); }
function toneG() { sendAJAX("setSSTC2Tone"+","+Math.pow(2,((67-69)/12))*440+",0,"+sstc2Ratio+",0"); }
function toneA() { sendAJAX("setSSTC2Tone"+","+Math.pow(2,((69-69)/12))*440+",0,"+sstc2Ratio+",0"); }
function toneH() { sendAJAX("setSSTC2Tone"+","+Math.pow(2,((71-69)/12))*440+",0,"+sstc2Ratio+",0"); }
function toneC1() { sendAJAX("setSSTC2Tone"+","+Math.pow(2,((72-69)/12))*440+",0,"+sstc2Ratio+",0"); }

function sweepUp() { sendAJAX("setSSTC2Sweep,"+sstc2SweepA+","+sstc2SweepB+","+sstc2SweepDur+","+sstc2Ratio); }
function sweepDown() { sendAJAX("setSSTC2Sweep,"+sstc2SweepB+","+sstc2SweepA+","+sstc2SweepDur+","+sstc2Ratio); }

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
  if (sstc2SweepA<0) { sstc2SweepA=0; }
  if (sstc2SweepA>5000) { sstc2SweepA=5000; }
  if (sstc2SweepB<0) { sstc2SweepB=0; }
  if (sstc2SweepB>5000) { sstc2SweepB=5000; }
  if (sstc2SweepDur<250) { sstc2SweepDur=250; }
  if (sstc2SweepDur>5000) { sstc2SweepDur=5000; }
  if (sstc2FreqA<0) { sstc2FreqA=0; }
  if (sstc2FreqA>200) { sstc2FreqA=200; }
  if (sstc2FreqB<0) { sstc2FreqB=0; }
  if (sstc2FreqB>200) { sstc2FreqB=200; }
  if (sstc2Ratio<0) { sstc2Ratio=0; }
  if (sstc2Ratio>255) { sstc2Ratio=255; }
  document.getElementById("sweepaBtn").innerHTML="Sweep A "+sstc2SweepA+" Hz";
  document.getElementById("sweepbBtn").innerHTML="Sweep B "+sstc2SweepB+" Hz";
  document.getElementById("sweepdurBtn").innerHTML="Duration "+sstc2SweepDur+" ms";
  document.getElementById("freqaBtn").innerHTML="Frequency A "+sstc2FreqA+" Hz";
  document.getElementById("freqbBtn").innerHTML="Frequency B "+sstc2FreqB+" Hz";
  document.getElementById("ratioBtn").innerHTML="Ratio "+sstc2Ratio;
  if (start==1) { sendAJAX("setSSTC2Tone"+","+sstc2FreqA+","+sstc2FreqB+","+sstc2Ratio+","+sstc2Ratio); } }

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

<div><div class="x4" ontouchstart="toneC();" ontouchend="toneOff();">C</div>
     <div class="x4" ontouchstart="toneD();" ontouchend="toneOff();">D</div>
     <div class="x4" ontouchstart="toneE();" ontouchend="toneOff();">E</div>
     <div class="x4" ontouchstart="toneF();" ontouchend="toneOff();">F</div></div>
<div><div class="x4" ontouchstart="toneG();" ontouchend="toneOff();">G</div>
     <div class="x4" ontouchstart="toneA();" ontouchend="toneOff();">A</div>
     <div class="x4" ontouchstart="toneH();" ontouchend="toneOff();">H</div>
     <div class="x4" ontouchstart="toneC1();" ontouchend="toneOff();">C1</div></div>

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

<div><div class="x1" onclick="toneOff();">Tone Off</div></div>
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
<div><div class="x1" id="ratioBtn" onclick="ratioDef();"></div></div>
<div><div class="x2" onclick="ratioDec();">&#8722;</div>
     <div class="x2" onclick="ratioInc();">+</div></div>

</body></html>

)";
