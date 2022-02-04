//Declaración de Librerias
#include <OneWire.h>
#include <DallasTemperature.h>
#include "DHT.h"
#define DHTTYPE DHT11

//Declaracion de variables
#define DHTPIN 8
const byte pinDatosDQ = 9;
int sensor = A1;
int valorHumedad;


//Instancias a las clases OneWire, DallasTemperature y DHT11
OneWire oneWiredObjeto(pinDatosDQ);
DallasTemperature sensorDS18B20(&oneWiredObjeto);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  //Iniciamos la comunicación serie
  Serial.begin(9600);
  sensorDS18B20.begin();
  dht.begin();
  pinMode(sensor, INPUT);
  Serial.println("NOMBRE DE SENSOR, TEMPERATURA, HUMEDAD, NOMBRE DE SENSOR, TEMPERATURA , HUMEDAD, NOMBRE DE SENSOR, TEMPERATURA , HUMEDAD");
}

void loop() {
  //--------------------SENSOR DS18B20-------------------------------------------
  //Iniciamos comandos para tomar temperatura a los sensores
  sensorDS18B20.requestTemperatures();
  //Leemos y mostramos los datos de los siguuientes DS18B20
  Serial.print("SENSOR DS18B20");
  Serial.print(",");
  Serial.print(sensorDS18B20.getTempCByIndex(0));
  Serial.print(",");
  Serial.print(" ");
  Serial.print(",");
  //-----------------------------------------------------------------------------
  //--------------------SENSOR DHT11-------------------------------------------
  float h = dht.readHumidity(); //Leemos la Humedad
  float t = dht.readTemperature(); //Leemos la temperatura en grados Celsius
  float f = dht.readTemperature(true); //Leemos la temperatura en grados Fahrenheit
  Serial.print("SENSOR DHT11");
  Serial.print(",");
  Serial.print(t);
  Serial.print(",");
  Serial.print(h);
  Serial.print(",");
  //-----------------------------------------------------------------------------
  //--------------------SENSOR F-28-------------------------------------------
  valorHumedad = analogRead(sensor);
  valorHumedad =  map(analogRead(sensor), 0, 1023,  100, 0);
  Serial.print("SENSOR FC-28");
  Serial.print(",");
  Serial.print(" ");
  Serial.print(",");
  Serial.print(valorHumedad);
  Serial.println("%");
  //-----------------------------------------------------------------------------

}
