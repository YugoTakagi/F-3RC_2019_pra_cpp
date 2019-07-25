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
    Adjustment.x = __pidX.use_pidController(Reference.x);
    Adjustment.y = __pidY.use_pidController(Reference.y);
    Adjustment.theta = __pidTheta.use_pidController(Reference.theta);
    
    
    inverse_kinematics_model();
//    motor
    hlow->M1.setDuty(velocity[0]);
    hlow->M2.setDuty(velocity[1]);
    hlow->M3.setDuty(velocity[2]);
}
void Curiosity::inverse_kinematics_model(){
//    ここをnumCppに入れたい
    for (int i=0; i<arraySize(jacobian); i++) {
        for (int j=0; j<arraySize(*jacobian); j++) {
            velocity[i]=Adjustment.x*jacobian[i][j]*nc.rotVel() +Adjustment.y*jacobian[i][j]*nc.rotVel() +Adjustment.theta*jacobian[i][j];
        }
    }
}


