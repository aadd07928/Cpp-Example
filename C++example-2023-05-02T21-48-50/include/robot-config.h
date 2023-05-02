using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor frontleft;
extern motor backleft;
extern motor frontright;
extern motor backright;
extern motor Roller;
extern digital_out numatics;
extern digital_out numatic;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );