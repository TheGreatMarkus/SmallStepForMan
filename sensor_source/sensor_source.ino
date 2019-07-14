void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);

}

void loop() {
  if (digitalRead(2) == HIGH) {
    Serial.println("Sensor Touched");
  } else {
    Serial.println("Sensor not Touched");
  }
  delay(200);
}
