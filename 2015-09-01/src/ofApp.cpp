#include "ofApp.h"
/* Begin description
{
    Mixing 2015-08-25 with 2015-08-15
}
End description */

/* Snippet begin */
void ofApp::setup(){
    ofSetWindowShape(500, 500);
    gif.setupPaused(16, 54);
    gif.fadeInOut(2, 1, ofColor::white);
    gif.enableTextOverlay();
    
    pattern1.setup(&gif);
    pattern2.setup(&gif);

    ofSetWindowShape(1000, 1200);
    pattern1.masker.toggleOverlay();
}

void ofApp::update(){
    pattern1.update();
    pattern2.update();
}

void ofApp::draw(){
    gif.begin();
    {
        ofEnableAlphaBlending();
        pattern1.draw();
        pattern2.draw();
    }
    gif.endCaptureDraw();
    pattern1.masker.drawOverlay();
}

void Pattern1::setup(ofxGifEncoderTemplate *_gif) {
    gif = _gif;
    layerIncrement = 0.01;
    maskIncrement = 0.0004;
    
    numLayers = 32;
    numMasksPerLayer = 6;
    masker.setup(numLayers);
    
    layer.setup("glass3.png");
    for(int i = 0; i < numLayers; i++) {
        scale = ofMap(i, 0, numLayers-1, 4, 2.5);
        layer.setTextureScale(scale);
        layer.setTextureOffset(i % 2 == 0 ? TEXTURE_OFFSET__MIDDLE__LEFT_TO_CENTER : TEXTURE_OFFSET__MIDDLE__RIGHT_TO_CENTER);
        layer.setTextureOffsetY(ofRandom(2));
        layers.push_back(layer);
        
        maskLoader.clear();
        scale = ofMap(i, 0, numLayers-1, 6, 0.33);
        mask.setup("tissue.png", scale, TEXTURE_OFFSET__MIDDLE__LEFT_TO_CENTER);
        for(int j = 0; j < numMasksPerLayer; j++) {
            mask.setTextureOffsetY(ofRandom(2));
            maskLoader.push_back(mask);
        }
        masks.push_back(maskLoader);
    }
}

void Pattern1::update() {
    for(int i = 0; i < numLayers; i++) {
        masker.beginLayer(i);
        {
            ofSetColor(ofColor(ofColor::red));
            increment = ofMap(i, 0, numLayers-1, layerIncrement, -layerIncrement);
            layers.at(i).incrementTextureOffsetY(increment);
            layers.at(i).draw();
        }
        masker.endLayer(i);
        
        masker.beginMask(i);
        {
            ofSetColor(ofColor::white);
            ofBackground(ofColor::white);
            for(int j = 0; j < numMasksPerLayer; j++) {
                increment = (j+1) * ofMap(i, 0, numLayers-1, maskIncrement, -maskIncrement);
                masks.at(i).at(j).incrementTextureOffsetY(increment);
                masks.at(i).at(j).draw();
            }
        }
        masker.endMask(i);
    }
}

void Pattern1::draw() {
    ofSetColor(ofColor(ofColor::red));
    layers.at(0).draw();
    masker.draw();
}

void Pattern2::setup(ofxGifEncoderTemplate *_gif) {
    gif = _gif;
    numRects = 7;
    numLayers = 1;
    masker.setup(numLayers, ISOLATE_LAYERS);
    masker.toggleOverlay();
    
    img1.setup("pcb2.png", 1.0, TEXTURE_OFFSET__TOP_TO_MIDDLE__RIGHT_TO_CENTER);
    
    for(int i = 0; i < numRects; i++) {
        rectAlphaMultipliers.push_back(ofRandom(0.05, 0.3));
    }
    rectWidth = (gif->width / numRects) + 1;
}

void Pattern2::update() {
    masker.beginLayer(0);
    {
        ofBackground(ofColor::black);
        img1.incrementTextureOffsetY(0.04);
        img1.draw(0, gif->halfHeight);
        img1.draw(0, -gif->halfHeight, TEXTURE_FLIP_HORIZONTAL);
    }
    masker.endLayer(0);
    
    masker.beginMask(0);
    {
        ofBackground(ofColor::black);
        for(int i = 0; i < numRects; i++) {
            alpha = sin(ofGetFrameNum() * rectAlphaMultipliers.at(i));
            alpha = ofMap(alpha, -1, 1, -100, 255);
            if(alpha < 0) alpha = 0;
            ofSetColor(ofColor(ofColor::white, alpha));
            ofRect(i * rectWidth, 0, rectWidth, gif->height);
        }
    }
    masker.endMask(0);
}

void Pattern2::draw() {
    ofEnableAlphaBlending();
    masker.draw();
}
/* Snippet end */

void ofApp::keyPressed(int key){
    if(key == 'o') {
        pattern1.masker.toggleOverlay();
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