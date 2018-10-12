#include "GlfwWindow.h"

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
GLFWwindow* GlfwWindow::CreateWindowObject()
{
    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

    // glfw window creation
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return NULL;
    }

    glfwMakeContextCurrent( window );
    glfwSetFramebufferSizeCallback( window, framebuffer_size_callback );

	return window;
}

void GlfwWindow::LoadGLFunctionPointers()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
		return;
    }
}

void GlfwWindow::GLTerminate()
{
    glfwTerminate();
}

void GlfwWindow::RenderFun( GLFWwindow *window )
{
    // render loop
    while ( !glfwWindowShouldClose( window ) )
    {
        // Check user input
        processInput( window );

        //  clear the screen with a color of our choice
        glClearColor( 0.5f, 0.3f, 0.1f, 1.0f );

		// Clear the color buffer and filled with color configured by glClearColor
        glClear( GL_COLOR_BUFFER_BIT );

        // Swap front buffer and back buffer ( Double buffer rendering )
        glfwSwapBuffers( window );

		// Checks if any Keyboard / Mouse events are triggered
        glfwPollEvents();
    }
}

// Process all user input
void GlfwWindow::processInput( GLFWwindow *window )
{
    if( glfwGetKey( window, GLFW_KEY_ESCAPE ) == GLFW_PRESS )
	{
        glfwSetWindowShouldClose( window, true );
	}
}