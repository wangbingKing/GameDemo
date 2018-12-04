//
//  CGLBase.hpp
//  GameEngine
//
//  Created by 王兵 on 2018/11/23.
//  Copyright © 2018 王兵. All rights reserved.
//

#ifndef CGLBase_hpp
#define CGLBase_hpp

#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGLES/ES3/gl.h>
#else
#include <GLES3/gl3.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#endif
    
    
    /// esCreateWindow flag - RGB color buffer
#define ES_WINDOW_RGB           0
    /// esCreateWindow flag - ALPHA color buffer
#define ES_WINDOW_ALPHA         1
    /// esCreateWindow flag - depth buffer
#define ES_WINDOW_DEPTH         2
    /// esCreateWindow flag - stencil buffer
#define ES_WINDOW_STENCIL       4
    /// esCreateWindow flat - multi-sample buffer
#define ES_WINDOW_MULTISAMPLE   8
    
    
    ///
    // Types
    //
#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif


typedef struct
{
    GLfloat   m[4][4];
} ESMatrix;


#define VERTEX_POS_SIZE         3   //x,y,z,
#define VERTEX_COLOR_SIZE       4   //r g b a

//顶点属性索引位置
#define VERTEX_POS_INDX         0
#define VERTEX_COLOR_INDX       1

#endif /* CGLBase_hpp */
