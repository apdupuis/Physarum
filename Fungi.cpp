#include "Fungi.h"



Fungi::Fungi()
{
	lookup_distance = 1;
}


Fungi::~Fungi()
{
}

void Fungi::setPosition(ofVec2f pos_in)
{
	position = pos_in;
	previous_position = position;
}

void Fungi::setHeading(ofVec2f head_in)
{
	heading = head_in;
}

void Fungi::setPix(ofPixels * pix_ref)
{
	src_pix = pix_ref;
}

void Fungi::setColor(ofColor col_in)
{
	color = col_in;
}

void Fungi::setLookupDistance(float dist)
{
	lookup_distance = dist;
}

void Fungi::update()
{
	ofVec2f new_heading;
	float max_brightness = -1;

	// pick three points in front of the fungi 
	for (int i = 0; i < 5; i++) {
		float angle = (i - 2) * 20;
		ofVec2f heading_rotated = heading;
		heading_rotated.rotate(angle);
		ofVec2f heading_rotated_scaled = heading_rotated;
		heading_rotated_scaled.scale(lookup_distance);

		ofVec2f new_pos_temp = position + (heading_rotated_scaled * ofGetMouseX() / 30);
		new_pos_temp += ofVec2f(ofGetWidth(), ofGetHeight());
		new_pos_temp = ofVec2f(fmod(new_pos_temp.x, ofGetWidth()), fmod(new_pos_temp.y, ofGetHeight()) );

		ofColor c = src_pix->getColor(new_pos_temp.x, new_pos_temp.y);
		float brightness = 0.3 * c.r + 0.5 * c.g + 0.2 * c.b;
		//brightness = abs(fmod(brightness + 1, 250) - 1);
		if (brightness > 200) {
			brightness = 150 - brightness;
		}

		if (brightness < 0) brightness = 0;

		if (brightness > max_brightness || (brightness == max_brightness && angle == 0) ) {
			max_brightness = brightness;
			new_heading = heading_rotated;
		}
	}

	//cout << "heading " << heading.x << " " << heading.y << endl;
	ofVec2f new_pos = position + new_heading * ofGetMouseY() / 150;
	new_pos += ofVec2f(ofGetWidth(), ofGetHeight());
	new_pos = ofVec2f(fmod(new_pos.x, ofGetWidth()), fmod(new_pos.y, ofGetHeight()));

	previous_position = position;
	position = new_pos;
	heading = new_heading;
}

void Fungi::draw()
{
	ofPushStyle();
	ofSetColor(color);
	ofEnableBlendMode(OF_BLENDMODE_SCREEN);
	ofDrawCircle(position.x, position.y, 1);
	ofDisableBlendMode();

	ofVec2f pos_temp = position;
	ofVec2f heading_temp = heading;
	//heading_temp.rotate(90);

	float mult = 1.2;

	for (int i = 0; i < 0; i++) {
		//pos_temp += heading_temp * 5;
		pos_temp -= ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
		pos_temp *= mult;
		pos_temp += ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
		ofDrawCircle(pos_temp.x, pos_temp.y, 1);
	}
	


	//ofSetLineWidth(1);
	//ofDrawLine(position, previous_position);
	ofPopStyle();
}

void Fungi::print()
{
	cout << "position " << position.x << " " << position.y << endl;
}
