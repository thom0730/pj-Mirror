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
    
    
    //カメラの接続確認
    ofSetLogLevel(OF_LOG_VERBOSE);
    check.setVerbose(true);
    check.listDevices();
     
    
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
        vidGrabber[i].draw(i*camWidth,0);
    }
    
    //FBOの描画
    for(int i = 0 ; i < camNUM;i++){
        if(DrawFlg[i]){
            FboDraw(i);
        }
        
    }
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    //カメラ1
    if (key == 'z' || key == 'Z'){
        RecFlg[0] = true; //録音の開始
    }
    if(key == '1'){
        DrawFlg[0] = true ; //描画の開始
    }
    //カメラ2
    if (key == 'x' || key == 'X'){
        RecFlg[1] = true; //録音の開始
    }
    if(key == '2'){
        DrawFlg[1] = true ; //描画の開始
    }
    //カメラ3
    if (key == 'c' || key == 'C'){
        RecFlg[2] = true; //録音の開始
    }
    if(key == '3'){
        DrawFlg[2] = true ; //描画の開始
    }
    

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    //カメラ(FBO)の処理
    
    //カメラ1
    if (key == 'z' || key == 'Z'){
        RecFlg[0] = false; //録音の停止
    }
    if(key == '1'){
        stop(0);
    }
    //カメラ2
    if (key == 'x' || key == 'X'){
        RecFlg[1] = false; //録音の停止
    }
    if(key == '2'){
        stop(1);
    }
    //カメラ3
    if (key == 'c' || key == 'C'){
        RecFlg[2] = false; //録音の停止
    }
    if(key == '3'){
        stop(2);
    }
    
    
    //グリッチ加工の処理
    
    

    

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

}//--------------------------------------------------------------
void ofApp::FboUpdate(int camera){

    fbo[camera].push_back(new ofFbo);//任意のカメラのFBOにバッファを追加
    int num = fbo[camera].size()-1;
    fbo[camera][num]->allocate(camWidth, camHeight, GL_RGB); //FBOの準備
    //FBOの書き込み
    fbo[camera][num]->begin();
    vidGrabber[camera].draw(0, 0, fbo[camera][num]->getWidth(), fbo[camera][num]->getHeight());
    fbo[camera][num]->end();
  
    
    //グリッジ
    myGlitch[camera].push_back(*new ofxPostGlitch);//グリッチ用のインスタンスをカメラ番号の動的配列に格納
    myGlitch[camera][num].setup(fbo[camera][num]);//初期化
    //エフェクトの指定
    myGlitch[camera][num].setFx(OFXPOSTGLITCH_CR_BLUERAISE	, true);

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
        myGlitch[camera][counter[camera]].generateFx(); //グリッチを生成
        fbo[camera][counter[camera]]->draw(position*camWidth,camHeight);
        
        cout << "FBO描画" << endl;
    }
    
    counter[camera]++;
    

    
}
