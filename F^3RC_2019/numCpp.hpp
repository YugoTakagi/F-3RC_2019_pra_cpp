//
//  numCpp.hpp
//  practice
//
//  Created by 高城友豪 on 2019/07/25.
//  Copyright © 2019 高城友豪. All rights reserved.
//

#ifndef numCpp_hpp
#define numCpp_hpp
#include <iostream>
template <typename T>
T add(T x, T y){
    return x +y;
}
template <typename T>
T sub(T x, T y){
    return x -y;
}
//  this template make size of array.
template<class T, size_t N>
size_t arraySize(const T (&array)[N]) {
    return N;
};
class NumCpp
{
private:
public:
    float area_of_trapezoid(float top_side, float bottom_side, float height);
    float rotVel();
};
#endif /* numCpp_hpp */
