#ifndef __GLMESH__
#define __GLMESH__

#include <glm/vec4.hpp>
#include <iostream>

class GLMesh 
{
	public:
		GLMesh();
		~GLMesh();
	private:
		std::vector<glm::vec3> mesh_data;
};

#endif
