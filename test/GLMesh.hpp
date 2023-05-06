#ifndef __GLMESH__
#define __GLMESH__

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <GL/gl3w.h>
#include <iostream>
#include <vector>

class GLMesh 
{
	public:
		GLMesh(glm::vec3 a, glm::vec3 b, glm::vec3 c);
		void SetVBO();
		~GLMesh();
	private:
		std::vector<glm::vec3> mesh_vertices; 
		std::vector<int> mesh_indices;
		GLuint vbo;
};

#endif
