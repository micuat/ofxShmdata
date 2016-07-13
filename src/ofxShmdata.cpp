#include "ofxShmdata.h"

namespace ofxShmdata {
    string generateVideoMetadata(int width,
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
        return generateVideoMetadata(width, height, frameRate, formatType,
            aspectRatioW, aspectRatioH);
    }

    string generateVideoMetadata(int width,
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
}
