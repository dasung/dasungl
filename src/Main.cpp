#include "stdafx.h"
#include "DGLWindow.h"

int main()
{
	DGLWindow *pDGLWindowInst = DGLWindow::GetDGLWindowInstance();

	// Window object is crated using GLFW
	pDGLWindowInst->CreateWindowGLFW();

	// Glad: load all OpenGL function pointers
	pDGLWindowInst->LoadGLFunctionPointers();

	// Call render loop
	pDGLWindowInst->RenderFun();

	// Clear all allocated GLFW resources
	pDGLWindowInst->Destroy();
}