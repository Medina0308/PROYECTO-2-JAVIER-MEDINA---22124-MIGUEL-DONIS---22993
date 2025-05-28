# 🤖 Brazo Robótico con Arduino – Modo Manual y Automático

Este proyecto controla un brazo robótico de 4 servos utilizando un Arduino. El sistema tiene dos modos de operación: manual (mediante joysticks) y automático (cambia entre poses predefinidas).

---

## 📦 Características

- Control manual de 4 servos con joysticks.
- 5 poses automáticas preprogramadas.
- Botón para cambiar de modo (Manual ↔ Automático).
- Botones para avanzar o retroceder entre poses.
- Movimiento suave de servos en modo automático.
- LED indicador de modo manual.

---

## 🔧 Materiales necesarios

- 1 × Arduino UNO 
- 4 × Servos (SG90 o similares)
- 2 × Joysticks
- 3 × Botones
- 1 × LED + Resistencia
- Jumpers y protoboard

---

## ⚙️ Conexiones

| Componente       | Pin Arduino     |
|------------------|-----------------|
| Servo 1          | 7               |
| Servo 2          | 6               |
| Servo 3          | 5               |
| Servo 4          | 4               |
| Joystick 1       | A0 & A1         |
| Potenciómetro 3  | A2 & A3         |
| Botón MODO       | 9               |
| Botón SIGUIENTE  | 10              |
| Botón ANTERIOR   | 11              |
| LED MODO MANUAL  | 8               |

---

## 🧠 ¿Cómo funciona?

### Modo Manual
- El usuario controla cada servo con unos joysticks.
- El LED de modo manual está encendido.
- Ideal para calibrar el brazo o moverlo libremente.

### Modo Automático
- Al presionar el botón MODO, se activa este modo.
- Los botones SIGUIENTE y ANTERIOR cambian entre 5 poses predefinidas.
- El brazo se mueve suavemente a la nueva pose.

---

## ▶️ Cómo usar

1. Sube el código al Arduino desde el archivo `.ino`.
2. Abre el Monitor Serial (opcional) para ver los estados.
3. Usa el botón MODO para alternar entre modos.
4. Controla los servos con joysticks (manual) o cambia de pose con los botones (automático).

---

## 📁 Estructura del código

- `setup()`: configura los pines, servos y comunicación serial.
- `loop()`: gestiona el modo de operación y la lectura de botones.
- `moverAPose()`: mueve los servos suavemente a una pose específica.
- `poses[]`: matriz que define 5 poses distintas para el brazo.

---


## 🧪 Créditos y agradecimientos

Proyecto desarrollado como práctica de control de servos y lógica digital con Arduino.

---

## ⚠️ Licencia

Este proyecto se puede usar con fines educativos y personales.
