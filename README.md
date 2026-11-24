# Arduino & LabVIEW Temperature Monitor with Automatic Fan Control

A temperature monitoring and control system that reads an LM35 sensor
through an Arduino, processes the data in LabVIEW using the LIFA toolkit,
indicates the temperature range with LEDs, and switches a 12V fan on
automatically when the temperature gets too high.

## Features
- Real-time temperature reading from an LM35 sensor
- Four-level temperature classification with LED indicators
- Automatic fan control based on a temperature threshold
- MOSFET-based fan switching, so the Arduino is never overloaded

## Logic

**Fan control**
- Temperature above 35 °C: fan ON
- Otherwise: fan OFF

**Temperature levels (one LED per level)**

| Level    | Condition          |
|----------|--------------------|
| Cool     | T ≤ 15 °C          |
| Moderate | 15 °C < T ≤ 25 °C  |
| Hot      | 25 °C < T ≤ 40 °C  |
| Very Hot | T > 40 °C          |

## Hardware
- Arduino [board, e.g. Uno]
- LM35 temperature sensor
- 4 LEDs with current-limiting resistors
- 12V DC fan
- IRF540 N-channel MOSFET (fan switch)
- Pull-down resistor between MOSFET gate and source
- Battery (powers the fan)

## Software and Compatibility
- LabVIEW 2014
- LabVIEW Interface for Arduino (LIFA) toolkit + NI-VISA
- Arduino IDE 1.6.6

This combination worked for the project. Other version combinations may
also work but were not tested. LIFA is no longer supported by NI, so
newer versions of LabVIEW or the Arduino IDE may cause problems.

## How It Works
1. The LIFA base firmware (LVIFA_Base) is uploaded to the Arduino using
   the Arduino IDE.
2. LabVIEW reads the LM35 output through the LIFA analog read VI.
3. The voltage is multiplied by 100 to get the temperature in °C
   (the LM35 outputs 10 mV per °C).
4. LabVIEW compares the temperature against the thresholds, lights the
   matching LED, and turns the fan on or off.

**Fan switching:** The Arduino only drives the gate of the IRF540 MOSFET.
The fan is powered from a separate battery through the MOSFET, so the fan
current never passes through the Arduino pins. A pull-down resistor
between the gate and source keeps the gate grounded, so noise cannot
switch the fan on accidentally.

**Sensor test sketch:** An Arduino-only sketch is included to verify the
LM35 before using LabVIEW:
temperature (°C) = (ADC / 1024 x 5000) / 10

## Screenshots
<img width="1366" height="727" alt="Project Working" src="https://github.com/user-attachments/assets/70deb40d-423c-44ac-ae38-9c6d2f658dbf" />
<img width="780" height="301" alt="image" src="https://github.com/user-attachments/assets/e00d699b-926b-48eb-9a2b-4cc9e6cb60dc" />
<img width="3884" height="2160" alt="I M_Lab_Project" src="https://github.com/user-attachments/assets/d2709708-da9a-457e-8c62-449b3d1e81fc" />


## Repository Contents
- `LM35 Interface with Arduino.vi` - LabVIEW VI file
- `Arduino Test Code.ino` - sensor test sketch
- `LIFA_Base.ino` -LIFA code for Arduino

  
## Acknowledgements
The Arduino-LabVIEW interfacing (LIFA setup and firmware upload) was
learned from the YouTube tutorial
[Labview Interface for Arduino](https://youtu.be/x4yA15ehsI4)
by Pardeep LabVIEW.

## Authors
Zain Rizwan - Electrical Engineer<br>
University group project (2023), with Bilawal, Shaheer & Jabbar
