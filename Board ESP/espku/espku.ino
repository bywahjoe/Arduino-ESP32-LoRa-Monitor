#include <WiFi.h>
#include <SPI.h>
#include <LoRa.h>
#include <U8x8lib.h>

#include "pinku.h"
U8X8_SH1106_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  u8x8.begin();
  u8x8.setPowerSave(0);
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.drawString(5, 3, "SYSTEM");
  u8x8.drawString(4, 4, "BYWAHJOE");
  delay(2000);
  u8x8.clearDisplay();
  u8x8.drawString(0, 3, "+__ LORA UNP __+");
  u8x8.drawString(0, 5, "LISTENING....");
  delay(2000);

  LoRa.setPins(myss, myrst, mydio0);
  while (!Serial);
  Serial.println("Lora Receiver");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  };
}

void loop() {

  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  } else {
    waitData();
  }

  // put your main code here, to run repeatedly:

}
void waitData() {
  u8x8.setInverseFont(1);
  u8x8.drawString(0, 5, "LISTENING [][][]");
  u8x8.setInverseFont(0);
  u8x8.clearLine(5);
}
void kirimWeb(){
  
  
  
}
