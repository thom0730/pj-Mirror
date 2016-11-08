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
    
    
    for(int i = 0 ; i < camNUM; i++){
        vidGrabber[i].setVerbose(true);
        vidGrabber[i].setDeviceID(i);
        vidGrabber[i].initGrabber(camWidth, camHeight);
       // vidGrabber[i].setDeviceID(i);

    }
    
    /*
    //カメラの接続確認
    ofSetLogLevel(OF_LOG_VERBOSE);
    check.setVerbose(true);
    check.listDevices();
     */
    
    //FBOの準備
   // fbo[0]->allocate(camWidth, camHeight, GL_RGB);
    DrawFlg = false;//フラグの初期化
    RecFlg = false;//フラグの初期化
    counter = 0;
    
    
    
    
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0 ; i < camNUM; i++){
        vidGrabber[i].update();
    }
    //FBOへの格納
    if(RecFlg){
        FboUpdate();
        cout << "FBOカクノウ" << endl;
        
    }
    

}

//--------------------------------------------------------------
void ofApp::draw(){
 
   // ofSetColor(0xffffff);
    for(int i = 0 ; i < camNUM; i++){
        if(i>=3){
            vidGrabber[i].draw((i-3)*camWidth,camHeight);
        }
        vidGrabber[i].draw(i*camWidth,0);
    }
    
    //FBOの描画
    if(DrawFlg){
        if(counter < fbo.size()){
            fbo[counter]->draw(2*camWidth,camHeight);
            cout << "FBO描画" << endl;
        }
        
        counter++;
        
        
    }
  
    //ムービーのビットマップデータを解析し、配列に格納
    
   /* unsigned char * pixels = vidGrabber.getPixels();
    //画像を10ピクセルごとにスキャン
    for (int i = 0; i < camWidth; i+=10){
        for (int j = 0; j < camHeight; j+=10){
            //RGBそれぞれのピクセルの明度を取得
            unsigned char r = pixels[(j * camWidth + i)*3];
            unsigned char g = pixels[(j * camWidth + i)*3+1];
            unsigned char b = pixels[(j * camWidth + i)*3+2];
            //取得したRGB値をもとに、円を描画
            //取得したピクセルの明るさを、円の半径に対応させている
            ofSetColor(255, 0, 0, 100);
            ofCircle(camWidth+40 + i,20+j,20.0*(float)r/255.0);
            ofSetColor(0, 255, 0, 100);
            ofCircle(camWidth+40 + i,20+j,20.0*(float)g/255.0);
            ofSetColor(0, 0, 255, 100);
            ofCircle(camWidth+40 + i,20+j,20.0*(float)b/255.0);
        }
    }*/

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //「s」キーを押すと、ビデオ取り込みの設定画面を表示
    if (key == 's' || key == 'S'){
       //  check.listDevices();
        
      /*  for(int i = 0 ; i < camNUM; i++){
            vidGrabber[i].videoSettings();
        }*/
    }
    
    if (key == 'a' || key == 'A'){
        RecFlg = true; //録音の開始
        
    }
    
    if(key == 'b' || key == 'B'){
        DrawFlg = true ; //描画の開始
        
        
    }
    

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 'a' || key == 'A'){
        RecFlg = false;//録画の停止
        
    }
    if(key == 'b' || key == 'B'){
        DrawFlg = false ;//描画の停止
        counter = 0;
        fbo.clear();
    }
    

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
//--------------------------------------------------------------
void ofApp::FboUpdate(){
    if (vidGrabber[0].isFrameNew()){
        fbo.push_back(new ofFbo);
        int num = fbo.size()-1;
        fbo[num]->allocate(camWidth, camHeight, GL_RGB);
        fbo[num]->begin();
        vidGrabber[0].draw(0, 0, fbo[num]->getWidth(), fbo[num]->getHeight());
        fbo[num]->end();
    }
    
    
}
