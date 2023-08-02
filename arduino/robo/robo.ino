// Código de referência em: https://blog.arduinoomega.com/robo-autonomo-basico-com-sensor-ultrassonico-hc-sr04/

// Bibliotecas necessárias
#include <NewPing.h> // https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home#!newping-arduino-library-for-arduino

// Definição dos pinos dos motores (PWM) // https://lobodarobotica.com/blog/arduino-nano-pinout/
#define MOTOR_A_IN1 3 // D3
#define MOTOR_A_IN2 9 // D5
#define MOTOR_B_IN3 10 // D6
#define MOTOR_B_IN4 11 // D9

// Definição do pino do sensor infravermelho (Analógico)
// #define SENSOR_IR 19 // A0
#define SENSOR_IR_FRENTE 5
#define SENSOR_IR_TRAS 6

// Definição dos pinos do sensor ultrassônico HC-SR04 (Digitais)
#define TRIGGER_PIN 7 // D7
#define ECHO_PIN 8 // D8

// Velocidades dos motores
#define VELOCIDADE_MAXIMA = 255;
#define VELOCIDADE_GIRO = 200;

// Configuração do sensor ultrassônico
NewPing sonar(TRIGGER_PIN, ECHO_PIN);

// Função para mover o robô para frente
void moverParaFrente(int velocidade) {
  analogWrite(MOTOR_A_IN1, velocidade);
  analogWrite(MOTOR_A_IN2, 0);
  analogWrite(MOTOR_B_IN3, velocidade);
  analogWrite(MOTOR_B_IN4, 0);
}

// Função para mover o robô para trás
void moverParaTras(int velocidade) {
  analogWrite(MOTOR_A_IN1, 0);
  analogWrite(MOTOR_A_IN2, velocidade);
  analogWrite(MOTOR_B_IN3, 0);
  analogWrite(MOTOR_B_IN4, velocidade);
}

// Função para parar o robô
void parar() {
  digitalWrite(MOTOR_A_IN1, 1);
  digitalWrite(MOTOR_A_IN2, 1);
  digitalWrite(MOTOR_B_IN3, 1);
  digitalWrite(MOTOR_B_IN4, 1);
  delay(100);
  digitalWrite(MOTOR_A_IN1, 0);
  digitalWrite(MOTOR_A_IN2, 0);
  digitalWrite(MOTOR_B_IN3, 0);
  digitalWrite(MOTOR_B_IN4, 0);
}

// Função para girar o robô para a esquerda
void girarEsquerda(int velocidade) {
  analogWrite(MOTOR_A_IN1, 0);
  analogWrite(MOTOR_A_IN2, velocidade);
  analogWrite(MOTOR_B_IN3, velocidade);
  analogWrite(MOTOR_B_IN4, 0);
}

// Função para girar o robô para a direita
void girarDireita(int velocidade) {
  analogWrite(MOTOR_A_IN1, velocidade);
  analogWrite(MOTOR_A_IN2, 0);
  analogWrite(MOTOR_B_IN3, 0);
  analogWrite(MOTOR_B_IN4, velocidade);
}

// Função para mover o robô à frente e esquerda (utilizando apenas rotação dos motores)
void moverFrenteEsquerda() {
  analogWrite(MOTOR_A_IN1, 0);
  analogWrite(MOTOR_A_IN2, VELOCIDADE_GIRO);
  analogWrite(MOTOR_B_IN3, VELOCIDADE_MAXIMA);
  analogWrite(MOTOR_B_IN4, 0);
  delay(500);  // Ajuste esse tempo conforme necessário para a curva
  parar();
}

// Função para mover o robô à frente e direita (utilizando apenas rotação dos motores)
void moverFrenteDireita() {
  analogWrite(MOTOR_A_IN1, VELOCIDADE_MAXIMA);
  analogWrite(MOTOR_A_IN2, 0);
  analogWrite(MOTOR_B_IN3, 0);
  analogWrite(MOTOR_B_IN4, VELOCIDADE_GIRO);
  delay(500);  // Ajuste esse tempo conforme necessário para a curva
  parar();
}

// Função para mover o robô para trás e esquerda (utilizando apenas rotação dos motores)
void moverTrasEsquerda() {
  analogWrite(MOTOR_A_IN1, VELOCIDADE_GIRO);
  analogWrite(MOTOR_A_IN2, 0);
  analogWrite(MOTOR_B_IN3, 0);
  analogWrite(MOTOR_B_IN4, VELOCIDADE_MAXIMA);
  delay(500);  // Ajuste esse tempo conforme necessário para a curva
  parar();
}

// Função para mover o robô para trás e direita (utilizando apenas rotação dos motores)
void moverTrasDireita() {
  analogWrite(MOTOR_A_IN1, 0);
  analogWrite(MOTOR_A_IN2, VELOCIDADE_MAXIMA);
  analogWrite(MOTOR_B_IN3, VELOCIDADE_GIRO);
  analogWrite(MOTOR_B_IN4, 0);
  delay(500);  // Ajuste esse tempo conforme necessário para a curva
  parar();
}

void setup() {
  // Configuração dos pinos dos motores e do sensor infravermelho
  pinMode(MOTOR_A_IN1, OUTPUT);
  pinMode(MOTOR_A_IN2, OUTPUT);
  pinMode(MOTOR_B_IN3, OUTPUT);
  pinMode(MOTOR_B_IN4, OUTPUT);
  pinMode(SENSOR_IR_FRENTE, INPUT);
  pinMode(SENSOR_IR_TRAS, INPUT);

  Serial.begin(9600);
}

void loop() {
  // Verifica se está na borda (superfície branca) usando o sensor infravermelho
  bool naBorda = digitalRead(SENSOR_IR);
  // Verifica a distância medida pelo sensor ultrassônico
  unsigned int distanciaFrente = sonar.ping_cm();
  Serial.print("Distancia frente: ");
  Serial.print(distanciaFrente);
  Serial.println(" cm");

  // Implementar lógica abaixo
}

