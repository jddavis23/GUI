#ifndef LOADTEX_HPP
#define LOADTEX_HPP

#include "proj.hpp"
// class Shader;
// class ProgShader;

class LoadTex
{
    private:
        unsigned int texture;
    public:
		LoadTex();
		LoadTex(char *str, int rendertype);
		LoadTex(const LoadTex &a);
		LoadTex & operator = (const LoadTex &a);
		~LoadTex();
		// void use();
		// void setBool(const std::string &name, bool value) const;  
		// void setInt(const std::string &name, int value) const;   
		// void setFloat(const std::string &name, float value) const;
		unsigned int getTexture() const;
};

#endif