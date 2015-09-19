#include "ofApp.h"
/* Begin description
{
    That doesn't matter.
}
End description */

/* Snippet begin */
void ofApp::setup(){
    ofSetWindowShape(500, 500);
    gif.setup(50);
    gif.fadeInOut(2, 3, ofColor::darkGray);
    gif.enableTextOverlay();
    numLayers = 5;
    masker.setup(numLayers + 1);
    rectSize = 400;
    rectThickness = 300;
    speed = 0.02;
    
    img.setup("road.png", 1.0, TEXTURE_OFFSET__MIDDLE__LEFT_TO_CENTER);
    for(int i = 0; i < numLayers; i++) {
        scale = ofMap(i, 0, numLayers-1, 0.125, 1.0);
        img.setTextureScale(scale);
        img.setTextureOffsetY(ofRandom(2));
        textures.push_back(img);
    }
    
    img.setup("pcb2.png", 1.0, TEXTURE_OFFSET__MIDDLE__RIGHT_TO_CENTER);
    for(int i = 0; i < numLayers; i++) {
        scale = ofMap(i, 0, numLayers-1, 1.0, 0.35);
        img.setTextureScale(scale);
        img.setTextureOffsetY(ofRandom(2));
        masks.push_back(img);
    }

    ofSetWindowShape(1200, 1200);
    masker.toggleOverlay();
}

void ofApp::update(){
    for(int i = 0; i < numLayers; i++) {
        masker.beginLayer(i);
        {
            textures.at(i).incrementTextureOffsetY(ofMap(i, 0, numLayers-1, -speed, speed));
            textures.at(i).draw();
        }
        masker.endLayer(i);
        
        masker.beginMask(i);
        {
            masks.at(i).incrementTextureOffsetY(ofMap(i, 0, numLayers-1, speed * 0.25, -speed * 0.25));
            masks.at(i).draw();
        }
        masker.endMask(i);
    }

    masker.beginLayer(numLayers);
    {
        ofBackground(ofColor::white);
        masker.drawLayers(0, numLayers-1);
    }
    masker.endLayer(numLayers);

    masker.beginMask(numLayers);
    {
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofSetColor(ofColor::white);
        ofRect(gif.halfWidth, gif.halfHeight, rectSize, rectSize);
        ofSetRectMode(OF_RECTMODE_CORNER);
    }
    masker.endMask(numLayers);
}

void ofApp::draw(){
    gif.begin();
    {
        ofSetColor(ofColor::red);
        ofRect(0, 0, gif.width, gif.height);
        masker.drawLayer(2);
        
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofSetColor(ofColor::white);
        ofRect(gif.halfWidth, gif.halfHeight, gif.width - rectThickness, gif.height - rectThickness);
        ofSetRectMode(OF_RECTMODE_CORNER);
        
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofSetColor(ofColor::black);
        ofRect(gif.halfWidth, gif.halfHeight, rectSize, rectSize);
        ofSetRectMode(OF_RECTMODE_CORNER);
        ofSetColor(ofColor::white);
        masker.drawLayer(numLayers);
        
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofSetColor(ofColor::white);
        ofRect(gif.halfWidth, gif.halfHeight, rectSize - rectThickness, rectSize - rectThickness);
        ofSetRectMode(OF_RECTMODE_CORNER);
    }
    gif.endCaptureDraw();
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