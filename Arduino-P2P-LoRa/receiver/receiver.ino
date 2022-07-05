#include <LoRa.h>

void setup() {
    Serial.begin(9600);

    if (!LoRa.begin(868E6)) {
	Serial.println("Failed to initialize LoRa");
	while(1);
    }
}

void loop() {
    int packetSize = LoRa.parsePacket();
    if (packetSize) {
	Serial.print("LoRa-Message: ");
	while (LoRa.available()) {
	    Serial.print((char)LoRa.read());
	}
    }
}
