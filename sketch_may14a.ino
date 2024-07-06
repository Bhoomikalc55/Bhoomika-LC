#include <Wire.h>
#include <TinyGPS++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SoftwareSerial.h>

int a=0;
int led=5;
 


void SEND_SMS(String num, String str );
 
#define RXD2 2
#define TXD2 3
SoftwareSerial neogps(2,3);
 
TinyGPSPlus gps;

float latitude, longitude;
void setup() 
{
  
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  //Begin serial communication Arduino IDE (Serial Monitor)
 
  //Begin serial communication Neo6mGPS
  neogps.begin(9600);

  Serial.println("GPS TRACKER..");

   SEND_SMS("+918123096631","Safey Device");
  delay(2000);
 
}
 
void loop() {
    
  boolean newData = false;
  for (unsigned long start = millis(); millis() - start < 1000;)
  {
    while (neogps.available())
    {
      if (gps.encode(neogps.read()))
      {
        newData = true;
      }
    }
  }
 
  //If newData is true
  if(newData == true)
  {
    newData = false;
    Serial.println(gps.satellites.value());
    print_speed();
  }
  else
  {

    Serial.println("No Data");
   
  }  
  
}
// 
void print_speed()
{

  if (gps.location.isValid() == 1)
  {
  
    Serial.print("Lat: ");
    Serial.println(gps.location.lat(),6);

    Serial.print("Lng: ");
    Serial.println(gps.location.lng(),6);
    delay(1000);
    latitude=gps.location.lat(),6;
    longitude=gps.location.lng(),6;
    
    String one = "Device Location AT:https://www.google.com/maps/?q=";
  String two = "," ;   
  String message = one +latitude +two + longitude;
  
  // Convert String to char array
  int str_len = message.length() + 1;
  char textmessage[str_len];
  message.toCharArray(textmessage,str_len);
  Serial.println(textmessage);
  digitalWrite(led,HIGH);
  delay(1000); 

  RFID();
         
  }
  else
  {

    Serial.println("No Data");
    digitalWrite(led,LOW);

  }  
 
}

void SEND_SMS(String num, String str )
{
    Serial.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
    delay(1000); // Delay of 1000 milli seconds or 1 second
    
    Serial.print("AT+CMGS=\""); // Send the SMS number
    Serial.print(num);
    Serial.println("\"");
    delay(1000);
    
    Serial.println(str);// The SMS text you want to send
    delay(100);
    
    Serial.println((char)26);// ASCII code of CTRL+Z
    delay(1000);

    Serial.println("SMS Sent..");
 
}

void RFID()
{
  if(Serial.available()>0)
  {
    String card=Serial.readString();
    Serial.println(card);
    delay(500);
    if(card=="15001FC0D71D")
    {
      if(a==0)
      {
        a=1;
        

        Serial.println("Tapped once");
        delay(1000);
      }
      else if(a==1)
      {
        a=0;
        String one = "Emergency AT:https://www.google.com/maps/?q=";
        String two = "," ;   
        String message = one +latitude +two + longitude;
        
        // Convert String to char array
        int str_len = message.length() + 1;
        char textmessage[str_len];
        message.toCharArray(textmessage,str_len);
        Serial.println(textmessage);
        SEND_SMS("+918123096631",textmessage);
//        digitalWrite(led,HIGH);
        delay(2000);
//        digitalWrite(led,LOW);
//        delay(1000);
    
      }
    }
  }
}