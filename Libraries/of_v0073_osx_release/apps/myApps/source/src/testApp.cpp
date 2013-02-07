#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);

    // we need GL_TEXTURE_2D for our models coords.
    ofDisableArbTex();
    
    
    mySquare.loadModel(150,150);
    mySquare2.loadModel(400,150);
    mySquare3.loadModel(650,150);
}

//--------------------------------------------------------------
void testApp::update(){
    
    //TODO:: Check what square is colliding with user, set isRotated for that square to true, than animate
    mySquare.animateModel();
    mySquare2.animateModel();
    mySquare3.animateModel();

    

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(50, 50, 50, 0);
    ofSetColor(255, 255, 255, 255);

    mySquare.drawModel();
    mySquare2.drawModel();
    mySquare3.drawModel();


  }

//--------------------------------------------------------------
void testApp::keyPressed(int key){
  

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
    mySquare.updateModel(y);
    mySquare2.updateModel(y);
    mySquare3.updateModel(y);

	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	//bAnimateMouse = false;

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}

