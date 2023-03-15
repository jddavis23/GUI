#include "includes/proj.hpp"

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main(int argc, char *argv[])
{
	//assigning vertices for a triangle, because GL uses 3D coordinate,
	//each point of triangle is actually an x, y, z coordinate.
	float vertices[] = {
    // positions         // colors
     0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
     0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
	};    

	if (argc != 3)
	{
		std::cout << "Error: Incorrect args\n";
		return -1;
	}
	Win mywindow(800, 600, "LearnOpenGL");
	GLFWwindow *window = mywindow.getWin();
	if (!window)
		return -1;
	ReadComp prog(argv[1], argv[2]); 

	unsigned int VBO;
	unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
	glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    glBindVertexArray(0); 

	while(!glfwWindowShouldClose(window))
	{
		processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw our first triangle
		float timeValue = glfwGetTime();
		float greenValue = (std::sin(timeValue) / 2.0f) + 0.5f;
		int vertexColorLocation = glGetUniformLocation(prog.getID(), "ourColor");
		
        prog.use();
		glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
	
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawArrays(GL_TRIANGLES, 0, 3);
       
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
	}
	glfwTerminate();
    return 0;
}