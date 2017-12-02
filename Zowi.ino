

/**************************************************************************************
*                                                                                     *
*   Programa de calibracion de Hippie                                                   *
*   Javier Isabel, 02/06/2015                                                         *
*                                                                                     *
*   En este programa se indica como calibrar a Hippie utilizando                        *
*   la librera diseñada especificamente para el, hippie.h                               *
*                                                                                     *
**************************************************************************************/

#include <Hippie.h> //Libreria Hippie, disponible en el repositorio de GitHub de Hippie
#include <ESP32_Servo.h>
#include <Oscillator.h> //Librera ArduSnake de Obijuan, en GitHub
#include <EEPROM.h>
#include <WiFi.h>
#include <ESPUI.h>

const char* ssid = "Real_Hippie";

/**************************************************************************************
*                                                                                     *
* Empezamos por declarar un objeto de la clase Hippie. La clase Hippie                    *
* contiene funciones para calibrar a Hippie y para crear y ejecutar                     *
* diversos tipos de movimientos                                                       *
*                                                                                     *
**************************************************************************************/

Hippie hippie;
int posiciones[] = {90, 90, 90, 90};

boolean walk_forward = false;
boolean walk_backward = false;
boolean jump = false;
boolean turn_left = false;
boolean turn_right = false;
boolean shake = false;
boolean swing = false;
boolean tt_swing = false;
boolean jitter = false;
boolean bend = false;
boolean flap = false;
boolean moon = false;
boolean moon_r = false;
boolean cruise = false;
boolean test_pos = false;

void setup()
{

   Serial.begin(115200);
  WiFi.mode(WIFI_AP);
  WiFi.setHostname(ssid);
  WiFi.softAP(ssid);
  //WiFi.softAP(ssid, password);
  Serial.println("");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());


  ESPUI.pad("Hips dont Lie", true, &Padle, COLOR_CARROT);
  ESPUI.button("TT_Swing  Button", &BeerButton,COLOR_PETERRIVER);
  ESPUI.button("Swing  Button", &BeerButton2,COLOR_PETERRIVER);
  ESPUI.button("Angry  Button", &BeerButton3,COLOR_PETERRIVER);
  ESPUI.button("Jitter  Button", &BeerButton4,COLOR_PETERRIVER);
  ESPUI.button("Shake  Button", &BeerButton5,COLOR_PETERRIVER);
  ESPUI.button("Bend  Button", &BeerButton6,COLOR_PETERRIVER);
  ESPUI.button("Flap  Button", &BeerButton7,COLOR_PETERRIVER);
  ESPUI.button("Moonwalk Left  Button", &BeerButton8,COLOR_PETERRIVER);
  ESPUI.button("cruisato  Button", &BeerButton9,COLOR_PETERRIVER);
  ESPUI.button("Moonwalk Right  Button", &BeerButton10,COLOR_PETERRIVER);

  ESPUI.switcher("Test", true, &test, COLOR_CARROT);
  
  ESPUI.begin("Hippie Control");

/**************************************************************************************
*                                                                                     *
* La funcion init sirve para configurar a Hippie, y se le pasan cinco parametros:       *
*  - (int) pin del servo superior izquierdo                                           *
*  - (int) pin del servo superior derecho                                             *
*  - (int) pin del servo inferior izquierdo                                           *
*  - (int) pin del servo inferior derecho                                             *
*  - (boolean) booleano que indica si quieren cargarse los valores de calibracion     *
*    de la memoria EEPROM (1, true) o no (0, false). Este valor puede omitirse, por   *
*    defecto sera 0                                                                   *
*                                                                                     *
**************************************************************************************/

  hippie.init(25, 13, 26, 16, false);
  //hippie.moveServos(500, posiciones);
}
void test(Control c, int type) {
}
void BeerButton(Control c, int type) {
  if (type == B_DOWN) {
    tt_swing = true;
  }
  else {
    tt_swing = false;
  }
}

void BeerButton2(Control c, int type) {
  if (type == B_DOWN) {
    swing = true;
  }
  else {
    swing = false;
  }
}

void BeerButton3(Control c, int type) {
  if (type == B_DOWN) {
    jump = true;
  }
  else {
    jump = false;
  }
}

void BeerButton4(Control c, int type) {
  if (type == B_DOWN) {
    jitter = true;
  }
  else {
    jitter = false;
  }
}

void BeerButton5(Control c, int type) {
  if (type == B_DOWN) {
    shake = true;
  }
  else {
    shake = false;
  }
}

void BeerButton6(Control c, int type) {
  if (type == B_DOWN) {
    bend = true;
  }
  else {
    bend = false;
  }
}

void BeerButton7(Control c, int type) {
  if (type == B_DOWN) {
    flap = true;
  }
  else {
    flap = false;
  }
}

void BeerButton8(Control c, int type) {
  if (type == B_DOWN) {
    moon = true;
  }
  else {
    moon = false;
  }
}

void BeerButton9(Control c, int type) {
  if (type == B_DOWN) {
    cruise = true;
  }
  else {
    cruise = false;
  }
}

void BeerButton10(Control c, int type) {
  if (type == B_DOWN) {
    moon_r = true;
  }
  else {
    moon_r = false;
  }
}


void Padle (Control c, int value) {
  switch (value) {
    case P_LEFT_DOWN:
      turn_left = true;
      break;
    case P_LEFT_UP:
      turn_left = false;
      break;
    case P_RIGHT_DOWN:
      turn_right = true;
      break;
    case P_RIGHT_UP:
      turn_right = false;
      break;
    case P_FOR_DOWN:
      walk_forward = true;
      break;
    case P_FOR_UP:
      walk_forward = false;
      break;
    case P_BACK_DOWN:
      walk_backward = true;
      break;
    case P_BACK_UP:
      walk_backward = false;
      break;
    case P_CENTER_DOWN:
      test_pos = true;
      break;
    case P_CENTER_UP:
      test_pos = false;
      break;
  }
}



void loop() 
{


/**************************************************************************************
*                                                                                     *
* Durante las pruebas utilizaremos la funcion moveServos para poner todos los servos  *
* a 90º y comparar su posicion real con la posicion buscada                           *
*                                                                                     *
**************************************************************************************/
  
  //hippie.walk(4,1800);

  if (walk_forward) hippie.new_walk();
  else if (walk_backward) hippie.new_walk(2,4,750);
  else if (turn_left) hippie.new_turn();
  else if (turn_right) hippie.new_turn(2);
  else if (shake) hippie.shakeLeg();
  else if (jump) hippie.jump();
  else if (swing) hippie.swing();
  else if (tt_swing) hippie.tiptoeSwing();
  else if (jitter) hippie.jitter();
  else if (bend) hippie.bend();
  else if (flap) hippie.flapping();
  else if (moon) hippie.moonwalker();
  else if (moon_r) hippie.moonwalker(1,900,50,-1);
  else if (cruise) hippie.crusaito();
  else if (test_pos) hippie.test_pos();
  else hippie.home();
 
}

