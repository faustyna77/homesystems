#include <Arduino.h>

#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>
//#define dhtpin 9
const int dhtpin=9;
const int czujnikcyf=2;

OneWire czujnik(czujnikcyf);
DallasTemperature sensor(&czujnik);


DHT dht(dhtpin,DHT22);

float readTemp()
{
  float temperature=dht.readTemperature();
  return temperature;


}
float readtempFahrenheit()
{
  sensor.requestTemperatures();
  float temfarenheit=sensor.getTempFByIndex(0);
  return temfarenheit;
}

float readHumidity()
{
  float  humidity=dht.readHumidity();
  return humidity;
}
float readTempfromdigital()
{
   sensor.requestTemperatures();
   float temp1=sensor.getTempCByIndex(0);
   return temp1;
}

void setup() {
  Serial.begin(9600);
  dht.begin();
  sensor.begin();
  

}

void loop() {
   //readTemp();

    
   if(Serial.available()>0)
   { 
    char commend=Serial.read();
    switch(commend)
    {
      case '1':
      Serial.print("Temperatura w stopniach C  ");
      Serial.print(readTemp());
      Serial.println(" C ");
      break;
      case '2':
      Serial.print(" Wilgotność powietrza:");
      Serial.print(readHumidity());
      Serial.print(" %");
       Serial.println("  ");
      break;
      case '3':
      Serial.print(" Temperatura w Fahrenheitach: ");
      Serial.print(readtempFahrenheit());
      Serial.print(" F");
       Serial.println("  ");
      break;
      case '4':
      Serial.print("Temperatura z czujnika cyfrowego: ");
      Serial.print(readTempfromdigital());
      Serial.print(" C");
      break;
     
      break;
     

      

    }
   
   
   }
   

}
