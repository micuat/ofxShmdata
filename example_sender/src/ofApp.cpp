#include "ofApp.h"


using namespace shmdata;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    logger = make_unique<ConsoleLogger>();
    // direct access writer with one reader
    w = make_unique<Writer>("/tmp/ofxShmdata-example",
         ofGetWidth() * ofGetHeight() * 3,
         ofxShmdata::generateVideoMetadata(ofGetWidth(), ofGetHeight(), 30),
         logger.get());
    assert(*w);
    r = std::make_unique<Reader>("/tmp/check-shmdata",
         [](void *data, size_t size){
           //auto frame = static_cast<Frame *>(data);
           std::cout << "(direct access) new data for client "
                     //<< frame->count
                     << " (size " << size << ")"
                     << std::endl;
         },
         nullptr,
         nullptr,
         logger.get());
    assert(*r);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofBackground(50,0,0);
    ofSetColor(0,200,0);
    ofNoFill();
    ofDrawBox(100);
    cam.end();

    {
        ofBufferObject buffer;
        ofxShmdata::writeScreenToBuffer(buffer);
    	unsigned char * p = buffer.map<unsigned char>(GL_READ_ONLY);
        w->copy_to_shm(p, ofGetWidth() * ofGetHeight() * 3);

    	buffer.unmap();
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
    ofSetWindowShape(640, 480);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
