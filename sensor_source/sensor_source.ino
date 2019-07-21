
const int LED_PIN = 13;
const int SENSOR_PIN = 2;

void setup() {
  pinMode(2, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(2) == HIGH) {
    Serial.println("Sensor Touched");
    digitalWrite(LED_PIN, HIGH);
  } else {
    Serial.println("Sensor not Touched");
    digitalWrite(LED_PIN, LOW);
  }
  delay(100);
}
