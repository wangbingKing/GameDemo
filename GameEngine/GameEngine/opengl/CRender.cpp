//
//  CRender.cpp
//  GameEngine
//
//  Created by 王兵 on 2018/11/29.
//  Copyright © 2018 王兵. All rights reserved.
//

#include "CRender.hpp"

CRender::CRender()
{
    vao = 0;
    vboIds[0] = 0;
    vboIds[1] = 0;
    vboIds[2] = 0;
}
void CRender::setVAO(GLuint value)
{
    vao = value;
}
void CRender::setVBOByIndex(int index,GLuint value)
{
    vboIds[index] = value;
}
GLuint CRender::getVAO()
{
    return vao;
}
GLuint CRender::getVBOByIndex(int index)
{
    return vboIds[index];
}
void CRender::initVertexBufferObjects()
{
    //分配三个缓冲区对象
    glGenBuffers(3, vboIds);
    //指定当前的缓冲区对象
    glBindBuffer(GL_ARRAY_BUFFER, vboIds[0]);
    //顶点数组数据或者元素数组数据储存
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
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPos), vertexPos, GL_STATIC_DRAW);
    
}

void CRender::drawPrimintiveWithOutVBOs(GLfloat *vertices,GLint vtxStride,GLint numIndices,GLushort *indices)
{
    GLfloat *vtxBuf = vertices;
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
    glEnableVertexAttribArray(VERTEX_POS_INDX);
    glEnableVertexAttribArray(VERTEX_COLOR_INDX);
    
    
    glVertexAttribPointer(VERTEX_POS_INDX, VERTEX_POS_SIZE, GL_FLOAT, GL_FALSE, vtxStride, vtxBuf);
    vtxBuf += VERTEX_POS_SIZE;
    glVertexAttribPointer(VERTEX_COLOR_INDX, VERTEX_COLOR_SIZE, GL_FLOAT, GL_FALSE, vtxStride, vtxBuf);
    glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_SHORT, indices);
}
void CRender::drawPrimintiveWithVBOs(GLfloat *vertices,GLint vtxStride,GLint numIndices,GLushort *indices)
{
    
    
}
