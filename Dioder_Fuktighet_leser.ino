#include <DHT.h>
#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>


hd44780_I2Cexp lcd;

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

  int status = lcd.begin(16, 2);

  if(status != 0){
    Serial.println("Virker ikke");
    while(true){

    }
  }

  Serial.begin(9600);

}

void loop() {

  float temp;
  float fukt;
  lesFuktighet(temp, fukt);

  lcd.backlight();  

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);

  lcd.setCursor(0, 1);
  lcd.print("Fukt: ");
  lcd.print(fukt);
  delay(2000);

}

void lesFuktighet(float &temperatur, float &fuktighet) {
  
  temperatur = dht.readTemperature();
  fuktighet = dht.readHumidity();

  if(isnan(temperatur) || isnan(fuktighet)){
    Serial.println("Kunne ikke lese sensoren. Sjekk koblingen");
    return;
  }

  Serial.print("Temperatur: ");
  Serial.print(temperatur);
  Serial.print(" fuktighet: ");
  Serial.print(fuktighet);
  Serial.println(" %");

  if (fuktighet >= 50){
    digitalWrite(ledPinBlaa, HIGH);
    digitalWrite(ledPinRed, LOW);
    noTone(buzzer);
    delay(50);
  }
  else if (fuktighet <= 48){
    digitalWrite(ledPinBlaa, LOW);
    digitalWrite(ledPinRed, HIGH);
    tone(buzzer, 1000);
    delay(50);
  };

}



