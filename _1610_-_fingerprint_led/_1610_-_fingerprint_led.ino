/* 
  FPS_Enroll.ino - Library example for controlling the GT-511C3 Finger Print Scanner (FPS)
  Created by Josh Hawley, July 23rd 2013
  Licensed for non-commercial use, must include this license message
  basically, Feel free to hack away at it, but just give me credit for my work =)
  TLDR; Wil Wheaton's Law

  This sketch will attempt to identify a previously enrolled fingerprint.
*/

#include "FPS_GT511C3.h"
#include "SoftwareSerial.h"

// Hardware setup - FPS connected to:
//    digital pin 4(arduino rx, fps tx)
//    digital pin 5(arduino tx - 560ohm resistor fps tx - 1000ohm resistor - ground)
//    this brings the 5v tx line down to about 3.2v so we dont fry our fps

FPS_GT511C3 fps(4, 5);

const int ledPin = 13;

void setup()
{
  Serial.begin(9600);
  delay(100);
  fps.Open();
  fps.SetLED(true);

        digitalWrite(ledPin, HIGH);   // turn the LED on   (HIGH is the voltage level)
      delay(1000);              // wait for a second
      digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
      delay(1000); 
}

void loop()
{

  // Identify fingerprint test
  if (fps.IsPressFinger())
  {
    fps.CaptureFinger(false);
    int id = fps.Identify1_N();
    if (id <200)
    {
      Serial.print("Verified ID:");
      Serial.println(id);
      digitalWrite(ledPin, HIGH);   // turn the LED on   (HIGH is the voltage level)
      delay(500);              // wait for a second
      digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
      delay(500);              // wait for a second
      digitalWrite(ledPin, HIGH);   // turn the LED on   (HIGH is the voltage level)
      delay(500);              // wait for a second
      digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
      delay(500);              // wait for a second
      
    }
    else
    {
      Serial.println("Finger not found");
       digitalWrite(ledPin, HIGH);   // turn the LED on   (HIGH is the voltage level)
      delay(100);              // wait for a second
      digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
      delay(100);   
      digitalWrite(ledPin, HIGH);   // turn the LED on   (HIGH is the voltage level)
      delay(100);   
      digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
      delay(100); 
    }
  }
  else
  {
    Serial.println("Please press finger");
  }
  delay(100);
}
