#include "stdafx.h"
#include "GlfwWindow.h"

int main()
{
	GlfwWindow obj;

	// Window object is crated using GLFW
	GLFWwindow* windowInst = obj.CreateWindowObject();

	// Glad: load all OpenGL function pointers
	obj.LoadGLFunctionPointers();

	// Call render loop
	obj.RenderFun( windowInst );

	// Clear all allocated GLFW resources
	obj.GLTerminate();
}