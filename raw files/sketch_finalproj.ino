// VESA laptop stand (http://leean02.github.io/EP1001/finalproject1001.html)
  
#define fan 0     // PA6
#define ldr 1     // PA7
#define temp 2    // PA1
#define sw 3      // PA2
#define led 4     // PA3

int sw_read;
int ldr_read;
int temp_read;
float ldr_volt;
float temp_volt;
float t;
const float constant = 5/1024;    // analogRead output is between 0 to 1023 as resolution of read out is 2^10, 5V is reference volt

void setup() {
  // put your setup code here, to run once:
  pinMode(fan, OUTPUT);
  pinMode(ldr, INPUT);
  pinMode(temp, INPUT);
  pinMode(sw, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  
  sw_read = digitalRead(sw);
  
  if (sw_read == 0) {    // switch closed (automatic on)
    digitalWrite(led, HIGH);    // led turn on when system is in operation
    ldr_read = analogRead(ldr);
    // ldr_volt = ldr_read * constant;
    
    if(ldr_read < 50)  {    // laptop on holder, resistance higher than 4.5 volts
      temp_read = analogRead(temp);
      //temp_volt = temp_read * constant;
      //t = temp_volt/0.01;   // increases by 0.01 volt every 1 degree celsius
      
      if(temp_read > 90)  {    // temp probe measures temperature above 30 degreee celsius
        digitalWrite(fan, HIGH);
      }
      
      else  {
        digitalWrite(fan, LOW);
      }
      
    }
    
    else  {
      digitalWrite(fan, LOW);
    }
  }
  
  else  {   // switch open (manual off)
    digitalWrite(led, LOW);
    digitalWrite(fan, LOW);
  }
  
}
