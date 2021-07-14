#include <DHT.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,6,5,4,3);
int trigpin = 8;
int echopin = 9;
float duration;
float distance_cm;
float distance_inch;


void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin,INPUT);

}

void loop() {

  digitalWrite(8,LOW);
  delay(100);
  digitalWrite(8,HIGH);
  delay(100);
  digitalWrite(trigpin,LOW);
  duration=pulseIn(9,HIGH);
distance_cm=0.034*duration/2.0;
distance_inch=distance_cm*0.393701;
lcd.setCursor(0,0);
lcd.print("Distance:");
lcd.print(distance_cm);
lcd.print("cm");

Serial.println("Distance:" + String(distance_cm)+"cm");
lcd.setCursor(0,1);
lcd.print(distance_inch);
lcd.print("inch");

Serial.println("Distance:" + String(distance_inch)+"inch");
Serial.println(distance_inch);

  delay(1000);
  
}
