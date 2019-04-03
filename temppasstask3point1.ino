// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>

#include "Adafruit_DHT.h"

// Define Pins
    #define DHTPIN 2     // what pin we're connected to

// Setup Sensor
    #define DHTTYPE DHT22		// DHT 22 (AM2302)

    DHT dht(DHTPIN, DHTTYPE);

int led = D7;  // The on-board LED
float temperature;
float humidity;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(D2, INPUT);
}

void loop() {
  digitalWrite(led, HIGH);   // Turn ON the LED
  temperature = dht.getTempCelcius();
  humidity = dht.getHumidity();
  String temp2 = String(humidity);
  String temp = String(temperature);
  Particle.publish("temp", temp, PRIVATE);
  Particle.publish("humidity", temp2, PRIVATE);
  delay(30000);               // Wait for 30 seconds

  digitalWrite(led, LOW);    // Turn OFF the LED
  delay(30000);               // Wait for 30 seconds
}