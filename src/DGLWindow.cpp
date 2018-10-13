#include "DGLWindow.h"

DGLWindow* DGLWindow::m_pDGLWindowPtr = NULL;
GLFWwindow* DGLWindow::m_pGlfwWindowPtr = NULL;

DGLWindow::DGLWindow()
{
}


DGLWindow::~DGLWindow()
{
}


DGLWindow* DGLWindow::GetDGLWindowInstance()
{
	if( m_pDGLWindowPtr = NULL )
		m_pDGLWindowPtr = new DGLWindow();

	return m_pDGLWindowPtr;
}


/*
  Callback function to adjest viewport when resizing the the window
*/
void framebuffer_size_callback( GLFWwindow* window, int width, int height )
{
	std::cout << "Resizing window...\n";
    glViewport( 0, 0, width, height );
}


/*
 OpenGL version 3.3, the core profile
 OpenGL support extensions. Graphic card company added these extensions to the card.
 GLFW library allows to create OpenGL context, define window parameters and handle user inputs.
*/
void DGLWindow::CreateWindowGLFW()
{
    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

    // glfw window creation
    m_pGlfwWindowPtr = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "DasunGL", NULL, NULL);
    if ( m_pGlfwWindowPtr == NULL )
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent( m_pGlfwWindowPtr );
    glfwSetFramebufferSizeCallback( m_pGlfwWindowPtr, framebuffer_size_callback );

}


void DGLWindow::LoadGLFunctionPointers()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
		return;
    }
}


void DGLWindow::Destroy()
{
	// Clear all allocated GLFW resources
    glfwTerminate();

	delete m_pDGLWindowPtr;
	m_pDGLWindowPtr = NULL;
}


void DGLWindow::RenderFun( int shaderProgram, int VAO )
{
    // render loop
    while ( !glfwWindowShouldClose( m_pGlfwWindowPtr ) )
    {
        // Check user input
        processInput();

        //  clear the screen with a color of our choice
        glClearColor( 0.5f, 0.3f, 0.1f, 1.0f );
		// Clear the color buffer and filled with color configured by glClearColor
        glClear( GL_COLOR_BUFFER_BIT );

        // draw our first triangle
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        //glDrawArrays(GL_TRIANGLES, 0, 6);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // Swap front buffer and back buffer ( Double buffer rendering )
        glfwSwapBuffers( m_pGlfwWindowPtr );
		// Checks if any Keyboard / Mouse events are triggered
        glfwPollEvents();
    }
}

// Process all user input
void DGLWindow::processInput()
{
    if( glfwGetKey( m_pGlfwWindowPtr, GLFW_KEY_ESCAPE ) == GLFW_PRESS )
	{
        glfwSetWindowShouldClose( m_pGlfwWindowPtr, true );
	}
}