#include <stdio.h>
#include <glew.h>
#include <glfw3.h>

const GLint WIDTH = 800, HEIGHT = 600;
int main()
{
    printf("CMake Test\n");

    if(!glfwInit())
    {
        printf("GLFW Initialization failed!\n");
        glfwTerminate();
        return 1;
    }

    //Setup GLFW window properties
    //OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //core profile = no backwards compatibility
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //Allow forward compatibility
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "OpenGLengine", NULL, NULL);
    if(!mainWindow)
    {
        printf("GLFW window creation failed!\n");
        glfwTerminate();
        return 1;
    }

    //Get buffer size info
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    //Set context for GLFW to use
    glfwMakeContextCurrent(mainWindow);

    //Allow modern extension features
    glewExperimental = GL_TRUE;

    GLenum initStatus = glewInit();
    if(GLEW_OK != initStatus && initStatus != GLEW_ERROR_NO_GLX_DISPLAY)
    {
        printf("GLEW initiaisation failed! GLEW exit code %d\n What went wrong:\n %s\n", initStatus, glewGetErrorString(initStatus));
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }

    //Setup viewport size
    glViewport(0, 0, bufferWidth, bufferHeight);

    //Loop until window closed
    while(!glfwWindowShouldClose(mainWindow))
    {
        //Get + Handle user input events
        glfwPollEvents();

        //Clear Window
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(mainWindow);
    }
}