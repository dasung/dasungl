#include "stdafx.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback( GLFWwindow* window, int width, int height );

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

class DGLWindow
{
public:
	static DGLWindow* GetDGLWindowInstance();
	void CreateWindowGLFW();
	void LoadGLFunctionPointers();
	void RenderFun( int shaderProgram, int VAO );
	void Destroy();

private:
	static DGLWindow* m_pDGLWindowPtr;
	static GLFWwindow* m_pGlfwWindowPtr;

	DGLWindow();									// Cannot be called from outside
	~DGLWindow();
	DGLWindow( DGLWindow const& ){ };				// Restric instance copy
	DGLWindow& operator=( DGLWindow const& ){ };  // Restrict assignment operator

	void processInput();

};