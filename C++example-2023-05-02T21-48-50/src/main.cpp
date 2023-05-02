/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\andre                                            */
/*    Created:      Tue May 02 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// frontleft            motor         1               
// backleft             motor         2               
// frontright           motor         3               
// backright            motor         4               
// Roller               motor         5               
// numatics             digital_out   A               
// numatic              digital_out   B               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void driver() {
  while(true) {
    frontleft.spin(forward,Controller1.Axis3.position(percent)+Controller1.Axis1.position(percent),percent);
    frontright.spin(forward,Controller1.Axis3.position(percent)-Controller1.Axis1.position(percent),percent);
    backleft.spin(forward,Controller1.Axis3.position(percent)+Controller1.Axis1.position(percent),percent);
    backright.spin(forward,Controller1.Axis3.position(percent)-Controller1.Axis1.position(percent),percent);

    Roller.stop();
    if(Controller1.ButtonL1.pressing()) {
      Roller.spin(forward,100,pct);
    }

    if(Controller1.ButtonR1.pressing()&&Controller1.ButtonR2.pressing()){
      numatics = 1;
      numatic = 1;
    }
  }
}

void driveback(float t) {
  
    frontleft.spin(reverse,50,pct);
    frontright.spin(reverse,50,pct);
    backleft.spin(reverse,50,pct);
    backright.spin(reverse,50,pct);
  wait(t, seconds);
  frontleft.stop();
  frontright.stop();
  backleft.stop();
  backright.stop();
}

void auton(){
  driveback(.2);
  Roller.spin(forward,100,pct);
  wait(.3,sec);
  Roller.stop();
}

competition Comp;
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Comp.drivercontrol(driver);
  Comp.autonomous(auton);

  while(true) {
    wait(10,msec);
    }
}
