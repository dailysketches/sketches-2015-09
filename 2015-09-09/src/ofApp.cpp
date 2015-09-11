#include "ofApp.h"
/* Begin description
{
   The relevance of scale
}
End description */

/* Snippet begin */
void ofApp::setup(){
    ofSetWindowShape(500, 500);
    gif.setup(60);
    gif.enableTextOverlay();
    pattern1.setup(&gif);
    masker.setup(1);
    masker.toggleOverlay();
    img1.setup("foil-large.png");
    img2.setup("face-full.png", 2000.0, TEXTURE_OFFSET__TOP__LEFT_TO_CENTER);
    img2.incrementTextureOffsetY(0.27);
    
    ofSetWindowShape(1200, 1200);
}

void ofApp::update(){
    pattern1.update();
    masker.beginLayer(0);
    {
        img2.incrementTextureOffsetY(-0.004);
        img2.incrementTextureScale(-0.15);
        img2.draw();
    }
    masker.endLayer(0);

    masker.beginMask(0);
    {
        pattern1.draw();
    }
    masker.endMask(0);
}

void ofApp::draw(){
    gif.begin();
    {
        masker.draw();
    }
    gif.endCaptureDraw();
    masker.drawOverlay();
}

void Pattern1::setup(ofxGifEncoderTemplate *_gif) {
    gif = _gif;
    numRoads = 2;
    masker.setup(numRoads + 1);
    rectWidth = gif->width / 2;
    halfRectWidth = rectWidth * 0.5;
    
    road.setup("road.png", 1.0, TEXTURE_OFFSET__MIDDLE__RIGHT_TO_CENTER);
    for(int i = 0; i < numRoads; i++) {
        scale = ofMap(i, 0, numRoads-1, 5, 1.3);
        road.setTextureScale(scale);
        road.setTextureOffsetY(ofRandom(2));
        road1s.push_back(road);
    }
    
    road.setup("road.png", 1.0, TEXTURE_OFFSET__MIDDLE__RIGHT_TO_CENTER);
    for(int i = 0; i < numRoads; i++) {
        scale = ofMap(i, 0, numRoads-1, 0.7, 2);
        road.setTextureScale(scale);
        road.setTextureOffsetY(ofRandom(2));
        road2s.push_back(road);
    }
}

void Pattern1::update() {
    for(int i = 0; i < numRoads; i++) {
        masker.beginLayer(i);
        {
            road1s.at(i).incrementTextureOffsetY(ofMap(i, 0, numRoads-1, -0.002, 0.002));
            road1s.at(i).draw();
        }
        masker.endLayer(i);
        
        masker.beginMask(i);
        {
            road2s.at(i).incrementTextureOffsetY(ofMap(i, 0, numRoads-1, -0.002, 0.002));
            road2s.at(i).draw();
        }
        masker.endMask(i);
    }
    
    masker.beginLayer(numRoads);
    {
        masker.drawLayers(0, numRoads - 1);
    }
    masker.endLayer(numRoads);
    
    masker.beginMask(numRoads);
    {
        ofBackground(ofColor::black);
        ofRect(gif->halfWidth - halfRectWidth - 1, 0, rectWidth + 2, gif->height);
    }
    masker.endMask(numRoads);
}

void Pattern1::draw() {
    ofPushMatrix();
    masker.drawLayer(numRoads);
    gif->rotateAroundCenter(180);
    ofTranslate(-rectWidth, 0);
    masker.drawLayer(numRoads);
    ofTranslate(rectWidth*2, 0);
    masker.drawLayer(numRoads);
    ofPopMatrix();
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