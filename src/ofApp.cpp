#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(800, 600);
	ofSetBackgroundColor(0);
	ofSetCircleResolution(40);

	joystick.setup(GLFW_JOYSTICK_1);

	fondo.load("fondo.wav");
	audio1.load("bruh.wav"); //Cargo el sonido

	fondo.setLoop(true);
	fondo.play(); //Le doy play en el setup para que suene siempre que la aplicación esté activa
}

//--------------------------------------------------------------
void ofApp::update()
{
	if (joystick.isPushing(0))
	{
		audio1.play(); //Activo el sonido
		audio1.setVolume(volumen); //Le seteo el volumen con la variable "volumen"
		ofSetColor(255, 0, 0);
	}
	else
	{
		ofSetColor(255);
	}

	ofSoundUpdate();

	float joyX = joystick.getAxis(0); //Devuelve la posición en X del analógico izquierdo
	float joyY = joystick.getAxis(1); //Devuelve la posición en Y del analógico izquierdo	
	//Los analógicos devuelven un valor entre -1 y 1.

	x = ofMap(joyX, -1, 1, ancho/2, ofGetWidth()-ancho/2);
	y = ofMap(joyY, -1, 1, alto/2, ofGetHeight()-alto/2);

	float _ancho = joystick.getAxis(2); //Devuelve la posición en X del analógico derecho
	float _alto = joystick.getAxis(3); //Devuelve la posición en Y del analógico derecho

	ancho = ofMap(_ancho, -1, 1, 1, 200);
	alto = ofMap(_alto, -1, 1, 200, 1);

	volumen = ofMap(alto, 200, 1, 1.0, 0.0); //Mapeo la variable "alto" (Que se controla con el analógico derecho) a 0-1 (Que es el volumen original del audio) y la guardo en "volumen" para despues usarla en el audio
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
