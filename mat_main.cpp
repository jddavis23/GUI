#include "includes/proj.hpp"
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void err_close(unsigned int VAO, unsigned int VBO, unsigned int EBO)
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
}

int main(int argc, char *argv[])
{
	//assigning vertices for a triangle, because GL uses 3D coordinate,
	//each point of triangle is actually an x, y, z coordinate.
	float vertices[] = {
    // positions          // colors           // texture coords
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
    };
     unsigned int indices[] = {  
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    // glm::mat4 trans = glm::mat4(1.0f);
    // trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
    // trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));  

	if (argc != 5)
	{
		std::cout << "usage: ./shader <vertex-comp-file> <fragment-comp-file> <texture-image> <texture-image>\n";
		return -1;
	}
	Win mywindow(800, 600, "LearnOpenGL");
	GLFWwindow *window = mywindow.getWin();
	if (!window)
		return -1;
	ReadComp prog(argv[1], argv[2]); 
    Buffer buff(vertices, sizeof(vertices), indices, sizeof(indices));

    LoadTex texture1(argv[3], GL_RGB);
    LoadTex texture2(argv[4], GL_RGBA);
    if (!texture1.getTexture() || !texture2.getTexture())
    {
        err_close(buff.getVAO(), buff.getVBO(), buff.getEBO());
        return -1;
    }
    
    prog.use(); // don't forget to activate the shader before setting uniforms!  
    prog.setInt("texture1", 0);
    prog.setInt("texture2", 1);
    
  
	while(!glfwWindowShouldClose(window))
	{
		processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1.getTexture());
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2.getTexture());
         // create transformations
        glm::mat4 transform = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
        transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

        prog.use();
	   unsigned int transformLoc = glGetUniformLocation(prog.getID(), "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

        glBindVertexArray(buff.getVAO()); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
	}
	err_close(buff.getVAO(), buff.getVBO(), buff.getEBO());
    return 0;
}