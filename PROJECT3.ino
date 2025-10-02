#include<LiquidCrystal.h>
const int rs=13,en=12,d4=8,d5=9,d6=10,d7=11;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int led=7;
int ir=2,gas=3,fire=4,ldr=5,buz=6;
void setup()
{
  pinMode(ir,INPUT);
  pinMode(gas,INPUT);
  pinMode(fire,INPUT);
  pinMode(ldr,INPUT);
  pinMode(buz,OUTPUT);
  pinMode(led,OUTPUT);
  lcd.begin(20,4);
  lcd.clear();
  lcd.print("Smart Home");
  delay(2000);
  lcd.clear();
  lcd.print("check sensors");
  delay(2000);
  lcd.clear();
  lcd.print("ir,fire,gas,ldr");
  delay(2000);
  lcd.clear();
}
void loop()
{
  if(digitalRead(ir)==LOW)
  {
    lcd.clear();
    lcd.print("person detected");
    delay(3000);
    lcd.clear();
    digitalWrite(led,HIGH);
  }
  else if(digitalRead(gas)==LOW)
  {
    lcd.clear();
    lcd.print("gas detected");
    delay(5000);
    lcd.clear();
    lightandsound();
  }
  else if(digitalRead(fire)==LOW)
  {
    lcd.clear();
    lcd.print("Fire detected");
    delay(5000);
    lcd.clear();
    lightandsound();
  }
   else if(digitalRead(ldr)==HIGH)
  {
    lcd.clear();
    lcd.print("Darkness Detected");
    delay(2000);
    digitalWrite(led,HIGH);
  }
  else if(digitalRead(ldr)==LOW)
  {
    lcd.clear();
    lcd.print("NO Darkness");
    delay(2000);
    digitalWrite(led,LOW);
  }
}
void lightandsound()
{
  digitalWrite(led,LOW);
  digitalWrite(buz,HIGH);
  delay(100);
  digitalWrite(buz,LOW);
}
