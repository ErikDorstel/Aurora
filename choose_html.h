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
input { background-color:#A0B0C0; padding:0.2em; width:90%; font-size:1em; color:#ffffff; outline:none; border:0px; }
input[type=checkbox] { width:1.2em; height:1.2em; }
.x0a  { background-color:#C0A0A0; padding:0.2em 0em 0.1em; width:100%; font-size:1.5em; }
.x0b  { background-color:#C0A0A0; padding:0.1em 0em 0.2em; width:100%; font-size:1.2em; }
.x0   { background-color:#C0A0A0; padding:0.4em 0em; width:100%; font-size:1.5em; }
.x1   { background-color:#A0B0C0; padding:0.4em 0em; width:100%; font-size:1.5em; }
.x2   { background-color:#888888; padding:0.4em 0em; width:48%; font-size:1.5em; }
.x3   { background-color:#888888; padding:0.4em 0em; width:32%; font-size:1.5em; }
.x4   { background-color:#888888; padding:0.4em 0em; width:24%; font-size:1.5em; }
</style>
<script>

function initChoose() { statusChoose(); statusChooseID=window.setInterval("statusChoose();",5000); requestAJAXconfigAP(); }

function statusChoose() { requestAJAXstatusAP(); requestAJAXstatusMQTT(); }

function scanAP() { document.getElementById("resultAP").innerHTML="<div class=\"x1\">Scan for WLAN Networks ...</div>"; requestAJAXscanAP(); }

function setAP(value) {
  document.getElementById("APName").value=value; document.getElementById("APPassword").value="";
  document.getElementById("resultAP").innerHTML="<div class=\"x1\">&nbsp;</div>"; }

function connectAP() {
  if (document.getElementById("APName").value!="" & document.getElementById("APPassword").value!="") {
    if (document.getElementById("MQTTBroker").value=="") { document.getElementById("MQTTEnabled").checked=false; }
    document.getElementById("resultAP").innerHTML="<div class=\"x1\">&nbsp;</div>";
    document.getElementById("statusAP").innerHTML="<div class=\"x1\">Connecting WLAN AP "+document.getElementById("APName").value+" ...</div>";
    document.getElementById("statusMQTT").innerHTML="<div class=\"x1\">&nbsp;</div>"; window.clearInterval(statusChooseID); window.setTimeout("initChoose();",5000); 
    requestAJAXconnectAP("connectAP,"+a2h(document.getElementById("APName").value)+","+a2h(document.getElementById("APPassword").value)+","+a2h(document.getElementById("MQTTBroker").value)+","+document.getElementById("MQTTEnabled").checked); } }

function requestAJAXstatusAP() {
  if (window.XMLHttpRequest) { ajaxOBJstatusAP=new XMLHttpRequest; } else if (window.ActiveXObject) { ajaxOBJstatusAP=new ActiveXObject("Microsoft.XMLHTTP"); }
  ajaxOBJstatusAP.open("GET","statusAP",true); ajaxOBJstatusAP.setRequestHeader("Content-Type","application/x-www-form-urlencoded"); ajaxOBJstatusAP.addEventListener('load',replyAJAXstatusAP); ajaxOBJstatusAP.send(); }

function requestAJAXstatusMQTT() {
  if (window.XMLHttpRequest) { ajaxOBJstatusMQTT=new XMLHttpRequest; } else if (window.ActiveXObject) { ajaxOBJstatusMQTT=new ActiveXObject("Microsoft.XMLHTTP"); }
  ajaxOBJstatusMQTT.open("GET","statusMQTT",true); ajaxOBJstatusMQTT.setRequestHeader("Content-Type","application/x-www-form-urlencoded"); ajaxOBJstatusMQTT.addEventListener('load',replyAJAXstatusMQTT); ajaxOBJstatusMQTT.send(); }

function requestAJAXconfigAP() {
  if (window.XMLHttpRequest) { ajaxOBJconfigAP=new XMLHttpRequest; } else if (window.ActiveXObject) { ajaxOBJconfigAP=new ActiveXObject("Microsoft.XMLHTTP"); }
  ajaxOBJconfigAP.open("GET","configAP",true); ajaxOBJconfigAP.setRequestHeader("Content-Type","application/x-www-form-urlencoded"); ajaxOBJconfigAP.addEventListener('load',replyAJAXconfigAP); ajaxOBJconfigAP.send(); }

function requestAJAXscanAP() {
  if (window.XMLHttpRequest) { ajaxOBJscanAP=new XMLHttpRequest; } else if (window.ActiveXObject) { ajaxOBJscanAP=new ActiveXObject("Microsoft.XMLHTTP"); }
  ajaxOBJscanAP.open("GET","scanAP",true); ajaxOBJscanAP.setRequestHeader("Content-Type","application/x-www-form-urlencoded"); ajaxOBJscanAP.addEventListener('load',replyAJAXscanAP); ajaxOBJscanAP.send(); }

function requestAJAXconnectAP(value) {
  if (window.XMLHttpRequest) { ajaxOBJconnectAP=new XMLHttpRequest; } else if (window.ActiveXObject) { ajaxOBJconnectAP=new ActiveXObject("Microsoft.XMLHTTP"); }
  ajaxOBJconnectAP.open("GET",value,true); ajaxOBJconnectAP.setRequestHeader("Content-Type","application/x-www-form-urlencoded"); ajaxOBJconnectAP.send(); }

function replyAJAXstatusAP() { if (ajaxOBJstatusAP.status==200) { document.getElementById("statusAP").innerHTML=ajaxOBJstatusAP.responseText; } }

function replyAJAXstatusMQTT() { if (ajaxOBJstatusMQTT.status==200) { document.getElementById("statusMQTT").innerHTML=ajaxOBJstatusMQTT.responseText; } }

function replyAJAXconfigAP() { if (ajaxOBJconfigAP.status==200) { configAP=ajaxOBJconfigAP.responseText;
  document.getElementById("APName").value=h2a(configAP.split(",")[0]); document.getElementById("APPassword").value=h2a(configAP.split(",")[1]);
  document.getElementById("MQTTBroker").value=h2a(configAP.split(",")[2]); if (configAP.split(",")[3]=="0") { document.getElementById("MQTTEnabled").checked=false; }
    else { document.getElementById("MQTTEnabled").checked=true; } } }

function replyAJAXscanAP() { if (ajaxOBJscanAP.status==200) { document.getElementById("resultAP").innerHTML=ajaxOBJscanAP.responseText; } }

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
<div id="statusAP"><div class="x1">&nbsp;</div></div>
<div><div class="x2">MQTT Broker</div>
     <div class="x2">Enabled</div></div>
<div><div class="x2"><form><input id="MQTTBroker" type="text"></form></div>
     <div class="x2"><form><input id="MQTTEnabled" type="checkbox"></form></div></div>
<div id="statusMQTT"><div class="x1">&nbsp;</div></div>
<div><div class="x3" onclick="connectAP();">Connect</div>
     <div class="x3" onclick="scanAP();">Scan</div>
     <div class="x3" onclick="location.replace('/');">Cancel</div></div>

</body></html>

)";
