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
#define MOTOR_A_IN1 6\n\
#define MOTOR_A_IN2 9\n\
#define MOTOR_B_IN1 3\n\
#define MOTOR_B_IN2 5\n\
#define MAX_SPEED 255\n\
#define HALF_SPEED 170\n\
#define CUSTOM_SPEED 150\n"

irDefinitions = "#define IR_TPIN 10\n\
#define IR_FPIN 4\n"

sonarDefinitions = "#define TRIGGER_PIN 12   // Arduino pin tied to trigger pin on the ultrasonic sensor.\n\
#define ECHO_PIN 11      // Arduino pin tied to echo pin on the ultrasonic sensor.\n\
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.\n"

moveFrenteDefinition = "void moveFrente(int a, int b)\n" +
    "{\n" +
    "   analogWrite(MOTOR_A_IN1, a);\n" +
    "   analogWrite(MOTOR_A_IN2, 0);\n" +
    "   analogWrite(MOTOR_B_IN1, b);\n" +
    "   analogWrite(MOTOR_B_IN2, 0);\n" +
    "}"

moveTrasDefinition = "void moveTras(int a, int b)\n" +
    "{\n" +
    "   analogWrite(MOTOR_A_IN2, a);\n" +
    "   analogWrite(MOTOR_A_IN1, 0);\n" +
    "   analogWrite(MOTOR_B_IN2, b);\n" +
    "   analogWrite(MOTOR_B_IN1, 0);\n" +
    "}"

Blockly.Arduino['movefrente'] = function (block) {
    var value_velma = Blockly.Arduino.valueToCode(block, 'velMA', Blockly.Arduino.ORDER_ATOMIC);
    var value_velmb = Blockly.Arduino.valueToCode(block, 'velMB', Blockly.Arduino.ORDER_ATOMIC);
    Blockly.Arduino.definitions_["define_motor_configs"] = motorDefinitions;
    Blockly.Arduino.definitions_["define_movefrente"] = moveFrenteDefinition;
    var code = "moveFrente(" + value_velma + "," + value_velmb + ");\n"
    return code;
};

Blockly.Arduino['movetras'] = function (block) {
    var value_velma = Blockly.Arduino.valueToCode(block, 'velMA', Blockly.Arduino.ORDER_ATOMIC);
    var value_velmb = Blockly.Arduino.valueToCode(block, 'velMB', Blockly.Arduino.ORDER_ATOMIC);
    Blockly.Arduino.definitions_["define_motor_configs"] = motorDefinitions;
    Blockly.Arduino.definitions_["define_movetras"] = moveTrasDefinition;
    var code = "moveTras(" + value_velma + "," + value_velmb + ");\n"
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
    var code = "parar();\n"
    return code;
};

