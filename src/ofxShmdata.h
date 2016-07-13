#include "ofMain.h"

#include "shmdata/writer.hpp"
#include "shmdata/reader.hpp"
#include "shmdata/console-logger.hpp"

namespace ofxShmdata {
    // Returns formatted descriptor string to initialize Writer
    string generateVideoDescriptor(int width,
        int height,
        int frameRate = 30,
        ofPixelFormat pixelFormat = OF_PIXELS_RGB,
        int aspectRatioW = 1,
        int aspectRatioH = 1);

    string generateVideoDescriptor(int width,
        int height,
        int frameRate,
        string formatType,
        int aspectRatioW = 1,
        int aspectRatioH = 1);

    void writeScreenToBuffer(ofBufferObject&);

    class ShmWriter{
    public:
        ShmWriter() {}
        void setup(string _name, int _width, int _height, int _frameRate = 30);
        void publishScreenBegin();
        void publishScreenEnd(bool drawOnScreen = true);
        // void publishBuffer(...);
    private:
        unique_ptr<shmdata::ConsoleLogger> logger;
    	unique_ptr<shmdata::Writer> writer;
        ofFbo screenFbo;
        ofPixels screenPixels;
        int width;
        int height;
        int frameRate;
        string name;
    };
}
