Facilino.LANG_COLOUR_MOVEMENT = '#CECE42';
Facilino.LANG_COLOUR_MOVEMENT_WALK = '#8D8D25';

Blockly.Blocks['HIPPIE_init'] = {
				category: Facilino.locales.getKey('LANG_CATEGORY_MOVEMENT'),
				subcategory: Facilino.locales.getKey('LANG_SUBCATEGORY_WALK'),
				category_colour: Facilino.LANG_COLOUR_MOVEMENT,
				colour: Facilino.LANG_COLOUR_MOVEMENT_WALK,
				helpUrl: Facilino.getHelpUrl('HIPPIE_init'),
				tags: [],
				examples: [],
				init: function () {
					this.appendDummyInput('').appendField(new Blockly.FieldImage('img/blocks/hippie.svg', 32*options.zoom, 32*options.zoom)).appendField(Facilino.locales.getKey('LANG_MOVEMENT_HIPPIE_ROBOT'));
					this.appendValueInput('YR').appendField(new Blockly.FieldImage('img/blocks/hippie_YR.svg', 24*options.zoom, 24*options.zoom)).appendField(Facilino.locales.getKey('LANG_MOVEMENT_HIPPIE_YR')).appendField(new Blockly.FieldImage('img/blocks/pwm_signal.svg', 24*options.zoom, 24*options.zoom)).setAlign(Blockly.ALIGN_RIGHT);
					this.appendValueInput('YL').appendField(new Blockly.FieldImage('img/blocks/hippie_YL.svg', 24*options.zoom, 24*options.zoom)).appendField(Facilino.locales.getKey('LANG_MOVEMENT_HIPPIE_YL')).appendField(new Blockly.FieldImage('img/blocks/pwm_signal.svg', 24*options.zoom, 24*options.zoom)).setAlign(Blockly.ALIGN_RIGHT);
					this.appendValueInput('RR').appendField(new Blockly.FieldImage('img/blocks/hippie_RR.svg', 24*options.zoom, 24*options.zoom)).appendField(Facilino.locales.getKey('LANG_MOVEMENT_HIPPIE_RR')).appendField(new Blockly.FieldImage('img/blocks/pwm_signal.svg', 24*options.zoom, 24*options.zoom)).setAlign(Blockly.ALIGN_RIGHT);
					this.appendValueInput('RL').appendField(new Blockly.FieldImage('img/blocks/hippie_RL.svg', 24*options.zoom, 24*options.zoom)).appendField(Facilino.locales.getKey('LANG_MOVEMENT_HIPPIE_RL')).appendField(new Blockly.FieldImage('img/blocks/pwm_signal.svg', 24*options.zoom, 24*options.zoom)).setAlign(Blockly.ALIGN_RIGHT);
					this.appendDummyInput('').appendField(Facilino.locales.getKey('LANG_MOVEMENT_HIPPIE_OFFSET'));
					this.appendDummyInput('').appendField(Facilino.locales.getKey('LANG_MOVEMENT_HIPPIE_YR')).appendField('+/-').appendField(new Blockly.FieldTextInput('0'), 'OYR').setAlign(Blockly.ALIGN_RIGHT);
					this.appendDummyInput('').appendField(Facilino.locales.getKey('LANG_MOVEMENT_HIPPIE_YL')).appendField('+/-').appendField(new Blockly.FieldTextInput('0'), 'OYL').setAlign(Blockly.ALIGN_RIGHT);
					this.appendDummyInput('').appendField(Facilino.locales.getKey('LANG_MOVEMENT_HIPPIE_RR')).appendField('+/-').appendField(new Blockly.FieldTextInput('0'), 'ORR').setAlign(Blockly.ALIGN_RIGHT);
					this.appendDummyInput('').appendField(Facilino.locales.getKey('LANG_MOVEMENT_HIPPIE_RL')).appendField('+/-').appendField(new Blockly.FieldTextInput('0'), 'ORL').setAlign(Blockly.ALIGN_RIGHT);
					this.setPreviousStatement(true,'code');
					this.setNextStatement(true,'code');
					this.setInputsInline(false);
					this.setColour(Facilino.LANG_COLOUR_MOVEMENT_WALK);
					this.setTooltip(Facilino.locales.getKey('LANG_HIPPIE_INIT_TOOLTIP'));
				}
			};
			
			Blockly.Arduino['HIPPIE_init'] = function(block) {
				var code='';
				var input_YR = Blockly.Arduino.valueToCode(this,'YR',Blockly.Arduino.ORDER_ATOMIC) || '26';
				var input_YL = Blockly.Arduino.valueToCode(this,'YL',Blockly.Arduino.ORDER_ATOMIC) || '25';
				var input_RR = Blockly.Arduino.valueToCode(this,'RR',Blockly.Arduino.ORDER_ATOMIC) || '17';
				var input_RL = Blockly.Arduino.valueToCode(this,'RL',Blockly.Arduino.ORDER_ATOMIC) || '16';
				var input_OYR = Blockly.Arduino.valueToCode(this,'OYR',Blockly.Arduino.ORDER_ATOMIC) || '0';
				var input_OYL = Blockly.Arduino.valueToCode(this,'OYL',Blockly.Arduino.ORDER_ATOMIC) || '0';
				var input_ORR = Blockly.Arduino.valueToCode(this,'ORR',Blockly.Arduino.ORDER_ATOMIC) || '0';
				var input_ORL = Blockly.Arduino.valueToCode(this,'ORL',Blockly.Arduino.ORDER_ATOMIC) || '0';
				Blockly.Arduino.definitions_['define_hippie_h'] = '#include <Hippie.h>';
				Blockly.Arduino.definitions_['declare_var_define_hippie']='Hippie hippie;\n';
				Blockly.Arduino.setups_['setup_hippie_init'] = 'hippie.init_with_trim('+input_YR+','+input_YL+','+input_RR+','+input_RL+','+input_OYR+','+input_OYL+','+input_ORR+','+input_ORL+');\n';
				return code;
			};
			
			Blockly.Arduino['HIPPIE_init'] = function(block) {
				var code='';
				var input_YR = Blockly.Arduino.valueToCode(this,'YR',Blockly.Arduino.ORDER_ATOMIC) || '26';
				var input_YL = Blockly.Arduino.valueToCode(this,'YL',Blockly.Arduino.ORDER_ATOMIC) || '25';
				var input_RR = Blockly.Arduino.valueToCode(this,'RR',Blockly.Arduino.ORDER_ATOMIC) || '17';
				var input_RL = Blockly.Arduino.valueToCode(this,'RL',Blockly.Arduino.ORDER_ATOMIC) || '16';
				var input_OYR = Blockly.Arduino.valueToCode(this,'OYR',Blockly.Arduino.ORDER_ATOMIC) || '0';
				var input_OYL = Blockly.Arduino.valueToCode(this,'OYL',Blockly.Arduino.ORDER_ATOMIC) || '0';
				var input_ORR = Blockly.Arduino.valueToCode(this,'ORR',Blockly.Arduino.ORDER_ATOMIC) || '0';
				var input_ORL = Blockly.Arduino.valueToCode(this,'ORL',Blockly.Arduino.ORDER_ATOMIC) || '0';
				Blockly.Arduino.definitions_['define_hippie_h'] = '#include <Hippie.h>';
				Blockly.Arduino.definitions_['declare_var_define_hippie']='Hippie hippie;\n';
				Blockly.Arduino.setups_['setup_hippie_init'] = 'hippie.init_with_trim('+input_YR+','+input_YL+','+input_RR+','+input_RL+','+input_OYR+','+input_OYL+','+input_ORR+','+input_ORL+');\n';
				return code;
			};
			
			Blockly.Arduino['HIPPIE_movement'] = function() {
				var code='';
				var movement = this.getFieldValue('MOVEMENT');
				if (movement==='0')
					code+='hippie.home();\n';
				else if (movement==='1')
					code+='hippie.jump('+(Blockly.Arduino.valueToCode(this, 'INP1', Blockly.Arduino.ORDER_ATOMIC) || '1')+','+(Blockly.Arduino.valueToCode(this, 'INP2', Blockly.Arduino.ORDER_ATOMIC) || '600')+');\n';
				else if (movement==='2')
					code+='hippie.new_walk('+(Blockly.Arduino.valueToCode(this, 'INP1', Blockly.Arduino.ORDER_ATOMIC) || '4')+','+(Blockly.Arduino.valueToCode(this, 'INP2', Blockly.Arduino.ORDER_ATOMIC) || '1000')+','+this.getFieldValue('FIELD3')+');\n';
				else if (movement==='3')
					code+='hippie.new_turn('+(Blockly.Arduino.valueToCode(this, 'INP1', Blockly.Arduino.ORDER_ATOMIC) || '4')+','+(Blockly.Arduino.valueToCode(this, 'INP2', Blockly.Arduino.ORDER_ATOMIC) || '1000')+','+this.getFieldValue('FIELD3')+');\n';
				else if (movement==='4')
					code+='hippie.bend('+(Blockly.Arduino.valueToCode(this, 'INP1', Blockly.Arduino.ORDER_ATOMIC) || '1')+','+(Blockly.Arduino.valueToCode(this, 'INP2', Blockly.Arduino.ORDER_ATOMIC) || '1400')+','+this.getFieldValue('FIELD3')+');\n';
				else if (movement==='5')
					code+='hippie.shakeLeg('+(Blockly.Arduino.valueToCode(this, 'INP1', Blockly.Arduino.ORDER_ATOMIC) || '1')+','+(Blockly.Arduino.valueToCode(this, 'INP2', Blockly.Arduino.ORDER_ATOMIC) || '2000')+','+this.getFieldValue('FIELD3')+');\n';
				else if (movement==='6')
					code+='hippie.updown('+(Blockly.Arduino.valueToCode(this, 'INP1', Blockly.Arduino.ORDER_ATOMIC) || '1')+','+(Blockly.Arduino.valueToCode(this, 'INP2', Blockly.Arduino.ORDER_ATOMIC) || '1000')+','+(Blockly.Arduino.valueToCode(this, 'INP3', Blockly.Arduino.ORDER_ATOMIC) || '40')+');\n';
				else if (movement==='7')
					code+='hippie.swing('+(Blockly.Arduino.valueToCode(this, 'INP1', Blockly.Arduino.ORDER_ATOMIC) || '1')+','+(Blockly.Arduino.valueToCode(this, 'INP2', Blockly.Arduino.ORDER_ATOMIC) || '1000')+','+(Blockly.Arduino.valueToCode(this, 'INP3', Blockly.Arduino.ORDER_ATOMIC) || '40')+');\n';
				else if (movement==='8')
					code+='hippie.tiptoeSwing('+(Blockly.Arduino.valueToCode(this, 'INP1', Blockly.Arduino.ORDER_ATOMIC) || '1')+','+(Blockly.Arduino.valueToCode(this, 'INP2', Blockly.Arduino.ORDER_ATOMIC) || '900')+','+(Blockly.Arduino.valueToCode(this, 'INP3', Blockly.Arduino.ORDER_ATOMIC) || '40')+');\n';
				else if (movement==='9')
					code+='hippie.jitter('+(Blockly.Arduino.valueToCode(this, 'INP1', Blockly.Arduino.ORDER_ATOMIC) || '1')+','+(Blockly.Arduino.valueToCode(this, 'INP2', Blockly.Arduino.ORDER_ATOMIC) || '500')+','+(Blockly.Arduino.valueToCode(this, 'INP3', Blockly.Arduino.ORDER_ATOMIC) || '50')+');\n';
				else if (movement==='10')
					code+='hippie.ascendingTurn('+(Blockly.Arduino.valueToCode(this, 'INP1', Blockly.Arduino.ORDER_ATOMIC) || '1')+','+(Blockly.Arduino.valueToCode(this, 'INP2', Blockly.Arduino.ORDER_ATOMIC) || '900')+','+(Blockly.Arduino.valueToCode(this, 'INP3', Blockly.Arduino.ORDER_ATOMIC) || '50')+');\n';
				else if (movement==='11')
					code+='hippie.moonwalker('+(Blockly.Arduino.valueToCode(this, 'INP1', Blockly.Arduino.ORDER_ATOMIC) || '1')+','+(Blockly.Arduino.valueToCode(this, 'INP2', Blockly.Arduino.ORDER_ATOMIC) || '900')+','+(Blockly.Arduino.valueToCode(this, 'INP4', Blockly.Arduino.ORDER_ATOMIC) || '50')+','+this.getFieldValue('FIELD3')+');\n';
				else if (movement==='12')
					code+='hippie.crusaito('+(Blockly.Arduino.valueToCode(this, 'INP1', Blockly.Arduino.ORDER_ATOMIC) || '1')+','+(Blockly.Arduino.valueToCode(this, 'INP2', Blockly.Arduino.ORDER_ATOMIC) || '900')+','+(Blockly.Arduino.valueToCode(this, 'INP4', Blockly.Arduino.ORDER_ATOMIC) || '20')+','+this.getFieldValue('FIELD3')+');\n';
				else if (movement==='13')
					code+='hippie.flapping('+(Blockly.Arduino.valueToCode(this, 'INP1', Blockly.Arduino.ORDER_ATOMIC) || '1')+','+(Blockly.Arduino.valueToCode(this, 'INP2', Blockly.Arduino.ORDER_ATOMIC) || '1000')+','+(Blockly.Arduino.valueToCode(this, 'INP4', Blockly.Arduino.ORDER_ATOMIC) || '50')+','+this.getFieldValue('FIELD3')+');\n';
				return code;
			}

			Blockly.Blocks['HIPPIE_movement'] = {
				category: Facilino.locales.getKey('LANG_CATEGORY_MOVEMENT'),
				subcategory: Facilino.locales.getKey('LANG_SUBCATEGORY_WALK'),
				tags: [],
				helpUrl: Facilino.getHelpUrl('LARS_movement'),
				examples: [],
				category_colour: Facilino.LANG_COLOUR_MOVEMENT,
				colour: Facilino.LANG_COLOUR_MOVEMENT_WALK,
				init: function() {
					this.setColour(Facilino.LANG_COLOUR_MOVEMENT_WALK);
					var movement = new Blockly.FieldDropdown([
					[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_HOME'),'0'],
					[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_JUMP'),'1'],
					[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_WALK'),'2'],
					[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_TURN'),'3'],
					[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_BEND'),'4'],
					[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_SHAKE_LEG'),'5'],
					[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_UPDOWN'),'6'],
					[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_SWING'),'7'],
					[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_TIPTOE_SWING'),'8'],
					[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_JITTER'),'9'],
					[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_ASCENDING_TURN'),'10'],
					[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_MOONWALKER'),'11'],
					[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_CRUSAITO'),'12'],
					[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_FLAPPING'),'13']
					]);
				this.appendDummyInput().appendField(new Blockly.FieldImage('img/blocks/hippie.svg', 32*options.zoom, 32*options.zoom)).appendField(Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT'));
				this.appendDummyInput('').appendField(Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_MOVEMENT')).appendField(movement,'MOVEMENT').setAlign(Blockly.ALIGN_RIGHT);
				this.last_movement = -1;
				this._inp1_removed = true;
				this._inp2_removed = true;
				this._inp3_removed = true;
				this._inp4_removed = true;
				this.checkMovement();
				this.last_movement = this.getFieldValue('MOVEMENT');
				this.setInputsInline(false);
				this.setPreviousStatement(true,'code');
					this.setNextStatement(true,'code');
				this.setOutput(false);
					this.setTooltip(Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_TOOLTIP'));
				},
				checkMovement: function() {
				var _movement = this.getFieldValue('MOVEMENT');
					try {
							if (_movement<11)
							{
								this._inp4_removed=true;
								this.removeInput('INP4');
							}
					} catch (e) {}
					try {
							if (((_movement>=6)&&(_movement<=10)&&(this.last_movement>=2)&&(this.last_movement<=5))||((_movement>=2)&&(_movement<=5)&&(this.last_movement>=6)&&(this.last_movement<=10)))
							{
								this._inp3_removed=true;
								this.removeInput('INP3');
							}
					} catch (e) {}
					try {
							if (_movement<2)
							{
								this._inp3_removed=true;
								this.removeInput('INP3');
							}
					} catch (e) {}
					try {
						if (_movement<1)
							{
								this._inp1_removed=true;
								this.removeInput('INP1');
								this._inp2_removed=true;
								this.removeInput('INP2');
							}
					} catch (e) {}
					if ( _movement == 1) {
						if (this._inp1_removed)
						{
							this.appendValueInput('INP1').setCheck(Number).appendField(Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_STEPS'),'TEXT1').setAlign(Blockly.ALIGN_RIGHT);
							this._inp1_removed=false;
						}
						else
							try{this.setFieldValue(Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_STEPS'),'TEXT1');}catch (e) {}	
						if (this._inp2_removed)
						{
							this.appendValueInput('INP2').setCheck(Number).appendField(Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_PERIOD','TEXT2')).setAlign(Blockly.ALIGN_RIGHT);
							this._inp2_removed=false;
						}
						else 
							try{this.setFieldValue(Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_PERIOD'),'TEXT2');}catch (e) {}	
					} else if (( _movement >= 2)&&( _movement <= 10)) {
						if (this._inp1_removed)
						{
							this.appendValueInput('INP1').setCheck(Number).appendField(Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_STEPS'),'TEXT1').setAlign(Blockly.ALIGN_RIGHT);
							this._inp1_removed=false;
						}
						else
							try{this.setFieldValue(Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_STEPS'),'TEXT1');}catch (e) {}	
						if (this._inp2_removed)
						{
							this.appendValueInput('INP2').setCheck(Number).appendField(Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_PERIOD','TEXT2')).setAlign(Blockly.ALIGN_RIGHT);
							this._inp2_removed=false;
						}
						else 
							try{this.setFieldValue(Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_PERIOD'),'TEXT2');}catch (e) {}
						if (this._inp3_removed)
						{
							if (_movement==2)
							  this.appendDummyInput('INP3').appendField(Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_DIR'),'TEXT3').appendField(new Blockly.FieldDropdown([[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_FORWARD'),'0'],[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_BACKWARD'),'1']]),'FIELD3').setAlign(Blockly.ALIGN_RIGHT);
							else if (_movement<=5)
							  this.appendDummyInput('INP3').appendField(Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_DIR'),'TEXT3').appendField(new Blockly.FieldDropdown([[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_LEFT'),'0'],[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_RIGHT'),'1']]),'FIELD3').setAlign(Blockly.ALIGN_RIGHT);
							else
							  this.appendValueInput('INP3').setCheck(Number).appendField(Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_HEIGHT'),'TEXT3').setAlign(Blockly.ALIGN_RIGHT);
							this._inp3_removed=false;
						}
						else {
							
							try{
								this.setFieldValue(Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_DIR'),'TEXT3'); this.getInput('INP3').removeField('FIELD3'); 
								if (_movement==2)
									this.getInput('INP3').appendField(new Blockly.FieldDropdown([[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_FORWARD'),'0'],[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_BACKWARD'),'1']]),'FIELD3');
								else if (_movement<=5)
									this.getInput('INP3').appendField(new Blockly.FieldDropdown([[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_LEFT'),'0'],[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_RIGHT'),'1']]),'FIELD3');
								else
									this.setFieldValue(Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_HEIGHT'),'TEXT3');
							}catch (e) {}
						}							
					}
					else if (( _movement >= 11)&&( _movement <= 13)){
						if (this._inp1_removed)
						{
							this.appendValueInput('INP1').setCheck(Number).appendField(Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_STEPS'),'TEXT1').setAlign(Blockly.ALIGN_RIGHT);
							this._inp1_removed=false;
						}
						else
							try{this.setFieldValue(Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_STEPS'),'TEXT1');}catch (e) {}	
						if (this._inp2_removed)
						{
							this.appendValueInput('INP2').setCheck(Number).appendField(Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_PERIOD','TEXT2')).setAlign(Blockly.ALIGN_RIGHT);
							this._inp2_removed=false;
						}
						else 
							try{this.setFieldValue(Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_PERIOD'),'TEXT2');}catch (e) {}
						if (this._inp3_removed)
						{
							if (_movement==11)
							  this.appendDummyInput('INP3').appendField(Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_DIR'),'TEXT3').appendField(new Blockly.FieldDropdown([[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_LEFT'),'0'],[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_RIGHT'),'1']]),'FIELD3').setAlign(Blockly.ALIGN_RIGHT);
							else 
							  this.appendDummyInput('INP3').appendField(Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_DIR'),'TEXT3').appendField(new Blockly.FieldDropdown([[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_FORWARD'),'0'],[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_BACKWARD'),'1']]),'FIELD3').setAlign(Blockly.ALIGN_RIGHT);
							this._inp3_removed=false;
						}
						else {
							
							try{
								this.setFieldValue(Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_DIR'),'TEXT3'); this.getInput('INP3').removeField('FIELD3'); 
								if (_movement==11)
									this.getInput('INP3').appendField(new Blockly.FieldDropdown([[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_LEFT'),'0'],[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_RIGHT'),'1']]),'FIELD3');
								else 
									this.getInput('INP3').appendField(new Blockly.FieldDropdown([[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_FORWARD'),'0'],[Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_BACKWARD'),'1']]),'FIELD3');
							}catch (e) {}
						}
						if (this._inp4_removed)
						{
							this.appendValueInput('INP4').setCheck(Number).appendField(Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_HEIGHT','TEXT4')).setAlign(Blockly.ALIGN_RIGHT);
							this._inp4_removed=false;
						}
						else 
							try{this.setFieldValue(Facilino.locales.getKey('LANG_HIPPIE_MOVEMENT_HEIGHT'),'TEXT4');}catch (e) {}
					}
				},
				onchange: function() {
					if (this.getFieldValue('MOVEMENT') !== this.last_movement) {
						this.checkMovement();
						this.last_movement = this.getFieldValue('MOVEMENT');
					}
				}
			};