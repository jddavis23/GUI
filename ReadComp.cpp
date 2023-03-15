#include "includes/proj.hpp"

ReadComp::ReadComp() : ID(0) {};

ReadComp::ReadComp(const char* vertexPath, const char* fragmentPath)
{
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;
	vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
	try 
	{
		// open files
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		std::stringstream vShaderStream, fShaderStream;
		// read file's buffer contents into streams
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();		
		// close file handlers
		vShaderFile.close();
		fShaderFile.close();
		// convert stream into string
		vertexCode   = vShaderStream.str();
		fragmentCode = fShaderStream.str();		
	}
	catch(std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
	this->vshader = Shader(vertexCode.c_str(), 0);
	glGetShaderiv(this->vshader.getShader(), GL_COMPILE_STATUS, &this->success);//error checker
	if(!this->success)
	{
		glGetShaderInfoLog(this->vshader.getShader(), 512, NULL, this->infoLog);
		std::cout << "ERROR::VSHADER::COMPILATION_FAILED\n" << this->infoLog << std::endl;
		return ;
	}
	this->fshader = Shader(fragmentCode.c_str(), 1);
		glGetShaderiv(this->fshader.getShader(), GL_COMPILE_STATUS, &this->success);//error checker
	if(!this->success)
	{
		glGetShaderInfoLog(this->fshader.getShader(), 512, NULL, this->infoLog);
		std::cout << "ERROR::FSHADER::COMPILATION_FAILED\n" << this->infoLog << std::endl;
		return ;
	}
	this->pshader = ProgShader(this->vshader.getShader(),this->fshader.getShader());
	glGetProgramiv(this->pshader.getShader(), GL_LINK_STATUS, &this->success);
	if(!this->success)
	{
		glGetProgramInfoLog(this->ID, 512, NULL, this->infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << this->infoLog << std::endl;
		return;
	}
	
};

ReadComp::ReadComp(const ReadComp &a)
{
	this->vshader = a.vshader;
	this->fshader = a.fshader;
	this->pshader = a.pshader;
};

ReadComp & ReadComp::operator = (const ReadComp &a)
{
	if (this != &a)
	{
		this->vshader = a.vshader;
		this->fshader = a.fshader;
		this->pshader = a.pshader;
	}
	return *this;
};

ReadComp::~ReadComp()
{
};

void ReadComp::use()
{
	glUseProgram(pshader.getShader());
};

void ReadComp::setBool(const std::string &name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
};

void ReadComp::setInt(const std::string &name, int value) const
{
	glUniform1i(glGetUniformLocation(this->ID, name.c_str()), value); 

};   
void ReadComp::setFloat(const std::string &name, float value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value); 
};

unsigned int ReadComp::getID()
{
	return this->pshader.getShader();
};
