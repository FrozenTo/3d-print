const int SENSOR_PIN = 5;
const float VS = 5.06;

// Атмосферное давление будет определено при запуске
float atmosphericPressure = 0;

float readPressure() {
  int mv = analogReadMilliVolts(SENSOR_PIN);
  float vout = mv / 1000.0;

  // MPX5700AP transfer function
  return (vout / VS - 0.04) / 0.0012858;
}

void setup() {
  Serial.begin(115200);

  analogReadResolution(12);
  analogSetPinAttenuation(SENSOR_PIN, ADC_11db);

  delay(2000);

  // В момент запуска насос должен быть выключен,
  // датчик находится при обычном атмосферном давлении.
  float sum = 0;

  for (int i = 0; i < 20; i++) {
    sum += readPressure();
    delay(50);
  }

  atmosphericPressure = sum / 20.0;

  Serial.print("Atmospheric zero = ");
  Serial.print(atmosphericPressure, 1);
  Serial.println(" kPa");
}

void loop() {
  int adc = analogRead(SENSOR_PIN);
  int mv = analogReadMilliVolts(SENSOR_PIN);

  float vout = mv / 1000.0;

  // Абсолютное давление
  float pressureAbs =
      (vout / VS - 0.04) / 0.0012858;

  // Давление относительно атмосферы
  float pressureGauge =
      pressureAbs - atmosphericPressure;

  Serial.print("ADC = ");
  Serial.print(adc);

  Serial.print("   Voltage = ");
  Serial.print(mv);
  Serial.print(" mV");

  Serial.print("   P_abs = ");
  Serial.print(pressureAbs, 1);
  Serial.print(" kPa");

  Serial.print("   P_gauge = ");
  Serial.print(pressureGauge, 1);
  Serial.println(" kPa");

  delay(500);
}