#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(800, 600);
	ofSetBackgroundColor(0);
	ofSetCircleResolution(40);

	joystick.setup(GLFW_JOYSTICK_1);
}

//--------------------------------------------------------------
void ofApp::update() {

	for (int i = 0; i < joystick.getButtonNum(); i++)
	{
		if (joystick.isPressed(i))
		{
			ofLog() << "pressed : " << i;
		}

		if (joystick.isPushing(i))
		{
			ofLog() << "pushing : " << i;
		}

		if (joystick.isRelease(i))
		{
			ofLog() << "released : " << i;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}
