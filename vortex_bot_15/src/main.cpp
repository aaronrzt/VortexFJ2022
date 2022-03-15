/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\aaron                                            */
/*    Created:      Mon Mar 14 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------
/ Funciones para cambiar la posición del brazo
/
/ Up: Los brazos están hasta arriba (pose inicial para pasar la inspección)
/ Mid: Los brazos están a medias (a la altura de llevar el goal)
/ Down: Los brazos están hasta abajo (para poder meter las tenazas debajo del goal)
/
---------------------------------------------------------------------------*/

void up2down(bool wait)
{
  ArmMotorGroup.resetRotation();
  ArmMotorGroup.spinToPosition(285, deg, wait);
}

void down2up(bool wait)
{
  ArmMotorGroup.resetRotation();
  ArmMotorGroup.spinToPosition(-285, deg, wait);  
}

void up2mid(bool wait)
{
  ArmMotorGroup.resetRotation();
  ArmMotorGroup.spinToPosition(185, deg, wait);  
}

void mid2up(bool wait)
{
  ArmMotorGroup.resetRotation();
  ArmMotorGroup.spinToPosition(-185, deg, wait);
}

void mid2down(bool wait)
{
  ArmMotorGroup.resetRotation();
  ArmMotorGroup.spinToPosition(100, deg, wait);    
}

void down2mid(bool wait)
{
  ArmMotorGroup.resetRotation();
  ArmMotorGroup.spinToPosition(-100, deg, wait);
}

void closeHand(bool wait)
{
  HandMotor.spinToPosition(140, deg);
  HandMotor.stop(brakeType::hold);
}

void openHand(bool wait)
{
  HandMotor.spinToPosition(0, deg);
}
//-----------------------------------------------------------------------------

void runTests(void)
{
  down2mid(true);
  vexDelay(1000);
  mid2up(true);
  vexDelay(1000);
  up2mid(true);
  vexDelay(1000);
  mid2down(true);
  vexDelay(1000);
  down2up(true);
  vexDelay(1000);
  up2down(true);
  vexDelay(1000);

  //Test de drivetrain
  Drivetrain.turnFor(90,deg);
  vexDelay(1000);
  Drivetrain.turnFor(-90,deg);
  vexDelay(1000);
  Drivetrain.driveFor(forward, 30, distanceUnits::cm, true);
  vexDelay(1000);
  Drivetrain.driveFor(forward, -30, distanceUnits::cm, true);
}

void autonomous(void)
{
  // setDriveVelocity: Cambia la velocidad de manejo a un (cantidad, pct)
  // driveFor: Maneja una distancia de (cantidad, unidades_distancia)
  // turnFor: Gira el robot sobre su eje (cantidad, unidades_angulo)
  // x2y (down2mid, mid2down, etc.): Cambia la posición del brazo de x a y
  Drivetrain.setDriveVelocity(65, pct);
  
  
  //Ajuste de la velocidad de giro
  Drivetrain.setTurnVelocity(35, pct);
  
  runTests();

}

int main()
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // Etapa autónoma
  autonomous();
  
}
