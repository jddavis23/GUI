#ifndef PROGSHADER_HPP
#define PROGSHADER_HPP

#include "proj.hpp"

//creating shader object, then using the object and compilation string 
//for compilation
class ProgShader
{
    private:
        unsigned int shader;
    public:
        ProgShader();
        ProgShader(unsigned int vsh, unsigned int fsh);
        ProgShader(const ProgShader &a);
        ProgShader & operator = (const ProgShader &a);
        ~ProgShader();
        unsigned int getShader() const;
};

#endif