//AUTOMATIC WIPER SYSTEM
#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(11,10,7,6,5,4);
Servo servo; 

int InInPositionition = 0; 
int SensorValue = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  servo.attach(9);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Automatic Auto."); 
  lcd.setCursor(0,1);
  lcd.print("Wiper System");
  delay(3000); 
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("Rain fall");
  lcd.setCursor(0,1);
  lcd.print("Intensity-");
}



void wipe(int Speed)
{

  if(Speed>400){Speed=5000;lcd.print("  LOW ");}
  if(Speed>350&&Speed<=400){Speed=3000;lcd.print("MEDIUM");}
  if(Speed<=350){Speed=500;lcd.print(" HIGH ");}
  for (InPosition = 180; InPosition >= 0; InPosition--) {
    servo.write(InPosition);            
    delay(3);                    
  }
  for (InPosition = 0; InPosition <= 180; InPosition++) { 
    servo.write(InPosition);             
    delay(3);                       
  }
  delay(Speed);
}




void loop() 
{
lcd.setCursor(10,1);
SensorValue = analogRead(A0);
Serial.println(SensorValue);
if(SensorValue>600){servo.write(180);lcd.print(" NIL  ");delay(1000);}
if(SensorValue<=600){lcd.setCursor(10,1);wipe(SensorValue);}
}
