#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

const int sensorPin = A0;
const int buzzerPin = 8;

void setup() {
  lcd.begin(16, 2);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);  // 🔥 important
}

void loop() {
  int value = analogRead(sensorPin);

  // 👉 Print in Serial Monitor
  Serial.print("Vibration Value: ");
  Serial.println(value);

  // 👉 LCD display
  lcd.setCursor(0, 0);
  lcd.print("Vib: ");
  lcd.print(value);
  lcd.print("   ");

  lcd.setCursor(0, 1);

  if (value < 50) {
    lcd.print("LOW        ");
    digitalWrite(buzzerPin, LOW);
  }
  else if (value < 200) {
    lcd.print("MEDIUM     ");
    digitalWrite(buzzerPin, LOW);
  }
  else {
    lcd.print("HIGH ALERT ");
    digitalWrite(buzzerPin, HIGH);
  }

  delay(200);
}