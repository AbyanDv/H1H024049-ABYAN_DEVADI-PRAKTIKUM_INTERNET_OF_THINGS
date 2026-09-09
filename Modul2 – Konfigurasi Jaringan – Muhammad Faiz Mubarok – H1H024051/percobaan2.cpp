#include <ESP8266WiFi.h>

const char* ssid     = "POCO X5 5G";
const char* password = "cobaliathplu";

void setup() {
  Serial.begin(115200);

  // Set mode WiFi menjadi Access Point
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  IPAddress apIP = WiFi.softAPIP();

  Serial.println();
  Serial.println("Access Point aktif!");
  Serial.print("SSID        : ");
  Serial.println(ssid);

  Serial.print("IP Address  : ");
  Serial.println(apIP);
}

void loop() {
  // Menampilkan jumlah perangkat yang terhubung setiap 5 detik
  int jumlahClient = WiFi.softAPgetStationNum();

  Serial.print("Jumlah perangkat terhubung: ");
  Serial.println(jumlahClient);

  delay(5000);
}