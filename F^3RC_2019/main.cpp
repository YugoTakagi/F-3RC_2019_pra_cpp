//
//  main.cpp
//  F^3RC_2019
//
//  Created by 高城友豪 on 2019/07/25.
//  Copyright © 2019 高城友豪. All rights reserved.
//

#include <iostream>
#include "LowlayerHandel.hpp"
#include "curiosity.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    LowlayerHandelTypedef hlow;
    Curiosity cy(&hlow, 20*10^-3);
    Datas State;
    Datas Reference;
    State.x=0.0;
    State.y=0.0;
    State.theta=0.0;
    Reference.x=1.0;
    Reference.y=1.0;
    Reference.theta=1.0;
    
    
    cy.using_model(State, Reference);
    return 0;
}
