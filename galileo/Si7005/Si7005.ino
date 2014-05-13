#include <Wire.h>
#include <Si7005.h> // Library Jonas Bo Jalling, <jonas@jalling.dk>, modified for Intel Galileo 

Si7005 Si(8); // CS is pin 8
char buff[70]; // output buffer



int getFrac(float f) // Blackmagic because sprintf doesn't handle %f
{
    unsigned int frac;
    if(f >= 0)
        frac = (f - int(f)) * 100;
    else
        frac = (int(f)- f ) * 100;
    return frac;
}

void setup()
{
  system("ifconfig eth0 192.168.158.82 netmask 255.255.255.252"); // Static IP: 192.168.158.82/30

  //Initialize sensor
  pinMode( 8, OUTPUT );
  digitalWrite( 8, HIGH );
  Wire.begin();
  
  if (!Si.detectSensor()) // Error message to temp file and endless loop
  {
    system("echo Device NOT detected >> /tmp/error");
    while (1) {;}
  }
    
  Si.disableHeater(); // for correct measurements
}


void loop()
{
  // Measure
  float temperature, humidity;
  temperature = Si.getTemperature();
  humidity = Si.getHumidity();

  // And send the data
  sprintf(buff,"wget \"http://192.168.158.81/set.php?temp=%d.%d&humidity=%d.%d\" -O -",int(temperature), getFrac(temperature),int(humidity), getFrac(humidity));
  system(buff);
  
  delay(1000);
}

