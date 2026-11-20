
#include <Arduino.h>
#include <DHTesp.h>

// ================= PIN CONFIGURATION =================
#define DHT_PIN       15
#define PIR_PIN       27
#define LDR_PIN       32
#define VOC_PIN       33
#define SOUND_PIN     34
#define PM25_PIN      35
#define CO2_PIN       36
#define FCU_PIN       39

DHTesp dhtSensor;

// ================= SETUP =================
void setup() {
  Serial.begin(115200);
  delay(1000);

  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);

  pinMode(PIR_PIN, INPUT);

  analogReadResolution(12);

  Serial.println();
  Serial.println("==================================");
  Serial.println(" SMART BRANCH SENSOR DIAGNOSTICS");
  Serial.println("==================================");
}

// ================= LOOP =================
void loop() {

  // 1. DHT22
  TempAndHumidity climate = dhtSensor.getTempAndHumidity();

  Serial.println("\n--- ENVIRONMENTAL SENSORS ---");

  if (dhtSensor.getStatus() == DHTesp::ERROR_NONE) {
    Serial.print("Temperature : ");
    Serial.print(climate.temperature, 2);
    Serial.println(" C");
    Serial.print("Humidity    : "); 
    Serial.print(climate.humidity, 2); 
    Serial.println("%"); 
  } else {
    Serial.println("DHT22 ERROR : " + String(dhtSensor.getStatusString()));
  }

  // 2. PIR Motion Sensor
  int motion = digitalRead(PIR_PIN);

  Serial.println("--- MOTION SENSOR ---");
  Serial.println("Motion      : %s" + String(motion == HIGH ? "DETECTED" : "NOT DETECTED"));

  // 3. Analog Sensors
  Serial.println("--- ANALOG SENSORS ---");

  Serial.println("LDR: " + String(analogRead(LDR_PIN)));
  Serial.println("VOC: " + String(analogRead(VOC_PIN)));
  Serial.println("Sound: " + String(analogRead(SOUND_PIN)));
  Serial.println("PM2.5: " + String(analogRead(PM25_PIN)));
  Serial.println("CO2: " + String(analogRead(CO2_PIN)));
  Serial.println("FCU Fan: " + String(analogRead(FCU_PIN)));

  Serial.println("\n==================================");

  delay(2500);
}