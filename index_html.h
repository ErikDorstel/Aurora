char *index_html=R"(

<!DOCTYPE html>
<html><head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="icon" href="data:,">
<style>
html     { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center; }
.button  { background-color: #C0D0E0; border: none; color: white; padding: 10px 39px; text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer; }
.button2 { background-color: #888888; font-size: 50px; padding: 15px 39px; }
</style>
<script>

function SSTC2init() {
  sstc2SpeedArray=[1,2,3,4,5,6,7,8,9,10,15,20,25,30,40,50,75,100,200,500]; sstc2Speed=0; sstc2Start=0; sstc2Power=0;
  document.getElementById("speedBtn").innerHTML="Speed "+Math.round(5000/sstc2SpeedArray[sstc2Speed])/100+" Hz";
  document.getElementById("startBtn").innerHTML="Start "+sstc2Start/1000+" ms";
  document.getElementById("powerBtn").innerHTML="Power "+sstc2Power/1000+" ms"; }

function speedDef() { sstc2Speed=0; doRange(0); }
function speedDec() { sstc2Speed+=1; doRange(0); }
function speedInc() { sstc2Speed-=1; doRange(0); }
function startDef() { sstc2Start=0; doRange(1); }
function startDec() { sstc2Start-=500; doRange(1); }
function startInc() { sstc2Start+=500; doRange(1); }
function powerDef() { sstc2Power=0; doRange(0); }
function powerDec() { sstc2Power-=500; doRange(0); }
function powerInc() { sstc2Power+=500; doRange(0); }

function toneOff() { sendAJAX("setSSTC2Tone,0,0"); }
function toneC() { sendAJAX("setSSTC2Tone"+","+Math.pow(2,((60-69)/12))*440+","+127); }
function toneD() { sendAJAX("setSSTC2Tone"+","+Math.pow(2,((62-69)/12))*440+","+127); }
function toneE() { sendAJAX("setSSTC2Tone"+","+Math.pow(2,((64-69)/12))*440+","+127); }
function toneF() { sendAJAX("setSSTC2Tone"+","+Math.pow(2,((65-69)/12))*440+","+127); }
function toneG() { sendAJAX("setSSTC2Tone"+","+Math.pow(2,((67-69)/12))*440+","+127); }
function toneA() { sendAJAX("setSSTC2Tone"+","+Math.pow(2,((69-69)/12))*440+","+127); }
function toneH() { sendAJAX("setSSTC2Tone"+","+Math.pow(2,((71-69)/12))*440+","+127); }
function toneC1() { sendAJAX("setSSTC2Tone"+","+Math.pow(2,((72-69)/12))*440+","+127); }

function sweepUp() { sendAJAX("setSSTC2Sweep,100,5000,3000,127"); }
function sweepDown() { sendAJAX("setSSTC2Sweep,5000,100,3000,127"); }

function doRange(start) {
  if (sstc2Speed<0) { sstc2Speed=0; } if (sstc2Speed>19) { sstc2Speed=19; }
  if (sstc2Start<0) { sstc2Start=0; } if (sstc2Start>12000) { sstc2Start=12000; }
  if (sstc2Power<0) { sstc2Power=0; } if (sstc2Power>12000) { sstc2Power=12000; }
  if (sstc2Start+sstc2Power>12000) { if (start==1) { sstc2Power=12000-sstc2Start; } else sstc2Start=12000-sstc2Power; }
  document.getElementById("speedBtn").innerHTML="Speed "+Math.round(5000/sstc2SpeedArray[sstc2Speed])/100+" Hz";
  document.getElementById("startBtn").innerHTML="Start "+sstc2Start/1000+" ms";
  document.getElementById("powerBtn").innerHTML="Power "+sstc2Power/1000+" ms";
  sendAJAX("setSSTC2Para"+","+sstc2SpeedArray[sstc2Speed]+","+sstc2Start+","+sstc2Power); }

function sendAJAX(value) {
  if (window.XMLHttpRequest) { ajaxObj=new XMLHttpRequest; } else if (window.ActiveXObject) { ajaxObj=new ActiveXObject("Microsoft.XMLHTTP"); }
  ajaxObj.open("GET",value,false); ajaxObj.setRequestHeader("Content-Type","application/x-www-form-urlencoded"); ajaxObj.send(); }

</script></head><body onload="SSTC2init();">
<h1>Aurora</h1>
<h2>SSTC-2 Controller</h2>

<p><button class="button" id="speedBtn" onclick="speedDef();"></button></p>
<p><button class="button button2" onclick="speedDec();">&#8722;</button>
   <button class="button button2" onclick="speedInc();">+</button></p>
<p><button class="button" id="startBtn" onclick="startDef();"></button></p>
<p><button class="button button2" onclick="startDec();">&#8722;</button>
   <button class="button button2" onclick="startInc();">+</button></p>
<p><button class="button" id="powerBtn" onclick="powerDef();"></button></p>
<p><button class="button button2" onclick="powerDec();">&#8722;</button>
   <button class="button button2" onclick="powerInc();">+</button></p>

<p><button class="button" ontouchstart="toneC();" ontouchend="toneOff();">C</button>
   <button class="button" ontouchstart="toneD();" ontouchend="toneOff();">D</button></p>
<p><button class="button" ontouchstart="toneE();" ontouchend="toneOff();">E</button>
   <button class="button" ontouchstart="toneF();" ontouchend="toneOff();">F</button></p>
<p><button class="button" ontouchstart="toneG();" ontouchend="toneOff();">G</button>
   <button class="button" ontouchstart="toneA();" ontouchend="toneOff();">A</button></p>
<p><button class="button" ontouchstart="toneH();" ontouchend="toneOff();">H</button>
   <button class="button" ontouchstart="toneC1();" ontouchend="toneOff();">C1</button></p>

<p><button class="button" onclick="sweepUp();">Sweep Up</button></p>
<p><button class="button" onclick="sweepDown();">Sweep Down</button></p>

</body></html>

)";
