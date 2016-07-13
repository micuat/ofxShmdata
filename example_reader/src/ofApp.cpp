#include "ofApp.h"


using namespace shmdata;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    logger = make_unique<ConsoleLogger>();
    r = std::make_unique<Reader>("/tmp/ofxShmdata-example",
        [&](void *data, size_t size){
            frame.setFromPixels((unsigned char*)data, 640, 480, OF_IMAGE_COLOR);
            //ofLogError() << "received " << size << " bytes";
        },
        nullptr,
        nullptr,
        logger.get());
    frame.allocate(640, 480, OF_IMAGE_COLOR);
    assert(*r);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetColor(255);
    frame.update(); // should be updated here, not in the callback
    frame.draw(0, 0, 640, 480);
    ofDrawBitmapString("Shmdata Reader Example", 20, 50);
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
    ofSetWindowShape(640, 480);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
