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
#define LED1 13 //led branco
#define LED2 2 //led azul
#define LDRRIGHT A2 //LDR direito
#define LDRCENTER1 A5 //LDR centro
#define LDRCENTER2 A3 //LDR centro 2
#define LDRLEFT A4 //LDR esquerda

int desLeft;
int desRight;
int center1;
int center2;
int sensorRight;
int sensorLeft;
int sensorCenter1;
int sensorCenter2;

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

  //ligando leds
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  calibrar();

}


void loop(){

  //lendo sensor ultrassonico
  double mili = Sensor.timing();
  double cm = Sensor.convert(mili, Ultrasonic::CM);
  Serial.println(cm);

  powerMotor(150,150,150,150);



}

/*
Ordem do metodo =>  motor da frente esquerda depois direita, motor traseiro esquerdo depois direita
Basta colocar a velocidade deseja como argumento
*/

void calibrar(){
  for(int i = 0; i < 10; i ++){
    sensorLeft = analogRead(LDRLEFT);
    sensorCenter1 = analogRead(LDRCENTER1);
    sensorCenter2 = analogRead(LDRCENTER2);
    sensorRight = analogRead(LDRRIGHT);

    desRight += sensorRight;
    desLeft += sensorLeft;
    center1 += sensorCenter1;
    center2 += sensorCenter2;
  }

  //media
  desRight /= 10;
  desLeft /= 10;
  center1 /= 10;
  center2 /= 10;


}

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
