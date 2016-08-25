/*
  Equipe Tibezz;
  Participantes: Luis E., Bruno G., Pedro A., Wesley C. e Joao N.; 
  Robotica IFAL
  
*/


//Import libraries 
#include <AFMotor.h> //librarie of motor shiedl
#include <Ultrasonic.h> //librarie of sensor ultrasonic

//Definition of ports
#define TRIGGER A0 //sensor ultrasonic 
#define ECHO A1 //sensor ultrasonic
#define LED1 13 //led azul
#define LED2 2 //led azul
#define LDRRIGHT A2 //LDR direite
#define LDRCENTER A3 //LDR centro
#define LDRLEFT A4 //LDR esquerda

//Create objects 
AF_DCMotor MRBack(3);//Motor direito traseiro
AF_DCMotor MLBack(4);//Motor esquerdo traseiro

AF_DCMotor MRFront(2);//Motor direito dianteiro
AF_DCMotor MLFront(1);//Motor esquerdo dianteiro

Ultrasonic Sensor(TRIGGER, ECHO); //Sensor ultrassonico 



/*
  Possiveis metodos:
  
    millis() - tempo de execucao
    setSpeed() - vel. do motor
    run() - direcao do motor
    timing() - recupera o tempo que a onda sonora levou
    convert(time, Ultrasonic::CM) - calcula a distancia do obstaculo com base no tempo
*/

void setup(){
  
  Serial.begin(9600); //Inicializando o serial
  pinMode(LED1, OUTPUT);
  pinMode(LED2, INPUT);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  
}

//TESTE
void loop(){
  
  double mili = Sensor.timing();
  double cm = Sensor.convert(mili, Ultrasonic::CM);
  Serial.println(cm);
  
  
  if(cm <= 15 ){

  }
  
   
}


void powerMotor(){
  MRBack.run(FORWARD);
  MRBack.setSpeed(150);
  
  MLBack.run(FORWARD);
  MLBack.setSpeed(150);
  
  MRFront.run(FORWARD);
  MRFront.setSpeed(150);
  
  MLFront.run(FORWARD);
  MLFront.setSpeed(150);
}
