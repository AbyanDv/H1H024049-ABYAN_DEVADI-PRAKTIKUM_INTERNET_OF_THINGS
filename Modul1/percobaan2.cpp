#include <DHT.h>

#define DHTPIN D4         // Pin data sensor terhubung ke D5 (GPIO14)
#define DHTTYPE DHT11     // Diubah ke tipe DHT11
#define RELAYPIN D1       // Pin kendali relay terhubung ke D1 (GPIO5)

DHT dht(DHTPIN, DHTTYPE);

const float suhuThreshold = 29.0; // Ambang batas suhu (°C)

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  pinMode(RELAYPIN, OUTPUT);
  digitalWrite(RELAYPIN, HIGH); // Matikan relay di awal (Active LOW)
}

void loop() {
  delay(1000); // DHT11 cukup jeda 1 detik

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Memeriksa pembacaan sensor
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Gagal membaca dari sensor DHT11!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature, 1);
  Serial.print(" °C\tHumidity: ");
  Serial.print(humidity, 1);
  Serial.print(" % -> ");

  // Kendali Aktuator (Logika Active LOW)
  if (temperature > suhuThreshold) {
    digitalWrite(RELAYPIN, LOW);   // Menyala saat suhu melampaui batas
    Serial.println("Aktuator: ON");
  } else {
    digitalWrite(RELAYPIN, HIGH);  // Mati saat suhu di bawah batas
    Serial.println("Aktuator: OFF");
  }
}