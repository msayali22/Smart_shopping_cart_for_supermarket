#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

char input[12];
int count = 0;
int a;
int p1=0,p2=0,p3=0,p4=0; 
int c1=0,c2=0,c3=0,c4=0;

double total = 0;
int count_prod = 0;


void setup ()
{
//  Pin direction
   
  pinMode(3, INPUT_PULLUP);   //Push Switch
  pinMode(4, OUTPUT);         //RED LED
  pinMode(5, OUTPUT);         //BUZZER
  pinMode(6, OUTPUT);         //GREEN LED

// Initialization
  Serial.begin(9600);

  
//  lcd.begin();
 lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(" AUTOMATIC BILL");
  delay (2000);
  lcd.setCursor(0, 1);
  lcd.print("  SHOPPING CART       ");
  delay (2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   WELCOME TO ");
  lcd.setCursor(0, 1); 
  lcd.print("JUST DO SHOPPING");

}
 void loop()
{
  
 count = 0;
    while (Serial.available() && count < 12)
    {
      input[count] = Serial.read();
      delay(5);
    }
      int a=digitalRead(3);
      
     if ((strncmp(input, "4000350ABAC5", 12) == 0) && (a == 1))
      {
       
        lcd.setCursor(0, 0);
        lcd.print("Sanitizer Added       ");
        lcd.setCursor(0, 1);
        lcd.print("Price(Rm):100      ");
        digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
        delay(2000);
        total = total + 100;
        count_prod++;
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);
        
      }


      else if ((strncmp(input, "4000350ABAC5", 12) == 0) && (a == 0))
      {
        if(p1>0)
        {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Sanitizer Removed!!!        "); 
        digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
        delay(2000);
        total = total - 100;
        lcd.clear();
       digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);
        }
        else
        {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Not in cart!!!        ");
        digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
        delay(2000);
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);
        lcd.clear();
        }
      }


       if ((strncmp(input, "4000351B7B15", 12) == 0) && (a == 1))
      {
        lcd.setCursor(0, 0);
        lcd.print("PPE Kit Added       ");
        lcd.setCursor(0, 1);
        lcd.print("Price(Rm):300      ");
       
        digitalWrite(6,HIGH);
        delay(2000);
        total = total + 300;
        count_prod++;
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);
        
      }


      else if ((strncmp(input, "4000351B7B15", 12) == 0) && (a == 0))
      {
        if(p2>0)
        {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("PPE Kit Removed!!!        ");
         digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
        delay(2000);
        total = total - 300;
        lcd.clear();
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);
        }
        else
        {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Not in cart!!!        ");
         digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
        delay(2000);
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);
        lcd.clear();
        }
      }

           if ((strncmp(input, "4000352B7C45", 12) == 0) && (a == 1))
      {
        lcd.setCursor(0, 0);
        lcd.print("Mask Added       ");
        lcd.setCursor(0, 1);
        lcd.print("Price(Rm):200      ");
       
        digitalWrite(6,HIGH);
        delay(2000);
        total = total + 200;
        count_prod++;
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);
        
      }


      else if ((strncmp(input, "4000352B7C45", 12) == 0) && (a == 0))
      {
        if(p3>0)
        {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Mask Removed!!!        ");
         digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
        delay(2000);
        total = total - 200;
        lcd.clear();
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);
        }
        else
        {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Not in cart!!!        ");
         digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
        delay(2000);
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);
        lcd.clear();
        }
      }

          if ((strncmp(input, "4000357D7B56", 12) == 0) && (a == 1))
      {
        lcd.setCursor(0, 0);
        lcd.print("Face Shild Added       ");
        lcd.setCursor(0, 1);
        lcd.print("Price(Rm):400      ");
       
        digitalWrite(6,HIGH);
        delay(2000);
        total = total + 400;
        count_prod++;
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);
        
      }


      else if ((strncmp(input, "4000357D7B56", 12) == 0) && (a == 0))
      {
        if(p4>0)
        {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Face Shild Removed!!!        ");
         digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
        delay(2000);
        total = total - 400;
        lcd.clear();
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);
        }
        else
        {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Not in cart!!!        ");
         digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
        delay(2000);
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);
        lcd.clear();
        }
      }

    if ((strncmp(input, "4000355181A5", 12) == 0) && (a == 1))
      {

     lcd.clear();  
     lcd.setCursor(0, 0);
     lcd.print("Total Price :-");
        
     lcd.setCursor(0, 1);
     lcd.print(total);

     delay(5000);
     lcd.clear();
   lcd.setCursor(0, 0);
  lcd.print("  THANKS FOR  ");
   lcd.setCursor(0, 1);
  lcd.print("   VISITING ");
     
      }     

}

