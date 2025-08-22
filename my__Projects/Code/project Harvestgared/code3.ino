#include <DHT11.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTTYPE DHT11 
#define DHTPIN A2  // استخدم الـ A2 فقط لحساس واحد

DHT11 dht11(A2);  // حساس واحد لدرجة الحرارة والرطوبة

#define Fan1 3
#define Fan2 4
#define Fan3 5
#define Fan4 6
#define Fan5 7

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  
  pinMode(Fan1, OUTPUT);
  pinMode(Fan2, OUTPUT);
  pinMode(Fan3, OUTPUT);
  pinMode(Fan4, OUTPUT);
  pinMode(Fan5, OUTPUT);

  lcd.init();
  lcd.backlight();
}

void loop() {
  // قراءة درجة الحرارة والرطوبة من الحساس الوحيد المتصل بـ A2
  float temperature = dht11.readTemperature();
  float humidity = dht11.readHumidity();

  // قراءة الأوامر من المنفذ التسلسلي
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == '1') {
      // النظام يعمل بشكل طبيعي بناءً على درجة الحرارة والرطوبة
      if (humidity > 10 ) {
        digitalWrite(Fan3, HIGH);
        digitalWrite(Fan4,  HIGH);
      } else if (humidity < 10) {
        digitalWrite(Fan3, LOW);
        digitalWrite(Fan4, LOW);
      }

      if (temperature < 10) {
        digitalWrite(Fan3, LOW);
        digitalWrite(Fan4, LOW);
      } else if (temperature > 10) {
        // digitalWrite(Fan1, HIGH);
        digitalWrite(Fan3, HIGH);
        digitalWrite(Fan4, HIGH);
      }
    } else if (command == '2') {
      // النظام يعمل بناءً على درجات حرارة ورطوبة مختلفة (أمر 2)
      if (humidity > 10) {
        digitalWrite(Fan3, 1);
        digitalWrite(Fan4, 1);
      } else if (humidity < 10) {
        digitalWrite(Fan3, 0);
        digitalWrite(Fan4, 0);
      }

      if (temperature < 10) {
        digitalWrite(Fan3, 0);
        digitalWrite(Fan4, 0);
      } else if (temperature > 10) {
        // digitalWrite(Fan1, HIGH);
        digitalWrite(Fan4, 1);
        digitalWrite(Fan3, 1);
      }
    } else if (command == '3') {
      // النظام يعمل بناءً على درجات حرارة ورطوبة مختلفة (أمر 3)
      if (humidity < 10 ) {
        digitalWrite(Fan3, LOW);
        digitalWrite(Fan4, LOW);
      } else if (humidity > 10) {
        digitalWrite(Fan3, HIGH);
        digitalWrite(Fan4, HIGH);
      }

      if (temperature < 10) {
        digitalWrite(Fan3, LOW);
        digitalWrite(Fan4, LOW);
      } else if (temperature > 10) {
        digitalWrite(Fan3, HIGH);
        digitalWrite(Fan4, HIGH);
      }
    } else if (command == '4') {
      // إيقاف تشغيل جميع المراوح والنظام
      digitalWrite(Fan1, LOW);
      digitalWrite(Fan2, LOW);
      digitalWrite(Fan3, LOW);
      digitalWrite(Fan4, LOW);
      digitalWrite(Fan5, LOW);

      // إيقاف النظام بالكامل
      Serial.println("System Stopped");
    }
  }

  // عرض البيانات على شاشة LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print(" %");

  // طباعة البيانات على Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(1000); // تأخير بسيط لتحديث البيانات
}
