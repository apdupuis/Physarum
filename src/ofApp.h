#pragma once

#include "ofMain.h"
#include "..\Fungi.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		std::vector<ofFbo> fb_fbo;
		std::vector<ofPixels> fb_pix;
		std::vector<std::vector<Fungi>> fun_guys;
		int num_systems = 1;
		int num_fun_guys = 14000;
};
