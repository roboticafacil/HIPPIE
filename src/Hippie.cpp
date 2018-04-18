#include "Arduino.h"

#include "Hippie.h"
#include <Oscillator.h>


void Hippie::init(int YL, int YR, int RL, int RR, int OYL, int OYR, int ORL, int ORR) {

  servo_pins[0] = YL;
  servo_pins[1] = YR;
  servo_pins[2] = RL;
  servo_pins[3] = RR;
  
  attachServos();
  isHippieResting=false;


  for (int i = 0; i < 4; i++) servo_position[i] = 90;
}

void Hippie::init_with_trim(int YL, int YR, int RL, int RR, int OYL, int OYR, int ORL, int ORR) {

  servo_pins[0] = YL;
  servo_pins[1] = YR;
  servo_pins[2] = RL;
  servo_pins[3] = RR;
  servo[0].SetTrim(OYL);
  servo[1].SetTrim(OYR);
  servo[2].SetTrim(ORL);
  servo[3].SetTrim(ORR);
  
  attachServos();
  isHippieResting=false;


  for (int i = 0; i < 4; i++) servo_position[i] = 90;
}

///////////////////////////////////////////////////////////////////
//-- ATTACH & DETACH FUNCTIONS ----------------------------------//
///////////////////////////////////////////////////////////////////
void Hippie::attachServos(){
    servo[0].attach(servo_pins[0]);
    servo[1].attach(servo_pins[1]);
    servo[2].attach(servo_pins[2]);
    servo[3].attach(servo_pins[3]);
}

void Hippie::detachServos(){
    servo[0].detach();
    servo[1].detach();
    servo[2].detach();
    servo[3].detach();
}


///////////////////////////////////////////////////////////////////
//-- BASIC MOTION FUNCTIONS -------------------------------------//
///////////////////////////////////////////////////////////////////
void Hippie::_moveServos(int time, int  servo_target[]) {

  attachServos();
  if(getRestState()==true){
        setRestState(false);
  }

  if(time>10){
    for (int i = 0; i < 4; i++) increment[i] = ((servo_target[i]) - servo_position[i]) / (time / 10.0);
    final_time =  millis() + time;

    for (int iteration = 1; millis() < final_time; iteration++) {
      partial_time = millis() + 10;
      for (int i = 0; i < 4; i++) servo[i].SetPosition(servo_position[i] + (iteration * increment[i]));
      while (millis() < partial_time); //pause
    }
  }
  else{
    for (int i = 0; i < 4; i++) servo[i].SetPosition(servo_target[i]);
  }
  for (int i = 0; i < 4; i++) servo_position[i] = servo_target[i];
}


void Hippie::oscillateServos(int A[4], int O[4], int T, double phase_diff[4], float cycle=1){

  for (int i=0; i<4; i++) {
    servo[i].SetO(O[i]);
    servo[i].SetA(A[i]);
    servo[i].SetT(T);
    servo[i].SetPh(phase_diff[i]);
	servo[i].SetTrim(servo_trim[i]);
  }
  double ref=millis();
   for (double x=ref; x<=T*cycle+ref; x=millis()){
     for (int i=0; i<4; i++){
        servo[i].refresh();
     }
  }
}


void Hippie::_execute(int A[4], int O[4], int T, double phase_diff[4], float steps = 1.0){

  attachServos();
  if(getRestState()==true){
        setRestState(false);
  }


  int cycles=(int)steps;

  //-- Execute complete cycles
  if (cycles >= 1)
    for(int i = 0; i < cycles; i++)
      oscillateServos(A,O, T, phase_diff);

  //-- Execute the final not complete cycle
  oscillateServos(A,O, T, phase_diff,(float)steps-cycles);
}



///////////////////////////////////////////////////////////////////
//-- HOME = Hippie at rest position -------------------------------//
///////////////////////////////////////////////////////////////////
void Hippie::home(){

  if(isHippieResting==false){ //Go to rest position only if necessary

    int homes[4]={90, 90, 90, 90}; //All the servos at rest position
    _moveServos(500,homes);   //Move the servos in half a second

    detachServos();
    isHippieResting=true;
  }
}

