#pragma once

#include "ofMain.h"
#include "ofxShmdata.h"

const int frameWidth = 640;
const int frameHeight = 480;

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

	unique_ptr<shmdata::ConsoleLogger> logger;
	unique_ptr<shmdata::Writer> w;
	unique_ptr<shmdata::Reader> r;

	ofEasyCam cam;

	const int frameSize = frameWidth * frameHeight * 3;
};
