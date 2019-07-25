//
//  pidController.cpp
//  test
//
//  Created by 高城友豪 on 2019/07/25.
//  Copyright © 2019 高城友豪. All rights reserved.
//

#include "pidController.hpp"
PidController::PidController(float dt):__dt(dt)
{
    kp=0.0;
    ki=0.0;
    kd=0.0;
    
    state=0.0;
    memory_before_state=0.0;
    proportional=0.0;
    integration=0.0;
    differential=0.0;
}

void PidController::set_gain(float kp,float ki,float kd){
    this->kp=kp;
    this->ki=ki;
    this->kd=kd;
}
void PidController::set_state(float state){
    memory_before_state = this->state;
    this->state = state;
}
float PidController::use_pidController(float ref){
    proportional = sub(ref,state);
    integration = nc.area_of_trapezoid(state, memory_before_state, __dt);
    differential = (sub(state, memory_before_state))/(__dt);
    return kp*proportional +ki*integration +kd*differential;
}
