//
//  Glitch.cpp
//  2camTest
//
//  Created by 諸星智也 on 2016/11/11.
//
//

#include "Glitch.hpp"

//--------------------------------------------------------------------------
void Glitch::EffectStart(int key)
{
    //グリッジ
    if (key == 'q') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_CONVERGENCE	, true);
        }
    }
    if (key == 'w') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_GLOW	, true);
        }
    }
    if (key == 'e') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_SHAKER	, true);
        }
    }
    if (key == 'r') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_CUTSLIDER	, true);
        }
    }
    if (key == 't') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_TWIST	, true);
        }
    }
    if (key == 'y') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_OUTLINE	, true);
        }    }
    if (key == 'u') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_NOISE	, true);
        }
    }
    if (key == 'i') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_SLITSCAN	, true);
        }
    }
    if (key == 'o') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_SWELL	, true);
        }
    }
    if (key == 'p') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_INVERT	, true);
        }
    }
    if (key == 'a') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST	, true);
        }
    }
    if (key == 's') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_CR_BLUERAISE	, true);
        }
    }
    if (key == 'd') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_CR_REDRAISE	, true);
        }
    }
    if (key == 'f') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_CR_GREENRAISE	, true);
        }
    }
    if (key == 'g') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, true);
        }
    }
    if (key == 'h') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_CR_REDINVERT	, true);
        }
    }
    if (key == 'j') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_CR_GREENINVERT	, true);
        }
    }
}

//--------------------------------------------------------------------------
void Glitch::EffectStop(int key)
{
    //グリッジ
    if (key == 'q') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_CONVERGENCE	, false);
        }
    }
    if (key == 'w') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_GLOW	, false);
        }
    }
    if (key == 'e') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_SHAKER	, false);
        }
    }
    if (key == 'r') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_CUTSLIDER	, false);
        }
    }
    if (key == 't') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_TWIST	, false);
        }
    }
    if (key == 'y') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_OUTLINE	, false);
        }    }
    if (key == 'u') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_NOISE	, false);
        }
    }
    if (key == 'i') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_SLITSCAN	, false);
        }
    }
    if (key == 'o') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_SWELL	, false);
        }
    }
    if (key == 'p') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_INVERT	, false);
        }
    }
    if (key == 'a') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST	, false);
        }
    }
    if (key == 's') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_CR_BLUERAISE	, false);
        }
    }
    if (key == 'd') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_CR_REDRAISE	, false);
        }
    }
    if (key == 'f') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_CR_GREENRAISE	, false);
        }
    }
    if (key == 'g') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, false);
        }
    }
    if (key == 'h') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_CR_REDINVERT	, false);
        }
    }
    if (key == 'j') {
        for(int i = 0;i<myGlitch.size();i++){
            myGlitch[i].setFx(OFXPOSTGLITCH_CR_GREENINVERT	, false);
        }
    }}
