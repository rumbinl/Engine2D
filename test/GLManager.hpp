#ifndef GLManager_hpp
#define GLManager_hpp

#include <GL/gl3w.h>
#include <iostream>
#include <vector>

class GLManager 
{
	public:
		GLManager();
		GLuint CreateStandardProgram();
		GLuint CreateStandardVertexShader();
		static GLuint CreateShader(const GLchar* shader_source, GLint shader_type);
		GLuint CreateStandardFragmentShader();
		~GLManager();
	private:
		std::vector<GLuint> shader_programs,shaders;
};

#endif
