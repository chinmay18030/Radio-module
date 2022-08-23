#include <nRF24L01.h>
#include <RF24.h>
#include <SPI.h>

RF24 radio(7,8); //CE, CSN pins to 7 and 8, can be connected anywhere
const byte adr[6] = "00001";

void setup() {
  radio.begin();
  radio.openWritingPipe(adr);
  radio.setPALevel(RF24_PA_MIN); 
  radio.stopListening();

}

void loop() {
  // put your main code here, to run repeatedly:
  const char text[] = "Hello World";
  radio.write(&text, sizeof(text));
  delay(1000);

}
