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
    
    
    LDR => retorno baixo: muita luz; retorno alto: pouca luz.
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
  
  //muito perto
  if(cm <= 15 ){
    offMotor();
    delay(200);
    powerMotor(150, 50, 150, 50);
  }
  else if (cm > 15 and cm <= 100){
    powerMotor(150, 150, 150, 150);
  }
  else if (cm > 100 and cm <= 400){
    powerMotor(250, 250, 250, 250); 
  }
    
}

/*
Ordem do metodo =>  motor da frente esquerda depois direita, motor traseiro esquerdo depois direita
Basta colocar a velocidade deseja como argumento
*/

void powerMotor(int vLeftFront, int vRightFront,  int vLeftBack, int vRightBack){ //metodo para ligar motor, velocidade em 250
  
  MRBack.setSpeed(vRightBack);
  MRBack.run(FORWARD);
  
  MLBack.setSpeed(vLeftBack);
  MLBack.run(FORWARD);
  
  MRFront.setSpeed(vRightFront);
  MRFront.run(FORWARD);
  
  MLFront.setSpeed(vLeftFront);
  MLFront.run(FORWARD);
}

//desligar motor
void offMotor (){
  
  MRBack.setSpeed(0);
  MRBack.run(RELEASE);
  
  MLBack.setSpeed(0);
  MLBack.run(RELEASE);
  
  MRFront.setSpeed(0);
  MRFront.run(RELEASE);
  
  MLFront.setSpeed(0);
  MLFront.run(RELEASE);
  
}
