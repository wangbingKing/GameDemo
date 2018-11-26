//
//  CESContext.cpp
//  GameEngine_ios
//
//  Created by 王兵 on 2018/11/24.
//  Copyright © 2018 王兵. All rights reserved.
//


#include "CESContext.hpp"
#include <stdlib.h>
CESContext *CESContext::m_cCESContext = nullptr;

CESContext::CESContext()
{
    
}
CESContext* CESContext::getInstance()
{
    if (nullptr == m_cCESContext)
    {
        m_cCESContext = new CESContext();
        atexit(Destory);
    }
    return m_cCESContext;
}
CESContext::~CESContext()
{
    
}
void CESContext::Destory()
{
    
}

GLboolean CESContext::esCreateWindow(const char *title, GLint width, GLint height, GLuint flags )
{
#ifndef __APPLE__
    EGLConfig config;
    EGLint majorVersion;
    EGLint minorVersion;
    EGLint contextAttribs[] = { EGL_CONTEXT_CLIENT_VERSION, 3, EGL_NONE };
    
#ifdef ANDROID
    // For Android, get the width/height from the window rather than what the
    // application requested.
    this->width = ANativeWindow_getWidth ( this->eglNativeWindow );
    this->height = ANativeWindow_getHeight ( this->eglNativeWindow );
#else
    this->width = width;
    this->height = height;
#endif
    if ( !WinCreate ( this, title ) )
    {
        return GL_FALSE;
    }
    
    this->eglDisplay = eglGetDisplay( this->eglNativeDisplay );
    if ( this->eglDisplay == EGL_NO_DISPLAY )
    {
        return GL_FALSE;
    }
    
    // Initialize EGL
    if ( !eglInitialize ( this->eglDisplay, &majorVersion, &minorVersion ) )
    {
        return GL_FALSE;
    }
    
    {
        EGLint numConfigs = 0;
        EGLint attribList[] =
        {
            EGL_RED_SIZE,       5,
            EGL_GREEN_SIZE,     6,
            EGL_BLUE_SIZE,      5,
            EGL_ALPHA_SIZE,     ( flags & ES_WINDOW_ALPHA ) ? 8 : EGL_DONT_CARE,
            EGL_DEPTH_SIZE,     ( flags & ES_WINDOW_DEPTH ) ? 8 : EGL_DONT_CARE,
            EGL_STENCIL_SIZE,   ( flags & ES_WINDOW_STENCIL ) ? 8 : EGL_DONT_CARE,
            EGL_SAMPLE_BUFFERS, ( flags & ES_WINDOW_MULTISAMPLE ) ? 1 : 0,
            // if EGL_KHR_create_context extension is supported, then we will use
            // EGL_OPENGL_ES3_BIT_KHR instead of EGL_OPENGL_ES2_BIT in the attribute list
            EGL_RENDERABLE_TYPE, GetContextRenderableType ( this->eglDisplay ),
            EGL_NONE
        };
        
        // Choose config
        if ( !eglChooseConfig ( this->eglDisplay, attribList, &config, 1, &numConfigs ) )
        {
            return GL_FALSE;
        }
        
        if ( numConfigs < 1 )
        {
            return GL_FALSE;
        }
    }
    
    
#ifdef ANDROID
    // For Android, need to get the EGL_NATIVE_VISUAL_ID and set it using ANativeWindow_setBuffersGeometry
    {
        EGLint format = 0;
        eglGetConfigAttrib ( this->eglDisplay, config, EGL_NATIVE_VISUAL_ID, &format );
        ANativeWindow_setBuffersGeometry ( this->eglNativeWindow, 0, 0, format );
    }
#endif // ANDROID
    
    // Create a surface
    this->eglSurface = eglCreateWindowSurface ( this->eglDisplay, config,
                                                    this->eglNativeWindow, NULL );
    
    if ( this->eglSurface == EGL_NO_SURFACE )
    {
        return GL_FALSE;
    }
    
    // Create a GL context
    this->eglContext = eglCreateContext ( this->eglDisplay, config,
                                              EGL_NO_CONTEXT, contextAttribs );
    
    if ( this->eglContext == EGL_NO_CONTEXT )
    {
        return GL_FALSE;
    }
    
    // Make the context current
    if ( !eglMakeCurrent ( this->eglDisplay, this->eglSurface,
                          this->eglSurface, this->eglContext ) )
    {
        return GL_FALSE;
    }
    
#endif // #ifndef __APPLE__
    
    return GL_TRUE;
}

void CESContext::setWidth(long width)
{
    this->width = (int)width;
}
void CESContext::setHeight(long height)
{
    this->height = (int)height;
}
GLint CESContext::getWidth()
{
    return this->width;
}
GLint CESContext::getHeight()
{
    return this->height;
}
void CESContext::setProgramObject(GLuint programObj)
{
    programObject = programObj;
}
GLuint CESContext::getProgramObject()
{
    return programObject;
}
