#pragma once

#include "ofMain.h"

#include "shmdata/writer.hpp"
#include "shmdata/reader.hpp"
#include "shmdata/console-logger.hpp"

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

	shared_ptr<shmdata::ConsoleLogger> logger;
	shared_ptr<shmdata::Writer> w;
	shared_ptr<shmdata::Reader> r;

	ofEasyCam cam;

	const int frameSize = frameWidth * frameHeight * 3;
};
