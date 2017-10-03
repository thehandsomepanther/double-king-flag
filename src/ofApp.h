#pragma once

#include "ofMain.h"
#include <deque>
#include <stdlib.h>
#include <math.h>
#include <iostream>

struct acceleration {
    float x;
    float y;
};

struct velocity {
    float x;
    float y;
} velocity;

struct position {
    float x;
    float y;
};

struct circle {
    struct position pos;
    struct velocity v;
    struct acceleration a;
    float radius;
};

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
		
        std::deque<circle> topCircles;
        std::deque<circle> bottomCircles;
};