bool Hippie::getRestState(){

    return isHippieResting;
}

void Hippie::setRestState(bool state){

    isHippieResting = state;
}


///////////////////////////////////////////////////////////////////
//-- PREDETERMINED MOTION SEQUENCES -----------------------------//
///////////////////////////////////////////////////////////////////

//---------------------------------------------------------
//-- Hippie movement: Jump
//--  Parameters:
//--    steps: Number of steps
//--    T: Period
//---------------------------------------------------------
void Hippie::jump(float steps, int T){

  int up[]={90,90,165,15};
  _moveServos(T,up);
  int down[]={90,90,90,90};
  _moveServos(T,down);
}

//---------------------------------------------------------
//-- Hippie Test Positions (bring feets and hips in certain position)
//---------------------------------------------------------
void Hippie::test_pos(){

	int left_feet_up[4]={90,0,90,30};								//watch from view of robot: [3] = left leg ... by + value: turn right
	_moveServos(1000,left_feet_up);									//							[4] = right leg ... by + value: right side up

}


//---------------------------------------------------------
//-- Hippie gait: Walking  (forward or backward)
//--  Parameters:
//--    * steps:  Number of steps
//--    * T : Period
//--    * Dir: Direction: FORWARD / BACKWARD
//---------------------------------------------------------
void Hippie::walk(float steps, int T, int dir){

  //-- Oscillator parameters for walking
  //-- Hip sevos are in phase
  //-- Feet servos are in phase
  //-- Hip and feet are 90 degrees out of phase
  //--      -90 : Walk forward
  //--       90 : Walk backward
  //-- Feet servos also have the same offset (for tiptoe a little bit)
  int A[4]= {30, 30, 40, 40}; //20
  int O[4] = {0, 0, 4, 30}; //-4
  double phase_diff[4] = {0, 0, DEG2RAD(dir * -90), DEG2RAD(dir * -90)};

  if ( dir == -1) {   double phase_diff[4] = {0, 0, DEG2RAD(dir * 90), DEG2RAD(dir * 90)}; }

  //-- Let's oscillate the servos!
  _execute(A, O, T, phase_diff, steps);
}


//---------------------------------------------------------
//-- Hippie gait: Turning (left or right)
//--  Parameters:
//--   * Steps: Number of steps
//--   * T: Period
//--   * Dir: Direction: LEFT / RIGHT
//---------------------------------------------------------
void Hippie::turn(float steps, int T, int dir){

  //-- Same coordination than for walking (see Hippie::walk)
  //-- The Amplitudes of the hip's oscillators are not igual
  //-- When the right hip servo amplitude is higher, the steps taken by
  //--   the right leg are bigger than the left. So, the robot describes an
  //--   left arc
  int A[4]= {30, 30, 20, 20};
  int O[4] = {0, 0, 4, 30};
  double phase_diff[4] = {0, 0, DEG2RAD(-90), DEG2RAD(-90)};

  if (dir == LEFT) {
    A[0] = 50; //-- Left hip servo
    A[1] = 10; //-- Right hip servo
  }
  else {
    A[0] = 10;
    A[1] = 50;
	A[2] = 40;
  }

  //-- Let's oscillate the servos!
  _execute(A, O, T, phase_diff, steps);
}


//---------------------------------------------------------
//-- Hippie gait: Lateral bend
//--  Parameters:
//--    steps: Number of bends
//--    T: Period of one bend
//--    dir: RIGHT=Right bend LEFT=Left bend
//---------------------------------------------------------
void Hippie::bend (int steps, int T, int dir){

  //Parameters of all the movements. Default: Left bend
  int bend1[4]={90, 90, 62, 35};
  int bend2[4]={90, 90, 62, 105+60};
  int homes[4]={90, 90, 90, 90};

  //Time of one bend, constrained in order to avoid movements too fast.
  //T=max(T, 600);

  //Changes in the parameters if right direction is chosen
  if(dir==-1)
  {
    bend1[2]=180-35;
    bend1[3]=180-60;  //Not 65. Hippie is unbalanced
    bend2[2]=180-105;
    bend2[3]=180-60;
  }

  //Time of the bend movement. Fixed parameter to avoid falls
  int T2=800;

  //Bend movement
  for (int i=0;i<steps;i++)
  {
    _moveServos(T2/2,bend1);
    _moveServos(T2/2,bend2);
    delay(T*0.8);
    _moveServos(500,homes);
  }

}

