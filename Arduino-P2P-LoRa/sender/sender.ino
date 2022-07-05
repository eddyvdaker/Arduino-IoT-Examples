#include <LoRa.h>

int counter = 0;

void setup() {
    Serial.begin(9600);

    if (!LoRa.begin(868E6)) {
	Serial.println("Starting LoRa failed");
	while(1);
    }
}

void loop() {
    String line = String("Counter: ");
    line.concat(String(counter));
    counter++;

    LoRa.beginPacket();
    LoRa.print(line);
    LoRa.endPacket();

    delay(1000);
}
