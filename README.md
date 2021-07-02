# Aurora
ESP32 based SSTC-2 Controller
#### Features
* WLAN Access Point with Web Server (IP 192.168.4.1)
* Sparks (sync mode)
  * Speed control (0.1Hz to 50Hz)
  * Start control (0ms to 12ms)
  * Power control (0ms to 12ms)
* async mode
  * play Note
  * Octave control
  * play Sweep
  * Beating
  * Ratio control (0/100 to 100/100)

#### GUI
* sync mode
  * click -/+ to decrease/increase speed or start or power
  * click speed to set 5Hz
  * click start to set 0ms
  * click power to set 0ms
* async mode
  * touch note to play note (touchscreen only)
  * click sweep up/down to play sweep
  * click power on/off for beating
  * click -/+ to decrease/increase ratio
  * click ratio to set 50/100

#### Speed
The speed is controlled by suppressing half waves. If every half-wave turns on the output, the speed is 50Hz. If, for example, the output is only switched on every 5th half-wave, the speed is 1 / (5 * 20ms) = 10Hz.
#### Start
The start time determines the switch-on delay of the output signal after the zero crossing of the 50Hz sync signal has been recognized.
#### Power
The power is set by the on-time of the output signal.
#### Schematic
The controller is designed for a halfbridge SSTC. The 50Hz input sync signal must be 12Volt rms. The output line is open collector. A schematic you will find within the "documentation" subfolder.
#### Smartphone Screenshot
![IMAGE ALT TEXT HERE](https://www.dorstel.de/github/Aurora_v1.3.png)
