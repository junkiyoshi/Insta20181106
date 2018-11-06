#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(39);
	ofNoFill();

	for (int i = 0; i < 8; i++) {

		this->webs.push_back(Web());
	}
}
//--------------------------------------------------------------
void ofApp::update() {

	for (Web& web : this->webs) { web.update(); }
}

//--------------------------------------------------------------
void ofApp::draw() {

	for (Web& web : this->webs) { web.draw(); }
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}