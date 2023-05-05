#ifndef __GLMANAGER__
#define __GLMANAGER__

#include <GL/gl3w.h>
#include <iostream>
#include <vector>

#include <GLShaderManager.hpp>

class GLManager 
{
	public:
		GLManager();
		GLuint CreateStandardShaderProgram();
		void SetShaderProgram();
		~GLManager();
	private:
		std::vector<GLuint> shader_programs;
		uint32_t current_shader_program_index;
};

#endif
