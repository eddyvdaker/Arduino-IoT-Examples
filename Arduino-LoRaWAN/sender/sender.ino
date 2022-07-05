#include <MKRWAN.h>

LoRaModem modem;

String appEui = "YOUR_APP_EUI";
String appKey = "YOUR_APP_KEY";

int counter = 0;

void setup() {
    Serial.begin(115200);

    if(!modem.begin(EU868)) {
	Serial.println("Failed to start LoRa");
	while(1) {}
    }
    Serial.print("Your module version is: ");
    Serial.println(modem.version());
    Serial.print("Your device EUI is: ");
    Serial.println(modem.deviceEUI());

    int connected = modem.joinOTAA(appEui, appKey);
    if (!connected) {
	Serial.println("Something went wrong");
	while(1) {}
    }

    modem.minPollInterval(60);	    // 60 is hardcoded minimum
}

void loop() {
    String msg = "Test message ";
    msg.concat(String(counter, DEC));
    counter++;

    int err;
    modem.beginPacket();
    modem.print(msg);
    err = modem.endPacket(true);
    if (err > 0) {
	Serial.println("Message send correctly");
    } else {
	Serial.println("Error sending message");
    }
    delay(60000);
}
