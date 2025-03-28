{/* <block type="movefrente"></block>
		<block type="movetras"></block>
		<block type="movefreesq"></block>
		<block type="movefredir"></block>
		<block type="movetraesq"></block>
		<block type="movetradir"></block> */}
'use strict';

goog.provide('Blockly.Arduino.rassumo');

goog.require('Blockly.Arduino');


motorDefinitions = "// Definição dos pinos dos motores\n\
#define MOTOR_A_IN1 11\n\
#define MOTOR_A_IN2 10\n\
#define MOTOR_B_IN1 9\n\
#define MOTOR_B_IN2 3\n\
#define MAX_SPEED 255\n\
#define HALF_SPEED 170\n\
#define CUSTOM_SPEED 150\n"

irDefinitions = "// Definição do pino do sensor infravermelho (Analógico)\n\
// #define SENSOR_IR 19 // A0\n\
#define SENSOR_IR_FRENTE 5\n\
#define SENSOR_IR_TRAS 6\n"

irSetups = "pinMode(SENSOR_IR_FRENTE, INPUT);\n\
  pinMode(SENSOR_IR_TRAS, INPUT);\n"

sonarDefinitions = "#define TRIGGER_PIN 7   // Arduino pin tied to trigger pin on the ultrasonic sensor.\n\
#define ECHO_PIN 8      // Arduino pin tied to echo pin on the ultrasonic sensor.\n\
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.\n\n\
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.\n"

moveFrenteDefinition = "// Função para mover o robô para frente\n" +
    "void moveFrente(int a, int b)\n" +
    "{\n" +
    "   analogWrite(MOTOR_A_IN1, a);\n" +
    "   analogWrite(MOTOR_A_IN2, 0);\n" +
    "   analogWrite(MOTOR_B_IN1, b);\n" +
    "   analogWrite(MOTOR_B_IN2, 0);\n" +
    "}"

moveTrasDefinition = "// Função para mover o robô para tras\n" +
    "void moveTras(int a, int b)\n" +
    "{\n" +
    "   analogWrite(MOTOR_A_IN2, a);\n" +
    "   analogWrite(MOTOR_A_IN1, 0);\n" +
    "   analogWrite(MOTOR_B_IN2, b);\n" +
    "   analogWrite(MOTOR_B_IN1, 0);\n" +
    "}"

gigarEsquerdaDefinition = "// Função para girar o robô para a esquerda\n" +
    "void girarEsquerda(int velocidade) {\n" +
    "  analogWrite(MOTOR_A_IN1, 0);\n" +
    "  analogWrite(MOTOR_A_IN2, velocidade);\n" +
    "  analogWrite(MOTOR_B_IN1, velocidade);\n" +
    "  analogWrite(MOTOR_B_IN2, 0);\n" +
    "}"

gigarDireitaDefinition = "// Função para girar o robô para a direita\n" +
    "void girarDireita(int velocidade) {\n" +
    "  analogWrite(MOTOR_A_IN1, velocidade);\n" +
    "  analogWrite(MOTOR_A_IN2, 0);\n" +
    "  analogWrite(MOTOR_B_IN1, 0);\n" +
    "  analogWrite(MOTOR_B_IN2, velocidade);\n" +
    "}"



Blockly.Arduino['movefrente'] = function (block) {
    var value_vel = Blockly.Arduino.valueToCode(block, 'vel', Blockly.Arduino.ORDER_ATOMIC);
    Blockly.Arduino.definitions_["define_motor_configs"] = motorDefinitions;
    Blockly.Arduino.definitions_["define_movefrente"] = moveFrenteDefinition;
    var code = "moveFrente(" + value_vel + "," + value_vel + ");\n"
    return code;
};

Blockly.Arduino['movetras'] = function (block) {
    var value_vel = Blockly.Arduino.valueToCode(block, 'vel', Blockly.Arduino.ORDER_ATOMIC);
    Blockly.Arduino.definitions_["define_motor_configs"] = motorDefinitions;
    Blockly.Arduino.definitions_["define_movetras"] = moveTrasDefinition;
    var code = "moveTras(" + value_vel + "," + value_vel + ");\n"
    return code;
};

