//
//  squareAnimator.h
//  assimpExample
//
//  Created by Desiree Melcer on 2013-02-07.
//
//

#ifndef __assimpExample__squareAnimator__
#define __assimpExample__squareAnimator__

#include <iostream>
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "ofVboMesh.h"


#endif /* defined(__assimpExample__squareAnimator__) */

class squareAnimator {
public:
    void loadModel(float xPosition, float yPosition);
    void updateModel(int y);
    void drawModel();
    void animateModel();
    
    ofxAssimpModelLoader square;
    float xPos;
    float yPos;
    float zPos;
    bool isRotated;
    
    bool bAnimate;
    bool bAnimateMouse;
    float animationTime;
    
    ofVboMesh mesh;
    ofPoint position;
    float normScale;
    ofPoint scale;
    ofPoint sceneCenter;
    ofMaterial material;
    ofTexture tex;
    ofLight	light;
    
};