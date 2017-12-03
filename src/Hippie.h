#ifndef Hippie_h
#define Hippie_h

#include <Oscillator.h>

//-- Constants
#define FORWARD     1
#define BACKWARD    -1
#define LEFT        1
#define RIGHT       -1
#define SMALL       5
#define MEDIUM      15
#define BIG         30


class Hippie
{
  public:

    //-- Hippie initialization
    void init(int YL, int YR, int RL, int RR, int Buzzer=PIN_Buzzer);

    //-- Attach & detach functions
    void attachServos();
    void detachServos();

    //-- Predetermined Motion Functions
    void _moveServos(int time, int  servo_target[]);
    void oscillateServos(int A[4], int O[4], int T, double phase_diff[4], float cycle);

    //-- HOME = Hippie at rest position
    void home();
    bool getRestState();
    void setRestState(bool state);

    //-- Predetermined Motion Functions
    void jump(float steps=1, int T = 600);

    void walk(float steps=4, int T=1000, int dir = FORWARD);
    void turn(float steps=4, int T=1000, int dir = LEFT);
    void bend (int steps=1, int T=1400, int dir=LEFT);
    void shakeLeg (int steps=1, int T = 2000, int dir=RIGHT);

    void updown(float steps=1, int T=1000, int h = 40);
    void swing(float steps=1, int T=1000, int h=40);
    void tiptoeSwing(float steps=1, int T=900, int h=40);
    void jitter(float steps=1, int T=500, int h=50);
    void ascendingTurn(float steps=1, int T=900, int h=50);

    void moonwalker(float steps=1, int T=900, int h=50, int dir=LEFT);
    void crusaito(float steps=1, int T=900, int h=20, int dir=FORWARD);
    void flapping(float steps=1, int T=1000, int h=50, int dir=FORWARD);

	  void test_pos();

    void new_walk(int dir = FORWARD, float steps =4, int T=750);
	  void new_turn(int dir = LEFT, float steps =2, int T=1000);


  private:

    Oscillator servo[4];

    int servo_pins[4];
    int servo_trim[4];
    int servo_position[4];

    int pinBuzzer;

    unsigned long final_time;
    unsigned long partial_time;
    float increment[4];

    bool isHippieResting;

    void _execute(int A[4], int O[4], int T, double phase_diff[4], float steps);

};

#endif
