#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	for (int i = 0; i < num_systems; i++) {
		ofFbo fbo;
		fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA_FLOAT16_ATI, 4);
		fbo.begin();
		ofClear(0);
		ofBackground(0);
		fbo.end();
		fb_fbo.push_back(fbo);

		ofPixels pix;
		fb_pix.push_back(pix);
	}
	
	for (int j = 0; j < num_systems; j++) {
		std::vector<Fungi> fun_vec;
		for (int i = 0; i < num_fun_guys; i++) {
			Fungi fun;
			fun.setPix(&fb_pix[j/2]);
			fun.setPosition(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())));
			ofVec2f heading = ofVec2f(((i % 1) * 7) + 1, 0);
			//ofVec2f heading = ofVec2f(((i % 2 * 5) + 1), 0);
			float lookup_dist = (i % 1) * 8 + 1;
			//if (j % 5 == 1) lookup_dist *= -0.3;
			fun.setLookupDistance(lookup_dist);
			heading.rotate(ofRandom(360));
			fun.setHeading(heading);
			ofColor c = ofColor(fmod((1.*(i + 100)), 255.), fmod((1.01*(i + 100)), 255.), fmod((1.02*(i + 100)), 255.));
			fun.setColor(c);
			fun_vec.push_back(fun);
		}
		fun_guys.push_back(fun_vec);
	}
}

//--------------------------------------------------------------
void ofApp::update(){

	for (int i = 0; i < num_systems; i++) {
		fb_fbo[i].readToPixels(fb_pix[i]);

		for (int j = 0; j < fun_guys[i].size(); j++) {
			fun_guys[i][j].update();
		}
	}

	
}

//--------------------------------------------------------------
void ofApp::draw(){

	for (int i = 0; i < num_systems; i++) {

		fb_fbo[i].begin();
		ofPushStyle();
		ofSetColor(0, 0, 0, 3);
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
		ofPopStyle();

		for (int j = 0; j < fun_guys[i].size(); j++) {
			fun_guys[i][j].draw();
		}

		fb_fbo[i].end();
	}

	ofSetColor(255);
	ofBackground(0);
	for (int i = 0; i < num_systems; i++) {
		fb_fbo[i].draw(0, 0);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
