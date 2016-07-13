#include "ofApp.h"


using namespace shmdata;

//--------------------------------------------------------------
void ofApp::setup(){
    shmWriter.setup("ofxShmdata-example", 640, 480);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    shmWriter.publishScreenBegin();
    cam.begin();
    ofBackground(50, 0, 0);
    ofSetColor(0, 200, 0);
    ofNoFill();
    ofDrawBox(100);
    cam.end();
    shmWriter.publishScreenEnd();

    ofSetColor(255);
    ofDrawBitmapString("Shmdata Writer Example", 20, 50);
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
