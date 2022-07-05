void setup() {
    Serial.begin(9600);
    Serial.println("start logging");
}

void loop() {
    Serial.println("log message");
    delay(1000);
}

