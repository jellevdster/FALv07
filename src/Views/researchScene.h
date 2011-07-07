//
//  researchScene.h
//  mnhPrototype
//
//  Created by Stephen Varga on 6/23/11.
//  Copyright 2011 Potion. All rights reserved.
//

#pragma once
#include "ofMain.h"
#include "mnhBaseScene.h"
#include "baseButton.h"
#include "mnhBottomMenu.h"
#include "activityScene.h"
#include "ofxAssimpModelLoader.h"
#include "ofVboMesh.h"


enum {
    MNH_RESEARCH_SCENE_FIRST,
    MNH_RESEARCH_SCENE_SECOND,
    MNH_RESEARCH_SCENE_THIRD,
    MNH_RESEARCH_SCENE_FOURTH,
    MNH_RESEARCH_SCENE_FIFTH,
    MNH_RESEARCH_SCENE_SIX,
    MNH_RESEARCH_SCENE_SEVEN,
    MNH_RESEARCH_SCENE_TOTAL
};

enum traumaType {
    MNH_FAL_ANTEMORTEM1,
    MNH_FAL_ANTEMORTEM2,
    MNH_FAL_PERIMORTEM1,
    MNH_FAL_PERIMORTEM2,
    MNH_FAL_POSTMORTEM
};


class researchScene : public mnhBaseScene {
	public:
		void setup();
		void update();
		void draw();
    
        void activate();
        void deactivate();
       // bool notice();
        bool getnotice(bool A);
    
        void touchDown(ofTouchEventArgs &touch);
        void touchMoved(ofTouchEventArgs &touch);
        void touchUp(ofTouchEventArgs &touch);
        void touchDoubleTap(ofTouchEventArgs &touch);
    
    private:
        baseButton caseB;
        baseButton infoB;
        baseButton hintB;
        //set up back and restart button
        baseButton back;
        baseButton start;        
        baseButton anteB;
        baseButton periB;
        baseButton postB;
        baseButton backtoinfo;
        baseButton backtoact;
    

        ofImage researchScreen;
    
        //set up for subButton
        ofImage caseI;
        ofImage infoI;
        ofImage hintI;
        //set up for 3D button
        ofImage anteI;
        ofImage periI;
        ofImage postI;
        //set up for subscene
        ofImage caseP;
        ofImage infoP;
        ofImage hintP;
        ofImage anteP;
        ofImage periP;
        ofImage postP;        
        
        float touchID;

        bool reset;
        bool bFirstDoubleTap;
        bool bFirstRun;
        bool a;
    
        int bonescale;
        //try to track
        int location_at_act;

        baseButton swap;

        //model properties
        float modelXPos, modelYPos;
        float modelSpaceWidth;
        float normScale;
        ofPoint position;
        ofPoint scale;
        ofPoint sceneCenter;
        ofVboMesh mesh;
        ofMaterial material;
        ofTexture tex;
        ofLight light;  
        ofxAssimpModelLoader *boneModel;
        ofVec3f posCord;

        //arcball rotation properties    
        float theta;
        float epsilonTransform;
        float sphereRadius;
        float stopMomentum;

        ofVec3f prevSpherePt, currSpherePt;
        ofVec3f axis;
        ofVec3f firstPt;
        GLfloat modelMatrix[16];
        
        //funcitons
        ofVec3f screenToSphere(ofVec3f p);
        void matrixCapture();
        void init3DViewer(traumaType trauma);
        void initModelEnv();
        void initResearchScene();
        void loadModel(string filename);
        void removeModel();
        void drawModel();
    
        
};