#ifndef SHADER_HPP
#define SHADER_HPP

#include "proj.hpp"

//creating shader object, then using the object and compilation string 
//for compilation
class Shader
{
    private:
        unsigned int shader;
        // int  success;
        // char infoLog[512];
    public:
        Shader();
        Shader(const char *str, int choice);
        Shader(const Shader &a);
        Shader & operator = (const Shader &a);
        ~Shader();
        unsigned int getShader() const;
};

#endif