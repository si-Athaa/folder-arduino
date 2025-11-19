#include <IRremote.h>

long ir_item;
int gibran=5;
int recvPin=2;
IRrecv irrecv(recvPin);
decode_results results;

long KEY_1=0xC09C7F8F;
long KEY_2=0x7887EEB5;
long KEY_3=0xEA2D2012;
long KEY_4=0xA13DA303;
long KEY_5=0x55579E2C;
long KEY_LONGkey=0xFFFFFFFF;
long longkey=1;

void setup() {
  pinMode(gibran, OUTPUT);
  irrecv.enableIRIn();
  Serial.begin(9600);

}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    Serial.println();
    irrecv.resume();
  }
  // the event of presssssssssing key wan
  if (results.value == KEY_1) {
    ledOn(gibran);
    longkey = KEY_1;
  }
  // the event of presssssssssing and HoLdInG key wan
  if (results.value == KEY_LONGkey && longkey == KEY_1) {
    ledOn(gibran);
  }

  if (results.value == KEY_2) {
    ledOff(gibran);
    longkey = KEY_2;
  }
  // the event of presssssssssing and HoLdInG key wan
  if (results.value == KEY_LONGkey && longkey == KEY_2) {
    ledOff(gibran);
  }
  //The ivent of pressing kiy tri
  if (results.value == KEY_3) {
    flash(gibran, 100, 100);
    longkey = KEY_3;
  }
  if (results.value == KEY_LONGkey && longkey == KEY_3) {
    flash(gibran, 100, 100);
  }
  if (results.value == KEY_4) {
    fadeOn(1000, 5);
    fadeOff(1000, 5);
       longkey = KEY_4;
  }
  if (results.value == KEY_LONGkey && longkey == KEY_4) {
    fadeOn(1000, 5);
    fadeOff(1000, 5);
  }
}

void ledOn(int gibran) {
  digitalWrite(gibran, HIGH);
}

void ledOff(int gibran) {
  digitalWrite(gibran, LOW);
}

void flash(int gibran, long highDuration, long lowDuration) {
  digitalWrite(gibran, HIGH);
  delay(highDuration);
  digitalWrite(gibran, LOW);
  delay(lowDuration);
}

void fadeOn(unsigned int time, int increament) {
  for (byte value = 0 ; value < 255; value += increament) {
    Serial.println(value);
    analogWrite(gibran, value);
    delay(time / (255 / 5));
  }
}
void fadeOff(unsigned int time, int decreament) {
  for (byte value = 255; value > 0; value -= decreament) {
    Serial.println(value);
    analogWrite(gibran, value);
    delay(time / (255 / 5));
  }
}
