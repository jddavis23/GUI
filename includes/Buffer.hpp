#ifndef BUFFER_HPP
#define BUFFER_HPP

#include "proj.hpp"
// class Shader;
// class ProgShader;

class Buffer
{
    private:
        unsigned int VBO;
        unsigned int VAO;
        unsigned int EBO;
    public:
        Buffer();
        Buffer(float vertices[], unsigned long szofv, unsigned indices[], unsigned long szofin);
        Buffer(const Buffer &a);
        Buffer & operator = (const Buffer &a);
        ~Buffer();
        unsigned int getVAO() const;
        unsigned int getVBO() const;
        unsigned int getEBO() const;
};

#endif