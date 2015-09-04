#include "ofApp.h"
/* Begin description
{
    It's only a test
}
End description */

/* Snippet begin */
void ofApp::setup(){
    ofSetWindowShape(500, 500);
    gif.setupPaused(30, 80);
    gif.fadeInOut(5, 3, ofColor::black);

    numLayers = 2;
    masker.setup(numLayers, ISOLATE_LAYERS);
    masker.toggleOverlay();
    
    img1.setup("pcb-bw.png");
    img2.setup("test.png");
    
    numRects = 200;
    for(int i = 0; i < numRects; i++) {
        rectAlphaMultipliers.push_back(ofRandom(0.1, 0.3));
    }
    rectHeight = (gif.height / numRects) + 1;
    
    ofSetWindowShape(1200, 1200);
}

void ofApp::update(){
    masker.beginLayer(0);
    {
        ofBackground(ofColor::black);
        for(int i = 0; i < numRects; i++) {
            alpha = sin(ofGetFrameNum() * rectAlphaMultipliers.at(i));
            alpha = ofMap(alpha, -1, 1, -100, 255);
            if(alpha < 0) alpha = 0;
            ofSetColor(ofColor(ofColor::white, alpha));
            ofRect(0, i * rectHeight, gif.width, rectHeight);
        }
    }
    masker.endLayer(0);
    
    masker.beginMask(0);
    {
        ofBackground(ofColor::black);
        img1.incrementTextureOffsetY(-0.2);
        img1.draw();
    }
    masker.endMask(0);

    masker.beginLayer(1);
    {
        img1.draw();
    }
    masker.endLayer(1);
    
    masker.beginMask(1);
    {
        gif.rotateAroundCenter(90);
        masker.drawLayer(0, false);
    }
    masker.endMask(1);
}

void ofApp::draw(){
    gif.begin();
    {
        ofEnableAlphaBlending();
        ofBackground(ofColor::black);
        img2.draw();
        masker.draw();
    }
    gif.endCaptureDraw();
    masker.drawOverlay();
}
/* Snippet end */

void ofApp::keyPressed(int key){

}

void ofApp::keyReleased(int key){

}

void ofApp::mouseMoved(int x, int y){

}

void ofApp::mouseDragged(int x, int y, int button){

}

void ofApp::mousePressed(int x, int y, int button){

}

void ofApp::mouseReleased(int x, int y, int button){

}

void ofApp::windowResized(int w, int h){

}

void ofApp::gotMessage(ofMessage msg){

}

void ofApp::dragEvent(ofDragInfo dragInfo){

}