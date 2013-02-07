#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){

    ofAppGlutWindow window;
    // can be OF_WINDOW or OF_FULLSCREEN
	ofSetupOpenGL(&window, 2024,1000, OF_WINDOW);			// <-------- setup the GL context
	ofRunApp( new testApp());

}
