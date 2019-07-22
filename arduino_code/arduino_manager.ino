
const int LED_PIN = 13;
const int SENSOR_PIN = 2;
bool sensor;

void setup() {
    pinMode(SENSOR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
    sensor = false;
}

void loop() {
    if (Serial.available() > 0) {
        String message = getMessage();

        if (message == "get") {
            if (digitalRead(SENSOR_PIN) == HIGH) {
                Serial.println("Arduino: SENSOR IS TOUCHED");
            } else {
                Serial.println("Arduino: SENSOR ISN'T TOUCHED");
            }
        } else if (message == "led_on") {
            Serial.println("Arduino: LED ON");
            digitalWrite(LED_PIN, HIGH);
        } else if (message == "led_off") {
            Serial.println("Arduino: LED OFF");
            digitalWrite(LED_PIN, LOW);
        }
    } else {
        updateLED();
    }
    delay(50);
}

String getMessage() {
    String readString = "";
    while (Serial.available() > 0) {
        char temp = Serial.read();
        readString += temp;
    }
    return readString;
}

void updateLED() {
    if (digitalRead(2) == HIGH && sensor == false) {
        digitalWrite(LED_PIN, HIGH);
        sensor = true;
    } else if (digitalRead(2) == LOW && sensor == true) {
        digitalWrite(LED_PIN, LOW);
        sensor = false;
    }
}
