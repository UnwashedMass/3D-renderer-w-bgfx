#include "VAO.h"

VAO::VAO() {
	//ID is the vertex array object
	glGenVertexArrays(1, &ID);
	
}

void VAO::LinkVBO(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset) {
	// copies the VBO into a buffer for opengl
	VBO.Bind();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	VBO.Unbind();
}

void VAO::Bind() {
	glBindVertexArray(ID);
}

void VAO::Unbind() {
	glBindVertexArray(0);

}

void VAO::Delete() {
	glDeleteBuffers(1, &ID);
}