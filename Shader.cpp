#include "includes/proj.hpp"

Shader::Shader()
{
    this->shader = 0;
};

Shader::Shader(const char *str, int choice)
{
    switch (choice)
    {
        case 0:
            this->shader = glCreateShader(GL_VERTEX_SHADER);
            break;
        case 1:
            this->shader = glCreateShader(GL_FRAGMENT_SHADER);
            break;
    }
	glShaderSource(this->shader, 1, &str, NULL);
	glCompileShader(this->shader);
    glGetShaderiv(this->shader, GL_COMPILE_STATUS, &this->success);//error checker
    if(!this->success)
    {
        glGetShaderInfoLog(this->shader, 512, NULL, this->infoLog);
        std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << this->infoLog << std::endl;
		this->shader = 0;
		return ;
    }
};

Shader::Shader(const Shader &a)
{
    this->shader = a.getShader();
};

Shader & Shader::operator = (const Shader &a)
{
    if (this != &a)
    {
        this->shader = a.shader;
    }
    return *this;
};

Shader::~Shader()
{
    
};

unsigned int Shader::getShader() const
{
    return (this->shader);
};




// unsigned int vertexShader;
// 	vertexShader = glCreateShader(GL_VERTEX_SHADER);
// 	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
// 	glCompileShader(vertexShader);
// 	int  success;
// 	char infoLog[512];
// 	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);//error checker
// 	if(!success)
// 	{
// 		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
// 		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
// 	}
