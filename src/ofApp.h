#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void longTri(int numLines, bool single, bool l2r);
		void halfTri(int numLines, bool single);
		void qtrTri(int numLines, bool l2r);
		void web(int numLines);
		void leaner(int numLines);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );

		float block;
		int seed;
		
		
};
