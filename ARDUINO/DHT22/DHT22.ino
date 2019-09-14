
#include "DHT.h"

#define DHTPIN 2    
#define DHTTYPE DHT22  

DHT dht(DHTPIN, DHTTYPE);


float h;
float t;
float f;
float hif;
float hic;

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {

  delay(2000);
  temperature&huidity();
  
}

void temperature&huidity(){
  
  // Reading temperature or humidity takes about 250 milliseconds!
   h = dht.readHumidity();
   t = dht.readTemperature();
   f = dht.readTemperature(true);


  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

 hif = dht.computeHeatIndex(f, h);
 hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}


void temperature&huidityControl(){
  
}

