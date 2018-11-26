//
//  CApplication.hpp
//  GameEngine
//
//  Created by 王兵 on 2018/11/16.
//  Copyright © 2018 王兵. All rights reserved.
//

#ifndef CApplication_hpp
#define CApplication_hpp

#include <stdio.h>
#include "CObj.hpp"
class CApplication : public CObj
{
public:
    CApplication();
    int run();
    int stop();
    virtual void tearDownGL();
    virtual void drawFunc(long width,long heigth);
    virtual int update(float fp);
    static CApplication* getInstance();
    void applicationDidEnterBackground();
    void applicationWillEnterForeground();
    
protected:
    virtual ~CApplication();
    static void Destory();
private:
    static CApplication *m_cApplication;
};

#endif /* CApplication_hpp */
