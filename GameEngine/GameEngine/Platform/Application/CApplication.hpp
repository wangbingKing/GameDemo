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
    void init(int width,int height);
    virtual int run();
    virtual int stop();
    virtual void tearDownGL();
    virtual void drawCell();
    virtual void drawCell(int width,int height);
    virtual int update(float fp);
    static CApplication* getInstance();
    void applicationDidEnterBackground();
    void applicationWillEnterForeground();
    
protected:
    virtual ~CApplication();
    static void Destory();
    static CApplication *m_cApplication;
    int                 width;
    int                 height;
};

#endif /* CApplication_hpp */
