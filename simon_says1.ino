// C++ code
//
int r = 0;
char game_start = 'f';

void setup()
{
  Serial.begin(9600);
  pinMode(A5, INPUT);
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(12, INPUT);
}

void loop()
{
  Serial.print("sensor: ");
  Serial.println(analogRead(A5));

  if (analogRead(A5) > 550) {
    game_start = 'f';
    while (game_start == 'f') {
      digitalWrite(13, HIGH);
      delay(200); // Wait for 200 millisecond(s)
      digitalWrite(13, LOW);
      digitalWrite(11, HIGH);
      delay(200); // Wait for 200 millisecond(s)
      digitalWrite(11, LOW);
      digitalWrite(9, HIGH);
      delay(200); // Wait for 200 millisecond(s)
      digitalWrite(9, LOW);
      if (digitalRead(12) == HIGH) {
        game_start = 't';
      }
    }
    game_start = 't';
    while (game_start == 't') {
      digitalWrite(13, LOW);
      digitalWrite(11, LOW);
      digitalWrite(9, LOW);
      r = random(1, 3 + 1);
      if (r == 1) {
        digitalWrite(13, HIGH);
        delay(1500); // Wait for 1500 millisecond(s) 
        digitalWrite(13, LOW);
      } else if (r == 2) {
          digitalWrite(11, HIGH);
          delay(1500);
      	  digitalWrite(11, LOW);
      } else {
          digitalWrite(9, HIGH);
          delay(1500);
          digitalWrite(9, LOW);
      }
      while ((digitalRead(12) == LOW) && (digitalRead(10) == LOW) && (digitalRead(8) == LOW)) {
        delay(100);
        if (((digitalRead(12) == HIGH) && (r == 1)) || ((digitalRead(10) == HIGH) && (r == 2))
          || ((digitalRead(8) == HIGH) && (r == 3))) {
          digitalWrite(13, HIGH);
          digitalWrite(11, HIGH);
          digitalWrite(9, HIGH);
          delay(1000);
          digitalWrite(13, LOW);
          digitalWrite(11, LOW);
          digitalWrite(9, LOW);
          delay(1000);
          digitalWrite(13, HIGH);
          digitalWrite(11, HIGH);
          digitalWrite(9, HIGH);
          delay(1000);
          digitalWrite(13, LOW);
          digitalWrite(11, LOW);
          digitalWrite(9, LOW);
          delay(1000);
          break;
        } else if ((digitalRead(10) == HIGH) || (digitalRead(8) == HIGH) || (digitalRead(12) == HIGH)) {
          digitalWrite(13, HIGH);
          delay(500);
          digitalWrite(13, LOW);
          delay(500);
          digitalWrite(13, HIGH);
          delay(500);
          digitalWrite(13, LOW);
          delay(1000);
          break;
        }
      } 
    }
  } else {
    digitalWrite(13, LOW);
    digitalWrite(11, LOW);
    digitalWrite(9, LOW);
  }
}