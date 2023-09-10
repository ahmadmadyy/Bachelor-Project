const int pwm = 9;
const int dir = 10;
const int inputCLK = 4;
const int inputDT = 3;
int max = 0;
double x=0;
int counter = 0; 
int currentStateCLK;
int previousStateCLK; 
String encdir ="";
double F_meas = 0;
double tau = 0;
double rpmo = 0;

void setup() {
  pinMode(pwm,OUTPUT); 
  pinMode(dir,OUTPUT); 
  pinMode (inputCLK,INPUT);
  pinMode (inputDT,INPUT);
  Serial.begin(9600);
  previousStateCLK = digitalRead(inputCLK);

}
double measure()
 {
   currentStateCLK = digitalRead(inputCLK);
   if (currentStateCLK != previousStateCLK){ 
     if (digitalRead(inputDT) != currentStateCLK) { 
       counter --;
       if(abs(counter)>max)
       {
        max = abs(counter);
       }
       
     } else {
       counter ++;
       encdir ="CW";
       if(abs(counter)>max)
       {
        max = abs(counter);
       }
       
     }

      //Serial.print("   ");
      //Serial.print("counter= ");
      //Serial.print(counter);
      //Serial.println();
      //Serial.print("max= ");
      //Serial.print(max);
      //Serial.println();
      //Serial.print("deflection= ");
      Serial.println(counter*1.8/12.0);
      //Serial.println();
   } 
   previousStateCLK = currentStateCLK; 
   return max*1.8/12.0;
 }



void loop() {
  x = measure();
 
  F_meas = 10930.4*x*0.01;
  //digitalWrite(dir,LOW);
  //analogWrite(pwm,50);
  //digitalWrite(dir,LOW);
  //analogWrite(pwm,50);

 
}
