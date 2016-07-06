#include "ofApp.h"


using namespace shmdata;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    logger = make_shared<ConsoleLogger>();
    // direct access writer with one reader
    w = make_shared<Writer>("/tmp/check-shmdata",
         frameSize,
         "video/x-raw, format=(string)RGB, width=(int)" + ofToString(frameWidth) +
         ", height=(int)" + ofToString(frameHeight) +
         ", framerate=(fraction)30/1, pixel-aspect-ratio=(fraction)1/1",
         logger.get());
    assert(*w);
    r = make_shared<Reader>("/tmp/check-shmdata",
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
        int sh = ofGetGLRenderer()->getViewportHeight();
        int x = 0, y = 0;
    	ofBufferObject buffer;
    	buffer.allocate(frameSize, GL_STATIC_READ);
    	if(ofGetGLRenderer()->isVFlipped()){
    		y = sh - y;
    		y -= frameHeight; // top, bottom issues
    	}

    	buffer.bind(GL_PIXEL_PACK_BUFFER);
    	glReadPixels(x, y, frameWidth, frameHeight, GL_RGB, GL_UNSIGNED_BYTE, 0); // read the memory....
    	buffer.unbind(GL_PIXEL_PACK_BUFFER);
    	unsigned char * p = buffer.map<unsigned char>(GL_READ_ONLY);
        w->copy_to_shm(p, frameSize);

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

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
