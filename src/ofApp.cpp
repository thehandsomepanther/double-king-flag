#include "ofApp.h"

using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255,255,255);
    ofSetFrameRate(60);
    
    int numCircles = 4;
    int minRadius = 20;
    int maxRadius = 40;
    int distBetweenCircles = 60;
    
    int topCirclesBaseline = 150;
    int bottomCirclesBaseline = 250;
    
    for (int i = 0; i < numCircles * 2; ++i) {
        struct circle c;
        struct position p;
        
        p.x = distBetweenCircles * i + 100;
        p.y = i % 2 == 0 ? rand() % topCirclesBaseline + 50 : rand() % bottomCirclesBaseline + topCirclesBaseline;
        
        if (i < 2) {
            c.radius = rand() % maxRadius + minRadius;
            c.pos = p;
        } else {
            bool colliding = true;
            while (colliding) {
                struct circle lastCircle = i % 2 == 0 ? topCircles[i-1] : bottomCircles[i-1];
            
                c.radius = rand() % (maxRadius - minRadius) + minRadius;
                c.pos = p;
                
                colliding = ofDist(lastCircle.pos.x, lastCircle.pos.y, c.pos.x, c.pos.y) < lastCircle.radius + c.radius;
            }
        }
        
        struct velocity v;
        v.x = 50.;
        v.y = 0.;
        
        struct acceleration a;
        a.x = 0.;
        a.y = 0.;
        
        c.v = v;
        c.a = a;
        
        if (i % 2 == 0) {
            topCircles.push_front(c);
        } else {
            bottomCircles.push_front(c);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofNoFill();
    ofSetHexColor(0xe0be21);
    for (int i = 0; i < topCircles.size(); ++i) {
        struct circle c = topCircles[i];
        ofDrawCircle(c.pos.x, c.pos.y, c.radius);
    }
    
    ofSetHexColor(0x000000);
    for (int i = 0; i < bottomCircles.size(); ++i) {
        struct circle c = bottomCircles[i];
        ofDrawCircle(c.pos.x, c.pos.y, c.radius);
    }
    
    ofSetHexColor(0x002fa7);
    ofBeginShape();
    
    struct circle c = bottomCircles[0];
    ofCurveVertex(c.pos.x, c.pos.y + c.radius);
    for (int i = 0; i < topCircles.size() * 2; ++i) {
        if (i % 2 == 0) {
            struct circle c = bottomCircles[i/2];
            ofCurveVertex(c.pos.x, c.pos.y + c.radius);
        } else {
            struct circle c = topCircles[i/2];
            ofCurveVertex(c.pos.x, c.pos.y - c.radius);
        }
    }
    c = topCircles[topCircles.size() - 1];
    ofCurveVertex(c.pos.x, c.pos.y - c.radius);
    ofEndShape(false);
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
