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


#ifndef _MP3PLAYER_H_
#define _MP3PLAYER_H_

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class MP3Player {
    public:
    	MP3Player(uint8_t play,uint8_t next, uint8_t previous, uint8_t volumeup, uint8_t volumedown);
        void next();
        void previous();
        void volumeUp();
        void volumeDown();
        void play();
        void pause();
        bool isPlaying();
        int currentTrack();
        void gotoTrack(int);
        void setTrackZero();
    private:
    	int play_pin;
    	int next_pin;
    	int previous_pin;
    	int volumeup_pin;
    	int volumedown_pin;
    	int track_no;
    	bool playing;
    	void trigger(int);
};

#endif