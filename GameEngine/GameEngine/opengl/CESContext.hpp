//
//  CECESContext.hpp
//  GameEngine_ios
//
//  Created by 王兵 on 2018/11/24.
//  Copyright © 2018 王兵. All rights reserved.
//

#ifndef CESContext_hpp
#define CESContext_hpp
#include "CGLBase.hpp"

class CESContext
{
public:
   
    
#ifndef __APPLE__
    /// Display handle
    EGLNativeDisplayType eglNativeDisplay;
    
    /// Window handle
    EGLNativeWindowType  eglNativeWindow;
    
    /// EGL display
    EGLDisplay  eglDisplay;
    
    /// EGL context
    EGLContext  eglContext;
    
    /// EGL surface
    EGLSurface  eglSurface;
#endif

    CESContext();
    ~CESContext();
    static CESContext*  getInstance();
    GLboolean           esCreateWindow(const char *title, GLint width, GLint height, GLuint flags );
    
    void                setWidth(long width);
    void                setHeight(long height);
    void                setProgramObject(GLuint grogramObj);
    GLint               getWidth();
    GLint               getHeight();
    GLuint              getProgramObject();
    
    
protected:
    static void         Destory();
    
private:
    static CESContext   *m_cCESContext;
    void                *platformData;
    GLuint              programObject;
    GLint               width;
    GLint               height;
};

#endif /* CESContext_hpp */
