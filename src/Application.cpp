#include "include/Application.hpp"

Application::Application()
{
	if(!glfwInit())
	{
		std::cout<<"GLFW Initialization Error"<<std::endl;
		return;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

	this->should_stop = false;

}

void Application::Run()
{
	while(!sig_term)
	{
		glfwWaitEvents();
		if(glfwGetKey(this->window, GLFW_KEY_ESCAPE)==GLFW_PRESS)
			this->sig_term = true;

		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(this->window);
	}
}

void Application::setClearColor(u32 new_clear_color)
{
	this->clear_color = new_clear_color;
	glClearColor(RED(new_clear_color), GREEN(new_clear_color), BLUE(new_clear_color), ALPHA(new_clear_color));
}

Application::~Application()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}
