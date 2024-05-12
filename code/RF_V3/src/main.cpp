/*
 * Remote Feelings: Adam Curtis, Aymeric Wang, Xinying Hu
 * 11/30/21
 * Prototype version. Author: Adam Curtis, Aymeric Wang
 */
#include <Arduino.h>
#include "calibration.h"
#include "pin_config.h"
#include "sender.h"
#ifndef SENDER_H
#include "reciever.h"
#endif
#ifndef MOTIONFUNKS_H
#include "MotionFuncs.h"
#endif

// int state = 'b'; //waiting
// int lastState = 'b'; //waiting

bool calibrated = false;


void interactOverUART(void){
  /* --------- Interacts over UART sending and receiving 8 bit numbers -------- */
  
  force_message_reciever(); // Gets in new force values from VR or robot
  // V2FollowandForce(); // Applies appropriate force to fingers
  readFingerPositions(); // Checks where the fingers are
  // Sends finger location to VR or robot 
  send_control();
  // delay(200);
}


void manualCalibration(){

  /* --------------------------- manual calibration --------------------------- */
  // ===STEP ONE=== 
  //  a. Make sure your motors and encoders work. Uncomment the functions in the block below. 
  // This will make the motors spin backward and forward to make sure the motor drivers are working correctly.
  //  b. printFingerPosition() function makes sure the encoder in the motor works too. These numbers 
  // should be changing when the motor moves===

  // testMotors(2); // function argument = ms delay. 2ms delay time sets a good speed of ramp up
  // printFingerPositions();
  // delay(100);
  
  // ===END STEP ONE. Put these lines back in comments===
  
  // ===STEP TWO===
  //  a. Uncomment the printForce() function and upload.
  //  b. Push on the motors and make sure the numbers being printed are changing.
  //  c. Stop pushing on the motors and let them sit naturally. Enter the resting values in the calibration header file.

  printForce();
  delay(300);
  
  // ===END STEP TWO. Put this line back in comments===

  // ===STEP THREE===
  //  a. Uncomment the function below and upload 
  //  b. Rotate the output shafts of the servos so that the full range of finger motion does not cross the  
  // discontinuity between highest and lowest value. Attach the physical hardware fingers to the glove and 
  // verify that you don't hit zero or 4096

  // printFingerPositions(); //prints out the location of each finger. 
  // delay(300);

  // ===END STEP THREE. Leave this function running.

  // ===STEP FOUR=== 
  //  a. With the same function running. Put on the glove, and curl each finger into your palm.
  //    i. Record this number in the fingerPosMin[] array starting with pinky, going to thumb
  //  b. Now extend each finger to its maximum open position
  //    i. Record this number in the fingerPosMax[] array starting with pinky, going to thumb

  // NOTE*** MIN can be higher or lower than MAX and vice versa. This is normal.

  // END STEP FOUR. Comment out this function again.

  // STEP FIVE. Uncomment the followFingersV2 function, upload, and move your fingers. 
  // The motors should help drive the exoskeleton to follow your fingers

  // followFingersV2(); //Just move with your finger motion, nothing else

  // END STEP FIVE. Put this line back in comments

  /* ------------------------- end manual calibration ------------------------- */  

}

void setup() {
  Serial.begin(115200);
  setupMotors();
  delay(1000);
}

void loop() {
  
  /* -------------------------------------------------------------------------- */
  /*       Use the following functions by uncommenting ONLY ONE AT A TIME       */
  /* -------------------------------------------------------------------------- */

  // test_UART();
  // delay(100);

  /* --------------------------- manual calibration --------------------------- */
  // Uncomment ONLY this function and follow the instructions in the function body
  // manualCalibration();
  /* ------------------------- end manual calibration ------------------------- */


  /* ------------------- Connect to VR or a robot over UART ------------------- */
  // UncommentaLY this function
  interactOverUART(); // Ca-lls James's simulation interface
  /* ---------a------------- end VR or robot control ------------------------ */


  /* --------------- Use for access to state machine controller --------------- */
  // controller();
  /* ------------------------- end state machine code ------------------------- */
}