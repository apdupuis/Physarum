#pragma once

#include "ofMain.h"

class Fungi
{
public:
	Fungi();
	~Fungi();

	void setPosition(ofVec2f pos_in);
	void setHeading(ofVec2f head_in);
	void setPix(ofPixels* pix_ref);
	void setColor(ofColor col_in);
	void setLookupDistance(float dist);
	void update();
	void draw();
	void print();

private:
	ofVec2f position;
	float lookup_distance;
	ofVec2f previous_position;
	ofVec2f heading;
	ofPixels* src_pix;
	ofColor color;
};

