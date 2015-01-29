/* ============================================
MP3Player library code is placed under the MIT license
Copyright (c) 2015 Ankit Daftery

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
===============================================
*/


#include "MP3Player.h"
#include <Arduino.h>

void MP3Player::next(){
    trigger(next_pin);
    ++track_no;
}


void MP3Player::previous(){
    trigger(previous_pin);
    --track_no;
}
void MP3Player::volumeUp(){
    trigger(volumeup_pin);
}
void MP3Player::volumeDown(){
    trigger(volumedown_pin);
}
void MP3Player::play(){
    if(!isPlaying()) trigger(play_pin);
    playing = true;
}
void MP3Player::pause(){
    if(isPlaying()) trigger(play_pin);
    playing = false;
}

bool MP3Player::isPlaying(){
    return playing;
}
int MP3Player::currentTrack(){
    return track_no;
}

void MP3Player::gotoTrack(int n){

    if(n>track_no) {
        while(track_no<n) {
            next();
        }
    }
    else if(n<track_no) {
        while(track_no>n) {
            previous();
        }
    }
    else {
        next();
        previous();
    }

}

void MP3Player::trigger(int n) { 
    digitalWrite(n,HIGH);
    delay(150);
    digitalWrite(n,LOW);
}


void MP3Player::setTrackZero() {
    track_no = 0;
}

MP3Player::MP3Player(uint8_t play,uint8_t next, uint8_t previous, uint8_t volumeup, uint8_t volumedown){
    play_pin = play;
    next_pin = next;
    previous_pin = previous;
    volumeup_pin = volumeup;
    volumedown_pin= volumedown;
    pinMode(play_pin,OUTPUT);
    pinMode(next_pin,OUTPUT);
    pinMode(previous_pin,OUTPUT);
    pinMode(volumeup_pin,OUTPUT);
    pinMode(volumedown_pin,OUTPUT);
    playing = true;
}
