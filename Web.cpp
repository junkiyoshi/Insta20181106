#include "Web.h"

//--------------------------------------------------------------
Web::Web() {

	this->location = ofPoint(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
	this->radius_start = 10;
	this->radius_max = floor(ofRandom(5, 10)) * 10;
	this->progress = ofRandom(1);
	this->life = 60;

	for (int deg = 0; deg < 360; deg += 30) {

		this->line_param.push_back(ofRandom(1, 2));
	}
}

//--------------------------------------------------------------
Web::~Web() {

}

//--------------------------------------------------------------
void Web::update() {

	if (this->progress > 1) {

		if (this->life-- < 0) {

			this->location = ofPoint(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
			this->radius_start = 10;
			this->radius_max = floor(ofRandom(5, 10)) * 10;
			this->progress = 0;
			this->life = 60;
		}
	}
	else {

		this->progress += 0.01;
	}
}

//--------------------------------------------------------------
void Web::draw() {

	ofPushMatrix();
	ofTranslate(this->location);

	ofSetColor(239, ofMap(this->life, 60, 0, 255, 0));

	int radius;
	for (radius = this->radius_start; radius < this->radius_max * this->progress; radius += 10) {

		ofBeginShape();
		for (int deg = 0; deg < 360; deg += 30) {

			ofVertex(ofPoint(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD)));
		}
		ofEndShape(true);
	}

	int i = 0;
	for (int deg = 0; deg < 360; deg += 30) {

		//ofDrawLine(ofPoint(), ofPoint(radius * this->line_param[i] * cos(deg * DEG_TO_RAD), radius * this->line_param[i] * sin(deg * DEG_TO_RAD)));
		ofDrawLine(ofPoint(), ofPoint(this->radius_max * this->line_param[i] * cos(deg * DEG_TO_RAD), this->radius_max * this->line_param[i] * sin(deg * DEG_TO_RAD)));
		i++;
	}

	ofPopMatrix();
}