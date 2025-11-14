int alarmhazardbuzzer = 7;
int alarmhazardbutton = 8;
int alarmhazardbutton1 = 9;
int variebelnyaoranglain;
int variebelmati;
bool buzzerNyala = false;

void setup()
{
  pinMode(alarmhazardbuzzer, OUTPUT);
  pinMode(alarmhazardbutton, INPUT);
  pinMode(alarmhazardbutton1, INPUT);
}

void loop()
{
  variebelnyaoranglain = digitalRead(alarmhazardbutton);
  variebelmati = digitalRead(alarmhazardbutton1);

  if (variebelnyaoranglain == HIGH)
  {
    buzzerNyala = true;
  }

  if (variebelmati == HIGH)
  {
    buzzerNyala = false;
    noTone(alarmhazardbuzzer);
  }

  if (buzzerNyala == true)
  {
    for (int i = 200; i <= 800 && buzzerNyala == true; i++)
    {
      tone(alarmhazardbuzzer, i);
      delay(5);
      if (digitalRead(alarmhazardbutton1) == HIGH)
      {
        buzzerNyala = false;
        noTone(alarmhazardbuzzer);
        break;
      }
    }

    delay(4000);

    for (int i = 800; i >= 200 && buzzerNyala == true; i--)
    {
      tone(alarmhazardbuzzer, i);
      delay(10);
      if (digitalRead(alarmhazardbutton1) == HIGH)
      {
        buzzerNyala = false;
        noTone(alarmhazardbuzzer);
        break;
      }
    }
  }
  else
  {
    noTone(alarmhazardbuzzer);
  }
}
