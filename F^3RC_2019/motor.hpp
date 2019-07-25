//
//  motor.hpp
//  practice
//
//  Created by 高城友豪 on 2019/07/25.
//  Copyright © 2019 高城友豪. All rights reserved.
//

#ifndef motor_hpp
#define motor_hpp

#include <stdio.h>
class Motor {
private:
    int __i;
public:
    Motor();
    void setDuty(float duty);
};
#endif /* motor_hpp */
