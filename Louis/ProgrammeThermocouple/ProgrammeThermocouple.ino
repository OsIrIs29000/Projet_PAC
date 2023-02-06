#include "max6675.h"
#include <math.h>

//THERMOCOUPLE
int thermoSO = 4;
int thermoCS = 5;
int thermoSCK = 6;

//THERMISTANCE
const int B = 4275;
const int R0 = 100000;
const int pinTempSensor = A2;

//THERMISTANCEv2
const int pinTempSensorv2 = A0;
const int R0v2 = 10000;
const int Bv2 = 3977;
const float T0 = 25 + 273.15;

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


  //THERMISTANCEv2
  float VRT = analogRead(A0);              //Acquisition analog value of VRT
  VRT = (5.00 / 1023.00) * VRT;      //Conversion to voltage
  float VR = 5 - VRT;
  float RT = VRT / (VR / 10000);               //Resistance of RT
 
  float ln = log(RT / R0v2);
  float TX = (1 / ((ln / B) + (1 / T0))); //Temperature from thermistor
 
  TX = TX - 311.15;                 //Conversion to Celsius
 
  Serial.print("Temperature : ");
  Serial.println(TX);
}




