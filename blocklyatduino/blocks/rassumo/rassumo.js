'use strict';

goog.provide('Blockly.Blocks.rassumo');

goog.require('Blockly.Blocks');
goog.require('Blockly.Types');



Blockly.Blocks['movefrente'] = {
    init: function () {
        this.appendDummyInput()
            .appendField("moveFrente");
        this.appendValueInput("velMA")
            .setCheck("Number")
            .appendField("velMA");
        this.appendValueInput("velMB")
            .setCheck("Number")
            .appendField("velMB");
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
            .appendField("moveTras");
        this.appendValueInput("velMA")
            .setCheck("Number")
            .appendField("velMA");
        this.appendValueInput("velMB")
            .setCheck("Number")
            .appendField("velMB");
        this.setInputsInline(true);
        this.setPreviousStatement(true);
        this.setNextStatement(true);
        this.setColour("#fc6203");
        this.setTooltip('Move o robô para trás');
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

