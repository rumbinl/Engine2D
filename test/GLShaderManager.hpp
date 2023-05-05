#ifndef __GLSHADERMANAGER__
#define __GLSHADERMANAGER__

#include <GL/gl3w.h>
#include <iostream>

namespace GLShaderManager 
{
	GLuint CreateStandardVertexShader();
	GLuint CreateStandardFragmentShader();
	GLuint CreateShaderProgram(GLuint vertex_shader, GLuint fragment_shader);
	GLuint CreateShader(const GLchar* shader_source, GLint shader_type);
}

#endif

