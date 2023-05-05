#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

#include <gl3w/GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cstdio>

#include "include/type.hpp"

typedef uint32_t u32;

class Application 
{
	public:
		Application();	
		u32 CreateWindow(u32 w, u32 h, u32 clear_color=RGBA(0,0,0,255));
		void Run();
		void setClearColor(u32 new_clear_color);
		~Application();
	private:
		std::vector<GLFWwindow> window_array;
		u32 window_width,window_height,clear_color;
		bool sig_term;
};
#endif
