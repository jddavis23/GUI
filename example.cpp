#include "includes/proj.hpp"


// int main(void)
// {
//     GLFWwindow* window;

//     /* Initialize the library */
//     if (!glfwInit())
//         return -1;

//     /* Create a windowed mode window and its OpenGL context */
//     window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
//     if (!window)
//     {
//         glfwTerminate();
//         return -1;
//     }
// 	gladLoadGL();

//     /* Make the window's context current */
//     glfwMakeContextCurrent(window);

// 	int width, height;
// 	glfwGetFramebufferSize(window, &width, &height);
// 	glViewport(30000, 100, width, height);


//     /* Loop until the user closes the window */
// 	//glfwWindowShouldClose(window);
//     while (!glfwWindowShouldClose(window))
//     {

//         /* Render here */
//         glClear(GL_COLOR_BUFFER_BIT);

//         /* Swap front and back buffers */
//         glfwSwapBuffers(window);

//         /* Poll for and process events */
//         glfwPollEvents();
//     }

//     glfwTerminate();
//     return 0;
// }

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}    
    return 0;
}