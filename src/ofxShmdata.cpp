#include "ofxShmdata.h"

namespace ofxShmdata {
    string generateVideoDescriptor(int width,
        int height,
        int frameRate,
        ofPixelFormat pixelFormat,
        int aspectRatioW,
        int aspectRatioH)
    {
        string formatType;
        if(pixelFormat == OF_PIXELS_RGB) {
            formatType = "RGB";
        }
        else if(pixelFormat == OF_PIXELS_RGBA) {
            formatType = "RGBA";
        }
        else if(pixelFormat == OF_PIXELS_BGRA) {
            formatType = "BGRA";
        }
        else {
            ofLogError() << "Pixel type not supported";
        }
        return generateVideoDescriptor(width, height, frameRate, formatType,
            aspectRatioW, aspectRatioH);
    }

    string generateVideoDescriptor(int width,
        int height,
        int frameRate,
        string formatType,
        int aspectRatioW,
        int aspectRatioH)
    {
        return "video/x-raw, format=(string)" + formatType + ", " +
            "width=(int)" + ofToString(width) + ", " +
            "height=(int)" + ofToString(height) + ", " +
            "framerate=(fraction)" + ofToString(frameRate) + "/1, " +
            "pixel-aspect-ratio=(fraction)" +
            ofToString(aspectRatioW) + "/" + ofToString(aspectRatioH);
    }

    // write screen shot to buffer
    // result will be vertically fliped
    // usage:
    // {
    //     ofBufferObject buffer;
    //     ofxShmdata::writeScreenToBuffer(buffer);
    //     unsigned char * p = buffer.map<unsigned char>(GL_READ_ONLY);
    //     w->copy_to_shm(p, ofGetWidth() * ofGetHeight() * 3);
    // }
    void writeScreenToBuffer(ofBufferObject& buffer)
    {
        int numChannels = 3;
        int x = 0, y = 0;
    	buffer.allocate(ofGetWidth() * ofGetHeight() * numChannels, GL_STATIC_READ);
        // int sh = ofGetGLRenderer()->getViewportHeight();
    	// if(ofGetGLRenderer()->isVFlipped()){
    	// 	y = sh - y;
    	// 	y -= ofGetHeight(); // top, bottom issues
    	// }

    	buffer.bind(GL_PIXEL_PACK_BUFFER);
    	glReadPixels(x, y, ofGetWidth(), ofGetHeight(), GL_RGB, GL_UNSIGNED_BYTE, 0);
    	buffer.unbind(GL_PIXEL_PACK_BUFFER);
    	buffer.unmap();
    }

    void ShmWriter::setup(string _name, int _width, int _height, int _frameRate)
    {
        name = _name;
        width = _width;
        height = _height;
        frameRate = _frameRate;

        ofSetFrameRate(frameRate);

        logger = make_unique<shmdata::ConsoleLogger>();

        writer = make_unique<shmdata::Writer>("/tmp/" + name,
             width * height * 3,
             generateVideoDescriptor(width, height, frameRate),
             logger.get());
        assert(*w);

        screenFbo.allocate(width, height, GL_RGB);
        screenPixels.allocate(width, height, OF_IMAGE_COLOR);
    }

    void ShmWriter::publishScreenBegin()
    {
        screenFbo.begin();
    }

    void ShmWriter::publishScreenEnd(bool drawOnScreen)
    {
        screenFbo.end();
        screenFbo.readToPixels(screenPixels);
        writer->copy_to_shm(screenPixels.getData(), width * height * 3);

        if(drawOnScreen) {
            screenFbo.draw(0, 0, ofGetWidth(), ofGetHeight());
        }
    }
}
