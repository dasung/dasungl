#include "stdafx.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback( GLFWwindow* window, int width, int height );

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

class GlfwWindow
{
private:
	void processInput( GLFWwindow *window );

public:
	GLFWwindow* CreateWindowObject();
	void LoadGLFunctionPointers();
	void RenderFun( GLFWwindow *window );
	void GLTerminate();
};