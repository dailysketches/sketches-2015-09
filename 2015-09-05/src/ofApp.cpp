#include "ofApp.h"
/* Begin description
{
    This doesn't make any sense.
}
End description */

/* Snippet begin */
void ofApp::setup(){
    ofSetWindowShape(500, 500);
    gif.setup(45);
    masker.setup(2);
    img1.setup("pcb-bw.png", 2.0);
    img2.setup("glass3.png", 1.0);
    img3.setup("foil1.png", 2.0);
    img4.setup("glass1-inverted.png", 1.0);

    masker.toggleOverlay();
    ofSetWindowShape(1200, 1200);
}

void ofApp::update(){
    if(ofGetFrameNum() % 9 == 0) {
        img1.setTextureOffset(ofRandom(2), ofRandom(2));
        img1.setTextureScale(ofRandom(0.5, 1.5));
        img2.setTextureOffset(ofRandom(2), ofRandom(2));
        img2.setTextureScale(ofRandom(0.5, 1.5));
    }
    if(ofGetFrameNum() % 3 == 0) {
        masker.beginLayer(0);
        {
            img3.setTexturePosition(ofRandom(2), ofRandom(2));
            img3.setTextureScale(ofRandom(1.0, 6.0));
            ofSetColor(ofColor::red);
            img3.draw();
        }
        masker.endLayer(0);
        
        masker.beginMask(0);
        {
            img4.setTexturePosition(ofRandom(2), ofRandom(2));
            img4.setTextureScale(ofRandom(1.0, 6.0));
            ofBackground(ofColor::white);
            if(ofRandom(1) > 0.25) {
                ofSetColor(ofColor(ofColor::white, 120));
                img4.draw();
            }
        }
        masker.endMask(0);
    } else {
        img1.incrementTextureScale(0.06);
        masker.beginLayer(1);
        {
            img1.draw();
        }
        masker.endLayer(1);
        
        masker.beginMask(1);
        {
            img1.draw();
        }
        masker.endMask(1);
    }
}

void ofApp::draw(){
    gif.begin();
    ofPushStyle();
    {
        img2.incrementTextureScale(-0.048);
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