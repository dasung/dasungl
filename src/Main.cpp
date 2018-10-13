#include "stdafx.h"
#include "DGLWindow.h"
#include "DGLShader.h"
#include "DGLVertex.h"

int main()
{
	DGLShader shaderObj;
	DGLVertex vertexObj;
	int VAO, vertexShader, fragmentShader, shaderProram;

	DGLWindow *pDGLWindowInst = DGLWindow::GetDGLWindowInstance();

	// Window object is crated using GLFW
	pDGLWindowInst->CreateWindowGLFW();

	// Glad: load all OpenGL function pointers
	pDGLWindowInst->LoadGLFunctionPointers();

	vertexShader = shaderObj.GenerateVertexShader();
	fragmentShader = shaderObj.GenerateFragmentShader();

	shaderProram = shaderObj.LinkShaders( vertexShader, fragmentShader );

	VAO = vertexObj.SetUpVertexData();

	// Call render loop
	pDGLWindowInst->RenderFun( shaderProram, VAO );

	// Clear all allocated GLFW resources
	pDGLWindowInst->Destroy();
	vertexObj.Destroy();
}