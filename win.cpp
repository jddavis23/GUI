#include "includes/proj.hpp"

Win::Win()
{
	this->window = NULL;
};

Win::Win(int width, int height, const char *title)
{
	glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	this->window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (this->window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return ;
	}
	glfwMakeContextCurrent(this->window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		return ;
	}
	glfwSetFramebufferSizeCallback(this->window, framebuffer_size_callback);
};

Win::Win(const Win &a)
{
	this->window = a.window;
};

Win & Win::operator = (const Win &a)
{
	if (this != &a)
		this->window = a.window;
	return *this;
};

GLFWwindow* Win::getWin()
{
	return window;
};

Win::~Win()
{
};

void framebuffer_size_callback(GLFWwindow*, int width, int height)
{
    glViewport(0, 0, width, height);
}