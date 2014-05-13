/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <jonas@jalling.dk> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.   Jonas Bo Jalling
 * ----------------------------------------------------------------------------
 */
/*
 Si7005
 
 Library for communicationg with the Silabs Si7005 temperature/
 humidity sensor over I2C.

 created 9 Aug 2013
 by Jonas B. Jalling
*/

#include <Wire.h>
#include <Si7005.h>

// Pin connected to the Si7005 CS pin
// The other I2C pins is controlled by the Wire library
const int Si7005_CS_PIN = 8;

Si7005 Si(Si7005_CS_PIN);
char buff[150];

void setup()
{
  system("ifconfig eth0 192.168.158.82 netmask 255.255.255.252");
  pinMode( Si7005_CS_PIN, OUTPUT );
  digitalWrite( Si7005_CS_PIN, HIGH );
  Wire.begin();
  
  digitalWrite( 9, HIGH );
  if (!Si.detectSensor())
  {
    system("echo Device NOT detected >> /tmp/x");
    while (1)
    {;;} // The sensor is not detected. Let's just stay here forever.
  }
  Si.disableHeater(); //disable the heater for good result
}

int getFrac(float f)
{
    unsigned int frac;
    if(f >= 0)
        frac = (f - int(f)) * 100;
    else
        frac = (int(f)- f ) * 100;
    return frac;
}


void loop()
{
  float temperature, humidity;

  // Uncomment line below to enable faster measurements (lower resolution)
  // Si.enableFastMeasurements();

  // Uncomment line below to enable the internal heater (affects the temperature measurement)
  // Si.enableHeater();

  // Do some measurements!
  temperature = Si.getTemperature();
  humidity = Si.getHumidity();

  // And output the data
  sprintf(buff,"wget \"http://192.168.158.81/set.php?temp=%d.%d&humidity=%d.%d\" -O -",int(temperature), getFrac(temperature),int(humidity), getFrac(humidity));
  system(buff);
  delay(1000);
}

