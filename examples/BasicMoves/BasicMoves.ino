// This examples shows the basic moves of the Hippie Library
#include <Hippie.h>
#include <Oscillator.h>

const char* ssid = "Hippie";

Hippie hippie;

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
  hippie.new_walk();
  hippie.home();
  delay(500);

  // backward, shit piece
  hippie.new_walk(2, 4, 750);
  hippie.home();
  delay(500);

  // left
  hippie.new_turn();
  hippie.home();
  delay(500);

  // right
  hippie.new_turn(2);
  hippie.home();
  delay(500);

  hippie.shakeLeg(); // TODO: Specify which leg
  hippie.home();
  delay(500);

  // left moonwalk
  hippie.moonwalker();
  hippie.home();
  delay(500);

  // right moonwalk
  hippie.moonwalker(1, 900, 50, -1);
  hippie.home();
  delay(500);

  // jump (it is not really a jump)
  hippie.jump();
  hippie.home();
  delay(500);

  /*
  // Here is some more to experiment with

  hippie.swing();
  hippie.tiptoeSwing();
  hippie.jitter();
  hippie.bend();
  hippie.flapping();
  hippie.crusaito();

  hippie.test_pos();
    */
}
