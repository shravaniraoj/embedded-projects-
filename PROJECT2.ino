#include<LiquidCrystal.h>
const int rs=13,en=12,d4=8,d5=9,d6=10,d7=11;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int s1=2,s2=3,s3=4,s4=5;
int led=6;
void setup()
{
  pinMode(s1,INPUT_PULLUP);
  pinMode(s2,INPUT_PULLUP);
  pinMode(s3,INPUT_PULLUP);
  pinMode(s4,INPUT_PULLUP);
  pinMode(led,OUTPUT);
  lcd.begin(20,4);
  lcd.clear();
  lcd.print("Restaurant Management ");
  lcd.setCursor(0,1);
  lcd.print("system");
  delay(2000);
  lcd.clear();
  lcd.print("select your menu");
  delay(2000);
}
void loop()
{
  main_menu();
}
void main_menu()
{
  digitalWrite(led,HIGH);
  lcd.clear();
  lcd.print("1.Tiffin 2.Lunch 3.Snacks 4.Tea");
  if(digitalRead(s1)==LOW)
  {
   lcd.clear();
   lcd.print("Tiffin Selected");
   delay(2000);
   lcd.clear();
   lcd.print("select your dish");
   delay(2000);
   lcd.clear();
   lcd.print("1.idli 2.dosa 3.puri 4.back");
   select();
   }
  else if(digitalRead(s2)==LOW)
  {
    lcd.clear();
    lcd.print("Lunch Selected");
    delay(2000);
    lcd.clear();
    lcd.print("select your dish");
    delay(2000);
    lcd.clear();
    lcd.print("1.north 2.south 3.roti 4.back");
    delay(3000);
    select(); 
  }
  else if(digitalRead(s3)==LOW)
  {
    lcd.clear();
    lcd.print("Snacks Selected");
    delay(2000);
    lcd.clear();
    lcd.print("select your dish");
    delay(2000);
    lcd.clear();
    lcd.print("1.samosa 2.kachori 3.chats 4.back");
    delay(3000);
    select(); 
  }
  else if(digitalRead(s4)==LOW)
  {
    lcd.clear();
    lcd.print("Tea Selected");
    delay(2000);
    lcd.clear();
    lcd.print("select your dish");
    delay(2000);
    lcd.clear();
    lcd.print("1.coffee 2.tea 3.milk 4.back");
    delay(3000);
    select(); 
  }
}
void select()
{
  while(1)
  {
    if(digitalRead(s1)==LOW)
    {
      lcd.clear();
      lcd.print("1 selected");
      delay(2000);
      confirm();
    }
    else if(digitalRead(s2)==LOW)
    {
      lcd.clear();
      lcd.print("2 selected");
      delay(2000);
      confirm();
    }
    else if(digitalRead(s3)==LOW)
    {
      lcd.clear();
      lcd.print("3 selected");
      delay(2000);
      confirm();
    }
    else if(digitalRead(s4)==LOW)
    {
      lcd.clear();
      lcd.print("back to main menu");
      delay(2000);
      main_menu();
    }
  }
}
void confirm()
{
  lcd.clear();
  lcd.print("1.yes 2.no");
  while(1)
  {
    if(digitalRead(s1)==LOW)
    {
      lcd.clear();
      lcd.print("thank you visit again");
      delay(2000);
      digitalWrite(led,LOW);
      return;
    }
   else if(digitalRead(s2)==LOW)
   {
     main_menu();
   }
  }
}
