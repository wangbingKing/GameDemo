//
//  GameEngine.cpp
//  GameEngine
//
//  Created by 王兵 on 2018/11/16.
//  Copyright © 2018 王兵. All rights reserved.
//

#include <iostream>
#include "GameEngine.hpp"
#include "GameEnginePriv.hpp"

void GameEngine::HelloWorld(const char * s)
{
    GameEnginePriv *theObj = new GameEnginePriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void GameEnginePriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

