// Código de referência em: https://blog.arduinoomega.com/robo-autonomo-basico-com-sensor-ultrassonico-hc-sr04/

// Bibliotecas necessárias
#include <NewPing.h> // https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home#!newping-arduino-library-for-arduino

// Definição dos pinos dos motores (PWM) // https://lobodarobotica.com/blog/arduino-nano-pinout/
#define MOTOR_A_IN1 6 // D3
#define MOTOR_A_IN2 8 // D5
#define MOTOR_B_IN3 9 // D6
#define MOTOR_B_IN4 12 // D9

// Definição do pino do sensor infravermelho (Analógico)
#define SENSOR_IR 19 // A0

// Definição dos pinos do sensor ultrassônico HC-SR04 (Digitais)
#define TRIGGER_PIN 10 // D7
#define ECHO_PIN 11 // D8

// Velocidades dos motores
#define VELOCIDADE_MAXIMA = 255;
#define VELOCIDADE_GIRO = 200;

// Configuração do sensor ultrassônico
NewPing sonar(TRIGGER_PIN, ECHO_PIN);

// Função para controlar a velocidade do motor A
void controlarVelocidadeMotorA(int velocidade) {
  analogWrite(MOTOR_A_IN1, 0); // Mantém o pino IN1 sempre em LOW
  analogWrite(MOTOR_A_IN2, velocidade); // Controla a velocidade usando o pino IN2 com PWM
}

// Função para controlar a velocidade do motor B
void controlarVelocidadeMotorB(int velocidade) {
  analogWrite(MOTOR_B_IN3, 0); // Mantém o pino IN3 sempre em LOW
  analogWrite(MOTOR_B_IN4, velocidade); // Controla a velocidade usando o pino IN4 com PWM
}

// Função para mover o robô para frente
void moverParaFrente() {
  controlarVelocidadeMotorA(VELOCIDADE_MAXIMA);
  controlarVelocidadeMotorB(VELOCIDADE_MAXIMA);
  digitalWrite(MOTOR_A_IN1, HIGH);
  digitalWrite(MOTOR_A_IN2, LOW);
  digitalWrite(MOTOR_B_IN3, HIGH);
  digitalWrite(MOTOR_B_IN4, LOW);
}

// Função para mover o robô para trás
void moverParaTras() {
  controlarVelocidadeMotorA(VELOCIDADE_MAXIMA);
  controlarVelocidadeMotorB(VELOCIDADE_MAXIMA);
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, HIGH);
  digitalWrite(MOTOR_B_IN3, LOW);
  digitalWrite(MOTOR_B_IN4, HIGH);
}

// Função para parar o robô
void parar() {
  controlarVelocidadeMotorA(0);
  controlarVelocidadeMotorB(0);
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, LOW);
  digitalWrite(MOTOR_B_IN3, LOW);
  digitalWrite(MOTOR_B_IN4, LOW);
}

// Função para girar o robô para a esquerda
void girarEsquerda() {
  controlarVelocidadeMotorA(VELOCIDADE_GIRO);
  controlarVelocidadeMotorB(VELOCIDADE_GIRO);
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, HIGH);
  digitalWrite(MOTOR_B_IN3, HIGH);
  digitalWrite(MOTOR_B_IN4, LOW);
}

// Função para girar o robô para a direita
void girarDireita() {
  controlarVelocidadeMotorA(VELOCIDADE_GIRO);
  controlarVelocidadeMotorB(VELOCIDADE_GIRO);
  digitalWrite(MOTOR_A_IN1, HIGH);
  digitalWrite(MOTOR_A_IN2, LOW);
  digitalWrite(MOTOR_B_IN3, LOW);
  digitalWrite(MOTOR_B_IN4, HIGH);
}

// Função para mover o robô à frente e esquerda (utilizando apenas rotação dos motores)
void moverFrenteEsquerda() {
  controlarVelocidadeMotorA(VELOCIDADE_GIRO);
  controlarVelocidadeMotorB(VELOCIDADE_MAXIMA);
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, HIGH);
  digitalWrite(MOTOR_B_IN3, HIGH);
  digitalWrite(MOTOR_B_IN4, LOW);
  delay(500);  // Ajuste esse tempo conforme necessário para a curva
  parar();
}

// Função para mover o robô à frente e direita (utilizando apenas rotação dos motores)
void moverFrenteDireita() {
  controlarVelocidadeMotorA(VELOCIDADE_MAXIMA);
  controlarVelocidadeMotorB(VELOCIDADE_GIRO);
  digitalWrite(MOTOR_A_IN1, HIGH);
  digitalWrite(MOTOR_A_IN2, LOW);
  digitalWrite(MOTOR_B_IN3, LOW);
  digitalWrite(MOTOR_B_IN4, HIGH);
  delay(500);  // Ajuste esse tempo conforme necessário para a curva
  parar();
}

// Função para mover o robô para trás e esquerda (utilizando apenas rotação dos motores)
void moverTrasEsquerda() {
  controlarVelocidadeMotorA(VELOCIDADE_GIRO);
  controlarVelocidadeMotorB(VELOCIDADE_MAXIMA);
  digitalWrite(MOTOR_A_IN1, HIGH);
  digitalWrite(MOTOR_A_IN2, LOW);
  digitalWrite(MOTOR_B_IN3, LOW);
  digitalWrite(MOTOR_B_IN4, HIGH);
  delay(500);  // Ajuste esse tempo conforme necessário para a curva
  parar();
}

// Função para mover o robô para trás e direita (utilizando apenas rotação dos motores)
void moverTrasDireita() {
  controlarVelocidadeMotorA(VELOCIDADE_MAXIMA);
  controlarVelocidadeMotorB(VELOCIDADE_GIRO);
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, HIGH);
  digitalWrite(MOTOR_B_IN3, HIGH);
  digitalWrite(MOTOR_B_IN4, LOW);
  delay(500);  // Ajuste esse tempo conforme necessário para a curva
  parar();
}

void setup() {
  // Configuração dos pinos dos motores e do sensor infravermelho
  pinMode(MOTOR_A_IN1, OUTPUT);
  pinMode(MOTOR_A_IN2, OUTPUT);
  pinMode(MOTOR_B_IN3, OUTPUT);
  pinMode(MOTOR_B_IN4, OUTPUT);
  pinMode(SENSOR_IR, INPUT);

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

