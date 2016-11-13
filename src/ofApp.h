#pragma once


#include "ofMain.h"
#include "ofxPostGlitch.h"
#include "Glitch.hpp"

//カメラの台数
#define camNUM 4


class ofApp : public ofBaseApp{
    
    
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void FboUpdate(int camera);
    void FboDraw(int camera);
    void stop(int number); //�`��̒�~�p�֐�
		
    ofVideoGrabber vidGrabber[camNUM];
    ofVideoGrabber check;
    int camWidth , camHeight;
    vector<ofFbo *> fbo[camNUM];

    
    bool RecFlg[camNUM];
    bool DrawFlg[camNUM];
    int counter[camNUM];
    
    Glitch EffectGlitch;//�O���b�`�G�t�F�N�g�̃C���X�^���X���J�����̌�������
    
    vector<ofxPostGlitch> myGlitch[camNUM];
    
};
