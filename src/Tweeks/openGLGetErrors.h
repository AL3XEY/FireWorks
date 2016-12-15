#ifndef OPENGL_GET_ERRORS
#define OPENGL_GET_ERRORS

#include <GLEW/glew.h>
#include <iostream>


static void openGLGetErrors() {
	GLenum err;
	while ((err = glGetError()) != GL_NO_ERROR) {
		std::cerr << "OpenGL error: " << err << std::endl;
	}
}

#endif