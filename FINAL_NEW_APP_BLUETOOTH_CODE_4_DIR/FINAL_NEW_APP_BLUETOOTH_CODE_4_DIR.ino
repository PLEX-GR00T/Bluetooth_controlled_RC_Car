//L298 1st for MOTOR 1 & 4

#define en1 2   //MOTOR 1
#define m11 3   //motor 1 red & (l298 pin 1)
#define m12 4   //motor 1 black & (l298 pin 2)

#define en4 5   //MOTOR 4
#define m41 6   //motor 4 red & (l298 pin 3)
#define m42 7   //motor 4 black & (l298 pin 4)

String readString;

//PWM VALUES

int pwmh=255;
int pwml=150;
int pwms=0;

void forwardfast();
void forwardslow();

void reversefast();

void leftfast();

void rightfast();

void Freeze(); 

//FUNCTION BODY

void forwardfast()
{
  Serial.println("FORWARD FULL");
  Serial.println("pwmh=255");

  //FOR FRONT SIDE WHEELS
  
  analogWrite(en1,pwmh);
  digitalWrite(m11,HIGH);
  digitalWrite(m12,LOW);

  analogWrite(en4,pwmh);
  digitalWrite(m41,LOW);
  digitalWrite(m42,HIGH);
}

void forwardslow()
{
  Serial.println("FORWARD FULL");
  Serial.println("pwmh=255");

  //FOR FRONT SIDE WHEELS
  
  analogWrite(en1,230);
  digitalWrite(m11,HIGH);
  digitalWrite(m12,LOW);

  analogWrite(en4,230);
  digitalWrite(m41,LOW);
  digitalWrite(m42,HIGH);
}

void leftfast()
{
  Serial.println("LEFT FULL");
  Serial.println("1 & 2 pwmh=255,3 & 4 pwmh=255 rev");

  //FOR FRONT SIDE WHEELS
  
  analogWrite(en1,230);
  digitalWrite(m11,HIGH);
  digitalWrite(m12,LOW);

  analogWrite(en4,230);
  digitalWrite(m41,HIGH);
  digitalWrite(m42,LOW);
}

void rightfast()
{
  Serial.println("RIGHT FULL");
  Serial.println("1 & 2 pwmh=255 rev ,3 & 4 pwmh=255");

  //FOR FRONT SIDE WHEELS
  
  analogWrite(en1,230);
  digitalWrite(m11,LOW);
  digitalWrite(m12,HIGH);

  analogWrite(en4,230);
  digitalWrite(m41,LOW);
  digitalWrite(m42,HIGH);

}

void Freeze()
{
  Serial.println("FREEZE");
  
  analogWrite(en1,pwms);
  analogWrite(en4,pwms);
}
void setup()
{
  Serial.begin(9600);

  for(int j=2;j<7;j++)
  {
    pinMode(j,OUTPUT); //BASE MOTORs
    digitalWrite(j,LOW); //INITIALLY LOW 
  }
}

void loop() {
  while(Serial.available()){
    delay(50);
    char c = Serial.read();
    readString+=c;
  }

  if(readString.length() > 0) {
    Serial.println(readString);

    if(readString == "FORWARD") //APP=LEFT------CODE=FORWARD
    {
      leftfast();
    }
    
    if(readString == "BACK") //APP=RIGHT------CODE=BACK
    {
      rightfast();
    }

    if(readString == "LEFT") //APP=BACK------CODE=LEFT
    {
      forwardslow();
    }

    if(readString == "RIGHT")   //APP=FORWARD------CODE=RIGHT
    {
      forwardfast();
    }

    if(readString == "STOP")  //APP=FREEZE------CODE=STOP
    {  
      Freeze();
    }

    readString = "";
  }
}