Blockly.Arduino['giraresquerda'] = function (block) {
    var value_vel = Blockly.Arduino.valueToCode(block, 'vel', Blockly.Arduino.ORDER_ATOMIC);
    Blockly.Arduino.definitions_["define_motor_configs"] = motorDefinitions;
    Blockly.Arduino.definitions_["define_giraresquerda"] = gigarEsquerdaDefinition;
    var code = "girarEsquerda(" + value_vel + ");\n"
    return code;
};

Blockly.Arduino['girardireita'] = function (block) {
    var value_vel = Blockly.Arduino.valueToCode(block, 'vel', Blockly.Arduino.ORDER_ATOMIC);
    Blockly.Arduino.definitions_["define_motor_configs"] = motorDefinitions;
    Blockly.Arduino.definitions_["define_girardireita"] = gigarDireitaDefinition;
    var code = "girarDireita(" + value_vel + ");\n"
    return code;
};

Blockly.Arduino['movefrentedireita'] = function (block) {
    var value_vel = Blockly.Arduino.valueToCode(block, 'vel', Blockly.Arduino.ORDER_ATOMIC);
    Blockly.Arduino.definitions_["define_motor_configs"] = motorDefinitions;
    Blockly.Arduino.definitions_["define_movefrente"] = moveFrenteDefinition;
    var code = "moveFrente(" + value_vel + "," + value_vel + " / 3);\n"
    return code;
};

Blockly.Arduino['movefrenteesquerda'] = function (block) {
    var value_vel = Blockly.Arduino.valueToCode(block, 'vel', Blockly.Arduino.ORDER_ATOMIC);
    Blockly.Arduino.definitions_["define_motor_configs"] = motorDefinitions;
    Blockly.Arduino.definitions_["define_movefrente"] = moveFrenteDefinition;
    var code = "moveFrente(" + value_vel + " / 3," + value_vel + ");\n"
    return code;
};

Blockly.Arduino['movetrasesquerda'] = function (block) {
    var value_vel = Blockly.Arduino.valueToCode(block, 'vel', Blockly.Arduino.ORDER_ATOMIC);
    Blockly.Arduino.definitions_["define_motor_configs"] = motorDefinitions;
    Blockly.Arduino.definitions_["define_movetras"] = moveTrasDefinition;
    var code = "moveFrente(" + value_vel + " / 3," + value_vel + ");\n"
    return code;
};

Blockly.Arduino['movetrasdireita'] = function (block) {
    var value_vel = Blockly.Arduino.valueToCode(block, 'vel', Blockly.Arduino.ORDER_ATOMIC);
    Blockly.Arduino.definitions_["define_motor_configs"] = motorDefinitions;
    Blockly.Arduino.definitions_["define_movetras"] = moveTrasDefinition;
    var code = "moveFrente(" + value_vel + "," + value_vel + " / 3);\n";
    return code;
};



Blockly.Arduino['parar'] = function (block) {
    Blockly.Arduino.definitions_["define_motor_configs"] = motorDefinitions;
    Blockly.Arduino.definitions_["define_parar"] = "void parar()\n" +
        "{\n" +
        "   analogWrite(MOTOR_A_IN2, 0);\n" +
        "   analogWrite(MOTOR_A_IN1, 0);\n" +
        "   analogWrite(MOTOR_B_IN2, 0);\n" +
        "   analogWrite(MOTOR_B_IN1, 0);\n" +
        "}"
    var code = "parar();\n";
    return code;
};


Blockly.Arduino['lesonar'] = function (block) {
    Blockly.Arduino.includes_["includes_sonar"] = "#include <NewPing.h>\n";
    Blockly.Arduino.definitions_["define_sonar"] = sonarDefinitions;
    var code = "sonar.ping_cm()";
    return [code, Blockly.Arduino.ORDER_ATOMIC];
};

Blockly.Arduino['leirfrente'] = function (block) {
    Blockly.Arduino.definitions_["define_ir"] = irDefinitions;
    Blockly.Arduino.setups_["setups_ir"] = irSetups;
    var code = "digitalRead(SENSOR_IR_FRENTE)";
    return [code, Blockly.Arduino.ORDER_ATOMIC];
};

Blockly.Arduino['leirtras'] = function (block) {
    Blockly.Arduino.definitions_["define_ir"] = irDefinitions;
    Blockly.Arduino.setups_["setups_ir"] = irSetups;
    var code = "digitalRead(SENSOR_IR_TRAS)";
    return [code, Blockly.Arduino.ORDER_ATOMIC];
};


