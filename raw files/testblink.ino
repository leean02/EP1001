#define led 4 // led connected to PA3 #4
#define fan 0 // fan connected to PA6 #0
// #define sw 3 // switch connected to PA2 #3
#define ldr 1 // ldr connected to PA7 #1
//#define btn 0 // btn connected to PA6 #0

// int sw_read;
int ldr_read;
// float ldr_volt;
// const float q = 5/1024;

void setup () {
pinMode (led, OUTPUT);
pinMode (fan, OUTPUT);
// pinMode (sw, INPUT_PULLUP);
pinMode (ldr, INPUT);
// pinMode (btn, INPUT);
// Serial.begin(9600);
}

void loop () {
  digitalWrite(led, HIGH);
  ldr_read = analogRead(ldr);
  if(ldr_read < 50)
  {
    digitalWrite(fan, HIGH);
  }
  else {
    digitalWrite(fan, LOW);
  }
}
  /*
   digitalWrite(led, HIGH);
    digitalWrite(fan, HIGH);
    
    delay(5000);
    
    digitalWrite(led, LOW);
    digitalWrite(fan, LOW);

    delay(5000);

  while(1){
    digitalWrite(led,digitalRead(sw));
  }
  if (digitalRead(btn) == LOW ){
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
  digitalWrite(fan, LOW);
  delay(5000);
  digitalWrite(fan, HIGH);
  delay(5000);
  if(digitalRead(sw) == HIGH) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }*/
