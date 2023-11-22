/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/
#define BLYNK_TEMPLATE_ID "TMPL4MVC3dAZc"
#define BLYNK_TEMPLATE_NAME "session2"
#define BLYNK_AUTH_TOKEN "nijx0j5fABzY3CvaIUn8h9TdJ31hKNyP"

#include <SPI.h>
#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h>

char auth[]=  BLYNK_AUTH_TOKEN;
char ssid[] = "4G-Gateway-E6F8";
char pass[] = "EE5NTMT4TGB";

BlynkTimer timer;

void myTimerEvent(){
  Blynk.virtualWrite(V2, millis()/1000);
}

BLYNK_WRITE(V3){
  if (param.asInt()==1){
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
  }
}

BLYNK_WRITE(V4){
  if (param.asInt()==1){
    digitalWrite(10, HIGH);
  }
  else{
    digitalWrite(10, LOW);
  }
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, myTimerEvent);
  pinMode(10, OUTPUT);

}

// the loop function runs over and over again forever
void loop() {
  Blynk.run();
  timer.run();
}
