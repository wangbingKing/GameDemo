//
//  CApplication.cpp
//  GameEngine
//
//  Created by 王兵 on 2018/11/16.
//  Copyright © 2018 王兵. All rights reserved.
//
#include <stdlib.h>
#include "CApplication.hpp"
#include "CESContext.hpp"
#include "CGLShader.hpp"
CApplication *CApplication::m_cApplication = nullptr;

CApplication::CApplication()
{
    CESContext::getInstance();
}
CApplication::~CApplication()
{
    
}
void CApplication::init(int w,int h)
{
    width = w;
    height = h;
}
int CApplication::run()
{
    char vShaderStr[] =
    "#version 300 es                          \n"
    "layout(location = 0) in vec4 vPosition;  \n"
    "void main()                              \n"
    "{                                        \n"
    "   gl_Position = vPosition;              \n"
    "}                                        \n";
    
    char fShaderStr[] =
    "#version 300 es                              \n"
    "precision mediump float;                     \n"
    "out vec4 fragColor;                          \n"
    "void main()                                  \n"
    "{                                            \n"
    "   fragColor = vec4 ( 1.0, 0.0, 0.0, 1.0 );  \n"
    "}                                            \n";
    GLuint projectObj = CGLShader::esLoadProgram(vShaderStr, fShaderStr);
    CESContext::getInstance()->setProgramObject(projectObj);
    
    glClearColor ( 1.0f, 1.0f, 1.0f, 0.0f );
    
    
    return 1;
}
int CApplication::update(float fp)
{
    return 1;
}
void CApplication::drawCell(int w,int h)
{
    GLuint programObj = CESContext::getInstance()->getProgramObject();
    
    GLfloat vVertices[] = {  0.0f,  0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };
    
    // Set the viewport
    glViewport ( 0, 0, w, h );
    
    // Clear the color buffer
    glClear ( GL_COLOR_BUFFER_BIT );
    
    // Use the program object
    glUseProgram ( programObj );
    
    // Load the vertex data
    glVertexAttribPointer ( 0, 3, GL_FLOAT, GL_FALSE, 0, vVertices );
    glEnableVertexAttribArray ( 0 );
    
    glDrawArrays ( GL_TRIANGLES, 0, 3 );
    
}
void CApplication::drawCell()
{
    drawCell(width,height);
}
void CApplication::tearDownGL()
{
    GLuint programObj = CESContext::getInstance()->getProgramObject();
    glDeleteProgram ( programObj );
}
int CApplication::stop()
{
    
    return 1;
}

void CApplication::applicationDidEnterBackground()
{
    
}
void CApplication::applicationWillEnterForeground()
{
    
}
CApplication* CApplication::getInstance()
{
    if (nullptr == m_cApplication)
    {
        m_cApplication = new CApplication();
        atexit(Destory);
    }
    return m_cApplication;
}
void CApplication::Destory()
{
    
}
