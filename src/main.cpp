#include <Arduino.h>

// Arduino Nano 3.0 (ATmega328P) — Blink LED
// LED_BUILTIN = D13 (ขา SCK ของ SPI ด้วย)
// Board: nanoatmega328 | Framework: arduino | Clock: 16 MHz

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("Arduino Nano 3.0 - Blink LED Start");
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("LED ON");
  delay(1000);

  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("LED OFF");
  delay(1000);
}
