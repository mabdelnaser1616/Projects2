#include<Servo.h>
#include<NewPing.h>
Servo s;
boolean goesforword;
int distance= 150;
NewPing sensor(A1,A2,250);
 const int leftmoterforward=7;
const int rihgtmoterforward=6;
 const int leftmoterbackward=5;
const int rightmoterbackward=4;


`







void setup() {
  // put your setup code here, to run once:
  pinMode(leftmoterforward,OUTPUT);
  pinMode(rihgtmoterforward,OUTPUT);
  pinMode(leftmoterbackward,OUTPUT);
  pinMode(rightmoterbackward,OUTPUT);
  s.attach(10);
  s.write(115);
  delay(1000);
  distance= readPing();
  delay(100);
  distance= readPing();
  delay(100);
  distance= readPing();
  delay(100);
  distance= readPing();
  delay(100);
  
  
  








}

void loop() {
  // put your main code here, to run repeatedly:
  if(distance<=20){
    stop();
    delay(100);
    backward();
    delay(100);
    stop();
    int right=  lookright();
    delay(1000);
    int left=lookleft();
    if(distance>=left){
      turnrihgt();

    }
    else{
      turnleft();

    }

  



  }
  else{
    forward();

  }
  int distance= readPing();


}
int lookright(){
  s.write(50);
  delay(2000);
  int distance= readPing();
  delay(100);
  s.write(115);
  delay(2000);
  return distance;


}
int lookleft(){
  s.write(170);
  delay(2000);
  int distance= readPing();
  delay(100);
  s.write(115);
  delay(2000);
  return distance;
  

}
int readPing(){
  delay(70);
  int cm= sensor.ping_cm();
  if(cm==0){
    cm=250;

  }
  return cm;


}
void stop(){
  digitalWrite(leftmoterforward,0);
  digitalWrite(rihgtmoterforward,0);
  digitalWrite(leftmoterforward,0);
  digitalWrite(rightmoterbackward,0);





}
void forward(){
  if(!goesforword){
    goesforword=true;
      digitalWrite(leftmoterforward,1);
      digitalWrite(rihgtmoterforward,1);
     digitalWrite(leftmoterforward,0);
     digitalWrite(rightmoterbackward,0);
  }
}
void backward(){
  goesforword= false;
    digitalWrite(leftmoterforward,0);
   digitalWrite(rihgtmoterforward,0);
   digitalWrite(leftmoterforward,1);
   digitalWrite(rightmoterbackward,1);
}
void turnrihgt(){
    digitalWrite(leftmoterforward,1);
  digitalWrite(rihgtmoterforward,0);
  digitalWrite(leftmoterbackward,0);
  digitalWrite(rightmoterbackward,1);
  delay(500);
    digitalWrite(leftmoterforward,1);
  digitalWrite(rihgtmoterforward,0);
  digitalWrite(leftmoterbackward,0);
  digitalWrite(rightmoterbackward,1);
}
void turnleft(){
    digitalWrite(leftmoterforward,0);
  digitalWrite(rihgtmoterforward,1);
  digitalWrite(leftmoterbackward,1);
  digitalWrite(rightmoterbackward,0);
  delay(500);
    digitalWrite(leftmoterforward,0);
  digitalWrite(rihgtmoterforward,1);
  digitalWrite(leftmoterbackward,1);
  digitalWrite(rightmoterbackward,0);
}
