//
//  curiosity.cpp
//  practice
//
//  Created by 高城友豪 on 2019/07/25.
//  Copyright © 2019 高城友豪. All rights reserved.
//

#include "curiosity.hpp"
Curiosity::Curiosity(LowlayerHandelTypedef *hlow, float dt):
__pidX(dt), __pidY(dt), __pidTheta(dt)
{
    this->hlow = hlow;
    __pidX.set_gain(0.0, 0.0, 0.0);
    __pidY.set_gain(0.0, 0.0, 0.0);
    __pidTheta.set_gain(0.0, 0.0, 0.0);
}

void Curiosity::using_model(Datas State, Datas Reference){
//    step to measurement
    this->State = State;
    this->Reference = Reference;
    
//    step to PidControl
    __pidX.set_state(State.x);
    __pidX.set_state(State.y);
    __pidX.set_state(State.theta);
    Adjustment[__x] = __pidX.use_pidController(Reference.x);
    Adjustment[__y] = __pidY.use_pidController(Reference.y);
    Adjustment[__theta] = __pidTheta.use_pidController(Reference.theta);
    
    inverse_kinematics_model();
//    motor
    hlow->M1.setDuty(velocity[0]);
    hlow->M2.setDuty(velocity[1]);
    hlow->M3.setDuty(velocity[2]);
}
void Curiosity::inverse_kinematics_model(){
//    ここをnumCppに入れたい
    for (int i=0; i<arraySize(jacobian); i++) {
            velocity[i]=Adjustment[__x]*jacobian[i][__x]*nc.rotVel() +Adjustment[__y]*jacobian[i][__y]*nc.rotVel() +Adjustment[__theta]*jacobian[i][__theta];
    }
}


