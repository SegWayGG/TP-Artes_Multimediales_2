#pragma once

#include "ofMain.h"
#include "ofxJoystick.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);

		ofxJoystick joystick;
		float x, y;
		float ancho, alto;

};
