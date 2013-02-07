//
//  squareAnimator.cpp
//  assimpExample
//
//  Created by Desiree Melcer on 2013-02-07.
//
//

#include "squareAnimator.h"

void squareAnimator::loadModel() {
    
    if(square.loadModel("cubeBake.dae",true)){
        
        
        square.setAnimation(0);
    	square.setPosition(ofGetWidth()/2, ofGetHeight()/2 , 0);
        square.setScale(0.2, 0.2, 0.2);
    	//model.createLightsFromAiModel();
    	//model.disableTextures();
    	//model.disableMaterials();
        
    	mesh = square.getMesh(0);
    	position = square.getPosition();
    	normScale = square.getNormalizedScale();
        scale = square.getScale();
    	sceneCenter = square.getSceneCenter();
    	material = square.getMaterialForMesh(0);
        tex = square.getTextureForMesh(0);
    }
    
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
	glEnable(GL_DEPTH_TEST);
    
    //some model / light stuff
    glShadeModel(GL_SMOOTH);
    light.enable();
    ofEnableSeparateSpecularLight();
    
    
	bAnimate		= false;
	bAnimateMouse 	= false;
	animationTime	= 0.0;
    
};

void squareAnimator::updateModel(int y) {
   
    bAnimateMouse = true;
    animationTime = float(y)/float(ofGetWidth());
    
};

void squareAnimator::animateModel(){
    
    if( bAnimate ){
		animationTime += ofGetLastFrameTime();
		if( animationTime >= 1.0 ){
			animationTime = 0.0;
		}
	    square.setNormalizedTime(animationTime);
		mesh = square.getCurrentAnimatedMesh(0);
	}
    
    
	if( bAnimateMouse ){
	    square.setNormalizedTime(animationTime);
		mesh = square.getCurrentAnimatedMesh(0);
	}

};

void squareAnimator::drawModel(){
    ofPushMatrix();
    ofTranslate(square.getPosition().x+100, square.getPosition().y, 0);
    //ofRotate(-mouseX, 0, 1, 0);
    //ofScale(0.5, 0.5);
    ofTranslate(-square.getPosition().x, -square.getPosition().y, 0);
    
    square.drawFaces();
    
    ofPopMatrix();
    
};