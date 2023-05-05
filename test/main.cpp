#include <iostream>

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include "GLManager.hpp"

#define DEBUG

using namespace std;

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

	GLFWwindow* w = glfwCreateWindow(640, 480, "TITLE", NULL, NULL);

	glfwMakeContextCurrent(w);

	cout<<gl3wInit()<<endl;

	glClearColor(255,255,255,255);

	GLManager* g = new GLManager();

	while(!glfwWindowShouldClose(w))
	{
		glfwSwapBuffers(w);
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);
		if(glfwGetKey(w,GLFW_KEY_ESCAPE)==GLFW_PRESS)
			glfwSetWindowShouldClose(w,GLFW_TRUE);
	}

	delete(g);
	glfwDestroyWindow(w);
	glfwTerminate();

	return 0;
}