//--------------------------------------------------------
//-- New Walk Move
//-- number of steps
//-- T: Period of one steps
//-- dir: direction of movement
//--------------------------------------------------------
void Hippie::new_walk(float steps, int T, int dir){
	if(dir==1){
		// Positions of walking
		int Pos_A[4] = {90,90,180, 90};
		int Pos_B[4] = {90,90,180, 180};
		int Pos_C[4] = {90,45,90, 180};
		int Pos_D[4] = {45,45,90,90};

		int Pos_E[4] = {45,45,30,30};
		int Pos_F[4] = {150,150,30,90};
		int Pos_G[4] = {150,150,90,90};

	// run movements
		for (int i=0;i<steps;i++)
		{
			_moveServos(T/2, Pos_A);
			_moveServos(T/3, Pos_B);
			//delay(T);
			_moveServos(T/2, Pos_C);
			_moveServos(T/2, Pos_D);
			//delay(T);
			_moveServos(T/2, Pos_E);
			_moveServos(T/2, Pos_F);
			_moveServos(T/2, Pos_G);

			//delay(T*3);
		}

	}

	//Backwards
	if (dir == 2){
		int Pos_1[4] = {90,90,180, 90};
		int Pos_2[4] = {90,90,180, 180};
		int Pos_3[4] = {90,145,90, 180};
		int Pos_4[4] = {145,145,90,90};

		int Pos_5[4] = {145,145,30,30};
		int Pos_6[4] = {45,45,30,90};
		int Pos_7[4] = {45,45,90,90};

		// run movements
		for (int i=0;i<steps;i++)
		{
			_moveServos(T/2, Pos_1);
			_moveServos(T/3, Pos_2);
			//delay(T);
			_moveServos(T/2, Pos_3);
			_moveServos(T/2, Pos_4);
			//delay(T);
			_moveServos(T/2, Pos_5);
			_moveServos(T/2, Pos_6);
			_moveServos(T/2, Pos_7);

			//delay(T*3);
		}

	}
}

//--------------------------------------------------------
//-- New Turn Move
//-- number of steps
//-- T: Period of one steps
//-- dir: direction of movement
//--------------------------------------------------------
void Hippie::new_turn(float steps, int T, int dir){
	//LEFT
	if (dir==1) {
	// Positions of turning
		int Pos_A[4] = {90,90,90, 30};
		int Pos_B[4] = {90,90,30, 30};
		int Pos_C[4] = {0,90,30,90};
		int Pos_D[4] = {0,90,90,90};
		int Pos_E[4] = {90,90,90,90};

		// run movements
		for (int i=0;i<steps;i++)
		{
			_moveServos(T/2, Pos_A);
			_moveServos(T/3, Pos_B);
			//delay(T);
			_moveServos(T/2, Pos_C);
			_moveServos(T/2, Pos_D);
			_moveServos(T/2, Pos_E);
		}
	}

	//RIGHT
	if (dir==2) {
	// Positions of turning
		int Pos_1[4] = {90,90,180, 90};
		int Pos_2[4] = {90,90,180, 180};
		int Pos_3[4] = {90,180,90, 180};
		int Pos_4[4] = {90,180,90,90};
		int Pos_5[4] = {90,90,90,90};

		// run movements
		for (int i=0;i<steps;i++)
		{
			_moveServos(T/2, Pos_1);
			_moveServos(T/3, Pos_2);
			//delay(T);
			_moveServos(T/2, Pos_3);
			_moveServos(T/2, Pos_4);
			_moveServos(T/2, Pos_5);
		}
	}
}

