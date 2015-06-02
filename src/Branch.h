//
//  Branch.h
//  fractale02
//
//  Created by yoshizumi ashikawa on 2015/06/02.
//
//

#ifndef __fractale02__Branch__
#define __fractale02__Branch__

#include <stdio.h>
#include "ofMain.h"

class Branch {
private:
    
public:
    Branch(float lev,float ind, float ex, float why);
    ~Branch();
    
    void updateMe(float ex, float why);
    void drawMe();
    
    float x;
    float y;
    float endx;
    float endy;
    
    float level;
    float index;
    
    float maxLevel;
    float numChildren;
    
    vector <Branch *> children;
    
    float strokeW,alpha;
    float len,lenChange;
    float rot,rotChange;
    
    float red,green,blue;
    float redChange,greenChange,blueChange;
    
};

#endif /* defined(__fractale02__Branch__) */
