#pragma once
#include "ofMain.h"

class Web {

public:

	Web();
	~Web();
	void update();
	void draw();

private:

	ofPoint location;
	int radius_max;
	int radius_start;
	float progress;
	int life;
	vector<float> line_param;
};