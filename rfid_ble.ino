#include <SoftwareSerial.h>

String tag, s;
String tag_id[30];
int counter = 0;

SoftwareSerial blueTooth(11, 10);
SoftwareSerial RFID(2, 255); 

void setup()
{   
  blueTooth.begin(9600);
  RFID.begin(9600);
}  

void loop() {
  while (RFID.available())
  {
    s = String(RFID.read(), HEX);
    tag = s + "-";
    tag_id[counter] = s;
    counter++;
  }
  if(tag != "")
  {
    tag="";
    for(int i = 0; i < 30; i++)
    {
      bluetooth.print(tag_id[i] + " ");
    }
    bluetooth.println("#");
    counter = 0;
  }
  
}