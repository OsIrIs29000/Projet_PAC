#include "max6675.h"
#include <math.h>

//THERMOCOUPLE
int thermoSO = 4;
int thermoCS = 5;
int thermoSCK = 6;

//THERMISTANCE
const int B = 4275;
const int R0 = 100000;
const int pinTempSensor = A0;


MAX6675 thermocouple(thermoSCK, thermoCS, thermoSO);

void setup() {
  Serial.begin(9600);
  delay(500);
}

void loop() {
  //THERMOCOUPLE
   Serial.print("C = "); 
   Serial.println(thermocouple.readCelsius());
   Serial.println();
   delay(1000);


   //THERMISTANCE
   int a = analogRead(pinTempSensor);
   float R = 1023.0/a-1.0;
   R = R0*R;
   float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15;
   Serial.print("temperature = ");
   Serial.println(temperature);
   delay(100);
}
