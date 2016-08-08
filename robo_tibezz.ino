/*
  Equipe Tibezz;
  Participantes: Luis E., Bruno G., Pedro A., Wesley C. e Joao N.; 
  Robotica IFAL
  
*/


//Import libraries 
#include <AFMotor.h> //librarie of motor shiedl
#include <Ultrasonic.h> //librarie of sensor ultrasonic

//Definition of ports
#define TRIGGER A0 
#define ECHO A1

//Create objects 
AF_DCMotor MRBack(3);//Motor direito traseiro
AF_DCMotor MLBack(4);//Motor esquerdo traseiro

AF_DCMotor MRFront(2);//Motor direito dianteiro
AF_DCMotor MLFront(1);//Motor esquerdo dianteiro

Ultrasonic Sensor(TRIGGER, ECHO);



/*
  Possiveis metodos:
  
    millis() - tempo de execucao
    setSpeed() - vel. do motor
    run() - direcao do motor
    timing() - recupera o tempo que a onda sonora levou
    convert(time, Ultrassonic::CM) - calcula a distancia do obstaculo com base no tempo
*/

void setup(){
  
  Serial.begin(9600); //Inicializando o serial  
  
}

void loop(){
  
  //Configuration of motors
  MRBack.setSpeed(250);
  MRBack.run(FORWARD);
  
  MLBack.setSpeed(250);
  MLBack.run(FORWARD);
  
  MRFront.setSpeed(250);
  MRFront.run(FORWARD);
  
  MLFront.setSpeed(250);
  MLFront.run(FORWARD);
}
