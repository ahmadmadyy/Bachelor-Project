
 // Rotary Encoder Inputs
 #define inputCLK 6
 #define inputDT 7
 const int pwm = 9; // pin 10 as pwm
const int dir = 10;  // pin 9 as dir
float x=0;

 int counter = 0; 
 int currentStateCLK;
 int previousStateCLK; 

 String encdir ="";

 void setup() { 
   
   // Set encoder pins as inputs  
   pinMode (inputCLK,INPUT);
   pinMode (inputDT,INPUT);
   pinMode(pwm,OUTPUT); //declare pin pwm as OUTPUT
  pinMode(dir,OUTPUT); //declare pin dir as OUTPUT


   // Setup Serial Monitor
   Serial.begin (9600);
   
   // Read the initial state of inputCLK
   // Assign to previousStateCLK variable
   previousStateCLK = digitalRead(inputCLK);

 } 

 void loop() { 
   digitalWrite(dir,HIGH); 
   analogWrite(pwm,255);
  // Read the current state of inputCLK
   currentStateCLK = digitalRead(inputCLK);
    
   // If the previous and the current state of the inputCLK are different then a pulse has occured
   if (currentStateCLK != previousStateCLK){ 
       
     // If the inputDT state is different than the inputCLK state then 
     // the encoder is rotating counterclockwise
     if (digitalRead(inputDT) != currentStateCLK) { 
       counter --;
       x=counter*1.8/12;
       encdir ="CCW";
       
     } else {
       // Encoder is rotating clockwise
       counter ++;
       x=counter*1.8/12;
       encdir ="CW";
       
     }
     Serial.print("Direction: ");
     Serial.print(encdir);
     Serial.print(" -- Value: ");
     Serial.println(x);
   } 
   // Update previousStateCLK with the current state
   previousStateCLK = currentStateCLK; 
 }
