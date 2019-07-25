//
//  curiosity.hpp
//  practice
//
//  Created by 高城友豪 on 2019/07/25.
//  Copyright © 2019 高城友豪. All rights reserved.
//

#ifndef curiosity_hpp
#define curiosity_hpp

#include <stdio.h>
#include "LowlayerHandel.hpp"
#include "pidController.hpp"
#include "numCpp.hpp"
typedef struct{
    float x;
    float y;
    float theta;
} Datas;
class Curiosity
{
private:
    LowlayerHandelTypedef *hlow;
    NumCpp nc;
    PidController __pidX;
    PidController __pidY;
    PidController __pidTheta;
    
    Datas State;
    Datas Adjustment;
    Datas Reference;
    float velocity[3];
    float jacobian[3][3]= {{11,12,13},{21,22,23},{31,32,33}};;
public:
    Curiosity(LowlayerHandelTypedef *hlow, float dt);
    void inverse_kinematics_model();
    void using_model(Datas State, Datas Reference);
};
#endif /* curiosity_hpp */
