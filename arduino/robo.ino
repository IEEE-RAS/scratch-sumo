// Bibliotecas necessárias
#include <AFMotor.h>
#include <NewPing.h>

// Definição dos pinos dos motores
#define MOTOR_ESQUERDA 2
#define MOTOR_DIREITA 4

// Definição do pino do sensor infravermelho
#define SENSOR_IR A0

// Definição dos pinos do sensor ultrassônico
#define TRIGGER_PIN 12
#define ECHO_PIN 13

// Configuração dos motores
AF_DCMotor motorEsquerda(MOTOR_ESQUERDA);
AF_DCMotor motorDireita(MOTOR_DIREITA);

// Configuração do sensor ultrassônico
NewPing sonar(TRIGGER_PIN, ECHO_PIN);

// Função para mover o robô para frente
void moverFrente() {
  motorEsquerda.setSpeed(255);
  motorDireita.setSpeed(255);
  motorEsquerda.run(FORWARD);
  motorDireita.run(FORWARD);
}

// Função para mover o robô para trás
void moverTras() {
  motorEsquerda.setSpeed(255);
  motorDireita.setSpeed(255);
  motorEsquerda.run(BACKWARD);
  motorDireita.run(BACKWARD);
}

// Função para parar o robô
void parar() {
  motorEsquerda.run(RELEASE);
  motorDireita.run(RELEASE);
}

// Função para girar o robô para a esquerda
void girarEsquerda() {
  motorEsquerda.setSpeed(255);
  motorDireita.setSpeed(255);
  motorEsquerda.run(BACKWARD);
  motorDireita.run(FORWARD);
}

// Função para girar o robô para a direita
void girarDireita() {
  motorEsquerda.setSpeed(255);
  motorDireita.setSpeed(255);
  motorEsquerda.run(FORWARD);
  motorDireita.run(BACKWARD);
}

void setup() {
  // Inicialização dos motores
  motorEsquerda.setSpeed(255);
  motorDireita.setSpeed(255);

  // Configuração dos pinos dos motores como saída
  pinMode(MOTOR_ESQUERDA, OUTPUT);
  pinMode(MOTOR_DIREITA, OUTPUT);

  // Configuração do pino do sensor infravermelho
  pinMode(SENSOR_IR, INPUT);

  Serial.begin(9600);
}

void loop() {
  // Verifica a distância medida pelo sensor ultrassônico
  unsigned int distanciaFrente = sonar.ping_cm();
  Serial.print("Distancia frente: ");
  Serial.print(distanciaFrente);
  Serial.println(" cm");

  // Verifica se há obstáculo no sensor infravermelho
  bool obstaculoAtras = digitalRead(SENSOR_IR);

  // Lógica de funcionamento

}