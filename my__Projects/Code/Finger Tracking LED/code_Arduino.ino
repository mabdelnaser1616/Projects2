int leds[5] = {2, 3, 4, 5, 6}; // Pins LEDs

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');
    if (data.length() == 5) {
      for (int i = 0; i < 5; i++) {
        if (data[i] == '1') {
          digitalWrite(leds[i], HIGH);
        } else {
          digitalWrite(leds[i], LOW);
        }
      }
    }
  }
}
