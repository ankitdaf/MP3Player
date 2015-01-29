/* ============================================
MP3Player library code is placed under the MIT license
Copyright (c) 2015 Ankit Daftery

Example sketch demonstrating how to play/pause,
go to next track, show current Track number etc

This sketch manipulates the buttons available on
the MP3 player via a Relay.
===============================================
*/

#include <MP3Player.h>

MP3Player mp3 = MP3Player(7, 8, 9, 10, 11);
void setup() {
  Serial.begin(9600);
  delay(5000);
  Serial.println(mp3.currentTrack());  // put your main code here, to run repeatedly:


}

void loop() {
  mp3.next();
  Serial.println(mp3.currentTrack());  // put your main code here, to run repeatedly:
delay(10000);
mp3.gotoTrack(2);
  Serial.println(mp3.currentTrack());  // put your main code here, to run repeatedly:
delay(10000);
mp3.pause();
}
