
const int LED_PIN = 13;
const int SENSOR_PIN = 2;
bool sensor; // Keep track of the current state of the sensor

void setup() {
    pinMode(SENSOR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
    sensor = false;
}

void loop() {
    if (Serial.available() > 0) {
        // Retrieve message sent by flask application through serial port
        String message = getMessage();

        if (message == "get") { // asks the arduino to return information about the sensor
            if (sensor) {
                Serial.println("Arduino: SENSOR IS ACTIVE");
            } else {
                Serial.println("Arduino: SENSOR ISN'T ACTIVE");
            }
        } else if (message == "led_on") { // Tells the arduino to turn on the led
            Serial.println("Arduino: LED ON");
            digitalWrite(LED_PIN, HIGH);
        } else if (message == "led_off") { // Tells the arduino to turn off the led
            Serial.println("Arduino: LED OFF");
            digitalWrite(LED_PIN, LOW);
        }
    } else {
        updateLED();
    }
    delay(100);
}

// Read Serial buffer until entire message is retrieved
String getMessage() {
    String readString = "";
    while (Serial.available() > 0) {
        char temp = Serial.read();
        readString += temp;
    }
    return readString;
}
// Update led based on sensor status
void updateLED() {
    if (digitalRead(2) == HIGH && sensor == false) {
        digitalWrite(LED_PIN, HIGH);
        sensor = true;
    } else if (digitalRead(2) == LOW && sensor == true) {
        digitalWrite(LED_PIN, LOW);
        sensor = false;
    }
}
