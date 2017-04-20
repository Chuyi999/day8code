#include "ofApp.h"

float x, y, angle = 0;
//--------------------------------------------------------------
void ofApp::setup(){
    
   
    song.load("1.mp3");
    while(!song.isLoaded());
    song.play();
    nBandsToGet = 300;
    
    
    
    
    fftSmoothed = new float[8192];
    for (int i = 0; i < 8192; i++){
        fftSmoothed[i] = 0;
    }
    
    val = ofSoundGetSpectrum(nBandsToGet);// request 6 values for fft
    for (int i = 0;i < nBandsToGet; i++){
        fftSmoothed[i] *= 0.96f;
        if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
    }
    
    fallWiggle = 0;
    
    
    
    
    
    song.play();
    
    
   
     
}
float *val;

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSoundUpdate();
    val = ofSoundGetSpectrum(nBandsToGet);
    for (int i = 0;i < nBandsToGet; i++){
        fftSmoothed[i] *= 0.96f;
        if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
    }
      val = ofSoundGetSpectrum(nBandsToGet);
     ofBackground(0,fftSmoothed[1]*100,57);
    
    for (int i = 0;i < nBandsToGet; i++){
        
        // let the smoothed value sink to zero:
        fftSmoothed[i] *= 1.56f;
        
        // take the max, either the smoothed or the incoming:
        if (fftSmoothed[i] > val[i]) fftSmoothed[i] = val[i];
//        if (myX > ofGetWidth()-100 || myX < 0) {
//            pxOffset *= -1;  // changes the sign of the number
//        }
//        
//        myX += (fftSmoothed[i]/300)*pxOffset;  // change our x location
//        if (myY > ofGetHeight()-100 || myY < 0) {
//            pyOffset *= -1;  // changes the sign of the number
//        }
//        
//        myY += 1*pyOffset;  // change our x location
        

        
    }
    float time = ofGetElapsedTimef() ;
    
    fallWiggle +=  ofSignedNoise(time * 0.6);

    
    
   }

float getX(int deg,int radius){

    float x = radius * cos(ofDegToRad(deg))+ofGetWidth()/2;
    return(x);
}

float getY(int deg,int radius){
    
    float y = radius * sin(ofDegToRad(deg))+ofGetHeight()/2;
    return(y);
}


//--------------------------------------------------------------
void ofApp::draw(){
    int r = 150;
   
    //ofRotate(ofRandom(0,40));
    
    
    for ( int i = 0; i <360; i ++){

//        ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, (-1 * val[i])*600);
////        ofRotate(45);
//        ofSetColor(0);
//        ofNoFill();
        ofSetColor(255,199,21);
        cout<<val[i]<<endl;

//
            ofFill();
            ofDrawCircle(ofGetWindowWidth()/2+i*50,ofGetWindowHeight()/2, (1*val[i])*30);
            ofDrawCircle(ofGetWindowWidth()/2-i*50,ofGetWindowHeight()/2, (1*val[i])*30);

//        if(val[i]>0.5){
                float x1 = getX(i,r);
                float y1 = getY(i,r);
                ofSetColor(255,199,21);
                ofDrawCircle(x1, y1,fftSmoothed[i/10]*30);
//        }
    
        //ofDrawRectangle(ofGetWidth()/2, ofGetHeight()/2, 30, (-1 * val[i])*600);
    }
    
    
    
    for ( int i = 0; i <nBandsToGet/2; i ++){
        
        
        int modValue = myX % 100;                             // our X location modulo 100
        int colorChange = ofMap (modValue, 0, 99, -200, 200); // map it to desired range
        int absCC = abs (colorChange);                        // use the absolute value
        
        ofSetColor(255);
              //ofDrawCircle(myX, myY/2, 10);
    

        
//        if(val[i]>0.005){
//        ofDrawCircle(fallWiggle * 3 + ofGetWidth()/2, fallWiggle + ofGetHeight()/2, 50);
//        }
//        cout<<val[i]<<endl;
        
        int radius = 100;  // because we are working w a normalized (unit) circle that is <= 1
        // cos & sin take RADIANS.
        // 2pi radians would be 2 x 57.2958 x 3.1416 = 360 degrees
        // Therefore to draw a whole circle you would use 0-TWO_PI to draw a whole circle
        x = radius * cos( ofDegToRad(angle*i) ) + ofGetWidth()/2;
        y = radius * sin( ofDegToRad(angle*i) ) + ofGetHeight()/2;
        
        angle += 1;
        if (angle >= 360) angle = 0; //TWO_PI
        
        // do this one last
//        ofSetColor(255, 0, 0);
//        ofDrawCircle(x, y, 20);
        for(int j=0; j <50; j++){
        ofSetColor(0, 255, 30);
       ofDrawCircle(0+j*90, y, (1*fftSmoothed[i])*10);
//            cout<<i<<endl;// sin only
        }

    
    }

    }
        


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
