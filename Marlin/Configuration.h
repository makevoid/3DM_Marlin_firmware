#ifndef CONFIGURATION_H
#define CONFIGURATION_H


// 3dm1 firmware

// to check always: big or small pulleys
// board: sanguino / minitronics / azteeg
// extruder resistor pullup value (M303 calibration)
// thermistor

// then:

// check extruder
// check steppers driver potentiometer, set to minimum


// sanguino dl: https://code.google.com/p/sanguino/downloads/list
// sanguino wiki: http://sanguino.cc/
//
// osx guide: http://sanguino.cc/softwareformac


//

#define STRING_VERSION_CONFIG_H __DATE__ " " __TIME__
#define STRING_CONFIG_H_AUTHOR "3DMaking firmware - based on ErikZalm/Marlin"

#define SERIAL_PORT 0

#define BAUDRATE 250000

#ifndef MOTHERBOARD
#define MOTHERBOARD 702
#endif
// 62 sanguino, 702 minitronics, 63 melzi

#define EXTRUDERS 1

#define POWER_SUPPLY 1

#define TEMP_SENSOR_0 1 // default -1, todo: try the thermocouple
#define TEMP_SENSOR_1 0
#define TEMP_SENSOR_2 0
#define TEMP_SENSOR_BED 0

// reduntant thermistor: interesting
//#define TEMP_SENSOR_1_AS_REDUNDANT
//#define MAX_REDUNDANT_TEMP_SENSOR_DIFF 10

// Actual temperature must be close to target for this long before M109 returns success
#define TEMP_RESIDENCY_TIME 10  // (seconds)
#define TEMP_HYSTERESIS 3       // (degC) range of +/- temperatures considered "close" to the target one
#define TEMP_WINDOW     1       // (degC) Window around target to start the residency timer x degC early.

// The minimal temperature defines the temperature below which the heater will not be enabled if it's used
// to check that the wiring to the thermistor is not broken.
// Otherwise this would lead to the heater being powered on all the time.
#define HEATER_0_MINTEMP 0 // kentstrapper uses 0
#define HEATER_1_MINTEMP 5
#define HEATER_2_MINTEMP 5
#define BED_MINTEMP 5

// When temperature exceeds max temp, your heater will be switched off.
// This feature exists to protect your hotend from overheating accidentally, but *NOT* from thermistor short/failure!
// You should use MINTEMP for thermistor short/failure protection.
#define HEATER_0_MAXTEMP 235
#define HEATER_1_MAXTEMP 235
#define HEATER_2_MAXTEMP 235
#define BED_MAXTEMP 90 // default: 150

// If your bed has low resistance e.g. .6 ohm and throws the fuse you can duty cycle it to reduce the
// average current. The value should be an integer and the heat bed will be turned on for 1 interval of
// HEATER_BED_DUTY_CYCLE_DIVIDER intervals.
//#define HEATER_BED_DUTY_CYCLE_DIVIDER 4

// PID settings:
// Comment the following line to disable PID and enable bang-bang.
#define PIDTEMP
#define BANG_MAX 255 // limits current to nozzle while in bang-bang mode; 255=full current
#define PID_MAX 255 // limits current to nozzle while PID is active (see PID_FUNCTIONAL_RANGE below); 255=full current
#ifdef PIDTEMP
  //#define PID_DEBUG // Sends debug data to the serial port.
  //#define PID_OPENLOOP 1 // Puts PID in open loop. M104/M140 sets the output power from 0 to PID_MAX
  #define PID_FUNCTIONAL_RANGE 10 // If the temperature difference between the target temperature and the actual temperature
                                  // is more then PID_FUNCTIONAL_RANGE then the PID will be shut off and the heater will be set to min/max.
  #define PID_INTEGRAL_DRIVE_MAX 255  //limit for the integral term
  #define K1 0.95 //smoothing factor within the PID
  #define PID_dT ((16.0 * 8.0)/(F_CPU / 64.0 / 256.0)) //sampling period of the temperature routine


// reprapworld resistor
// #define  DEFAULT_Kp 31.61
// #define  DEFAULT_Ki 1.47
// #define  DEFAULT_Kd 170.37

// china red resistor on 3dm1 alpha
//#define  DEFAULT_Kp 7.46
//#define  DEFAULT_Ki 0.17
//#define  DEFAULT_Kd 83.70


