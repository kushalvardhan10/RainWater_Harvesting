#include <LiquidCrystal.h>
#include <Servo.h>

// Initialize the LCD library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo valveServo;

// Define pins
const int rainSensorPin = A0;
const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 6;

// Thresholds and other constants
const int rainThreshold = 500;
const int distanceThreshold = 20; // in cm

void setup() {
  pinMode(rainSensorPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  valveServo.attach(servoPin);
  lcd.begin(16, 2);
  valveServo.write(0); // start with valve closed
  Serial.begin(9600);

  lcd.print("Rain Harvesting");
  lcd.setCursor(0, 1);
  lcd.print("System");
  delay(2000);
  lcd.clear();
}

void loop() {
  int rainValue = analogRead(rainSensorPin);
  float distance = measureDistance();

  // Display sensor values
  lcd.setCursor(0, 0);
  lcd.print("Rain: ");
  lcd.print(rainValue);

  lcd.setCursor(0, 1);
  lcd.print("Level: ");
  lcd.print(distance);
  lcd.print(" cm   "); // overwrite old chars

  // Control valve based on conditions
  if (rainValue > rainThreshold && distance < distanceThreshold) {
    valveServo.write(90); // open valve
    lcd.setCursor(10, 1);
    lcd.print("Valve: OPEN ");
  } else {
    valveServo.write(0); // close valve
    lcd.setCursor(10, 1);
    lcd.print("Valve: CLOSE");
  }

  // Debugging output
  Serial.print("Rain Value: ");
  Serial.print(rainValue);
  Serial.print(" | Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000);
}

// Function to measure distance using ultrasonic sensor
float measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2; // convert to cm
}