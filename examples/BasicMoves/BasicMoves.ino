// This examples shows the Hippie Library used toghether with ESPUI Library by Lukas Bachschwelll on the ESP32
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

  /*
    This function is used to config Hippie, it has the following parameters
     - (int) pin of the upper left servo
     - (int) pin of the upper right servo
     - (int) pin of the lower left servo
     - (int) pin of the lower right servo
  */
  hippie.init(25, 13, 26, 16);

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