// red resistor on galileo
//#define  DEFAULT_Kp 20.98
//#define  DEFAULT_Ki 1.56
//#define  DEFAULT_Kd 70.46

// geetech buda
//#define  DEFAULT_Kp 28.35
//#define  DEFAULT_Ki 3.02
//#define  DEFAULT_Kd 66.42

//#define  DEFAULT_Kp 67.51
//#define  DEFAULT_Ki 3.84
//#define  DEFAULT_Kd 296.44
#define  DEFAULT_Kp 80.26
#define  DEFAULT_Ki 4.96
#define  DEFAULT_Kd 324.81

// 100k glass thermistor big - similar to reprapworld
// #define  DEFAULT_Kp 20.17
// #define  DEFAULT_Ki 1.32
// #define  DEFAULT_Kd 77.32




#endif // PIDTEMP


#define MAX_BED_POWER 255 // limits duty cycle to bed; 255=full current





#define PREVENT_DANGEROUS_EXTRUDE // disable cold moves
#define PREVENT_LENGTHY_EXTRUDE

#define EXTRUDE_MINTEMP 165 // default is 170
#define EXTRUDE_MAXLENGTH (X_MAX_LENGTH+Y_MAX_LENGTH) //prevent extrusion of very large distances.

//===========================================================================
//=============================Mechanical Settings===========================
//===========================================================================

// Uncomment the following line to enable CoreXY kinematics
// #define COREXY

// coarse Endstop Settings
#define ENDSTOPPULLUPS // Comment this out (using // at the start of the line) to disable the endstop pullup resistors

#ifndef ENDSTOPPULLUPS
  // fine Enstop settings: Individual Pullups. will be ignored if ENDSTOPPULLUPS is defined
  // #define ENDSTOPPULLUP_XMAX
  // #define ENDSTOPPULLUP_YMAX
  // #define ENDSTOPPULLUP_ZMAX
  // #define ENDSTOPPULLUP_XMIN
  // #define ENDSTOPPULLUP_YMIN
  // #define ENDSTOPPULLUP_ZMIN
#endif

#ifdef ENDSTOPPULLUPS
  #define ENDSTOPPULLUP_XMAX
  #define ENDSTOPPULLUP_YMAX
  #define ENDSTOPPULLUP_ZMAX
  #define ENDSTOPPULLUP_XMIN
  #define ENDSTOPPULLUP_YMIN
  #define ENDSTOPPULLUP_ZMIN
#endif

// The pullups are needed if you directly connect a mechanical endswitch between the signal and ground pins.
const bool X_MIN_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
const bool Y_MIN_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
const bool Z_MIN_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
const bool X_MAX_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
const bool Y_MAX_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
const bool Z_MAX_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
//#define DISABLE_MAX_ENDSTOPS
//#define DISABLE_MIN_ENDSTOPS

// Disable max endstops for compatibility with endstop checking routine
#if defined(COREXY) && !defined(DISABLE_MAX_ENDSTOPS)
  #define DISABLE_MAX_ENDSTOPS
#endif

// For Inverting Stepper Enable Pins (Active Low) use 0, Non Inverting (Active High) use 1
#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define E_ENABLE_ON 0 // For all extruders

// Disables axis when it's not being used.
#define DISABLE_X false
#define DISABLE_Y false
#define DISABLE_Z false
#define DISABLE_E false // For all extruders

#define INVERT_X_DIR false    // for Mendel set to false, for Orca set to true
#define INVERT_Y_DIR false   // for 3dm1: false, for prusa i2: true
#define INVERT_Z_DIR false  // for 3dm1: false, for prusa i2: true
#define INVERT_E0_DIR true    // for direct drive extruder v9 set to true, for geared extruder set to false
#define INVERT_E1_DIR false    // for direct drive extruder v9 set to true, for geared extruder set to false
#define INVERT_E2_DIR false   // for direct drive extruder v9 set to true, for geared extruder set to false

// ENDSTOP SETTINGS:
// Sets direction of endstops when homing; 1=MAX, -1=MIN
#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR -1

#define min_software_endstops true // If true, axis won't move to coordinates less than HOME_POS.
#define max_software_endstops true  // If true, axis won't move to coordinates greater than the defined lengths below.

//============================= Bed Auto Leveling ===========================

//#define ENABLE_AUTO_BED_LEVELING // Delete the comment to enable (remove // at the start of the line)

