#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofEnableAntiAliasing();

	block = 40.0;
	seed = 70; //i liked this one the best
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(255);
	ofSeedRandom(seed);
	ofSetColor(0);

	//two for loops to make the grid
	for (int x = 70; x < 1470; x+=block)
	{
		for (int y = 70; y < 1470; y += block)
		{
			for (int i = 0; i < 12; i++) { //up to 3 overlapping long triangles/pairs
				if (ofRandom(1.0) > 0.8) {
					ofPushMatrix();
					ofTranslate(x, y);
					int numLines = floor(ofRandom(0, 12));
					bool l2r = floor(ofRandom(0.5, 1.5));
					bool single = floor(ofRandom(0.5, 1.5));
					ofRotateDeg(90*i);
					longTri(numLines, single, l2r);
					ofPopMatrix();
				}
			}
			for (int i = 0; i < 4; i++) { //try all 4 positions of the diagonal half block
				if (ofRandom(1.0) > 0.94) {
					bool single = floor(ofRandom(0.5, 1.5));
					bool l2r = floor(ofRandom(0.5, 1.5));
					int numLines = floor(ofRandom(0, 12));
					ofPushMatrix();
					ofTranslate(x, y);
					if (l2r)ofRotateDeg(90);
					halfTri(numLines, single);
					ofPopMatrix();
				}
			}
			for (int i = 0; i < 4; i++) { //try all 4 positions of the half diamond
				if (ofRandom(1.0) > 0.94) {
					ofPushMatrix();
					ofTranslate(x, y);
					int numLines = floor(ofRandom(0, 12));
					bool l2r = floor(ofRandom(0.5, 1.5));
					ofRotateDeg(90 * i);
					qtrTri(numLines, l2r);
					ofPopMatrix();
				}
			}
			if (ofRandom(1.0) > 0.99) { //sprinkle in some little webs
				ofPushMatrix();
				ofTranslate(x, y);
				int numLines = floor(ofRandom(5, 12));
				web(numLines);
				ofPopMatrix();
			}
			if (ofRandom(1.0) > 0.99) { //sprinkle in a few obtuse triangles
				ofPushMatrix();
				ofTranslate(x, y);
				int numLines = floor(ofRandom(5, 12));
				leaner(numLines);
				ofPopMatrix();
			}
		}
	}
}


//--------------------------------------------------------------
void ofApp::longTri(int numLines, bool single, bool l2r) {
	//flip a coin to do the top or bottom half
	bool top = true;
	bool bot = true;
	if (single) {
		float pick = ofRandom(1.0);
		if (pick < 0.5)
		{
			top = false;
		}
		else
		{
			bot = false;
		}
	}

	if (l2r) {
		//top diagonal l to r
		if (top) {
			for (int i = 0; i < numLines; i++)
			{
				ofDrawLine((block / -2) + (block / 2.0 / numLines * i), (block / -2), 0, (block / 2) - (block / numLines * i));
			}
		}
		//bottom diagonal l to r
		if (bot) {
			for (int i = 0; i < numLines; i++)
			{
				ofDrawLine((block / -2), (block / -2) + (block / numLines * i), (block / -2.0 / numLines * i), block / 2);
			}
		}
	} else {
	//top diagonal r to l
		if (top) {
			for (int i = 0; i < numLines; i++)
			{
				ofDrawLine((block / -2.0 / numLines * i), (block / -2), (block / -2), (block / 2) - (block / numLines * i));
			}
		}

	//bottom diagonal r to l
		if (bot) {
			for (int i = 0; i < numLines; i++)
			{
				ofDrawLine(0, (block / -2) + (i * block / numLines), (block / -2) + (block / 2.0 / numLines * i), block / 2);
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::halfTri(int numLines, bool single) {
	
	//flip a coin to do the top or bottom half
	bool top = true;
	bool bot = true;
	if (single) {
		float pick = ofRandom(1.0);
		if (pick < 0.5)
		{
			top = false;
		}
		else
		{
			bot = false;
		}
	}

		//top diagonal l to r
		if (top) {
			for (int i = 0; i < numLines; i++)
			{
				ofDrawLine((block / -2) + (block / numLines * i), (block / -2), (block / 2), (block / 2) - (block / numLines * i));
			}
		}
		//bottom diagonal l to r
		if (bot) {
			for (int i = 0; i < numLines; i++)
			{
				ofDrawLine((block / -2), (block / -2) + (block / numLines * i),(block/2)-(block / numLines * i), block / 2);
			}
		}

}

//--------------------------------------------------------------
void ofApp::qtrTri(int numLines, bool l2r) {

	//diagonal l to r
	if (l2r) {
		for (int i = 0; i < numLines; i++)
		{
			ofDrawLine((block / -2), (block / -2) + (block / numLines * i), (block / -2.0/numLines*i),  (block /2.0/ numLines * i));
		}
	}
	//diagonal r to l
	else {
		for (int i = 0; i < numLines; i++)
		{
			ofDrawLine((block / -2), (block / 2) - (block / numLines * i), (block /-2.0/ numLines * i), (block / -2.0 / numLines * i));
		}
	}

}

//--------------------------------------------------------------
void ofApp::web(int numLines) {

		for (int i = 0; i < numLines; i++)
		{
			ofDrawLine(-(block / numLines * i), (block / -2), (block / -2), (block / -2.0 / numLines * i));
			ofDrawLine(0, (block / -2)+(block / 2.0 / numLines * i), (block / -2)+(block / numLines * i), 0);
		}
}

//--------------------------------------------------------------
void ofApp::leaner(int numLines) {

	for (int i = 0; i < numLines; i++)
	{
		ofDrawLine((block/-2)+(block/numLines*i), block/2, block, 0);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//seed++;
	//cout<<seed<<endl;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}


