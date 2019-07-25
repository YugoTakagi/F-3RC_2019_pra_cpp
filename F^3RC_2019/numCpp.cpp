//
//  numCpp.cpp
//  practice
//
//  Created by 高城友豪 on 2019/07/25.
//  Copyright © 2019 高城友豪. All rights reserved.
//

#include "numCpp.hpp"
float NumCpp::area_of_trapezoid(float top_side, float bottom_side, float height){
    return  (add(top_side, bottom_side)/2)*height;
}
float NumCpp::rotVel(){
    return 1;
}
