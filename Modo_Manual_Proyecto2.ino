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

void setup() {
  // Conectar servos a sus pines
  for (int i = 0; i < 4; i++) {
    servos[i].attach(pinesServo[i]);
  }

  // Configurar pines de botones y LED
  pinMode(LED_MANUAL, OUTPUT);
  pinMode(BTN_MODO, INPUT);
  pinMode(BTN_SIGUIENTE, INPUT);
  pinMode(BTN_ANTERIOR, INPUT);

  digitalWrite(LED_MANUAL, HIGH); // Inicia en modo manual (LED encendido)

  // Iniciar comunicación serial
  Serial.begin(9600);
  Serial.println("== Brazo en modo MANUAL ==");
}

void loop() {
  // Cambiar entre modo manual y automático
  if (digitalRead(BTN_MODO)) {
    modoManual = !modoManual;  // Cambia de estado
    digitalWrite(LED_MANUAL, modoManual);  // Enciende o apaga el LED
    Serial.println(modoManual ? "\n== Modo MANUAL ==" : "\n== Modo AUTOMÁTICO ==");
    delay(300);  // Pequeña pausa para evitar rebotes
  }

  // Si está en modo manual, leer joysticks y mover servos
  if (modoManual) {
    for (int i = 0; i < 4; i++) {
      int angulo = map(analogRead(pinesJoy[i]), 0, 1023, 0, 180);
      servos[i].write(angulo);
    }
  }

  // Si está en automático y no se está moviendo, manejar botones
  else if (!moviendo) {
    if (digitalRead(BTN_SIGUIENTE)) {
      poseActual = (poseActual + 1) % NUM_POSES;  // Siguiente pose
      moverAPose(poseActual);
      delay(300);
    } else if (digitalRead(BTN_ANTERIOR)) {
      poseActual = (poseActual + NUM_POSES - 1) % NUM_POSES;  // Anterior
      moverAPose(poseActual);
      delay(300);
    }
  }
}

// Función para mover suavemente los servos a una pose
void moverAPose(byte indice) {
  moviendo = true;

  // Leer posición actual de los servos
  int actual[4];
  for (int i = 0; i < 4; i++) {
    actual[i] = servos[i].read();
  }

  // Mover paso a paso hasta llegar a la pose deseada
  while (true) {
    bool listo = true;
    for (int i = 0; i < 4; i++) {
      if (actual[i] < poses[indice][i]) actual[i]++;
      else if (actual[i] > poses[indice][i]) actual[i]--;
      else continue;

      listo = false;
      servos[i].write(actual[i]);
    }

    if (listo) break;  // Salir del bucle cuando todos los servos estén en posición
    delay(15);         // Esperar para hacer el movimiento más suave
  }

  moviendo = false;
}
