 
 // Rotary Encoder Inputs
 #define inputCLK 4
 #define inputDT 3

 int counter = 0; 
 int currentStateCLK;
 int previousStateCLK; 
 int x=0;
 int max;
 unsigned long time = 0;

 String encdir ="";

 void setup() { 
   
   // Set encoder pins as inputs  
   pinMode (inputCLK,INPUT);
   pinMode (inputDT,INPUT);

   // Setup Serial Monitor
   Serial.begin (9600);
   
   // Read the initial state of inputCLK
   // Assign to previousStateCLK variable
   previousStateCLK = digitalRead(inputCLK);

 } 
 int count()
 {
  // Read the current state of inputCLK
   currentStateCLK = digitalRead(inputCLK);
    
   // If the previous and the current state of the inputCLK are different then a pulse has occured
   if (currentStateCLK != previousStateCLK){ 
       
     // If the inputDT state is different than the inputCLK state then 
     // the encoder is rotating counterclockwise
     if (digitalRead(inputDT) != currentStateCLK) { 
       counter --;
       encdir ="CCW";
       if(counter>max)
       {
        max = counter;
       }
       
     } else {
       // Encoder is rotating clockwise
       counter ++;
       encdir ="CW";
       if(counter>max)
       {
        max = counter;
       }
       
     }
      Serial.print("   ");
      Serial.print("counter= ");
      Serial.print(counter);
      Serial.println();
      Serial.print("max= ");
      Serial.print(max);
      Serial.println();
   } 
   // Update previousStateCLK with the current state
   previousStateCLK = currentStateCLK; 
   return max;
 }
 
 void loop() 
 {
 x=count();

 }
 
