// Código de referência em: https://blog.arduinoomega.com/robo-autonomo-basico-com-sensor-ultrassonico-hc-sr04/

// Bibliotecas necessárias
#include <NewPing.h> // https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home#!newping-arduino-library-for-arduino

// Definição dos pinos dos motores
#define MOTOR_A_ENA 3
#define MOTOR_A_IN1 4
#define MOTOR_A_IN2 5
#define MOTOR_B_ENB 9
#define MOTOR_B_IN3 6
#define MOTOR_B_IN4 7

// Definição do pino do sensor infravermelho
#define SENSOR_IR A0

// Definição dos pinos do sensor ultrassônico HC-SR04
#define TRIGGER_PIN 10
#define ECHO_PIN 11

// Configuração dos motores
#define VELOCIDADE_MAXIMA 255
#define VELOCIDADE_GIRO 200

// Configuração do sensor ultrassônico
#define MAX_DISTANCE 300 // Colocar aqui o tamanho em diâmetro da arena, até quantos cm o sensor pode captar
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// Função para mover o robô para frente
void moverParaFrente() {
  analogWrite(MOTOR_A_ENA, VELOCIDADE_MAXIMA);
  digitalWrite(MOTOR_A_IN1, HIGH);
  digitalWrite(MOTOR_A_IN2, LOW);
  analogWrite(MOTOR_B_ENB, VELOCIDADE_MAXIMA);
  digitalWrite(MOTOR_B_IN3, HIGH);
  digitalWrite(MOTOR_B_IN4, LOW);
}

// Função para mover o robô para trás
void moverParaTras() {
  analogWrite(MOTOR_A_ENA, VELOCIDADE_MAXIMA);
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, HIGH);
  analogWrite(MOTOR_B_ENB, VELOCIDADE_MAXIMA);
  digitalWrite(MOTOR_B_IN3, LOW);
  digitalWrite(MOTOR_B_IN4, HIGH);
}

// Função para parar o robô
void parar() {
  analogWrite(MOTOR_A_ENA, 0);
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, LOW);
  analogWrite(MOTOR_B_ENB, 0);
  digitalWrite(MOTOR_B_IN3, LOW);
  digitalWrite(MOTOR_B_IN4, LOW);
}

// Função para girar o robô para a esquerda
void girarEsquerda() {
  analogWrite(MOTOR_A_ENA, VELOCIDADE_GIRO);
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, HIGH);
  analogWrite(MOTOR_B_ENB, VELOCIDADE_GIRO);
  digitalWrite(MOTOR_B_IN3, HIGH);
  digitalWrite(MOTOR_B_IN4, LOW);
}

// Função para girar o robô para a direita
void girarDireita() {
  analogWrite(MOTOR_A_ENA, VELOCIDADE_GIRO);
  digitalWrite(MOTOR_A_IN1, HIGH);
  digitalWrite(MOTOR_A_IN2, LOW);
  analogWrite(MOTOR_B_ENB, VELOCIDADE_GIRO);
  digitalWrite(MOTOR_B_IN3, LOW);
  digitalWrite(MOTOR_B_IN4, HIGH);
}

// Função para mover o robô para frente e virar à esquerda
void moverFrenteEsquerda() {
  moverParaFrente();
  delay(500);
  girarEsquerda();
  delay(500);
  parar();
}

// Função para mover o robô para frente e virar à direita
void moverFrenteDireita() {
  moverParaFrente();
  delay(500);
  girarDireita();
  delay(500);
  parar();
}

// Função para mover o robô para trás e virar à esquerda
void moverTrasEsquerda() {
  moverParaTras();
  delay(500);
  girarEsquerda();
  delay(500);
  parar();
}

// Função para mover o robô para trás e virar à direita
void moverTrasDireita() {
  moverParaTras();
  delay(500);
  girarDireita();
  delay(500);
  parar();
}

void setup() {
  // Configuração dos pinos dos motores como saída
  pinMode(MOTOR_A_ENA, OUTPUT);
  pinMode(MOTOR_A_IN1, OUTPUT);
  pinMode(MOTOR_A_IN2, OUTPUT);
  pinMode(MOTOR_B_ENB, OUTPUT);
  pinMode(MOTOR_B_IN3, OUTPUT);
  pinMode(MOTOR_B_IN4, OUTPUT);

  // Configuração do pino do sensor infravermelho como entrada
  pinMode(SENSOR_IR, INPUT);

  Serial.begin(9600);
}

void loop() {
  // Verifica a distância medida pelo sensor ultrassônico
  unsigned int distanciaFrente = sonar.ping_cm();
  Serial.print("Distancia frente: ");
  Serial.print(distanciaFrente);
  Serial.println(" cm");

  // Verifica se está na borda (superfície branca) usando o sensor infravermelho
  bool naBorda = digitalRead(SENSOR_IR);

  // Lógica de movimentação do robô
  if (distanciaFrente > 10) {  // Se a distância medida à frente for maior que 10 cm
    if (!naBorda) {
      moverParaFrente();
    } else {
      moverParaTras();
      delay(500);
      girarEsquerda();
      delay(1000);
    }
  } else {  // Se houver um obstáculo próximo à frente
    moverParaTras();
    delay(500);
    girarEsquerda();
    delay(1000);
  }

}
