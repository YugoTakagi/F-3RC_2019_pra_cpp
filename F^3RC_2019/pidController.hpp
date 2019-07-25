//
//  pidController.hpp
//  test
//
//  Created by 高城友豪 on 2019/07/25.
//  Copyright © 2019 高城友豪. All rights reserved.
//

#ifndef pidController_hpp
#define pidController_hpp

#include <stdio.h>
#include "numCpp.hpp"
class PidController {
private:
    NumCpp nc;
    float __dt;
    float kp;
    float ki;
    float kd;
    
    float state;
    float memory_before_state;
    float proportional;
    float integration;
    float differential;
public:
    explicit PidController(float dt);
    void set_gain(float kp,float ki,float kd);
    void set_state(float state);
    float use_pidController(float ref);
};
#endif /* pidController_hpp */
