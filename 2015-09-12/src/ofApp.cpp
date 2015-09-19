#include "ofApp.h"
/* Begin description
{
    X-ray.
}
End description */

/* Snippet begin */
void ofApp::setup(){
    ofSetWindowShape(500, 500);
    gif.setup(50);
    gif.fadeInOut(2, 3, ofColor::darkGray);
    gif.enableTextOverlay();
    numLayers = 8;
    masker.setup(numLayers + 1);
    rectSize = 200;
    rectThickness = 2;
    speed = 0.1;
    
    img.setup("road.png", 1.0, TEXTURE_OFFSET__MIDDLE__LEFT_TO_CENTER);
    for(int i = 0; i < numLayers; i++) {
        scale = ofMap(i, 0, numLayers-1, 0.25, 0.7);
        img.setTextureScale(scale);
        img.setTextureOffsetY(ofRandom(2));
        textures.push_back(img);
    }
    
    img.setup("pcb2.png", 1.0, TEXTURE_OFFSET__MIDDLE__RIGHT_TO_CENTER);
    for(int i = 0; i < numLayers; i++) {
        scale = ofMap(i, 0, numLayers-1, 1.4, 0.75);
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
            masks.at(i).incrementTextureOffsetY(ofMap(i, 0, numLayers-1, speed * 0.125, -speed * 0.125));
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
        ofBackground(ofColor::black);
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
        ofSetColor(ofColor::black);
        ofRect(gif.halfWidth, gif.halfHeight, rectSize, rectSize);
        ofSetRectMode(OF_RECTMODE_CORNER);
        ofSetColor(ofColor::white);
        masker.drawLayer(numLayers);
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