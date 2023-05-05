#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <GLFW/glfw3.h>

class Window 
{
	public:
		Window(u32 window_width, u32 window_height, u32 clear_color=RGB(0,0,0));
		~Window();
	private:
		GLFWwindow* window;
		u32 window_width, window_height;
		bool active;
};

#endif
