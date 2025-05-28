// PROYECTO #2 ELECTRONICA DIGITAL
// JAVIER MEDINA - 22124 & MIGUEL DONIS - 22993

#include <Servo.h>

// Pines de servos y joysticks
const byte pinesServo[] = {7, 6, 5, 4};
const byte pinesJoy[]   = {A0, A1, A2, A3};

// Pines de LED y botones
const byte LED_MANUAL   = 8;
const byte BTN_MODO     = 9;
const byte BTN_SIGUIENTE= 10;
const byte BTN_ANTERIOR = 11;

// Arreglo de 4 servos
Servo servos[4];

// Variables de control
bool modoManual = true;
bool moviendo = false;
byte poseActual = 0;

// Lista de poses automáticas (ángulos para los 4 servos)
const byte NUM_POSES = 5;
const int poses[NUM_POSES][4] = {
  {  0,  45,  90,  45},
  { 45,  90,  45,  90},
  { 90, 135,  90, 135},
  {135,  90, 135,  90},
  {180,  45,  90,  45}
};
