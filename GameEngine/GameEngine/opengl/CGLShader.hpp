//
//  CGLShader.hpp
//  GameEngine
//
//  Created by 王兵 on 2018/11/24.
//  Copyright © 2018 王兵. All rights reserved.
//

#ifndef CGLShader_hpp
#define CGLShader_hpp

#include <stdarg.h>
#include "CGLBase.hpp"

class CGLShader
{
public:
    static inline GLuint esLoadShader ( GLenum type, const char *shaderSrc )
    {
        GLuint shader;
        GLint compiled;
        
        // Create the shader object
        shader = glCreateShader ( type );
        
        if ( shader == 0 )
        {
            for(GLenum err; (err = glGetError()) != GL_NO_ERROR;)
            {
                //Process/log the error.
                printf("error %d =",err);
            }
            return 0;
        }
        
        // Load the shader source
        glShaderSource ( shader, 1, &shaderSrc, NULL );
        
        // Compile the shader
        glCompileShader ( shader );
        
        // Check the compile status
        glGetShaderiv ( shader, GL_COMPILE_STATUS, &compiled );
        
        if ( !compiled )
        {
            GLint infoLen = 0;
            
            glGetShaderiv ( shader, GL_INFO_LOG_LENGTH, &infoLen );
            
            if ( infoLen > 1 )
            {
                char *infoLog = (char *)malloc ( sizeof ( char ) * infoLen );
                
                glGetShaderInfoLog ( shader, infoLen, NULL, infoLog );
                esLogMessage ( "Error compiling shader:\n%s\n", infoLog );
                
                free ( infoLog );
            }
            
            glDeleteShader ( shader );
            return 0;
        }
        
        return shader;
        
    }
    static inline void esLogMessage ( const char *formatStr, ... )
    {
        va_list params;
        char buf[BUFSIZ];
        
        va_start ( params, formatStr );
        vsprintf ( buf, formatStr, params );
        
#ifdef ANDROID
        __android_log_print ( ANDROID_LOG_INFO, "esUtil" , "%s", buf );
#else
        printf ( "%s", buf );
#endif
        
        va_end ( params );
    }
    
    static inline GLuint esLoadProgram ( const char *vertShaderSrc, const char *fragShaderSrc )
    {
        GLuint vertexShader;
        GLuint fragmentShader;
        GLuint programObject;
        GLint linked;
        
        // Load the vertex/fragment shaders
        vertexShader = esLoadShader ( GL_VERTEX_SHADER, vertShaderSrc );
        
        if ( vertexShader == 0 )
        {
            return 0;
        }
        
        fragmentShader = esLoadShader ( GL_FRAGMENT_SHADER, fragShaderSrc );
        
        if ( fragmentShader == 0 )
        {
            glDeleteShader ( vertexShader );
            return 0;
        }
        
        // Create the program object
        programObject = glCreateProgram ( );
        
        if ( programObject == 0 )
        {
            return 0;
        }
        
        glAttachShader ( programObject, vertexShader );
        glAttachShader ( programObject, fragmentShader );
        
        // Link the program
        glLinkProgram ( programObject );
        
        // Check the link status
        glGetProgramiv ( programObject, GL_LINK_STATUS, &linked );
        
        if ( !linked )
        {
            GLint infoLen = 0;
            
            glGetProgramiv ( programObject, GL_INFO_LOG_LENGTH, &infoLen );
            
            if ( infoLen > 1 )
            {
                char *infoLog = (char *)malloc ( sizeof ( char ) * infoLen );
                
                glGetProgramInfoLog ( programObject, infoLen, NULL, infoLog );
                esLogMessage ( "Error linking program:\n%s\n", infoLog );
                
                free ( infoLog );
            }
            
            glDeleteProgram ( programObject );
            return 0;
        }
        
        // Free up no longer needed shader resources
        glDeleteShader ( vertexShader );
        glDeleteShader ( fragmentShader );
        
        return programObject;
    }

    
};


#endif /* CGLShader_hpp */
