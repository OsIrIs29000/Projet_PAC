#include "max6675.h"

int thermoSO = 4;
int thermoCS = 5;
int thermoSCK = 6;

MAX6675 thermocouple(thermoSCK, thermoCS, thermoSO);

void setup() {
  Serial.begin(9600);
  delay(500);
}

void loop() {
  
   Serial.print("C = "); 
   Serial.println(thermocouple.readCelsius());
   Serial.println();
 
   delay(1000);
}
