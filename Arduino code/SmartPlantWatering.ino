#include
<LiquidCrystal.h>
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
const int rainPin = 7;
const int soilPin =
A0;
LiquidCrystal lcd(12, 11, 5, 4, 3,
2);void setup() {
Serial.begin(9600);
lcd.begin(16, 2);
dht.begin();
}
void loop() {
int soilValue = 
analogRead(soilPin);int rainValue 
= digitalRead(rainPin); float 
humidity = dht.readHumidity();
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Soil Moisture:
");lcd.print(soilValue);
lcd.setCursor(0, 1);
lcd.print("Rain: ");
lcd.print(rainValue);
lcd.setCursor(8, 1);
lcd.print("Humidity: ");
lcd.print(humidity);
if(soilValue < 500 && rainValue == LOW && humidity < 80){
lcd.setCursor(0, 3);
lcd.print("Watering...");
} else {
lcd.setCursor(0,
3);
lcd.print("Not Watering");
}
delay(1000);
}