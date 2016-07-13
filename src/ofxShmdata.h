#include "ofMain.h"

#include <shmdata/writer.hpp>
#include <shmdata/reader.hpp>
#include <shmdata/abstract-logger.hpp>

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

    class ShmdataLogger : public shmdata::AbstractLogger {
    private:
         void on_error(std::string&& str) final { ofLog(OF_LOG_ERROR, str.c_str()); }
         void on_critical(std::string&& str) final { ofLog(OF_LOG_FATAL_ERROR, str.c_str()); }
         void on_warning(std::string&& str) final { ofLog(OF_LOG_WARNING, str.c_str()); }
         void on_message(std::string&& str) final { ofLog(OF_LOG_NOTICE, str.c_str()); }
         void on_info(std::string&& str) final { ofLog(OF_LOG_NOTICE, str.c_str()); }
         void on_debug(std::string&& str) final { ofLog(OF_LOG_VERBOSE, str.c_str()); }
    };

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

    class ShmReader{
    public:
        ShmReader() : imageTextureDirty(true), connected(false) {}
        void setup(string _name);
        void draw();
    //private:
        unique_ptr<shmdata::ConsoleLogger> logger;
    	unique_ptr<shmdata::Reader> reader;
    	ofImage frame;
        int width;
        int height;
        string name;
        int channels;
        bool imageTextureDirty;
        bool connected;
    };
}
