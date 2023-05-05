#include "include/Window.hpp"

Window::Window(u32 window_width, u32 window_height, u32 clear_color)
{
	this->window = glfwCreateWindow(window_width, window_height, window_name, NULL, NULL);	
}