//---------------------------------------------------------
//-- Hippie gait: Shake a leg
//--  Parameters:
//--    steps: Number of shakes
//--    T: Period of one shake
//--    dir: RIGHT=Right leg LEFT=Left leg
//---------------------------------------------------------
void Hippie::shakeLeg (int steps,int T,int dir){

  //This variable change the amount of shakes
  int numberLegMoves=4;

  //Parameters of all the movements. Default: Right leg
  int shake_leg1[4]={90, 90, 58, 35-15};
  int shake_leg2[4]={90, 90, 58, 120+30};
  int shake_leg3[4]={90, 90, 58, 60-30};
  int homes[4]={90, 90, 90, 90};

  //Changes in the parameters if left leg is chosen
  if(dir==-1)
  {
    shake_leg1[2]=180-35;
    shake_leg1[3]=180-58;
    shake_leg2[2]=180-120;
    shake_leg2[3]=180-58;
    shake_leg3[2]=180-60;
    shake_leg3[3]=180-58;
  }

  //Time of the bend movement. Fixed parameter to avoid falls
  int T2=1000;
  //Time of one shake, constrained in order to avoid movements too fast.
  T=T-T2;
  T=max(T,200*numberLegMoves);

  for (int j=0; j<steps;j++)
  {
  //Bend movement
  _moveServos(T2/2,shake_leg1);
  _moveServos(T2/2,shake_leg2);

    //Shake movement
    for (int i=0;i<numberLegMoves;i++)
    {
    _moveServos(T/(2*numberLegMoves),shake_leg3);
    _moveServos(T/(2*numberLegMoves),shake_leg2);
    }
    _moveServos(500,homes); //Return to home position
  }

  delay(T);
}


//---------------------------------------------------------
//-- Hippie movement: up & down
//--  Parameters:
//--    * steps: Number of jumps
//--    * T: Period
//--    * h: Jump height: SMALL / MEDIUM / BIG
//--              (or a number in degrees 0 - 90)
//---------------------------------------------------------
void Hippie::updown(float steps, int T, int h){

  //-- Both feet are 180 degrees out of phase
  //-- Feet amplitude and offset are the same
  //-- Initial phase for the right foot is -90, so that it starts
  //--   in one extreme position (not in the middle)
  int A[4]= {0, 0, h, h};
  int O[4] = {0, 0, h, -h+50};
  double phase_diff[4] = {0, 0, DEG2RAD(-90), DEG2RAD(90)};

  //-- Let's oscillate the servos!
  _execute(A, O, T, phase_diff, steps);
}


//---------------------------------------------------------
//-- Hippie movement: swinging side to side
//--  Parameters:
//--     steps: Number of steps
//--     T : Period
//--     h : Amount of swing (from 0 to 50 aprox)
//---------------------------------------------------------
void Hippie::swing(float steps, int T, int h){

  //-- Both feets are in phase. The offset is half the amplitude
  //-- It causes the robot to swing from side to side
  int A[4]= {0, 0, h, h};
  int O[4] = {0, 0, h/2-20, -h/2+50-20};
  double phase_diff[4] = {0, 0, DEG2RAD(0), DEG2RAD(0)};

  //-- Let's oscillate the servos!
  _execute(A, O, T, phase_diff, steps);
}


//---------------------------------------------------------
//-- Hippie movement: swinging side to side without touching the floor with the heel
//--  Parameters:
//--     steps: Number of steps
//--     T : Period
//--     h : Amount of swing (from 0 to 50 aprox)
//---------------------------------------------------------
void Hippie::tiptoeSwing(float steps, int T, int h){

  //-- Both feets are in phase. The offset is not half the amplitude in order to tiptoe
  //-- It causes the robot to swing from side to side
  int A[4]= {0, 0, h, h};
  int O[4] = {0, 0, h-20, -h+50};
  double phase_diff[4] = {0, 0, 0, 0};

  //-- Let's oscillate the servos!
  _execute(A, O, T, phase_diff, steps);
}


