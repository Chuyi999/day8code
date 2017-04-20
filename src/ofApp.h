#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        ofSoundPlayer song;
        int nBandsToGet;
    
    
    
    
    
    
    float avgSound;
    float* fftSmoothed;
    float *val;
   
    
    ofFbo fbo;
    ofColor color;
    
    double wavePhase;
    double pulsePhase;
    double sampleRate;
    
    float fallWiggle;
    
    int pxOffset = 2;
    int myX = 0;
    int myY = 0;
    int pyOffset = 2;
    
  



};


