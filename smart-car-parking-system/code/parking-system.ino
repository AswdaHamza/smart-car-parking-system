#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define trigPin1 8
#define echoPin1 9
#define trigPin2 10
#define echoPin2 11

Servo gateServo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

int slotCount = 4;

long readDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH) * 0.034 / 2;
}

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  gateServo.attach(3);
  gateServo.write(0); // Gate closed

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Smart Parking");
  lcd.setCursor(0, 1);
  lcd.print("System Ready...");
  delay(2000);
  lcd.clear();
}

void loop() {
  long dist1 = readDistance(trigPin1, echoPin1); // Entry
  long dist2 = readDistance(trigPin2, echoPin2); // Exit

  if (dist1 < 15 && slotCount > 0) {
    slotCount--;
    gateServo.write(90); // Open gate
    delay(3000);
    gateServo.write(0);  // Close gate
  }

  if (dist2 < 15 && slotCount < 4) {
    slotCount++;
    gateServo.write(90);
    delay(3000);
    gateServo.write(0);
  }

  lcd.setCursor(0, 0);
  lcd.print("Slots Available:");
  lcd.setCursor(0, 1);
  lcd.print("       ");
  lcd.setCursor(0, 1);
  lcd.print(slotCount);
  delay(1000);
}
