const int pwm = 9; // pin 10 as pwm
const int dir = 10;  // pin 9 as dir
int i=0; 

void setup(){

  Serial.begin(9600);
  pinMode(pwm,OUTPUT); //declare pin pwm as OUTPUT
  pinMode(dir,OUTPUT); //declare pin dir as OUTPUT

}

void loop(){
  //SIGN MAGNITUDE MODE  
  //Controlling motor with program set

   digitalWrite(dir,HIGH);  // if DIR pin is HIGH, B will HIGH ; if DIR pin is LOW, A will HIGH

    // from 0 to 255, increment one for every 0.5 second
   analogWrite(pwm,150);    //write 'i' value to PWM pin
}