//---------------------------------------------------------
//-- Hippie gait: Jitter
//--  Parameters:
//--    steps: Number of jitters
//--    T: Period of one jitter
//--    h: height (Values between 5 - 25)
//---------------------------------------------------------
void Hippie::jitter(float steps, int T, int h){

  //-- Both feet are 180 degrees out of phase
  //-- Feet amplitude and offset are the same
  //-- Initial phase for the right foot is -90, so that it starts
  //--   in one extreme position (not in the middle)
  //-- h is constrained to avoid hit the feets
  h=min(25,h);
  int A[4]= {h, h, 0, 0};
  int O[4] = {0, 0, 0, 0};
  double phase_diff[4] = {DEG2RAD(-90), DEG2RAD(90), 0, 0};

  //-- Let's oscillate the servos!
  _execute(A, O, T, phase_diff, steps);
}


//---------------------------------------------------------
//-- Hippie gait: Ascending & turn (Jitter while up&down)
//--  Parameters:
//--    steps: Number of bends
//--    T: Period of one bend
//--    h: height (Values between 5 - 15)
//---------------------------------------------------------
void Hippie::ascendingTurn(float steps, int T, int h){

  //-- Both feet and legs are 180 degrees out of phase
  //-- Initial phase for the right foot is -90, so that it starts
  //--   in one extreme position (not in the middle)
  //-- h is constrained to avoid hit the feets
  h=min(13,h);
  int A[4]= {h, h, h, h};
  int O[4] = {0, 0, h+4, -h+40};
  double phase_diff[4] = {DEG2RAD(-90), DEG2RAD(90), DEG2RAD(-90), DEG2RAD(90)};

  //-- Let's oscillate the servos!
  _execute(A, O, T, phase_diff, steps);
}


//---------------------------------------------------------
//-- Hippie gait: Moonwalker. Hippie moves like Michael Jackson
//--  Parameters:
//--    Steps: Number of steps
//--    T: Period
//--    h: Height. Typical valures between 15 and 40
//--    dir: Direction: LEFT / RIGHT
//---------------------------------------------------------
void Hippie::moonwalker(float steps, int T, int h, int dir){

  //-- This motion is similar to that of the caterpillar robots: A travelling
  //-- wave moving from one side to another
  //-- The two Hippie's feet are equivalent to a minimal configuration. It is known
  //-- that 2 servos can move like a worm if they are 120 degrees out of phase
  //-- In the example of Hippie, the two feet are mirrored so that we have:
  //--    180 - 120 = 60 degrees. The actual phase difference given to the oscillators
  //--  is 60 degrees.
  //--  Both amplitudes are equal. The offset is half the amplitud plus a little bit of
  //-   offset so that the robot tiptoe lightly

  int A[4]= {0, 0, h, h};
  int O[4] = {0, 0, h/2+2, -h/2 -2+60};
  int phi = -dir * 90;
  double phase_diff[4] = {0, 0, DEG2RAD(phi), DEG2RAD(-60 * dir + phi)};

  //-- Let's oscillate the servos!
  _execute(A, O, T, phase_diff, steps);
}


//----------------------------------------------------------
//-- Hippie gait: Crusaito. A mixture between moonwalker and walk
//--   Parameters:
//--     steps: Number of steps
//--     T: Period
//--     h: height (Values between 20 - 50)
//--     dir:  Direction: LEFT / RIGHT
//-----------------------------------------------------------
void Hippie::crusaito(float steps, int T, int h, int dir){

  int A[4]= {25, 25, h, h};
  int O[4] = {0, 0, h/2+ 4, -h/2 - 4+30};
  double phase_diff[4] = {90, 90, DEG2RAD(0), DEG2RAD(-60 * dir)};

  //-- Let's oscillate the servos!
  _execute(A, O, T, phase_diff, steps);
}


//---------------------------------------------------------
//-- Hippie gait: Flapping
//--  Parameters:
//--    steps: Number of steps
//--    T: Period
//--    h: height (Values between 10 - 30)
//--    dir: direction: FOREWARD, BACKWARD
//---------------------------------------------------------
void Hippie::flapping(float steps, int T, int h, int dir){

  int A[4]= {12+10, 12+10, h, h};
  int O[4] = {0, 0, h - 10, -h + 10+60};
  double phase_diff[4] = {DEG2RAD(0), DEG2RAD(180), DEG2RAD(-90 * dir), DEG2RAD(90 * dir)};

  //-- Let's oscillate the servos!
  _execute(A, O, T, phase_diff, steps);
}
