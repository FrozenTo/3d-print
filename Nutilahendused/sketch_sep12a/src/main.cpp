#include <Arduino.h>

#ifndef SENSOR_PIN
#define SENSOR_PIN 5
#endif

#ifndef SENSOR_VS
#define SENSOR_VS 5.06f
#endif

namespace {
constexpr uint32_t kSerialBaud = 115200;
constexpr uint16_t kReferenceSamples = 40;
constexpr uint16_t kLoopSamples = 12;
constexpr uint16_t kSampleDelayMs = 20;
constexpr uint16_t kPrintDelayMs = 500;
constexpr float kTransferOffset = 0.04f;
constexpr float kTransferSensitivity = 0.0012858f;
constexpr float kNormalAirMinKpa = 95.0f;
constexpr float kNormalAirMaxKpa = 108.0f;

float atmosphericPressureKpa = 0.0f;

float pressureKpaFromMillivolts(int millivolts) {
  const float vout = millivolts / 1000.0f;
  return (vout / SENSOR_VS - kTransferOffset) / kTransferSensitivity;
}

float readPressureKpa() {
  return pressureKpaFromMillivolts(analogReadMilliVolts(SENSOR_PIN));
}

float readAveragePressureKpa(uint16_t samples) {
  float sum = 0.0f;

  for (uint16_t i = 0; i < samples; ++i) {
    sum += readPressureKpa();
    delay(kSampleDelayMs);
  }

  return sum / samples;
}

const char *normalAirStatus(float pressureKpa) {
  if (pressureKpa < kNormalAirMinKpa) {
    return "LOW";
  }
  if (pressureKpa > kNormalAirMaxKpa) {
    return "HIGH";
  }
  return "NORMAL";
}

void printStartupHint() {
  Serial.println();
  Serial.println("MPX5700AP pressure monitor");
  Serial.print("Sensor GPIO: ");
  Serial.println(SENSOR_PIN);
  Serial.print("Sensor supply voltage: ");
  Serial.print(SENSOR_VS, 2);
  Serial.println(" V");
  Serial.println("Keep the pump off during startup; the first readings become the air reference.");
}
}  // namespace

void setup() {
  Serial.begin(kSerialBaud);
  delay(1500);

  analogReadResolution(12);
  analogSetPinAttenuation(SENSOR_PIN, ADC_11db);

  printStartupHint();

  atmosphericPressureKpa = readAveragePressureKpa(kReferenceSamples);

  Serial.print("Atmospheric reference = ");
  Serial.print(atmosphericPressureKpa, 1);
  Serial.print(" kPa (");
  Serial.print(normalAirStatus(atmosphericPressureKpa));
  Serial.println(")");
}

void loop() {
  const int adc = analogRead(SENSOR_PIN);
  const int millivolts = analogReadMilliVolts(SENSOR_PIN);
  const float pressureAbsKpa = readAveragePressureKpa(kLoopSamples);
  const float pressureGaugeKpa = pressureAbsKpa - atmosphericPressureKpa;

  Serial.print("ADC=");
  Serial.print(adc);
  Serial.print("  Voltage=");
  Serial.print(millivolts);
  Serial.print(" mV  P_abs=");
  Serial.print(pressureAbsKpa, 1);
  Serial.print(" kPa  P_gauge=");
  Serial.print(pressureGaugeKpa, 1);
  Serial.print(" kPa  Air=");
  Serial.println(normalAirStatus(pressureAbsKpa));

  delay(kPrintDelayMs);
}
