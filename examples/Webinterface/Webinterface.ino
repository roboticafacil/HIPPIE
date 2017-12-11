// This examples shows the Hippie Library used toghether with ESPUI Library by Lukas Bachschwelll on the ESP32
#include <WiFi.h>
#include <ESPUI.h>
#include <Hippie.h>
#include <Oscillator.h>


const char* ssid = "Hippie";

Hippie hippie;

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
  Serial.println("");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());


  ESPUI.pad("Move", true, &buttonPad, COLOR_CARROT);
  ESPUI.button("TT Swing", &ttSwingButton, COLOR_PETERRIVER);
  ESPUI.button("Swing", &swingButton, COLOR_PETERRIVER);
  ESPUI.button("Angry", &angryButton, COLOR_PETERRIVER);
  ESPUI.button("Jitter", &jitterButton, COLOR_PETERRIVER);
  ESPUI.button("Shake", &shakeButton, COLOR_PETERRIVER);
  ESPUI.button("Bend", &bendButton, COLOR_PETERRIVER);
  ESPUI.button("Flap", &flapButton, COLOR_PETERRIVER);
  ESPUI.button("Moonwalk Left", &moonLeftButton, COLOR_PETERRIVER);
  ESPUI.button("Cruisato", &cruisatoButton, COLOR_PETERRIVER);
  ESPUI.button("Moonwalk Right", &moonRightButton, COLOR_PETERRIVER);

  ESPUI.begin("Hippie Control Demo");

  /*
    This function is used to config Hippie, it has the following parameters
     - (int) pin of the upper left servo
     - (int) pin of the upper right servo
     - (int) pin of the lower left servo
     - (int) pin of the lower right servo
  */

  hippie.init(25, 13, 26, 16);
}


void ttSwingButton(Control c, int type) {
  if (type == B_DOWN) {
    tt_swing = true;
  }
  else {
    tt_swing = false;
  }
}

void swingButton(Control c, int type) {
  if (type == B_DOWN) {
    swing = true;
  }
  else {
    swing = false;
  }
}

void angryButton(Control c, int type) {
  if (type == B_DOWN) {
    jump = true;
  }
  else {
    jump = false;
  }
}

void jitterButton(Control c, int type) {
  if (type == B_DOWN) {
    jitter = true;
  }
  else {
    jitter = false;
  }
}

void shakeButton(Control c, int type) {
  if (type == B_DOWN) {
    shake = true;
  }
  else {
    shake = false;
  }
}

void bendButton(Control c, int type) {
  if (type == B_DOWN) {
    bend = true;
  }
  else {
    bend = false;
  }
}

void flapButton(Control c, int type) {
  if (type == B_DOWN) {
    flap = true;
  }
  else {
    flap = false;
  }
}

void moonLeftButton(Control c, int type) {
  if (type == B_DOWN) {
    moon = true;
  }
  else {
    moon = false;
  }
}

void cruisatoButton(Control c, int type) {
  if (type == B_DOWN) {
    cruise = true;
  }
  else {
    cruise = false;
  }
}

void moonRightButton(Control c, int type) {
  if (type == B_DOWN) {
    moon_r = true;
  }
  else {
    moon_r = false;
  }
}


void buttonPad (Control c, int value) {
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
  if (walk_forward) hippie.new_walk();
  else if (walk_backward) hippie.new_walk(2, 4, 750);
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
  else if (moon_r) hippie.moonwalker(1, 900, 50, -1);
  else if (cruise) hippie.crusaito();
  else if (test_pos) hippie.test_pos();
  else hippie.home();
}
