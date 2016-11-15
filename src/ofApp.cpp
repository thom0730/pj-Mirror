#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(30);

    ofEnableSmoothing();
    //画面の混色の設定を加算合成にする
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    
    //キャプチャするムービーのサイズを指定
    camWidth = ofGetWidth()/3; //3
    camHeight = (2*camWidth)/3; //2
    
    
   
    vidGrabber.setVerbose(true);
    vidGrabber.setDeviceID(0);
    vidGrabber.initGrabber(ofGetWidth(), ofGetHeight());
  
    
    
    //カメラの接続確認
    ofSetLogLevel(OF_LOG_VERBOSE);
    check.setVerbose(true);
    check.listDevices();
    
    
    myFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);
    glitch.myGlitch.setup(&myFbo);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    vidGrabber.update();


}

//--------------------------------------------------------------
void ofApp::draw(){
    myFbo.begin();
    vidGrabber.draw(0,0);
    myFbo.end();
    
    
    glitch.myGlitch.generateFx();
    
    myFbo.draw(0,0);
    


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    glitch.EffectStart(key); //エフェクトの開始

    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    glitch.EffectStop(key);
    


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