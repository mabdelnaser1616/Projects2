#include<Servo.h>
#include <Ultrasonic.h>
Ultrasonic ultra(5, 4);

Servo s;


void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  s.attach(7);


  



}

void loop() {
  // put your main code here, to run repeatedly:
  float distance=ultra.read();
  Serial.println(distance);
  if(distance<20){
    

    s.write(90);
   



     
  }
  else{
    

    s.write(0);
    


  }

}
