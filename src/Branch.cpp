//
//  Branch.cpp
//  fractale02
//
//  Created by yoshizumi ashikawa on 2015/06/02.
//
//

#include "Branch.h"

Branch::Branch(float lev,float ind, float ex, float why){
    maxLevel = 3;
    numChildren = 3;
    
    level = lev;
    index = ind;

    strokeW = round((1/level)*10000);
    alpha = 255 / level;
    len = (1/level)*ofRandom(200);
    rot = ofRandom(360);
    lenChange = ofRandom(10) - 5;
    rotChange = ofRandom(8) - 4;
    
    red = ofRandom(255);
    green = ofRandom(255);
    blue = ofRandom(255);
    
    redChange = ofRandom(10)-5;
    greenChange = ofRandom(10)-5;
    blueChange = ofRandom(10)-5;
    
    updateMe(ex,why);
    
    if(level < maxLevel){
        children.resize(numChildren);
        for(int x = 0;x<numChildren;x++){
            Branch *child = new Branch(level+1,x,endx,endy);
            children[x] = child;
        }
    }
}

void Branch::updateMe(float ex, float why){
    x = ex;
    y = why;
    
    rot += rotChange;
    if(rot > 360){
        rot = 0;
    }
    else if(rot < 0){
        rot = 360;
    }
    
    len -= lenChange;
    if(len <0){
        lenChange *= -1;
    }else if(len > 200){
        lenChange *= -1;
    }
    
    red += redChange;
    if(red > 255 || red < 0){
        redChange *= -1;
    }
    
    std::cout << redChange << endl;
    
    green += greenChange;
    if(green > 255 || green < 0){
        greenChange *= -1;
    }
    
    blue += blueChange;
    if(blue > 255 || blue < 0){
        blueChange *= -1;
    }
    
    float radian = TWO_PI/360*rot;
    endx = x + (len *cos(radian));
    endy = y + (len * sin(radian));
    
    for(int i = 0;i<children.size();i++){
        children[i]->updateMe(endx, endy);
    }
    
    
//    endx = x + (level * (ofRandom(100) -50));
//    endy = y + 50 +(level * (ofRandom(50)));
}

void Branch::drawMe(){
    ofSetColor(red,green,blue,alpha);
    ofSetLineWidth(2);
    
    ofLine(x,y,endx,endy);
    ofCircle(endx, endy, len/12);

    
    for(int i = 0;i<children.size();i++){
        children[i]->drawMe();
    }
}

Branch::~Branch(){
    
}