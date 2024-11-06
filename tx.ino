// Kode untuk Arduino Uno sebagai pengirim
#include <SPI.h>
#include <RF24.h>

// Pin CE dan CSN untuk NRF24L01 pada Arduino Uno
#define CE_PIN 9
#define CSN_PIN 10

RF24 radio(CE_PIN, CSN_PIN); // Inisialisasi modul RF24

const byte address[6] = "00001"; // Alamat komunikasi

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address); // Alamat komunikasi
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();
}

void loop() {
  const char text[] = "Hello ESP32!";
  radio.write(&text, sizeof(text)); // Kirim data
  Serial.println("Data dikirim: Hello ESP32!");
  delay(1000); // Tunggu 1 detik sebelum mengirim lagi
}
