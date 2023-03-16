#ifndef READCOMP_HPP
#define READCOMP_HPP

#include "proj.hpp"
class Shader;
class ProgShader;

class ReadComp
{
    private:
		int success;
		char infoLog[512];
		unsigned int ID;
		//GLFWwindow *window;
		Shader vshader;
		Shader fshader;
		ProgShader pshader;
    public:
		ReadComp();
		ReadComp(const char* vertexPath, const char* fragmentPath);
		ReadComp(const ReadComp &a);
		ReadComp & operator = (const ReadComp &a);
		~ReadComp();
		void use();
		void setBool(const std::string &name, bool value) const;  
		void setInt(const std::string &name, int value) const;   
		void setFloat(const std::string &name, float value) const;
		unsigned int getID() const;
};

#endif