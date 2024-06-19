#include <LiquidCrystal.h>
LiquidCrystal lcd(11, 10, 9, 8, 7, 6);
#include <NewPing.h>

#define TRIGGER_PIN 13
#define ECHO_PIN 12
NewPing ultrasonic(TRIGGER_PIN, ECHO_PIN);

#define ledaman 2
#define led1 3
#define led2 4
#define led3 5

int z = 0;
int y = 500;
long distance;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Fahmi Tri Ramadhani");
  lcd.setCursor(0, 1);
  lcd.print("2108096086");
  delay(200);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pengukuran");
  lcd.setCursor(0, 1);
  lcd.print("Ketinggian Air");
  Serial.begin(9600);
  pinMode(ledaman, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  delay(600);
  lcd.clear();
}

void loop() {
  delay(100);
  distance = ultrasonic.ping_cm();
  Serial.print("Hasil Sensor : ");
  Serial.print(distance);
  Serial.print(" cm");
  Serial.print(" ");
  z = y - distance;
  lcd.setCursor(0, 0); lcd.print("Ketinggian Air");
  lcd.setCursor(0, 1); lcd.print("Tinggi :"); lcd.print(z);
  lcd.setCursor(14, 1); lcd.print("Cm");

  if ((z <= 200) && (z > 0)) {
    digitalWrite(ledaman, HIGH);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(200);
  } else if ((z <= 300) && (z > 200)) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(ledaman, LOW);
    delay(200);
  } else if ((z <= 450) && (z >= 350)) {
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(ledaman, LOW);
    delay(200);
  } else if (z > 450) {
    digitalWrite(led3, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(ledaman, LOW);
    delay(200);
  }
}
