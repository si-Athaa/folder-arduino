int nepal=A4;
int nopal=A3;
int zakri=A2;
int haris=A1;
int harus=A0;

void setup()  {
pinMode(nepal, OUTPUT);
pinMode(nopal, OUTPUT);
pinMode(zakri, OUTPUT);
pinMode(haris, OUTPUT);
pinMode(harus, OUTPUT);
}

void loop()  {
  for (int a=0;  a<=255;a++)
  {
  analogWrite(harus,a);
  delay(8);
}

  for (int a=255;  a>=0;a--)
  {
  analogWrite(harus,a);
  delay(8);
}

  for (int b=0;  b<=255;b++)
  {
  analogWrite(haris,b);
  delay(8);
}

  for (int b=255;  b>=0;b--)
  {
  analogWrite(haris,b);
  delay(8);
}


  for (int c=0;  c<=255;c++)
  {
  analogWrite(zakri,c);
  delay(8);
}

  for (int c=255;  c>=0;c--)
  {
  analogWrite(zakri,c);
  delay(8);
}

for (int d=0;  d<=255;d++)
  {
  analogWrite(nopal,d);
  delay(8);
}

  for (int d=255;  d>=0;d--)
  {
  analogWrite(nopal,d);
  delay(8);
}

 for (int e=0;  e<=255;e++)
  {
  analogWrite(nepal,e);
  delay(8);
}

 for (int e=255;  e>=0;e--)
  {
  analogWrite(nepal,e);
  delay(8);
}
  delay(800);
}
