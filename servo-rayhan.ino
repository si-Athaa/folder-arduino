#include <Servo.h>

Servo myServo;

const int buttonOn  = 8;
const int buttonOff = 9;

bool running = false;    // Status servo (jalan atau mati)
int angle = 0;           // Posisi awal
int stepVal = 2;         // Kecepatan gerak (2° per loop)

void setup() {
  myServo.attach(7);
  pinMode(buttonOn, INPUT);   // Karena rangkaian pakai pull-down resistor
  pinMode(buttonOff, INPUT);

  myServo.write(0);           // Start diem
}

void loop() {

  // ==== ON DITEKAN → START SERVO GERAK BOLAK-BALIK ====
  if (digitalRead(buttonOn) == HIGH) {
    running = true;
    delay(200);
  }

  // ==== OFF DITEKAN → STOP ====
  if (digitalRead(buttonOff) == HIGH) {
    running = false;
    myServo.write(angle);  // servo berhenti di posisi terakhir
    delay(200);
  }

  // ==== JIKA RUNNING ====
  if (running) {
    myServo.write(angle);   // gerak servo

    angle += stepVal;       // tambah/kurangi sudut

    // Balik arah kalau sampai ujung
    if (angle >= 180 || angle <= 0) {
      stepVal = -stepVal;
    }

    delay(15);  // smooth gerak
  }
}