#ifdef ENABLE_AUTO_BED_LEVELING

  // these are the positions on the bed to do the probing
  #define LEFT_PROBE_BED_POSITION 15
  #define RIGHT_PROBE_BED_POSITION 170
  #define BACK_PROBE_BED_POSITION 180
  #define FRONT_PROBE_BED_POSITION 20

  // these are the offsets to the prob relative to the extruder tip (Hotend - Probe)
  #define X_PROBE_OFFSET_FROM_EXTRUDER -25
  #define Y_PROBE_OFFSET_FROM_EXTRUDER -29
  #define Z_PROBE_OFFSET_FROM_EXTRUDER -12.35

  #define XY_TRAVEL_SPEED 8000         // X and Y axis travel speed between probes, in mm/min

  #define Z_RAISE_BEFORE_PROBING 15    //How much the extruder will be raised before traveling to the first probing point.
  #define Z_RAISE_BETWEEN_PROBINGS 5  //How much the extruder will be raised when traveling from between next probing points


  //If defined, the Probe servo will be turned on only during movement and then turned off to avoid jerk
  //The value is the delay to turn the servo off after powered on - depends on the servo speed; 300ms is good value, but you can try lower it.
  // You MUST HAVE the SERVO_ENDSTOPS defined to use here a value higher than zero otherwise your code will not compile.

//  #define PROBE_SERVO_DEACTIVATION_DELAY 300

#endif

// Travel limits after homing
#define X_MAX_POS 170
#define X_MIN_POS 0
#define Y_MAX_POS 170
#define Y_MIN_POS 0
#define Z_MAX_POS 200

#ifndef ENABLE_AUTO_BED_LEVELING
#define Z_MIN_POS 0
#else
#define Z_MIN_POS (-1*Z_PROBE_OFFSET_FROM_EXTRUDER)  //With Auto Bed Leveling, the Z_MIN MUST have the same distance as Z_PROBE
#endif

#define X_MAX_LENGTH (X_MAX_POS - X_MIN_POS)
#define Y_MAX_LENGTH (Y_MAX_POS - Y_MIN_POS)
#define Z_MAX_LENGTH (Z_MAX_POS - Z_MIN_POS)

//// MOVEMENT SETTINGS
#define NUM_AXIS 4 // The axis order in all axis related arrays is X, Y, Z, E
//#define HOMING_FEEDRATE {50*60, 50*60, 4*60, 0}  // set the homing speeds (mm/min)
#define HOMING_FEEDRATE {45*60, 45*60, 3.5*60, 0}

// default settings
//
// #define DEFAULT_AXIS_STEPS_PER_UNIT   {78.7402,78.7402,200.0*8/3,760*1.1}  // default steps per unit for Ultimaker
// #define DEFAULT_MAX_FEEDRATE          {500, 500, 5, 25}    // (mm/sec)
// #define DEFAULT_MAX_ACCELERATION      {9000,9000,100,10000}    // X, Y, Z, E maximum start speed for accelerated moves. E default values are good for skeinforge 40+, for older versions raise them a lot.

// #define DEFAULT_ACCELERATION          3000    // X, Y, Z and E max acceleration in mm/s^2 for printing moves
// #define DEFAULT_RETRACT_ACCELERATION  3000   // X, Y, Z and E max acceleration in mm/s^2 for retracts


// 3DM1 settings

// note: following triffid guide for steps + decrease default speed and acceleration (http://reprap.org/wiki/Triffid_Hunter's_Calibration_Guide)

// x, y, z, e
//#define DEFAULT_AXIS_STEPS_PER_UNIT   {55.172,  55.172,  2560, 4000} // big pulleys
#define DEFAULT_AXIS_STEPS_PER_UNIT   {80,          80,  2560, 2500} // small pulleys
// #define DEFAULT_AXIS_STEPS_PER_UNIT   {80,80,2560,674.65217}  // default steps per unit for Ultimaker
#define DEFAULT_MAX_FEEDRATE          {300, 300, 5, 25}    // (mm/sec)
#define DEFAULT_MAX_ACCELERATION      {900, 900,100,10000}    // X, Y, Z, E maximum start speed for accelerated moves. E default values are good for skeinforge 40+, for older versions raise them a lot.

