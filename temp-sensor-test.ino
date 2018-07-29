/********************************************************************/
// I tweaked the provided code slightly for easier output reading
// when using multiple sensors, in my case, 5 sensors
// the example code for getting the addresses of all your sensors
// worked properly! which is great
// this program properly reads temps from however many you ask for
// again in my case 5
/********************************************************************/
// First we include the libraries
#include <OneWire.h>
#include <DallasTemperature.h>
/********************************************************************/
// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2
/********************************************************************/
// Setup a oneWire instance to communicate with any OneWire devices
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
/********************************************************************/
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
/********************************************************************/
void setup(void)
{
 // start serial port
 Serial.begin(9600);
 Serial.println("Dallas Temperature IC Control Library Demo");
 // Start up the library
 sensors.begin();
}

/********************************************************************/
// call the oneWireSearch routine to get a count of sensors first I
// slight mods only like removing the now redundant lib reference
// also kept the comm speed to 9600 for now not 115k
/********************************************************************/
// next rev of this will include the OneWireSearch routine
// ok the next one will, this one not yet...
/********************************************************************/

}
/********************************************************************/
void loop(void)
{
	TempDisplay();
}
/********************************************************************/
void TempDisplay() {
 // call sensors.requestTemperatures() to issue a global temperature
 // request to all devices on the bus
/********************************************************************/
 Serial.print(" Requesting temperatures...");
 sensors.requestTemperatures(); // Send the command to get temperature readings
 Serial.println("DONE");
/********************************************************************/
 Serial.print("Temperature 0 is: ");
 Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"?
   // You can have more than one DS18B20 on the same bus.
   // 0 refers to the first IC on the wire
 Serial.println(" ");
 Serial.print("Temperature 1 is: ");
 Serial.print(sensors.getTempCByIndex(1));
 Serial.println(" ");
 Serial.print("Temperature 2 is: ");
 Serial.print(sensors.getTempCByIndex(2));
 Serial.println(" ");
 Serial.print("Temperature 3 is: ");
 Serial.print(sensors.getTempCByIndex(3));
 Serial.println(" ");
 Serial.print("Temperature 4 is: ");
 Serial.print(sensors.getTempCByIndex(4));
 Serial.println(" ");
   delay(1000);
}
