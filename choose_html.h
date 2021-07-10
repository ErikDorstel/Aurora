char *choose_html=R"(

<!DOCTYPE html>
<html lang="en"><head>
<title>Aurora - SSTC-2 Controller</title>
<meta name="author" content="Erik Dorstel">
<meta name="generator" content="vi">
<meta name="repository" content="https://github.com/ErikDorstel/Aurora">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<meta charset="utf-8">
<style>
html  { font-family:Arial; }
div   { background-color:#888888; color:#ffffff; border:0px; padding:0px; margin:0px; text-align:center; width:100%; user-select:none; display:inline-block; }
input { font-size:1em; width:90%; outline:none; background-color:#A0B0C0; border:0px; color:#ffffff; padding:0.2em; }
.x0a  { background-color:#C0A0A0; padding:0.2em 0em 0.1em; width:100%; font-size:1.5em; }
.x0b  { background-color:#C0A0A0; padding:0.1em 0em 0.2em; width:100%; font-size:1.2em; }
.x0   { background-color:#C0A0A0; padding:0.4em 0em; width:100%; font-size:1.5em; }
.x1   { background-color:#A0B0C0; padding:0.4em 0em; width:100%; font-size:1.5em; }
.x2   { background-color:#888888; padding:0.4em 0em; width:48%; font-size:1.5em; }
.x3   { background-color:#888888; padding:0.4em 0em; width:32%; font-size:1.5em; }
.x4   { background-color:#888888; padding:0.4em 0em; width:24%; font-size:1.5em; }
</style>
<script>

function initChoose() {
  document.getElementById("statusAP").innerHTML=sendAJAX("statusAP");
  authAP=sendAJAX("authAP"); document.getElementById("APName").value=h2a(authAP.split(",")[0]); document.getElementById("APPassword").value=h2a(authAP.split(",")[1]); }
  
function scanAP() {
  document.getElementById("resultAP").innerHTML="<div class=\"x1\">Scan for WLAN Networks ...</div>";
  document.getElementById("resultAP").innerHTML=sendAJAX("scanAP"); }

function setAP(value) { document.getElementById("APName").value=value; document.getElementById("APPassword").value=""; document.getElementById("resultAP").innerHTML="<div class=\"x1\">&nbsp;</div>"; }

function connectAP() {
  if (document.getElementById("APName").value!="" & document.getElementById("APPassword").value!="") {
  document.getElementById("statusAP").innerHTML="<div class=\"x1\">Connecting WLAN AP "+document.getElementById("APName").value+" ...</div>"; window.setTimeout("location.replace('/');",2000); 
  sendAJAX("connectAP,"+a2h(document.getElementById("APName").value)+","+a2h(document.getElementById("APPassword").value)); } }

function sendAJAX(value) {
  if (window.XMLHttpRequest) { ajaxObj=new XMLHttpRequest; } else if (window.ActiveXObject) { ajaxObj=new ActiveXObject("Microsoft.XMLHTTP"); }
  ajaxObj.open("GET",value,false); ajaxObj.setRequestHeader("Content-Type","application/x-www-form-urlencoded"); ajaxObj.send(); return ajaxObj.responseText; }

function a2h(aValue) { hValue=[]; for (idx=0;idx<aValue.length;idx++) { hValue.push(Number(aValue.charCodeAt(idx)).toString(16)); } return hValue.join(''); }
function h2a(hValue) { aValue=""; for (idx=0;idx<hValue.length;idx+=2) { aValue+=String.fromCharCode(parseInt(hValue.substr(idx,2),16)); } return aValue; }

</script></head><body onload="initChoose();">

<div><div class="x0a">Aurora</div></div>
<div><div class="x0b">SSTC-2 Controller</div></div>
<div id="resultAP"><div class="x1">&nbsp;</div></div>
<div><div class="x2">WLAN Name</div>
     <div class="x2">Password</div></div>
<div><div class="x2"><form><input id="APName" type="text"></form></div>
     <div class="x2"><form><input id="APPassword" type="password"></form></div></div>
<div><div class="x3" onclick="connectAP();">Connect</div>
     <div class="x3" onclick="scanAP();">Scan</div>
     <div class="x3" onclick="location.replace('/');">Cancel</div></div>
<div id="statusAP"><div class="x1">&nbsp;</div></div>

</body></html>

)";
