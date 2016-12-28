#include <Servo.h>
Servo myservo;
int IN3 = 7;
int IN4 = 8;
int ENB = 6;
int servodata;
int potpin = A0;
int pos = 60; 
int val;
void setup()  {
  Serial.begin(9600);
  Serial.println("Redy");

  myservo.attach(9);
  pinMode (8, OUTPUT);
  pinMode (7, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
}

void loop()
{

  if (Serial.available() > 0)
  {
    servodata = Serial.read();

    if (servodata == '1') // Single Quote! This is a character.
    {
      Serial.println("Y");
      
        myservo.write(68);
      
      
    }


  
  if (servodata == '2') // Single Quote! This is a character.
  {
    Serial.println("Y");
    
      myservo.write(19);

    
  }
  if (servodata == 'w') // Single Quote! This is a character.
  {
    Serial.println("OK");
    {

      digitalWrite (IN3, HIGH);
      digitalWrite (IN4, LOW);
    }
  }
  if (servodata == 's') // Single Quote! This is a character.
  {
    Serial.println("OK");
    {

      digitalWrite (IN3, LOW);
      digitalWrite (IN4, HIGH);
    }
  }
  if (servodata == 'e') // Single Quote! This is a character.
  {
    Serial.println("OK");
    {

      digitalWrite (IN3, LOW);
      digitalWrite (IN4, LOW);
    }
  }
  val = analogRead(potpin);
  val = map(val, 0, 1023, 0, 255);
  analogWrite(ENB, 245);
   
   if (servodata == 'h') // Single Quote! This is a character.
    {
      Serial.println(val);
    }
  }
}

