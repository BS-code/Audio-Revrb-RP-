#include <Arduino.h>
// Menentukan parameter PWM
const int PWM_PIN = 2;
const int PWM_FREQ = 50000;
const int PWM_BITS = 16;
const int PWM_RANGE = pow(2, PWM_BITS);
// Menentukan parameter ADC
const int ADC_PIN = A0;
const int ADC_RANGE = 1024;
// Menentukan jumlah sampel dan delay
const int SAMPLES = 1000;
const int DELAY_MS = 5;
// Membuat lookup table sinusoid
int16_t sin_lut[PWM_RANGE];
void create_sin_lut() {
  for (int i = 0; i < PWM_RANGE; i++) {
    sin_lut[i] = (int16_t)(PWM_RANGE * sin(2 * PI * i / PWM_RANGE));
  }
}
// Program utama
void setup() {
  // Membuat lookup table sinusoid
  create_sin_lut();
  // Mengatur input ADC
  analogReference(DEFAULT);
  pinMode(ADC_PIN, INPUT);
  // Mengatur output PWM
  pinMode(PWM_PIN, OUTPUT);
  ledcSetup(0, PWM_FREQ, PWM_BITS);
  ledcAttachPin(PWM_PIN, 0);
}
void loop() {
  // Mengambil nilai ADC
  int value = analogRead(ADC_PIN);
  // Menambahkan efek reverb
  for (int i = 0; i < SAMPLES; i++) {
    int j = i % PWM_RANGE;
    int x = sin_lut[j];
    int y = value;
    int16_t out = x * y / ADC_RANGE;
    ledcWrite(0, out + PWM_RANGE / 2);
    delay(DELAY_MS);
  }
}