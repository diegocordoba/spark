//
//  squareAnimator.cpp
//  assimpExample
//
//  Created by Desiree Melcer on 2013-02-07.
//
//

#include "squareAnimator.h"

void squareAnimator::loadModel(float xPosition, float yPosition) {
    
    if(square.loadModel("cubeBake.dae",true)){
        
        square.setAnimation(0);
    	square.setPosition(xPosition, yPosition , 0);
        square.setScale(0.5, 0.5, 0.5);
    	//model.createLightsFromAiModel();
    	//model.disableTextures();
    	//model.disableMaterials();
        
    	mesh = square.getMesh(0);
        xPos = square.getPosition().x;
        yPos= square.getPosition().y;
        zPos = square.getPosition().z;
        
        
        printf("%f, %f, %f", xPos, yPos, zPos);
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
    
     //TODO:: Figure out sub animations - four little squares
    
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
     ofTranslate(-square.getPosition().x, -square.getPosition().y, 0);
     square.drawFaces();
    ofPopMatrix();
    
};