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
}
