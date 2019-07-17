const int RF  = 6;
const int RB  = 7;

const int LF  = 8;
const int LB  = 9;

 int vSpeed=255;     // Default speed, from 0 to 255
 int state;

void setup() {
  
  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);
  

  Serial.begin(9600);
}
void loop() {
  

  if (Serial.available() > 0) {
    state = Serial.read();
  }
  
  //Change speed if state is equal from 0 to 4. Values must be from 0 to 255 (PWM)
    if (state == '0'){
      vSpeed=0;}
    else if (state == '1'){
      vSpeed=100;}
    else if (state == '2'){
      vSpeed=180;}
    else if (state == '3'){
      vSpeed=200;}
    else if (state == '4'){
      vSpeed=255;}


 // OK    
  if (state == 'F') {
    analogWrite(RF, vSpeed);  analogWrite(RB, 0);
    analogWrite(LF, vSpeed);  analogWrite(LB, 0);
  }
  
// OK  
  else if (state == 'B') {
    analogWrite(RF, 0);   analogWrite(RB, vSpeed);
    analogWrite(LF, 0);   analogWrite(LB, vSpeed);
  }

//OK
    else if (state == 'G') {
    analogWrite(RF, vSpeed);   analogWrite(RB,0 );
    analogWrite(LF, 0);   analogWrite(LB, vSpeed);
   }

//OK
  else if (state == 'I') {
    analogWrite(RF, 0);   analogWrite(RB, vSpeed);
    analogWrite(LF, vSpeed);   analogWrite(LB,0 );
  
  }

//OK
  else if (state == 'L') {
    analogWrite(RF,vSpeed); analogWrite(RB, 0); 
    analogWrite(LF, 0);      analogWrite(LB, 0); 
 
  }
  
//OK  
  else if (state == 'R') {
    analogWrite(RF,0); analogWrite(RB, 0);  
    analogWrite(LF, vSpeed);    analogWrite(LB, 0); 
  
  }

//OK
  else if (state == 'J') {
    analogWrite(RF, 0);   analogWrite(RB,0 ); 
    analogWrite(LF, 0); analogWrite(LB, vSpeed);
 
  }

//OK  
  else if (state == 'H') {
    analogWrite(RF, 0);   analogWrite(RB, vSpeed); 
    analogWrite(LF, 0);   analogWrite(LB,0 ); 
   
  }

//OK

  else
  {
  analogWrite(RF, 0);   analogWrite(RB, 0);
  analogWrite(LF, 0);   analogWrite(LB, 0);

   }



/*
   
  if (state == 'W') {
    digitalWrite(lights, HIGH);
    state = 'n';
  }
  else if (state == 'w') {
    digitalWrite(lights, LOW);
    state = 'n';
  }
  else if (state == 'U') {
    digitalWrite(blights, HIGH);
    state = 'n';
  }
  else if (state == 'u') {
    digitalWrite(blights, LOW);
    state = 'n';
  }
  else if (state == 'V') {
    tone(buzzer, 1000);
    state = 'n';
  }
  else if (state == 'v') {
    noTone(buzzer);
    state = 'n';
  }
    else if (state == 'X') {
    digitalWrite(extra, HIGH);
    digitalWrite(slightl, HIGH);
    digitalWrite(slightr, HIGH);
    digitalWrite(blights, HIGH);
    state = 'n';
  }
  else if (state == 'x') {
    digitalWrite(extra, LOW);
    digitalWrite(slightl, LOW);
    digitalWrite(slightr, LOW);
    digitalWrite(blights, LOW);
    state = 'n';
  }
*/
  
}
