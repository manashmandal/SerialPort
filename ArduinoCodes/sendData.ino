/*
 * Author: Manash Kumar Mandal
 * Example For sending data to SerialPort
 */

#define BAUD 9600
#define DELAY_TIME 100

const char* helloWorld = "Hello, world!";

void setup() {
  Serial.begin(BAUD);
}

void loop() {
  Serial.println(helloWorld);
  delay(DELAY_TIME);
}
