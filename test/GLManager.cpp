#include "GLManager.hpp"

GLManager::GLManager()
{
	this->CreateStandardShaderProgram();
	current_shader_program_index = 0;
	SetShaderProgram();
}

void GLManager::SetShaderProgram()
{
	glUseProgram(current_shader_program_index);
}

GLuint GLManager::CreateStandardShaderProgram()
{
	this->shader_programs.push_back(GLShaderManager::CreateShaderProgram(GLShaderManager::CreateStandardVertexShader(), GLShaderManager::CreateStandardFragmentShader()));
	return this->shader_programs.size()-1;
}


GLManager::~GLManager()
{
	for(int i=0;i<this->shader_programs.size();i++)
		glDeleteProgram(this->shader_programs[i]);
}

