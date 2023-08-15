'use strict';

goog.provide('Blockly.Blocks.rassumo');

goog.require('Blockly.Blocks');
goog.require('Blockly.Types');



Blockly.Blocks['movefrente'] = {
    init: function () {
        this.appendDummyInput()
            .appendField("moveParaFrente");
        this.appendValueInput("vel")
            .setCheck("Number")
            .appendField("Velocidade");
        this.setInputsInline(true);
        this.setPreviousStatement(true);
        this.setNextStatement(true);
        this.setColour("#fc6203");
        this.setTooltip('Move o robô para frente');
        this.setHelpUrl('https://www.arduino.cc/reference/en/');
    }
};



Blockly.Blocks['movetras'] = {
    init: function () {
        this.appendDummyInput()
            .appendField("moveParaTras");
        this.appendValueInput("vel")
            .setCheck("Number")
            .appendField("Velcidade");
        this.setInputsInline(true);
        this.setPreviousStatement(true);
        this.setNextStatement(true);
        this.setColour("#fc6203");
        this.setTooltip('Move o robô para trás');
        this.setHelpUrl('https://www.arduino.cc/reference/en/');
    }
};


Blockly.Blocks['giraresquerda'] = {
    init: function () {
        this.appendDummyInput()
            .appendField("girarParaEsquerda");
        this.appendValueInput("vel")
            .setCheck("Number")
            .appendField("Velcidade");
        this.setInputsInline(true);
        this.setPreviousStatement(true);
        this.setNextStatement(true);
        this.setColour("#fc6203");
        this.setTooltip('Gira o robô em seu eixo principal para a esquerda');
        this.setHelpUrl('https://www.arduino.cc/reference/en/');
    }
};

Blockly.Blocks['girardireita'] = {
    init: function () {
        this.appendDummyInput()
            .appendField("girarParaDireita");
        this.appendValueInput("vel")
            .setCheck("Number")
            .appendField("Velcidade");
        this.setInputsInline(true);
        this.setPreviousStatement(true);
        this.setNextStatement(true);
        this.setColour("#fc6203");
        this.setTooltip('Gira o robô em seu eixo principal para a direita');
        this.setHelpUrl('https://www.arduino.cc/reference/en/');
    }
};

Blockly.Blocks['movefrentedireita'] = {
    init: function () {
        this.appendDummyInput()
            .appendField("moveFrenteDireita");
        this.appendValueInput("vel")
            .setCheck("Number")
            .appendField("Velocidade");
        this.setInputsInline(true);
        this.setPreviousStatement(true);
        this.setNextStatement(true);
        this.setColour("#fc6203");
        this.setTooltip('Faz curva à frente e a direita');
        this.setHelpUrl('https://www.arduino.cc/reference/en/');
    }
};


Blockly.Blocks['movefrenteesquerda'] = {
    init: function () {
        this.appendDummyInput()
            .appendField("moveFrenteEsquerda");
        this.appendValueInput("vel")
            .setCheck("Number")
            .appendField("Velocidade");
        this.setInputsInline(true);
        this.setPreviousStatement(true);
        this.setNextStatement(true);
        this.setColour("#fc6203");
        this.setTooltip('Faz curva à frente e a esquerda');
        this.setHelpUrl('https://www.arduino.cc/reference/en/');
    }
};


Blockly.Blocks['movetrasesquerda'] = {
    init: function () {
        this.appendDummyInput()
            .appendField("moveTrasEsquerda");
        this.appendValueInput("vel")
            .setCheck("Number")
            .appendField("Velocidade");
        this.setInputsInline(true);
        this.setPreviousStatement(true);
        this.setNextStatement(true);
        this.setColour("#fc6203");
        this.setTooltip('Faz curva para tras e a esquerda');
        this.setHelpUrl('https://www.arduino.cc/reference/en/');
    }
};

Blockly.Blocks['movetrasdireita'] = {
    init: function () {
        this.appendDummyInput()
            .appendField("moveTrasDireita");
        this.appendValueInput("vel")
            .setCheck("Number")
            .appendField("Velocidade");
        this.setInputsInline(true);
        this.setPreviousStatement(true);
        this.setNextStatement(true);
        this.setColour("#fc6203");
        this.setTooltip('Faz curva para tras e a esquerda');
        this.setHelpUrl('https://www.arduino.cc/reference/en/');
    }
};

Blockly.Blocks['parar'] = {
    init: function () {
        this.appendDummyInput()
            .appendField("Parar");
        this.setInputsInline(true);
        this.setPreviousStatement(true);
        this.setNextStatement(true);
        this.setColour("#fc6203");
        this.setTooltip('Para o movimento do robô');
        this.setHelpUrl('https://www.arduino.cc/reference/en/');
    }
};


Blockly.Blocks['lesonar'] = {
    init: function () {
        this.appendDummyInput()
            .appendField("Lê Sonar");
        this.setInputsInline(false);
        this.setOutput(true);
        this.setColour("#8132a8");
        this.setTooltip('Lê valor do sonar');
        this.setHelpUrl('https://www.arduino.cc/reference/en/');
    }
};

Blockly.Blocks['leirfrente'] = {
    init: function () {
        this.appendDummyInput()
            .appendField("Lê Borda Frontal");
        this.setInputsInline(false);
        this.setOutput(true);
        this.setColour("#8132a8");
        this.setTooltip('Lê valor do sensor de IR frontal para detectar borda');
        this.setHelpUrl('https://www.arduino.cc/reference/en/');
    }
};

Blockly.Blocks['leirtras'] = {
    init: function () {
        this.appendDummyInput()
            .appendField("Lê Borda Traseira");
        this.setInputsInline(false);
        this.setOutput(true);
        this.setColour("#8132a8");
        this.setTooltip('Lê valor do sensor de IR traseiro para detectar borda');
        this.setHelpUrl('https://www.arduino.cc/reference/en/');
    }
};

