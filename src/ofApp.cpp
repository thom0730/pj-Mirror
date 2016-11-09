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
    for(int i = 0;i<camNUM;i++){
        DrawFlg[i] = false;//フラグの初期化
        RecFlg[i] = false;//フラグの初期化
        counter[i] = 0;
    }

    
    
    
    
    
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0 ; i < camNUM; i++){
        vidGrabber[i].update();
    }
    //FBOへの格納
    for(int i = 0 ; i < camNUM;i++){
        if(RecFlg[i]){
            FboUpdate(i);
            cout << "FBOカクノウ" << endl;
            
        }
        
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
    for(int i = 0 ; i < camNUM;i++){
        if(DrawFlg[i]){
            FboDraw(i);
            
        }
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

    //カメラ1
    if (key == 'q' || key == 'Q'){
        RecFlg[0] = true; //録音の開始
    }
    if(key == '1'){
        DrawFlg[0] = true ; //描画の開始
    }
    //カメラ2
    if (key == 'w' || key == 'W'){
        RecFlg[1] = true; //録音の開始
    }
    if(key == '2'){
        DrawFlg[1] = true ; //描画の開始
    }
    //カメラ3
    if (key == 'e' || key == 'E'){
        RecFlg[2] = true; //録音の開始
    }
    if(key == '3'){
        DrawFlg[2] = true ; //描画の開始
    }
    //カメラ4
    if (key == 'r' || key == 'R'){
        RecFlg[3] = true; //録音の開始
    }
    if(key == '4'){
        DrawFlg[3] = true ; //描画の開始
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    //カメラ1
    if (key == 'q' || key == 'Q'){
        RecFlg[0] = false; //録音の停止
    }
    if(key == '1'){
        stop(0);
    }
    //カメラ2
    if (key == 'w' || key == 'W'){
        RecFlg[1] = false; //録音の停止
    }
    if(key == '2'){
        stop(1);
    }
    //カメラ3
    if (key == 'e' || key == 'E'){
        RecFlg[2] = false; //録音の停止
    }
    if(key == '3'){
        stop(2);
    }
    //カメラ4
    if (key == 'r' || key == 'R'){
        RecFlg[3] = false; //録音の停止
    }
    if(key == '4'){
        stop(3);
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
void ofApp::FboUpdate(int camera){
    if (vidGrabber[camera].isFrameNew()){
        fbo[camera].push_back(new ofFbo);
        int num = fbo[camera].size()-1;
        fbo[camera][num]->allocate(camWidth, camHeight, GL_RGB);
        fbo[camera][num]->begin();
        vidGrabber[camera].draw(0, 0, fbo[camera][num]->getWidth(), fbo[camera][num]->getHeight());
        fbo[camera][num]->end();
    }
    
    
}
//--------------------------------------------------------------
void ofApp::stop(int number){
    DrawFlg[number] = false ;
    counter[number] = 0;
    fbo[number].clear();
}
//--------------------------------------------------------------
void ofApp::FboDraw(int camera){
    int position = camera + 1;//生成位置の指定(最終的には必要ない処理)
    if(counter[camera] < fbo[camera].size()){
        if(position < 3){
            fbo[camera][counter[camera]]->draw(position*camWidth,camHeight);
        }else{
            fbo[camera][counter[camera]]->draw((position-3)*camWidth,2*camHeight);
        }
        cout << "FBO描画" << endl;
    }
    
    counter[camera]++;
    

    
}
