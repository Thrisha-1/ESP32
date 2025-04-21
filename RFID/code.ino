#include <HardwareSerial.h>

HardwareSerial RFIDReader(2);  


#define LED1 25
#define LED2 26
#define LED3 2


String uid1 = "0002306949";
String uid2 = "0002312277";
String uid3 = "0002307809";

String scannedUID = "";

void setup() {
  Serial.begin(115200);
  RFIDReader.begin(9600, SERIAL_8N1, 16, 17);  

  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);

  Serial.println("📡 RFID Reader Ready...");
}

void loop() {
  if (RFIDReader.available()) {
    scannedUID = "";
    delay(100);

    while (RFIDReader.available()) {
      char ch = RFIDReader.read();
      if (isPrintable(ch)) {
        scannedUID += ch;
      }
    }

    scannedUID.trim();
    Serial.print("Scanned UID: ");
    Serial.println(scannedUID);

    if (scannedUID == uid1) {
      Serial.println(" UID1 Match: Blinking LED1 (GPIO 25)");
      blinkLED(LED1);
    } else if (scannedUID == uid2) {
      Serial.println(" UID2 Match: Blinking LED2 (GPIO 26)");
      blinkLED(LED2);
    } else if (scannedUID == uid3) {
      Serial.println(" UID3 Match: Blinking LED3 (GPIO 2)");
      blinkLED(LED3);
    } else {
      Serial.println(" Unknown UID. No LED action.");
    }
  }
}

void blinkLED(int pin) {
  digitalWrite(pin, HIGH);
  delay(500);
  digitalWrite(pin, LOW);
}
