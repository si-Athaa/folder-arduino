int yaksarigen = 7; 
long duration, cm;

void setup() {
  Serial.begin(9600);
}

void loop() {
  pinMode(yaksarigen, OUTPUT); 
  
  digitalWrite(yaksarigen, LOW);
  delayMicroseconds(2);
  
  digitalWrite(yaksarigen, HIGH);
  delayMicroseconds(5);
  
  digitalWrite(yaksarigen, LOW);

  pinMode(yaksarigen, INPUT);
  duration = pulseIn(yaksarigen, HIGH);

  cm = duration / 29 / 2;

  Serial.print("Jarak: ");
  Serial.print(cm);
  Serial.println(" cm");

  delay(100);
}
