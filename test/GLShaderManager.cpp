#include <GLShaderManager.hpp>

GLuint CreateStandardVertexShader()
{
	const GLchar* vertex_shader_source = "#version 330 core\nuniform mat4 transform;\nlayout (location=0) in vec3 position;\nvoid main(){\ngl_Position = transform * vec4(position,1.0);\n}\0";
	return CreateShader(vertex_shader_source, GL_VERTEX_SHADER);
	
}

GLuint CreateStandardFragmentShader()
{
	const GLchar* fragment_shader_source = "#version 330 core\nout vec4 color;\nvoid main(){\ncolor = vec4(1.0);\n}\0";
	return CreateShader(fragment_shader_source, GL_FRAGMENT_SHADER);
}

GLuint CreateShaderProgram(GLuint vertex_shader, GLuint fragment_shader)
{
	GLuint shader_program = glCreateProgram();
	glAttachShader(shader_program, vertex_shader);
	glAttachShader(shader_program, fragment_shader);
	glLinkProgram(shader_program);
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
	GLint program_status;
	glGetProgramiv(shader_program, GL_LINK_STATUS, &program_status);
	if(program_status == GL_FALSE)
	{
	#ifdef DEBUG
		char info_log[1024];
		glGetProgramInfoLog(shader_program, 1024, NULL, info_log);
		return 0;
	#endif
	}
	return shader_program;
}

GLuint CreateShader(const GLchar* shader_source, GLint shader_type)
{
	GLuint shader = glCreateShader(shader_type);
	glShaderSource(shader, 1, &shader_source, NULL);
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
		return 0;
	}
	return shader;
}
