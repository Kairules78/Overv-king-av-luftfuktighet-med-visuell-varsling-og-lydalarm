#include <DHT.h>
const int ledPinRed = 12;
const int ledPinBlaa = 2;
const int sensorPin2 = 3;
const int buzzer = 10;
DHT dht (sensorPin2, DHT11);

void setup() {
  pinMode(ledPinBlaa, OUTPUT);
  pinMode(ledPinRed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  dht.begin();
  Serial.begin(9600);

}

void loop() {
  lesFuktighet();
  delay(2000);

  
}

void lesFuktighet() {
  float temperatur = dht.readTemperature();
  float fuktighet = dht.readHumidity();

  if(isnan(temperatur) || isnan(fuktighet)){
    Serial.println("Kunne ikke lese sensoren. Sjekk koblingen");
    return;
  }

  Serial.print("Temperatur: ");
  Serial.print(temperatur);
  Serial.print(" fuktighet: ");
  Serial.print(fuktighet);
  Serial.println(" %");

  if (fuktighet >= 40){
    digitalWrite(ledPinBlaa, HIGH);
    digitalWrite(ledPinRed, LOW);
    noTone(buzzer);
    delay(50);
  }
  else if (fuktighet <= 38){
    digitalWrite(ledPinBlaa, LOW);
    digitalWrite(ledPinRed, HIGH);
    tone(buzzer, 1000);
    delay(50);
  };

}



