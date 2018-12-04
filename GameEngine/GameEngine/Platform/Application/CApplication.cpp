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
GLuint vao = 0;
GLuint vboIds[3];
GLfloat color[4] = {1.0f,0.0f,0.0f,0.0f};
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
    "#version 300 es                            \n"
    "layout(location = 0) in vec4 a_position;   \n"
    "layout(location = 1) in vec4 a_color;      \n"
    "out vec4 v_color;                          \n"
    "void main()                                \n"
    "{                                          \n"
    "    v_color = a_color;                     \n"
    "    gl_Position = a_position;              \n"
    "}";
    
    char fShaderStr[] =
    "#version 300 es            \n"
    "precision mediump float;   \n"
    "in vec4 v_color;           \n"
    "out vec4 o_fragColor;      \n"
    "void main()                \n"
    "{                          \n"
    "    o_fragColor = v_color; \n"
    "}" ;
    GLuint projectObj = CGLShader::esLoadProgram(vShaderStr, fShaderStr);
    CESContext::getInstance()->setProgramObject(projectObj);
    
//    glBindVertexArray(1, vao);
//    glGenBuffers(1,&vao);
    
    GLint maxVertexAttribs;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &maxVertexAttribs);
    
    glClearColor ( 1.0f, 1.0f, 1.0f, 0.0f );
    
    
    return 1;
}
int CApplication::update(float fp)
{
    color[0] = color[0] + fp * 0.1f;
    if( color[0] > 1.0f)
    {
        color[0] = color[0] - 1.0f;
    }
    return 1;
}
void CApplication::drawCell(int w,int h)
{
    GLuint programObj = CESContext::getInstance()->getProgramObject();
    
    GLfloat vertexPos[3 * 3] =
    {
        0.0f,  0.5f, 0.0f, // v0
        -0.5f, -0.5f, 0.0f, // v1
        0.5f, -0.5f, 0.0f  // v2
    };
    GLfloat vertexPos2[3 * 3] =
    {
        1.0f,  0.5f, 0.0f, // v0
        0.5f, -0.5f, 0.0f, // v1
        1.5f, -0.5f, 0.0f  // v2
    };
    
    // Set the viewport
    glViewport ( 0, 0, w, h );
    
    // Clear the color buffer
    glClear ( GL_COLOR_BUFFER_BIT );
    
    // Use the program object
    glUseProgram ( programObj );
    
    GLint count = 0;
    glGetProgramiv(programObj, GL_ACTIVE_ATTRIBUTES, &count);
    
    // Load the vertex data
    glVertexAttribPointer ( 0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), vertexPos );
    glVertexAttribPointer ( 0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), vertexPos2 );
    
    glVertexAttrib4fv ( 1, color );
    
    glEnableVertexAttribArray ( 0 );
    glDrawArrays ( GL_TRIANGLES, 0, 6 );
    glDisableVertexAttribArray ( 0 );
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
