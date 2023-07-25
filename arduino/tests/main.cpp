#include <Arduino.h>

#include <NewPing.h>

#define IR_TPIN 6
#define IR_FPIN 5
#define IR_APIN A1

// Definição dos pinos dos motores
#define MOTOR_A_IN1 11
#define MOTOR_A_IN2 10
#define MOTOR_B_IN1 9
#define MOTOR_B_IN2 3
#define MAX_SPEED 255
#define HALF_SPEED 170
#define CUSTOM_SPEED 120

#define TRIGGER_PIN 7    // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN 8       // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
int sensor[] = {0, 0, 0};
enum SENSOR_MAP
{
  IRFRONT,
  IRBACK,
  USOUND
};

enum MOVE_STATE
{
  STOP,
  FRONT,
  BACK
};

MOVE_STATE movement = STOP;

// put function declarations here:
void frente(int, int);
void tras(int, int);
void parar();

void setup()
{
  // put your setup code here, to run once:
  pinMode(IR_TPIN, INPUT);
  pinMode(IR_FPIN, INPUT);
  pinMode(IR_APIN, INPUT);
  Serial.begin(115200);
}

void loop()
{
  // put your main code here, to run repeatedly:
  sensor[IRFRONT] = digitalRead(IR_FPIN);
  sensor[IRBACK] = digitalRead(IR_TPIN);
  sensor[USOUND] = sonar.ping_cm();

  Serial.print("IR_F: ");
  Serial.print(sensor[IRFRONT]);
  Serial.print(" IR_B: ");
  Serial.print(sensor[IRBACK]);
  Serial.print(" USND: ");
  Serial.print(sensor[USOUND]);
  Serial.print("\n");
  delay(10);
  frente(CUSTOM_SPEED, 0);
  delay(5000);
  frente(HALF_SPEED, 0);
  delay(5000);
  frente(MAX_SPEED, 0);
  delay(5000);
  // if ((!sensor[IRFRONT]) && (!sensor[IRBACK]))
  // {
  //   if (movement == STOP)
  //   {
  //     movement = FRONT;
  //     frente(CUSTOM_SPEED, CUSTOM_SPEED);
  //     Serial.print("frente\n");
  //   }
  // }
  // else
  // {
  //   if (movement == FRONT)
  //   {
  //     movement = STOP;
  //     Serial.print("stop\n");
  //     parar();
  //   }
  // }
}

// put function definitions here:
void frente(int a, int b)
{
  analogWrite(MOTOR_A_IN1, a);
  analogWrite(MOTOR_A_IN2, 0);
  analogWrite(MOTOR_B_IN1, b);
  analogWrite(MOTOR_B_IN2, 0);
}

void tras(int a, int b)
{
  analogWrite(MOTOR_A_IN2, a);
  analogWrite(MOTOR_A_IN1, 0);
  analogWrite(MOTOR_B_IN2, b);
  analogWrite(MOTOR_B_IN1, 0);
}

void parar()
{
  analogWrite(MOTOR_A_IN2, 0);
  analogWrite(MOTOR_A_IN1, 0);
  analogWrite(MOTOR_B_IN2, 0);
  analogWrite(MOTOR_B_IN1, 0);
}