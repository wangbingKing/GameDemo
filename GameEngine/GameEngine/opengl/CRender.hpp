//
//  CRender.hpp
//  GameEngine
//
//  Created by 王兵 on 2018/11/29.
//  Copyright © 2018 王兵. All rights reserved.
//

#ifndef CRender_hpp
#define CRender_hpp
#include "CGLBase.hpp"

class CRender
{
public:
    CRender();
    void setVAO(GLuint value);
    void setVBOByIndex(int index,GLuint value);
    GLuint getVAO();
    GLuint getVBOByIndex(int index);
    
    void initVertexBufferObjects();
    void drawPrimintiveWithOutVBOs(GLfloat *vertices,GLint vtxStride,GLint numIndices,GLushort *indices);
    void drawPrimintiveWithVBOs(GLfloat *vertices,GLint vtxStride,GLint numIndices,GLushort *indices);
private:
    GLuint vao;
    GLuint vboIds[3];
};

#endif /* CRender_hpp */
