//
//  Glitch.hpp
//  2camTest
//
//  Created by 諸星智也 on 2016/11/11.
//
//
#ifndef Glitch_hpp
#define Glitch_hpp

#include "ofMain.h"
#include "ofxPostGlitch.h"

#define camNUM 4

class Glitch {
    
public:
    //グリッジ用
    vector<ofxPostGlitch> myGlitch;
    void EffectStart(int key); //エフェクトの開始
    void EffectStop(int key); //エフェクトの停止
    
    
    
};

#endif /* Glitch_hpp */