#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(800, 600);
	ofSetBackgroundColor(0);
	ofSetCircleResolution(40);

	joystick.setup(GLFW_JOYSTICK_1);
}

//--------------------------------------------------------------
void ofApp::update()
{
	if (joystick.isPushing(0))
	{
		ofSetColor(255, 0, 0);
	}
	else
	{
		ofSetColor(255);
	}

	float joyX = joystick.getAxis(0); //Devuelve la posici�n en X del anal�gico izquierdo
	float joyY = joystick.getAxis(1); //Devuelve la posici�n en Y del anal�gico izquierdo	
	//Los anal�gicos devuelven un valor entre -1 y 1.

	x = ofMap(joyX, -1, 1, ancho/2, ofGetWidth()-ancho/2);
	y = ofMap(joyY, -1, 1, alto/2, ofGetHeight()-alto/2);

	float _ancho = joystick.getAxis(2); //Devuelve la posici�n en X del anal�gico derecho
	float _alto = joystick.getAxis(3); //Devuelve la posici�n en Y del anal�gico derecho

	ancho = ofMap(_ancho, -1, 1, 1, 200);
	alto = ofMap(_alto, -1, 1, 200, 1);
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofDrawEllipse(x, y, ancho, alto);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}
