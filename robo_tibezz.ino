//Import libraries 
#include <AFMotor.h>
#include <Ultrasonic.h>

//Create objects 
AF_DCMotor MRBack(3);//Motor direito traseiro
AF_DCMotor MLBack(4);//Motor esquerdo traseiro

AF_DCMotor MRFront(2);//Motor direito dianteiro
AF_DCMotor MLFront(1);//Motor esquerdo dianteiro

void setup(){
}

void loop(){
  
  //Configuration of motors
  //MRBack.setSpeed(250);
  //MRBack.run(FORWARD);
  
  MLBack.setSpeed(250);
  MLBack.run(FORWARD);
  
  //MRFront.setSpeed(250);
  //MRFront.run(FORWARD);
  
  MLFront.setSpeed(250);
  MLFront.run(FORWARD);
}
