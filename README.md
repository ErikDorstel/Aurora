# Aurora
ESP32 based SSTC-2 Controller
#### Features
* WLAN Access Point mode with Web Server (http://192.168.4.1 or http://aurora.tesla)
* DNS server to resolve local hostname aurora.tesla
* WLAN Station mode with Web Server (connect to WLAN AP and store credentials in Flash Memory)
* MQTT client (connect to MQTT Broker and store credentials in Flash Memory)
* Sparks (sync mode)
  * Speed control (0.1Hz to 50Hz)
  * Start control (0ms to 12ms)
  * Power control (0ms to 12ms)
* async mode
  * play Music Notes (with octave and ratio control)
  * play Sweeps (with ratio control)
  * Beating Tones (with ratio control)
  * Touch Controller (supports one or two voices/fingers)

#### Speed
The speed is controlled by suppressing half waves. If every half-wave turns on the output, the speed is 50Hz. If, for example, the output is only switched on every 5th half-wave, the speed is 1 / (5 * 20ms) = 10Hz.
#### Start
The start time determines the switch-on delay of the output signal after the zero crossing of the 50Hz sync signal has been recognized.
#### Power
The power is set by the on-time of the output signal.
#### Schematic
The controller is designed for a halfbridge SSTC. The 50Hz input sync signal must be 12Volt rms. The output line is open collector. A schematic you will find within the "documentation" subfolder.
#### MQTT
The MQTT client supports the following topics. The topic syntax is compatible to https://github.com/ErikDorstel/tasView.
* cmnd/aurora/status 0
* cmnd/aurora/status 10
* cmnd/aurora/status 11
* cmnd/aurora/para <speed>,<start µs>,<power µs>
* cmnd/aurora/tone <freqA Hz>,<ratioA %>,<freqB Hz>,<ratioB %>
* cmnd/aurora/sweep <freqA Hz>,<freqB Hz>,<duration ms>,<ratio %>
 
#### Smartphone Screenshot
![IMAGE ALT TEXT HERE](https://www.dorstel.de/github/Aurora_v1.5.png)
