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
