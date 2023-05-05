#include "GLManager.hpp"

GLManager::GLManager()
{
}

GLuint GLManager::CreateStandardProgram()
{
}

GLuint GLManager::CreateStandardVertexShader()
{
	const GLchar* vertex_shader_source = "#version 330 core\nuniform mat4 transform;\nlayout (location=0) in vec4 position;\nvoid main(){\ngl_Position = transform * vec4(position,1.0);\n}\0";
	return CreateShader(vertex_shader_source,GL_VERTEX_SHADER);
	
}

GLuint GLManager::CreateShader(const GLchar* shader_source, GLint shader_type)
{
	GLuint shader = glCreateShader(shader_type);
	glShaderSource(shader,1,&shader_source,NULL);
	glCompileShader(shader);
	GLint compile_status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_status);
	if(compile_status==GL_FALSE)
	{
#ifdef DEBUG		
		GLchar info_log[512];
		glGetShaderInfoLog(shader, 1024, NULL, info_log);
		std::cout<<"SHADER COMPILE ERROR:"<<endl<<info_log<<endl;
#endif
	}
	return shader;
}

GLuint GLManager::CreateStandardFragmentShader()
{
}

GLManager::~GLManager()
{
}

