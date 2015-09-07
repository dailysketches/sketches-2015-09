#include "ofApp.h"
/* Begin description
{
    Blockage.
}
End description */

/* Snippet begin */
void ofApp::setup(){
    ofSetWindowShape(500, 500);
    gif.setup(54);
    masker.setup(2);
    img1.setup("foil1.png");
    img2.setup("glass3.png");
    img3.setup("foil1.png");
    img4.setup("glass1-inverted.png");
    img5.setup("glass1-inverted.png");

    masker.toggleOverlay();
    ofSetWindowShape(1200, 1200);
}

void ofApp::update(){
    if(ofGetFrameNum() % 18 == 0) {
        img2.setTextureOffset(ofRandom(2), ofRandom(2));
        img2.setTextureScale(3);
    }
    if(ofGetFrameNum() % 6 == 0) {
        img1.setTexturePosition(ofRandom(2), ofRandom(2));
        img1.setTextureScale(2);
        img3.setTexturePosition(ofRandom(2), ofRandom(2));
        img3.setTextureScale(2);
        img4.setTexturePosition(ofRandom(2), ofRandom(2));
        img4.setTextureScale(ofRandom(1.0, 6.0));
        img5.setTexturePosition(ofRandom(2), ofRandom(2));
        img5.setTextureScale(ofRandom(1.0, 6.0));
    }
    
    masker.beginLayer(0);
    {
        img1.incrementTextureOffsetX(0.01);
        img1.incrementTextureScale(0.05);
        ofSetColor(ofColor(106, 68, 71));
        img1.draw();
    }
    masker.endLayer(0);
    
    masker.beginMask(0);
    {
        img4.incrementTextureOffsetY(0.04);
        img4.incrementTextureScale(0.84);
        ofBackground(ofColor::white);
        ofSetColor(ofColor(ofColor::white, 200));
        img4.draw();
    }
    masker.endMask(0);

    masker.beginLayer(1);
    {
        img3.incrementTextureOffsetX(-0.01);
        img3.incrementTextureScale(-0.033);
        ofSetColor(ofColor(106, 68, 71));
        img3.draw();
    }
    masker.endLayer(1);
    
    masker.beginMask(1);
    {
        img5.incrementTextureOffsetY(-0.01);
        img5.incrementTextureScale(0.25);
        ofBackground(ofColor::white);
        ofSetColor(ofColor(ofColor::white, 240));
        img5.draw();
    }
    masker.endMask(1);
}

void ofApp::draw(){
    gif.begin();
    ofPushStyle();
    {
        img2.incrementTextureScale(-0.1);
        img2.draw();
        ofSetColor(ofColor::white);
        masker.draw();
    }
    ofPopStyle();
    gif.endAndCaptureFrame();
    gif.draw();
    masker.drawOverlay();
}
/* Snippet end */

void ofApp::keyPressed(int key){
    if(key == 'o') {
        masker.toggleOverlay();
    }
}

void ofApp::keyReleased(int key){

}

void ofApp::mouseMoved(int x, int y ){

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