#define DEFAULT_ACCELERATION          600    // X, Y, Z and E max acceleration in mm/s^2 for printing moves
#define DEFAULT_RETRACT_ACCELERATION  600   // X, Y, Z and E max acceleration in mm/s^2 for retracts

// -------

// The speed change that does not require acceleration (i.e. the software might assume it can be done instantaneously)
#define DEFAULT_XYJERK                20.0    // (mm/sec)
#define DEFAULT_ZJERK                 0.4     // (mm/sec)
#define DEFAULT_EJERK                 5.0    // (mm/sec)

//===========================================================================
//=============================Additional Features===========================
//===========================================================================

// EEPROM
// the microcontroller can store settings in the EEPROM, e.g. max velocity...
// M500 - stores paramters in EEPROM
// M501 - reads parameters from EEPROM (if you need reset them after you changed them temporarily).
// M502 - reverts to the default "factory settings".  You still need to store them in EEPROM afterwards if you want to.
//define this to enable eeprom support


// Preheat Constants
#define PLA_PREHEAT_HOTEND_TEMP 180
#define PLA_PREHEAT_HPB_TEMP 70
#define PLA_PREHEAT_FAN_SPEED 255   // Insert Value between 0 and 255

#define ABS_PREHEAT_HOTEND_TEMP 240
#define ABS_PREHEAT_HPB_TEMP 100
#define ABS_PREHEAT_FAN_SPEED 255   // Insert Value between 0 and 255

// The MaKr3d Makr-Panel with graphic controller and SD support
// http://reprap.org/wiki/MaKr3d_MaKrPanel
//#define MAKRPANEL

// The RepRapWorld REPRAPWORLD_KEYPAD v1.1
// http://reprapworld.com/?products_details&products_id=202&cPath=1591_1626
//#define REPRAPWORLD_KEYPAD
//#define REPRAPWORLD_KEYPAD_MOVE_STEP 10.0 // how much should be moved when a key is pressed, eg 10.0 means 10mm per click


//automatic expansion
#if defined (MAKRPANEL)
 #define DOGLCD
 #define SDSUPPORT
 #define ULTIPANEL
 #define NEWPANEL
 #define DEFAULT_LCD_CONTRAST 17
#endif

#if defined(REPRAPWORLD_KEYPAD)
  #define NEWPANEL
  #define ULTIPANEL
#endif


// Increase the FAN pwm frequency. Removes the PWM noise but increases heating in the FET/Arduino
//#define FAST_PWM_FAN

// Use software PWM to drive the fan, as for the heaters. This uses a very low frequency
// which is not ass annoying as with the hardware PWM. On the other hand, if this frequency
// is too low, you should also increment SOFT_PWM_SCALE.
//#define FAN_SOFT_PWM

// Incrementing this by 1 will double the software PWM frequency,
// affecting heaters, and the fan if FAN_SOFT_PWM is enabled.
// However, control resolution will be halved for each increment;
// at zero value, there are 128 effective control positions.
#define SOFT_PWM_SCALE 0

// M240  Triggers a camera by emulating a Canon RC-1 Remote
// Data from: http://www.doc-diy.net/photo/rc-1_hacked/
// #define PHOTOGRAPH_PIN     23

// SF send wrong arc g-codes when using Arc Point as fillet procedure
//#define SF_ARC_FIX

// Support for the BariCUDA Paste Extruder.
//#define BARICUDA

/*********************************************************************\
* R/C SERVO support
* Sponsored by TrinityLabs, Reworked by codexmas
**********************************************************************/

// Number of servos
//
// If you select a configuration below, this will receive a default value and does not need to be set manually
// set it manually if you have more servos than extruders and wish to manually control some
// leaving it undefined or defining as 0 will disable the servo subsystem
// If unsure, leave commented / disabled
//
//#define NUM_SERVOS 3 // Servo index starts with 0 for M280 command

// Servo Endstops
//
// This allows for servo actuated endstops, primary usage is for the Z Axis to eliminate calibration or bed height changes.
// Use M206 command to correct for switch height offset to actual nozzle height. Store that setting with M500.
//
//#define SERVO_ENDSTOPS {-1, -1, 0} // Servo index for X, Y, Z. Disable with -1
//#define SERVO_ENDSTOP_ANGLES {0,0, 0,0, 70,0} // X,Y,Z Axis Extend and Retract angles

#include "Configuration_adv.h"
#include "thermistortables.h"

#endif //__CONFIGURATION_H
