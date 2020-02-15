#include <SoftwareSerial.h>

SoftwareSerial hc06(2,3);
int led = 13;
char val;

void setup(){
  //Initialize Serial Monitor
  Serial.begin(9600);
  Serial.println("ENTER AT Commands:");
  pinMode(led, OUTPUT);
  //Initialize Bluetooth Serial Port
  hc06.begin(9600);
  Serial.begin(9600);
}

void loop(){
  //Write data from HC06 to Serial Monitor
  if (hc06.available()){
    Serial.write(hc06.read());
  }
  
  //Write from Serial Monitor to HC06
  if (Serial.available()){
    hc06.write(Serial.read());
  }  

  while(hc06.available()>0)
  {
    val = hc06.read();
    Serial.println(val);
  }

  if(val == '1'){
    digitalWrite(led, HIGH);
  }
  else if(val == '2'){
    digitalWrite(led, LOW);
  }
}
