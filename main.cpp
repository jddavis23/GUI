#include "includes/proj.hpp"

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main()
{
	//assigning vertices for a triangle, because GL uses 3D coordinate,
	//each point of triangle is actually an x, y, z coordinate.
	float vertices[] = {
    // positions         // colors
     0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
     0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
};    

	Win mywindow(800, 600, "LearnOpenGL");
	GLFWwindow *window = mywindow.getWin();
	if (!window)
		return -1;
	Shader vshader(vertexShaderSource, 0);
	Shader fshader(fragShaderSource, 1);
	if (!fshader.getShader() || !vshader.getShader())
		return -1;
	ProgShader pshader(vshader.getShader(), fshader.getShader());
	if (!pshader.getShader())
		return -1;
	
	//linking vertex attributes
	// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	// glEnableVertexAttribArray(0);  

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
        glUseProgram(pshader.getShader());
		float timeValue = glfwGetTime();
		float greenValue = (std::sin(timeValue) / 2.0f) + 0.5f;
		int vertexColorLocation = glGetUniformLocation(pshader.getShader(), "ourColor");
		glUseProgram(pshader.getShader());
		glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
	
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawArrays(GL_TRIANGLES, 0, 3);
        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // glBindVertexArray(0); // no need to unbind it every time 
 
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
	}
	glfwTerminate();
    return 0;
}