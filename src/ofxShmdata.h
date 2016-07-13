#include "ofMain.h"

#include "shmdata/writer.hpp"
#include "shmdata/reader.hpp"
#include "shmdata/console-logger.hpp"

namespace ofxShmdata {
    // Returns formatted metadata string to initialize Writer
    string generateVideoMetadata(int width,
        int height,
        int frameRate = 30,
        ofPixelFormat pixelFormat = OF_PIXELS_RGB,
        int aspectRatioW = 1,
        int aspectRatioH = 1);

    string generateVideoMetadata(int width,
        int height,
        int frameRate,
        string formatType,
        int aspectRatioW = 1,
        int aspectRatioH = 1);
}
