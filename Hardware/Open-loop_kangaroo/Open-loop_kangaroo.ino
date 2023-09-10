const int pwm = 9;
const int dir = 10;
const int inputCLK = 4;
const int inputDT = 3;
int pinAstateCurrent = LOW;                // Current state of Pin A
int pinAStateLast = pinAstateCurrent; 
String encdir ="";
double deflection = 0;
int counter = 0; 

void setup() {
  // put your setup code here, to run once:
  pinMode(pwm,OUTPUT); 
  pinMode(dir,OUTPUT); 
  pinMode (inputCLK,INPUT);
  pinMode (inputDT,INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(inputDT), update, CHANGE);
}

void update() {

  /* WARNING: For this example I've used Serial.println within the interrupt callback. The Serial 
   * library already uses interrupts which could cause errors. Therefore do not use functions 
   * of the Serial libray in your interrupt callback.
   */

  // ROTATION DIRECTION
  pinAstateCurrent = digitalRead(inputCLK);    // Read the current state of Pin A
  
  // If there is a minimal movement of 1 step
  if ((pinAStateLast == LOW) && (pinAstateCurrent == HIGH)) {
    
    if (digitalRead(inputDT) == HIGH) {      // If Pin B is HIGH
      counter++; 
      deflection = counter*1.8/12.0;
      Serial.println(deflection);
    } else {
      counter--;   
      deflection = counter*1.8/12.0;
      Serial.println(deflection);
    }
    
  }
  
  pinAStateLast = pinAstateCurrent;        // Store the latest read value in the currect state variable
  
}
 
void loop() {
  // put your main code here, to run repeatedly:
 for(int x=0;x<63;x++)
 {
  float y = float(x)/10;
  delay(100);
 if(y>0 && y<3.14)
 {
  digitalWrite(dir,HIGH);
 }
 else
 {
  digitalWrite(dir,LOW);
 }
  analogWrite(pwm,10*sin(y));
  //Serial.print("Wave: ");
  Serial.println(10*sin(y));
  //Serial.print("Deflection: ");
  //Serial.print(deflection);
 }
}
