#ifndef WIN_HPP
#define WIN_HPP

#include "proj.hpp"

class Win
{
	private:
	GLFWwindow* window;
	public:
	Win();
	Win(int width, int height, const char *title);
	Win(const Win &a);
	Win & operator = (const Win &a);
	~Win();
	GLFWwindow* getWin();
};

void framebuffer_size_callback(GLFWwindow*, int width, int height);

#endif