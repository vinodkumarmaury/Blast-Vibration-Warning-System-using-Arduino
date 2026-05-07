# Blast Vibration Warning System using Arduino

## Abstract

This project presents a low-cost Arduino-based blast vibration warning system designed to detect and classify vibration levels in mining environments. A piezoelectric sensor senses vibration, the signal is conditioned and read by an Arduino, and the system displays real-time vibration levels on an LCD while activating a buzzer when thresholds are exceeded. The approach offers a simple, cost-effective early-warning solution for improving safety in mining operations.

## Introduction

Blast-induced vibrations in mining operations can cause structural damage and safety hazards. Conventional seismographs are expensive and not always practical for small-scale deployments. This project develops an affordable embedded system using Arduino to monitor and alert vibration levels in real time.

## Objectives

- Detect vibration using a piezoelectric sensor
- Generate alerts based on vibration thresholds
- Display real-time vibration data on a 16x2 LCD

## Methodology

1. Piezoelectric sensor converts mechanical vibration into electrical signals.
2. Signal conditioning module filters and scales the signal for Arduino ADC.
3. Arduino reads the analog value on `A0` and compares it with predefined thresholds.
4. System classifies vibration as LOW, MEDIUM, or HIGH and provides feedback on the LCD and via a buzzer.

Flow (short): Sensor → Signal Conditioning → `A0` (Arduino) → Threshold Comparison → LCD + Buzzer

## Hardware

- Arduino Uno (or compatible)
- Piezoelectric vibration sensor
- Signal conditioning module (op-amp/filter)
- 16x2 LCD (parallel or I2C)
- Buzzer (active)
- Breadboard, jumper wires, power supply

## Software

- Arduino IDE
- (Optional) Tinkercad for simulation

## Circuit Overview

- Piezo sensor signal → Signal conditioning module → Arduino `A0`
- LCD connected in 4-bit mode to digital pins (example mapping below)
- Buzzer connected to a digital pin (e.g., `8`) with appropriate drive

Example pin mapping (parallel LCD):

- RS: 7
- E: 6
- D4: 5
- D5: 4
- D6: 3
- D7: 2
- Sensor signal → A0
- Buzzer → 8

## Flow of Execution (Objective-wise)

Objective 1 — Detect vibration:
- Piezo detects mechanical vibration → converted to voltage → conditioned → read on `A0` → raw value obtained

Objective 2 — Real-time alert:
- Arduino continuously compares value:
  - value < 50 → LOW (safe)
  - 50 ≤ value < 200 → MEDIUM (moderate)
  - value ≥ 200 → HIGH (danger) → buzzer ON

Objective 3 — Display on LCD:
- Arduino writes the value and status to the 16x2 LCD each loop iteration

## Code (Arduino sketch)

```cpp
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

const int sensorPin = A0;
const int buzzerPin = 8;

void setup() {
  lcd.begin(16, 2);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(sensorPin);
  Serial.print("Vibration Value: ");
  Serial.println(value);

  lcd.setCursor(0, 0);
  lcd.print("Vib: ");
  lcd.print(value);
  lcd.print("   ");

  lcd.setCursor(0, 1);
  if (value < 50) {
    lcd.print("LOW        ");
    digitalWrite(buzzerPin, LOW);
  } else if (value < 200) {
    lcd.print("MEDIUM     ");
    digitalWrite(buzzerPin, LOW);
  } else {
    lcd.print("HIGH ALERT ");
    digitalWrite(buzzerPin, HIGH);
  }

  delay(200);
}
```

## Results

The system reads analog vibration values, classifies them, and updates the LCD in real time. Example Serial Monitor output:

```
Vibration Value: 12
Vibration Value: 35
Vibration Value: 180
Vibration Value: 320
```

LCD example:

```
Vib: 215
HIGH ALERT
```

## Applications

- Mining safety monitoring
- Blast vibration detection
- Structural health monitoring
- Industrial vibration analysis

## Conclusion

This project demonstrates a low-cost and effective prototype for monitoring blast-induced vibrations using Arduino. It accurately classifies vibration intensity and provides timely alerts to improve onsite safety.

## Future Scope

- Integrate IoT for remote monitoring (WiFi/Bluetooth)
- SD card or cloud logging for historical analysis
- ML-based prediction and anomaly detection
- Multi-sensor arrays and wireless sensor networks

## References

- Arduino Official Documentation
- DGMS Guidelines for Blast Vibration
- Research papers on vibration monitoring systems

---

Created for blast vibration monitoring and structural safety assessment.

