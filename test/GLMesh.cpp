#include <GLMesh.hpp>

GLMesh::GLMesh(glm::vec3 a, glm::vec3 b, glm::vec3 c)
{
	this->mesh_vertices = {a, b, c};
	this->mesh_indices = {1, 2, 3};
}

void GLMesh::SetVBO()
{
	glGenBuffers(1, &this->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	glBufferData(GL_ARRAY_BUFFER, this->mesh_vertices.size()*sizeof(float), &this->mesh_vertices[0][0], GL_STATIC_DRAW);
}

GLMesh::~GLMesh()
{
}
