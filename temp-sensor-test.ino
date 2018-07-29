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
/********************************************************************/
//    FILE: oneWireSearch.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.02
// PURPOSE: scan for 1-Wire devices + code snippet generator
//    DATE: 2015-june-30
//     URL: http://forum.arduino.cc/index.php?topic=333923
//
// inspired by http://www.hacktronics.com/Tutorials/arduino-1-wire-address-finder.html
//
// Released to the public domain
//
// 0.1.00 initial version
// 0.1.01 first published version
// 0.1.02 small output changes

#include <OneWire.h>

void OneWireSetup()
{
  Serial.begin(9600);
  Serial.println("//\n// Start oneWireSearch.ino \n//");

  for (uint8_t pin = 2; pin < 13; pin++)
  {
    findDevices(pin);
  }
  Serial.println("\n//\n// End oneWireSearch.ino \n//");
}

void OneWireLoop()
{
}

uint8_t findDevices(int pin)
{
  OneWire ow(pin);

  uint8_t address[8];
  uint8_t count = 0;

  if (ow.search(address))
  {
    Serial.print("\nuint8_t pin");
    Serial.print(pin, DEC);
    Serial.println("[][8] = {");
    do {
      count++;
      Serial.println("  {");
      for (uint8_t i = 0; i < 8; i++)
      {
        Serial.print("0x");
        if (address[i] < 0x10) Serial.print("0");
        Serial.print(address[i], HEX);
        if (i < 7) Serial.print(", ");
      }
      Serial.println("  },");
    } while (ow.search(address));

    Serial.println("};");
    Serial.print("// nr devices found: ");
    Serial.println(count);
  }

  return count;
}
/********************************************************************/
// call the Dallas routine to get all sensor addresses
// slight mods only like removing the now redundant lib reference
// also kept the comm speed to 9600 for now not 115k
/********************************************************************/
/********************************************************************/
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
