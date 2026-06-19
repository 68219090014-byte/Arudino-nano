# Arduino Nano 3.0 (ATmega328)

## ภาพรวม

Arduino Nano 3.0 เป็นบอร์ดไมโครคอนโทรลเลอร์ขนาดเล็กที่ใช้ชิป **ATmega328P** เป็นหัวใจหลัก เหมาะสำหรับโปรเจกต์ที่ต้องการขนาดกะทัดรัดแต่มีประสิทธิภาพสูง

---

## ข้อมูลจำเพาะ (Specifications)

| คุณสมบัติ | รายละเอียด |
|---|---|
| ไมโครคอนโทรลเลอร์ | ATmega328P |
| สถาปัตยกรรม | AVR 8-bit |
| แรงดันไฟทำงาน | 5V |
| แรงดันไฟนำเข้า | 7–12V (ผ่านขา VIN) |
| ความเร็วสัญญาณนาฬิกา | 16 MHz |
| Flash Memory | 32 KB (2 KB สำรองไว้สำหรับ Bootloader) |
| SRAM | 2 KB |
| EEPROM | 1 KB |
| ขา Digital I/O | 14 ขา (6 ขารองรับ PWM) |
| ขา Analog Input | 8 ขา (A0–A7) |
| ความละเอียด ADC | 10-bit |
| กระแสไฟต่อขา I/O | 40 mA (สูงสุด) |
| การเชื่อมต่อ USB | Mini-USB |
| ขนาดบอร์ด | 18 × 45 mm |

---

## ผังขา (Pinout)

### ขา Digital
- **D0 (RX)** — รับข้อมูล Serial
- **D1 (TX)** — ส่งข้อมูล Serial
- **D2–D13** — Digital I/O ทั่วไป
- **D3, D5, D6, D9, D10, D11** — รองรับ PWM (~)

### ขา Analog
- **A0–A5** — Analog Input (ใช้ร่วมกับ Digital ได้)
- **A6, A7** — Analog Input เท่านั้น (ไม่รองรับ Digital)

### ขาไฟฟ้า
- **VIN** — แรงดันไฟเข้า 7–12V
- **5V** — จ่ายไฟ 5V regulated
- **3.3V** — จ่ายไฟ 3.3V (กระแสสูงสุด 50 mA)
- **GND** — กราวด์
- **RESET** — รีเซ็ตบอร์ด
- **AREF** — แรงดันอ้างอิงสำหรับ ADC

---

## การสื่อสาร (Communication)

| โปรโตคอล | ขาที่ใช้ |
|---|---|
| UART / Serial | D0 (RX), D1 (TX) |
| SPI | D10 (SS), D11 (MOSI), D12 (MISO), D13 (SCK) |
| I2C | A4 (SDA), A5 (SCL) |

---

## การตั้งค่าใน PlatformIO

```ini
[env:nanoatmega328]
platform = atmelavr
board = nanoatmega328
framework = arduino
monitor_speed = 9600
```

> หากใช้บอร์ด Clone ที่ใช้ชิป CH340 ให้เปลี่ยน `upload_protocol` เป็น `arduino` และติดตั้งไดรเวอร์ CH340 ก่อนใช้งาน

---

## ตัวอย่างโค้ด Blink LED

```cpp
void setup() {
    pinMode(LED_BUILTIN, OUTPUT); // D13
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
}
```

---

## หมายเหตุสำคัญ

- ขา **A6** และ **A7** ใช้เป็น Analog Input เท่านั้น ไม่สามารถใช้เป็น Digital I/O ได้
- Flash Memory มีอายุการเขียนประมาณ **10,000 ครั้ง**
- EEPROM มีอายุการเขียนประมาณ **100,000 ครั้ง**
- บอร์ดทนกระแสไฟสูงสุดรวมทุกขา **200 mA** ไม่ควรต่อโหลดหนักโดยตรง
- ใช้ Mini-USB (ไม่ใช่ Micro-USB) สำหรับการอัปโหลดและ Serial Monitor
