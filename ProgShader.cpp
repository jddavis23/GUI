#include "includes/proj.hpp"

ProgShader::ProgShader()
{
	this->shader = 0;
};

ProgShader::ProgShader(unsigned int vsh, unsigned int fsh)
{
	this->shader = glCreateProgram();
	glAttachShader(this->shader, vsh);
	glAttachShader(this->shader, fsh);
	glLinkProgram(this->shader);
	glGetProgramiv(this->shader, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(this->shader, 512, NULL, infoLog);
		std::cout << "ERROR::PROGRAM::OBJECT::COMPILATION_FAILED\n" << infoLog << std::endl;
		this->shader = 0;
	}
	
	//deleting vertex and fragment shaders
	glDeleteShader(vsh);
	glDeleteShader(fsh);
};

ProgShader::ProgShader(const ProgShader &a)
{
	this->shader = a.getShader();
};

ProgShader & ProgShader::operator = (const ProgShader &a)
{
	if (this != &a)
		this->shader = a.getShader();
	return *this;
		
};

ProgShader::~ProgShader()
{
};

unsigned int ProgShader::getShader() const
{
	return this->shader;
};